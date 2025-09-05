
// Auto-generated at 2025-09-05 12:43:07.712213 by ops-translator

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

/** @brief Test application for 1D fpga blackscholes application based on OPS-DSL
  * @author Beniel Thileepan
  * @details
  *
  *  This version is based on C/C++ and uses the OPS prototype highlevel domain
  *  specific API for developing multi-block Structured mesh applications.
  *  Coded in C API.
  */

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include "blackscholes_utils.h"
#include "blackscholes_cpu.h"

#define OPS_1D
#define OPS_HLS_V2
// #define OPS_FPGA
// #define VERIFICATION
// #define DEBUG_VERBOSE
// #define PROFILE
// #define POWER_PROFILE
#include "ops_lib_core.h"
#include <ops_seq_v2.h>
#include <ops_hls_rt_support.h>
#include <hls_kernels.hpp>
#include "blackscholes_kernels.h"
/* ops_par_loop declarations */

void ops_par_loop_ops_krnl_zero_init(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_const_init(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_interior_init(ops::hls::Block, int, int*, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_copy(ops::hls::Block, int, int*, ops::hls::Grid<float>&, ops::hls::Grid<float>&);

void ops_par_loop_ops_krnl_calc_coefficient(ops::hls::Block, int, int*, ops::hls::Grid<float>&, ops::hls::Grid<float>&, ops::hls::Grid<float>&);


extern const unsigned short mem_vector_factor;

#ifdef POWER_PROFILE
    unsigned int power_iter = 1;
    #ifdef PROFILE
    std::cerr << "POWER_PROFILE cannot be enabled with PROFILE" << std::endl;
    exit(-1);
    #endif  
#endif

int main(int argc, const char **argv)
{
    // OPS initialisation
	ops_init_backend(argc, argv);


	GridParameter gridProp;
	gridProp.logical_size_x = 180;
	gridProp.logical_size_y = 1;
	gridProp.batch = 1;
	gridProp.num_iter = 6000;
    gridProp.batch_size = 1;

    	// setting grid parameters given by user
	const char* pch;

	for ( int n = 1; n < argc; n++ )
	{
		pch = strstr(argv[n], "-sizex=");

		if(pch != NULL)
		{
			gridProp.logical_size_x = atoi ( argv[n] + 7 ); continue;
		}

		pch = strstr(argv[n], "-iters=");

		if(pch != NULL)
		{
			gridProp.num_iter = atoi ( argv[n] + 7 ); continue;
		}
		pch = strstr(argv[n], "-batch=");

		if(pch != NULL)
		{
			gridProp.batch = atoi ( argv[n] + 7 ); continue;
		}
#ifdef BATCHING
        pch = strstr(argv[n], "-bsize=");
        if(pch != NULL) {
            gridProp.batch_size = atoi ( argv[n] + 7 );
            if(gridProp.batch_size < 1) {
                std::cerr << "Batch size must be greater than 0" << std::endl;
                exit(-1);
            }
            continue;
        }
#endif
#ifdef POWER_PROFILE
        pch = strstr(argv[n], "-piter=");
        if(pch != NULL) {
            power_iter = atoi ( argv[n] + 7 );  continue;
        }
#endif
	}

#ifdef POWER_PROFILE
    gridProp.batch = 1; // batch is not used in power profiling
    #ifdef BATCHING
    if(power_iter % gridProp.batch_size != 0) {
            std::cerr << "Batch size must divide the number of power batches evenly" << std::endl;
            exit(-1);
    }
    std::cout << "Total power iterations: " << power_iter << std::endl;
    std::cout << "Power profiling enabled, number of power iterations per batch: " << power_iter / gridProp.batch_size << std::endl;
    power_iter = power_iter / gridProp.batch_size;
    #endif 
    std::cout << "Power profiling enabled, number of power iterations: " << power_iter << std::endl;
#else
    if(gridProp.batch % gridProp.batch_size != 0) {
        std::cerr << "Batch size must divide the number of batches evenly" << std::endl;
        exit(-1);
    }

    gridProp.batch /= gridProp.batch_size;
    std::cout << "Batching enabled, number of batches: " << gridProp.batch << ", batch size: " << gridProp.batch_size << std::endl;
#endif
    printf("Grid: %dx1 , %d iterations, %d batches\n", gridProp.logical_size_x, gridProp.num_iter, gridProp.batch);

	//adding halo
	gridProp.act_size_x = gridProp.logical_size_x+2;
	gridProp.act_size_y = 1;

	//padding each row as multiple of vectorization factor
#ifdef OPS_FPGA
	gridProp.grid_size_x = (gridProp.act_size_x % mem_vector_factor) != 0 ?
			(gridProp.act_size_x/mem_vector_factor + 1) * mem_vector_factor :
			gridProp.act_size_x;
#else
gridProp.grid_size_x = gridProp.act_size_x;
#endif
	gridProp.grid_size_y = gridProp.act_size_y;

	//allocating memory buffer
	unsigned int data_size_bytes = gridProp.grid_size_x * gridProp.grid_size_y * sizeof(float) * gridProp.batch * gridProp.batch_size;

	if(data_size_bytes >= 4000000000)
	{
		std::cerr << "Maximum buffer size is exceeded!" << std::endl;
		return -1;
	}

#ifdef PROFILE
	double init_cpu_runtime[gridProp.batch];
	double main_loop_cpu_runtime[gridProp.batch];
	double init_runtime[gridProp.batch];
	double main_loop_runtime[gridProp.batch];

    std::string profile_filename = "perf_profile.csv";

    std::ofstream fstream;
    fstream.open(profile_filename, std::ios::out | std::ios::trunc);

    if (!fstream.is_open()) {
        std::cerr << "Error: Could not open the file " << profile_filename << std::endl;
        return 1; // Indicate an error occurred
    }
#endif
	std::vector<blackscholesParameter> calcParam(gridProp.batch * gridProp.batch_size); //multiple blackscholes calculations

	//First calculation for test value

	calcParam[0].spot_price = 16;
	calcParam[0].strike_price = 10;
	calcParam[0].time_to_maturity = 0.25;
	calcParam[0].volatility = 0.4;
	calcParam[0].risk_free_rate = 0.1;
	calcParam[0].N = gridProp.num_iter;
	calcParam[0].K = gridProp.logical_size_x;
	calcParam[0].SMaxFactor = 3;
	calcParam[0].delta_t = calcParam[0].time_to_maturity / calcParam[0].N;
	calcParam[0].delta_S = calcParam[0].strike_price * calcParam[0].SMaxFactor/ (calcParam[0].K);
	calcParam[0].stable = stencil_stability(calcParam[0]);

	std::random_device dev;
	std::mt19937 rndGen(dev());
	std::uniform_real_distribution<> dis(0.0, 0.05);

	for (int i = 1; i < gridProp.batch * gridProp.batch_size; i++)
	{
		calcParam[i].spot_price = 16 + dis(rndGen);
		calcParam[i].strike_price = 10 + dis(rndGen);
		calcParam[i].time_to_maturity = 0.25 + dis(rndGen);
		calcParam[i].volatility = 0.4 + dis(rndGen);
		calcParam[i].risk_free_rate = 0.1 + dis(rndGen);
		calcParam[i].N = gridProp.num_iter;
		calcParam[i].K = gridProp.logical_size_x;
		calcParam[i].SMaxFactor = 3;
		calcParam[i].delta_t = calcParam[i].time_to_maturity / calcParam[i].N;
		calcParam[i].delta_S = calcParam[i].strike_price * calcParam[i].SMaxFactor/ (calcParam[i].K);
		calcParam[i].stable = stencil_stability(calcParam[i]);

		if (not calcParam[i].stable)
		{
			std::cerr << "Calc job: " << i << " is unstable" << std::endl;
		}
	}

	//ops::hls::Block
    ops::hls::Block grid1D[gridProp.batch];

    for (unsigned int bat = 0; bat < gridProp.batch; bat++)
    {
        std::string name = std::string("batch_") + std::to_string(bat);
#ifndef BATCHING
        grid1D[bat] = ops_hls_decl_block(1, name.c_str());
#else
        grid1D[bat] = ops_hls_decl_block_batch(1, name.c_str(), gridProp.batch_size);
#endif
    }

	//ops_data
	int size[] = {static_cast<int>(gridProp.logical_size_x)};
	int base[] = {0};
	int d_m[] = {-1};
	int d_p[] = {1};

	ops::hls::Grid<stencil_type> dat_current[gridProp.batch]; // = ops_hls_decl_dat(grid1D,  1,  size,  base,  d_m,  d_p,  current, "float",  "dat_current", mem_vector_factor);
	ops::hls::Grid<stencil_type> dat_next[gridProp.batch];// = ops_hls_decl_dat(grid1D,  1,  size,  base,  d_m,  d_p,  next, "float",  "dat_next", mem_vector_factor);
	ops::hls::Grid<stencil_type> dat_a[gridProp.batch]; // = ops_hls_decl_dat(grid1D,  1,  size,  base,  d_m,  d_p,  a,  "float",  "dat_a", mem_vector_factor);
	ops::hls::Grid<stencil_type> dat_b[gridProp.batch]; // = ops_hls_decl_dat(grid1D,  1,  size,  base,  d_m,  d_p,  b,  "float",  "dat_b", mem_vector_factor);
	ops::hls::Grid<stencil_type> dat_c[gridProp.batch]; // = ops_hls_decl_dat(grid1D,  1,  size,  base,  d_m,  d_p,  c,  "float",  "dat_c", mem_vector_factor);

#ifdef VERIFICATION
    float * grid_u1_cpu[gridProp.batch]; // = (float*) aligned_alloc(4096, data_size_bytes);
	float * grid_u2_cpu[gridProp.batch]; // = (float*) aligned_alloc(4096, data_size_bytes);
#endif
	//Allocation
	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
		float *current = nullptr, *next = nullptr;
		float *a = nullptr, *b = nullptr, *c = nullptr;

		std::string name = std::string("current_") + std::to_string(bat);
		dat_current[bat] = ops_hls_decl_dat(grid1D[bat],  1,  size,  base,  d_m,  d_p,  current, "float",  name.c_str(), mem_vector_factor);
		name = std::string("next_") + std::to_string(bat);
		dat_next[bat] = ops_hls_decl_dat(grid1D[bat],  1,  size,  base,  d_m,  d_p,  next, "float",  name.c_str(), mem_vector_factor);
		name = std::string("a_") + std::to_string(bat);
		dat_a[bat] = ops_hls_decl_dat(grid1D[bat],  1,  size,  base,  d_m,  d_p,  a,  "float",  name.c_str(), mem_vector_factor);
		name = std::string("b_") + std::to_string(bat);
		dat_b[bat] = ops_hls_decl_dat(grid1D[bat],  1,  size,  base,  d_m,  d_p,  a,  "float",  name.c_str(), mem_vector_factor);
		name = std::string("x_") + std::to_string(bat);
		dat_c[bat] = ops_hls_decl_dat(grid1D[bat],  1,  size,  base,  d_m,  d_p,  a,  "float",  name.c_str(), mem_vector_factor);
#ifdef VERIFICATION
		grid_u1_cpu[bat] = (float*) aligned_alloc(4096, data_size_bytes);
		grid_u2_cpu[bat] = (float*) aligned_alloc(4096, data_size_bytes);
#endif
	}

#ifdef VERIFICATION
	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
	#ifdef PROFILE
		auto init_start_clk_point = std::chrono::high_resolution_clock::now();
	#endif

		intialize_grid(grid_u1_cpu[bat], gridProp, calcParam[bat]);
		copy_grid(grid_u1_cpu[bat], grid_u2_cpu[bat], gridProp);

	#ifdef PROFILE
		auto init_stop_clk_point = std::chrono::high_resolution_clock::now();
		init_cpu_runtime[bat] = std::chrono::duration<double, std::micro> (init_stop_clk_point - init_start_clk_point).count();
	#endif
	}
	
	#ifdef DEBUG_VERBOSE
	std::cout << std::endl;
	std::cout << "*********************************************"  << std::endl;
	std::cout << "**            intial grid values           **"  << std::endl;
	std::cout << "*********************************************"  << std::endl;

	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
        for (unsigned int sub_bat = 0; sub_bat < gridProp.batch_size; sub_bat++)
        {
            unsigned offset = sub_bat * gridProp.grid_size_x;
            std::cout << "Batch [" << bat << ":" << sub_bat << "]" << std::endl;

            for (unsigned int i = 0; i < gridProp.act_size_x; i++)
            {
			std::cout << "index: " << i << " initial_val: " << grid_u1_cpu[bat][offset + i]<< std::endl;
            }
		}
	}
	std::cout << "============================================="  << std::endl << std::endl;
	#endif
#endif
	//defining the stencils
	int s1d_3pt[] = {-1, 0, 1};
	int s1d_1pt[] = {0};


	//partition

	int lower_Pad_range[] = {-1,0};
	int upper_pad_range[] = {gridProp.logical_size_x, gridProp.logical_size_x + 1};
	int interior_range[] = {0, gridProp.logical_size_x};
	int full_range[] = {-1, gridProp.logical_size_x + 1};

	//initializing data
	for (int bat = 0; bat < gridProp.batch; bat++)
	{
#ifdef PROFILE
		auto grid_init_start_clk_point = std::chrono::high_resolution_clock::now();
#endif
		ops_par_loop_ops_krnl_zero_init( grid1D[bat],  1 ,  lower_Pad_range, dat_current[bat]);

		
		float sMax = calcParam[bat].SMaxFactor * calcParam[bat].strike_price;

		ops_par_loop_ops_krnl_const_init( grid1D[bat],  1 ,  upper_pad_range, dat_current[bat], &sMax);
		
		float* delta_s = &calcParam[bat].delta_S;
		float* strike_price = &calcParam[bat].strike_price;

		ops_par_loop_ops_krnl_interior_init( grid1D[bat],  1 ,  interior_range, dat_current[bat], delta_s, strike_price);


		ops_par_loop_ops_krnl_copy( grid1D[bat],  1 ,  full_range, dat_current[bat], dat_next[bat]);

		//blackscholes calc
		float alpha = calcParam[bat].volatility * calcParam[bat].volatility * calcParam[bat].delta_t;
		float beta = calcParam[bat].risk_free_rate * calcParam[bat].delta_t;

		ops_par_loop_ops_krnl_calc_coefficient( grid1D[bat],  1 ,  interior_range, dat_a[bat], dat_b[bat], dat_c[bat], &(alpha), &(beta));

#ifdef VERIFICATION
    for (unsigned int bat = 0; bat < gridProp.batch; bat++)
    { 
        float* current_raw = (float*)dat_current[bat].get_raw_pointer();
		float* next_raw = (float*)dat_next[bat].get_raw_pointer();
        float* a_raw = (float*)dat_a[bat].get_raw_pointer();
        float* b_raw = (float*)dat_b[bat].get_raw_pointer();
        float* c_raw = (float*)dat_c[bat].get_raw_pointer();

    #ifdef DEBUG_VERBOSE

        printGrid2D<float>(current_raw, dat_current[bat].originalProperty, "curr after init");
		printGrid2D<float>(next_raw, dat_next[bat].originalProperty, "next after init");
		printGrid2D<float>(a_raw, dat_a[bat].originalProperty, "coeff a after init");
        printGrid2D<float>(b_raw, dat_b[bat].originalProperty, "coeff b after init");
        printGrid2D<float>(c_raw, dat_c[bat].originalProperty, "coeff c after init");
        printGrid2D<float>(grid_u1_cpu[bat], dat_current[bat].originalProperty, "curr CPU after init");
        printGrid2D<float>(grid_u2_cpu[bat], dat_next[bat].originalProperty, "next CPU after init");
	#endif
    }
#endif

#ifdef PROFILE
		auto grid_init_stop_clk_point = std::chrono::high_resolution_clock::now();
		init_runtime[bat] = std::chrono::duration<double, std::micro>(grid_init_stop_clk_point - grid_init_start_clk_point).count();
		auto blackscholes_calc_start_clk_point = grid_init_stop_clk_point;
#endif
#ifdef POWER_PROFILE
    for (unsigned int p = 0; p < power_iter; p++)
    {
        std::cout << "Power profiling iter: " << p << " of " << power_iter << std::endl;
#endif
#ifdef OPS_FPGA
#endif 
// #ifndef OPS_FPGA
		isl0(calcParam[bat].N, interior_range, dat_current[bat], dat_a[bat], dat_b[bat], dat_c[bat], dat_next[bat]);
// #else
//         ops_iter_par_loop("ops_iter_par_loop_0", calcParam[bat].N,
// 			ops_par_loop(ops_krnl_blackscholes, "blackscholes_1", grid1D[bat], 1, interior_range,
// 					ops_arg_dat(dat_next[bat], 1, S1D_1pt, "float", OPS_WRITE),
// 					ops_arg_dat(dat_current[bat], 1, S1D_3pt, "float", OPS_READ),
// 					ops_arg_dat(dat_a[bat], 1, S1D_1pt, "float", OPS_READ),
// 					ops_arg_dat(dat_b[bat], 1, S1D_1pt, "float", OPS_READ),
// 					ops_arg_dat(dat_c[bat], 1, S1D_1pt, "float", OPS_READ)),
//             // ops_par_copy<float>(dat_current[bat], dat_next[bat])
//             ops_par_loop(ops_krnl_copy, "copy_1", grid1D[bat], 1, interior_range,
//                     ops_arg_dat(dat_next[bat], 1, S1D_3pt, "float", OPS_READ),
//                     ops_arg_dat(dat_current[bat], 1, S1D_1pt, "float", OPS_WRITE))
//             );
// #endif

#ifdef PROFILE
     #ifndef OPS_FPGA
		auto blackscholes_calc_stop_clk_point = std::chrono::high_resolution_clock::now();
		main_loop_runtime[bat] = std::chrono::duration<double, std::micro>(blackscholes_calc_stop_clk_point - blackscholes_calc_start_clk_point).count();
    #endif
#endif  
#ifdef POWER_PROFILE
    }
#endif
}

#ifdef VERIFICATION
    for (unsigned int bat = 0; bat < gridProp.batch; bat++)
    { 
	#ifdef PROFILE
		auto naive_start_clk_point = std::chrono::high_resolution_clock::now();
	#endif
		//golden computation
		bs_explicit1(grid_u1_cpu[bat], grid_u2_cpu[bat], gridProp, calcParam[bat]);
		copy_grid(grid_u1_cpu[bat], grid_u2_cpu[bat], gridProp);

	
	#ifdef PROFILE
		auto naive_stop_clk_point = std::chrono::high_resolution_clock::now();
		main_loop_cpu_runtime[bat] = std::chrono::duration<double, std::micro> (naive_stop_clk_point - naive_start_clk_point).count(); 
	#endif
	}

	std::cout << std::endl;
	std::cout << "*********************************************"  << std::endl;
	std::cout << "**      Debug info after calculations      **"  << std::endl;
	std::cout << "*********************************************"  << std::endl;

	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
		float* current_raw = (float*)dat_current[bat].get_raw_pointer();
		float* next_raw = (float*)dat_next[bat].get_raw_pointer();

	#ifdef DEBUG_VERBOSE
        printGrid2D<float>(current_raw, dat_next[bat].originalProperty, "curr after computation");
		printGrid2D<float>(next_raw, dat_next[bat].originalProperty, "next after computation");
		printGrid2D<float>(grid_u2_cpu[bat], dat_next[bat].originalProperty, "next_Acpu after computation");
	#endif

        if(verify(next_raw, grid_u2_cpu[bat], size, d_m, d_p, full_range, gridProp.batch_size))
            std::cout << "[BATCH - " << bat << "] verification of current after calculation" << "[PASSED]" << std::endl;
        else
            std::cout << "[BATCH - " << bat << "] verification of current after calculation" << "[FAILED]" << std::endl;

        for (unsigned int sub_bat = 0; sub_bat < gridProp.batch_size; sub_bat++)
        {
            //explicit blackscholes test
    	    float direct_calc_value = test_blackscholes_call_option(calcParam[bat * gridProp.batch_size + sub_bat], nullptr);

            std::cout <<  "Batch [" << bat << ":" << sub_bat << "] call option price from cpu direct calc method: " << direct_calc_value << std::endl;	
            std::cout <<  "Batch [" << bat << ":" << sub_bat << "] call option price from cpu explicit iter method: " << get_call_option(grid_u2_cpu[bat], calcParam[bat * gridProp.batch_size + sub_bat], sub_bat, gridProp.grid_size_x) << std::endl;
            std::cout <<  "Batch [" << bat << ":" << sub_bat << "] call option price from ops explicit method: " << get_call_option(next_raw, calcParam[bat * gridProp.batch_size + sub_bat], sub_bat, gridProp.grid_size_x) << std::endl;
        }
	}
	std::cout << "============================================="  << std::endl << std::endl;
#endif
	
	    //cleaning
    for (unsigned int bat = 0; bat < gridProp.batch; bat++)
    {
        ops_free_dat(dat_current[bat]);
        ops_free_dat(dat_next[bat]);
        ops_free_dat(dat_a[bat]);
        ops_free_dat(dat_b[bat]);
		ops_free_dat(dat_c[bat]);
#ifdef VERIFICATION
        free(grid_u1_cpu[bat]);
        free(grid_u2_cpu[bat]);
#endif
    }
//	for (int i = 0; i < gridProp.logical_size_x; i++)
//	{
//		std::cout << "idx: " << i << ", dat_current: " << grid_ops_result[i] << std::endl;
//	}
//	ops_print_dat_to_txtfile_core(dat_current, "dat_current.txt");
//	ops_print_dat_to_txtfile_core(dat_next, "dat_next.txt");
	
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
    std::cout << "[WARNING] The runtime is averaged over the batch size of " << gridProp.batch_size << std::endl;

	#ifdef VERIFICATION
	double cpu_avg_main_loop_runtime = 0;
	double cpu_max_main_loop_runtime = 0;
	double cpu_min_main_loop_runtime = 0;
	double cpu_avg_init_runtime = 0;
	double cpu_max_init_runtime = 0;
	double cpu_min_init_runtime = 0;
	double cpu_main_loop_std = 0;
	double cpu_init_std = 0;
	double cpu_total_std = 0;
	#endif

	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
    #ifdef OPS_FPGA
        main_loop_runtime[bat] = ops_hls_get_execution_runtime<std::chrono::microseconds>(std::string("isl0"), bat);
    #endif
        main_loop_runtime[bat] /= gridProp.batch_size;
        init_runtime[bat] /= gridProp.batch_size;

        fstream << gridProp.logical_size_x << "," << 1 << "," << 1 << "," << calcParam[bat].N << "," << 1 << "," << bat << "," << init_runtime[bat] \
                << "," << main_loop_runtime[bat] << "," << main_loop_runtime[bat] + init_runtime[bat] << std::endl;

		std::cout << "run: "<< bat << "| total runtime (DEVICE): " << main_loop_runtime[bat] + init_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> init runtime: " << init_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> main loop runtime: " << main_loop_runtime[bat] << "(us)" << std::endl;
	#ifdef VERIFICATION	
		std::cout << "| total runtime (CPU-golden): " << main_loop_cpu_runtime[bat] + init_cpu_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> init runtime: " << init_cpu_runtime[bat] << "(us)" << std::endl;
		std::cout << "     |--> main loop runtime: " << main_loop_cpu_runtime[bat] << "(us)" << std::endl;
	#endif
		avg_init_runtime += init_runtime[bat];
		avg_main_loop_runtime += main_loop_runtime[bat];
	#ifdef VERIFICATION
		cpu_avg_init_runtime += init_cpu_runtime[bat];
		cpu_avg_main_loop_runtime += main_loop_cpu_runtime[bat];
	#endif

		if (bat == 0)
		{
			max_main_loop_runtime = main_loop_runtime[bat];
			min_main_loop_runtime = main_loop_runtime[bat];
			max_init_runtime = init_runtime[bat];
			min_init_runtime = init_runtime[bat];
	#ifdef VERIFICATION
			cpu_max_main_loop_runtime = main_loop_cpu_runtime[bat];
			cpu_min_main_loop_runtime = main_loop_cpu_runtime[bat];
			cpu_max_init_runtime = init_cpu_runtime[bat];
			cpu_min_init_runtime = init_cpu_runtime[bat];
	#endif
		}
		else
		{
			max_main_loop_runtime = std::max(max_main_loop_runtime, main_loop_runtime[bat]);
			min_main_loop_runtime = std::min(min_main_loop_runtime, main_loop_runtime[bat]);
			max_init_runtime = std::max(max_init_runtime, init_runtime[bat]);
			min_init_runtime = std::min(min_init_runtime, init_runtime[bat]);
	#ifdef VERIFICATION
			cpu_max_main_loop_runtime = std::max(cpu_max_main_loop_runtime, main_loop_cpu_runtime[bat]);
			cpu_min_main_loop_runtime = std::min(cpu_min_main_loop_runtime, main_loop_cpu_runtime[bat]);
			cpu_max_init_runtime = std::max(cpu_max_init_runtime, init_cpu_runtime[bat]);
			cpu_min_init_runtime = std::min(cpu_min_init_runtime, init_cpu_runtime[bat]);
	#endif
		}
	}

	avg_init_runtime /= gridProp.batch;
	avg_main_loop_runtime /= gridProp.batch;

	#ifdef VERIFICATION
	cpu_avg_init_runtime /= gridProp.batch;
	cpu_avg_main_loop_runtime /= gridProp.batch;
	#endif

	for (unsigned int bat = 0; bat < gridProp.batch; bat++)
	{
		main_loop_std += std::pow(main_loop_runtime[bat] - avg_main_loop_runtime, 2);
		init_std += std::pow(init_runtime[bat] - avg_init_runtime, 2);
		total_std += std::pow(main_loop_runtime[bat] + init_runtime[bat] - avg_init_runtime - avg_main_loop_runtime, 2);
	#ifdef VERIFICATION
		cpu_main_loop_std += std::pow(main_loop_cpu_runtime[bat] - cpu_avg_main_loop_runtime, 2);
		cpu_init_std += std::pow(init_cpu_runtime[bat] - cpu_avg_init_runtime, 2);
		cpu_total_std += std::pow(main_loop_cpu_runtime[bat] + init_cpu_runtime[bat] - cpu_avg_init_runtime - cpu_avg_main_loop_runtime, 2);
	#endif
	}

	main_loop_std = std::sqrt(main_loop_std / gridProp.batch);
	init_std = std::sqrt(init_std / gridProp.batch);
	total_std = std::sqrt(total_std / gridProp.batch);
	#ifdef VERIFICATION
	cpu_main_loop_std = std::sqrt(cpu_main_loop_std / gridProp.batch);
	cpu_init_std = std::sqrt(cpu_init_std / gridProp.batch);
	cpu_total_std = std::sqrt(cpu_total_std / gridProp.batch);
	#endif
	std::cout << "Total runtime - DEVICE (AVG): " << avg_main_loop_runtime + avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << avg_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime - DEVICE (MIN): " << min_main_loop_runtime + min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << min_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime - DEVICE (MAX): " << max_main_loop_runtime + max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << max_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Standard Deviation init - DEVICE: " << init_std << std::endl;
	std::cout << "Standard Deviation main loop - DEVICE: " << main_loop_std << std::endl;
	std::cout << "Standard Deviation total - DEVICE: " << total_std << std::endl;
	#ifdef VERIFICATION
	std::cout << "Total runtime - CPU (AVG): " << cpu_avg_main_loop_runtime + cpu_avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << cpu_avg_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << cpu_avg_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime - CPU (MIN): " << cpu_min_main_loop_runtime + cpu_min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << cpu_min_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << cpu_min_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Total runtime - CPU (MAX): " << cpu_max_main_loop_runtime + cpu_max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> init runtime: " << cpu_max_init_runtime << "(us)" << std::endl;
	std::cout << "     |--> main loop runtime: " << cpu_max_main_loop_runtime << "(us)" << std::endl;
	std::cout << "Standard Deviation init - CPU: " << cpu_init_std << std::endl;
	std::cout << "Standard Deviation main loop - CPU: " << cpu_main_loop_std << std::endl;
	std::cout << "Standard Deviation total - CPU: " << cpu_total_std << std::endl;
	#endif
	std::cout << "======================================================" << std::endl;

    fstream << "args: " << "-sizex=" << gridProp.logical_size_x << " -iters=" << gridProp.num_iter << " -batch=" << gridProp.batch << " -bsize=" << gridProp.batch_size << std::endl;
    fstream.close();

    if (fstream.good()) { // Check if operations were successful after closing
        std::cout << "Successfully wrote data to " << profile_filename << std::endl;
    } else {
            std::cerr << "Error occurred during writing to " << profile_filename << std::endl;
            return 1; // Indicate an error occurred
    }
#endif

	//Finalizing the OPS library

	ops_exit_backend();


 	std::cout << "Exit properly" << std::endl;
    return 0;
}