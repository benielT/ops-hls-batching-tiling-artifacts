// Auto-generated at 2026-03-11 15:59:44.067746 by ops-translator
#include <ops_hls_kernel_support.h>
#include <kernel_outerloop_0_2.hpp>
 

static void joint_PE_outerloop_0(const unsigned short PEId, const ops::hls::StencilConfigCoreSingleTile & stencilConfig, 
        ::hls::stream<ap_uint<axis_data_width>>& arg0_hls_stream_in, 
        ::hls::stream<ap_uint<axis_data_width>>& arg1_hls_stream_out
)
{
    ::hls::stream<ap_uint<axis_data_width>> node2_1_to_node3_0;
    #pragma HLS STREAM variable = node2_1_to_node3_0 depth = 10

    kernel_jac3D_kernel_stencil_PE(PEId, stencilConfig,
            arg0_hls_stream_in,
            arg1_hls_stream_out
    );
}



static void kernel_outerloop_0_dataflow_region_cascaded(const unsigned short& slr_region, const ops::hls::StencilConfigCoreSingleTile& stencilConfig,
    ::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor_2 + 1]
)
{
#pragma HLS INLINE 

    const unsigned short PEId_offset = 11;

    for (int i = 0; i < iter_par_factor_2; i++)
    {
#pragma HLS UNROLL factor=iter_par_factor_2
        joint_PE_outerloop_0(PEId_offset + i, stencilConfig,
                arg0_arg1_streams[i],
                arg0_arg1_streams[i+1]
        );
    }
}
static void kernel_outerloop_0_dataflow_region(const unsigned short& slr_region, const ops::hls::StencilConfigCoreSingleTile& stencilConfig, const unsigned int num_pkts,
hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out)
{
#pragma HLS DATAFLOW
::hls::stream<ap_uint<axis_data_width>> arg0_arg1_streams[iter_par_factor_2 + 1];
    #pragma HLS STREAM variable = arg0_arg1_streams depth = 66
    
        ops::hls::axis2stream<axis_data_width>(arg0_axis_in, arg0_arg1_streams[0], num_pkts);

        kernel_outerloop_0_dataflow_region_cascaded(slr_region, stencilConfig, arg0_arg1_streams);

        ops::hls::stream2axis<axis_data_width>(arg0_arg1_streams[iter_par_factor_2], arg1_axis_out,  num_pkts);

}

static void kernel_outerloop_0_main_region(const unsigned short& slr_region, const unsigned int& outer_itr, const ops::hls::StencilConfigCoreTiled& stencilConfig, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_in, 
        hls::stream <ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_out
    )
{
    const unsigned short total_tiles = stencilConfig.tile_count[0] * stencilConfig.tile_count[1];
    unsigned short tile_x = 0;
    unsigned short tile_y = 0;
	const unsigned short z_diff = stencilConfig.outer_loop_limit - 1;

    for (unsigned int i = 0; i < outer_itr/2; i++)
    {
        for (unsigned short tile_id = 0; tile_id < total_tiles; tile_id++)
        {
    //#pragma HLS PIPELINE
            if (tile_id > 0) {
                tile_x++;
                if (tile_x >= stencilConfig.tile_count[0]) {
                    tile_x = 0;
                    tile_y++;
                }
            } 
        
            const unsigned short tile_size_x = tile_x == (stencilConfig.tile_count[0] -1) ? stencilConfig.last_tile_size[0] : stencilConfig.tile_size[0];
            const unsigned short tile_size_y = tile_y == (stencilConfig.tile_count[1] -1) ? stencilConfig.last_tile_size[1] : stencilConfig.tile_size[1];
            const unsigned int num_pkts = tile_size_x * tile_size_y * z_diff;
            const ops::hls::StencilConfigCoreSingleTile tileConfig = ops::hls::stencilConfigCoreSingleTileGen3D(stencilConfig, tile_x, tile_y);

            kernel_outerloop_0_dataflow_region(slr_region, tileConfig, 
                num_pkts, arg0_axis_in, arg1_axis_out);
        }

        tile_x = 0;
        tile_y = 0; 

        for (unsigned short tile_id = 0; tile_id < total_tiles; tile_id++)
        {
    //#pragma HLS PIPELINE
            if (tile_id > 0) {
                tile_x++;
                if (tile_x >= stencilConfig.tile_count[0]) {
                    tile_x = 0;
                    tile_y++;
                }
            } 
        
            const unsigned short tile_size_x = tile_x == (stencilConfig.tile_count[0] -1) ? stencilConfig.last_tile_size[0] : stencilConfig.tile_size[0];
            const unsigned short tile_size_y = tile_y == (stencilConfig.tile_count[1] -1) ? stencilConfig.last_tile_size[1] : stencilConfig.tile_size[1];
            const unsigned int num_pkts = tile_size_x * tile_size_y * z_diff;
            const ops::hls::StencilConfigCoreSingleTile tileConfig = ops::hls::stencilConfigCoreSingleTileGen3D(stencilConfig, tile_x, tile_y);
            kernel_outerloop_0_dataflow_region(slr_region, tileConfig, 
                num_pkts, arg0_axis_in, arg1_axis_out);
        }

        tile_x = 0;
        tile_y = 0;
    }
}
extern "C" void kernel_outerloop_0_2
(
        const unsigned short slr_region,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_grid_size_2,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
#ifndef OPS_TILING
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_lower_limit_2,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
        const unsigned short stencilConfig_upper_limit_2,
#endif
        const unsigned short stencilConfig_outer_loop_limit,
#ifndef OPS_TILING
        const unsigned short stencilConfig_batch_size,
#else
        const unsigned short tile_size_x,
        const unsigned short tile_size_y,
        const unsigned short last_tile_size_x,
        const unsigned short last_tile_size_y,
        const unsigned short tile_count_x,
        const unsigned short tile_count_y,
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
    #pragma HLS INTERFACE s_axilite port = stencilConfig_grid_size_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_dim bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_total_itr bundle = control
#ifndef OPS_TILING
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_lower_limit_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = stencilConfig_upper_limit_2 bundle = control
#endif
    #pragma HLS INTERFACE s_axilite port = stencilConfig_outer_loop_limit bundle = control
#ifndef OPS_TILING
    #pragma HLS INTERFACE s_axilite port = stencilConfig_batch_size bundle = control
#else
    #pragma HLS INTERFACE s_axilite port = tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_count_x bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_count_y bundle = control
    #pragma HLS INTERFACE s_axilite port = total_xblocks bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_upper_limit_x bundle = control
#endif
    

    #pragma HLS INTERFACE axis port = arg0_axis_in register
    #pragma HLS INTERFACE axis port = arg1_axis_out register

    #pragma HLS INTERFACE ap_ctrl_chain port = return
    #pragma HLS INTERFACE s_axilite port = return bundle = control   

    ops::hls::StencilConfigCoreTiled stencilConfig;

    stencilConfig.dim = stencilConfig_dim;
    stencilConfig.grid_size[0] = stencilConfig_grid_size_0;
    stencilConfig.grid_size[1] = stencilConfig_grid_size_1;
    stencilConfig.grid_size[2] = stencilConfig_grid_size_2;
    stencilConfig.outer_loop_limit = stencilConfig_outer_loop_limit;
    stencilConfig.tiling_dim = 2;
    stencilConfig.tile_size[0] = tile_size_x;
    stencilConfig.tile_size[1] = tile_size_y;
    stencilConfig.last_tile_size[0] = last_tile_size_x;
    stencilConfig.last_tile_size[1] = last_tile_size_y;
    stencilConfig.tile_count[0] = tile_count_x;
    stencilConfig.tile_count[1] = tile_count_y;
    stencilConfig.last_tile_upper_limit_x = last_tile_upper_limit_x;
    constexpr unsigned short num_of_pkts_per_beat = mem_data_width / axis_data_width;
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
arg0_axis_in, arg1_axis_out);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Ending outerloop_0 kernel TOP \n", __func__);
#endif
}
