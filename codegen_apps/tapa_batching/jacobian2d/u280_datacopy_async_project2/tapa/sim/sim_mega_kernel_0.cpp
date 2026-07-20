// Auto-generated at 2026-07-20 03:38:03.241902 by ops-translator
#include <sim_mega_kernel_0.hpp>

void sim_mega_kernel_0(const unsigned int num_beats,
        const unsigned int num_of_axis_trans,
        const unsigned int num_beats_per_b,
        const unsigned int num_axis_trans_per_b,
        const unsigned int loopback_itr,
        const unsigned int outer_itr,
        const unsigned short stencilConfig_grid_size_0,
        const unsigned short stencilConfig_grid_size_1,
        const unsigned short stencilConfig_dim,
        const unsigned short stencilConfig_total_itr,
        const unsigned short stencilConfig_lower_limit_0,
        const unsigned short stencilConfig_lower_limit_1,
        const unsigned short stencilConfig_upper_limit_0,
        const unsigned short stencilConfig_upper_limit_1,
        const unsigned short stencilConfig_outer_loop_limit,
        const unsigned short stencilConfig_batch_size,
    //u
        ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg0,
    //u2
        ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg1
)

{
    //u
        ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 128, 4096> arg0_axis_in_strm("supper_arg0_axis_in_strm");
    //u2
        ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 128, 4096> arg1_axis_out_strm("supper_arg1_axis_out_strm");
        ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 128, 4096> arg0_arg1_SLR_inter_0_1("supper_arg0_arg1_SLR_inter_0_1");
        ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 128, 4096> arg0_arg1_SLR_inter_1_2("supper_arg0_arg1_SLR_inter_1_2");

        ::tapa::task()
            .invoke(
                    kernel_outerloop_0,
                    0,
                    outer_itr,
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
                //u
                    arg0_axis_in_strm,
                //u2
                    arg0_arg1_SLR_inter_0_1
            )
            .invoke(
                    kernel_outerloop_0,
                    1,
                    outer_itr,
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
                //u
                    arg0_arg1_SLR_inter_0_1,
                //u2
                    arg0_arg1_SLR_inter_1_2
            )
            .invoke(
                    kernel_outerloop_0,
                    2,
                    outer_itr,
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
                //u
                    arg0_arg1_SLR_inter_1_2,
                //u2
                    arg1_axis_out_strm
            )
        .invoke(datamover_outerloop_0, num_beats, num_of_axis_trans, num_beats_per_b, num_axis_trans_per_b, stencilConfig_batch_size, outer_itr,
        //u
            arg0,
        //u2
            arg1,
        //u
            arg0_axis_in_strm,
        //u2
            arg1_axis_out_strm
    
        );
}
