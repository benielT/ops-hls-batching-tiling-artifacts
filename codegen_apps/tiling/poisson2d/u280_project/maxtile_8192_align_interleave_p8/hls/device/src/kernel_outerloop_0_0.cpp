// Auto-generated at 2026-08-13 00:16:01.964531 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0_0.hpp>
 



/*static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short slr_region, const ops::hls::StencilConfigCoreSingleTile stencilConfig,
        const unsigned int num_pkts,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor_0 + 1][8]
)
{
#pragma HLS INLINE 

    constexpr unsigned short PEId_offset = 0;
        ::hls::stream<ap_uint<axis_data_width>> node2_1_to_node3_0[iter_par_factor_0][8];
    #pragma HLS STREAM variable = node2_1_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_1_to_node3_0
    ::hls::stream<ap_uint<half_axis_data_width_poisson_kernel_stencil_0>> arg0_poisson_kernel_stencil_in_subtile_stream[iter_par_factor_0][8];
    #pragma HLS STREAM variable = arg0_poisson_kernel_stencil_in_subtile_stream     
    #pragma HLS ARRAY_PARTITION variable = arg0_poisson_kernel_stencil_in_subtile_stream

    ::hls::stream<ap_uint<half_axis_data_width_poisson_kernel_stencil_1>> arg1_poisson_kernel_stencil_out_subtile_stream[iter_par_factor_0][8];
    #pragma HLS STREAM variable = arg1_poisson_kernel_stencil_out_subtile_stream     
    #pragma HLS ARRAY_PARTITION variable = arg1_poisson_kernel_stencil_out_subtile_stream


    for (int i = 0; i < iter_par_factor_0; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor_0
            ops::hls::stream2interleave<axis_data_width, 32, 8, 1>(arg0_arg1_streams[0], arg0_poisson_kernel_stencil_in_subtile_stream[i], num_pkts);
    kernel_poisson_kernel_stencil_PE<4, 0>(
                None, i, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[i][0],
                arg0_poisson_kernel_stencil_in_subtile_stream[i][1],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][0],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][1]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 1>(
                None, i, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[i][2],
                arg0_poisson_kernel_stencil_in_subtile_stream[i][3],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][2],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][3]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 2>(
                None, i, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[i][4],
                arg0_poisson_kernel_stencil_in_subtile_stream[i][5],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][4],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][5]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 3>(
                None, i, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[i][6],
                arg0_poisson_kernel_stencil_in_subtile_stream[i][7],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][6],
                arg1_poisson_kernel_stencil_out_subtile_stream[i][7]
  
            );
    ops::hls::interleave2stream<axis_data_width, 32, 8, 1>(arg1_poisson_kernel_stencil_out_subtile_stream[i], arg0_arg1_streams[1], num_pkts);

    }
}*/


static void kernel_outerloop_0_dataflow_region(const unsigned short slr_region, const ops::hls::StencilConfigCoreSingleTile& stencilConfig, const unsigned int num_pkts,
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_1_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_2_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_3_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_4_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_5_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_6_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_7_axis_in, 
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
#pragma HLS DATAFLOW
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[2][8];
    #pragma HLS ARRAY_PARTITION variable = arg0_arg1_streams complete

    #pragma HLS STREAM variable = arg0_arg1_streams depth = 10
    
        ::hls::stream<ap_uint<axis_data_width>> node2_1_to_node3_0[iter_par_factor_0][8];
    #pragma HLS STREAM variable = node2_1_to_node3_0       
    #pragma HLS ARRAY_PARTITION variable = node2_1_to_node3_0
    ::hls::stream<ap_uint<half_axis_data_width_poisson_kernel_stencil_0>> arg0_poisson_kernel_stencil_in_subtile_stream[iter_par_factor_0][8];
    #pragma HLS STREAM variable = arg0_poisson_kernel_stencil_in_subtile_stream     
    #pragma HLS ARRAY_PARTITION variable = arg0_poisson_kernel_stencil_in_subtile_stream

    ::hls::stream<ap_uint<half_axis_data_width_poisson_kernel_stencil_1>> arg1_poisson_kernel_stencil_out_subtile_stream[iter_par_factor_0][8];
    #pragma HLS STREAM variable = arg1_poisson_kernel_stencil_out_subtile_stream     
    #pragma HLS ARRAY_PARTITION variable = arg1_poisson_kernel_stencil_out_subtile_stream


        ops::hls::axis2stream<axis_data_width>(arg0_0_axis_in, arg0_arg1_streams[0][0], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_1_axis_in, arg0_arg1_streams[0][1], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_2_axis_in, arg0_arg1_streams[0][2], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_3_axis_in, arg0_arg1_streams[0][3], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_4_axis_in, arg0_arg1_streams[0][4], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_5_axis_in, arg0_arg1_streams[0][5], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_6_axis_in, arg0_arg1_streams[0][6], num_pkts);
        ops::hls::axis2stream<axis_data_width>(arg0_7_axis_in, arg0_arg1_streams[0][7], num_pkts);

    /*    kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, 
        num_pkts,
    arg0_arg1_streams); */

            ops::hls::stream2interleave<axis_data_width, 32, 8, 1>(arg0_arg1_streams[0], arg0_poisson_kernel_stencil_in_subtile_stream[0], num_pkts);
    kernel_poisson_kernel_stencil_PE<4, 0>(
                0, 0, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[0][0],
                arg0_poisson_kernel_stencil_in_subtile_stream[0][1],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][0],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][1]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 1>(
                0, 0, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[0][2],
                arg0_poisson_kernel_stencil_in_subtile_stream[0][3],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][2],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][3]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 2>(
                0, 0, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[0][4],
                arg0_poisson_kernel_stencil_in_subtile_stream[0][5],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][4],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][5]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 3>(
                0, 0, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[0][6],
                arg0_poisson_kernel_stencil_in_subtile_stream[0][7],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][6],
                arg1_poisson_kernel_stencil_out_subtile_stream[0][7]
  
            );

            ops::hls::updateInterleaveBoundaries<axis_data_width, 32, 8, 1>(arg1_poisson_kernel_stencil_out_subtile_stream[0], arg0_poisson_kernel_stencil_in_subtile_stream[1], num_pkts);
    kernel_poisson_kernel_stencil_PE<4, 0>(
                0, 1, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[1][0],
                arg0_poisson_kernel_stencil_in_subtile_stream[1][1],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][0],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][1]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 1>(
                0, 1, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[1][2],
                arg0_poisson_kernel_stencil_in_subtile_stream[1][3],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][2],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][3]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 2>(
                0, 1, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[1][4],
                arg0_poisson_kernel_stencil_in_subtile_stream[1][5],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][4],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][5]
  
            );
    kernel_poisson_kernel_stencil_PE<4, 3>(
                0, 1, 
                stencilConfig,
                arg0_poisson_kernel_stencil_in_subtile_stream[1][6],
                arg0_poisson_kernel_stencil_in_subtile_stream[1][7],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][6],
                arg1_poisson_kernel_stencil_out_subtile_stream[1][7]
  
            );
    ops::hls::interleave2stream<axis_data_width, 32, 8, 1>(arg1_poisson_kernel_stencil_out_subtile_stream[1], arg0_arg1_streams[1], num_pkts);


        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][0], arg1_0_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][1], arg1_1_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][2], arg1_2_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][3], arg1_3_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][4], arg1_4_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][5], arg1_5_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][6], arg1_6_axis_out,  num_pkts);
        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[1][7], arg1_7_axis_out,  num_pkts);

}

static void kernel_outerloop_0_main_region(const unsigned short slr_region, const unsigned int outer_itr, const ops::hls::StencilConfigCoreTiled& stencilConfig, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_1_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_2_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_3_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_4_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_5_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_6_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_7_axis_in, 
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
    const unsigned short total_tiles = stencilConfig.tile_count[0] * stencilConfig.tile_count[1];
    unsigned short tile_x = 0;
    const unsigned short y_diff = stencilConfig.outer_loop_limit - 1;

    for (unsigned int i = 0; i < outer_itr; i++)
    {
        for (unsigned short tile_id = 0; tile_id < total_tiles; tile_id++)
        {
    //#pragma HLS PIPELINE
            if (tile_id > 0) {
                tile_x++;
                if (tile_x >= stencilConfig.tile_count[0]) {
                    tile_x = 0;
                }
            } 

            const unsigned short tile_size_x = tile_x == (stencilConfig.tile_count[0] -1) ? stencilConfig.last_tile_size[0] : stencilConfig.tile_size[0];
            bool small_tile = tile_size_x <= 4; 
            const unsigned int widen_tile_size_x = (tile_size_x + 7) >> 3;
            const unsigned int num_pkts_div_by_banks = widen_tile_size_x * y_diff;

        #ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s| \n===============================\n", __func__);
            printf("[KERNEL_DEBUG]|%s| tile_size_x: %d\n", __func__, tile_size_x);
            printf("[KERNEL_DEBUG]|%s| widen_tile_size_x: %d\n", __func__, widen_tile_size_x);
            printf("[KERNEL_DEBUG]|%s| num_pkts_div_bank: %d\n", __func__, num_pkts_div_by_banks);
            printf("[KERNEL_DEBUG]|%s| ===============================\n", __func__);
        #endif
            //const ops::hls::StencilConfigCoreSingleTile tileConfig = ops::hls::stencilConfigCoreSingleTileGen2D(stencilConfig, tile_x//);
            ops::hls::StencilConfigCoreSingleTile tileConfig;
            tileConfig.dim = stencilConfig.dim;
            const bool is_last_tile_x = (tile_x == stencilConfig.tile_count[0] - 1);
            tileConfig.tile_size[0] = widen_tile_size_x;
            tileConfig.tile_size[1] = stencilConfig.grid_size[1];
            tileConfig.tile_size[2] = stencilConfig.grid_size[2];
            tileConfig.outer_loop_limit = stencilConfig.outer_loop_limit;
            //tileConfig.is_tiled[0] = stencilConfig.tile_count[0] > 1;
            //tileConfig.is_tiled[1] = stencilConfig.tile_count[1] > 1;
            tileConfig.is_first[0] = tile_x == 0;
            tileConfig.is_first[1] = true;
            tileConfig.is_last[0] = is_last_tile_x;
            tileConfig.is_last[1] = true;
            tileConfig.last_tile_upper_limit_x = stencilConfig.last_tile_upper_limit_x;
            tileConfig.line_diff = widen_tile_size_x - 1;
            tileConfig.plane_diff = 0;
    
    #ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s| \n=== StencilConfigCoreSingleTile ======\n", __func__);
            printf("[KERNEL_DEBUG]|%s| tile_size: (%d, %d, %d)\n", __func__, tileConfig.tile_size[0], tileConfig.tile_size[1], tileConfig.tile_size[2]);
            printf("[KERNEL_DEBUG]|%s| dim: %d\n", __func__, tileConfig.dim);
            printf("[KERNEL_DEBUG]|%s| outer_loop_limit: %d\n", __func__, tileConfig.outer_loop_limit); 
            printf("[KERNEL_DEBUG]|%s| last_tile_upper_limit_x: %d\n", __func__, tileConfig.last_tile_upper_limit_x); 
            printf("[KERNEL_DEBUG]|%s| is_first: (%d,%d) \n", __func__, tileConfig.is_first[0], tileConfig.is_first[1]); 
            printf("[KERNEL_DEBUG]|%s| is_last: (%d,%d) \n", __func__, tileConfig.is_last[0], tileConfig.is_last[1]);
            printf("[KERNEL_DEBUG]|%s| ===============================\n", __func__);
    #endif 

            kernel_outerloop_0_dataflow_region(slr_region, tileConfig, 
                num_pkts_div_by_banks,
                 arg0_0_axis_in, 
                arg0_1_axis_in, 
                arg0_2_axis_in, 
                arg0_3_axis_in, 
                arg0_4_axis_in, 
                arg0_5_axis_in, 
                arg0_6_axis_in, 
                arg0_7_axis_in, 
                arg1_0_axis_out, 
                arg1_1_axis_out, 
                arg1_2_axis_out, 
                arg1_3_axis_out, 
                arg1_4_axis_out, 
                arg1_5_axis_out, 
                arg1_6_axis_out, 
                arg1_7_axis_out
);
        }
        tile_x = 0;
    }
}
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
    

    #pragma HLS INTERFACE axis port = arg0_0_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_1_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_2_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_3_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_4_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_5_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_6_axis_in register 
    #pragma HLS INTERFACE axis port = arg0_7_axis_in register 
    #pragma HLS INTERFACE axis port = arg1_0_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_1_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_2_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_3_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_4_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_5_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_6_axis_out register 
    #pragma HLS INTERFACE axis port = arg1_7_axis_out register 

    #pragma HLS INTERFACE ap_ctrl_chain port = return
    #pragma HLS INTERFACE s_axilite port = return bundle = control   

    ops::hls::StencilConfigCoreTiled stencilConfig;

    stencilConfig.dim = stencilConfig_dim;
    stencilConfig.grid_size[0] = stencilConfig_grid_size_0;
    stencilConfig.grid_size[1] = stencilConfig_grid_size_1;
    stencilConfig.outer_loop_limit = stencilConfig_outer_loop_limit;
    stencilConfig.tiling_dim = 1;
    stencilConfig.tile_size[0] = tile_size_x;
    stencilConfig.tile_size[1] = 1;
    stencilConfig.last_tile_size[0] = last_tile_size_x;
    stencilConfig.last_tile_size[1] = 1;
    stencilConfig.tile_count[0] = tile_count_x;
    stencilConfig.tile_count[1] = 1;
    stencilConfig.last_tile_upper_limit_x = last_tile_upper_limit_x;
    //constexpr unsigned short num_of_pkts_per_beat = mem_data_width / axis_data_width;
    //constexpr unsigned short bytes_per_pkt = sizeof(stencil_type) * vector_factor;
    const unsigned int num_beats = total_xblocks;
    const unsigned int num_pkts = num_beats * num_of_pkts_per_beat;
    //const unsigned int total_bytes = num_pkts * bytes_per_pkt;

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| num_beats: %d, num_pkts: %d\n", __func__,
         num_beats, num_pkts);

    printf("[KERNEL_DEBUG]|%s| stencilConfig: dim: %hu, grid_size:(%d,%d,%d), outer_loop_limit: %d, tiling_dim: %hu, tile_size:(%d,%d),\
        last_tile_size:(%d,%d), tile_count:(%d,%d)\n, total_xblocks: %d\n", __func__,
        stencilConfig.dim,
        stencilConfig.grid_size[0], stencilConfig.grid_size[1], stencilConfig.grid_size[2],
        stencilConfig.outer_loop_limit,
        stencilConfig.tiling_dim,
        stencilConfig.tile_size[0], stencilConfig.tile_size[1],
        stencilConfig.last_tile_size[0], stencilConfig.last_tile_size[1],
        stencilConfig.tile_count[0], stencilConfig.tile_count[1], total_xblocks);
#endif

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting outerloop_0 kernel TOP \n", __func__);
#endif

    kernel_outerloop_0_main_region(slr_region, outer_itr, stencilConfig, 
                arg0_0_axis_in, 
                arg0_1_axis_in, 
                arg0_2_axis_in, 
                arg0_3_axis_in, 
                arg0_4_axis_in, 
                arg0_5_axis_in, 
                arg0_6_axis_in, 
                arg0_7_axis_in, 
                arg1_0_axis_out, 
                arg1_1_axis_out, 
                arg1_2_axis_out, 
                arg1_3_axis_out, 
                arg1_4_axis_out, 
                arg1_5_axis_out, 
                arg1_6_axis_out, 
                arg1_7_axis_out
);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
