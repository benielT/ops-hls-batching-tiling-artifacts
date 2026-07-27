// Auto-generated at 2026-07-26 21:35:16.751907 by ops-translator

#pragma once
#include <ops_hls_kernel_support.h>
#include "../../common/include/common_config.hpp"

extern "C" void repeater_outerloop_0(
    //dat_current
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in,
    //dat_a
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out,
    //dat_b
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_out,
    //dat_c
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_out,
    //dat_next
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg4_axis_out
)
{
    #pragma HLS INTERFACE axis port = arg0_axis_in register     #pragma HLS INTERFACE axis port = arg1_axis_in register     #pragma HLS INTERFACE axis port = arg1_axis_out register     #pragma HLS INTERFACE axis port = arg2_axis_in register     #pragma HLS INTERFACE axis port = arg2_axis_out register     #pragma HLS INTERFACE axis port = arg3_axis_in register     #pragma HLS INTERFACE axis port = arg3_axis_out register     #pragma HLS INTERFACE axis port = arg4_axis_out register 
    #pragma HLS INTERFACE ap_ctrl_none port=return
    
    #pragma HLS PIPELINE II=1 style=flp
    
    arg4_axis_out.write(arg0_axis_in.read());
    arg1_axis_out.write(arg1_axis_in.read());
    arg2_axis_out.write(arg2_axis_in.read());
    arg3_axis_out.write(arg3_axis_in.read());
}