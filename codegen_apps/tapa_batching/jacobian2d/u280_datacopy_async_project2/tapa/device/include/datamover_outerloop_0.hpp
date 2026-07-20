// Auto-generated at 2026-07-20 03:38:03.150538 by ops-translator


#pragma once
#include <ops_tapa_kernel_support.h>
#include "../../common/include/common_config.hpp"


void datamover_outerloop_0(
        const unsigned int num_beats,
        const unsigned int num_axis_trans,
        const unsigned int num_beats_per_b,
        const unsigned int num_axis_trans_per_b,
        const unsigned short bsize,
        const unsigned int outerloop_itr,
    //u
         ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg0,
    //u2
         ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg1,
        //u
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& arg0_axis_out,
    //u2
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& arg1_axis_in

)
;