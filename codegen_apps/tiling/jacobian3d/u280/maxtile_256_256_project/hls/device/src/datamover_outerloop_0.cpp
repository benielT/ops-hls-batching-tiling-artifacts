// Auto-generated at 2026-03-11 15:59:44.060462 by ops-translator
#include <datamover_outerloop_0.hpp>
static void datamover_outerloop_0_dataflow_region_read(
        const unsigned int num_pkts,
        const ops::hls::MemConfig& memconfig,
        ap_uint<mem_data_width>* arg0,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_out)
{
#pragma HLS DATAFLOW
    static ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_strm;
    #pragma HLS STREAM variable = arg0_read_mem_strm depth = 64
    static ::hls::stream<ap_uint<axis_data_width>> arg0_read_reduced_mem_strm;
    #pragma HLS STREAM variable = arg0_read_reduced_mem_strm depth = 128
    ops::hls::mem2stream<mem_data_width, 32, 2>(arg0, arg0_read_mem_strm, memconfig.total_xblocks);
    
    ops::hls::stream2streamStepdown<mem_data_width, axis_data_width>(arg0_read_mem_strm, arg0_read_reduced_mem_strm, memconfig.total_xblocks);
    ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm, arg0_axis_out, num_pkts);
}

static void datamover_outerloop_0_dataflow_region_write(
        const unsigned int num_pkts,
        const ops::hls::MemConfig& memconfig,
        ap_uint<mem_data_width>* arg1,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in)
{
    static ::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_strm;
    #pragma HLS STREAM variable = arg1_write_mem_strm depth = 64
    static ::hls::stream<ap_uint<axis_data_width>> arg1_write_reduced_mem_strm;
    #pragma HLS STREAM variable = arg1_write_reduced_mem_strm depth = 128

#pragma HLS DATAFLOW
    ops::hls::axis2stream<axis_data_width>(arg1_axis_in, arg1_write_reduced_mem_strm, num_pkts);
    
    ops::hls::stream2streamStepup<axis_data_width, mem_data_width>(arg1_write_reduced_mem_strm, arg1_write_mem_strm, memconfig.total_xblocks);
    ops::hls::stream2mem<mem_data_width, 32, 2>(arg1, arg1_write_mem_strm, memconfig.total_xblocks);
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileMem2stream(
        ap_uint<mem_data_width>* arg_b0,
        ap_uint<mem_data_width>* arg_b1,
        ap_uint<mem_data_width>* arg_b2,
        ap_uint<mem_data_width>* arg_b3,
        ap_uint<mem_data_width>* arg_b4,
        ap_uint<mem_data_width>* arg_b5,
        ap_uint<mem_data_width>* arg_b6,
        ap_uint<mem_data_width>* arg_b7,
        unsigned short abs_row_offset,
        unsigned short z_row_stride,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_out, const ap_uint<160>& command )
{
    // #pragma HLS INLINE off
    #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| reading tile from mem to stream \n", __func__);
    #endif

    //static ::hls::stream<ap_uint<MEM_DATA_WIDTH>> strm_internal("strm_internal");
	//#pragma HLS STREAM variable = strm_internal depth = 64

    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    ap_uint<64> offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);

    for (unsigned short z = 0; z < size_z; z++)
    {
        #pragma HLS PIPELINE off
        unsigned short z_row_id_offset = abs_row_offset + z * z_row_stride;

    for (unsigned short y = 0; y < size_y; y++)
    {
        #pragma HLS PIPELINE off
        unsigned short abs_row_id_of_y = y + z_row_id_offset;
        unsigned short bank_id = abs_row_id_of_y % NUM_BANKS;
        ap_uint<64> per_bank_row = (ap_uint<64>)(abs_row_id_of_y >> NUM_BANKS_SHIFT);
        ap_uint<64> s2 = offset_x + per_bank_row * stride_y;
        #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| z:%u y:%u abs_row_id:%u bank_id:%u  offset:%llu size_x:%u stride_y:%u size_y:%u stride_z:%u size_z:%u\n", 
                __func__, (unsigned int)z, (unsigned int)y, (unsigned int)abs_row_id_of_y, (unsigned int)bank_id, 
                (unsigned long long)s2, (unsigned int)size_x, (unsigned int)stride_y, (unsigned int)size_y, 
                (unsigned int)stride_z, (unsigned int)size_z);
        #endif
                    if (bank_id == 0)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b0 + s2, strm_out, size_x);
                    else if (bank_id == 1)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b1 + s2, strm_out, size_x);
                    else if (bank_id == 2)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b2 + s2, strm_out, size_x);
                    else if (bank_id == 3)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b3 + s2, strm_out, size_x);
                    else if (bank_id == 4)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b4 + s2, strm_out, size_x);
                    else if (bank_id == 5)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b5 + s2, strm_out, size_x);
                    else if (bank_id == 6)
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b6 + s2, strm_out, size_x);
                    else
                        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b7 + s2, strm_out, size_x);
    }
    }
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileStream2memWithAvoid(
        ap_uint<mem_data_width>* arg_b0,
        ap_uint<mem_data_width>* arg_b1,
        ap_uint<mem_data_width>* arg_b2,
        ap_uint<mem_data_width>* arg_b3,
        ap_uint<mem_data_width>* arg_b4,
        ap_uint<mem_data_width>* arg_b5,
        ap_uint<mem_data_width>* arg_b6,
        ap_uint<mem_data_width>* arg_b7,
        unsigned short abs_row_offset,
        unsigned short z_row_stride,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_in, const ap_uint<192>& command)
{
    //     // #pragma HLS INLINE off
    #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| writing tile from stream to mem \n", __func__);
    #endif
    
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    ap_uint<64> offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
	ap_uint<16> avoid_x = command.range(175,160);
	ap_uint<16> avoid_y = command.range(191,176);

    for (ap_uint<16> z = 0; z < size_z; z++)
    {
        #pragma HLS PIPELINE off
        unsigned short z_row_id_offset = abs_row_offset + z * z_row_stride;
        for (ap_uint<16> y = 0; y < size_y; y++)
        {
            #pragma HLS PIPELINE off
            // ap_uint<64> s2 = s3 + y * stride_y;
            unsigned short abs_row_id_of_y = y + z_row_id_offset;
            unsigned short bank_id = abs_row_id_of_y % NUM_BANKS;
            // unsigned short j_shifted = abs_row_id_of_y >> NUM_BANKS_SHIFT;
            // unsigned short j_floor = j_shifted << NUM_BANKS_SHIFT;
            // bool access_cond = j_floor + bank_id < size_y;
            ap_uint<64> per_bank_row = (ap_uint<64>)(abs_row_id_of_y >> NUM_BANKS_SHIFT);
            ap_uint<64> s2 = offset_x + per_bank_row * stride_y;
            #ifdef DEBUG_LOG
                printf("|HLS DEBUG_LOG|%s| z:%u y:%u offset:%llu, size_x:%u, stride_y:%u, size_y:%u, stride_z:%u, size_z:%u avoid_x:%u avoid_y:%u\n", 
                       __func__, (unsigned int)z, (unsigned int)y, (unsigned long long)s2, (unsigned int)size_x, (unsigned int)stride_y, (unsigned int)size_y, 
                       (unsigned int)stride_z, (unsigned int)size_z, (unsigned int)avoid_x, (unsigned int)avoid_y);
            #endif
			if (y < avoid_y)
				ops::hls::hlsTerminate<MEM_DATA_WIDTH, IN_ITR>(strm_in, size_x);
            else if (bank_id == 0) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b0 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 1) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b1 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 2) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b2 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 3) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b3 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 4) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b4 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 5) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b5 + s2, strm_in, size_x, avoid_x);
            else if (bank_id == 6) 
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b6 + s2, strm_in, size_x, avoid_x);
            else
                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b7 + s2, strm_in, size_x, avoid_x);
        }
    }
}

static void datamover_outerloop_0_dataflow_read_write_dataflow_region(
        const unsigned int num_pkts,
        const unsigned int num_beats,
        ap_uint<192>& command,
        ap_uint<160>& short_command,
        unsigned short abs_row_offset,
        unsigned short z_row_stride,
        ap_uint<mem_data_width>* arg0_b0,
        ap_uint<mem_data_width>* arg0_b1,
        ap_uint<mem_data_width>* arg0_b2,
        ap_uint<mem_data_width>* arg0_b3,
        ap_uint<mem_data_width>* arg0_b4,
        ap_uint<mem_data_width>* arg0_b5,
        ap_uint<mem_data_width>* arg0_b6,
        ap_uint<mem_data_width>* arg0_b7,
        ap_uint<mem_data_width>* arg1_b0,
        ap_uint<mem_data_width>* arg1_b1,
        ap_uint<mem_data_width>* arg1_b2,
        ap_uint<mem_data_width>* arg1_b3,
        ap_uint<mem_data_width>* arg1_b4,
        ap_uint<mem_data_width>* arg1_b5,
        ap_uint<mem_data_width>* arg1_b6,
        ap_uint<mem_data_width>* arg1_b7,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_axis_in
)    
{
    #pragma HLS DATAFLOW
    static ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_strm;
    #pragma HLS STREAM variable = arg0_read_mem_strm depth = 64
    static ::hls::stream<ap_uint<axis_data_width>> arg0_read_reduced_mem_strm;
    #pragma HLS STREAM variable = arg0_read_reduced_mem_strm depth = 128
    static ::hls::stream<ap_uint<axis_data_width>> arg1_write_reduced_mem_strm;
    #pragma HLS STREAM variable = arg1_write_reduced_mem_strm depth = 128
    static ::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_strm;
    #pragma HLS STREAM variable = arg1_write_mem_strm depth = 64


        //ops::hls::mem2streamTiled<mem_data_width, 16, 2>(arg0_b1, arg0_b2, arg0_read_mem_strm, memconfig);
        //ops::hls::stridedTileMem2stream<mem_data_width,  16, 2>(arg0_b1, arg0_read_mem_strm_b1, memconfig, 0);
        //ops::hls::stridedTileMem2stream<mem_data_width,  16, 2>(arg0_b2, arg0_read_mem_strm_b2, memconfig, 1);
        //ops::hls::combineSteams<mem_data_width, 2>(arg0_read_mem_strm_b1, arg0_read_mem_strm_b2, arg0_read_mem_strm, memconfig);
        stridedTileMem2stream<mem_data_width, 8, 16, 2>(
                arg0_b0,
                arg0_b1,
                arg0_b2,
                arg0_b3,
                arg0_b4,
                arg0_b5,
                arg0_b6,
                arg0_b7,
                abs_row_offset,
                z_row_stride,
                arg0_read_mem_strm, short_command);
        ops::hls::stream2streamStepdown<mem_data_width, axis_data_width>(arg0_read_mem_strm, arg0_read_reduced_mem_strm, num_beats);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm, arg0_axis_out, num_pkts);

        ops::hls::axis2stream<axis_data_width>(arg1_axis_in, arg1_write_reduced_mem_strm, num_pkts);
    
        ops::hls::stream2streamStepup<axis_data_width, mem_data_width>(arg1_write_reduced_mem_strm, arg1_write_mem_strm, num_beats);
        // ops::hls::stream2memTiled<mem_data_width, 16, 2>(arg1_b1, arg1_b2, arg1_write_mem_strm, memconfig);
        // ops::hls::splitStream<mem_data_width, 2>(arg1_write_mem_strm, arg1_write_mem_strm_b1, arg1_write_mem_strm_b2, memconfig);
        // ops::hls::stridedTileStream2mem<mem_data_width, 16, 2>(arg1_write_mem_strm_b1, arg1_b1, memconfig, 0);
        // ops::hls::stridedTileStream2mem<mem_data_width, 16, 2>(arg1_write_mem_strm_b2, arg1_b2, memconfig, 1);
        stridedTileStream2memWithAvoid<mem_data_width, 8, 16, 2>(
                arg1_b0,
                arg1_b1,
                arg1_b2,
                arg1_b3,
                arg1_b4,
                arg1_b5,
                arg1_b6,
                arg1_b7,
                abs_row_offset,
                z_row_stride,
                arg1_write_mem_strm, command);
}

static void datamover_outerloop_0_dataflow_read_write(
        const unsigned int iter,
        const ops::hls::MemConfigTile& memconfig,
        ap_uint<mem_data_width>* arg0_b0,
        ap_uint<mem_data_width>* arg0_b1,
        ap_uint<mem_data_width>* arg0_b2,
        ap_uint<mem_data_width>* arg0_b3,
        ap_uint<mem_data_width>* arg0_b4,
        ap_uint<mem_data_width>* arg0_b5,
        ap_uint<mem_data_width>* arg0_b6,
        ap_uint<mem_data_width>* arg0_b7,
        ap_uint<mem_data_width>* arg1_b0,
        ap_uint<mem_data_width>* arg1_b1,
        ap_uint<mem_data_width>* arg1_b2,
        ap_uint<mem_data_width>* arg1_b3,
        ap_uint<mem_data_width>* arg1_b4,
        ap_uint<mem_data_width>* arg1_b5,
        ap_uint<mem_data_width>* arg1_b6,
        ap_uint<mem_data_width>* arg1_b7,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_axis_in
)    
{
    //TODO: memconfig.start_offset need to be handled for multibank tiling if start_offset != 0. In all our cased start_offset == 0 for now
    const unsigned short total_tiles = memconfig.tile_count_x * memconfig.tile_count_y;
    const unsigned short z_diff = memconfig.end_z - memconfig.start_z;
    const unsigned short stride_z = memconfig.grid_xblocks * memconfig.grid_size_y;
	unsigned short tile_y = 0;
	unsigned short tile_x = 0;
	const unsigned short stride_y = memconfig.grid_xblocks;

    for (unsigned int i = 0; i < iter/2; i++)
    {
    //#pragma HLS PIPELINE REWIND
    #ifdef DEBUG_LOG
        printf("[KERNEL_DEBUG]|%s| Calling datamover. i:%d\n", __func__, i);
    #endif
        for (unsigned short tile_id = 0; tile_id < total_tiles; tile_id++)
		{
            if (tile_id > 0) {
				tile_x++;
				if (tile_x >= memconfig.tile_count_x) {
					tile_x = 0;
					tile_y++;
				}
			}

            const unsigned short tile_size_x = tile_x == (memconfig.tile_count_x -1) ? memconfig.last_tile_size_x : memconfig.tile_size_x;
			const ap_uint<64> tile_x_offset = tile_x * memconfig.effective_tile_size_x;
			const unsigned short abs_row_offset = tile_y * memconfig.effective_tile_size_y;
			const ap_uint<64> tile_y_offset = abs_row_offset * memconfig.grid_xblocks;
			const unsigned short tile_size_y = tile_y == (memconfig.tile_count_y -1) ? memconfig.last_tile_size_y : memconfig.tile_size_y;
            const ap_uint<64> offset = memconfig.start_offset + tile_x_offset ;
            const unsigned int total_beats = tile_size_x * tile_size_y * z_diff;
			const unsigned int total_pkts = total_beats * num_of_pkts_per_beat;

            const unsigned int avoid_x = tile_x == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
            const unsigned int avoid_y = tile_y == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
            auto command = ops::hls::commandGen3D(offset, 1, (ap_uint<16>)tile_size_x, (ap_uint<16>)stride_y, (ap_int<16>)tile_size_y, 
                    (ap_int<16>)stride_z, (ap_uint<16>)z_diff, (ap_uint<16>)avoid_x, (ap_uint<16>)avoid_y);
            ap_uint<160> short_command = command.range(159,0);

            datamover_outerloop_0_dataflow_read_write_dataflow_region(
                    total_pkts,
                    total_beats,
                    command,
                    short_command,
                    abs_row_offset,
                    memconfig.grid_size_y,
                    arg0_b0,
                    arg0_b1,
                    arg0_b2,
                    arg0_b3,
                    arg0_b4,
                    arg0_b5,
                    arg0_b6,
                    arg0_b7,
                    arg1_b0,
                    arg1_b1,
                    arg1_b2,
                    arg1_b3,
                    arg1_b4,
                    arg1_b5,
                    arg1_b6,
                    arg1_b7,
                    arg0_axis_out,
                    arg1_axis_in
            );
        }

        tile_x = 0;
        tile_y = 0;

        for (unsigned short tile_id = 0; tile_id < total_tiles; tile_id++)
		{
            if (tile_id > 0) {
				tile_x++;
				if (tile_x >= memconfig.tile_count_x) {
					tile_x = 0;
					tile_y++;
				}
			}

            const unsigned short tile_size_x = tile_x == (memconfig.tile_count_x -1) ? memconfig.last_tile_size_x : memconfig.tile_size_x;
			const ap_uint<64> tile_x_offset = tile_x * memconfig.effective_tile_size_x;
			const unsigned short abs_row_offset = tile_y * memconfig.effective_tile_size_y;
			const ap_uint<64> tile_y_offset = abs_row_offset * memconfig.grid_xblocks;
			const unsigned short tile_size_y = tile_y == (memconfig.tile_count_y -1) ? memconfig.last_tile_size_y : memconfig.tile_size_y;
            const ap_uint<64> offset = memconfig.start_offset + tile_x_offset ;
            const unsigned int total_beats = tile_size_x * tile_size_y * z_diff;
			const unsigned int total_pkts = total_beats * num_of_pkts_per_beat;

            const unsigned int avoid_x = tile_x == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
            const unsigned int avoid_y = tile_y == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
            auto command = ops::hls::commandGen3D(offset, 1, (ap_uint<16>)tile_size_x, (ap_uint<16>)stride_y, (ap_int<16>)tile_size_y, 
                    (ap_int<16>)stride_z, (ap_uint<16>)z_diff, (ap_uint<16>)avoid_x, (ap_uint<16>)avoid_y);
            ap_uint<160> short_command = command.range(159,0);

            datamover_outerloop_0_dataflow_read_write_dataflow_region(
                    total_pkts,
                    total_beats,
                    command,
                    short_command,
                    abs_row_offset,
                    memconfig.grid_size_y,
                    arg1_b0,
                    arg1_b1,
                    arg1_b2,
                    arg1_b3,
                    arg1_b4,
                    arg1_b5,
                    arg1_b6,
                    arg1_b7,
                    arg0_b0,
                    arg0_b1,
                    arg0_b2,
                    arg0_b3,
                    arg0_b4,
                    arg0_b5,
                    arg0_b6,
                    arg0_b7,
                    arg0_axis_out,
                    arg1_axis_in
);
        }

        tile_x = 0;
        tile_y = 0;
    }
}

static void datamover_outerloop_0_loopback_dataflow_region(
        const unsigned int num_pkts
,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_out,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in)
{
    static ::hls::stream<ap_uint<axis_data_width>> arg0_mem_strm;
    #pragma HLS STREAM variable = arg0_mem_strm
#pragma HLS DATAFLOW
    ops::hls::axis2stream<axis_data_width>(arg1_axis_in, arg0_mem_strm, num_pkts);
    ops::hls::stream2axis<axis_data_width>(arg0_mem_strm, arg0_axis_out, num_pkts);
}

static void datamover_outerloop_0_loopback(
        const unsigned int iter,
        const unsigned int num_pkts
,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_out,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg1_axis_in)
{
    for (unsigned int i = 0; i < iter; i++)
    {
     //   pragma HLS PIPELINE REWIND
    #ifdef DEBUG_LOG
        printf("[KERNEL_DEBUG]|%s| Calling loopback. i:%d\n", __func__, i);
    #endif
        datamover_outerloop_0_loopback_dataflow_region(num_pkts
,
        arg0_axis_out,
        arg1_axis_in);
    } 
}
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
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_axis_out,
    //u2
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_axis_in
    )

{
    #pragma HLS INTERFACE s_axilite port = range_start_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = range_end_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = range_start_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = range_end_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = range_start_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = range_end_2 bundle = control
 
    #pragma HLS INTERFACE s_axilite port = gridSize_0 bundle = control
    #pragma HLS INTERFACE s_axilite port = gridSize_1 bundle = control
    #pragma HLS INTERFACE s_axilite port = gridSize_2 bundle = control
    #pragma HLS INTERFACE s_axilite port = outer_itr bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = overlap_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = overlap_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = effective_tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = effective_tile_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_size_x bundle = control
    #pragma HLS INTERFACE s_axilite port = last_tile_size_y bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_count_x bundle = control
    #pragma HLS INTERFACE s_axilite port = tile_count_y bundle = control
    #pragma HLS INTERFACE s_axilite port = total_xblocks bundle = control
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem0 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem1 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem2 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem3 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem4 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem5 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem6 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem7 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b7 bundle = control
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem8 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem9 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem10 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem11 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem12 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem13 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem14 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem15 depth=4096 max_read_burst_length=16 max_write_burst_length=16 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b7 bundle = control
    #pragma HLS INTERFACE mode=axis port=arg0_axis_out register
    #pragma HLS INTERFACE mode=axis port=arg1_axis_in register

    #pragma HLS INTERFACE mode=s_axilite port=return bundle = control
    #pragma HLS INTERFACE mode=ap_ctrl_chain port=return

    ops::hls::AccessRange range;
    range.start[0] = range_start_0;
    range.end[0] = range_end_0;
    range.start[1] = range_start_1;
    range.end[1] = range_end_1;
    range.start[2] = range_start_2;
    range.end[2] = range_end_2;
    range.dim = 3;

    ops::hls::SizeType read_gridSize = { gridSize_0, gridSize_1, gridSize_2 };
    ops::hls::SizeType2d tile_size = {tile_size_x, tile_size_y};
    ops::hls::SizeType2d overlap_size = {overlap_size_x, overlap_size_y};
    ops::hls::SizeType2d effective_tile_size = {effective_tile_size_x, effective_tile_size_y};
    ops::hls::SizeType2d last_tile_size = {last_tile_size_x, last_tile_size_y};
    ops::hls::SizeType2d tile_count = {tile_count_x, tile_count_y};

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| starting datamover TOP range:(%d,%d,%d) ---> (%d,%d,%d)\n", __func__,
            range.start[0], range.start[1], range.start[2], range.end[0], range.end[1], range.end[2]);
    printf("[KERNEL_DEBUG]|%s| read_gridSize: (%d, %d, %d), \n", __func__,
            read_gridSize[0], read_gridSize[1], read_gridSize[2]);
#endif 

    ops::hls::MemConfigTile config;

    ops::hls::genMemConfigTileV2<mem_data_width, data_width>(read_gridSize, range, tile_size, tile_count, overlap_size, effective_tile_size, last_tile_size, total_xblocks, config);   
        datamover_outerloop_0_dataflow_read_write(
                outer_itr,
                config,
                arg0_b0,
                arg0_b1,
                arg0_b2,
                arg0_b3,
                arg0_b4,
                arg0_b5,
                arg0_b6,
                arg0_b7,
                arg1_b0,
                arg1_b1,
                arg1_b2,
                arg1_b3,
                arg1_b4,
                arg1_b5,
                arg1_b6,
                arg1_b7,
            arg0_axis_out,
            arg1_axis_in
            );
}


