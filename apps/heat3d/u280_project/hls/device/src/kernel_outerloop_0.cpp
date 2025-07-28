// Auto-generated at 2025-07-29 00:06:57.774556 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0.hpp>

static void joint_PE_outerloop_0(const unsigned short PEId, const ops::hls::StencilConfigCore& stencilConfig, 
        ::hls::stream<ap_uint<axis_data_width>>& arg0_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg1_hls_stream_out, 
        const float& param_k
)
{
    ::hls::stream<ap_uint<axis_data_width>> node2_0_to_node3_1;
    #pragma HLS STREAM variable = node2_0_to_node3_1 depth = 10

    kernel_ops_krnl_heat3D_PE(PEId, stencilConfig,
            arg1_hls_stream_out,
            arg0_hls_stream_in,
            param_k
    );
}



static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short& slr_region, const ops::hls::StencilConfigCore& stencilConfig,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1], 
    const float& param_k
)
{
#pragma HLS INLINE 

    const unsigned short PEId_offset = slr_region * iter_par_factor;

    for (int i = 0; i < iter_par_factor; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor
        joint_PE_outerloop_0(PEId_offset + i, stencilConfig,
                arg0_arg1_streams[i],
                arg0_arg1_streams[i+1],
                param_k
        );
    }
}
static void kernel_outerloop_0_dataflow_region(const unsigned short& slr_region, const ops::hls::StencilConfigCore& stencilConfig, const unsigned int total_bytes,
hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out, const float& param_k)
{
#pragma HLS DATAFLOW
::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1];
    #pragma HLS STREAM variable = arg0_arg1_streams depth = 10
    
        ops::hls::axis2stream<axis_data_width, axis_data_width>(arg0_axis_in, arg0_arg1_streams[0], total_bytes);

        kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, arg0_arg1_streams,param_k);

        ops::hls::stream2axis<axis_data_width, axis_data_width>(arg1_axis_out, arg0_arg1_streams[iter_par_factor], total_bytes);

}

extern "C" void kernel_outerloop_0(
        const unsigned short slr_region,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_grid_size_2,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_lower_limit_2,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
        const unsigned short stencilConfig_upper_limit_2,
        const unsigned short stencilConfig_outer_loop_limit,
        const float param_k,
    //u
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in,
    //u2
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out
)

{
    #pragma HLS INTERFACE s_axilite port = slr_region bundle = control
    #pragma HLS INTERFACE s_axilite port = outer_itr bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_dim bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_total_itr bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_outer_loop_limit bundle = control

    #pragma HLS INTERFACE s_axilite port = param_k bundle = control
    

    #pragma HLS INTERFACE axis port = arg0_axis_in register
    #pragma HLS INTERFACE axis port = arg1_axis_out register

    #pragma HLS INTERFACE ap_ctrl_chain port = return
    #pragma HLS INTERFACE s_axilite port = return bundle = control   


    ops::hls::StencilConfigCore stencilConfig;

    stencilConfig.dim = stencilConfig_dim;
    stencilConfig.grid_size[0] = stencilConfig_grid_size_0;
    stencilConfig.grid_size[1] = stencilConfig_grid_size_1;
    stencilConfig.grid_size[2] = stencilConfig_grid_size_2;
    stencilConfig.lower_limit[0] = stencilConfig_lower_limit_0;
    stencilConfig.lower_limit[1] = stencilConfig_lower_limit_1;
    stencilConfig.lower_limit[2] = stencilConfig_lower_limit_2;
    stencilConfig.upper_limit[0] = stencilConfig_upper_limit_0;
    stencilConfig.upper_limit[1] = stencilConfig_upper_limit_1;
    stencilConfig.upper_limit[2] = stencilConfig_upper_limit_2;
    stencilConfig.total_itr = stencilConfig_total_itr;
    stencilConfig.outer_loop_limit = stencilConfig_outer_loop_limit;

    unsigned int total_bytes = stencilConfig_total_itr * vector_factor * sizeof(stencil_type);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting outerloop_0 kernel TOP \n", __func__);
#endif

    for (unsigned int i = 0; i < outer_itr; i++)
    {
        kernel_outerloop_0_dataflow_region(slr_region, stencilConfig, total_bytes, arg0_axis_in, arg1_axis_out, param_k);
    }

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
