// Auto-generated at 2026-03-16 14:01:45.891113 by ops-translator

#ifndef __LOOP_PE_JAC3D_KERNEL_STENCIL_TEST__
#define __LOOP_PE_JAC3D_KERNEL_STENCIL_TEST__
#include <ops_hls_kernel_support.h>
#include "../../common/include/common_config.hpp"

static constexpr unsigned short read_num_points_jac3D_kernel_stencil_test = 7;
static constexpr unsigned short read_stencil_size_jac3D_kernel_stencil_test = 3;
static constexpr unsigned short read_stencil_dim_jac3D_kernel_stencil_test = 3;

static constexpr unsigned short write_num_points_jac3D_kernel_stencil_test = 1;
static constexpr unsigned short write_stencil_size_jac3D_kernel_stencil_test = 1;
static constexpr unsigned short write_stencil_dim_jac3D_kernel_stencil_test = 3;

static constexpr unsigned short adj_shift_bits = 6;
static constexpr unsigned short adj_vector_factor = vector_factor * 8;
static constexpr unsigned short vector_factor_jac3D_kernel_stencil_test_0 = adj_vector_factor * 1;
static constexpr unsigned short axis_data_width_l_jac3D_kernel_stencil_test_0 = vector_factor_jac3D_kernel_stencil_test_0 * data_width;
static constexpr unsigned short axis_data_width_l_jac3D_kernel_stencil_test_0_half = axis_data_width_l_jac3D_kernel_stencil_test_0 >> 1;
// typedef ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0> widen_jac3D_kernel_stencil_test_0_dt;
// typedef ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0_half> widen_jac3D_kernel_stencil_test_0_half_dt;
static constexpr unsigned short vector_factor_jac3D_kernel_stencil_test_1 = adj_vector_factor * 1;
static constexpr unsigned short axis_data_width_l_jac3D_kernel_stencil_test_1 = vector_factor_jac3D_kernel_stencil_test_1 * data_width;
static constexpr unsigned short axis_data_width_l_jac3D_kernel_stencil_test_1_half = axis_data_width_l_jac3D_kernel_stencil_test_1 >> 1;
// typedef ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1> widen_jac3D_kernel_stencil_test_1_dt;
// typedef ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half> widen_jac3D_kernel_stencil_test_1_half_dt;

// typedef ::hls::stream<widen_jac3D_kernel_stencil_test_0_half_dt> widen_stream_jac3D_kernel_stencil_test_0_dt;
// typedef ::hls::stream<widen_jac3D_kernel_stencil_test_1_half_dt> widen_stream_jac3D_kernel_stencil_test_1_dt;

typedef ap_uint<288> pe_hls_arg0_dt;
typedef ::hls::stream<pe_hls_arg0_dt> widen_stream_jac3D_kernel_stencil_test_0_dt;
typedef ap_uint<288> pe_hls_arg1_dt;
typedef ::hls::stream<pe_hls_arg1_dt> widen_stream_jac3D_kernel_stencil_test_1_dt;
// static constexpr unsigned short tile_shift_bits = 4; //16 elements
static constexpr unsigned short tile_vector_factor_arg0 = vector_factor * 2 + 2;
static constexpr unsigned short tile_vector_factor_arg1_min2 = vector_factor * 2;
static constexpr unsigned short tile_vector_factor_arg1_min1 = vector_factor * 2 + 1;
static constexpr unsigned short tile_vector_factor_arg1 = tile_vector_factor_arg1_min2 + 2;
typedef ap_uint<576> widen_jac3D_kernel_stencil_test_0_dt;
typedef ap_uint<576> widen_jac3D_kernel_stencil_test_1_dt;
/*
    ArgDat(id=0, loc=/home/x_thileeb/repos/ops-hls-batching-new/codegen_apps/tiling/jacobian3d/u280/maxtile_256_256_interleave_project_copy/jac3D7pt.cpp/327:21, access_type=AccessType.OPS_READ, opt=True, dat_id=0, global_dat_id=-1, stencil_id=S3D_7PT)
    ArgDat(id=1, loc=/home/x_thileeb/repos/ops-hls-batching-new/codegen_apps/tiling/jacobian3d/u280/maxtile_256_256_interleave_project_copy/jac3D7pt.cpp/328:21, access_type=AccessType.OPS_WRITE, opt=True, dat_id=1, global_dat_id=-1, stencil_id=S3D_00)
*/
inline void kernel_jac3D_kernel_stencil_test_core(
        const stencil_type& reg_0_0,
        const stencil_type& reg_0_1,
        const stencil_type& reg_0_2,
        const stencil_type& reg_0_3,
        const stencil_type& reg_0_4,
        const stencil_type& reg_0_5,
        const stencil_type& reg_0_6,
        stencil_type& reg_1_0
)
{
#ifdef DEBUG_LOG
    printf("[KERNEL_INTERNAL_CORE]|%s| starting kernel core: kernel_jac3D_kernel_stencil_test_core\n",__func__);
#endif

    float tmp1 = reg_0_6 * (0.02f);
    float tmp2 = reg_0_5 * (0.04f);
    float tmp3 = reg_0_2 * (0.05f);
    float tmp4 = reg_0_3 * (0.79f);
    float tmp5 = reg_0_4 * (0.06f);
    float tmp6 = reg_0_1 * (0.03f);
    float tmp7 = reg_0_0 * (0.01f);
    float tmp8 = tmp1 + tmp2;
    float tmp9 = tmp3 + tmp4;
    float tmp10 = tmp5 + tmp6;
    float tmp11 = tmp7 + tmp8;
    float tmp12 = tmp9 + tmp10;
    reg_1_0 = tmp11 + tmp12;
    // reg_1_0 = reg_0_3 + 1;

#ifdef DEBUG_LOG
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_0: %f \n", __func__, reg_0_0);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_1: %f \n", __func__, reg_0_1);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_2: %f \n", __func__, reg_0_2);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_3: %f \n", __func__, reg_0_3);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_4: %f \n", __func__, reg_0_4);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_5: %f \n", __func__, reg_0_5);
    printf("[KERNEL_INTERNAL_CORE]|%s| read_val - reg_0_6: %f \n", __func__, reg_0_6);
    printf("[KERNEL_INTERNAL_CORE]|%s| write_val - reg_1_0: %f \n", __func__, reg_1_0);
#endif

#ifdef DEBUG_LOG
    printf("[KERNEL_INTERNAL_CORE]|%s| exiting: kernel_jac3D_kernel_stencil_test_core\n",__func__);
#endif
}

template <unsigned short NUM_SUB_TILE, unsigned short SUB_TILE_ID>
class Stencil_jac3D_kernel_stencil_test : public ops::hls::StencilCoreV2<stencil_type, read_num_points_jac3D_kernel_stencil_test, adj_vector_factor, ops::hls::CoefTypes::CONST_COEF,
        read_stencil_size_jac3D_kernel_stencil_test, read_stencil_dim_jac3D_kernel_stencil_test, true>
{
    using ops::hls::StencilCoreV2<stencil_type, read_num_points_jac3D_kernel_stencil_test, adj_vector_factor, ops::hls::CoefTypes::CONST_COEF,
            read_stencil_size_jac3D_kernel_stencil_test, read_stencil_dim_jac3D_kernel_stencil_test, true>::m_stencilConfig;
public:

    void stencilRun(
            widen_stream_jac3D_kernel_stencil_test_0_dt& arg0_u_rd_buffer,
            widen_stream_jac3D_kernel_stencil_test_0_dt& arg0_l_rd_buffer,
            widen_stream_jac3D_kernel_stencil_test_1_dt& arg1_u_wr_buffer,
            widen_stream_jac3D_kernel_stencil_test_1_dt& arg1_l_wr_buffer
        )
    {
        ::ops::hls::StencilConfigCoreSingleTile stencilConfig = m_stencilConfig;
        #pragma HLS ARRAY_PARTITION variable = stencilConfig.tile_size dim = 1 complete
        //#pragma HLS ARRAY_PARTITION variable = stencilConfig.is_tiled dim = 1 complete
        #pragma HLS ARRAY_PARTITION variable = stencilConfig.is_first dim = 1 complete
        #pragma HLS ARRAY_PARTITION variable = stencilConfig.is_last dim = 1 complete
        //#pragma HLS ARRAY_PARTITION variable = stencilConfig.last_tile_size dim = 1 complete
        //#pragma HLS ARRAY_PARTITION variable = stencilConfig.tile_count dim = 1 complete
        //#pragma HLS ARRAY_PARTITION variable = stencilConfig.grid_size dim = 1 complete
        const unsigned short peId = m_PEId;

        const unsigned short span_x = 2;
        const unsigned short half_span_x = 1;
        const unsigned short true_tile_size_x = stencilConfig.tile_size[0] << adj_shift_bits;
        // overlap_size = 32, total_PEs = 2 
        
        constexpr bool is_first_sub_tile = (SUB_TILE_ID == 0);
        constexpr bool is_last_sub_tile = (SUB_TILE_ID == NUM_SUB_TILE - 1);
        const bool is_first_x = stencilConfig.is_first[0] && is_first_sub_tile;
        const bool is_last_x =  stencilConfig.is_last[0] && is_last_sub_tile;
        constexpr unsigned short sub_tile_id_x_sub_tile_size = SUB_TILE_ID * 16;
        const short x_idx_adjust = is_first_x ? - half_span_x : sub_tile_id_x_sub_tile_size - half_span_x;
        // const unsigned short adj_half_span_x_lower = stencilConfig.is_first[0]? half_span_x : half_span_x * (peId + 1);
        // const unsigned short adj_half_span_x_upper = stencilConfig.is_last[0]? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_x_lower = is_first_x? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_x_upper = is_last_x? half_span_x : half_span_x * (peId + 1);

        // const unsigned short adj_half_span_y_lower = stencilConfig.is_first[1]? half_span_x : half_span_x * (peId + 1);
        // const unsigned short adj_half_span_y_upper = stencilConfig.is_last[1]? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_y_lower = stencilConfig.is_first[1]? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_y_upper = stencilConfig.is_last[1]? half_span_x : half_span_x * (peId + 1);

        // static limits are set outside the tile loops
        const unsigned short lower_limit_x = adj_half_span_x_lower;
        //const unsigned short min_limit_x_const = stencilConfig.last_tile_upper_limit_x < true_tile_size_x ? stencilConfig.last_tile_upper_limit_x : true_tile_size_x;  //(stencilConfig.last_tile_upper_limit_x - adj_half_span_x) < adj_half_span_x ? adj_half_span_x : (stencilConfig.last_tile_upper_limit_x - adj_half_span_x);
        //const unsigned short upper_limit_x = (min_limit_x_const - adj_half_span_x_upper) < adj_half_span_x_upper ? adj_half_span_x_upper : min_limit_x_const - adj_half_span_x_upper;
        const unsigned short upper_limit_x = stencilConfig.is_last[0] ? stencilConfig.last_tile_upper_limit_x - 1 : true_tile_size_x - adj_half_span_x_upper;
        const unsigned short lower_limit_y = adj_half_span_y_lower;
        const unsigned short lower_limit_z = half_span_x;
        const unsigned short upper_limit_z = stencilConfig.outer_loop_limit - span_x;
        const unsigned short upper_limit_y = (stencilConfig.tile_size[1] - adj_half_span_y_upper) < adj_half_span_y_upper ? adj_half_span_y_upper : (stencilConfig.tile_size[1] - adj_half_span_y_upper);

            //read_origin_wide_diff_x: 0, read_origin_wide_diff: (0,0,1)
        //  *** counters definitions ****
            short i = -1;
            short j = 0; 
            short k = -1;
            //unsigned short plane_diff = tile_size_x * tile_size_y - 1;
            unsigned short plane_diff = stencilConfig.tile_size[0] * stencilConfig.tile_size[1] - 1;

        //  *** stencil description and read & write point definitions  ****
            /*
            WindowBufferDiscriptor(widen_stencil=Stencil(id=-1, dim=3, stencil_ptr='read_stencil_widen', num_points=7, points=[Point(x=1, y=1, z=0), Point(x=1, y=0, z=1), Point(x=0, y=1, z=1), Point(x=1, y=1, z=1), Point(x=2, y=1, z=1), Point(x=1, y=2, z=1), Point(x=1, y=1, z=2)], base_point=Point(x=1, y=1, z=1), stencil_size=Point(x=3, y=3, z=3), d_m=Point(x=-0.75, y=1, z=1), d_p=Point(x=1.0, y=1, z=1), row_discriptors=[StencilRowDiscriptor(row_id=(1, 0), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=1, z=0)]), StencilRowDiscriptor(row_id=(0, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=0, z=1)]), StencilRowDiscriptor(row_id=(1, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=0, y=1, z=1), Point(x=1, y=1, z=1), Point(x=2, y=1, z=1)]), StencilRowDiscriptor(row_id=(2, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=2, z=1)]), StencilRowDiscriptor(row_id=(1, 2), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=1, z=2)])], stride=[], read_origin_diff=Point(x=0, y=0, z=1)), window_buffers=[WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False), WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False), WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False), WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False)], chains=[(0, WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False)), (1, WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False), 1), (2, 3), (3, 4), (4, WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False), 2), (5, WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False), 5), (6, 'read_val'), (WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False), 6)], point_to_widen_map={Point(x=1, y=1, z=0): Point(x=1, y=1, z=0), Point(x=1, y=0, z=1): Point(x=1, y=0, z=1), Point(x=0, y=1, z=1): Point(x=0, y=1, z=1), Point(x=1, y=1, z=1): Point(x=1, y=1, z=1), Point(x=2, y=1, z=1): Point(x=2, y=1, z=1), Point(x=1, y=2, z=1): Point(x=1, y=2, z=1), Point(x=1, y=1, z=2): Point(x=1, y=1, z=2)})
            */
            // Stencil: S3D_7PT
            //      |- point: (1,1,0)
            //      |- point: (1,0,1)
            //      |- point: (0,1,1)
            //      |- point: (1,1,1)
            //      |- point: (2,1,1)
            //      |- point: (1,2,1)
            //      `- point: (1,1,2)
            // read point: (1,0,1), write point: (1,1,0)
            unsigned short S3D_7PT_buf_p0_1_rd;

            if (-1 * stencilConfig.tile_size[0] + 0 > 0)
                S3D_7PT_buf_p0_1_rd = -1 * stencilConfig.tile_size[0] + 0;
            else
                S3D_7PT_buf_p0_1_rd = 0;

            unsigned short S3D_7PT_buf_p0_1_wr;

            if (1 * stencilConfig.tile_size[0] + 0 > 0)
                S3D_7PT_buf_p0_1_wr = 1 * stencilConfig.tile_size[0] + 0;
            else
                S3D_7PT_buf_p0_1_wr = 0;
            // read point: (0,1,1), write point: (1,0,1)
            unsigned short S3D_7PT_buf_r0_1_p1_rd = 0;
            unsigned short S3D_7PT_buf_r0_1_p1_wr = 1;
            // read point: (1,2,1), write point: (2,1,1)
            unsigned short S3D_7PT_buf_r1_2_p1_rd = 0;
            unsigned short S3D_7PT_buf_r1_2_p1_wr = 1;
            // read point: (1,1,2), write point: (1,2,1)
            unsigned short S3D_7PT_buf_p1_2_rd;

            if (-1 * stencilConfig.tile_size[0] + 0 > 0)
                S3D_7PT_buf_p1_2_rd = -1 * stencilConfig.tile_size[0] + 0;
            else
                S3D_7PT_buf_p1_2_rd = 0;

            unsigned short S3D_7PT_buf_p1_2_wr;

            if (1 * stencilConfig.tile_size[0] + 0 > 0)
                S3D_7PT_buf_p1_2_wr = 1 * stencilConfig.tile_size[0] + 0;
            else
                S3D_7PT_buf_p1_2_wr = 0;

        //  *** iteration limit definition ****
            unsigned int iter_limit = stencilConfig.outer_loop_limit * stencilConfig.tile_size[0] * stencilConfig.tile_size[1];

        //  *** data read write boundary definitions ****
            unsigned int S3D_7PT_read_lb_itr = 0;
            unsigned int S3D_7PT_read_ub_itr = stencilConfig.tile_size[2]  * stencilConfig.tile_size[0] * stencilConfig.tile_size[1];

        /*
            unsigned int read_lb_itr = 0;
            unsigned int read_ub_itr = stencilConfig.grid_size[2] * stencilConfig.grid_size[1] * stencilConfig.grid_size[0];
        */
        //  *** Read & write widen temporaries ****
        // arg0(u)
            widen_jac3D_kernel_stencil_test_0_dt arg0_read_val = 0;
        // arg1(u2)
            widen_jac3D_kernel_stencil_test_1_dt arg1_update_val;
            widen_jac3D_kernel_stencil_test_1_dt arg1_update_val_tmp;
        // 2
        //  *** widen stencil values holder & window buffers ****

            // arg0(u)
            widen_jac3D_kernel_stencil_test_0_dt arg0_widenStencilValues[read_num_points_jac3D_kernel_stencil_test];
            #pragma HLS ARRAY_PARTITION variable = arg0_widenStencilValues dim = 1 complete

            widen_jac3D_kernel_stencil_test_0_dt arg0_buf_p0_1[1067];
            #pragma HLS BIND_STORAGE variable = arg0_buf_p0_1 type = ram_s2p impl = URAM latency=2  
                    // curr SIS_id = 0
                    // next SIS_id = 1
            widen_jac3D_kernel_stencil_test_0_dt arg0_buf_r0_1_p1[5];
            #pragma HLS BIND_STORAGE variable = arg0_buf_r0_1_p1 type = ram_s2p impl = BRAM latency=2
                    // curr SIS_id = 1
                    // next SIS_id = 0
            widen_jac3D_kernel_stencil_test_0_dt arg0_buf_r1_2_p1[5];
            #pragma HLS BIND_STORAGE variable = arg0_buf_r1_2_p1 type = ram_s2p impl = BRAM latency=2
                    // curr SIS_id = 0
                    // next SIS_id = 1
            widen_jac3D_kernel_stencil_test_0_dt arg0_buf_p1_2[1070];
            #pragma HLS BIND_STORAGE variable = arg0_buf_p1_2 type = ram_s2p impl = URAM latency=2  
                    // curr SIS_id = 1
                    // next SIS_id = 0

            bool neg_cond_storage[tile_vector_factor_arg1];
            #pragma HLS ARRAY_PARTITION variable = neg_cond_storage dim=1 complete
            stencil_type arg0_rowArr_1_0[tile_vector_factor_arg0 + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_0 dim=1 complete
            stencil_type arg0_rowArr_0_1[tile_vector_factor_arg0 + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_0_1 dim=1 complete
            stencil_type arg0_rowArr_1_1[tile_vector_factor_arg0 + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_1 dim=1 complete
            stencil_type arg0_rowArr_2_1[tile_vector_factor_arg0 + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_2_1 dim=1 complete
            stencil_type arg0_rowArr_1_2[tile_vector_factor_arg0 + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_2 dim=1 complete

            const short cond_x_val = stencilConfig.tile_size[0] - 1; 
            const short cond_y_val = stencilConfig.tile_size[1]  - 1;
            const short cond_z_val = stencilConfig.outer_loop_limit - 1;

    #ifdef DEBUG_LOG
            printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d] initial values, "\
                "iter_limit(%d), true_tile_size_x(%d), "\
                "tile_size_x(%d), "\
                "iter_limit: %d, S3D_7PT_read_ub_itr: %d, S3D_7PT_read_lb_itr: %d, stencilConfig.tile_size[2]: %d, " \
                " stencilConfig.tile_size[1]: %d, stencilConfig.outer_loop_limit:%d \n", 
                m_PEId, iter_limit, true_tile_size_x,  stencilConfig.tile_size[0],
                iter_limit, S3D_7PT_read_ub_itr, S3D_7PT_read_lb_itr, stencilConfig.tile_size[1], stencilConfig.tile_size[2], stencilConfig.outer_loop_limit);
    #endif

            for (unsigned int itr = 0; itr < iter_limit; itr++)
            {
            #pragma HLS PIPELINE II=1
                unsigned int reg_itr = register_it(itr);

                spc_temp_blocking_read:
                {
                    bool cond_x_terminate = (i == cond_x_val ? true : false); 
                    bool cond_y_terminate = (j == cond_y_val ? true : false);
                    bool cond_z_terminate = (k == cond_z_val ? true : false);

    #ifdef DEBUG_LOG
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d] loop params before update i(%d), "\
                        "j(%d), "\
                        "k(%d), "\
                        "S3D_7PT_buf_p0_1_rd: %d, "\
                        "S3D_7PT_buf_p0_1_wr: %d, "\
                        "S3D_7PT_buf_r0_1_p1_rd: %d, "\
                        "S3D_7PT_buf_r0_1_p1_wr: %d, "\
                        "S3D_7PT_buf_r1_2_p1_rd: %d, "\
                        "S3D_7PT_buf_r1_2_p1_wr: %d, "\
                        "S3D_7PT_buf_p1_2_rd: %d, "\
                        "S3D_7PT_buf_p1_2_wr: %d, "\
                        "reg_itr(%d)\n", m_PEId, i, 
                        j,
                        k,
                        S3D_7PT_buf_p0_1_rd, 
                        S3D_7PT_buf_p0_1_wr, 
                        S3D_7PT_buf_r0_1_p1_rd, 
                        S3D_7PT_buf_r0_1_p1_wr, 
                        S3D_7PT_buf_r1_2_p1_rd, 
                        S3D_7PT_buf_r1_2_p1_wr, 
                        S3D_7PT_buf_p1_2_rd, 
                        S3D_7PT_buf_p1_2_wr, 
                        reg_itr);
    #endif
                    if (cond_x_terminate)
                        i = 0;
                    else
                        i++;
                    if (cond_x_terminate && cond_y_terminate)
                        j = 0;
                    else if  (cond_x_terminate)
                        j++;
                    if (cond_x_terminate && cond_y_terminate && cond_z_terminate)
                        k = 0;
                    else if (cond_x_terminate && cond_y_terminate)
                        k++;

                    bool S3D_7PT_read_cond = (reg_itr < S3D_7PT_read_ub_itr) and (reg_itr >= S3D_7PT_read_lb_itr);
                /*    bool read_cond  =  (reg_itr < read_ub_itr) and (reg_itr >= read_lb_itr); */

                    if (S3D_7PT_read_cond)
                    {
                        arg0_read_val.range(287, 0) = arg0_l_rd_buffer.read();
                        arg0_read_val.range(575, 288) = arg0_u_rd_buffer.read();
                    }

                    /*if (read_cond)
                    {
                        arg0_read_val = arg0_rd_buffer.read();
                    }*/

                    arg0_widenStencilValues[0] = arg0_buf_p0_1[S3D_7PT_buf_p0_1_wr];                
                    arg0_widenStencilValues[1] = arg0_buf_r0_1_p1[S3D_7PT_buf_r0_1_p1_wr];                
                    arg0_buf_p0_1[S3D_7PT_buf_p0_1_rd] = arg0_widenStencilValues[1];                
                    arg0_widenStencilValues[2] = arg0_widenStencilValues[3];                
                    arg0_widenStencilValues[3] = arg0_widenStencilValues[4];                
                    arg0_widenStencilValues[4] = arg0_buf_r1_2_p1[S3D_7PT_buf_r1_2_p1_wr];                
                    arg0_buf_r0_1_p1[S3D_7PT_buf_r0_1_p1_rd] = arg0_widenStencilValues[2];                
                    arg0_widenStencilValues[5] = arg0_buf_p1_2[S3D_7PT_buf_p1_2_wr];                
                    arg0_buf_r1_2_p1[S3D_7PT_buf_r1_2_p1_rd] = arg0_widenStencilValues[5];                
                    arg0_widenStencilValues[6] = arg0_read_val;                
                    arg0_buf_p1_2[S3D_7PT_buf_p1_2_rd] = arg0_widenStencilValues[6];

                    bool cond_end_of_line_buff_S3D_7PT_buf_p0_1_rd = S3D_7PT_buf_p0_1_rd >= (plane_diff);
                    bool cond_end_of_line_buff_S3D_7PT_buf_p0_1_wr = S3D_7PT_buf_p0_1_wr >= (plane_diff);

                    if (cond_end_of_line_buff_S3D_7PT_buf_p0_1_rd)
                        S3D_7PT_buf_p0_1_rd = 0;
                    else
                        S3D_7PT_buf_p0_1_rd++;

                    if (cond_end_of_line_buff_S3D_7PT_buf_p0_1_wr)
                        S3D_7PT_buf_p0_1_wr = 0;
                    else
                        S3D_7PT_buf_p0_1_wr++;
                    bool cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_rd = S3D_7PT_buf_r0_1_p1_rd >= (stencilConfig.tile_size[0] - 1);
                    bool cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_wr = S3D_7PT_buf_r0_1_p1_wr >= (stencilConfig.tile_size[0] - 1);

                    if (cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_rd)
                        S3D_7PT_buf_r0_1_p1_rd = 0;
                    else
                        S3D_7PT_buf_r0_1_p1_rd++;

                    if (cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_wr)
                        S3D_7PT_buf_r0_1_p1_wr = 0;
                    else
                        S3D_7PT_buf_r0_1_p1_wr++;
                    bool cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_rd = S3D_7PT_buf_r1_2_p1_rd >= (stencilConfig.tile_size[0] - 1);
                    bool cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_wr = S3D_7PT_buf_r1_2_p1_wr >= (stencilConfig.tile_size[0] - 1);

                    if (cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_rd)
                        S3D_7PT_buf_r1_2_p1_rd = 0;
                    else
                        S3D_7PT_buf_r1_2_p1_rd++;

                    if (cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_wr)
                        S3D_7PT_buf_r1_2_p1_wr = 0;
                    else
                        S3D_7PT_buf_r1_2_p1_wr++;
                    bool cond_end_of_line_buff_S3D_7PT_buf_p1_2_rd = S3D_7PT_buf_p1_2_rd >= (plane_diff);
                    bool cond_end_of_line_buff_S3D_7PT_buf_p1_2_wr = S3D_7PT_buf_p1_2_wr >= (plane_diff);

                    if (cond_end_of_line_buff_S3D_7PT_buf_p1_2_rd)
                        S3D_7PT_buf_p1_2_rd = 0;
                    else
                        S3D_7PT_buf_p1_2_rd++;

                    if (cond_end_of_line_buff_S3D_7PT_buf_p1_2_wr)
                        S3D_7PT_buf_p1_2_wr = 0;
                    else
                        S3D_7PT_buf_p1_2_wr++;

    #ifdef DEBUG_LOG
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] loop params after update i(%d), "\
                                    "j(%d), "\
                                    "k(%d), "\
                                    "S3D_7PT_buf_p0_1_rd(%d), "\
                                    "S3D_7PT_buf_p0_1_wr(%d), "\
                                    "S3D_7PT_buf_r0_1_p1_rd(%d), "\
                                    "S3D_7PT_buf_r0_1_p1_wr(%d), "\
                                    "S3D_7PT_buf_r1_2_p1_rd(%d), "\
                                    "S3D_7PT_buf_r1_2_p1_wr(%d), "\
                                    "S3D_7PT_buf_p1_2_rd(%d), "\
                                    "S3D_7PT_buf_p1_2_wr(%d), "\
                                    "reg_itr(%d)\n", m_PEId, SUB_TILE_ID, i, 
                                    j,
                                    k,
                                    S3D_7PT_buf_p0_1_rd, 
                                    S3D_7PT_buf_p0_1_wr, 
                                    S3D_7PT_buf_r0_1_p1_rd, 
                                    S3D_7PT_buf_r0_1_p1_wr, 
                                    S3D_7PT_buf_r1_2_p1_rd, 
                                    S3D_7PT_buf_r1_2_p1_wr, 
                                    S3D_7PT_buf_p1_2_rd, 
                                    S3D_7PT_buf_p1_2_wr, 
                                    reg_itr);

                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] --------------------------------------------------------\n\n", m_PEId, SUB_TILE_ID);

                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] read values arg0: (", m_PEId,SUB_TILE_ID);
                    for (int ri = 0; ri < tile_vector_factor_arg0; ri++)
                    {
                        ops::hls::DataConv tmpConverter;
                        tmpConverter.i = arg0_read_val.range((ri + 1)*s_datatype_size - 1, ri * s_datatype_size);

                        printf("%f ", tmpConverter.f);
                    }
                    printf(")\n");
    #endif      
                }

                vec2arr: for (unsigned short x = 0; x < tile_vector_factor_arg0; x++)
                {
    #pragma HLS UNROLL factor=tile_vector_factor_arg0
                    ops::hls::DataConv arg0_tmpConverter_1_0;
                    arg0_tmpConverter_1_0.i = arg0_widenStencilValues[0].range(s_datatype_size * (x + 1) - 1, x * s_datatype_size);
                    arg0_rowArr_1_0[x + half_span_x] = arg0_tmpConverter_1_0.f; 
                    ops::hls::DataConv arg0_tmpConverter_0_1;
                    arg0_tmpConverter_0_1.i = arg0_widenStencilValues[1].range(s_datatype_size * (x + 1) - 1, x * s_datatype_size);
                    arg0_rowArr_0_1[x + half_span_x] = arg0_tmpConverter_0_1.f; 
                    ops::hls::DataConv arg0_tmpConverter_1_1;
                    arg0_tmpConverter_1_1.i = arg0_widenStencilValues[3].range(s_datatype_size * (x + 1) - 1, x * s_datatype_size);
                    arg0_rowArr_1_1[x + half_span_x] = arg0_tmpConverter_1_1.f; 
                    ops::hls::DataConv arg0_tmpConverter_2_1;
                    arg0_tmpConverter_2_1.i = arg0_widenStencilValues[5].range(s_datatype_size * (x + 1) - 1, x * s_datatype_size);
                    arg0_rowArr_2_1[x + half_span_x] = arg0_tmpConverter_2_1.f; 
                    ops::hls::DataConv arg0_tmpConverter_1_2;
                    arg0_tmpConverter_1_2.i = arg0_widenStencilValues[6].range(s_datatype_size * (x + 1) - 1, x * s_datatype_size);
                    arg0_rowArr_1_2[x + half_span_x] = arg0_tmpConverter_1_2.f; 

                }
                vec2arr_rest:
                {
                    //diff = -1
                    // access_idx = 0
                    ops::hls::DataConv arg0_tmpConverter_0_1_1_7;
                    arg0_tmpConverter_0_1_1_7.i = arg0_widenStencilValues[2].range(s_datatype_size * (17 + 1) - 1, s_datatype_size * 17);
                    arg0_rowArr_1_1[0] = arg0_tmpConverter_0_1_1_7.f;
                    //diff = 1
                    // access_idx = 65
                    ops::hls::DataConv arg0_tmpConverter_2_1_1_0;
                    arg0_tmpConverter_2_1_1_0.i = arg0_widenStencilValues[4].range(s_datatype_size * (0 + 1) - 1, s_datatype_size * 0);
                    arg0_rowArr_1_1[19] = arg0_tmpConverter_2_1_1_0.f;
                }

                process: for (unsigned short x = 1; x < tile_vector_factor_arg1_min1; x++)
                {
    #pragma HLS UNROLL factor=tile_vector_factor_arg1_min2
                    short index = (i << adj_shift_bits) + x + x_idx_adjust;
//                    short index_min_1 = index - 1;
                    bool neg_cond = register_it(             
                            (index < lower_limit_x)
                            || (index >= upper_limit_x)
                            || (j < lower_limit_y) 
                            || (j >= upper_limit_y)
                            || (k < lower_limit_z) 
                            || (k >= upper_limit_z)
                    );

    #ifdef DEBUG_LOG
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] index=(%d, %d, %d), lowerbound=(%d, %d, %d), upperbound=(%d, %d, %d), neg_cond=%d\n", m_PEId, SUB_TILE_ID, index, j, k,
                                lower_limit_x, lower_limit_y, lower_limit_z, 
                                upper_limit_x, upper_limit_y, upper_limit_z, neg_cond);

    #endif
                    stencil_type arg1_result;

                    kernel_jac3D_kernel_stencil_test_core(
                            arg0_rowArr_1_0[x + 1],
                            arg0_rowArr_0_1[x + 1],
                            arg0_rowArr_1_1[x + 0],
                            arg0_rowArr_1_1[x + 1],
                            arg0_rowArr_1_1[x + 2],
                            arg0_rowArr_2_1[x + 1],
                            arg0_rowArr_1_2[x + 1],
                            arg1_result
                    );

                    ops::hls::DataConv arg1_tmpConvWrite;
                    
                    if (neg_cond){
                        // dat_id: 1, dat: u2, swap_id: 0, swap_dat: u
                        arg1_tmpConvWrite.f = arg0_rowArr_1_1[x + 1];
                        // arg1_update_val.range(s_datatype_size * (x + 1) - 1, x * s_datatype_size) = arg1_tmpConvWrite.i;
                    } else {
                        arg1_tmpConvWrite.f = arg1_result;
                    }
                    arg1_update_val.range(s_datatype_size * (x + 1) - 1, x * s_datatype_size) = arg1_tmpConvWrite.i;
                }
                process_rest: {
                    arg1_update_val.range(s_datatype_size * (0 + 1) - 1, s_datatype_size * 0) = arg0_rowArr_1_1[0 + 1];
                    arg1_update_val.range(s_datatype_size * (17 + 1) - 1, s_datatype_size * 17) = arg0_rowArr_1_1[17 + 1];
                }
    //             process_part2: for (unsigned short x = 0; x < tile_vector_factor_arg1; x++)
    //             {
    // #pragma HLS UNROLL factor=tile_vector_factor_arg1
    //                 // short index = (i << adj_shift_bits) + x + x_idx_adjust;


    //                 ops::hls::DataConv arg1_tmpConvWrite;

    //                 if (neg_cond_storage[x])
    //                 {
    //     // [1, 0]
    //             //dat_id: 1, dat: u2, swap_id: 0, swap_dat: u
    //                     arg1_tmpConvWrite.f = arg0_rowArr_1_1[x + 1];
    //                     arg1_update_val.range(s_datatype_size * (x + 1) - 1, x * s_datatype_size) = arg1_tmpConvWrite.i;
    //                 }                    
    //             }

                write:
                {
                    bool cond_write = (k >= 0);

                    if (cond_write)
                    {
    #ifdef DEBUG_LOG
                        printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] --------------------------------------------------------\n\n", m_PEId, SUB_TILE_ID);

                        printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_test_PE_%d_t%d] wirte values arg1: (", m_PEId, SUB_TILE_ID);
                        for (int ri = 0; ri < tile_vector_factor_arg1; ri++)
                        {
                            ops::hls::DataConv tmpConverter;
                            tmpConverter.i = arg1_update_val.range((ri + 1)*s_datatype_size - 1, ri * s_datatype_size);
                            printf("%f ", tmpConverter.f);
                        }
                        printf(")\n");
    #endif
                        arg1_l_wr_buffer <<  arg1_update_val.range(287,0);
                        arg1_u_wr_buffer <<  arg1_update_val.range(575,288);
                    }
                }
            }
        }
};

template <unsigned short NUM_SUB_TILE, unsigned short SUB_TILE_ID>
static void kernel_jac3D_kernel_stencil_PE(const short& PEId, const ops::hls::StencilConfigCoreSingleTile& stencilConfig,
            //u
    widen_stream_jac3D_kernel_stencil_test_0_dt& arg0_u_rd_buffer,
    widen_stream_jac3D_kernel_stencil_test_0_dt& arg0_l_rd_buffer,
            //u2
    widen_stream_jac3D_kernel_stencil_test_1_dt& arg1_u_wr_buffer,
    widen_stream_jac3D_kernel_stencil_test_1_dt& arg1_l_wr_buffer        
)
{
    Stencil_jac3D_kernel_stencil_test<NUM_SUB_TILE, SUB_TILE_ID> stencil;

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s|PE_%d_t%d| stencil config gridSize: %d (xblocks), %d, %d\n", __func__, PEId, SUB_TILE_ID, stencilConfig.tile_size[0], stencilConfig.tile_size[1], stencilConfig.tile_size[2]);
#endif
    stencil.setConfig(PEId, stencilConfig);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s|PE_%d_t%d| starting stencil kernel PE\n", __func__, PEId, SUB_TILE_ID);
#endif

    stencil.stencilRun(
            arg0_u_rd_buffer,
            arg0_l_rd_buffer,
            arg1_u_wr_buffer,
            arg1_l_wr_buffer
);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s|PE_%d_t%d| Ending stencil kernel PE\n", __func__, PEId, SUB_TILE_ID);
#endif
} 

static void hls_1024_2x_to_256_8x(::hls::stream<ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0_half>> &in_l, ::hls::stream<ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0_half>> &in_u,
    ::hls::stream<pe_hls_arg0_dt>& out_0,
    ::hls::stream<pe_hls_arg0_dt>& out_1,
    ::hls::stream<pe_hls_arg0_dt>& out_2,
    ::hls::stream<pe_hls_arg0_dt>& out_3,
    ::hls::stream<pe_hls_arg0_dt>& out_4,
    ::hls::stream<pe_hls_arg0_dt>& out_5,
    ::hls::stream<pe_hls_arg0_dt>& out_6,
    ::hls::stream<pe_hls_arg0_dt>& out_7,
    const unsigned int num_pkts
) 
{
    ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0_half> l_dataf, u_dataf, l_data, u_data, l_datab, u_datab;

    unsigned int num_pkts_plus_1 = register_it(num_pkts + 1);

    for (unsigned int itr = 0; itr < num_pkts_plus_1; itr++)
    {
        #pragma HLS PIPELINE II=1

		ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_0_half> tmp0, tmp1;

		bool cond = register_it(itr < num_pkts);
		if(cond){
			tmp0 = in_l.read();
			tmp1 = in_u.read();
		}

		l_datab = l_data;
		u_datab = u_data;

		l_data = l_dataf;
		u_data = u_dataf;

		l_dataf = register_it(tmp0);
		u_dataf = register_it(tmp1);


		if(itr >= 1){
			pe_hls_arg0_dt tmp0_0_0;
			tmp0_0_0.range(287,32) = l_data.range(255,0);
			tmp0_0_0.range(31,0) = u_datab.range(1023,992);

			out_0 << tmp0_0_0;
			out_1 << l_data.range(543,256);

			out_2 << l_data.range(767,480);
			pe_hls_arg0_dt tmp0_1_1;
			tmp0_1_1.range(255,0) = l_data.range(1023,768);
			tmp0_1_1.range(287,256) = u_data.range(31,0);
			out_3 << tmp0_1_1;

			pe_hls_arg0_dt tmp0_0_2;
			tmp0_0_2.range(287,32) = u_data.range(255,0);
			tmp0_0_2.range(31,0) = l_data.range(1023,992);
			out_4 << tmp0_0_2;
			out_5 << u_data.range(543,256);

			out_6 << u_data.range(767,480);
			pe_hls_arg0_dt tmp0_1_3;
			tmp0_1_3.range(255,0) = u_data.range(1023,768);
			tmp0_1_3.range(287,256) = l_dataf.range(31,0);
			out_7 << tmp0_1_3;
        }
    }

    // printf("[DEBUG][INTERNAL][%s] Exit\n", __func__);
}


static void fifo288_8_2axis(::hls::stream <pe_hls_arg1_dt> &in0_0, hls::stream <pe_hls_arg1_dt> &in1_0,
		hls::stream <pe_hls_arg1_dt> &in0_1, hls::stream <pe_hls_arg1_dt> &in1_1,
		hls::stream <pe_hls_arg1_dt> &in0_2, hls::stream <pe_hls_arg1_dt> &in1_2,
		hls::stream <pe_hls_arg1_dt> &in0_3, hls::stream <pe_hls_arg1_dt> &in1_3,
		hls::stream<ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half>> &out_0, hls::stream<ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half>> &out_1, unsigned int total_itr){

	for (unsigned int itr = 0; itr < total_itr; itr++){
		#pragma HLS PIPELINE II=1

		ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half> tmp0, tmp1;
		ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half> l_data, u_data;
		
        // printf("[DEBUG][INTERNAL][%s] --------------------------------------------------------\n\n", __func__);

        pe_hls_arg1_dt tmp_0 = in0_0.read();
		pe_hls_arg1_dt tmp_1 = in1_0.read();
		pe_hls_arg1_dt tmp_2 = in0_1.read();
		pe_hls_arg1_dt tmp_3 = in1_1.read();
        pe_hls_arg1_dt tmp_4 = in0_2.read();
		pe_hls_arg1_dt tmp_5 = in1_2.read();
		pe_hls_arg1_dt tmp_6 = in0_3.read();
		pe_hls_arg1_dt tmp_7 = in1_3.read();

        
        // printf("[DEBUG][INTERNAL][%s] Read Values \n     tmp0: (", __func__);
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_0.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp1: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_1.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp2: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_2.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp3: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_3.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp4: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_4.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp5: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_5.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp6: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_6.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp7: (");
        // for (int ri = 0; ri < 9; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp_7.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");


        l_data.range(255,0) = tmp_0.range(287,32);
		l_data.range(511,256) = tmp_1.range(255,0);
		l_data.range(767,512) = tmp_2.range(287,32);
		l_data.range(1023,768) = tmp_3.range(255,0);

		u_data.range(255,0) = tmp_4.range(287,32);
		u_data.range(511,256) = tmp_5.range(255,0);
		u_data.range(767,512) = tmp_6.range(287,32);
		u_data.range(1023,768) = tmp_7.range(255,0);


		tmp0 = register_it <ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half>>(l_data);
		tmp1 = register_it <ap_uint<axis_data_width_l_jac3D_kernel_stencil_test_1_half>>(u_data);

        // printf("[DEBUG][INTERNAL][%s] Write Values \n     tmp0: (", __func__);
        // for (int ri = 0; ri < tile_vector_factor_arg1; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp0.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

        // printf("    tmp1: (", __func__);
        // for (int ri = 0; ri < tile_vector_factor_arg1; ri++)
        // {
        //     ops::hls::DataConv tmpConverter;
        //     tmpConverter.i = tmp1.range((ri + 1)*32 - 1, ri * 32);
        //     printf("%f ", tmpConverter.f);
        // }
        // printf(")\n");

		out_0.write(tmp0);
		out_1.write(tmp1);
	}

    // printf("[DEBUG][INTERNAL][%s] Exit\n", __func__);
}

#endif // __LOOP_PE_JAC3D_KERNEL_STENCIL_
