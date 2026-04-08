// Auto-generated at 2026-03-13 23:06:00.651449 by ops-translator
#include "datamover_outerloop_0.hpp"


template <unsigned short NUM_BANKS, unsigned short IN_ITR=2>
static void read_config_stream_gen(const ap_uint<160>& command, 
    ::hls::stream<ap_uint<48>>& b0_command_strm,
    ::hls::stream<ap_uint<48>>& b1_command_strm,
    ::hls::stream<ap_uint<48>>& b2_command_strm,
    ::hls::stream<ap_uint<48>>& b3_command_strm,
    ::hls::stream<ap_uint<48>>& b4_command_strm,
    ::hls::stream<ap_uint<48>>& b5_command_strm,
    ::hls::stream<ap_uint<48>>& b6_command_strm,
    ::hls::stream<ap_uint<48>>& b7_command_strm)
{
	unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);
	size_t offset_x = command.range(63,0);
	ap_uint<16> size_x = command.range(95,80);
	ap_uint<16> stride_y = command.range(111,96);
	ap_uint<16> size_y = command.range(127,112);
	ap_uint<16> stride_z = command.range(143,128);
	ap_uint<16> size_z = command.range(159,144);

	const unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
	const ap_uint<3> size_x_mod_num_banks = size_x % NUM_BANKS;

	for (unsigned short z = 0; z < size_z; z++)
	{
	    for (unsigned short y = 0; y < size_y; y++)
	    {
//		#pragma HLS PIPELINE II = IN_ITR

	    	size_t z_offset = offset_x + z * stride_z;
	    	size_t abs_offset = z_offset + y * stride_y;
			const unsigned int bank_offset = abs_offset >> NUM_BANKS_SHIFT;
			const ap_uint<3> starting_bank = abs_offset % NUM_BANKS; //starting bank
			const ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_num_banks;
			const bool is_t1_or_t2 = banks_upper_limit < starting_bank;

			const unsigned int bank_offset_b0 = ap_uint<3>(0) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b1 = ap_uint<3>(1) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b2 = ap_uint<3>(2) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b3 = ap_uint<3>(3) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b4 = ap_uint<3>(4) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b5 = ap_uint<3>(5) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b6 = ap_uint<3>(6) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b7 = ap_uint<3>(7) < starting_bank ? bank_offset + 1: bank_offset;

			const bool is_b0_gt_sb = ap_uint<3>(0) >= starting_bank;
			const bool is_b1_gt_sb = ap_uint<3>(1) >= starting_bank;
			const bool is_b2_gt_sb = ap_uint<3>(2) >= starting_bank;
			const bool is_b3_gt_sb = ap_uint<3>(3) >= starting_bank;
			const bool is_b4_gt_sb = ap_uint<3>(4) >= starting_bank;
			const bool is_b5_gt_sb = ap_uint<3>(5) >= starting_bank;
			const bool is_b6_gt_sb = ap_uint<3>(6) >= starting_bank;
			const bool is_b7_gt_sb = ap_uint<3>(7) >= starting_bank;

			const bool is_b0_lt_uplim = ap_uint<3>(0) < banks_upper_limit;
			const bool is_b1_lt_uplim = ap_uint<3>(1) < banks_upper_limit;
			const bool is_b2_lt_uplim = ap_uint<3>(2) < banks_upper_limit;
			const bool is_b3_lt_uplim = ap_uint<3>(3) < banks_upper_limit;
			const bool is_b4_lt_uplim = ap_uint<3>(4) < banks_upper_limit;
			const bool is_b5_lt_uplim = ap_uint<3>(5) < banks_upper_limit;
			const bool is_b6_lt_uplim = ap_uint<3>(6) < banks_upper_limit;
			const bool is_b7_lt_uplim = ap_uint<3>(7) < banks_upper_limit;

			bool b0_cond, b1_cond, b2_cond, b3_cond, b4_cond, b5_cond, b6_cond, b7_cond;

			if (is_t1_or_t2) {
				b0_cond = is_b0_gt_sb || is_b0_lt_uplim;
				b1_cond = is_b1_gt_sb || is_b1_lt_uplim;
				b2_cond = is_b2_gt_sb || is_b2_lt_uplim;
				b3_cond = is_b3_gt_sb || is_b3_lt_uplim;
				b4_cond = is_b4_gt_sb || is_b4_lt_uplim;
				b5_cond = is_b5_gt_sb || is_b5_lt_uplim;
				b6_cond = is_b6_gt_sb || is_b6_lt_uplim;
				b7_cond = is_b7_gt_sb || is_b7_lt_uplim;
			} else {
				b0_cond = is_b0_gt_sb && is_b0_lt_uplim;
				b1_cond = is_b1_gt_sb && is_b1_lt_uplim;
				b2_cond = is_b2_gt_sb && is_b2_lt_uplim;
				b3_cond = is_b3_gt_sb && is_b3_lt_uplim;
				b4_cond = is_b4_gt_sb && is_b4_lt_uplim;
				b5_cond = is_b5_gt_sb && is_b5_lt_uplim;
				b6_cond = is_b6_gt_sb && is_b6_lt_uplim;
				b7_cond = is_b7_gt_sb && is_b7_lt_uplim;
			}
			const unsigned char add_arg_b0 = b0_cond ? 1 : 0;
			const unsigned char add_arg_b1 = b1_cond ? 1 : 0;
            const unsigned char add_arg_b2 = b2_cond ? 1 : 0;
			const unsigned char add_arg_b3 = b3_cond ? 1 : 0;
            const unsigned char add_arg_b4 = b4_cond ? 1 : 0;
			const unsigned char add_arg_b5 = b5_cond ? 1 : 0;
            const unsigned char add_arg_b6 = b6_cond ? 1 : 0;
			const unsigned char add_arg_b7 = b7_cond ? 1 : 0;

			unsigned short b0_size_x = size_x_div_by_banks_floor + add_arg_b0;
			unsigned short b1_size_x = size_x_div_by_banks_floor + add_arg_b1;
            unsigned short b2_size_x = size_x_div_by_banks_floor + add_arg_b2;
			unsigned short b3_size_x = size_x_div_by_banks_floor + add_arg_b3;
            unsigned short b4_size_x = size_x_div_by_banks_floor + add_arg_b4;
			unsigned short b5_size_x = size_x_div_by_banks_floor + add_arg_b5;
            unsigned short b6_size_x = size_x_div_by_banks_floor + add_arg_b6;
			unsigned short b7_size_x = size_x_div_by_banks_floor + add_arg_b7;

            ap_uint<48> b0_command, b1_command, b2_command, b3_command, b4_command, b5_command, b6_command, b7_command;
            
            b0_command.range(31,0) = bank_offset_b0;
            b1_command.range(31,0) = bank_offset_b1;
            b2_command.range(31,0) = bank_offset_b2;
            b3_command.range(31,0) = bank_offset_b3;
            b4_command.range(31,0) = bank_offset_b4;
            b5_command.range(31,0) = bank_offset_b5;
            b6_command.range(31,0) = bank_offset_b6;
            b7_command.range(31,0) = bank_offset_b7;
            b0_command.range(47,32) = b0_size_x;
            b1_command.range(47,32) = b1_size_x;
            b2_command.range(47,32) = b2_size_x;
            b3_command.range(47,32) = b3_size_x;
            b4_command.range(47,32) = b4_size_x;
            b5_command.range(47,32) = b5_size_x;
            b6_command.range(47,32) = b6_size_x;
            b7_command.range(47,32) = b7_size_x;

            b0_command_strm << b0_command;
            b1_command_strm << b1_command;
            b2_command_strm << b2_command;
            b3_command_strm << b3_command;
            b4_command_strm << b4_command;
            b5_command_strm << b5_command;
            b6_command_strm << b6_command;
            b7_command_strm << b7_command;
	    }
	}
}

template <unsigned short NUM_BANKS, unsigned short IN_ITR=2>
static void write_config_stream_gen(const ap_uint<192>& command,
    ::hls::stream<ap_uint<64>>& b0_command_strm,
    ::hls::stream<ap_uint<64>>& b1_command_strm,
    ::hls::stream<ap_uint<64>>& b2_command_strm,
    ::hls::stream<ap_uint<64>>& b3_command_strm,
    ::hls::stream<ap_uint<64>>& b4_command_strm,
    ::hls::stream<ap_uint<64>>& b5_command_strm,
    ::hls::stream<ap_uint<64>>& b6_command_strm,
    ::hls::stream<ap_uint<64>>& b7_command_strm)
{
	unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);
	ap_uint<64> offset_x = command.range(63,0);
	ap_uint<16> size_x = command.range(95,80);
	ap_uint<16> stride_y = command.range(111,96);
	ap_uint<16> size_y = command.range(127,112);
	ap_uint<16> stride_z = command.range(143,128);
	ap_uint<16> size_z = command.range(159,144);
	ap_uint<16> avoid_x = command.range(175,160);
	ap_uint<16> avoid_y = command.range(191,176);

	unsigned short avoid_x_per_bank = avoid_x >> NUM_BANKS_SHIFT;
		ap_uint<3> avoid_x_mod_banks = avoid_x % NUM_BANKS;

	const unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
	const ap_uint<3> size_x_mod_banks = size_x % NUM_BANKS;

	for (unsigned short z = 0; z < size_z; z++)
	{
	    for (unsigned short y = 0; y < size_y; y++)
	    {
#pragma HLS LOOP_FLATTEN
//		#pragma HLS PIPELINE II = IN_ITR

	    	size_t z_offset = offset_x + z * stride_z;
	    	size_t abs_offset = z_offset + y * stride_y;
			const unsigned int bank_offset = abs_offset >> NUM_BANKS_SHIFT;
			const ap_uint<3> starting_bank = abs_offset % NUM_BANKS; //starting bank
			const ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_banks;
			const bool is_t1_or_t2 = banks_upper_limit < starting_bank;
			const ap_uint<3> avoid_x_bank_upper_limit = starting_bank + avoid_x_mod_banks;
			const bool is_t1_or_t2_avoid_x = avoid_x_bank_upper_limit < starting_bank;

			const unsigned int bank_offset_b0 = ap_uint<3>(0) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b1 = ap_uint<3>(1) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b2 = ap_uint<3>(2) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b3 = ap_uint<3>(3) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b4 = ap_uint<3>(4) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b5 = ap_uint<3>(5) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b6 = ap_uint<3>(6) < starting_bank ? bank_offset + 1: bank_offset;
			const unsigned int bank_offset_b7 = ap_uint<3>(7) < starting_bank ? bank_offset + 1: bank_offset;

			const bool is_b0_gt_sb = ap_uint<3>(0) >= starting_bank;
			const bool is_b1_gt_sb = ap_uint<3>(1) >= starting_bank;
			const bool is_b2_gt_sb = ap_uint<3>(2) >= starting_bank;
			const bool is_b3_gt_sb = ap_uint<3>(3) >= starting_bank;
			const bool is_b4_gt_sb = ap_uint<3>(4) >= starting_bank;
			const bool is_b5_gt_sb = ap_uint<3>(5) >= starting_bank;
			const bool is_b6_gt_sb = ap_uint<3>(6) >= starting_bank;
			const bool is_b7_gt_sb = ap_uint<3>(7) >= starting_bank;

			const bool is_b0_lt_uplim = ap_uint<3>(0) < banks_upper_limit;
			const bool is_b1_lt_uplim = ap_uint<3>(1) < banks_upper_limit;
			const bool is_b2_lt_uplim = ap_uint<3>(2) < banks_upper_limit;
			const bool is_b3_lt_uplim = ap_uint<3>(3) < banks_upper_limit;
			const bool is_b4_lt_uplim = ap_uint<3>(4) < banks_upper_limit;
			const bool is_b5_lt_uplim = ap_uint<3>(5) < banks_upper_limit;
			const bool is_b6_lt_uplim = ap_uint<3>(6) < banks_upper_limit;
			const bool is_b7_lt_uplim = ap_uint<3>(7) < banks_upper_limit;

			bool b0_cond, b1_cond, b2_cond, b3_cond, b4_cond, b5_cond, b6_cond, b7_cond;

			if (is_t1_or_t2) {
				b0_cond = is_b0_gt_sb || is_b0_lt_uplim;
				b1_cond = is_b1_gt_sb || is_b1_lt_uplim;
				b2_cond = is_b2_gt_sb || is_b2_lt_uplim;
				b3_cond = is_b3_gt_sb || is_b3_lt_uplim;
				b4_cond = is_b4_gt_sb || is_b4_lt_uplim;
				b5_cond = is_b5_gt_sb || is_b5_lt_uplim;
				b6_cond = is_b6_gt_sb || is_b6_lt_uplim;
				b7_cond = is_b7_gt_sb || is_b7_lt_uplim;
			} else {
				b0_cond = is_b0_gt_sb && is_b0_lt_uplim;
				b1_cond = is_b1_gt_sb && is_b1_lt_uplim;
				b2_cond = is_b2_gt_sb && is_b2_lt_uplim;
				b3_cond = is_b3_gt_sb && is_b3_lt_uplim;
				b4_cond = is_b4_gt_sb && is_b4_lt_uplim;
				b5_cond = is_b5_gt_sb && is_b5_lt_uplim;
				b6_cond = is_b6_gt_sb && is_b6_lt_uplim;
				b7_cond = is_b7_gt_sb && is_b7_lt_uplim;
			}
			const unsigned char add_arg_b0 = b0_cond ? 1 : 0;
			const unsigned char add_arg_b1 = b1_cond ? 1 : 0;
            const unsigned char add_arg_b2 = b2_cond ? 1 : 0;
			const unsigned char add_arg_b3 = b3_cond ? 1 : 0;
            const unsigned char add_arg_b4 = b4_cond ? 1 : 0;
			const unsigned char add_arg_b5 = b5_cond ? 1 : 0;
            const unsigned char add_arg_b6 = b6_cond ? 1 : 0;
			const unsigned char add_arg_b7 = b7_cond ? 1 : 0;

			unsigned short b0_size_x = size_x_div_by_banks_floor + add_arg_b0;
			unsigned short b1_size_x = size_x_div_by_banks_floor + add_arg_b1;
            unsigned short b2_size_x = size_x_div_by_banks_floor + add_arg_b2;
			unsigned short b3_size_x = size_x_div_by_banks_floor + add_arg_b3;
            unsigned short b4_size_x = size_x_div_by_banks_floor + add_arg_b4;
			unsigned short b5_size_x = size_x_div_by_banks_floor + add_arg_b5;
            unsigned short b6_size_x = size_x_div_by_banks_floor + add_arg_b6;
			unsigned short b7_size_x = size_x_div_by_banks_floor + add_arg_b7;

			const bool is_b0_lt_avoid_uplim = ap_uint<3>(0) < avoid_x_bank_upper_limit;
			const bool is_b1_lt_avoid_uplim = ap_uint<3>(1) < avoid_x_bank_upper_limit;
			const bool is_b2_lt_avoid_uplim = ap_uint<3>(2) < avoid_x_bank_upper_limit;
			const bool is_b3_lt_avoid_uplim = ap_uint<3>(3) < avoid_x_bank_upper_limit;
			const bool is_b4_lt_avoid_uplim = ap_uint<3>(4) < avoid_x_bank_upper_limit;
			const bool is_b5_lt_avoid_uplim = ap_uint<3>(5) < avoid_x_bank_upper_limit;
			const bool is_b6_lt_avoid_uplim = ap_uint<3>(6) < avoid_x_bank_upper_limit;
			const bool is_b7_lt_avoid_uplim = ap_uint<3>(7) < avoid_x_bank_upper_limit;

			bool b0_avoid_x_cond, b1_avoid_x_cond, b2_avoid_x_cond, b3_avoid_x_cond, b4_avoid_x_cond,
				b5_avoid_x_cond, b6_avoid_x_cond, b7_avoid_x_cond;

			if (is_t1_or_t2_avoid_x) {
				b0_avoid_x_cond = is_b0_gt_sb || is_b0_lt_avoid_uplim;
				b1_avoid_x_cond = is_b1_gt_sb || is_b1_lt_avoid_uplim;
				b2_avoid_x_cond = is_b2_gt_sb || is_b2_lt_avoid_uplim;
				b3_avoid_x_cond = is_b3_gt_sb || is_b3_lt_avoid_uplim;
				b4_avoid_x_cond = is_b4_gt_sb || is_b4_lt_avoid_uplim;
				b5_avoid_x_cond = is_b5_gt_sb || is_b5_lt_avoid_uplim;
				b6_avoid_x_cond = is_b6_gt_sb || is_b6_lt_avoid_uplim;
				b7_avoid_x_cond = is_b7_gt_sb || is_b7_lt_avoid_uplim;
			} else {
				b0_avoid_x_cond = is_b0_gt_sb && is_b0_lt_avoid_uplim;
				b1_avoid_x_cond = is_b1_gt_sb && is_b1_lt_avoid_uplim;
				b2_avoid_x_cond = is_b2_gt_sb && is_b2_lt_avoid_uplim;
				b3_avoid_x_cond = is_b3_gt_sb && is_b3_lt_avoid_uplim;
				b4_avoid_x_cond = is_b4_gt_sb && is_b4_lt_avoid_uplim;
				b5_avoid_x_cond = is_b5_gt_sb && is_b5_lt_avoid_uplim;
				b6_avoid_x_cond = is_b6_gt_sb && is_b6_lt_avoid_uplim;
				b7_avoid_x_cond = is_b7_gt_sb && is_b7_lt_avoid_uplim;
			}
			const unsigned char add_avoid_x_arg_b0 = b0_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b1 = b1_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b2 = b2_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b3 = b3_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b4 = b4_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b5 = b5_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b6 = b6_avoid_x_cond ? 1 : 0;
			const unsigned char add_avoid_x_arg_b7 = b7_avoid_x_cond ? 1 : 0;

			const unsigned char adj_b0_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b0;
			const unsigned char adj_b1_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b1;
			const unsigned char adj_b2_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b2;
			const unsigned char adj_b3_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b3;
			const unsigned char adj_b4_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b4;
			const unsigned char adj_b5_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b5;
			const unsigned char adj_b6_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b6;
			const unsigned char adj_b7_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b7;

			unsigned short b0_avoid_x = y < avoid_y ? b0_size_x : adj_b0_avoid_x;
			unsigned short b1_avoid_x = y < avoid_y ? b1_size_x : adj_b1_avoid_x;
			unsigned short b2_avoid_x = y < avoid_y ? b2_size_x : adj_b2_avoid_x;
			unsigned short b3_avoid_x = y < avoid_y ? b3_size_x : adj_b3_avoid_x;
			unsigned short b4_avoid_x = y < avoid_y ? b4_size_x : adj_b4_avoid_x;
			unsigned short b5_avoid_x = y < avoid_y ? b5_size_x : adj_b5_avoid_x;
			unsigned short b6_avoid_x = y < avoid_y ? b6_size_x : adj_b6_avoid_x;
			unsigned short b7_avoid_x = y < avoid_y ? b7_size_x : adj_b7_avoid_x;

			b0_avoid_x = b0_avoid_x > b0_size_x ? b0_size_x : b0_avoid_x;
			b1_avoid_x = b1_avoid_x > b1_size_x ? b1_size_x : b1_avoid_x;
			b2_avoid_x = b2_avoid_x > b2_size_x ? b2_size_x : b2_avoid_x;
			b3_avoid_x = b3_avoid_x > b3_size_x ? b3_size_x : b3_avoid_x;
			b4_avoid_x = b4_avoid_x > b4_size_x ? b4_size_x : b4_avoid_x;
			b5_avoid_x = b5_avoid_x > b5_size_x ? b5_size_x : b5_avoid_x;
			b6_avoid_x = b6_avoid_x > b6_size_x ? b6_size_x : b6_avoid_x;
			b7_avoid_x = b7_avoid_x > b7_size_x ? b7_size_x : b7_avoid_x;


            ap_uint<64> b0_command, b1_command, b2_command, b3_command, b4_command, b5_command, b6_command, b7_command;

            b0_command.range(31,0) = bank_offset_b0;
            b1_command.range(31,0) = bank_offset_b1;
            b2_command.range(31,0) = bank_offset_b2;
            b3_command.range(31,0) = bank_offset_b3;
            b4_command.range(31,0) = bank_offset_b4;
            b5_command.range(31,0) = bank_offset_b5;
            b6_command.range(31,0) = bank_offset_b6;
            b7_command.range(31,0) = bank_offset_b7;
            b0_command.range(47,32) = b0_size_x;
            b1_command.range(47,32) = b1_size_x;
            b2_command.range(47,32) = b2_size_x;
            b3_command.range(47,32) = b3_size_x;
            b4_command.range(47,32) = b4_size_x;
            b5_command.range(47,32) = b5_size_x;
            b6_command.range(47,32) = b6_size_x;
            b7_command.range(47,32) = b7_size_x;

            b0_command.range(63,48) = b0_avoid_x;
			b1_command.range(63,48) = b1_avoid_x;
			b2_command.range(63,48) = b2_avoid_x;
			b3_command.range(63,48) = b3_avoid_x;
			b4_command.range(63,48) = b4_avoid_x;
			b5_command.range(63,48) = b5_avoid_x;
			b6_command.range(63,48) = b6_avoid_x;
			b7_command.range(63,48) = b7_avoid_x;

            b0_command_strm << b0_command;
            b1_command_strm << b1_command;
            b2_command_strm << b2_command;
            b3_command_strm << b3_command;
            b4_command_strm << b4_command;
            b5_command_strm << b5_command;
            b6_command_strm << b6_command;
            b7_command_strm << b7_command;
	    }
	}
}

template <unsigned short MEM_DATA_WIDTH, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileMem2streamV2(ap_uint<MEM_DATA_WIDTH>* in, ::hls::stream<ap_uint<48>>& strm_command,
		::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_out, unsigned short size_y, unsigned short size_z)
{
	for (unsigned short z = 0; z < size_z; z++)
	{
		for (unsigned short y = 0; y < size_y; y++)
		{
//			#pragma HLS PIPELINE II = IN_ITR
			auto command = strm_command.read();
			unsigned int bank_offset = command.range(31,0);
			unsigned short size_x = command.range(47,32);
			#ifdef DEBUG_LOG
			    printf("|HLS DEBUG_LOG|%s| reading tile from mem to stream, bank_offset:%d, size_x:%d \n", __func__, bank_offset, size_x);
			#endif
			ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(in + bank_offset, strm_out, size_x);

		}
	}
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned char BANK_OFFSET, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileMem2stream(
        ap_uint<MEM_DATA_WIDTH>* arg_b0,
        ap_uint<MEM_DATA_WIDTH>* arg_b1,
        // ap_uint<mem_data_width>* arg_b2,
        // ap_uint<mem_data_width>* arg_b3,
        // ap_uint<mem_data_width>* arg_b4,
        // ap_uint<mem_data_width>* arg_b5,
        // ap_uint<mem_data_width>* arg_b6,
        // ap_uint<mem_data_width>* arg_b7,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_out,
        // ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_out,
        const ap_uint<160>& command )
{
    // #pragma HLS INLINE off
    #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| reading tile from mem to stream \n", __func__);
    #endif

    //static ::hls::stream<ap_uint<MEM_DATA_WIDTH>> strm_internal("strm_internal");
	//#pragma HLS STREAM variable = strm_internal depth = 64
//    constexpr unsigned short mem_data_width_elements = MEM_DATA_WIDTH << shift_bits;
//    constexpr unsigned short par_bank_read_offest = mem_data_width_elements * NUM_BANKS;
    unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    const ap_uint<3> bank_b0_offset = BANK_OFFSET;
    const ap_uint<3> bank_b1_offset = BANK_OFFSET + 1;
    

    size_t offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
//    unsigned short size_x_div_by_banks_ceil = (size_x + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
    ap_uint<3> size_x_mod_num_banks = size_x % NUM_BANKS;

    // unsigned short large_reads = size_x % NUM_BANKS;

    for (unsigned short z = 0; z < size_z; z++)
    {
        // #pragma HLS PIPELINE off


    for (unsigned short y = 0; y < size_y; y++)
    {
#pragma HLS LOOP_FLATTEN

    	size_t z_offset = offset_x + z * stride_z;
        size_t abs_offset = z_offset + y * stride_y;
        unsigned int bank_offset = abs_offset >> NUM_BANKS_SHIFT;
        ap_uint<3> starting_bank = abs_offset % NUM_BANKS; //starting bank
        unsigned int bank_offset_b0 = bank_b0_offset < starting_bank ? bank_offset + 1: bank_offset;
        unsigned int bank_offset_b1 = bank_b1_offset < starting_bank ? bank_offset + 1: bank_offset;
        ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_num_banks;
        bool is_t1_or_t2 = banks_upper_limit < starting_bank;
        bool is_b0_gt_sb = bank_b0_offset >= starting_bank;
        bool is_b1_gt_sb = bank_b1_offset >= starting_bank;
        bool b0_cond_t1 = is_b0_gt_sb || bank_b0_offset < banks_upper_limit;
        bool b1_cond_t1 = is_b1_gt_sb || bank_b1_offset < banks_upper_limit;
        bool b0_cond_t2 = is_b0_gt_sb && bank_b0_offset < banks_upper_limit;
        bool b1_cond_t2 = is_b1_gt_sb && bank_b1_offset < banks_upper_limit;
        bool b0_cond, b1_cond;
        if (is_t1_or_t2) {
            b0_cond = b0_cond_t1;
            b1_cond = b1_cond_t1;
        } else {
            b0_cond = b0_cond_t2;
            b1_cond = b1_cond_t2;
        }
		unsigned char add_arg_b0 = b0_cond ? 1 : 0;
		unsigned char add_arg_b1 = b1_cond ? 1 : 0;
		unsigned short b0_size_x = size_x_div_by_banks_floor + add_arg_b0;
		unsigned short b1_size_x = size_x_div_by_banks_floor + add_arg_b1;

    #ifdef DEBUG_LOG
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream| \n===============================\n");
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream| BANK_OFFSET: %d\n", int(BANK_OFFSET));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream| \n-------------------------------\n");
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    y: %d\n", y);
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    abs_offset: %d\n", int(abs_offset));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    bank_offset_b0: %d\n", int(bank_offset_b0));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    bank_offset_b1: %d\n", int(bank_offset_b1));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    starting_bank: %d\n", int(starting_bank));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    banks_upper_limit: %d\n", int(banks_upper_limit));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    add_arg_b0: %d\n", int(add_arg_b0));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    add_arg_b1: %d\n", int(add_arg_b1));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    common_size: %d\n", int(size_x_div_by_banks_floor));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    b0_size_x: %d\n", int(b0_size_x));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream|    b1_size_x: %d\n", int(b1_size_x));
        ops::hls::print("[KERNEL_DEBUG]|stridedTileMem2stream| ===============================\n");
    #endif

        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b0 + bank_offset_b0, strm0_out, b0_size_x);
        ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b1 + bank_offset_b1, strm1_out, b1_size_x);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b2 + bank_offset, strm2_out, size_x_div_by_banks_ceil);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b3 + bank_offset, strm3_out, size_x_div_by_banks_ceil);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b4 + bank_offset, strm4_out, size_x_div_by_banks_ceil);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b5 + bank_offset, strm5_out, size_x_div_by_banks_ceil);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b6 + bank_offset, strm6_out, size_x_div_by_banks_ceil);
        // ops::hls::mem2stream<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b7 + bank_offset, strm7_out, size_x_div_by_banks_ceil);
    }
    }
    // printf("[KERNEL_DEBUG]|%s|BANK_OFFSET_%d| Exit\n", __func__, BANK_OFFSET);
}    
    
template <unsigned short MEM_DATA_WIDTH, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileStream2memWithAvoidV2(::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_in, ap_uint<MEM_DATA_WIDTH>* out, ::hls::stream<ap_uint<64>>& strm_command
		, unsigned short size_y, unsigned short size_z)
{
	for (unsigned short z = 0; z < size_z; z++)
	{
		for (unsigned short y = 0; y < size_y; y++)
		{
//			#pragma HLS PIPELINE II = IN_ITR
			auto command = strm_command.read();
			unsigned int bank_offset = command.range(31,0);
			unsigned short size_x = command.range(47,32);
			unsigned short avoid_x = command.range(63, 48);
			#ifdef DEBUG_LOG
			    printf("|HLS DEBUG_LOG|%s| reading tile from mem to stream, bank_offset:%d, size_x:%d \n", __func__, bank_offset, size_x);
			#endif
			ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(out + bank_offset, strm_in, size_x, avoid_x);
		}
	}
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned char BANK_OFFSET, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void stridedTileStream2memWithAvoid(
        ap_uint<mem_data_width>* arg_b0,
        ap_uint<mem_data_width>* arg_b1,
        // ap_uint<mem_data_width>* arg_b2,
        // ap_uint<mem_data_width>* arg_b3,
        // ap_uint<mem_data_width>* arg_b4,
        // ap_uint<mem_data_width>* arg_b5,
        // ap_uint<mem_data_width>* arg_b6,
        // ap_uint<mem_data_width>* arg_b7,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_in,
		::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_in,
		 const ap_uint<192>& command)
{
    //     // #pragma HLS INLINE off
    #ifdef DEBUG_LOG
        printf("|HLS DEBUG_LOG|%s| writing tile from stream to mem \n", __func__);
    #endif
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    const ap_uint<3> bank_b0_offset = BANK_OFFSET;
    const ap_uint<3> bank_b1_offset = BANK_OFFSET + 1;

    ap_uint<64> offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
	ap_uint<16> avoid_x = command.range(175,160);
	ap_uint<16> avoid_y = command.range(191,176);
	unsigned short avoid_x_per_bank = avoid_x >> NUM_BANKS_SHIFT;
	ap_uint<3> avoid_x_mod_banks = avoid_x % NUM_BANKS;

	unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
	ap_uint<3> size_x_mod_banks = size_x % NUM_BANKS;

    for (unsigned short z = 0; z < size_z; z++)
    {
//        #pragma HLS PIPELINE off
//        unsigned short z_row_id_offset = abs_row_offset + z * z_row_stride;


        for (unsigned short y = 0; y < size_y; y++)
        {
		#pragma HLS LOOP_FLATTEN
        	size_t z_offset = offset_x + z * stride_z;
        	size_t abs_offset = z_offset + y * stride_y;
        	unsigned short bank_offset = abs_offset >> NUM_BANKS_SHIFT;
        	ap_uint<3> starting_bank = abs_offset % NUM_BANKS; //starting bank
            unsigned int bank_offset_b0 = bank_b0_offset < starting_bank ? bank_offset + 1: bank_offset;
            unsigned int bank_offset_b1 = bank_b1_offset < starting_bank ? bank_offset + 1: bank_offset;
            ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_banks;
            // Every bank > staring bank || every bank  < (size_x % NUM_BANK + starting_bank) % NUM_BANKS will have extra 1
            bool is_t1_or_t2 = banks_upper_limit < starting_bank;
            bool is_b0_gt_sb = bank_b0_offset >= starting_bank;
            bool is_b1_gt_sb = bank_b1_offset >= starting_bank;
            bool b0_cond_t1 = is_b0_gt_sb || bank_b0_offset < banks_upper_limit;
            bool b1_cond_t1 = is_b1_gt_sb || bank_b1_offset < banks_upper_limit;
            bool b0_cond_t2 = is_b0_gt_sb && bank_b0_offset < banks_upper_limit;
            bool b1_cond_t2 = is_b1_gt_sb && bank_b1_offset < banks_upper_limit;
            bool b0_cond, b1_cond;
            if (is_t1_or_t2) {
                b0_cond = b0_cond_t1;
                b1_cond = b1_cond_t1;
            } else {
                b0_cond = b0_cond_t2;
                b1_cond = b1_cond_t2;
            }
            unsigned char add_arg_b0 = b0_cond ? 1 : 0;
            unsigned char add_arg_b1 = b1_cond ? 1 : 0;
            unsigned short b0_size_x = size_x_div_by_banks_floor + add_arg_b0;
            unsigned short b1_size_x = size_x_div_by_banks_floor + add_arg_b1;

            ap_uint<3> avoid_x_bank_upper_limit = starting_bank + avoid_x_mod_banks;
            bool is_t1_or_t2_avoid_x = avoid_x_bank_upper_limit < starting_bank;
            bool b0_avoid_x_cond_t1 = is_b0_gt_sb || bank_b0_offset < avoid_x_bank_upper_limit;
            bool b1_avoid_x_cond_t1 = is_b1_gt_sb || bank_b1_offset < avoid_x_bank_upper_limit;
            bool b0_avoid_x_cond_t2 = is_b0_gt_sb && bank_b0_offset < avoid_x_bank_upper_limit;
            bool b1_avoid_x_cond_t2 = is_b1_gt_sb && bank_b1_offset < avoid_x_bank_upper_limit;
            bool b0_avoid_x_cond, b1_avoid_x_cond;
            if (is_t1_or_t2_avoid_x) {
                b0_avoid_x_cond = b0_avoid_x_cond_t1;
                b1_avoid_x_cond = b1_avoid_x_cond_t1;
            } else {
                b0_avoid_x_cond = b0_avoid_x_cond_t2;
                b1_avoid_x_cond = b1_avoid_x_cond_t2;
            }
			unsigned char add_avoid_x_arg_b0 = b0_avoid_x_cond ? 1 : 0;
			unsigned char add_avoid_x_arg_b1 = b1_avoid_x_cond ? 1 : 0;
			unsigned char adj_b0_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b0;
			unsigned char adj_b1_avoid_x = avoid_x_per_bank + add_avoid_x_arg_b1;
			unsigned short b0_avoid_x = y < avoid_y ? b0_size_x : adj_b0_avoid_x;
			unsigned short b1_avoid_x = y < avoid_y ? b1_size_x : adj_b1_avoid_x;
            b0_avoid_x = b0_avoid_x > b0_size_x ? b0_size_x : b0_avoid_x;
            b1_avoid_x = b1_avoid_x > b1_size_x ? b1_size_x : b1_avoid_x;

        // #ifdef DEBUG_LOG
            // ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid| \n===============================\n");
            if (BANK_OFFSET == 0) {
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid| BANK_OFFSET: %d\n", BANK_OFFSET);
            // ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid| \n-------------------------------\n");
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    y: %d\n", y);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    abs_offset: %d\n", abs_offset);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    bank_offset: %d\n", bank_offset);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    bank_offset_b0: %d\n", bank_offset_b0);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    bank_offset_b1: %d\n", bank_offset_b1);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    starting_bank: %d\n", uint(starting_bank));
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    banks_upper_limit: %d\n", uint(banks_upper_limit));
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    add_arg_b0: %d\n", add_arg_b0);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    add_arg_b1: %d\n", add_arg_b1);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    common_size: %d\n", size_x_div_by_banks_floor);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    b0_size_x: %d\n", b0_size_x);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    b1_size_x: %d\n", b1_size_x);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    avoid_x_bank_upper_limit: %d\n", uint(avoid_x_bank_upper_limit));
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    add_avoid_x_arg_b0: %d\n", add_avoid_x_arg_b0);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    add_avoid_x_arg_b1: %d\n", add_avoid_x_arg_b1);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    adj_b0_avoid_x: %d\n", adj_b0_avoid_x);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    adj_b1_avoid_x: %d\n", adj_b1_avoid_x);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    avoid_x_common: %d\n", avoid_x_per_bank);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    b0_avoid_x: %d\n", b0_avoid_x);
            ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid|    b1_avoid_x: %d\n\n", b1_avoid_x);
            }
            // ops::hls::print("[KERNEL_DEBUG]|stridedTileStream2memWithAvoid| ===============================\n");
        // #endif
			ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b0 + bank_offset_b0, strm0_in, b0_size_x, b0_avoid_x);
			ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b1 + bank_offset_b1, strm1_in, b1_size_x, b1_avoid_x);
            // ap_uint<64> s2 = s3 + y * stride_y;
//            unsigned short abs_row_id_of_y = y + z_row_id_offset;
//            unsigned short bank_id = abs_row_id_of_y % NUM_BANKS;
            // unsigned short j_shifted = abs_row_id_of_y >> NUM_BANKS_SHIFT;
            // unsigned short j_floor = j_shifted << NUM_BANKS_SHIFT;
            // bool access_cond = j_floor + bank_id < size_y;
//            ap_uint<64> per_bank_row = (ap_uint<64>)(abs_row_id_of_y >> NUM_BANKS_SHIFT);
//            ap_uint<64> s2 = offset_x + per_bank_row * stride_y;
//            #ifdef DEBUG_LOG
//                printf("|HLS DEBUG_LOG|%s| z:%u y:%u offset:%llu, size_x:%u, stride_y:%u, size_y:%u, stride_z:%u, size_z:%u avoid_x:%u avoid_y:%u\n",
//                       __func__, (unsigned int)z, (unsigned int)y, (unsigned long long)s2, (unsigned int)size_x, (unsigned int)stride_y, (unsigned int)size_y,
//                       (unsigned int)stride_z, (unsigned int)size_z, (unsigned int)avoid_x, (unsigned int)avoid_y);
//            #endif
//			if (y < avoid_y)
//				ops::hls::hlsTerminate<MEM_DATA_WIDTH, IN_ITR>(strm_in, size_x);
//            else if (bank_id == 0)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b0 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 1)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b1 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 2)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b2 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 3)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b3 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 4)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b4 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 5)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b5 + s2, strm_in, size_x, avoid_x);
//            else if (bank_id == 6)
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b6 + s2, strm_in, size_x, avoid_x);
//            else
//                ops::hls::stream2memWithAvoid<MEM_DATA_WIDTH, BURST_SIZE, IN_ITR>(arg_b7 + s2, strm_in, size_x, avoid_x);
        }
    }
    // printf("[KERNEL_DEBUG]|%s|BANK_OFFSET_%d| Exit\n", __func__, BANK_OFFSET);
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void redirect(
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_in, 
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_out, 
        const ap_uint<160>& command)
{
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    size_t offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
    unsigned short size_x_div_by_banks_ceil = (size_x + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
    // unsigned short large_reads = size_x % NUM_BANKS;
    ap_uint<3> size_x_mod_banks = size_x % NUM_BANKS;

    for (unsigned short z = 0; z < size_z; z++)
    {

    for (unsigned short y = 0; y < size_y; y++)
    {
		#pragma HLS LOOP_FLATTEN

        const size_t z_offset = offset_x + z * stride_z;
        const size_t abs_offset = z_offset + y * stride_y;
        const unsigned short bank_offset = abs_offset >> NUM_BANKS_SHIFT;
		const ap_uint<3> starting_bank = abs_offset % NUM_BANKS;
        const ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_banks;
        const bool is_t1_or_t2 = banks_upper_limit < starting_bank;

		const bool is_b0_gt_sb = ap_uint<3>(0) >= starting_bank;
		const bool is_b1_gt_sb = ap_uint<3>(1) >= starting_bank;
		const bool is_b2_gt_sb = ap_uint<3>(2) >= starting_bank;
		const bool is_b3_gt_sb = ap_uint<3>(3) >= starting_bank;
		const bool is_b4_gt_sb = ap_uint<3>(4) >= starting_bank;
		const bool is_b5_gt_sb = ap_uint<3>(5) >= starting_bank;
		const bool is_b6_gt_sb = ap_uint<3>(6) >= starting_bank;
		const bool is_b7_gt_sb = ap_uint<3>(7) >= starting_bank;

		const bool is_b0_lt_uplim = ap_uint<3>(0) < banks_upper_limit;
        const bool is_b1_lt_uplim = ap_uint<3>(1) < banks_upper_limit;
        const bool is_b2_lt_uplim = ap_uint<3>(2) < banks_upper_limit;
        const bool is_b3_lt_uplim = ap_uint<3>(3) < banks_upper_limit;
        const bool is_b4_lt_uplim = ap_uint<3>(4) < banks_upper_limit;
        const bool is_b5_lt_uplim = ap_uint<3>(5) < banks_upper_limit;
        const bool is_b6_lt_uplim = ap_uint<3>(6) < banks_upper_limit;
        const bool is_b7_lt_uplim = ap_uint<3>(7) < banks_upper_limit;

		bool b0_cond, b1_cond, b2_cond, b3_cond, b4_cond, b5_cond, b6_cond, b7_cond;

		if (is_t1_or_t2) {
			b0_cond = is_b0_gt_sb || is_b0_lt_uplim;
			b1_cond = is_b1_gt_sb || is_b1_lt_uplim;
			b2_cond = is_b2_gt_sb || is_b2_lt_uplim;
			b3_cond = is_b3_gt_sb || is_b3_lt_uplim;
			b4_cond = is_b4_gt_sb || is_b4_lt_uplim;
			b5_cond = is_b5_gt_sb || is_b5_lt_uplim;
			b6_cond = is_b6_gt_sb || is_b6_lt_uplim;
			b7_cond = is_b7_gt_sb || is_b7_lt_uplim;
		} else {
			b0_cond = is_b0_gt_sb && is_b0_lt_uplim;
			b1_cond = is_b1_gt_sb && is_b1_lt_uplim;
			b2_cond = is_b2_gt_sb && is_b2_lt_uplim;
			b3_cond = is_b3_gt_sb && is_b3_lt_uplim;
			b4_cond = is_b4_gt_sb && is_b4_lt_uplim;
			b5_cond = is_b5_gt_sb && is_b5_lt_uplim;
			b6_cond = is_b6_gt_sb && is_b6_lt_uplim;
			b7_cond = is_b7_gt_sb && is_b7_lt_uplim;
		}

        for (unsigned short x = 0; x < size_x_div_by_banks_ceil; x++)
        {
            #pragma HLS PIPELINE II=IN_ITR

            ap_uint<mem_data_width> swap0, swap1, swap2, swap3, swap4, swap5, swap6, swap7;
            ap_uint<mem_data_width> tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;

            const bool is_x_lt_bank_x_size = x < size_x_div_by_banks_floor;
            const bool b0_read_cond = is_x_lt_bank_x_size || b0_cond;
            const bool b1_read_cond = is_x_lt_bank_x_size || b1_cond;
            const bool b2_read_cond = is_x_lt_bank_x_size || b2_cond;
            const bool b3_read_cond = is_x_lt_bank_x_size || b3_cond;
            const bool b4_read_cond = is_x_lt_bank_x_size || b4_cond;
            const bool b5_read_cond = is_x_lt_bank_x_size || b5_cond;
            const bool b6_read_cond = is_x_lt_bank_x_size || b6_cond;
            const bool b7_read_cond = is_x_lt_bank_x_size || b7_cond;

            tmp0 = b0_read_cond ? register_it(strm0_in.read()) : ap_uint<mem_data_width>(0);
            tmp1 = b1_read_cond ? register_it(strm1_in.read()) : ap_uint<mem_data_width>(0);
            tmp2 = b2_read_cond ? register_it(strm2_in.read()) : ap_uint<mem_data_width>(0);
            tmp3 = b3_read_cond ? register_it(strm3_in.read()) : ap_uint<mem_data_width>(0);
            tmp4 = b4_read_cond ? register_it(strm4_in.read()) : ap_uint<mem_data_width>(0);
            tmp5 = b5_read_cond ? register_it(strm5_in.read()) : ap_uint<mem_data_width>(0);
            tmp6 = b6_read_cond ? register_it(strm6_in.read()) : ap_uint<mem_data_width>(0);
            tmp7 = b7_read_cond ? register_it(strm7_in.read()) : ap_uint<mem_data_width>(0);

            switch (starting_bank)
            {
                case 0: swap0 = tmp0; swap1 = tmp1; swap2 = tmp2; swap3 = tmp3; swap4 = tmp4; swap5 = tmp5; swap6 = tmp6; swap7 = tmp7; break;
                case 1: swap0 = tmp1; swap1 = tmp2; swap2 = tmp3; swap3 = tmp4; swap4 = tmp5; swap5 = tmp6; swap6 = tmp7; swap7 = tmp0; break;
                case 2: swap0 = tmp2; swap1 = tmp3; swap2 = tmp4; swap3 = tmp5; swap4 = tmp6; swap5 = tmp7; swap6 = tmp0; swap7 = tmp1; break;
                case 3: swap0 = tmp3; swap1 = tmp4; swap2 = tmp5; swap3 = tmp6; swap4 = tmp7; swap5 = tmp0; swap6 = tmp1; swap7 = tmp2; break;
                case 4: swap0 = tmp4; swap1 = tmp5; swap2 = tmp6; swap3 = tmp7; swap4 = tmp0; swap5 = tmp1; swap6 = tmp2; swap7 = tmp3; break;
                case 5: swap0 = tmp5; swap1 = tmp6; swap2 = tmp7; swap3 = tmp0; swap4 = tmp1; swap5 = tmp2; swap6 = tmp3; swap7 = tmp4; break;
                case 6: swap0 = tmp6; swap1 = tmp7; swap2 = tmp0; swap3 = tmp1; swap4 = tmp2; swap5 = tmp3; swap6 = tmp4; swap7 = tmp5; break;
                case 7: swap0 = tmp7; swap1 = tmp0; swap2 = tmp1; swap3 = tmp2; swap4 = tmp3; swap5 = tmp4; swap6 = tmp5; swap7 = tmp6; break;
            }

            // ops::hls::print("[KERNEL_DEBUG]|redirect| \n===============================\n");

            strm0_out << swap0;
            strm1_out << swap1;
            strm2_out << swap2;
            strm3_out << swap3;
            strm4_out << swap4;
            strm5_out << swap5;
            strm6_out << swap6;
            strm7_out << swap7;
        }
    }
    }
    // printf("[KERNEL_DEBUG]|%s| Exit\n", __func__);
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void reverseRedirect(
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_out,
        const ap_uint<160>& command)
{
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    size_t offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
    unsigned short size_x_div_by_banks_ceil = (size_x + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    unsigned short size_x_div_by_banks_floor = size_x >> NUM_BANKS_SHIFT;
    ap_uint<3> size_x_mod_banks = size_x % NUM_BANKS;

    for (unsigned short z = 0; z < size_z; z++)
    {

    for (unsigned short y = 0; y < size_y; y++)
    {
#pragma HLS LOOP_FLATTEN
    	const size_t z_offset = offset_x + z * stride_z;
        const size_t abs_offset = z_offset + y * stride_y;
        const unsigned short bank_offset = abs_offset >> NUM_BANKS_SHIFT;
		const ap_uint<3> starting_bank = abs_offset % NUM_BANKS;
        const ap_uint<3> banks_upper_limit = starting_bank + size_x_mod_banks;
        const bool is_t1_or_t2 = banks_upper_limit < starting_bank;

		const bool is_b0_gt_sb = ap_uint<3>(0) >= starting_bank;
		const bool is_b1_gt_sb = ap_uint<3>(1) >= starting_bank;
		const bool is_b2_gt_sb = ap_uint<3>(2) >= starting_bank;
		const bool is_b3_gt_sb = ap_uint<3>(3) >= starting_bank;
		const bool is_b4_gt_sb = ap_uint<3>(4) >= starting_bank;
		const bool is_b5_gt_sb = ap_uint<3>(5) >= starting_bank;
		const bool is_b6_gt_sb = ap_uint<3>(6) >= starting_bank;
		const bool is_b7_gt_sb = ap_uint<3>(7) >= starting_bank;

		const bool is_b0_lt_uplim = ap_uint<3>(0) < banks_upper_limit;
        const bool is_b1_lt_uplim = ap_uint<3>(1) < banks_upper_limit;
        const bool is_b2_lt_uplim = ap_uint<3>(2) < banks_upper_limit;
        const bool is_b3_lt_uplim = ap_uint<3>(3) < banks_upper_limit;
        const bool is_b4_lt_uplim = ap_uint<3>(4) < banks_upper_limit;
        const bool is_b5_lt_uplim = ap_uint<3>(5) < banks_upper_limit;
        const bool is_b6_lt_uplim = ap_uint<3>(6) < banks_upper_limit;
        const bool is_b7_lt_uplim = ap_uint<3>(7) < banks_upper_limit;

		bool b0_cond, b1_cond, b2_cond, b3_cond, b4_cond, b5_cond, b6_cond, b7_cond;

		if (is_t1_or_t2) {
			b0_cond = is_b0_gt_sb || is_b0_lt_uplim;
			b1_cond = is_b1_gt_sb || is_b1_lt_uplim;
			b2_cond = is_b2_gt_sb || is_b2_lt_uplim;
			b3_cond = is_b3_gt_sb || is_b3_lt_uplim;
			b4_cond = is_b4_gt_sb || is_b4_lt_uplim;
			b5_cond = is_b5_gt_sb || is_b5_lt_uplim;
			b6_cond = is_b6_gt_sb || is_b6_lt_uplim;
			b7_cond = is_b7_gt_sb || is_b7_lt_uplim;
		} else {
			b0_cond = is_b0_gt_sb && is_b0_lt_uplim;
			b1_cond = is_b1_gt_sb && is_b1_lt_uplim;
			b2_cond = is_b2_gt_sb && is_b2_lt_uplim;
			b3_cond = is_b3_gt_sb && is_b3_lt_uplim;
			b4_cond = is_b4_gt_sb && is_b4_lt_uplim;
			b5_cond = is_b5_gt_sb && is_b5_lt_uplim;
			b6_cond = is_b6_gt_sb && is_b6_lt_uplim;
			b7_cond = is_b7_gt_sb && is_b7_lt_uplim;
		}
		// unsigned char add_arg_b0_diff = 0 - offset_x_mod_banks;
		// unsigned char add_arg_b1_diff = 1 - offset_x_mod_banks;
		// unsigned char add_arg_b2_diff = 2 - offset_x_mod_banks;
		// unsigned char add_arg_b3_diff = 3 - offset_x_mod_banks;
		// unsigned char add_arg_b4_diff = 4 - offset_x_mod_banks;
		// unsigned char add_arg_b5_diff = 5 - offset_x_mod_banks;
		// unsigned char add_arg_b6_diff = 6 - offset_x_mod_banks;
		// unsigned char add_arg_b7_diff = 7 - offset_x_mod_banks;

		// bool is_arg_b0 = add_arg_b0_diff < size_x_mod_banks;
		// bool is_arg_b1 = add_arg_b1_diff < size_x_mod_banks;
		// bool is_arg_b2 = add_arg_b2_diff < size_x_mod_banks;
		// bool is_arg_b3 = add_arg_b3_diff < size_x_mod_banks;
		// bool is_arg_b4 = add_arg_b4_diff < size_x_mod_banks;
		// bool is_arg_b5 = add_arg_b5_diff < size_x_mod_banks;
		// bool is_arg_b6 = add_arg_b6_diff < size_x_mod_banks;
		// bool is_arg_b7 = add_arg_b7_diff < size_x_mod_banks;
		//ops::hls::print("[KERNEL_DEBUG]| reverseRedirect |  starting_bank: %d\n", uint(starting_bank));

        for (unsigned short x = 0; x < size_x_div_by_banks_ceil; x++)
        {
            #pragma HLS PIPELINE II=IN_ITR

            ap_uint<mem_data_width> swap0;
            ap_uint<mem_data_width> swap1;
            ap_uint<mem_data_width> swap2;
            ap_uint<mem_data_width> swap3;
            ap_uint<mem_data_width> swap4;
            ap_uint<mem_data_width> swap5;
            ap_uint<mem_data_width> swap6;
            ap_uint<mem_data_width> swap7;

            auto tmp0 = register_it(strm0_in.read());
            auto tmp1 = register_it(strm1_in.read());
            auto tmp2 = register_it(strm2_in.read());
            auto tmp3 = register_it(strm3_in.read());
            auto tmp4 = register_it(strm4_in.read());
            auto tmp5 = register_it(strm5_in.read());
            auto tmp6 = register_it(strm6_in.read());
            auto tmp7 = register_it(strm7_in.read());

            const bool is_x_lt_bank_x_size = x < size_x_div_by_banks_floor;
            const bool b0_write_cond = is_x_lt_bank_x_size || b0_cond;
            const bool b1_write_cond = is_x_lt_bank_x_size || b1_cond;
            const bool b2_write_cond = is_x_lt_bank_x_size || b2_cond;
            const bool b3_write_cond = is_x_lt_bank_x_size || b3_cond;
            const bool b4_write_cond = is_x_lt_bank_x_size || b4_cond;
            const bool b5_write_cond = is_x_lt_bank_x_size || b5_cond;
            const bool b6_write_cond = is_x_lt_bank_x_size || b6_cond;
            const bool b7_write_cond = is_x_lt_bank_x_size || b7_cond;
//            ops::hls::DataConv conv;
//            conv.i = tmp0.range(31, 0);
//			ops::hls::print("[KERNEL_DEBUG]| reverseRedirect | tmp0:1   %f,\n", conv.f);
//			conv.i = tmp0.range(319, 288);
//			ops::hls::print("[KERNEL_DEBUG]| reverseRedirect | tmp0:10   %f,\n", conv.f);

            switch (starting_bank)
            {
                case 0: swap0 = tmp0; swap1 = tmp1; swap2 = tmp2; swap3 = tmp3; swap4 = tmp4; swap5 = tmp5; swap6 = tmp6; swap7 = tmp7; break;
                case 1: swap1 = tmp0; swap2 = tmp1; swap3 = tmp2; swap4 = tmp3; swap5 = tmp4; swap6 = tmp5; swap7 = tmp6; swap0 = tmp7; break;
                case 2: swap2 = tmp0; swap3 = tmp1; swap4 = tmp2; swap5 = tmp3; swap6 = tmp4; swap7 = tmp5; swap0 = tmp6; swap1 = tmp7; break;
                case 3: swap3 = tmp0; swap4 = tmp1; swap5 = tmp2; swap6 = tmp3; swap7 = tmp4; swap0 = tmp5; swap1 = tmp6; swap2 = tmp7; break;
                case 4: swap4 = tmp0; swap5 = tmp1; swap6 = tmp2; swap7 = tmp3; swap0 = tmp4; swap1 = tmp5; swap2 = tmp6; swap3 = tmp7; break;
                case 5: swap5 = tmp0; swap6 = tmp1; swap7 = tmp2; swap0 = tmp3; swap1 = tmp4; swap2 = tmp5; swap3 = tmp6; swap4 = tmp7; break;
                case 6: swap6 = tmp0; swap7 = tmp1; swap0 = tmp2; swap1 = tmp3; swap2 = tmp4; swap3 = tmp5; swap4 = tmp6; swap5 = tmp7; break;
                case 7: swap7 = tmp0; swap0 = tmp1; swap1 = tmp2; swap2 = tmp3; swap3 = tmp4; swap4 = tmp5; swap5 = tmp6; swap6 = tmp7; break;
            }

            if (b0_write_cond){
//            	conv.i = swap0.range(31, 0);
//            	ops::hls::print("[KERNEL_DEBUG]| reverseRedirect | swap0:1   %f,\n", conv.f);
//            	conv.i = swap0.range(319, 288);
//				ops::hls::print("[KERNEL_DEBUG]| reverseRedirect | swap0:10   %f,\n", conv.f);
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 0);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap0.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
            	strm0_out << swap0;
            }
            if (b1_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 1);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap1.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
            	strm1_out << swap1;
            }
            if (b2_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 2);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap2.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
            	strm2_out << swap2;
            }
			if (b3_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 3);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap3.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
				strm3_out << swap3;
			}
			if (b4_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 4);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap4.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
				strm4_out << swap4;
			}
			if (b5_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 5);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap5.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
				strm5_out << swap5;
			}
			if (b6_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 6);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap6.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
				strm6_out << swap6;
			}
			if (b7_write_cond){
    #ifdef DEBUG_LOG
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| reverseRedirect | reading  x: %d, bank_id:%d val=(",  x, 7);
            
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = swap7.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, \n", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
				strm7_out << swap7;
			}
        }
    }
    }
    // printf("[KERNEL_DEBUG]|%s| Exit\n", __func__);
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void combine(
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_in, 
        ::hls::stream<ap_uint<MEM_DATA_WIDTH*2>>& strm_widen_l_out,
		::hls::stream<ap_uint<MEM_DATA_WIDTH*2>>& strm_widen_h_out,
        const ap_uint<160>& command)
{
    constexpr unsigned short ii = IN_ITR >> 1;
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    ap_uint<64> offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    // unsigned short size_y_div_num_banks_ceil = (size_y + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
    unsigned short size_x_div_by_banks_ceil = (size_x + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    unsigned short size_x_div_by_banks_ceil_pkts = size_x_div_by_banks_ceil << 1;

    for (unsigned short z = 0; z < size_z; z++)
    {
    for (unsigned short y = 0; y < size_y; y++)
    {
        #pragma HLS LOOP_FLATTEN
        size_t z_offset = offset_x + z * stride_z;
        size_t abs_offset = z_offset + y * stride_y;
        unsigned short bank_offset = abs_offset >> NUM_BANKS_SHIFT;
        unsigned short starting_bank = abs_offset % NUM_BANKS;


        for (unsigned short x = 0; x < size_x_div_by_banks_ceil_pkts; x++)
        {
            #pragma HLS PIPELINE II=ii
            ap_uint<mem_data_width*2> l_l_comb;
            ap_uint<mem_data_width*2> l_u_comb;
            ap_uint<mem_data_width*2> u_l_comb;
            ap_uint<mem_data_width*2> u_u_comb;

            write_l: if (x % 2 == 0 ) {
                l_l_comb.range(511,0) = register_it(strm0_in.read());
                l_l_comb.range(1023,512) = register_it(strm1_in.read());
                l_u_comb.range(511,0) = register_it(strm2_in.read());
                l_u_comb.range(1023,512) = register_it(strm3_in.read());
                u_l_comb.range(511,0) = register_it(strm4_in.read());
                u_l_comb.range(1023,512) = register_it(strm5_in.read());
                u_u_comb.range(511,0) = register_it(strm6_in.read());
                u_u_comb.range(1023,512) = register_it(strm7_in.read());

//                ops::hls::DataConv tmp;
                // tmp.i = l_comb.range(31,0);
                // ops::hls::print("   |HLS DEBUG_LOG|combine| x val=%d\n", x);
                // ops::hls::print("   |HLS DEBUG_LOG|combine| read l_comb val=(%f\n", tmp.f);
                // for (unsigned n = 0; n < 16; n++)
                // {
                //     // #pragma HLS UNROLL
                //     ops::hls::DataConv tmp;
                //     tmp.i = l_comb.range(n * 32 + 32 - 1, n * 32);
                //     ops::hls::print("     %f,\n", tmp.f);
                // }
                // ops::hls::print(")\n");
//                printf("   |HLS DEBUG_LOG||%s| read h_comb val=(\n", __func__);
//                for (unsigned n = 0; n < 64; n++)
//                {
//                    // #pragma HLS UNROLL
//                    ops::hls::DataConv tmp;
//                    tmp.i = h_comb.range(n * 32 + 32 - 1, n * 32);
//                    printf("%f,\n", tmp.f);
//                }
//                printf(")\n");
                strm_widen_l_out << l_l_comb;
                strm_widen_h_out << l_u_comb;
            }                
            else {
            	strm_widen_l_out << u_l_comb;
            	strm_widen_h_out << u_u_comb;
            }
        }
    }
    }
    // printf("[KERNEL_DEBUG]|%s| Exit\n", __func__);
}

template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
static void split(
        ::hls::stream<ap_uint<MEM_DATA_WIDTH*2>>& strm_widen_l_in,
		::hls::stream<ap_uint<MEM_DATA_WIDTH*2>>& strm_widen_u_in,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm0_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm1_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm2_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm3_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm4_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm5_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm6_out,
        ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm7_out, 
        const ap_uint<160>& command)
{
    constexpr unsigned short ii = IN_ITR >> 1;
    const unsigned short NUM_BANKS_SHIFT = LOG2(NUM_BANKS);

    ap_uint<64> offset_x = command.range(63,0);
    ap_uint<16> size_x = command.range(95,80);
    ap_uint<16> stride_y = command.range(111,96);
    ap_uint<16> size_y = command.range(127,112);
    // unsigned short size_y_div_num_banks_ceil = (size_y + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    ap_uint<16> stride_z = command.range(143,128);
    ap_uint<16> size_z = command.range(159,144);
    unsigned short size_x_div_by_banks_ceil = (size_x + NUM_BANKS - 1) >> NUM_BANKS_SHIFT;
    unsigned short size_x_div_by_banks_ceil_pkts = size_x_div_by_banks_ceil << 1;

    for (unsigned short z = 0; z < size_z; z++)
    {

    for (unsigned short y = 0; y < size_y; y++)
    {
        #pragma HLS LOOP_FLATTEN
        size_t z_offset = offset_x + z * stride_z;
        size_t abs_offset = z_offset + y * stride_y;
        unsigned short bank_offset = abs_offset >> NUM_BANKS_SHIFT;
        unsigned short starting_bank = abs_offset % NUM_BANKS;

        for (unsigned short x = 0; x < size_x_div_by_banks_ceil_pkts; x++)
        {
            #pragma HLS PIPELINE II=ii
        	unsigned short reged_x = register_it(x);
        	ap_uint<mem_data_width*2> l_l_comb;
        	ap_uint<mem_data_width*2> l_u_comb;
			ap_uint<mem_data_width*2> u_l_comb;
			ap_uint<mem_data_width*2> u_u_comb;
			ap_uint<mem_data_width*2> in_l_data;
			ap_uint<mem_data_width*2> in_u_data;

			ops::hls::DataConv conv;
			in_l_data = register_it<ap_uint<MEM_DATA_WIDTH*2>>(strm_widen_l_in.read());
			in_u_data = register_it<ap_uint<MEM_DATA_WIDTH*2>>(strm_widen_u_in.read());
			// ops::hls::print("[KERNEL_DEBUG]| split | x  %d,\n", x);
			// ops::hls::print("[KERNEL_DEBUG]| split | y  %d,\n", y);
			// ops::hls::print("[KERNEL_DEBUG]| split | z  %d,\n", z);
//        	conv.i = in_l_data.range(31, 0);
//        	ops::hls::print("[KERNEL_DEBUG]| split | in_data:0   %f,\n", conv.f);
//			conv.i = in_l_data.range(319, 288);
//			ops::hls::print("[KERNEL_DEBUG]| split | in_data:9   %f,\n", conv.f);

            if (reged_x % 2 == 0) {
            	l_l_comb = in_l_data;
            	l_u_comb = in_u_data;
    #ifdef DEBUG_LOG
                ap_uint<MEM_DATA_WIDTH> tmp = l_l_comb.range(511,0);
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| split | reading  x: %d, bank_id:0-3\n   bank0=(",  reged_x);
            
                
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");
                
                tmp = l_l_comb.range(1023,512);
                printf("   bank1=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");

                tmp = l_u_comb.range(511,0);
                printf("   bank2=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");

                tmp = l_u_comb.range(1023,512);
                printf("   bank3=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
            	strm0_out << l_l_comb.range(511,0);
				strm1_out << l_l_comb.range(1023,512);
				strm2_out << l_u_comb.range(511,0);
				strm3_out << l_u_comb.range(1023,512);
//				conv.i = l_l_comb.range(31, 0);
//				ops::hls::print("[KERNEL_DEBUG]| split | l_l_comb:0   %f,\n", conv.f);
//				conv.i = l_l_comb.range(319, 288);
//				ops::hls::print("[KERNEL_DEBUG]| split | l_l_comb:9   %f,\n", conv.f);
            }
            else {
            	u_l_comb = in_l_data;
            	u_u_comb = in_u_data;
    #ifdef DEBUG_LOG
                ap_uint<MEM_DATA_WIDTH> tmp = u_l_comb.range(511,0);
                printf("====================================================================================\n");
                printf("|HLS DEBUG_LOG| split | reading  x: %d, bank_id:0-3\n   bank4=(",  reged_x);
            
                
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");
                
                tmp = u_l_comb.range(1023,512);
                printf("   bank5=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");

                tmp = u_u_comb.range(511,0);
                printf("   bank6=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");

                tmp = u_u_comb.range(1023,512);
                printf("   bank7=(");
                for (unsigned k = 0; k < MEM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
                {
                    ops::hls::DataConv conv;
                    conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
                    printf("%f, ", conv.f);
                }
                printf(")\n");
                printf("====================================================================================\n");
    #endif
            	strm4_out << u_l_comb.range(511,0);
				strm5_out << u_l_comb.range(1023,512);
				strm6_out << u_u_comb.range(511,0);
				strm7_out << u_u_comb.range(1023,512);
//				conv.i = u_l_comb.range(31, 0);
//				ops::hls::print("[KERNEL_DEBUG]| split | u_l_comb:0   %f,\n", conv.f);
//				conv.i = u_l_comb.range(319, 288);
//				ops::hls::print("[KERNEL_DEBUG]| split | u_l_comb:9   %f,\n", conv.f);
            }
        }
    }
    }
    // printf("[KERNEL_DEBUG]|%s| Exit\n", __func__);
}

//template <unsigned short IN_STREAM_DATA_WIDTH, unsigned short OUT_STREAM_DATA_WIDTH>
//static void streamSplit2(::hls::stream<ap_uint<IN_STREAM_DATA_WIDTH>>& strm_in,
//        ::hls::stream<ap_uint<OUT_STREAM_DATA_WIDTH>>& strm_l_out, ::hls::stream<ap_uint<OUT_STREAM_DATA_WIDTH>>& strm_h_out, unsigned int num_pkts)
//{
//    constexpr unsigned short out_strm_data_width_min_1 = OUT_STREAM_DATA_WIDTH - 1;
//    constexpr unsigned short out_strm_data_width = OUT_STREAM_DATA_WIDTH;
//    constexpr unsigned short in_strm_data_width_min_1 = IN_STREAM_DATA_WIDTH - 1;
//
//    #ifdef DEBUG_LOG
//    ops::hls::print("====================================================================================\n");
//    ops::hls::print("|HLS DEBUG_LOG| streamSplit2 | starting. pkts %d \n", num_pkts);
//    ops::hls::print("====================================================================================\n");
//    #endif
//    for (unsigned int i = 0; i < num_pkts; i++)
//    {
//        #pragma HLS PIPELINE II=1
//        ap_uint<IN_STREAM_DATA_WIDTH> tmp = register_it<ap_uint<IN_STREAM_DATA_WIDTH>>(strm_in.read());
//    #ifdef DEBUG_LOG
//        ops::hls::print("====================================================================================\n");
//        ops::hls::print("|HLS DEBUG_LOG| streamSplit2 | reading index: %d, val=(\n", i);
//
//        for (unsigned k = 0; k < IN_STREAM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
//        {
//            ops::hls::DataConv conv;
//            conv.i = tmp.range((k+1) * sizeof(stencil_type) * 8 - 1, k * sizeof(stencil_type) * 8);
//            ops::hls::print("		%f,\n", conv.f);
//        }
//        ops::hls::print(")\n");
//		ops::hls::print("====================================================================================\n");
//    #endif
//        strm_l_out << tmp.range(out_strm_data_width_min_1, 0);
//        strm_h_out << tmp.range(in_strm_data_width_min_1, out_strm_data_width);
//    }
//}
//
//
//template <unsigned short IN_STREAM_DATA_WIDTH, unsigned short OUT_STREAM_DATA_WIDTH>
//static void streamCombine2(::hls::stream<ap_uint<IN_STREAM_DATA_WIDTH>>& strm_l_in, ::hls::stream<ap_uint<IN_STREAM_DATA_WIDTH>>& strm_h_in,
//        ::hls::stream<ap_uint<OUT_STREAM_DATA_WIDTH>>& strm_out, unsigned int num_pkts)
//{
//    constexpr unsigned short out_strm_data_width_min_1 = OUT_STREAM_DATA_WIDTH - 1;
//    constexpr unsigned short in_strm_data_width = IN_STREAM_DATA_WIDTH;
//    constexpr unsigned short in_strm_data_width_min_1 = IN_STREAM_DATA_WIDTH - 1;
//    for (unsigned int i = 0; i < num_pkts; i++)
//    {
//        #pragma HLS PIPELINE II=1
//
//        ap_uint<OUT_STREAM_DATA_WIDTH> tmp;
//        tmp.range(in_strm_data_width_min_1, 0) = register_it<ap_uint<IN_STREAM_DATA_WIDTH>>(strm_l_in.read());
//        tmp.range(out_strm_data_width_min_1, in_strm_data_width) = register_it<ap_uint<IN_STREAM_DATA_WIDTH>>(strm_h_in.read());
////        ops::hls::DataConv conv;
////		conv.i = tmp.range(31, 0);
////		ops::hls::print("[KERNEL_DEBUG]| streamCombine2 | tmp:1   %f,\n", conv.f);
////		conv.i = tmp.range(63, 32);
////		ops::hls::print("[KERNEL_DEBUG]| streamCombine2 | tmp:10   %f,\n", conv.f);
////		conv.i = tmp.range(319, 288);
////		ops::hls::print("[KERNEL_DEBUG]| streamCombine2 | tmp:10   %f,\n", conv.f);
////		conv.i = tmp.range(351, 320);
////		ops::hls::print("[KERNEL_DEBUG]| streamCombine2 | tmp:11   %f,\n", conv.f);
//        #ifdef DEBUG_LOG
//        // ops::hls::print("====================================================================================\n");
//        ops::hls::print("|HLS DEBUG_LOG| streamCombine2 | combined val index: %d, val=(\n", i);
//        for (unsigned k = 0; k < OUT_STREAM_DATA_WIDTH/(sizeof(stencil_type) * 8); k++)
//        {
//            ops::hls::DataConv conv;
//            conv.i = tmp.range((k+1) * DEBUG_LOG_SIZE_OF * 8 - 1, k * DEBUG_LOG_SIZE_OF * 8);
//            ops::hls::print("		%f,\n", conv.f);
//        }
//        ops::hls::print(")%d\n\n",0);
//		// ops::hls::print("====================================================================================\n");
//     #endif
//        strm_out << tmp;
//    }
//}
// template <unsigned short MEM_DATA_WIDTH, unsigned short NUM_BANKS, unsigned short BURST_SIZE=32, unsigned short IN_ITR=2>
// static void stridedTileStream2memWithAvoid(
//         ap_uint<mem_data_width>* arg_b0,
//         ap_uint<mem_data_width>* arg_b1,
//         // ap_uint<mem_data_width>* arg_b2,
//         // ap_uint<mem_data_width>* arg_b3,
//         // ap_uint<mem_data_width>* arg_b4,
//         // ap_uint<mem_data_width>* arg_b5,
//         // ap_uint<mem_data_width>* arg_b6,
//         // ap_uint<mem_data_width>* arg_b7,
//         unsigned short abs_row_offset,
//         unsigned short z_row_stride,
//         ::hls::stream<ap_uint<MEM_DATA_WIDTH>>& strm_in, const ap_uint<192>& command)
// {




static void datamover_outerloop_0_dataflow_read_write_dataflow_region(
//        const unsigned int num_pkts,
        const unsigned int num_beats,
        const unsigned int num_beats_div_4,
		const unsigned short size_y,
		const unsigned short size_z,
        ap_uint<192>& command,
        ap_uint<160>& short_command,
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
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_u_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_l_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_u_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_l_axis_in
)    
{
    #pragma HLS DATAFLOW
	::hls::stream<ap_uint<48>> arg0_read_command_strm[8];
	#pragma HLS STREAM variable = arg0_read_command_strm depth = 2
    ::hls::stream<ap_uint<mem_data_width>> arg0_read_mem_strm[8];
    #pragma HLS STREAM variable = arg0_read_mem_strm depth = 64
    ::hls::stream<ap_uint<mem_data_width>> arg0_redirect_mem_strm[8];
    #pragma HLS STREAM variable = arg0_redirect_mem_strm depth = 64
//    static ::hls::stream<ap_uint<mem_data_width*4>> arg0_combined_2048;
//    #pragma HLS STREAM variable = arg0_combined_2048 depth = 64
    ::hls::stream<ap_uint<mem_data_width*2>> arg0_combined_1024[2];
    #pragma HLS STREAM variable = arg0_combined_1024 depth = 64
    ::hls::stream<ap_uint<mem_data_width*2>> arg1_combined_1024[2];
    #pragma HLS STREAM variable = arg1_combined_1024 depth = 64
//    ::hls::stream<ap_uint<mem_data_width*4>> arg1_combined_2048;
//    #pragma HLS STREAM variable = arg1_combined_2048 depth = 64
    ::hls::stream<ap_uint<mem_data_width>> arg1_redirect_mem_strm[8];
	#pragma HLS STREAM variable = arg1_redirect_mem_strm depth = 64
	::hls::stream<ap_uint<mem_data_width>> arg1_write_mem_strm[8];
	#pragma HLS STREAM variable = arg1_write_mem_strm depth = 64
	::hls::stream<ap_uint<64>> arg1_write_command_strm[8];
		#pragma HLS STREAM variable = arg1_write_command_strm depth = 2

	read_config_stream_gen<8,2>(short_command,arg0_read_command_strm[0], arg0_read_command_strm[1], arg0_read_command_strm[2], arg0_read_command_strm[3],
			arg0_read_command_strm[4], arg0_read_command_strm[5], arg0_read_command_strm[6], arg0_read_command_strm[7]);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b0, arg0_read_command_strm[0], arg0_read_mem_strm[0], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b1, arg0_read_command_strm[1], arg0_read_mem_strm[1], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b2, arg0_read_command_strm[2], arg0_read_mem_strm[2], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b3, arg0_read_command_strm[3], arg0_read_mem_strm[3], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b4, arg0_read_command_strm[4], arg0_read_mem_strm[4], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b5, arg0_read_command_strm[5], arg0_read_mem_strm[5], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b6, arg0_read_command_strm[6], arg0_read_mem_strm[6], size_y, size_z);
	stridedTileMem2streamV2<mem_data_width, 16, 2>(arg0_b7, arg0_read_command_strm[7], arg0_read_mem_strm[7], size_y, size_z);
//	stridedTileMem2stream<mem_data_width, 8, 0, 16, 2>(arg0_b0, arg0_b1, arg0_read_mem_strm[0], arg0_read_mem_strm[1], short_command);
//    stridedTileMem2stream<mem_data_width, 8, 2, 16, 2>(arg0_b2, arg0_b3, arg0_read_mem_strm[2], arg0_read_mem_strm[3], short_command);
//    stridedTileMem2stream<mem_data_width, 8, 4, 16, 2>(arg0_b4, arg0_b5, arg0_read_mem_strm[4], arg0_read_mem_strm[5], short_command);
//    stridedTileMem2stream<mem_data_width, 8, 6, 16, 2>(arg0_b6, arg0_b7, arg0_read_mem_strm[6], arg0_read_mem_strm[7], short_command);

    redirect<mem_data_width, 8, 16, 2>(arg0_read_mem_strm[0], arg0_read_mem_strm[1], arg0_read_mem_strm[2], arg0_read_mem_strm[3],
            arg0_read_mem_strm[4], arg0_read_mem_strm[5], arg0_read_mem_strm[6], arg0_read_mem_strm[7],
            arg0_redirect_mem_strm[0], arg0_redirect_mem_strm[1], arg0_redirect_mem_strm[2], arg0_redirect_mem_strm[3],
            arg0_redirect_mem_strm[4], arg0_redirect_mem_strm[5], arg0_redirect_mem_strm[6], arg0_redirect_mem_strm[7], short_command);

    combine<mem_data_width, 8, 16, 2>(arg0_redirect_mem_strm[0], arg0_redirect_mem_strm[1], arg0_redirect_mem_strm[2], arg0_redirect_mem_strm[3],
            arg0_redirect_mem_strm[4], arg0_redirect_mem_strm[5], arg0_redirect_mem_strm[6], arg0_redirect_mem_strm[7],  arg0_combined_1024[0], arg0_combined_1024[1], short_command);
    
//    streamSplit2<mem_data_width_4x,mem_data_width_2x>(arg0_combined_2048, arg0_combined_1024[0], arg0_combined_1024[1], num_beats_div_4);
    ops::hls::stream2axis<axis_data_width>(arg0_combined_1024[0], arg0_l_axis_out, num_beats_div_4);//, false);
    ops::hls::stream2axis<axis_data_width>(arg0_combined_1024[1], arg0_u_axis_out, num_beats_div_4);//, false);

    ops::hls::axis2stream<axis_data_width>(arg1_l_axis_in, arg1_combined_1024[0], num_beats_div_4);//, false);
    ops::hls::axis2stream<axis_data_width>(arg1_u_axis_in, arg1_combined_1024[1], num_beats_div_4);//, false);
//    streamCombine2<mem_data_width_2x, mem_data_width_4x>(arg1_combined_1024[0], arg1_combined_1024[1], arg1_combined_2048, num_beats_div_4);
    split<mem_data_width, 8, 16, 2>(arg1_combined_1024[0], arg1_combined_1024[1], arg1_redirect_mem_strm[0], arg1_redirect_mem_strm[1], arg1_redirect_mem_strm[2], arg1_redirect_mem_strm[3],
    		arg1_redirect_mem_strm[4], arg1_redirect_mem_strm[5], arg1_redirect_mem_strm[6], arg1_redirect_mem_strm[7], short_command);
    reverseRedirect<mem_data_width, 8, 16, 2>(arg1_redirect_mem_strm[0], arg1_redirect_mem_strm[1], arg1_redirect_mem_strm[2], arg1_redirect_mem_strm[3],
    		arg1_redirect_mem_strm[4], arg1_redirect_mem_strm[5], arg1_redirect_mem_strm[6], arg1_redirect_mem_strm[7],
			arg1_write_mem_strm[0], arg1_write_mem_strm[1], arg1_write_mem_strm[2], arg1_write_mem_strm[3],
			arg1_write_mem_strm[4], arg1_write_mem_strm[5], arg1_write_mem_strm[6], arg1_write_mem_strm[7], short_command);
   write_config_stream_gen<8,2>(command, arg1_write_command_strm[0], arg1_write_command_strm[1], arg1_write_command_strm[2], arg1_write_command_strm[3],
   		arg1_write_command_strm[4], arg1_write_command_strm[5], arg1_write_command_strm[6], arg1_write_command_strm[7]);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[0], arg1_b0, arg1_write_command_strm[0], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[1], arg1_b1, arg1_write_command_strm[1], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[2], arg1_b2, arg1_write_command_strm[2], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[3], arg1_b3, arg1_write_command_strm[3], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[4], arg1_b4, arg1_write_command_strm[4], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[5], arg1_b5, arg1_write_command_strm[5], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[6], arg1_b6, arg1_write_command_strm[6], size_y, size_z);
   stridedTileStream2memWithAvoidV2<mem_data_width, 16, 2>(arg1_write_mem_strm[7], arg1_b7, arg1_write_command_strm[7], size_y, size_z);

    // stridedTileStream2memWithAvoid<mem_data_width, 8, 0, 16, 2>(arg1_b0, arg1_b1, arg1_write_mem_strm[0], arg1_write_mem_strm[1], command);
    // stridedTileStream2memWithAvoid<mem_data_width, 8, 2, 16, 2>(arg1_b2, arg1_b3, arg1_write_mem_strm[2], arg1_write_mem_strm[3], command);
    // stridedTileStream2memWithAvoid<mem_data_width, 8, 4, 16, 2>(arg1_b4, arg1_b5, arg1_write_mem_strm[4], arg1_write_mem_strm[5], command);
    // stridedTileStream2memWithAvoid<mem_data_width, 8, 6, 16, 2>(arg1_b6, arg1_b7, arg1_write_mem_strm[6], arg1_write_mem_strm[7], command);
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
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_u_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_l_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_u_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_l_axis_in
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
        ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0_dataflow_read_write| Calling datamover. i:%d\n", i);
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
//			const unsigned short abs_row_offset = tile_y * memconfig.effective_tile_size_y;
//			const ap_uint<64> tile_y_offset = abs_row_offset * memconfig.grid_xblocks;
			const unsigned short tile_size_y = tile_y == (memconfig.tile_count_y -1) ? memconfig.last_tile_size_y : memconfig.tile_size_y;
            const ap_uint<64> offset = memconfig.start_offset + tile_x_offset ;
            const unsigned int tile_size_y_mul_z_diff = tile_size_y * z_diff;
            const unsigned int widen_pkts_x = (tile_size_x + 3) >> 2;
            const unsigned int total_beats = tile_size_x * tile_size_y_mul_z_diff;
            const unsigned int total_beats_div_4 = widen_pkts_x * tile_size_y_mul_z_diff;
            bool small_tile = tile_size_x  <= 2;
            const unsigned int total_pkts_div_4 = small_tile ? total_beats_div_4 << 1 : total_beats_div_4;
//			const unsigned int total_pkts = total_beats * num_of_pkts_per_beat;

            const unsigned int avoid_x = tile_x == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
            const unsigned int avoid_y = tile_y == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
            auto command = ops::hls::commandGen3D(offset, 1, (ap_uint<16>)tile_size_x, (ap_uint<16>)stride_y, (ap_int<16>)tile_size_y, 
                    (ap_int<16>)stride_z, (ap_uint<16>)z_diff, (ap_uint<16>)avoid_x, (ap_uint<16>)avoid_y);
            ap_uint<160> short_command = command.range(159,0);

        #ifdef DEBUG_LOG
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| \n===============================\n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| total_beats: %d\n", total_beats);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| total_pkts_div_4: %d\n", total_pkts_div_4);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| ===============================\n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| command:   \n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    offset: %d  \n", offset);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_x (512_ty): %d  \n", tile_size_x);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_x: %d  \n",1);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_y: %d  \n", tile_size_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_y: %d  \n", stride_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_z: %d  \n", z_diff);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_z: %d  \n", stride_z);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    avoid_x: %d  \n", avoid_x);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    avoid_y: %d  \n", avoid_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| ===============================\n");
        #endif
            
            datamover_outerloop_0_dataflow_read_write_dataflow_region(
//                    total_pkts,
                    total_beats,
					total_pkts_div_4,
                    uint16_t(command.range(127,112)),
                    uint16_t(command.range(159,144)),
                    command,
                    short_command,
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
                    arg0_u_axis_out,
                    arg0_l_axis_out,
                    arg1_u_axis_in,
                    arg1_l_axis_in
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
            const unsigned int tile_size_y_mul_z_diff = tile_size_y * z_diff;
            const unsigned int widen_pkts_x = (tile_size_x + 3) >> 2;
            const unsigned int total_beats = tile_size_x * tile_size_y_mul_z_diff;
            const unsigned int total_beats_div_4 = widen_pkts_x * tile_size_y_mul_z_diff;
            bool small_tile = tile_size_x  < 4;
            const unsigned int total_pkts_div_4 = small_tile ? total_beats_div_4 << 1 : total_beats_div_4;
//			const unsigned int total_pkts = total_beats * num_of_pkts_per_beat;

            const unsigned int avoid_x = tile_x == 0 ? 0 : memconfig.tile_overlap_size_x >> 1;
            const unsigned int avoid_y = tile_y == 0 ? 0 : memconfig.tile_overlap_size_y >> 1;
            auto command = ops::hls::commandGen3D(offset, 1, (ap_uint<16>)tile_size_x, (ap_uint<16>)stride_y, (ap_int<16>)tile_size_y, 
                    (ap_int<16>)stride_z, (ap_uint<16>)z_diff, (ap_uint<16>)avoid_x, (ap_uint<16>)avoid_y);
            ap_uint<160> short_command = command.range(159,0);

         #ifdef DEBUG_LOG
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| \n===============================\n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| total_beats: %d\n", total_beats);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| total_pkts_div_4: %d\n", total_pkts_div_4);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| ===============================\n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| command:   \n");
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    offset: %d  \n", offset);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_x (512_ty): %d  \n", tile_size_x);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_x: %d  \n",1);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_y: %d  \n", tile_size_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_y: %d  \n", stride_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    tile_z: %d  \n", z_diff);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    stride_z: %d  \n", stride_z);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    avoid_x: %d  \n", avoid_x);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0|    avoid_y: %d  \n", avoid_y);
            ops::hls::print("[KERNEL_DEBUG]|datamover_outerloop_0| ===============================\n");
         #endif

            datamover_outerloop_0_dataflow_read_write_dataflow_region(
//                    total_pkts,
                    total_beats,
					total_pkts_div_4,
					uint16_t(command.range(127,112)),
					uint16_t(command.range(159,144)),
                    command,
                    short_command,
//                    abs_row_offset,
//                    memconfig.grid_size_y,
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
                    arg0_u_axis_out,
                    arg0_l_axis_out,
                    arg1_u_axis_in,
                    arg1_l_axis_in
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
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_u_axis_out,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg0_l_axis_out,
    //u2
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_u_axis_in,
        hls::stream <ap_axiu<axis_data_width,0,0,0>>& arg1_l_axis_in
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
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem0 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem1 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem2 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem3 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem4 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem5 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem6 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem7 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg0_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg0_b7 bundle = control
 
    #pragma HLS INTERFACE mode=m_axi bundle=gmem8 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b0 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b0 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem9 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b1 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b1 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem10 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b2 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b2 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem11 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b3 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b3 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem12 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b4 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b4 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem13 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b5 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b5 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem14 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b6 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b6 bundle = control
    #pragma HLS INTERFACE mode=m_axi bundle=gmem15 depth=512 max_read_burst_length=8 max_write_burst_length=8 \
            num_read_outstanding=2 num_write_outstanding=2 \
            port=arg1_b7 offset=slave latency=64
    #pragma HLS INTERFACE s_axilite port = arg1_b7 bundle = control
    #pragma HLS INTERFACE mode=axis port=arg0_u_axis_out register
    #pragma HLS INTERFACE mode=axis port=arg0_l_axis_out register
    #pragma HLS INTERFACE mode=axis port=arg1_u_axis_in register
    #pragma HLS INTERFACE mode=axis port=arg1_l_axis_in register

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
            arg0_u_axis_out,
            arg0_l_axis_out,
            arg1_u_axis_in,
            arg1_l_axis_in
            );
}


