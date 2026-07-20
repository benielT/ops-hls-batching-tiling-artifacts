#pragma once
#include "../device/include/datamover_outerloop_0.hpp"
// Auto-generated at 2026-07-18 03:10:39.347782 by ops-translator



#ifdef LOOPBACK_DESIGN

// TAPA PARSER BYPASS COMMENT - DO NOT REMOVE THIS
void task_stepdown_lb(
        ::tapa::istream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& strm_out,
        const unsigned int num_beats) {

        ops::tapa::stream2streamStepdown<stencil_type, mem_vector_factor, vector_factor>(strm_in, strm_out, num_beats);
}

void task_stepup_lb(
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& strm_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_out,
        const unsigned int num_beats) {

        ops::tapa::stream2streamStepup<stencil_type, vector_factor, mem_vector_factor>(strm_in, strm_out, num_beats);
}

void task_terminate_lb(
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& strm_in,
        const unsigned int num_axis_trans) {
    
        ops::tapa::terminate<stencil_type, vector_factor>(strm_in, num_axis_trans);
}

void task_mem2stream_lb(
#ifdef ASYNC_MOVER
    ::tapa::async_mmap<::tapa::vec_t<stencil_type, mem_vector_factor>>& arg0,
#else
    ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg0,
#endif
    ::tapa::ostream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_out,
    const unsigned int num_beats) 
{
#ifdef ASYNC_MOVER
    ops::tapa::mem2stream<stencil_type, mem_vector_factor, 2>(arg0, strm_out, num_beats);
#else
    ops::tapa::mem2stream_blocking<stencil_type, mem_vector_factor, 1>(arg0, strm_out, num_beats);
#endif
}  

void task_stream2mem_lb(
#ifdef ASYNC_MOVER
    ::tapa::async_mmap<::tapa::vec_t<stencil_type, mem_vector_factor>>& arg1,
#else 
    ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg1,
#endif
    ::tapa::istream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_in,
    const unsigned int num_beats) 
{
#ifdef ASYNC_MOVER
    ops::tapa::stream2mem<stencil_type, mem_vector_factor, 2>(arg1, strm_in, num_beats);
#else
    ops::tapa::stream2mem_blocking<stencil_type, mem_vector_factor, 1>(arg1, strm_in, num_beats);
#endif
}

void hybrid_datamover_router(
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& mem_in,
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& axis_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& axis_out,
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& mem_out,
        const unsigned int num_trans,
        const unsigned int outerloop_itr
#ifdef DEBUG_LOG
        , const char* debg_str = ""
#endif
        )
{
#ifdef DEBUG_LOG
    printf("[KERNEL_DEBUG]|%s|%s| num_trans: %d, outerloop_itr: %d\n", __func__, debg_str, num_trans, outerloop_itr);
#endif
    for (unsigned int itr = 0; itr < outerloop_itr+1; itr++) {
        if (itr == 0 ) {
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s|%s| Initial read from memory\n", __func__, debg_str);
#endif
            for (unsigned int itr = 0; itr < num_trans; itr++) {
                #pragma HLS PIPELINE II=1
                auto data = mem_in.read();
                axis_out.write(data);
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s|%s|read_from_mem| forwarding trans: %d, trans val: (",__func__, debg_str, itr);
                for (int j = 0; j < vector_factor; j++) {
                    printf(" %f,", data[j]);
                }
                printf(")\n");
#endif
            }
        }
        else if (itr == outerloop_itr) {
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s|%s| Final write to memory\n", __func__, debg_str);
#endif
            for (unsigned int itr = 0; itr < num_trans; itr++) {
                #pragma HLS PIPELINE II=1
                auto data = axis_in.read();
                mem_out.write(data);
#ifdef DEBUG_LOG
            printf("[KERNEL_DEBUG]|%s|%s|write_to_mem| forwarding trans: %d, trans val: (",__func__, debg_str, itr);
                for (int j = 0; j < mem_vector_factor; j++) {
                    printf(" %f,", data[j]);
                }
                printf(")\n");
#endif
            }
        }
        else {
            for (unsigned int itr = 0; itr < num_trans; itr++) {
                #pragma HLS PIPELINE II=1
                auto data = axis_in.read();
                axis_out.write(data);
#ifdef DEBUG_LOG
                printf("[KERNEL_DEBUG]|%s|%s|loopback| forwarding iter: %d, trans: %d, trans val: (",__func__, debg_str, itr, itr);
                for (int j = 0; j < vector_factor; j++) {
                    printf(" %f,", data[j]);
                }
                printf(")\n");
#endif
            }
        }
    }
}
#else
// TAPA PARSER BYPASS COMMENT - DO NOT REMOVE THIS
void task_stepdown(
        ::tapa::istream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, vector_factor>>& strm_out,
        const unsigned int num_beats,
        const unsigned int outerloop_itr) {

    for (unsigned int itr = 0; itr < outerloop_itr; itr++)
        ops::tapa::stream2streamStepdown<stencil_type, mem_vector_factor, vector_factor>(strm_in, strm_out, num_beats);
}

void task_stepup(
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& strm_in,
        ::tapa::ostream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_out,
        const unsigned int num_beats,
        const unsigned int outerloop_itr) {

    for (unsigned int itr = 0; itr < outerloop_itr; itr++)
        ops::tapa::stream2streamStepup<stencil_type, vector_factor, mem_vector_factor>(strm_in, strm_out, num_beats);
}

void task_terminate(
        ::tapa::istream<::tapa::vec_t<stencil_type, vector_factor>>& strm_in,
        const unsigned int num_axis_trans,
        const unsigned int outerloop_itr) {
    
    for (unsigned int itr = 0; itr < outerloop_itr; itr++)
        ops::tapa::terminate<stencil_type, vector_factor>(strm_in, num_axis_trans);
}

void task_pingpong_mem2stream(
    #ifdef ASYNC_MOVER
        ::tapa::async_mmap<::tapa::vec_t<stencil_type, mem_vector_factor>>& arg0,
        ::tapa::async_mmap<::tapa::vec_t<stencil_type, mem_vector_factor>>& arg1,
    #else
        ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg0,
        ::tapa::mmap<::tapa::vec_t<stencil_type, mem_vector_factor>> arg1,
    #endif 
        ::tapa::ostream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_out,
        ::tapa::istream<bool>& sync_in,
        const unsigned int num_beats,
        const unsigned int outerloop_itr) {
    
    auto outerloop_itr_by_2 = outerloop_itr >> 1;

    for (unsigned int itr = 0; itr < outerloop_itr_by_2; itr++) {
    #ifdef ASYNC_MOVER
        ops::tapa::mem2stream<stencil_type, mem_vector_factor,2>(arg0, strm_out, num_beats);
        sync_in.read(); 
        ops::tapa::mem2stream<stencil_type, mem_vector_factor,2>(arg1, strm_out, num_beats);
        sync_in.read(); 
    #else
        ops::tapa::mem2stream_blocking<stencil_type, mem_vector_factor, 2>(arg0, strm_out, num_beats);
        sync_in.read(); 
        ops::tapa::mem2stream_blocking<stencil_type, mem_vector_factor, 2>(arg1, strm_out, num_beats);
        sync_in.read();
    #endif
    }
}

void task_pingpong_stream2mem(
    #ifdef ASYNC_MOVER
        ::tapa::async_mmap<::tapa::vec_t<float, mem_vector_factor>>& arg0,
        ::tapa::async_mmap<::tapa::vec_t<float, mem_vector_factor>>& arg1,
    #else
        ::tapa::mmap<::tapa::vec_t<float, mem_vector_factor>> arg0,
        ::tapa::mmap<::tapa::vec_t<float, mem_vector_factor>> arg1,
    #endif
        ::tapa::istream<::tapa::vec_t<stencil_type, mem_vector_factor>>& strm_in,
        ::tapa::ostream<bool>& sync_out,
        const unsigned int num_beats,
        const unsigned int outerloop_itr) {
    
    auto outerloop_itr_by_2 = outerloop_itr >> 1;
    for (unsigned int itr = 0; itr < outerloop_itr_by_2; itr++) {
    #ifdef ASYNC_MOVER
        ops::tapa::stream2mem<stencil_type, mem_vector_factor, 2>(arg1, strm_in, num_beats);    
        sync_out.write(true);
        ops::tapa::stream2mem<stencil_type, mem_vector_factor, 2>(arg0, strm_in, num_beats);
        sync_out.write(true);
    #else
        ops::tapa::stream2mem_blocking<stencil_type, mem_vector_factor, 2>(arg1, strm_in, num_beats);
        sync_out.write(true);
        ops::tapa::stream2mem_blocking<stencil_type, mem_vector_factor, 2>(arg0, strm_in, num_beats);
        sync_out.write(true);
    #endif
    }
}
#endif

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

{
    ::tapa::stream<::tapa::vec_t<stencil_type, mem_vector_factor>, 18, 4096> arg0_read_mem_strm("arg0_read_mem_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, mem_vector_factor>, 18, 4096> arg1_write_mem_strm("arg1_write_mem_strm");

#ifdef LOOPBACK_DESIGN
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 18, 4096> arg0_read_reduced_mem_strm("arg0_read_reduced_mem_strm");
    ::tapa::stream<::tapa::vec_t<stencil_type, vector_factor>, 18, 4096> arg1_write_reduced_mem_strm("datmov_arg1_write_reduced_mem_strm");

    ::tapa::task()
            .invoke(task_mem2stream_lb, arg0, arg0_read_mem_strm, num_beats)
            .invoke(task_stepdown_lb, arg0_read_mem_strm, arg0_read_reduced_mem_strm, num_beats)
            .invoke(hybrid_datamover_router, arg0_read_reduced_mem_strm, arg1_axis_in, arg0_axis_out, arg1_write_reduced_mem_strm, num_axis_trans, outerloop_itr)
            .invoke(task_stepup_lb, arg1_write_reduced_mem_strm, arg1_write_mem_strm, num_beats)
            .invoke(task_stream2mem_lb,  arg1, arg1_write_mem_strm, num_beats)
    ;
#else
    ::tapa::stream<bool, 256> arg0_arg1_sync_strm("datmov_arg0_arg1_sync_strm");

    ::tapa::task()
            .invoke(task_pingpong_mem2stream, arg0, arg1, arg0_read_mem_strm, arg0_arg1_sync_strm, num_beats, outerloop_itr)
            .invoke(task_stepdown, arg0_read_mem_strm, arg0_axis_out, num_beats, outerloop_itr)
            .invoke(task_stepup, arg1_axis_in, arg1_write_mem_strm, num_beats, outerloop_itr)
            .invoke(task_pingpong_stream2mem, arg0, arg1, arg1_write_mem_strm, arg0_arg1_sync_strm, num_beats, outerloop_itr)
    ;
#endif
}
