// Auto-generated at 2026-07-05 14:05:30.106002 by ops-translator

#ifndef __LOOP_PE_JAC3D_KERNEL_STENCIL__
#define __LOOP_PE_JAC3D_KERNEL_STENCIL__
#include <ops_hls_kernel_support.h>
#include "../../common/include/common_config.hpp"

static constexpr unsigned short read_num_points_jac3D_kernel_stencil = 7;
static constexpr unsigned short read_stencil_size_jac3D_kernel_stencil = 3;
static constexpr unsigned short read_stencil_dim_jac3D_kernel_stencil = 3;

static constexpr unsigned short write_num_points_jac3D_kernel_stencil = 1;
static constexpr unsigned short write_stencil_size_jac3D_kernel_stencil = 1;
static constexpr unsigned short write_stencil_dim_jac3D_kernel_stencil = 3;

static constexpr unsigned short adj_vector_factor = vector_factor * 8;
static constexpr unsigned short adj_shift_bits = 5;
static constexpr unsigned short sub_tile_pe_count = 4;
static constexpr unsigned short sub_shift_bits = 2;
static constexpr unsigned short subtile_vector_factor = adj_vector_factor >> sub_shift_bits;
static constexpr unsigned short subtile_full_vector_factor = subtile_vector_factor + 2;
static constexpr unsigned short subtile_full_vector_factor_min_hs = subtile_vector_factor + 1;
static constexpr unsigned short vector_factor_jac3D_kernel_stencil_0 = (vector_factor  * 2 + 2) * 1;
static constexpr unsigned short axis_data_width_jac3D_kernel_stencil_0 = (vector_factor_jac3D_kernel_stencil_0 * data_width);
static constexpr unsigned short axis_data_width_jac3D_kernel_stencil_0_min_1 = axis_data_width_jac3D_kernel_stencil_0 - 1;
typedef ap_uint<axis_data_width_jac3D_kernel_stencil_0> widen_jac3D_kernel_stencil_0_dt;
static constexpr unsigned short half_axis_data_width_jac3D_kernel_stencil_0 = (vector_factor_jac3D_kernel_stencil_0 * data_width) >> 1;
static constexpr unsigned short half_axis_data_width_jac3D_kernel_stencil_0_min_1 = half_axis_data_width_jac3D_kernel_stencil_0 - 1;
typedef ap_uint<half_axis_data_width_jac3D_kernel_stencil_0> half_widen_jac3D_kernel_stencil_0_dt;
static constexpr unsigned short vector_factor_jac3D_kernel_stencil_1 = (vector_factor  * 2 + 2) * 1;
static constexpr unsigned short axis_data_width_jac3D_kernel_stencil_1 = (vector_factor_jac3D_kernel_stencil_1 * data_width);
static constexpr unsigned short axis_data_width_jac3D_kernel_stencil_1_min_1 = axis_data_width_jac3D_kernel_stencil_1 - 1;
typedef ap_uint<axis_data_width_jac3D_kernel_stencil_1> widen_jac3D_kernel_stencil_1_dt;
static constexpr unsigned short half_axis_data_width_jac3D_kernel_stencil_1 = (vector_factor_jac3D_kernel_stencil_1 * data_width) >> 1;
static constexpr unsigned short half_axis_data_width_jac3D_kernel_stencil_1_min_1 = half_axis_data_width_jac3D_kernel_stencil_1 - 1;
typedef ap_uint<half_axis_data_width_jac3D_kernel_stencil_1> half_widen_jac3D_kernel_stencil_1_dt;

typedef ::hls::stream<half_widen_jac3D_kernel_stencil_0_dt> half_widen_stream_jac3D_kernel_stencil_0_dt;
typedef ::hls::stream<half_widen_jac3D_kernel_stencil_1_dt> half_widen_stream_jac3D_kernel_stencil_1_dt;

/*
    ArgDat(id=0, loc=/home/x_thileeb/repos/ops-hls-batching-new/codegen_apps/tiling/jacobian3d/u280/maxtile_256_256_P5_V4_VM8_interleave_project/jac3D7pt.cpp/335:21, access_type=AccessType.OPS_READ, opt=True, dat_id=0, global_dat_id=-1, stencil_id=S3D_7PT)
    ArgDat(id=1, loc=/home/x_thileeb/repos/ops-hls-batching-new/codegen_apps/tiling/jacobian3d/u280/maxtile_256_256_P5_V4_VM8_interleave_project/jac3D7pt.cpp/336:21, access_type=AccessType.OPS_WRITE, opt=True, dat_id=1, global_dat_id=-1, stencil_id=S3D_00)
*/
inline void kernel_jac3D_kernel_stencil_core(
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
    printf("[KERNEL_INTERNAL_CORE]|%s| starting kernel core: kernel_jac3D_kernel_stencil_core\n",__func__);
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
    printf("[KERNEL_INTERNAL_CORE]|%s| exiting: kernel_jac3D_kernel_stencil_core\n",__func__);
#endif
}

template <unsigned short NUM_SUB_TILE, unsigned short SUB_TILE_ID>
class Stencil_jac3D_kernel_stencil : public ops::hls::StencilCoreV2<stencil_type, read_num_points_jac3D_kernel_stencil, subtile_vector_factor, ops::hls::CoefTypes::CONST_COEF,
        read_stencil_size_jac3D_kernel_stencil, read_stencil_dim_jac3D_kernel_stencil, true>
{
    using ops::hls::StencilCoreV2<stencil_type, read_num_points_jac3D_kernel_stencil, subtile_vector_factor, ops::hls::CoefTypes::CONST_COEF,
            read_stencil_size_jac3D_kernel_stencil, read_stencil_dim_jac3D_kernel_stencil, true>::m_stencilConfig;
public:

    void stencilRun(
            half_widen_stream_jac3D_kernel_stencil_0_dt& arg0_l_rd_buffer,
            half_widen_stream_jac3D_kernel_stencil_0_dt& arg0_u_rd_buffer,
            half_widen_stream_jac3D_kernel_stencil_1_dt& arg1_l_wr_buffer,
            half_widen_stream_jac3D_kernel_stencil_1_dt& arg1_u_wr_buffer
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
        // --------- Interleave Subtile related computations ------------
        constexpr bool is_first_sub_tile = (SUB_TILE_ID == 0);
        constexpr bool is_last_sub_tile = (SUB_TILE_ID == (NUM_SUB_TILE - 1));
        constexpr unsigned short sub_tile_id_mul_subtile_vector_factor = SUB_TILE_ID * subtile_vector_factor;
        //---------------------------------------------------------------
        const unsigned short true_tile_size_x = stencilConfig.tile_size[0] << adj_shift_bits;
        // overlap_size = 16, total_PEs = 5 
        // const unsigned short overlap_offset_x = 10;
        const bool is_first_x = stencilConfig.is_first[0] && is_first_sub_tile;
        const bool is_last_x = stencilConfig.is_last[0] && is_last_sub_tile;

        // --------- Interleave Subtile related computations ------------
        const short x_idx_adjust = is_first_x ? -half_span_x : sub_tile_id_mul_subtile_vector_factor - half_span_x;
#ifdef DEBUG_LOG
        printf("[DEBUG][INTERNAL][%s:%d:%d] Interleave Related Parameters\n" \
                "is_first_sub_tile: %d, is_last_sub_tile: %d, sub_tile_id_mul_subtile_vector_factor: %d, x_idx_adjust: %d, \n"
                , __func__, m_PEId, SUB_TILE_ID, is_first_sub_tile, is_last_sub_tile, sub_tile_id_mul_subtile_vector_factor, x_idx_adjust);
#endif
        //---------------------------------------------------------------

        // const unsigned short adj_half_span_x = stencilConfig.tile_count[0] == 1? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_x_lower = is_first_x? half_span_x : half_span_x * (peId + 1);
        const unsigned short adj_half_span_x_upper = is_last_x? half_span_x : half_span_x * (peId + 1);
        //const unsigned short adj_half_span_y = stencilConfig.tile_count[1] == 1? half_span_x : half_span_x * (peId + 1);
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
            WindowBufferDiscriptor(widen_stencil=Stencil(id=-1, dim=3, stencil_ptr='read_stencil_widen', num_points=7, points=[Point(x=1, y=1, z=0), Point(x=1, y=0, z=1), Point(x=0, y=1, z=1), Point(x=1, y=1, z=1), Point(x=2, y=1, z=1), Point(x=1, y=2, z=1), Point(x=1, y=1, z=2)], base_point=Point(x=1, y=1, z=1), stencil_size=Point(x=3, y=3, z=3), d_m=Point(x=-0.5, y=1, z=1), d_p=Point(x=1.0, y=1, z=1), row_discriptors=[StencilRowDiscriptor(row_id=(1, 0), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=1, z=0)]), StencilRowDiscriptor(row_id=(0, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=0, z=1)]), StencilRowDiscriptor(row_id=(1, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=0, y=1, z=1), Point(x=1, y=1, z=1), Point(x=2, y=1, z=1)]), StencilRowDiscriptor(row_id=(2, 1), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=2, z=1)]), StencilRowDiscriptor(row_id=(1, 2), base_point=Point(x=1, y=1, z=1), row_points=[Point(x=1, y=1, z=2)])], stride=[], read_origin_diff=Point(x=0, y=0, z=1)), window_buffers=[WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False), WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False), WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False), WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False)], chains=[(0, WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False)), (1, WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_p0_1', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=0, z=1), write_point=Point(x=1, y=1, z=0), is_read_write_aligned=False), 1), (2, 3), (3, 4), (4, WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_r0_1_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=0, y=1, z=1), write_point=Point(x=1, y=0, z=1), is_read_write_aligned=False), 2), (5, WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False)), (WindowBuffer(name='buf_r1_2_p1', buffer_type=<BufferType.LINE_BUFF: 0>, read_point=Point(x=1, y=2, z=1), write_point=Point(x=2, y=1, z=1), is_read_write_aligned=False), 5), (6, 'read_val'), (WindowBuffer(name='buf_p1_2', buffer_type=<BufferType.PLANE_BUFF: 1>, read_point=Point(x=1, y=1, z=2), write_point=Point(x=1, y=2, z=1), is_read_write_aligned=False), 6)], point_to_widen_map={Point(x=1, y=1, z=0): Point(x=1, y=1, z=0), Point(x=1, y=0, z=1): Point(x=1, y=0, z=1), Point(x=0, y=1, z=1): Point(x=0, y=1, z=1), Point(x=1, y=1, z=1): Point(x=1, y=1, z=1), Point(x=2, y=1, z=1): Point(x=2, y=1, z=1), Point(x=1, y=2, z=1): Point(x=1, y=2, z=1), Point(x=1, y=1, z=2): Point(x=1, y=1, z=2)})
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
            unsigned short S3D_7PT_buf_p0_1_rd = 0;
            constexpr short S3D_7PT_buf_p0_1_rd_const_diff_x = 0;
            // constexpr short S3D_7PT_buf_p0_1_rd_const_diff_x = 0;
            constexpr short S3D_7PT_buf_p0_1_rd_const_diff_y = -1;
            const short S3D_7PT_buf_p0_1_rd_const_diff = S3D_7PT_buf_p0_1_rd_const_diff_y * stencilConfig.tile_size[0] + S3D_7PT_buf_p0_1_rd_const_diff_x;
            const short S3D_7PT_buf_p0_1_rd_const_buf_len_init = plane_diff  + S3D_7PT_buf_p0_1_rd_const_diff;
            const unsigned short S3D_7PT_buf_p0_1_rd_const_buf_len = S3D_7PT_buf_p0_1_rd_const_buf_len_init < 0 ? 0 : S3D_7PT_buf_p0_1_rd_const_buf_len_init;
            // read point: (0,1,1), write point: (1,0,1)
            unsigned short S3D_7PT_buf_r0_1_p1_rd = 0;
            constexpr short S3D_7PT_buf_r0_1_p1_rd_const_diff = -1;
            // constexpr short S3D_7PT_buf_r0_1_p1_rd_const_diff = 0;
            const short S3D_7PT_buf_r0_1_p1_rd_const_buf_len_init = stencilConfig.tile_size[0] - 1  + S3D_7PT_buf_r0_1_p1_rd_const_diff;
            const unsigned short S3D_7PT_buf_r0_1_p1_rd_const_buf_len = S3D_7PT_buf_r0_1_p1_rd_const_buf_len_init < 0 ? 0 : S3D_7PT_buf_r0_1_p1_rd_const_buf_len_init;
            // read point: (1,2,1), write point: (2,1,1)
            unsigned short S3D_7PT_buf_r1_2_p1_rd = 0;
            constexpr short S3D_7PT_buf_r1_2_p1_rd_const_diff = -1;
            // constexpr short S3D_7PT_buf_r1_2_p1_rd_const_diff = 0;
            const short S3D_7PT_buf_r1_2_p1_rd_const_buf_len_init = stencilConfig.tile_size[0] - 1  + S3D_7PT_buf_r1_2_p1_rd_const_diff;
            const unsigned short S3D_7PT_buf_r1_2_p1_rd_const_buf_len = S3D_7PT_buf_r1_2_p1_rd_const_buf_len_init < 0 ? 0 : S3D_7PT_buf_r1_2_p1_rd_const_buf_len_init;
            // read point: (1,1,2), write point: (1,2,1)
            unsigned short S3D_7PT_buf_p1_2_rd = 0;
            constexpr short S3D_7PT_buf_p1_2_rd_const_diff_x = 0;
            // constexpr short S3D_7PT_buf_p1_2_rd_const_diff_x = 0;
            constexpr short S3D_7PT_buf_p1_2_rd_const_diff_y = -1;
            const short S3D_7PT_buf_p1_2_rd_const_diff = S3D_7PT_buf_p1_2_rd_const_diff_y * stencilConfig.tile_size[0] + S3D_7PT_buf_p1_2_rd_const_diff_x;
            const short S3D_7PT_buf_p1_2_rd_const_buf_len_init = plane_diff  + S3D_7PT_buf_p1_2_rd_const_diff;
            const unsigned short S3D_7PT_buf_p1_2_rd_const_buf_len = S3D_7PT_buf_p1_2_rd_const_buf_len_init < 0 ? 0 : S3D_7PT_buf_p1_2_rd_const_buf_len_init;

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
            widen_jac3D_kernel_stencil_0_dt arg0_read_val = 0;
        // arg1(u2)
            widen_jac3D_kernel_stencil_1_dt arg1_update_val;
        // 2
        //  *** widen stencil values holder & window buffers ****

            // arg0(u)
            widen_jac3D_kernel_stencil_0_dt arg0_widenStencilValues[read_num_points_jac3D_kernel_stencil];
            #pragma HLS ARRAY_PARTITION variable = arg0_widenStencilValues dim = 1 complete
            // Max grid_size: (256, 256, 300)
            //tile_size_x = 256, tile_size_y: 256, half_span_x: 0, vector_factor: 8, interleave_div: 4
            widen_jac3D_kernel_stencil_0_dt arg0_buf_p0_1[2048];
            #pragma HLS BIND_STORAGE variable = arg0_buf_p0_1 type = ram_s2p impl = URAM latency=2  
                    // curr SIS_id = 0
                    // next SIS_id = 1
            //tile_size_x = 256, half_span_x: 0, vector_factor: 8, interleave_div: 4
            widen_jac3D_kernel_stencil_0_dt arg0_buf_r0_1_p1[8];
            #pragma HLS BIND_STORAGE variable = arg0_buf_r0_1_p1 type = ram_s2p impl = BRAM latency=2
                    // curr SIS_id = 1
                    // next SIS_id = 0
            //tile_size_x = 256, half_span_x: 0, vector_factor: 8, interleave_div: 4
            widen_jac3D_kernel_stencil_0_dt arg0_buf_r1_2_p1[8];
            #pragma HLS BIND_STORAGE variable = arg0_buf_r1_2_p1 type = ram_s2p impl = BRAM latency=2
                    // curr SIS_id = 0
                    // next SIS_id = 1
            //tile_size_x = 256, tile_size_y: 256, half_span_x: 0, vector_factor: 8, interleave_div: 4
            widen_jac3D_kernel_stencil_0_dt arg0_buf_p1_2[2048];
            #pragma HLS BIND_STORAGE variable = arg0_buf_p1_2 type = ram_s2p impl = URAM latency=2  
                    // curr SIS_id = 1
                    // next SIS_id = 0

            stencil_type arg0_rowArr_1_0[subtile_full_vector_factor + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_0 dim=1 complete
            stencil_type arg0_rowArr_0_1[subtile_full_vector_factor + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_0_1 dim=1 complete
            stencil_type arg0_rowArr_1_1[subtile_full_vector_factor + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_1 dim=1 complete
            stencil_type arg0_rowArr_2_1[subtile_full_vector_factor + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_2_1 dim=1 complete
            stencil_type arg0_rowArr_1_2[subtile_full_vector_factor + span_x];
            #pragma HLS ARRAY_PARTITION variable = arg0_rowArr_1_2 dim=1 complete

            const short cond_x_val = stencilConfig.tile_size[0] - 1; 
            const short cond_y_val = stencilConfig.tile_size[1]  - 1;
            const short cond_z_val = stencilConfig.outer_loop_limit - 1;

#ifdef DEBUG_LOG
             printf("[DEBUG][INTERNAL][%s:%d:%d] initial values, "\
                "tile_size_x(%d), tile_size_y:(%d), grid_size_z:(%d), "\ 
                "iter_limit(%d), stencilConfig.outer_loop_limit:%d \n",
                __func__,m_PEId,
                SUB_TILE_ID, 
                stencilConfig.tile_size[0], stencilConfig.tile_size[1], stencilConfig.tile_size[2],

                iter_limit, stencilConfig.outer_loop_limit);
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
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] loop params before update i(%d), "\
                        "j(%d), "\
                        "k(%d), "\
                        "S3D_7PT_buf_p0_1_rd: %d, "\
                        "S3D_7PT_buf_r0_1_p1_rd: %d, "\
                        "S3D_7PT_buf_r1_2_p1_rd: %d, "\
                        "S3D_7PT_buf_p1_2_rd: %d, "\
                        "S3D_7PT_buf_p0_1_rd_cont_buf_len: %d, "\
                        "S3D_7PT_buf_r0_1_p1_rd_cont_buf_len: %d, "\
                        "S3D_7PT_buf_r1_2_p1_rd_cont_buf_len: %d, "\
                        "S3D_7PT_buf_p1_2_rd_cont_buf_len: %d, "\
                        "reg_itr(%d)\n", m_PEId, SUB_TILE_ID,  i, 
                        j,
                        k,
                        S3D_7PT_buf_p0_1_rd, 
                        S3D_7PT_buf_r0_1_p1_rd, 
                        S3D_7PT_buf_r1_2_p1_rd, 
                        S3D_7PT_buf_p1_2_rd, 
                        S3D_7PT_buf_p0_1_rd_const_buf_len, 
                        S3D_7PT_buf_r0_1_p1_rd_const_buf_len, 
                        S3D_7PT_buf_r1_2_p1_rd_const_buf_len, 
                        S3D_7PT_buf_p1_2_rd_const_buf_len, 
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
                        arg0_read_val.range(half_axis_data_width_jac3D_kernel_stencil_0_min_1, 0) = arg0_l_rd_buffer.read();
                        arg0_read_val.range(axis_data_width_jac3D_kernel_stencil_0_min_1, half_axis_data_width_jac3D_kernel_stencil_0) = arg0_u_rd_buffer.read();
                    }

                    /*if (read_cond)
                    {
                        arg0_read_val = arg0_rd_buffer.read();
                    }*/

                    arg0_widenStencilValues[0] = arg0_buf_p0_1[S3D_7PT_buf_p0_1_rd];                
                    arg0_widenStencilValues[1] = arg0_buf_r0_1_p1[S3D_7PT_buf_r0_1_p1_rd];                
                    arg0_buf_p0_1[S3D_7PT_buf_p0_1_rd] = arg0_widenStencilValues[1];                
                    arg0_widenStencilValues[2] = arg0_widenStencilValues[3];                
                    arg0_widenStencilValues[3] = arg0_widenStencilValues[4];                
                    arg0_widenStencilValues[4] = arg0_buf_r1_2_p1[S3D_7PT_buf_r1_2_p1_rd];                
                    arg0_buf_r0_1_p1[S3D_7PT_buf_r0_1_p1_rd] = arg0_widenStencilValues[2];                
                    arg0_widenStencilValues[5] = arg0_buf_p1_2[S3D_7PT_buf_p1_2_rd];                
                    arg0_buf_r1_2_p1[S3D_7PT_buf_r1_2_p1_rd] = arg0_widenStencilValues[5];                
                    arg0_widenStencilValues[6] = arg0_read_val;                
                    arg0_buf_p1_2[S3D_7PT_buf_p1_2_rd] = arg0_widenStencilValues[6];

                    bool cond_end_of_line_buff_S3D_7PT_buf_p0_1_rd = S3D_7PT_buf_p0_1_rd >= S3D_7PT_buf_p0_1_rd_const_buf_len;

                    if (cond_end_of_line_buff_S3D_7PT_buf_p0_1_rd)
                        S3D_7PT_buf_p0_1_rd = 0;
                    else
                        S3D_7PT_buf_p0_1_rd++;

                    bool cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_rd = S3D_7PT_buf_r0_1_p1_rd >= S3D_7PT_buf_r0_1_p1_rd_const_buf_len;

                    if (cond_end_of_line_buff_S3D_7PT_buf_r0_1_p1_rd)
                        S3D_7PT_buf_r0_1_p1_rd = 0;
                    else
                        S3D_7PT_buf_r0_1_p1_rd++;

                    bool cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_rd = S3D_7PT_buf_r1_2_p1_rd >= S3D_7PT_buf_r1_2_p1_rd_const_buf_len;

                    if (cond_end_of_line_buff_S3D_7PT_buf_r1_2_p1_rd)
                        S3D_7PT_buf_r1_2_p1_rd = 0;
                    else
                        S3D_7PT_buf_r1_2_p1_rd++;
                    bool cond_end_of_line_buff_S3D_7PT_buf_p1_2_rd = S3D_7PT_buf_p1_2_rd >= S3D_7PT_buf_p1_2_rd_const_buf_len;

                    if (cond_end_of_line_buff_S3D_7PT_buf_p1_2_rd)
                        S3D_7PT_buf_p1_2_rd = 0;
                    else
                        S3D_7PT_buf_p1_2_rd++;

    #ifdef DEBUG_LOG
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] loop params after update i: %d, "\
                                    "j: %d, "\
                                    "k: %d, "\
                                    "S3D_7PT_buf_p0_1_rd(%d), "\
                                    "S3D_7PT_buf_r0_1_p1_rd(%d), "\
                                    "S3D_7PT_buf_r1_2_p1_rd(%d), "\
                                    "S3D_7PT_buf_p1_2_rd(%d), "\
                                    "S3D_7PT_buf_p0_1_rd_const_buf_len: %d, "\
                                    "S3D_7PT_buf_r0_1_p1_rd_const_buf_len: %d, "\
                                    "S3D_7PT_buf_r1_2_p1_rd_const_buf_len: %d, "\
                                    "S3D_7PT_buf_p1_2_rd_const_buf_len: %d, "\
                                    "reg_itr: %d\n", m_PEId, SUB_TILE_ID, i, 
                                    j,
                                    k,
                                    S3D_7PT_buf_p0_1_rd,  
                                    S3D_7PT_buf_r0_1_p1_rd,  
                                    S3D_7PT_buf_r1_2_p1_rd,  
                                    S3D_7PT_buf_p1_2_rd,  
                                    S3D_7PT_buf_p0_1_rd_const_buf_len,  
                                    S3D_7PT_buf_r0_1_p1_rd_const_buf_len,  
                                    S3D_7PT_buf_r1_2_p1_rd_const_buf_len,  
                                    S3D_7PT_buf_p1_2_rd_const_buf_len,  
                                    reg_itr);

                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] --------------------------------------------------------\n\n", m_PEId, SUB_TILE_ID);

                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] read values arg0: (", m_PEId, SUB_TILE_ID);
                    for (int ri = 0; ri < subtile_full_vector_factor; ri++)
                    {
                        ops::hls::DataConv tmpConverter;
                        tmpConverter.i = arg0_read_val.range((ri + 1)*s_datatype_size - 1, ri * s_datatype_size);

                        printf("%f ", tmpConverter.f);
                    }
                    printf(")\n");
    #endif      
                }

                vec2arr: for (unsigned short x = 0; x < subtile_full_vector_factor; x++)
                {
                #pragma HLS UNROLL factor=subtile_full_vector_factor
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
                    ops::hls::DataConv arg0_tmpConverter_0_1_1_9;
                    arg0_tmpConverter_0_1_1_9.i = arg0_widenStencilValues[2].range(s_datatype_size * (9 + 1) - 1, s_datatype_size * 9);
                    arg0_rowArr_1_1[0] = arg0_tmpConverter_0_1_1_9.f;
                    //diff = 1
                    // access_idx = 11
                    ops::hls::DataConv arg0_tmpConverter_2_1_1_0;
                    arg0_tmpConverter_2_1_1_0.i = arg0_widenStencilValues[4].range(s_datatype_size * (0 + 1) - 1, s_datatype_size * 0);
                    arg0_rowArr_1_1[11] = arg0_tmpConverter_2_1_1_0.f;
                }
                process: for (unsigned short x = half_span_x; x < subtile_full_vector_factor_min_hs; x++)
                {
    #pragma HLS UNROLL factor=subtile_vector_factor
                    short index = (i << adj_shift_bits) + x + x_idx_adjust;
                    bool neg_cond = register_it(             
                            (index < lower_limit_x) 
                            || (index >= upper_limit_x)
                            || (j < lower_limit_y) 
                            || (j >= upper_limit_y)
                            || (k < lower_limit_z) 
                            || (k >= upper_limit_z)
                    );

    #ifdef DEBUG_LOG
                    printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] index=(%d, %d, %d), lowerbound=(%d, %d, %d), upperbound=(%d, %d, %d), neg_cond=%d\n", m_PEId, SUB_TILE_ID, index, j, k,
                                lower_limit_x, lower_limit_y, lower_limit_z, 
                                upper_limit_x, upper_limit_y, upper_limit_z, neg_cond);

    #endif

                    stencil_type arg1_result;

                    kernel_jac3D_kernel_stencil_core(
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

                    if (not neg_cond)
                    {
                        arg1_tmpConvWrite.f = arg1_result;
                    }
                    else
                    {

        // [1, 0]
                //dat_id: 1, dat: u2, swap_id: 0, swap_dat: u
                        arg1_tmpConvWrite.f = arg0_rowArr_1_1[x + 1];
                    }
                // *** rw convertions ***

                    arg1_update_val.range(s_datatype_size * (x + 1) - 1, x * s_datatype_size) = arg1_tmpConvWrite.i;

                }
                process_rest: 
                {
                    ops::hls::DataConv arg1_0_tmpConvWrite;
                    arg1_0_tmpConvWrite.f = arg0_rowArr_1_1[1];
                    arg1_update_val.range(s_datatype_size * 1 - 1, 0 * s_datatype_size) = arg1_0_tmpConvWrite.i;
                    ops::hls::DataConv arg1_9_tmpConvWrite;
                    arg1_9_tmpConvWrite.f = arg0_rowArr_1_1[10];
                    arg1_update_val.range(s_datatype_size * 10 - 1, 9 * s_datatype_size) = arg1_9_tmpConvWrite.i;

                }
                write:
                {
                    bool cond_write = (k >= 0);

                    if (cond_write)
                    {
    #ifdef DEBUG_LOG
                        printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] --------------------------------------------------------\n\n", m_PEId, SUB_TILE_ID);

                        printf("[DEBUG][INTERNAL][jac3D_kernel_stencil_PE_%d:%d] wirte values arg1: (", m_PEId, SUB_TILE_ID);
                        for (int ri = 0; ri < subtile_full_vector_factor; ri++)
                        {
                            ops::hls::DataConv tmpConverter;
                            tmpConverter.i = arg1_update_val.range((ri + 1)*s_datatype_size - 1, ri * s_datatype_size);
                            printf("%f ", tmpConverter.f);
                        }
                        printf(")\n");
    #endif
                    arg1_l_wr_buffer<< arg1_update_val.range(half_axis_data_width_jac3D_kernel_stencil_1_min_1, 0);
                    arg1_u_wr_buffer<< arg1_update_val.range(axis_data_width_jac3D_kernel_stencil_1_min_1, half_axis_data_width_jac3D_kernel_stencil_1);
                    }
                }
            }
        }
};

template <unsigned short NUM_SUB_TILE, unsigned short SUB_TILE_ID>
static void kernel_jac3D_kernel_stencil_PE(
    const unsigned short& PEId_offset,
    const unsigned short& PEId_i,
    const ops::hls::StencilConfigCoreSingleTile& stencilConfig,
            //u
            half_widen_stream_jac3D_kernel_stencil_0_dt& arg0_l_rd_buffer,
            half_widen_stream_jac3D_kernel_stencil_0_dt& arg0_u_rd_buffer,
            //u2
            half_widen_stream_jac3D_kernel_stencil_1_dt& arg1_l_wr_buffer,
            half_widen_stream_jac3D_kernel_stencil_1_dt& arg1_u_wr_buffer
)
{
    Stencil_jac3D_kernel_stencil<NUM_SUB_TILE, SUB_TILE_ID> stencil;

    short PEId = PEId_offset + PEId_i;

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG][%d:%d]|%s| stencil config gridSize: %d (xblocks), %d, %d\n", PEId, SUB_TILE_ID, __func__, stencilConfig.tile_size[0], stencilConfig.tile_size[1], stencilConfig.tile_size[2]);
#endif

    stencil.setConfig(PEId, stencilConfig);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG][%d:%d]|%s| starting stencil kernel PE\n", PEId, SUB_TILE_ID, __func__);
#endif

    stencil.stencilRun(
            arg0_l_rd_buffer,
            arg0_u_rd_buffer, 
            arg1_l_wr_buffer,
            arg1_u_wr_buffer

);

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG][%d:%d]|%s| Ending stencil kernel PE\n", PEId, SUB_TILE_ID, __func__);
#endif
} 

#endif // __LOOP_PE_JAC3D_KERNEL_STENCIL__
