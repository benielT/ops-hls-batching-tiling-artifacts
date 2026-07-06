// Auto-generated at 2026-07-05 14:05:30.456505 by ops-translator

#include <datamover_outerloop_0.hpp>
static void datamover_outerloop_0_dataflow_region_read(
        const unsigned int num_pkts,
        const ops::hls::MemConfig& memconfig,
        ap_uint<mem_data_width>* arg0,
        hls::stream<ap_axiu<axis_data_width, 0, 0, 0>>& arg0_axis_out)
{
#pragma HLS DATAFLOW
    ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_strm;
    #pragma HLS STREAM variable = arg0_read_mem_strm depth = 16
    ::hls::stream<ap_uint<axis_data_width>> arg0_read_reduced_mem_strm;
    #pragma HLS STREAM variable = arg0_read_reduced_mem_strm depth = 32
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
    ::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_strm;
    #pragma HLS STREAM variable = arg1_write_mem_strm depth = 16
    ::hls::stream<ap_uint<axis_data_width>> arg1_write_reduced_mem_strm;
    #pragma HLS STREAM variable = arg1_write_reduced_mem_strm depth = 32

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
        unsigned int abs_row_offset,
        unsigned int z_row_stride,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_out, const ap_uint<160>& command )
{
    // #pragma HLS INLINE off
    #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| reading tile from mem to stream \n", __func__);
    #endif

    //static ::hls::stream<ap_uint<MEM_DATA_WIDTH>> strm_internal("strm_internal");
	//#pragma HLS STREAM variable = strm_internal depth = 16

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
        unsigned int abs_row_id_of_y = y + z_row_id_offset;
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
        unsigned int abs_row_offset,
        unsigned int z_row_stride,
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
        unsigned int z_row_id_offset = abs_row_offset + z * z_row_stride;
        for (ap_uint<16> y = 0; y < size_y; y++)
        {
            #pragma HLS PIPELINE off
            // ap_uint<64> s2 = s3 + y * stride_y;
            unsigned int abs_row_id_of_y = y + z_row_id_offset;
            unsigned short bank_id = abs_row_id_of_y % NUM_BANKS;
            // unsigned int j_shifted = abs_row_id_of_y >> NUM_BANKS_SHIFT;
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

struct InterleaveTileConfig {
    unsigned int num_small_trans;
    unsigned int num_big_trans;
    unsigned short bank_tile_size_x_floor;
    unsigned short bank_tile_size_x_ceil;
    ap_uint<8> big_bank_tile_size_x_mask;
    unsigned short tile_offset_x_floor; 
    ap_uint<3> big_tile_offset_x_banks_upper;
    unsigned short tile_offset_y;
    unsigned short tile_size_y;
    unsigned int total_rows; 
    unsigned short bank_avoid_x_floor;
    ap_uint<8> big_bank_avoid_x_mask;
    unsigned short avoid_y;
};

struct InterleaveStaticTileConfig {
    unsigned short bank_grid_size_x_floor;
    ap_uint<3> big_grid_size_x_banks_upper;
    unsigned short grid_size_y;
    unsigned short tile_size_z;
};


static void datamover_outerloop_0_dataflow_read_write_dataflow_region(
        const unsigned int num_small_trans,
        const unsigned int num_big_trans,
        const unsigned short bank_tile_size_x_floor,
        const unsigned short bank_tile_size_x_ceil,
        const ap_uint<8> big_bank_tile_size_x_mask,
        const unsigned short tile_offset_x_floor,
        const ap_uint<3> big_tile_offset_x_banks_upper,
        const unsigned short tile_offset_y,
        const unsigned short tile_size_y,
        const unsigned int total_rows, 
        const unsigned short bank_avoid_x_floor,
        const ap_uint<8> big_bank_avoid_x_mask,
        const unsigned short avoid_y,
        const unsigned short bank_grid_size_x_floor,
        const ap_uint<3> big_grid_size_x_banks_upper,
        const unsigned short grid_size_y,
        const unsigned short tile_size_z,
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
{
    #pragma HLS DATAFLOW
    ::hls::stream<ap_uint<32>> arg0_read_offset_strm[8];
    #pragma HLS STREAM variable = arg0_read_offset_strm depth = 32
    ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_redirect_strm[8];
    #pragma HLS STREAM variable = arg0_read_mem_redirect_strm depth = 22   
    ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_strm[8];
    #pragma HLS STREAM variable = arg0_read_mem_strm depth = 22
    ::hls::stream<ap_uint<axis_data_width>> arg0_read_reduced_mem_strm[8];
    #pragma HLS STREAM variable = arg0_read_reduced_mem_strm depth = 38
    ::hls::stream<ap_uint<mem_data_width>> arg0_write_mem_redirect_strm[8];
    #pragma HLS STREAM variable = arg0_write_mem_redirect_strm depth = 22
    ::hls::stream<ap_uint<32>> arg0_write_offset_strm[8];
    #pragma HLS STREAM variable = arg0_write_offset_strm depth = 32    
    ::hls::stream<ap_uint<axis_data_width>> arg1_write_reduced_mem_strm[8];
    #pragma HLS STREAM variable = arg1_write_reduced_mem_strm depth = 38
    ::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_strm[8];
    #pragma HLS STREAM variable = arg1_write_mem_strm depth = 22
    ::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_redirect_strm[8];
    #pragma HLS STREAM variable = arg1_write_mem_redirect_strm depth = 22
    ::hls::stream<ap_uint<32>> arg1_write_offset_strm[8];
    #pragma HLS STREAM variable = arg1_write_offset_strm depth = 32    

        //ops::hls::mem2streamTiled<mem_data_width, 4, 2>(arg0_b1, arg0_b2, arg0_read_mem_strm, memconfig);
        //ops::hls::stridedTileMem2stream<mem_data_width,  4, 2>(arg0_b1, arg0_read_mem_strm_b1, memconfig, 0);
        //ops::hls::stridedTileMem2stream<mem_data_width,  4, 2>(arg0_b2, arg0_read_mem_strm_b2, memconfig, 1);
        //ops::hls::combineSteams<mem_data_width, 2>(arg0_read_mem_strm_b1, arg0_read_mem_strm_b2, arg0_read_mem_strm, memconfig);
        ops::hls::offsetGenerator<8, 2>(tile_size_y, tile_size_z, bank_grid_size_x_floor, big_grid_size_x_banks_upper, grid_size_y, 
                tile_offset_x_floor, big_tile_offset_x_banks_upper, tile_offset_y, bank_tile_size_x_floor, big_bank_tile_size_x_mask, arg0_read_offset_strm);
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 0, 4, 2>(arg0_b0, arg0_read_mem_strm[0],  arg0_read_offset_strm[0], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_0"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 1, 4, 2>(arg0_b1, arg0_read_mem_strm[1],  arg0_read_offset_strm[1], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_1"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 2, 4, 2>(arg0_b2, arg0_read_mem_strm[2],  arg0_read_offset_strm[2], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_2"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 3, 4, 2>(arg0_b3, arg0_read_mem_strm[3],  arg0_read_offset_strm[3], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_3"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 4, 4, 2>(arg0_b4, arg0_read_mem_strm[4],  arg0_read_offset_strm[4], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_4"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 5, 4, 2>(arg0_b5, arg0_read_mem_strm[5],  arg0_read_offset_strm[5], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_5"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 6, 4, 2>(arg0_b6, arg0_read_mem_strm[6],  arg0_read_offset_strm[6], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_6"
#endif
        );
        ops::hls::stridedTileMem2streamV4<mem_data_width, 8, 7, 4, 2>(arg0_b7, arg0_read_mem_strm[7],  arg0_read_offset_strm[7], bank_tile_size_x_floor, big_bank_tile_size_x_mask, total_rows
#ifdef DEBUG_LOG 
        , "bank_7"
#endif
        );
        ops::hls::redirectV2<mem_data_width, 8, 2>(arg0_read_mem_strm, arg0_read_mem_redirect_strm, bank_tile_size_x_floor, bank_tile_size_x_ceil, big_bank_tile_size_x_mask, big_tile_offset_x_banks_upper, total_rows);          
        ops::hls::aggregatedStream2streamStepdown<mem_data_width, axis_data_width, 8, 2>(arg0_read_mem_redirect_strm, arg0_read_reduced_mem_strm, num_big_trans);  
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[0], arg0_0_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[1], arg0_1_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[2], arg0_2_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[3], arg0_3_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[4], arg0_4_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[5], arg0_5_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[6], arg0_6_axis_out, num_small_trans);
        ops::hls::stream2axis<axis_data_width>(arg0_read_reduced_mem_strm[7], arg0_7_axis_out, num_small_trans);

        ops::hls::axis2stream<axis_data_width>(arg1_0_axis_in, arg1_write_reduced_mem_strm[0], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_1_axis_in, arg1_write_reduced_mem_strm[1], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_2_axis_in, arg1_write_reduced_mem_strm[2], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_3_axis_in, arg1_write_reduced_mem_strm[3], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_4_axis_in, arg1_write_reduced_mem_strm[4], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_5_axis_in, arg1_write_reduced_mem_strm[5], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_6_axis_in, arg1_write_reduced_mem_strm[6], num_small_trans);
        ops::hls::axis2stream<axis_data_width>(arg1_7_axis_in, arg1_write_reduced_mem_strm[7], num_small_trans);
    
        ops::hls::aggregatedStream2streamStepup<axis_data_width, mem_data_width, 8, 2>(arg1_write_reduced_mem_strm, arg1_write_mem_redirect_strm, num_big_trans);
        ops::hls::reverseRedirectV2<mem_data_width, 8, 2>(arg1_write_mem_redirect_strm, arg1_write_mem_strm, bank_tile_size_x_floor, bank_tile_size_x_ceil, big_bank_tile_size_x_mask, big_tile_offset_x_banks_upper, total_rows);
        //ops::hls::writeConfigStreamGenerator<8, 2>(offset, size_x, stride_y, size_y, stride_z, size_z, avoid_x, avoid_y, arg1_write_command_strm);
        ops::hls::offsetGenerator<8, 2>(tile_size_y, tile_size_z, bank_grid_size_x_floor, big_grid_size_x_banks_upper, grid_size_y, 
                tile_offset_x_floor, big_tile_offset_x_banks_upper, tile_offset_y, bank_tile_size_x_floor, big_bank_tile_size_x_mask, arg1_write_offset_strm);
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 0, 4, 2>(arg1_write_mem_strm[0], arg1_b0, arg1_write_offset_strm[0], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_0"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 1, 4, 2>(arg1_write_mem_strm[1], arg1_b1, arg1_write_offset_strm[1], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_1"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 2, 4, 2>(arg1_write_mem_strm[2], arg1_b2, arg1_write_offset_strm[2], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_2"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 3, 4, 2>(arg1_write_mem_strm[3], arg1_b3, arg1_write_offset_strm[3], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_3"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 4, 4, 2>(arg1_write_mem_strm[4], arg1_b4, arg1_write_offset_strm[4], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_4"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 5, 4, 2>(arg1_write_mem_strm[5], arg1_b5, arg1_write_offset_strm[5], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_5"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 6, 4, 2>(arg1_write_mem_strm[6], arg1_b6, arg1_write_offset_strm[6], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_6"
#endif
        );
        ops::hls::stridedTileStream2memWithAvoidV4<mem_data_width, 8, 7, 4, 2>(arg1_write_mem_strm[7], arg1_b7, arg1_write_offset_strm[7], bank_tile_size_x_floor, big_bank_tile_size_x_mask, bank_avoid_x_floor, big_bank_avoid_x_mask, avoid_y, tile_size_y, tile_size_z        
#ifdef DEBUG_LOG 
        , "bank_7"
#endif
        );

#ifdef DEBUG_LOG
#ifndef __SYNTHESIS__
    // -------------------------------------------------------------------------
    // HLS SIMULATION DEBUG BLOCK: Check for hanging streams
    // -------------------------------------------------------------------------

    for (int i = 0; i < 8; i++) {
        if (!arg0_read_offset_strm[i].empty())
            printf("[SIM WARNING] arg0_read_offset_strm[%d] has %zu leftover elements!\n", i, arg0_read_offset_strm[i].size());
    } 
    for (int i = 0; i < 8; i++) {
        if(!arg0_read_mem_redirect_strm[i].empty())
            printf("[SIM WARNING] arg0_read_mem_redirect_strm[%d] has %zu leftover elements!\n", i, arg0_read_mem_redirect_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg0_read_mem_strm[i].empty())
            printf("[SIM WARNING] arg0_read_mem_strm[%d] has %zu leftover elements!\n", i, arg0_read_mem_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg0_read_reduced_mem_strm[i].empty())
            printf("[SIM WARNING] arg0_read_reduced_mem_strm[%d] has %zu leftover elements!\n", i, arg0_read_reduced_mem_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg0_write_mem_redirect_strm[i].empty())
            printf("[SIM WARNING] arg0_write_mem_redirect_strm[%d] has %zu leftover elements!\n", i, arg0_write_mem_redirect_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg0_write_offset_strm[i].empty())
            printf("[SIM WARNING] arg0_write_offset_strm[%d] has %zu leftover elements!\n", i, arg0_write_offset_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg1_write_reduced_mem_strm[i].empty())
            printf("[SIM WARNING] arg1_write_reduced_mem_strm[%d] has %zu leftover elements!\n", i, arg1_write_reduced_mem_strm[i].size());
    } 
    for (int i = 0; i < 8; i++) {
        if(!arg1_write_mem_strm[i].empty())
            printf("[SIM WARNING] arg1_write_mem_strm[%d] has %zu leftover elements!\n", i, arg1_write_mem_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg1_write_mem_redirect_strm[i].empty())
            printf("[SIM WARNING] arg1_write_mem_redirect_strm[%d] has %zu leftover elements!\n", i, arg1_write_mem_redirect_strm[i].size());
    }
    for (int i = 0; i < 8; i++) {
        if(!arg1_write_offset_strm[i].empty())
            printf("[SIM WARNING] arg1_write_offset_strm[%d] has %zu leftover elements!\n", i, arg1_write_offset_strm[i].size());
    }
    // -------------------------------------------------------------------------
#endif
#endif
}

/*static void datamover_outerloop_0_tile_config_wrapper(const ops::hls::MemConfigTile& memconfig,
    const unsigned short& tile_x_id,
    const unsigned short& tile_y_id,
    const unsigned short& z_diff,
    unsigned int& num_pkts,
    unsigned int& num_beats,
    unsigned int& offset,
    unsigned short& size_x,
    unsigned short& avoid_x,
    unsigned short& size_y,
    unsigned short& avoid_y,
    unsigned int& abs_row_offset,
    bool& is_small_tile
)
{
#pragma HLS INLINE off
    const unsigned short tile_size_x = tile_x_id == (memconfig.tile_count_x -1) ? memconfig.last_tile_size_x : memconfig.tile_size_x;
    const ap_uint<64> tile_x_offset = tile_x_id * memconfig.effective_tile_size_x;
    abs_row_offset = tile_y_id * memconfig.effective_tile_size_y;
    const ap_uint<64> tile_y_offset = abs_row_offset * memconfig.grid_xblocks;
    const unsigned short tile_size_y = tile_y_id == (memconfig.tile_count_y -1) ? memconfig.last_tile_size_y : memconfig.tile_size_y;
    offset = memconfig.start_offset + tile_x_offset + tile_y_offset;
    const unsigned int tile_size_y_mul_z_diff = tile_size_y * z_diff;
    const unsigned int total_beats = tile_size_x * tile_size_y_mul_z_diff;
    const unsigned int x_pkts = (tile_size_x + 7) >> 3;
    const unsigned int total_pkts = x_pkts * tile_size_y_mul_z_diff;

    avoid_x = tile_x_id == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
    avoid_y = tile_y_id == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
    //command = ops::hls::commandGen3D(offset, 1, (ap_uint<16>)tile_size_x, (ap_uint<16>)stride_y, (ap_int<16>)tile_size_y, 
    //        (ap_int<16>)stride_z, (ap_uint<16>)z_diff, (ap_uint<16>)avoid_x, (ap_uint<16>)avoid_y);

    num_pkts = total_pkts;
    num_beats = total_beats;
    size_y = tile_size_y;
    size_x = tile_size_x;
    is_small_tile = false;
 

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|datamover_%s| \n===============================\n","__func__");
    printf("[KERNEL_DEBUG]|datamover_%s| total_beats: %d\n", "__func__", total_beats);
    printf("[KERNEL_DEBUG]|datamover_%s| total_pkts: %d\n","__func__", total_pkts);
    printf("[KERNEL_DEBUG]|datamover_%s| ===============================\n","__func__");
    printf("[KERNEL_DEBUG]|datamover_%s| command:   \n","__func__");
    printf("[KERNEL_DEBUG]|datamover_%s|    offset: %d  \n", "__func__", offset);
    printf("[KERNEL_DEBUG]|datamover_%s|    tile_x: %d  \n","__func__" , tile_size_x);
    printf("[KERNEL_DEBUG]|datamover_%s|    tile_y: %d  \n","__func__", tile_size_y);
    printf("[KERNEL_DEBUG]|datamover_%s|    tile_z: %d  \n","__func__" , z_diff);
    printf("[KERNEL_DEBUG]|datamover_%s|    avoid_x: %d  \n","__func__" , avoid_x);
    printf("[KERNEL_DEBUG]|datamover_%s|    avoid_y: %d  \n","__func__", avoid_y);
    printf("[KERNEL_DEBUG]|datamover_%s|    x_pkts: %d  \n","__func__", x_pkts);
    printf("[KERNEL_DEBUG]|datamover_%s|    is_small_tile: %d  \n","__func__", is_small_tile);
    printf("[KERNEL_DEBUG]|datamover_%s| ===============================\n","__func__");
#endif
}*/

static void datamover_outerloop_0_tile_config_wrapper(const ops::hls::MemConfigTile& memconfig,
        const unsigned short& tile_x_id,
        const unsigned short& tile_y_id,
        const unsigned short& tile_size_z,
        InterleaveTileConfig& tile_config) {
    #pragma HLS INLINE
    constexpr unsigned short BANK_SHIFT = 3;
    constexpr unsigned short BANK_MASK = 7;
    const unsigned short tile_size_x = tile_x_id == (memconfig.tile_count_x - 1) ? memconfig.last_tile_size_x : memconfig.tile_size_x;
    const unsigned short tile_size_y = tile_y_id == (memconfig.tile_count_y - 1) ? memconfig.last_tile_size_y : memconfig.tile_size_y;
    const unsigned int num_rows = tile_size_y * tile_size_z;
    tile_config.tile_size_y = tile_size_y;
    tile_config.total_rows = num_rows;
    const unsigned short tile_offset_x = tile_x_id * memconfig.effective_tile_size_x;
    tile_config.tile_offset_x_floor = tile_offset_x >> BANK_SHIFT;
    tile_config.big_tile_offset_x_banks_upper = tile_offset_x & BANK_MASK;
    const unsigned short tile_offset_y = tile_y_id * memconfig.effective_tile_size_y;
    tile_config.tile_offset_y = tile_offset_y;
    const unsigned bank_tile_size_x_ceil = (tile_size_x + BANK_MASK) >> BANK_SHIFT;
    const unsigned bank_tile_size_x_floor = tile_size_x >> BANK_SHIFT;
    tile_config.bank_tile_size_x_ceil = bank_tile_size_x_ceil;
    tile_config.bank_tile_size_x_floor = bank_tile_size_x_floor;
    tile_config.num_big_trans = bank_tile_size_x_ceil * num_rows;
    tile_config.num_small_trans = tile_config.num_big_trans << 1;

    const unsigned short avoid_x = tile_x_id == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
    tile_config.bank_avoid_x_floor = avoid_x >> BANK_SHIFT;
    const unsigned short avoid_y = tile_y_id == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
    tile_config.avoid_y = avoid_y;

    const ap_uint<3> start_bank = tile_offset_x & BANK_MASK;
    const ap_uint<3> tile_size_x_mod_bank = tile_size_x & BANK_MASK; //i.e, Ending bank relative to start
    const ap_uint<3> end_bank = start_bank + tile_size_x_mod_bank;
    bool is_t1_or_t2 = end_bank < start_bank;

    const ap_uint<3> avoid_x_mod_banks = avoid_x & BANK_MASK; //i.e, Ending bank big bank_avoid_x relative to start
    const ap_uint<3> end_bank_avoid_x = start_bank + avoid_x_mod_banks;
    bool is_avoid_x_t1_or_t2 = end_bank_avoid_x < start_bank;

    for (ap_uint<4> i = 0; i < 8; i++) 
    {
        #pragma HLS UNROLL
        const bool is_gt_sb = i >= start_bank;
        const bool is_lt_uplim = i < end_bank;
        const bool is_avoid_x_lt_uplim = i < end_bank_avoid_x;

        tile_config.big_bank_tile_size_x_mask[i] = is_t1_or_t2 ? is_gt_sb || is_lt_uplim : is_gt_sb && is_lt_uplim;
        tile_config.big_bank_avoid_x_mask[i] = is_avoid_x_t1_or_t2 ? is_gt_sb || is_avoid_x_lt_uplim : is_gt_sb && is_avoid_x_lt_uplim;
    } 
}

static void datamover_outerloop_0_static_tile_config_wrapper(const ops::hls::MemConfigTile& memconfig,
        InterleaveStaticTileConfig& staticConfig) {
    #pragma HLS INLINE
    staticConfig.tile_size_z = memconfig.end_z - memconfig.start_z;
    staticConfig.bank_grid_size_x_floor = memconfig.grid_xblocks >> 3;
    staticConfig.big_grid_size_x_banks_upper = memconfig.grid_xblocks & 7;
    staticConfig.grid_size_y = memconfig.grid_size_y;
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
{
    //TODO: memconfig.start_offset need to be handled for multibank tiling if start_offset != 0. In all our cased start_offset == 0 for now
    const unsigned int iter_by_2 = iter >> 1;
    const unsigned short total_tiles = memconfig.tile_count_x * memconfig.tile_count_y;
    //const unsigned short z_diff = memconfig.end_z - memconfig.start_z;
    //const unsigned short stride_z = memconfig.grid_xblocks * memconfig.grid_size_y;
	unsigned short tile_y = 0;
	unsigned short tile_x = 0;
	const unsigned short stride_y = memconfig.grid_xblocks;
    InterleaveStaticTileConfig staticConfig;
    datamover_outerloop_0_static_tile_config_wrapper(memconfig, staticConfig);
    for (unsigned int i = 0; i < iter_by_2; i++)
    {
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

            unsigned int total_beats = 0;
            unsigned int total_pkts = 0;

            unsigned int offset = 0;
            unsigned short size_x = 0;
            unsigned short avoid_x = 0;
            unsigned short size_y = 0;
            unsigned short avoid_y = 0;
            unsigned int abs_row_offset = 0;
            bool is_small_tile = false;

            InterleaveTileConfig interleaveTileConfig;
            //datamover_outerloop_0_tile_config_wrapper(memconfig, tile_x, tile_y, z_diff, total_pkts, ////total_beats, offset, size_x, avoid_x, size_y, avoid_y, abs_row_offset, // is_small_tile );
            datamover_outerloop_0_tile_config_wrapper(memconfig, tile_x, tile_y, staticConfig.tile_size_z, interleaveTileConfig);
        
            // unsigned int small_tile_pkts = total_pkts << 1;

#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|datamover_%s| \n=============== Interleave Tile Config ================\n","isl0");
            printf("[KERNEL_DEBUG]|datamover_%s|    total_pkts: %u\n","isl0", interleaveTileConfig.num_big_trans);
            printf("[KERNEL_DEBUG]|datamover_%s|    small_tile_pkts: %u\n","isl0", interleaveTileConfig.num_small_trans);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_tile_size_x_floor: %u  \n", "isl0", interleaveTileConfig.bank_tile_size_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_tile_size_x_ceil: %u  \n","isl0" , interleaveTileConfig.bank_tile_size_x_ceil);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_bank_tile_size_x_mask: ","isl0");
            for (ap_uint<4> b_id = 0; b_id < 8; b_id++) {
                printf("%d", (unsigned short)interleaveTileConfig.big_bank_tile_size_x_mask[b_id]);
                if (b_id != 8 - 1) 
                    printf(", ");
            }
            printf("\n");
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_offset_x_floor: %u  \n","isl0" , interleaveTileConfig.tile_offset_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_tile_offset_x_banks_upper: %u  \n","isl0" , interleaveTileConfig.big_tile_offset_x_banks_upper);
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_offset_y: %u  \n","isl0" , interleaveTileConfig.tile_offset_y);
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_size_y: %d  \n","isl0", interleaveTileConfig.tile_size_y);
            printf("[KERNEL_DEBUG]|datamover_%s|    total_rows: %d  \n","isl0", interleaveTileConfig.total_rows);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_avoid_x_floor: %d  \n","isl0" , interleaveTileConfig.bank_avoid_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_bank_avoid_x_mask: ","isl0");
            for (ap_uint<4> b_id = 0; b_id < 8; b_id++) {
                printf("%d",  (unsigned short)interleaveTileConfig.big_bank_avoid_x_mask[b_id]);
                if (b_id != 8 - 1) 
                    printf(", ");
            }
            printf("\n");
            printf("[KERNEL_DEBUG]|datamover_%s|    avoid_y: %d  \n","isl0", interleaveTileConfig.avoid_y);
            printf("[KERNEL_DEBUG]|datamover_%s| ===============================\n","isl0");
#endif





            datamover_outerloop_0_dataflow_read_write_dataflow_region(
                    interleaveTileConfig.num_small_trans,
                    interleaveTileConfig.num_big_trans,
                    interleaveTileConfig.bank_tile_size_x_floor,
                    interleaveTileConfig.bank_tile_size_x_ceil,
                    interleaveTileConfig.big_bank_tile_size_x_mask,
                    interleaveTileConfig.tile_offset_x_floor,
                    interleaveTileConfig.big_tile_offset_x_banks_upper,
                    interleaveTileConfig.tile_offset_y,
                    interleaveTileConfig.tile_size_y,
                    interleaveTileConfig.total_rows,
                    interleaveTileConfig.bank_avoid_x_floor,
                    interleaveTileConfig.big_bank_avoid_x_mask,
                    interleaveTileConfig.avoid_y,
                    staticConfig.bank_grid_size_x_floor,
                    staticConfig.big_grid_size_x_banks_upper,
                    staticConfig.grid_size_y,
                    staticConfig.tile_size_z,
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
                    arg0_0_axis_out,
                arg0_1_axis_out,
                arg0_2_axis_out,
                arg0_3_axis_out,
                arg0_4_axis_out,
                arg0_5_axis_out,
                arg0_6_axis_out,
                arg0_7_axis_out,
                arg1_0_axis_in,
                arg1_1_axis_in,
                arg1_2_axis_in,
                arg1_3_axis_in,
                arg1_4_axis_in,
                arg1_5_axis_in,
                arg1_6_axis_in,
                arg1_7_axis_in

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

            
            unsigned int total_beats = 0;
            unsigned int total_pkts = 0;

            unsigned int offset = 0;
            unsigned short size_x = 0;
            unsigned short avoid_x = 0;
            unsigned short size_y = 0;
            unsigned short avoid_y = 0;
            unsigned int abs_row_offset = 0;
            bool is_small_tile = false;

            InterleaveTileConfig interleaveTileConfig;
            //datamover_outerloop_0_tile_config_wrapper(memconfig, tile_x, tile_y, z_diff, total_pkts, total_beats, offset, size_x, avoid_x, size_y, avoid_y, abs_row_offset,  is_small_tile );
            datamover_outerloop_0_tile_config_wrapper(memconfig, tile_x, tile_y, staticConfig.tile_size_z, interleaveTileConfig);
        
            //unsigned int small_tile_pkts = total_pkts << 1;
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|datamover_%s| \n=============== Interleave Tile Config ================\n","isl0");
            printf("[KERNEL_DEBUG]|datamover_%s|    total_pkts: %u\n","isl0", interleaveTileConfig.num_big_trans);
            printf("[KERNEL_DEBUG]|datamover_%s|    small_tile_pkts: %u\n","isl0", interleaveTileConfig.num_small_trans);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_tile_size_x_floor: %u  \n", "isl0", interleaveTileConfig.bank_tile_size_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_tile_size_x_ceil: %u  \n","isl0" , interleaveTileConfig.bank_tile_size_x_ceil);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_bank_tile_size_x_mask: ","isl0");
            for (ap_uint<4> b_id = 0; b_id < 8; b_id++) {
                printf("%d", (unsigned short)interleaveTileConfig.big_bank_tile_size_x_mask[b_id]);
                if (b_id != 8 - 1) 
                    printf(", ");
            }
            printf("\n");
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_offset_x_floor: %u  \n","isl0" , interleaveTileConfig.tile_offset_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_tile_offset_x_banks_upper: %u  \n","isl0" , interleaveTileConfig.big_tile_offset_x_banks_upper);
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_offset_y: %u  \n","isl0" , interleaveTileConfig.tile_offset_y);
            printf("[KERNEL_DEBUG]|datamover_%s|    tile_size_y: %d  \n","isl0", interleaveTileConfig.tile_size_y);
            printf("[KERNEL_DEBUG]|datamover_%s|    total_rows: %d  \n","isl0", interleaveTileConfig.total_rows);
            printf("[KERNEL_DEBUG]|datamover_%s|    bank_avoid_x_floor: %d  \n","isl0" , interleaveTileConfig.bank_avoid_x_floor);
            printf("[KERNEL_DEBUG]|datamover_%s|    big_bank_avoid_x_mask: ","isl0");
            for (ap_uint<4> b_id = 0; b_id < 8; b_id++) {
                printf("%d",  (unsigned short)interleaveTileConfig.big_bank_avoid_x_mask[b_id]);
                if (b_id != 8 - 1) 
                    printf(", ");
            }
            printf("\n");
            printf("[KERNEL_DEBUG]|datamover_%s|    avoid_y: %d  \n","isl0", interleaveTileConfig.avoid_y);
            printf("[KERNEL_DEBUG]|datamover_%s| ===============================\n","isl0");
#endif


            datamover_outerloop_0_dataflow_read_write_dataflow_region(
                    interleaveTileConfig.num_small_trans,
                    interleaveTileConfig.num_big_trans,
                    interleaveTileConfig.bank_tile_size_x_floor,
                    interleaveTileConfig.bank_tile_size_x_ceil,
                    interleaveTileConfig.big_bank_tile_size_x_mask,
                    interleaveTileConfig.tile_offset_x_floor,
                    interleaveTileConfig.big_tile_offset_x_banks_upper,
                    interleaveTileConfig.tile_offset_y,
                    interleaveTileConfig.tile_size_y,
                    interleaveTileConfig.total_rows,
                    interleaveTileConfig.bank_avoid_x_floor,
                    interleaveTileConfig.big_bank_avoid_x_mask,
                    interleaveTileConfig.avoid_y,
                    staticConfig.bank_grid_size_x_floor,
                    staticConfig.big_grid_size_x_banks_upper,
                    staticConfig.grid_size_y,
                    staticConfig.tile_size_z,
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
                    arg0_0_axis_out,
                arg0_1_axis_out,
                arg0_2_axis_out,
                arg0_3_axis_out,
                arg0_4_axis_out,
                arg0_5_axis_out,
                arg0_6_axis_out,
                arg0_7_axis_out,
                arg1_0_axis_in,
                arg1_1_axis_in,
                arg1_2_axis_in,
                arg1_3_axis_in,
                arg1_4_axis_in,
                arg1_5_axis_in,
                arg1_6_axis_in,
                arg1_7_axis_in

            );
        }

        tile_x = 0;
        tile_y = 0;
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
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem0 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem1 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem2 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem3 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem4 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem5 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem6 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem7 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg0_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b7 bundle = control
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem8 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem9 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem10 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem11 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem12 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem13 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem14 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem15 depth=4096 max_read_burst_length=4 max_write_burst_length=4 \
            num_read_outstanding=4 num_write_outstanding=4 \
            port=arg1_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b7 bundle = control
    #pragma HLS INTERFACE mode=axis port=arg0_0_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_1_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_2_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_3_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_4_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_5_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_6_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg0_7_axis_out register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_0_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_1_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_2_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_3_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_4_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_5_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_6_axis_in register register_mode=both
    #pragma HLS INTERFACE mode=axis port=arg1_7_axis_in register register_mode=both

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
                        arg0_0_axis_out,
                arg0_1_axis_out,
                arg0_2_axis_out,
                arg0_3_axis_out,
                arg0_4_axis_out,
                arg0_5_axis_out,
                arg0_6_axis_out,
                arg0_7_axis_out,
                arg1_0_axis_in,
                arg1_1_axis_in,
                arg1_2_axis_in,
                arg1_3_axis_in,
                arg1_4_axis_in,
                arg1_5_axis_in,
                arg1_6_axis_in,
                arg1_7_axis_in

            );
}


