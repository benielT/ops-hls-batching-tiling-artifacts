// Auto-generated at 2025-09-04 18:06:18.052173 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0.hpp>

static void joint_PE_outerloop_0(const unsigned short PEId, const ops::hls::StencilConfigCore& stencilConfig, 
        ::hls::stream<ap_uint<axis_data_width>>& arg0_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg1_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg1_hls_stream_out, 
        ::hls::stream<ap_uint<axis_data_width>>& arg2_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg2_hls_stream_out, 
        ::hls::stream<ap_uint<axis_data_width>>& arg3_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg3_hls_stream_out, 
        ::hls::stream<ap_uint<axis_data_width>>& arg4_hls_stream_out
)
{
    ::hls::stream<ap_uint<axis_data_width>> node2_0_to_node3_0;
    #pragma HLS STREAM variable = node2_0_to_node3_0 depth = 10

    kernel_ops_krnl_blackscholes_PE(PEId, stencilConfig,
            arg4_hls_stream_out,
            arg0_hls_stream_in,
            arg1_hls_stream_in,
            arg1_hls_stream_out,
            arg2_hls_stream_in,
            arg2_hls_stream_out,
            arg3_hls_stream_in,
            arg3_hls_stream_out
    );
}



static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short& slr_region, const ops::hls::StencilConfigCore& stencilConfig,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg2_arg2_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg3_arg3_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg4_arg4_streams[iter_par_factor + 1]
)
{
#pragma HLS INLINE 

    const unsigned short PEId_offset = slr_region * iter_par_factor;

    for (int i = 0; i < iter_par_factor; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor
        joint_PE_outerloop_0(PEId_offset + i, stencilConfig,
                arg0_arg1_streams[i],
                arg2_arg2_streams[i], arg2_arg2_streams[i+1],
                arg3_arg3_streams[i], arg3_arg3_streams[i+1],
                arg4_arg4_streams[i], arg4_arg4_streams[i+1],
                arg0_arg1_streams[i+1]
        );
    }
}
static void kernel_outerloop_0_dataflow_region(const unsigned short& slr_region, const ops::hls::StencilConfigCore& stencilConfig, const unsigned int total_bytes,
hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in,  hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out,  hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_in, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_out,  hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_in, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_out, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg4_axis_out)
{
#pragma HLS DATAFLOW
::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1];
    #pragma HLS STREAM variable = arg0_arg1_streams depth = 10
::hls::stream<ap_uint<axis_data_width>> arg2_arg2_streams[iter_par_factor + 1];
    #pragma HLS STREAM variable = arg2_arg2_streams depth = 10
::hls::stream<ap_uint<axis_data_width>> arg3_arg3_streams[iter_par_factor + 1];
    #pragma HLS STREAM variable = arg3_arg3_streams depth = 10
::hls::stream<ap_uint<axis_data_width>> arg4_arg4_streams[iter_par_factor + 1];
    #pragma HLS STREAM variable = arg4_arg4_streams depth = 10
    
        ops::hls::axis2stream<axis_data_width, axis_data_width>(arg0_axis_in, arg0_arg1_streams[0], total_bytes);
        ops::hls::axis2stream<axis_data_width, axis_data_width>(arg1_axis_in, arg2_arg2_streams[0], total_bytes);
        ops::hls::axis2stream<axis_data_width, axis_data_width>(arg2_axis_in, arg3_arg3_streams[0], total_bytes);
        ops::hls::axis2stream<axis_data_width, axis_data_width>(arg3_axis_in, arg4_arg4_streams[0], total_bytes);

        kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, arg0_arg1_streams, arg2_arg2_streams, arg3_arg3_streams, arg4_arg4_streams);

        ops::hls::stream2axis<axis_data_width, axis_data_width>(arg1_axis_out, arg2_arg2_streams[iter_par_factor], total_bytes);
        ops::hls::stream2axis<axis_data_width, axis_data_width>(arg2_axis_out, arg3_arg3_streams[iter_par_factor], total_bytes);
        ops::hls::stream2axis<axis_data_width, axis_data_width>(arg3_axis_out, arg4_arg4_streams[iter_par_factor], total_bytes);
        ops::hls::stream2axis<axis_data_width, axis_data_width>(arg4_axis_out, arg0_arg1_streams[iter_par_factor], total_bytes);

}

extern "C" void kernel_outerloop_0(
        const unsigned short slr_region,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_outer_loop_limit,
        const unsigned short stencilConfig_batch_size,
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
    #pragma HLS INTERFACE s_axilite port = slr_region bundle = control
    #pragma HLS INTERFACE s_axilite port = outer_itr bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_dim bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_total_itr bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_outer_loop_limit bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_batch_size bundle = control

    

    #pragma HLS INTERFACE axis port = arg0_axis_in register
    #pragma HLS INTERFACE axis port = arg1_axis_in register
    #pragma HLS INTERFACE axis port = arg1_axis_out register
    #pragma HLS INTERFACE axis port = arg2_axis_in register
    #pragma HLS INTERFACE axis port = arg2_axis_out register
    #pragma HLS INTERFACE axis port = arg3_axis_in register
    #pragma HLS INTERFACE axis port = arg3_axis_out register
    #pragma HLS INTERFACE axis port = arg4_axis_out register

    #pragma HLS INTERFACE ap_ctrl_chain port = return
    #pragma HLS INTERFACE s_axilite port = return bundle = control   


    ops::hls::StencilConfigCore stencilConfig;

    stencilConfig.dim = stencilConfig_dim;
    stencilConfig.grid_size[0] = stencilConfig_grid_size_0;
    stencilConfig.lower_limit[0] = stencilConfig_lower_limit_0;
    stencilConfig.upper_limit[0] = stencilConfig_upper_limit_0;
    stencilConfig.total_itr = stencilConfig_total_itr;
    stencilConfig.outer_loop_limit = stencilConfig_outer_loop_limit;
    stencilConfig.batch_size = stencilConfig_batch_size;

    unsigned int tmp1 = stencilConfig_batch_size * vector_factor;
    unsigned int tmp2 = stencilConfig_total_itr * sizeof(stencil_type);
    unsigned int total_bytes = tmp1 * tmp2;
    

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting outerloop_0 kernel TOP \n", __func__);
#endif

    for (unsigned int i = 0; i < outer_itr; i++)
    {
        kernel_outerloop_0_dataflow_region(slr_region, stencilConfig, total_bytes, arg0_axis_in, arg1_axis_in, arg1_axis_out, arg2_axis_in, arg2_axis_out, arg3_axis_in, arg3_axis_out, arg4_axis_out);
    }

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
