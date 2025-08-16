
// Auto-generated at 2025-08-16 01:04:10.041532 by ops-translator
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

/** @Test application for fpga batched temporal blocked jacobian 2D
  * @author Beniel Thileepan
  */

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern const unsigned short mem_vector_factor;

// OPS header file
#define OPS_3D
//#define VERIFICATION
// #define OPS_CPP_API
#define OPS_HLS_V2
// #define OPS_FPGA
// #define PROFILE
// #define POWER_PROFILE
#include "user_types.h"
#include <ops_seq_v2.h>
#include <ops_hls_rt_support.h>
#include <hls_kernels.hpp>
#include "jac3D7pt_kernel.h"
/* ops_par_loop declarations */

void ops_par_loop_kernel_populate(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_kernel_initialguess(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_kernel_copy(ops::hls::Block, int, int*, ops::hls::Grid<float>&, ops::hls::Grid<float>&);

#include "jac3D7pt_cpu_verification.hpp"

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
/******************************************************************************
* Main program
*******************************************************************************/
int main(int argc, const char **argv)
{
  /**-------------------------- Initialisation --------------------------**/

    // OPS initialisation
	ops_init_backend(argc, argv);



    //Mesh
    int imax = 20;
    int jmax = 20;
    int kmax = 20;
    unsigned int iter_max = 135;
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

    //The 2D block
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


    //declare stencils
    int s3D_00[] = {0,0,0};
    int s3D_7pt[] = {0,0,-1, 0,-1,0, -1,0,0, 0,0,0, 1,0,0, 0,1,0, 0,0,1};

    //declare datasets
    int size[] = {imax, jmax, kmax};
    int base[] = {0,0,0};
    int d_m[] = {-1,-1,-1};
    int d_p[] = {1,1,1};
    float* temp = NULL;

    ops::hls::Grid<stencil_type> u[batches];
    ops::hls::Grid<stencil_type> u2[batches];
    ops::hls::Grid<stencil_type> f[batches];
    ops::hls::Grid<stencil_type> ref[batches];
#ifdef VERIFICATION
    float* u_cpu[batches];
    float* u2_cpu[batches];
    float* f_cpu[batches];
    float* ref_cpu[batches];

    int grid_size_z = size[2] - d_m[2] + d_p[2];
    int grid_size_y = size[1] - d_m[1] + d_p[1];
    #ifdef OPS_FPGA
    int grid_size_x = ((size[0] - d_m[0] + d_p[0] + mem_vector_factor - 1) / mem_vector_factor) * mem_vector_factor;
    #else
    int grid_size_x = size[0] - d_m[0] + d_p[0];
    #endif
#endif

    // Allocation
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        std::string name = std::string("u_") + std::to_string(bat);
        u[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);
        name = std::string("u2_") + std::to_string(bat);
        u2[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);
        name = std::string("f_") + std::to_string(bat);
        f[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);
        name = std::string("ref_") + std::to_string(bat);
        ref[bat] = ops_hls_decl_dat(blocks[bat],  1,  size,  base,  d_m,  d_p,  temp,  "float",  name.c_str(), mem_vector_factor);
#ifdef VERIFICATION
        u_cpu[bat] = (float*)malloc(sizeof(float) * grid_size_x * grid_size_y * grid_size_z * batch_size);
        u2_cpu[bat] = (float*)malloc(sizeof(float) * grid_size_x * grid_size_y * grid_size_z * batch_size);
        f_cpu[bat] = (float*)malloc(sizeof(float) * grid_size_x * grid_size_y * grid_size_z * batch_size);
        ref_cpu[bat] = (float*)malloc(sizeof(float) * grid_size_x * grid_size_y * grid_size_z * batch_size);
#endif
    }


    int full_range[] = {d_m[0], size[0] + d_p[0], d_m[1], size[1] + d_p[1],  d_m[2], size[2] + d_p[2]};
    int internal_range[] = {0, size[0], 0, size[1], 0, size[2]};

    #ifdef POWER_PROFILE
    for (unsigned int p = 0; p < power_iter; p++)
    {
#endif
#ifndef OPS_FPGA
    #ifdef BATCHING
        ops_par_loop_blocks_all(batch_size);
    #endif
#endif
    //Producer
    for (unsigned int bat = 0; bat < batches; bat++)
    {
#ifdef PROFILE
        auto init_start_clk_point =  std::chrono::high_resolution_clock::now();
#endif
#ifdef VERIFICATION
        initialise_grid(u_cpu[bat], size, d_m, d_p, full_range, batch_size);
        // printGrid2D(u_cpu[bat], u[bat].originalProperty, "u_CPU after init");
        copy_grid(u2_cpu[bat], u_cpu[bat], size, d_m, d_p, full_range, batch_size);

        ops_dat_fetch_data(u[bat], 0, (char*)u_cpu[bat]);

        ops_par_loop(kernel_copy, "kernel_update", blocks[bat], 3, full_range, 
            ops_arg_dat(u[bat], 1, S3D_00, "float", OPS_READ),
            ops_arg_dat(u2[bat], 1, S3D_00, "float", OPS_WRITE));
#else
        ops_par_loop_kernel_populate( blocks[bat],  3 ,  full_range, u[bat]);

        ops_par_loop_kernel_initialguess( blocks[bat],  3 ,  internal_range, u[bat]);

        ops_par_loop_kernel_copy( blocks[bat],  3 ,  full_range, u[bat], u2[bat]);
#endif
#ifdef PROFILE
        auto init_end_clk_point = std::chrono::high_resolution_clock::now();
        init_runtime[bat] = std::chrono::duration<double, std::micro> (init_end_clk_point - init_start_clk_point).count();
#endif

#ifdef VERIFICATION
        auto u_raw = (float*)u[bat].get_raw_pointer();
        auto u2_raw = (float*)u2[bat].get_raw_pointer();

        // printGrid3D(u_raw, u[bat].originalProperty, "test");

        if(verify(u_raw, u_cpu[bat], size, d_m, d_p, full_range, batch_size))
            std::cout << "[BATCH - " << bat << "] verification of u after initiation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of u after initiation" << "[FAILED]" << std::endl;

        if(verify(u2_raw, u2_cpu[bat], size, d_m, d_p, full_range, batch_size))
            std::cout << "[BATCH - " << bat << "] verification of u2 after initiation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of u2 after initiation" << "[FAILED]" << std::endl;
#endif
    }

    //iterative stencil loop
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        printf("Launching jacobian3d calculation: %d x %d x %d mesh\n", size[0], size[1], size[2]);
#ifdef PROFILE
        auto main_loop_start_clk_point = std::chrono::high_resolution_clock::now();
#endif
#ifdef OPS_FPGA
#endif
        isl0(iter_max, internal_range, u[bat], u2[bat]);

#ifdef PROFILE
    #ifndef OPS_FPGA
        auto main_loop_end_clk_point = std::chrono::high_resolution_clock::now();
        main_loop_runtime[bat] = std::chrono::duration<double, std::micro>(main_loop_end_clk_point - main_loop_start_clk_point).count();
    #endif
#endif
    }
#ifndef OPS_FPGA
    #ifndef BATCHING
    ops_par_loop_blocks_end();
    #endif
#endif

#ifdef POWER_PROFILE
    }
#endif
    //Final Verification after calc
#ifdef VERIFICATION
    for (unsigned int bat = 0; bat < batches; bat++)
    {
        auto u_raw = (float*)u[bat].get_raw_pointer();
        auto u2_raw = (float*)u2[bat].get_raw_pointer();

        for (int iter = 0; iter < iter_max; iter++)
        {
            stencil_computation(u_cpu[bat], u2_cpu[bat], size, d_m, d_p, internal_range, batch_size);
            copy_grid(u_cpu[bat], u2_cpu[bat], size, d_m, d_p, internal_range, batch_size);
        }

		// printGrid3D<float>(u_raw, u[bat].originalProperty, "u after computation");
		// printGrid3D<float>(u_cpu[bat], u[bat].originalProperty, "u_Acpu after computation");

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
        ops_free_dat(f[bat]);
        ops_free_dat(ref[bat]);
#ifdef VERIFICATION
        free(u_cpu[bat]);
        free(u2_cpu[bat]);
        free(f_cpu[bat]);
        free(ref_cpu[bat]);
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