// Auto-generated at 2026-07-05 14:05:30.453791 by ops-translator


#pragma once
#include <ops_hls_kernel_support.h>
#include "../../common/include/common_config.hpp"


extern "C" void datamover_outerloop_0(
        const unsigned short range_start_0,
        const unsigned short range_end_0,
        const unsigned short range_start_1,
        const unsigned short range_end_1,
        const unsigned short range_start_2,
        const unsigned short range_end_2,
        const unsigned short gridSize_0,
        const unsigned short gridSize_1,
        const unsigned short gridSize_2,
        const unsigned int outer_itr,
        const unsigned short tile_size_x,
        const unsigned short tile_size_y,
        const unsigned short overlap_size_x,
        const unsigned short overlap_size_y,
        const unsigned short effective_tile_size_x,
        const unsigned short effective_tile_size_y,
        const unsigned short last_tile_size_x,
        const unsigned short last_tile_size_y,
        const unsigned short tile_count_x,
        const unsigned short tile_count_y,
        const unsigned int total_xblocks,
    //u
        ap_uint<mem_data_width>* arg0_b0,
        ap_uint<mem_data_width>* arg0_b1,
        ap_uint<mem_data_width>* arg0_b2,
        ap_uint<mem_data_width>* arg0_b3,
        ap_uint<mem_data_width>* arg0_b4,
        ap_uint<mem_data_width>* arg0_b5,
        ap_uint<mem_data_width>* arg0_b6,
        ap_uint<mem_data_width>* arg0_b7,
    //u2
        ap_uint<mem_data_width>* arg1_b0,
        ap_uint<mem_data_width>* arg1_b1,
        ap_uint<mem_data_width>* arg1_b2,
        ap_uint<mem_data_width>* arg1_b3,
        ap_uint<mem_data_width>* arg1_b4,
        ap_uint<mem_data_width>* arg1_b5,
        ap_uint<mem_data_width>* arg1_b6,
        ap_uint<mem_data_width>* arg1_b7,
        //u
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_0_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_1_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_2_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_3_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_4_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_5_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_6_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_7_axis_out,
    //u2
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_0_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_1_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_2_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_3_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_4_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_5_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_6_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_7_axis_in

    )
;
