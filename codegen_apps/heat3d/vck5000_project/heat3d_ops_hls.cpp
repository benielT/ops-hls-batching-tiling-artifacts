
// Auto-generated at 2025-09-04 18:12:08.051454 by ops-translator
/*
* Open source copyright declaration based on BSD open source template:
* http://www.opensource.org/licenses/bsd-license.php
*
* This file is part of the OPS distribution.
*
* Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
* the main source directory for a full list of copyright holders.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * The name of Mike Giles may not be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @Test application for fpga batched temporal blocked heat3d
  * @author Beniel Thileepan
  */


#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int imax, jmax, kmax;
extern const unsigned short mem_vector_factor;
// float pi  = 2.0 * asin(1.0);

//Including main OPS header file, and setting 3D
#define OPS_3D
// #define OPS_CPP_API
#define OPS_HLS_V2
// #define OPS_FPGA
// #define PROFILE
// #define VERIFICATION
#include <ops_seq_v2.h>
#include <ops_hls_rt_support.h>
#include <hls_kernels.hpp>
//Including applicaiton-specific "user kernels"
/* ops_par_loop declarations */

void ops_par_loop_ops_krnl_zero_init(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_interior_init(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_copy(ops::hls::Block, int, int*, ops::hls::Grid<float>&, ops::hls::Grid<float>&);

#include "heat3d.hpp"
#include "heat3d_kernels.h"
#include "heat3d_cpu_verification.hpp"

#ifdef PROFILE
    #include <chrono>
#endif

#ifdef POWER_PROFILE
    unsigned int power_iter = 1;
    #ifdef PROFILE
    std::cerr << "POWER_PROFILE cannot be enabled with PROFILE" << std::endl;
    exit(-1);
    #endif  
#endif
int main(int argc, const char** argv)
{
    //Initialise the OPS library, passing runtime args, and setting diagnostics level to low (1)
	ops_init_backend(argc, argv);


    imax = 5;
    jmax = 5;
    kmax = 5;

    unsigned int iter_max = 2;
    unsigned int batches = 1;
    int batch_size = 1;

    const char* pch;
    for ( int n = 1; n < argc; n++ ) 
    {
        pch = strstr(argv[n], "-sizex=");

        if(pch != NULL) {
            imax = atoi ( argv[n] + 7 ); continue;
        }
        pch = strstr(argv[n], "-sizey=");

        if(pch != NULL) {
            jmax = atoi ( argv[n] + 7 ); continue;
        }
        pch = strstr(argv[n], "-sizez=");

        if(pch != NULL) {
            kmax = atoi ( argv[n] + 7 ); continue;
        }
        pch = strstr(argv[n], "-iters=");

        if(pch != NULL) {
            iter_max = atoi ( argv[n] + 7 ); continue;
        }
        pch = strstr(argv[n], "-batch=");

        if(pch != NULL) {
            batches = atoi ( argv[n] + 7 ); continue;
        }
#ifdef BATCHING
        pch = strstr(argv[n], "-bsize=");
        if(pch != NULL) {
            batch_size = atoi ( argv[n] + 7 );
            if(batch_size < 1) {
                std::cerr << "Batch size must be greater than 0" << std::endl;
                exit(-1);
            }
            continue;
        }
#endif
#ifdef POWER_PROFILE
        pch = strstr(argv[n], "-piter=");
        if(pch != NULL) {
            power_iter = atoi ( argv[n] + 7 ); continue;
        }
        batches = 1;
#endif
    }
#ifdef BATCHING
    #ifndef POWER_PROFILE
    if(batches % batch_size != 0) {
        std::cerr << "Batch size must divide the number of batches evenly" << std::endl;
        exit(-1);
    }
    batches /= batch_size;
    std::cout << "Batching enabled, number of batches: " << batches << ", batch size: " << batch_size << std::endl;
    #endif
#endif
#ifdef POWER_PROFILE
    #ifdef BATCHING
            if(power_iter % batch_size != 0) {
                    std::cerr << "Batch size must divide the number of power batches evenly" << std::endl;
                    exit(-1);
            }
            std::cout << "Total power iterations: " << power_iter << std::endl;
            std::cout << "Power profiling enabled, number of power iterations per batch: " << power_iter / batch_size << std::endl;
            power_iter = power_iter / batch_size;
    #endif 
            std::cout << "Power profiling enabled, number of power iterations: " << power_iter << std::endl;
#endif
#ifdef PROFILE
	double init_runtime[batches];
	double main_loop_runtime[batches];

    std::string profile_filename = "perf_profile.csv";

    std::ofstream fstream;
    fstream.open(profile_filename, std::ios::out | std::ios::trunc);

    if (!fstream.is_open()) {
        std::cerr << "Error: Could not open the file " << profile_filename << std::endl;
        return 1; // Indicate an error occurred
    }
#endif
    GridParameter gridData;
    gridData.logical_size_x = imax;
    gridData.logical_size_y = jmax;
    gridData.logical_size_z = kmax;
    gridData.batch = batches;
    gridData.batch_size = batch_size;
    gridData.num_iter = iter_max;

    //adding halo
    gridData.act_size_x = gridData.logical_size_x + 2;
    gridData.act_size_y = gridData.logical_size_y + 2;
    gridData.act_size_z = gridData.logical_size_z + 2;

    //padding each row as multiples of vectorization factor
    gridData.grid_size_x = (gridData.act_size_x % mem_vector_factor) != 0 ?
			      (gridData.act_size_x/mem_vector_factor + 1) * mem_vector_factor:
			      gridData.act_size_x;
	  gridData.grid_size_y = gridData.act_size_y;
    gridData.grid_size_z = gridData.act_size_z;

    unsigned int data_size_bytes = sizeof(float) * gridData.grid_size_x 
            * gridData.grid_size_y * gridData.grid_size_z * batch_size;

    float angle_res_x = 2 * M_PI / gridData.logical_size_x;
    float angle_res_y = 2 * M_PI / gridData.logical_size_y;
    float angle_res_z = 2 * M_PI / gridData.logical_size_z;

    if (data_size_bytes >= 4000000000)
    {
        std::cerr << "Maximum buffer size is exceeded!" << std::endl;
    }


    //The 3D block
    ops::hls::Block blocks[batches];

    for (unsigned int bat = 0; bat < batches; bat++)
    {
        std::string name = std::string("batch_") + std::to_string(bat);
#ifndef BATCHING
        blocks[bat] = ops_hls_decl_block(3, name.c_str());
#else
        blocks[bat] = ops_hls_decl_block_batch(3, name.c_str(), batch_size);
#endif
    }

    //defining stencils
    int s3d_1pt[] = {0,0,0};

    int s3d_7pt[] = {0,0,0, 1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};

    //The two datasets
    int size[] = {imax, jmax, kmax};
    int base[] = {0,0,0};
    int d_m[] = {-1,-1,-1};
    int d_p[] = {1,1,1};
    float* temp = NULL;

    ops::hls::Grid<stencil_type> u[batches];
    ops::hls::Grid<stencil_type> u2[batches];
    std::vector<heat3DParameter> calcParam(gridData.batch);

#ifdef VERIFICATION
    float* u_cpu[batches];
    float* u2_cpu[batches];
#endif

    // Allocation
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        std::string name = std::string("u_") + std::to_string(bat);
        u[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);
        name = std::string("u2_") + std::to_string(bat);
        u2[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);

#ifdef VERIFICATION
        u_cpu[bat] = (float*)malloc(data_size_bytes);
        u2_cpu[bat] = (float*)malloc(data_size_bytes);
#endif
        //Generating calc parameters
        calcParam[bat].alpha = 1.5/1000; //diffusivity 
        calcParam[bat].h = 1/gridData.act_size_x; 
        calcParam[bat].delta_t = 0.5; //0.5s
        calcParam[bat].K = calcParam[bat].alpha * calcParam[bat].delta_t / (calcParam[bat].h * calcParam[bat].h);
    }

    //defining the access ranges
    int bottom_plane_range[] = {-1,gridData.logical_size_x+1, -1,gridData.logical_size_y+1, -1,0};
    int top_plane_range[] = {-1,gridData.logical_size_x+1, -1,gridData.logical_size_y+1, gridData.logical_size_z,gridData.logical_size_z+1};
    int front_plane_range[] = {-1,gridData.logical_size_x+1,-1,0,-1,gridData.logical_size_z+1};
    int back_plane_range[] = {-1,gridData.logical_size_x+1, gridData.logical_size_y,gridData.logical_size_y+1, -1,gridData.logical_size_z+1};
    int left_plane_range[] = {-1,0, -1,gridData.logical_size_y+1, -1,gridData.logical_size_z+1};
    int right_plane_range[] = {gridData.logical_size_x,gridData.logical_size_x+1, -1,gridData.logical_size_y+1, -1,gridData.logical_size_z+1};
    int full_range[] = {-1,gridData.logical_size_x+1, -1,gridData.logical_size_y+1, -1,gridData.logical_size_z+1};
    int interior_range[] =  {0,gridData.logical_size_x, 0,gridData.logical_size_y, 0,gridData.logical_size_z};

#ifdef POWER_PROFILE
    for (unsigned int p = 0; p < power_iter; p++)
    {
#endif
#ifndef OPS_FPGA
    #ifdef BATCHING
        ops_par_loop_blocks_all(batch_size);
    #endif
#endif
    for (unsigned int bat = 0; bat < batches; bat++)
    {
#ifdef PROFILE
        auto init_start_clk_point =  std::chrono::high_resolution_clock::now();
#endif
        //Initializing data
        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  top_plane_range, u[bat]);

        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  bottom_plane_range, u[bat]);

        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  front_plane_range, u[bat]);
        
        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  back_plane_range, u[bat]);

        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  left_plane_range, u[bat]);

        ops_par_loop_ops_krnl_zero_init( blocks[bat],  3 ,  right_plane_range, u[bat]);

        ops_par_loop_ops_krnl_interior_init( blocks[bat],  3 ,  interior_range, u[bat], &angle_res_x, &angle_res_y, &angle_res_z);

        ops_par_loop_ops_krnl_copy( blocks[bat],  3 ,  full_range, u2[bat], u[bat]);

#ifdef PROFILE
        auto init_end_clk_point = std::chrono::high_resolution_clock::now();
        init_runtime[bat] = std::chrono::duration<double, std::micro> (init_end_clk_point - init_start_clk_point).count();
#endif

#ifdef VERIFICATION
        auto u_raw = (float*)u[bat].get_raw_pointer();
        auto u2_raw = (float*)u2[bat].get_raw_pointer();

        initialize_grid(u_cpu[bat], size, d_m, d_p, full_range, batch_size, angle_res_x, angle_res_y, angle_res_z);
        copy_grid(u_cpu[bat], u2_cpu[bat], gridData, batch_size);
        if(verify(u_raw, u_cpu[bat], size, d_m, d_p, full_range, batch_size))
            std::cout << "[BATCH - " << bat << "] verification of u after initiation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of u after initiation" << "[FAILED]" << std::endl;

        if(verify(u2_raw, u2_cpu[bat], size, d_m, d_p, full_range, batch_size))
            std::cout << "[BATCH - " << bat << "] verification of u2 after initiation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of u2 after initiation" << "[FAILED]" << std::endl;
#endif

        printf("Launching poisson calculation: %d x %d x %d mesh\n", size[0], size[1], size[2]);

        //iterative stencil loop
#ifdef PROFILE
        auto main_loop_start_clk_point = std::chrono::high_resolution_clock::now();
#endif

        float param_k = calcParam[bat].K;

#ifdef OPS_FPGA
#endif
        isl0(iter_max, interior_range, u[bat], u2[bat], &param_k);

#ifdef PROFILE
    #ifndef OPS_FPGA
        auto main_loop_end_clk_point = std::chrono::high_resolution_clock::now();
        main_loop_runtime[bat] = std::chrono::duration<double, std::micro>(main_loop_end_clk_point - main_loop_start_clk_point).count();
    #endif
#endif 
#ifndef OPS_FPGA
    #ifndef BATCHING
    ops_par_loop_blocks_end();
    #endif
#endif

#ifdef POWER_PROFILE
    }
#endif
    }

    //Final Verification after calc
#ifdef VERIFICATION
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        auto u_raw = (float*)u[bat].get_raw_pointer();
        auto u2_raw = (float*)u2[bat].get_raw_pointer();

        heat3D_explicit(u_cpu[bat], u2_cpu[bat], gridData, calcParam, batch_size);
        
        // if(verify(u_raw, u_cpu[bat], size, d_m, d_p, full_range))
        //     std::cout << "[BATCH - " << bat << "] verification of u after calculation" << "[PASSED]" << std::endl;
        // else
        //     std::cout << "[BATCH - " << bat << "] verification of u after calculation" << "[FAILED]" << std::endl;

        if(verify(u2_raw, u2_cpu[bat], size, d_m, d_p, full_range, batch_size))
            std::cout << "[BATCH - " << bat << "] verification of u2 after calculation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of u2 after calculation" << "[FAILED]" << std::endl;
    }
#endif

    //cleaning
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        ops_free_dat(u[bat]);
        ops_free_dat(u2[bat]);

#ifdef VERIFICATION
        free(u_cpu[bat]);
        free(u2_cpu[bat]);

#endif
    }

#ifdef PROFILE
	std::cout << std::endl;
	std::cout << "******************************************************" << std::endl;
	std::cout << "**                runtime summary                   **" << std::endl;
	std::cout << "******************************************************" << std::endl;

	double avg_main_loop_runtime = 0;
	double max_main_loop_runtime = 0;
	double min_main_loop_runtime = 0;
	double avg_init_runtime = 0;
	double max_init_runtime = 0;
	double min_init_runtime = 0;
	double main_loop_std = 0;
	double init_std = 0;
	double total_std = 0;

    fstream << "grid_x," << "grid_y," << "grid_z," << "iters," << "batch_size," << "batch_id," << "init_time," << "main_time," << "total_time" << std::endl; 

	for (unsigned int bat = 0; bat < batches; bat++)
	{
    #ifdef OPS_FPGA
        main_loop_runtime[bat] = ops_hls_get_execution_runtime<std::chrono::microseconds>(std::string("isl0"), bat);
    #endif
        main_loop_runtime[bat] /= batch_size;
        init_runtime[bat] /= batch_size;

        fstream << imax << "," << jmax << "," << kmax << "," << iter_max << "," << 1 << "," << bat << "," << init_runtime[bat] \
                << "," << main_loop_runtime[bat] << "," << main_loop_runtime[bat] + init_runtime[bat] << std::endl;
        std::cout << "[WARNING] The runtime is averaged over the batch size of " << batch_size << std::endl;

		std::cout << "run: "<< bat << "| total runtime: " << main_loop_runtime[bat] + init_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> init runtime: " << init_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> main loop runtime: " << main_loop_runtime[bat] << "(us)" << std::endl;
		avg_init_runtime += init_runtime[bat];
		avg_main_loop_runtime += main_loop_runtime[bat];

		if (bat == 0)
		{
			max_main_loop_runtime = main_loop_runtime[bat];
			min_main_loop_runtime = main_loop_runtime[bat];
			max_init_runtime = init_runtime[bat];
			min_init_runtime = init_runtime[bat];
		}
		else
		{
			max_main_loop_runtime = std::max(max_main_loop_runtime, main_loop_runtime[bat]);
			min_main_loop_runtime = std::min(min_main_loop_runtime, main_loop_runtime[bat]);
			max_init_runtime = std::max(max_init_runtime, init_runtime[bat]);
			min_init_runtime = std::min(min_init_runtime, init_runtime[bat]);
		}
	}

	avg_init_runtime /= batches;
	avg_main_loop_runtime /= batches;

	for (unsigned int bat = 0; bat < batches; bat++)
	{
		main_loop_std += std::pow(main_loop_runtime[bat] - avg_main_loop_runtime, 2);
		init_std += std::pow(init_runtime[bat] - avg_init_runtime, 2);
		total_std += std::pow(main_loop_runtime[bat] + init_runtime[bat] - avg_init_runtime - avg_main_loop_runtime, 2);
	}

	main_loop_std = std::sqrt(main_loop_std / batches);
	init_std = std::sqrt(init_std / batches);
	total_std = std::sqrt(total_std / batches);

	std::cout << "Total runtime (AVG): " << avg_main_loop_runtime + avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << avg_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime (MIN): " << min_main_loop_runtime + min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << min_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime (MAX): " << max_main_loop_runtime + max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << max_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Standard Deviation init: " << init_std << std::endl;
	std::cout << "Standard Deviation main loop: " << main_loop_std << std::endl;
	std::cout << "Standard Deviation total: " << total_std << std::endl;
	std::cout << "======================================================" << std::endl;

        fstream << "args: " << "-sizex=" << imax << " -sizey=" << jmax << " -sizez=" << kmax << " -iters=" << iter_max << " -batch=" << batches << " -bsize=" << batch_size << std::endl;
    fstream.close();

    if (fstream.good()) { // Check if operations were successful after closing
        std::cout << "Successfully wrote data to " << profile_filename << std::endl;
    } else {
            std::cerr << "Error occurred during writing to " << profile_filename << std::endl;
            return 1; // Indicate an error occurred
    }

#endif

	ops_exit_backend();


    std::cout << "Exit properly" << std::endl;
    return 0;
}
