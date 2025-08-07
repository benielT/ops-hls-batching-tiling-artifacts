// Auto-generated at 2025-07-28 23:08:00.271981 by ops-translator
#pragma once 
#include <ops_hls_rt_support.h>

void inline kernel_kernel_populate_core(
        float& arg0_0
)
{

  arg0_0 = myfun();

}

void ops_par_loop_kernel_populate(ops::hls::Block dummyBlock, int dim, int* ops_range,
            ops::hls::Grid<float>& arg0
)

{
    ops::hls::AccessRange range;
    opsRange2hlsRange(dim, ops_range, range, arg0.originalProperty);
    constexpr int arg0_0_stencil_offset[] = { 0, 0, 0 };
    getGrid(arg0);

        for (unsigned short j = range.start[1]; j < range.end[1]; j++)
        {
            for (unsigned short i = range.start[0]; i < range.end[0]; i++)
            {
                kernel_kernel_populate_core(
                    arg0.hostBuffer[getOffset(arg0_0_stencil_offset, arg0.originalProperty, i , j)]
                );
            }
        }

    arg0.isHostBufDirty = true;

}
