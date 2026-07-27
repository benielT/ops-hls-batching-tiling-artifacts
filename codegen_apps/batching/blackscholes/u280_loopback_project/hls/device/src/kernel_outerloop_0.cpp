// Auto-generated at 2026-07-24 21:57:56.257974 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0.hpp>
 



/*static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short slr_region, const ops::hls::StencilConfigCore stencilConfig,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg4_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg1_arg1_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg2_arg2_streams[iter_par_factor + 1], 
    ::hls::stream<ap_uint<axis_data_width>> arg3_arg3_streams[iter_par_factor + 1]
)
{
#pragma HLS INLINE 

    const unsigned short PEId_offset = slr_region;
        ::hls::stream<ap_uint<axis_data_width>> node2_0_to_node3_0[iter_par_factor];
    #pragma HLS STREAM variable = node2_0_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_0_to_node3_0


    for (int i = 0; i < iter_par_factor; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor
            kernel_ops_krnl_blackscholes_PE(
            None, i,
            stencilConfig,
            arg0_arg4_streams[i+1],
            arg0_arg4_streams[i],
            arg1_arg1_streams[i],
            arg1_arg1_streams[i+1],
            arg2_arg2_streams[i],
            arg2_arg2_streams[i+1],
            arg3_arg3_streams[i],
            arg3_arg3_streams[i+1]
    );

    }
}*/


static void kernel_outerloop_0_dataflow_region(const unsigned short slr_region, const ops::hls::StencilConfigCore& stencilConfig, const unsigned int num_pkts,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg4_axis_out
)
{
#pragma HLS DATAFLOW
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg4_streams[iter_par_factor + 1];
    #pragma HLS ARRAY_PARTITION variable = arg0_arg4_streams complete

    #pragma HLS STREAM variable = arg0_arg4_streams depth = 10
    ::hls::stream<ap_uint<axis_data_width>> arg1_arg1_streams[iter_par_factor + 1];
    #pragma HLS ARRAY_PARTITION variable = arg1_arg1_streams complete

    #pragma HLS STREAM variable = arg1_arg1_streams depth = 10
    ::hls::stream<ap_uint<axis_data_width>> arg2_arg2_streams[iter_par_factor + 1];
    #pragma HLS ARRAY_PARTITION variable = arg2_arg2_streams complete

    #pragma HLS STREAM variable = arg2_arg2_streams depth = 10
    ::hls::stream<ap_uint<axis_data_width>> arg3_arg3_streams[iter_par_factor + 1];
    #pragma HLS ARRAY_PARTITION variable = arg3_arg3_streams complete

    #pragma HLS STREAM variable = arg3_arg3_streams depth = 10
    
        ::hls::stream<ap_uint<axis_data_width>> node2_0_to_node3_0[iter_par_factor];
    #pragma HLS STREAM variable = node2_0_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_0_to_node3_0


        ops::hls::axis2stream<axis_data_width>(arg0_axis_in, arg0_arg4_streams[0], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg1_axis_in, arg1_arg1_streams[0], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg2_axis_in, arg2_arg2_streams[0], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg3_axis_in, arg3_arg3_streams[0], num_pkts);

    /*    kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, 
    arg0_arg4_streams,    arg1_arg1_streams,    arg2_arg2_streams,    arg3_arg3_streams); */

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 0,
            stencilConfig,
            arg0_arg4_streams[0+1],
            arg0_arg4_streams[0],
            arg1_arg1_streams[0],
            arg1_arg1_streams[0+1],
            arg2_arg2_streams[0],
            arg2_arg2_streams[0+1],
            arg3_arg3_streams[0],
            arg3_arg3_streams[0+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 1,
            stencilConfig,
            arg0_arg4_streams[1+1],
            arg0_arg4_streams[1],
            arg1_arg1_streams[1],
            arg1_arg1_streams[1+1],
            arg2_arg2_streams[1],
            arg2_arg2_streams[1+1],
            arg3_arg3_streams[1],
            arg3_arg3_streams[1+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 2,
            stencilConfig,
            arg0_arg4_streams[2+1],
            arg0_arg4_streams[2],
            arg1_arg1_streams[2],
            arg1_arg1_streams[2+1],
            arg2_arg2_streams[2],
            arg2_arg2_streams[2+1],
            arg3_arg3_streams[2],
            arg3_arg3_streams[2+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 3,
            stencilConfig,
            arg0_arg4_streams[3+1],
            arg0_arg4_streams[3],
            arg1_arg1_streams[3],
            arg1_arg1_streams[3+1],
            arg2_arg2_streams[3],
            arg2_arg2_streams[3+1],
            arg3_arg3_streams[3],
            arg3_arg3_streams[3+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 4,
            stencilConfig,
            arg0_arg4_streams[4+1],
            arg0_arg4_streams[4],
            arg1_arg1_streams[4],
            arg1_arg1_streams[4+1],
            arg2_arg2_streams[4],
            arg2_arg2_streams[4+1],
            arg3_arg3_streams[4],
            arg3_arg3_streams[4+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 5,
            stencilConfig,
            arg0_arg4_streams[5+1],
            arg0_arg4_streams[5],
            arg1_arg1_streams[5],
            arg1_arg1_streams[5+1],
            arg2_arg2_streams[5],
            arg2_arg2_streams[5+1],
            arg3_arg3_streams[5],
            arg3_arg3_streams[5+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 6,
            stencilConfig,
            arg0_arg4_streams[6+1],
            arg0_arg4_streams[6],
            arg1_arg1_streams[6],
            arg1_arg1_streams[6+1],
            arg2_arg2_streams[6],
            arg2_arg2_streams[6+1],
            arg3_arg3_streams[6],
            arg3_arg3_streams[6+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 7,
            stencilConfig,
            arg0_arg4_streams[7+1],
            arg0_arg4_streams[7],
            arg1_arg1_streams[7],
            arg1_arg1_streams[7+1],
            arg2_arg2_streams[7],
            arg2_arg2_streams[7+1],
            arg3_arg3_streams[7],
            arg3_arg3_streams[7+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 8,
            stencilConfig,
            arg0_arg4_streams[8+1],
            arg0_arg4_streams[8],
            arg1_arg1_streams[8],
            arg1_arg1_streams[8+1],
            arg2_arg2_streams[8],
            arg2_arg2_streams[8+1],
            arg3_arg3_streams[8],
            arg3_arg3_streams[8+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 9,
            stencilConfig,
            arg0_arg4_streams[9+1],
            arg0_arg4_streams[9],
            arg1_arg1_streams[9],
            arg1_arg1_streams[9+1],
            arg2_arg2_streams[9],
            arg2_arg2_streams[9+1],
            arg3_arg3_streams[9],
            arg3_arg3_streams[9+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 10,
            stencilConfig,
            arg0_arg4_streams[10+1],
            arg0_arg4_streams[10],
            arg1_arg1_streams[10],
            arg1_arg1_streams[10+1],
            arg2_arg2_streams[10],
            arg2_arg2_streams[10+1],
            arg3_arg3_streams[10],
            arg3_arg3_streams[10+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 11,
            stencilConfig,
            arg0_arg4_streams[11+1],
            arg0_arg4_streams[11],
            arg1_arg1_streams[11],
            arg1_arg1_streams[11+1],
            arg2_arg2_streams[11],
            arg2_arg2_streams[11+1],
            arg3_arg3_streams[11],
            arg3_arg3_streams[11+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 12,
            stencilConfig,
            arg0_arg4_streams[12+1],
            arg0_arg4_streams[12],
            arg1_arg1_streams[12],
            arg1_arg1_streams[12+1],
            arg2_arg2_streams[12],
            arg2_arg2_streams[12+1],
            arg3_arg3_streams[12],
            arg3_arg3_streams[12+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 13,
            stencilConfig,
            arg0_arg4_streams[13+1],
            arg0_arg4_streams[13],
            arg1_arg1_streams[13],
            arg1_arg1_streams[13+1],
            arg2_arg2_streams[13],
            arg2_arg2_streams[13+1],
            arg3_arg3_streams[13],
            arg3_arg3_streams[13+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 14,
            stencilConfig,
            arg0_arg4_streams[14+1],
            arg0_arg4_streams[14],
            arg1_arg1_streams[14],
            arg1_arg1_streams[14+1],
            arg2_arg2_streams[14],
            arg2_arg2_streams[14+1],
            arg3_arg3_streams[14],
            arg3_arg3_streams[14+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 15,
            stencilConfig,
            arg0_arg4_streams[15+1],
            arg0_arg4_streams[15],
            arg1_arg1_streams[15],
            arg1_arg1_streams[15+1],
            arg2_arg2_streams[15],
            arg2_arg2_streams[15+1],
            arg3_arg3_streams[15],
            arg3_arg3_streams[15+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 16,
            stencilConfig,
            arg0_arg4_streams[16+1],
            arg0_arg4_streams[16],
            arg1_arg1_streams[16],
            arg1_arg1_streams[16+1],
            arg2_arg2_streams[16],
            arg2_arg2_streams[16+1],
            arg3_arg3_streams[16],
            arg3_arg3_streams[16+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 17,
            stencilConfig,
            arg0_arg4_streams[17+1],
            arg0_arg4_streams[17],
            arg1_arg1_streams[17],
            arg1_arg1_streams[17+1],
            arg2_arg2_streams[17],
            arg2_arg2_streams[17+1],
            arg3_arg3_streams[17],
            arg3_arg3_streams[17+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 18,
            stencilConfig,
            arg0_arg4_streams[18+1],
            arg0_arg4_streams[18],
            arg1_arg1_streams[18],
            arg1_arg1_streams[18+1],
            arg2_arg2_streams[18],
            arg2_arg2_streams[18+1],
            arg3_arg3_streams[18],
            arg3_arg3_streams[18+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 19,
            stencilConfig,
            arg0_arg4_streams[19+1],
            arg0_arg4_streams[19],
            arg1_arg1_streams[19],
            arg1_arg1_streams[19+1],
            arg2_arg2_streams[19],
            arg2_arg2_streams[19+1],
            arg3_arg3_streams[19],
            arg3_arg3_streams[19+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 20,
            stencilConfig,
            arg0_arg4_streams[20+1],
            arg0_arg4_streams[20],
            arg1_arg1_streams[20],
            arg1_arg1_streams[20+1],
            arg2_arg2_streams[20],
            arg2_arg2_streams[20+1],
            arg3_arg3_streams[20],
            arg3_arg3_streams[20+1]
    );

            kernel_ops_krnl_blackscholes_PE(
            slr_region, 21,
            stencilConfig,
            arg0_arg4_streams[21+1],
            arg0_arg4_streams[21],
            arg1_arg1_streams[21],
            arg1_arg1_streams[21+1],
            arg2_arg2_streams[21],
            arg2_arg2_streams[21+1],
            arg3_arg3_streams[21],
            arg3_arg3_streams[21+1]
    );


        ops::hls::stream2axis<axis_data_width>(arg1_arg1_streams[iter_par_factor], arg1_axis_out, num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg2_arg2_streams[iter_par_factor], arg2_axis_out, num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg3_arg3_streams[iter_par_factor], arg3_axis_out, num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg4_streams[iter_par_factor], arg4_axis_out,  num_pkts);

}

static void kernel_outerloop_0_main_region(const unsigned short slr_region, const unsigned int outer_itr, const ops::hls::StencilConfigCore& stencilConfig, 
const unsigned int num_pkts,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg2_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_in,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg3_axis_out, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg4_axis_out
    )
{

    for (unsigned int i = 0; i < outer_itr; i++)
    {

            kernel_outerloop_0_dataflow_region(slr_region, stencilConfig, 
                num_pkts,
 
                arg0_axis_in, 
                arg1_axis_in, 
                arg1_axis_out,                 arg2_axis_in, 
                arg2_axis_out,                 arg3_axis_in, 
                arg3_axis_out,                 arg4_axis_out
);
    }
}
extern "C" void kernel_outerloop_0
(
        const unsigned short slr_region,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
#ifndef OPS_TILING
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_upper_limit_0,
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

#ifndef OPS_TILING
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_0 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_0 bundle = control

#endif
    #pragma HLS INTERFACE s_axilite port = stencilConfig_outer_loop_limit bundle = control
#ifndef OPS_TILING
    #pragma HLS INTERFACE s_axilite port = stencilConfig_batch_size bundle = control
#else

    #pragma HLS INTERFACE s_axilite port = tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_count_x bundle = control
    #pragma HLS INTERFACE s_axilite port = total_xblocks bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_upper_limit_x bundle = control

#endif
    

    #pragma HLS INTERFACE axis port = arg0_axis_in register 
    #pragma HLS INTERFACE axis port = arg1_axis_in register     #pragma HLS INTERFACE axis port = arg1_axis_out register     #pragma HLS INTERFACE axis port = arg2_axis_in register     #pragma HLS INTERFACE axis port = arg2_axis_out register     #pragma HLS INTERFACE axis port = arg3_axis_in register     #pragma HLS INTERFACE axis port = arg3_axis_out register     #pragma HLS INTERFACE axis port = arg4_axis_out register 

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
    //constexpr unsigned short num_of_pkts_per_beat = mem_data_width / axis_data_width;
    // unsigned int tmp1 = stencilConfig_batch_size; //this cause 2 DSP! 
    // unsigned int tmp2 = stencilConfig_total_itr;
    // unsigned int num_pkts = tmp1 * tmp2;
    unsigned int num_pkts = stencilConfig_batch_size * stencilConfig_total_itr;

#ifdef DEBUG_LOG
    unsigned int num_beats = num_pkts / num_of_pkts_per_beat;
    printf("[KERNEL_DEBUG]|%s| num_beats: %d, num_pkts: %d\n", __func__,
         num_beats, num_pkts);
    printf("[KERNEL_DEBUG]|%s| stencilConfig: dim: %hu, grid_size:(%d,%d,%d), lower_limit:(%d,%d,%d), upper_limit:(%d,%d,%d), \
            total_itr: %d, outer_loop_limit: %d, batch_size: %d\n", __func__,
        stencilConfig.dim,
        stencilConfig.grid_size[0], stencilConfig.grid_size[1], stencilConfig.grid_size[2],
        stencilConfig.lower_limit[0], stencilConfig.lower_limit[1], stencilConfig.lower_limit[2],
        stencilConfig.upper_limit[0], stencilConfig.upper_limit[1], stencilConfig.upper_limit[2],
        stencilConfig.total_itr,
        stencilConfig.outer_loop_limit,
        stencilConfig.batch_size);
#endif

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting outerloop_0 kernel TOP \n", __func__);
#endif

    kernel_outerloop_0_main_region(slr_region, outer_itr, stencilConfig, 
num_pkts, 
                arg0_axis_in, 
                arg1_axis_in, 
                arg1_axis_out, 
                arg2_axis_in, 
                arg2_axis_out, 
                arg3_axis_in, 
                arg3_axis_out, 
                arg4_axis_out
);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
