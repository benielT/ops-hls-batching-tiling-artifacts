// Auto-generated at 2026-08-13 00:16:01.962874 by ops-translator
#pragma once
#include "PE_poisson_kernel_stencil.hpp"





extern "C" void kernel_outerloop_0_0
(
        const unsigned short slr_region,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
#ifndef OPS_TILING
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
#endif
        const unsigned short stencilConfig_outer_loop_limit,
#ifndef OPS_TILING
        const unsigned short stencilConfig_batch_size,
#else
        const unsigned short tile_size_x,
        const unsigned short last_tile_size_x,
        const unsigned short tile_count_x,
        const unsigned int total_xblocks,
        const unsigned short last_tile_upper_limit_x,
#endif
    //u
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_0_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_1_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_2_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_3_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_4_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_5_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_6_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_7_axis_in,
    //u2
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_0_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_1_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_2_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_3_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_4_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_5_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_6_axis_out,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_7_axis_out
)
;
