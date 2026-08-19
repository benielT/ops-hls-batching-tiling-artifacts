// Auto-generated at 2026-08-18 12:56:49.590817 by ops-translator

#pragma once
#include <ops_hls_kernel_support.h>
#include "../../common/include/common_config.hpp"

extern "C" void repeater_outerloop_0(
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
{
    #pragma HLS INTERFACE axis port = arg0_0_axis_in register     #pragma HLS INTERFACE axis port = arg0_1_axis_in register     #pragma HLS INTERFACE axis port = arg0_2_axis_in register     #pragma HLS INTERFACE axis port = arg0_3_axis_in register     #pragma HLS INTERFACE axis port = arg0_4_axis_in register     #pragma HLS INTERFACE axis port = arg0_5_axis_in register     #pragma HLS INTERFACE axis port = arg0_6_axis_in register     #pragma HLS INTERFACE axis port = arg0_7_axis_in register     #pragma HLS INTERFACE axis port = arg1_0_axis_out register     #pragma HLS INTERFACE axis port = arg1_1_axis_out register     #pragma HLS INTERFACE axis port = arg1_2_axis_out register     #pragma HLS INTERFACE axis port = arg1_3_axis_out register     #pragma HLS INTERFACE axis port = arg1_4_axis_out register     #pragma HLS INTERFACE axis port = arg1_5_axis_out register     #pragma HLS INTERFACE axis port = arg1_6_axis_out register     #pragma HLS INTERFACE axis port = arg1_7_axis_out register 
    #pragma HLS INTERFACE ap_ctrl_none port=return
    
    #pragma HLS PIPELINE II=1 style=flp
    
    arg1_0_axis_out.write(arg0_0_axis_in.read());
    arg1_1_axis_out.write(arg0_1_axis_in.read());
    arg1_2_axis_out.write(arg0_2_axis_in.read());
    arg1_3_axis_out.write(arg0_3_axis_in.read());
    arg1_4_axis_out.write(arg0_4_axis_in.read());
    arg1_5_axis_out.write(arg0_5_axis_in.read());
    arg1_6_axis_out.write(arg0_6_axis_in.read());
    arg1_7_axis_out.write(arg0_7_axis_in.read());
}