// Auto-generated at 2026-07-24 21:22:44.413792 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0.hpp>
 



/*static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short slr_region, const ops::hls::StencilConfigCore stencilConfig,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1]
)
{
#pragma HLS INLINE 

    const unsigned short PEId_offset = slr_region;
        ::hls::stream<ap_uint<axis_data_width>> node2_1_to_node3_0[iter_par_factor];
    #pragma HLS STREAM variable = node2_1_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_1_to_node3_0


    for (int i = 0; i < iter_par_factor; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor
            kernel_poisson_kernel_stencil_PE(
            None, i,
            stencilConfig,
            arg0_arg1_streams[i],
            arg0_arg1_streams[i+1]
    );

    }
}*/


static void kernel_outerloop_0_dataflow_region(const unsigned short slr_region, const ops::hls::StencilConfigCore& stencilConfig, const unsigned int num_pkts,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out
)
{
#pragma HLS DATAFLOW
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor + 1];
    #pragma HLS ARRAY_PARTITION variable = arg0_arg1_streams complete

    #pragma HLS STREAM variable = arg0_arg1_streams depth = 10
    
        ::hls::stream<ap_uint<axis_data_width>> node2_1_to_node3_0[iter_par_factor];
    #pragma HLS STREAM variable = node2_1_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_1_to_node3_0


        ops::hls::axis2stream<axis_data_width>(arg0_axis_in, arg0_arg1_streams[0], num_pkts);

    /*    kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, 
    arg0_arg1_streams); */

            kernel_poisson_kernel_stencil_PE(
            slr_region, 0,
            stencilConfig,
            arg0_arg1_streams[0],
            arg0_arg1_streams[0+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 1,
            stencilConfig,
            arg0_arg1_streams[1],
            arg0_arg1_streams[1+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 2,
            stencilConfig,
            arg0_arg1_streams[2],
            arg0_arg1_streams[2+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 3,
            stencilConfig,
            arg0_arg1_streams[3],
            arg0_arg1_streams[3+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 4,
            stencilConfig,
            arg0_arg1_streams[4],
            arg0_arg1_streams[4+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 5,
            stencilConfig,
            arg0_arg1_streams[5],
            arg0_arg1_streams[5+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 6,
            stencilConfig,
            arg0_arg1_streams[6],
            arg0_arg1_streams[6+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 7,
            stencilConfig,
            arg0_arg1_streams[7],
            arg0_arg1_streams[7+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 8,
            stencilConfig,
            arg0_arg1_streams[8],
            arg0_arg1_streams[8+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 9,
            stencilConfig,
            arg0_arg1_streams[9],
            arg0_arg1_streams[9+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 10,
            stencilConfig,
            arg0_arg1_streams[10],
            arg0_arg1_streams[10+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 11,
            stencilConfig,
            arg0_arg1_streams[11],
            arg0_arg1_streams[11+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 12,
            stencilConfig,
            arg0_arg1_streams[12],
            arg0_arg1_streams[12+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 13,
            stencilConfig,
            arg0_arg1_streams[13],
            arg0_arg1_streams[13+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 14,
            stencilConfig,
            arg0_arg1_streams[14],
            arg0_arg1_streams[14+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 15,
            stencilConfig,
            arg0_arg1_streams[15],
            arg0_arg1_streams[15+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 16,
            stencilConfig,
            arg0_arg1_streams[16],
            arg0_arg1_streams[16+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 17,
            stencilConfig,
            arg0_arg1_streams[17],
            arg0_arg1_streams[17+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 18,
            stencilConfig,
            arg0_arg1_streams[18],
            arg0_arg1_streams[18+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 19,
            stencilConfig,
            arg0_arg1_streams[19],
            arg0_arg1_streams[19+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 20,
            stencilConfig,
            arg0_arg1_streams[20],
            arg0_arg1_streams[20+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 21,
            stencilConfig,
            arg0_arg1_streams[21],
            arg0_arg1_streams[21+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 22,
            stencilConfig,
            arg0_arg1_streams[22],
            arg0_arg1_streams[22+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 23,
            stencilConfig,
            arg0_arg1_streams[23],
            arg0_arg1_streams[23+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 24,
            stencilConfig,
            arg0_arg1_streams[24],
            arg0_arg1_streams[24+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 25,
            stencilConfig,
            arg0_arg1_streams[25],
            arg0_arg1_streams[25+1]
    );

            kernel_poisson_kernel_stencil_PE(
            slr_region, 26,
            stencilConfig,
            arg0_arg1_streams[26],
            arg0_arg1_streams[26+1]
    );


        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[iter_par_factor], arg1_axis_out,  num_pkts);

}

static void kernel_outerloop_0_main_region(const unsigned short slr_region, const unsigned int outer_itr, const ops::hls::StencilConfigCore& stencilConfig, 
const unsigned int num_pkts,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out
    )
{

    for (unsigned int i = 0; i < outer_itr; i++)
    {

            kernel_outerloop_0_dataflow_region(slr_region, stencilConfig, 
                num_pkts,
 
                arg0_axis_in, 
                arg1_axis_out
);
    }
}
extern "C" void kernel_outerloop_0
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
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in,
    //u2
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out
)

{
    #pragma HLS INTERFACE s_axilite port = slr_region bundle = control
    #pragma HLS INTERFACE s_axilite port = outer_itr bundle = control
    
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_0 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_1 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_dim bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_total_itr bundle = control

#ifndef OPS_TILING
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_0 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_1 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_0 bundle = control

    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_1 bundle = control

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
    #pragma HLS INTERFACE axis port = arg1_axis_out register 

    #pragma HLS INTERFACE ap_ctrl_chain port = return
    #pragma HLS INTERFACE s_axilite port = return bundle = control   

    ops::hls::StencilConfigCore stencilConfig;

    stencilConfig.dim = stencilConfig_dim;
    stencilConfig.grid_size[0] = stencilConfig_grid_size_0;
    stencilConfig.grid_size[1] = stencilConfig_grid_size_1;
    stencilConfig.lower_limit[0] = stencilConfig_lower_limit_0;
    stencilConfig.lower_limit[1] = stencilConfig_lower_limit_1;
    stencilConfig.upper_limit[0] = stencilConfig_upper_limit_0;
    stencilConfig.upper_limit[1] = stencilConfig_upper_limit_1;
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
                arg1_axis_out
);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
