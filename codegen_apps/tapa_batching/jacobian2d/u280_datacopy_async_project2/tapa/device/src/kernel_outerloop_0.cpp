// Auto-generated at 2026-07-20 03:38:03.157249 by ops-translator
#include <kernel_outerloop_0.hpp>
 

// TAPA PARSER BYPASS COMMENT - DO NOT REMOVE THIS
void joint_PE_0(
        const unsigned short PEId_offset, const unsigned short PEId_i, const unsigned int outer_itr, 
            const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
        const unsigned short stencilConfig_outer_loop_limit,
        const unsigned short stencilConfig_batch_size
,
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& arg0_hls_stream_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& arg1_hls_stream_out
    )
{
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> node2_1_to_node3_0;

    //const unsigned short PEId_offset_i = PEId_offset + i;
    kernel_jac2D_kernel_stencil_PE(
            PEId_offset, PEId_i, outer_itr,
                    stencilConfig_grid_size_0,
        stencilConfig_grid_size_1,
        stencilConfig_dim,
        stencilConfig_total_itr,
        stencilConfig_lower_limit_0,
        stencilConfig_lower_limit_1,
        stencilConfig_upper_limit_0,
        stencilConfig_upper_limit_1,
        stencilConfig_outer_loop_limit,
        stencilConfig_batch_size
,
            arg0_hls_stream_in,
            arg1_hls_stream_out
    );

}

// TAPA PARSER BYPASS COMMENT - DO NOT REMOVE THIS
void axis_to_strm(const unsigned int outer_itr, const unsigned int total_itr,const unsigned short bsize,
        ::tapa::istream<::tapa::vec_t<stencil_type, 8>>& axis_in, 
        ::tapa::ostream<::tapa::vec_t<stencil_type, 8>>& hls_out) {

    unsigned int total_outer_itr = outer_itr * bsize;
#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting axis_to_stream. outer_iter: %d, bsize: %d, total_outer_itr: %d, total_itr: %d \n",__func__, outer_itr, bsize, total_outer_itr, total_itr);
#endif

    for (unsigned int i = 0; i < total_outer_itr; i++) {
        for (unsigned int j = 0; j < total_itr; j++)
        {
            auto data = axis_in.read();
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s| Read itr: %d, trans_id: %d, in_trans val: (",__func__, i, j);
            for (int j = 0; j < vector_factor; j++) {
                printf(" %f,", data[j]);
            }
            printf(")\n");
#endif  
            hls_out.write(data);
        }
    }
}

// TAPA PARSER BYPASS COMMENT - DO NOT REMOVE THIS
void strm_to_axis(const unsigned int outer_itr, const unsigned int total_itr, const unsigned short bsize, 
        ::tapa::istream<::tapa::vec_t<stencil_type,8>>& hls_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type,8>>& axis_out) {
    unsigned int total_outer_itr = outer_itr * bsize;

#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s| Starting axis_to_stream. outer_iter: %d, bsize: %d, total_outer_itr: %d, total_itr: %d \n",__func__, outer_itr, bsize, total_outer_itr, total_itr);
#endif
    for (unsigned int i = 0; i < total_outer_itr; i++) {
        for (unsigned int j = 0; j < total_itr; j++)
        {
            auto data = hls_in.read();
            axis_out.write(data);
#ifdef DEBUG_LOG
        printf("[KERNEL_DEBUG]|%s| write itr: %d, trans_id: %d, trans val: (",__func__, i, j);
        for (int j = 0; j < vector_factor; j++) {
            printf(" %f,", data[j]);
        }
        printf(")\n");
#endif
        }
    }    
}



void kernel_outerloop_0(        const unsigned short slr_region,
        const unsigned int outer_itr,
                const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_dim,
        const unsigned int stencilConfig_total_itr,
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
        const unsigned short stencilConfig_outer_loop_limit,
        const unsigned short stencilConfig_batch_size
,
    //u
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& arg0_axis_in,
    //u2
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& arg1_axis_out
)
{
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 8, 4096> arg0_in_intl_strm("ker0_arg0_in_intl_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 8, 4096> arg1_out_intl_strm("ker0_arg1_out_intl_strm");
    
    //iter_par_factor PE-PE connections

    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_0_1_strm("ker0_arg0_1_PE_0_1_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_1_2_strm("ker0_arg0_1_PE_1_2_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_2_3_strm("ker0_arg0_1_PE_2_3_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_3_4_strm("ker0_arg0_1_PE_3_4_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_4_5_strm("ker0_arg0_1_PE_4_5_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 12, 4096> arg0_1_PE_5_6_strm("ker0_arg0_1_PE_5_6_strm");


    ::tapa::task()
        .invoke(axis_to_strm, outer_itr, stencilConfig_total_itr, stencilConfig_batch_size, 
                arg0_axis_in,
                arg0_in_intl_strm
        )
        .invoke(joint_PE_0, slr_region, 0, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_in_intl_strm,
                arg0_1_PE_0_1_strm
        )
        .invoke(joint_PE_0, slr_region, 1, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_0_1_strm,
                arg0_1_PE_1_2_strm
        )
        .invoke(joint_PE_0, slr_region, 2, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_1_2_strm,
                arg0_1_PE_2_3_strm
        )
        .invoke(joint_PE_0, slr_region, 3, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_2_3_strm,
                arg0_1_PE_3_4_strm
        )
        .invoke(joint_PE_0, slr_region, 4, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_3_4_strm,
                arg0_1_PE_4_5_strm
        )
        .invoke(joint_PE_0, slr_region, 5, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_4_5_strm,
                arg0_1_PE_5_6_strm
        )
        .invoke(joint_PE_0, slr_region, 6, outer_itr,
                stencilConfig_grid_size_0,
                stencilConfig_grid_size_1,
                stencilConfig_dim,
                stencilConfig_total_itr,
                stencilConfig_lower_limit_0,
                stencilConfig_lower_limit_1,
                stencilConfig_upper_limit_0,
                stencilConfig_upper_limit_1,
                stencilConfig_outer_loop_limit,
                stencilConfig_batch_size,
                arg0_1_PE_5_6_strm,
                arg1_out_intl_strm
        )
        .invoke(strm_to_axis, outer_itr, stencilConfig_total_itr, stencilConfig_batch_size,
                arg1_out_intl_strm,
                arg1_axis_out
        );
}
