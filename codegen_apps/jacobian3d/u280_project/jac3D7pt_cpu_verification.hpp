/*
* Open source copyright declaration based on BSD open source template:
* http://www.opensource.org/licenses/bsd-license.php
*
* This file is part of the OPS distribution.
*
* Copyright (c) 2013, Mike Giles and others. Please see the AUTHORS file in
* the main source directory for a full list of copyright holders.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
* * The name of Mike Giles may not be used to endorse or promote products
* derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY Mike Giles ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Mike Giles BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/** @Test application for fpga batched temporal blocked jacobian 2D
  * @author Beniel Thileepan, Kamalavasan Kamalakannan
  */

#pragma once

#include <math.h>

#define EPSILON 0.0001
typedef float stencil_type;
extern const unsigned short mem_vector_factor;

void initialise_grid(stencil_type* u, int size[3], int d_m[3], int d_p[3], int range[6], int batch_size)
{
    int grid_size_z = size[2] - d_m[2] + d_p[2];
    int grid_size_y = size[1] - d_m[1] + d_p[1];
#ifdef OPS_FPGA
    int grid_size_x = ((size[0] - d_m[0] + d_p[0] + mem_vector_factor - 1) / mem_vector_factor) * mem_vector_factor;
#else
    int grid_size_x = size[0] - d_m[0] + d_p[0];
#endif
    int actual_size_x = size[0] - d_m[0] + d_p[0];

    for (int bat = 0; bat < batch_size; bat++)
    {
        int offset = bat * grid_size_x * grid_size_y * grid_size_z;

        for (int k = range[4] - d_m[2]; k < range[5] - d_m[2]; k++)
        {
            for (int j = range[2] - d_m[1]; j < range[3] -d_m[1]; j++)
            {
                for (int i = range[0] - d_m[0]; i < range[1] - d_m[0]; i++)
                {
                    int index = k * grid_size_y * grid_size_x + j * grid_size_x + i;
                    if(i == 0 || j == 0 || k == 0 || i == actual_size_x -1  || j==grid_size_y-1 || k==grid_size_y-1)
                    {
                        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                        u[offset + index] = r;
                    } 
                    else 
                    {
                        u[offset + index] = 0;
                    }
                }
            }
        }
    }
}

void stencil_computation(stencil_type* u, stencil_type* u2, int size[3], int d_m[3], int d_p[3], int range[6], int batch_size)
{
    int grid_size_z = size[2] - d_m[2] + d_p[2];
    int grid_size_y = size[1] - d_m[1] + d_p[1];
#ifdef OPS_FPGA
    int grid_size_x = ((size[0] - d_m[0] + d_p[0] + mem_vector_factor - 1) / mem_vector_factor) * mem_vector_factor;
#else
    int grid_size_x = size[0] - d_m[0] + d_p[0];
#endif
    int actual_size_x = size[0] - d_m[0] + d_p[0];

    for (int bat = 0; bat < batch_size; bat++)
    {
        int offset = bat * grid_size_x * grid_size_y * grid_size_z;

        for (int k = range[4] - d_m[2]; k < range[5] - d_m[2]; k++)
        {
            for (int j = range[2] - d_m[1]; j < range[3] -d_m[1]; j++)
            {
                for (int i = range[0] - d_m[0]; i < range[1] - d_m[0]; i++)
                {
                    int index = k * grid_size_y * grid_size_x + j * grid_size_x + i + offset;
                    if(i == 0 || j == 0 || k == 0 || i == actual_size_x -1  || j==grid_size_y-1 || k==grid_size_y-1)
                    {
                    u2[index] = u[index];
                    } 
                    else 
                    {
                        u2[index] = u[(k+1)* grid_size_x * grid_size_y + (j)*grid_size_x + (i)] * (0.02f) + \
                                    u[(k)* grid_size_x * grid_size_y + (j+1)*grid_size_x + (i)] * (0.04f) + \
                                    u[(k)* grid_size_x * grid_size_y + (j)*grid_size_x + (i-1)] * (0.05f) + \
                                    u[(k)* grid_size_x * grid_size_y + (j)*grid_size_x + (i)] * (0.79f) + \
                                    u[(k)* grid_size_x * grid_size_y + (j)*grid_size_x + (i+1)] * (0.06f) + \
                                    u[(k)* grid_size_x * grid_size_y + (j-1)*grid_size_x + (i)] * (0.03f) + \
                                    u[(k-1)* grid_size_x * grid_size_y + (j)*grid_size_x + (i)] * (0.01f);
                    }
                }
            }
        }
    }
}

void copy_grid(stencil_type* u2, stencil_type* u, int size[3], int d_m[3], int d_p[3], int range[6], int batch_size)
{
    int grid_size_z = size[2] - d_m[2] + d_p[2];
    int grid_size_y = size[1] - d_m[1] + d_p[1];
#ifdef OPS_FPGA
    int grid_size_x = ((size[0] - d_m[0] + d_p[0] + mem_vector_factor - 1) / mem_vector_factor) * mem_vector_factor;
#else
    int grid_size_x = size[0] - d_m[0] + d_p[0];
#endif
    int actual_size_x = size[0] - d_m[0] + d_p[0];


    for (int bat = 0; bat < batch_size; bat++)
    {
        int offset = bat * grid_size_x * grid_size_y * grid_size_z;

        for (int k = range[4] - d_m[2]; k < range[5] - d_m[2]; k++)
        {
            for (int j = range[2] - d_m[1]; j < range[3] -d_m[1]; j++)
            {
                for (int i = range[0] - d_m[0]; i < range[1] - d_m[0]; i++)
                {
                    int index = k * grid_size_y * grid_size_x + j * grid_size_x + i;
                    u2[offset + index] = u[offset + index];
                }
            }
        }
    }
}


bool verify(stencil_type * grid_data1, stencil_type *  grid_data2, int size[2], int d_m[2], int d_p[2], int range[4], int batch_size = 1)
{
    bool passed = true;
    int grid_size_z = size[2] - d_m[2] + d_p[2];
    int grid_size_y = size[1] - d_m[1] + d_p[1];
#ifdef OPS_FPGA
    int grid_size_x = ((size[0] - d_m[0] + d_p[0] + mem_vector_factor - 1) / mem_vector_factor) * mem_vector_factor;
#else
    int grid_size_x = size[0] - d_m[0] + d_p[0];
#endif
    int actual_size_x = size[0] - d_m[0] + d_p[0];


    for (int bat = 0; bat < batch_size; bat++)
    {
        int offset = bat * grid_size_x * grid_size_y * grid_size_z;

        for (int k = range[4] - d_m[2]; k < range[5] - d_m[2]; k++)
        {
            for (int j = range[2] - d_m[1]; j < range[3] -d_m[1]; j++)
            {
                for (int i = range[0] - d_m[0]; i < range[1] - d_m[0]; i++)
                {
                    int index = k * grid_size_y * grid_size_x + j * grid_size_x + i + offset;
                    if(i == 0 || j == 0 || k == 0 || i == actual_size_x -1  || j==grid_size_y-1 || k==grid_size_y-1)
                    {
                        if (fabs(grid_data1[index] - grid_data2[index])/(fabs(grid_data1[index]) + fabs(grid_data2[index])) > EPSILON)
                        {
                            std::cerr << "[ERROR] value Mismatch index: (" << i << ", " << j << ", " << k << "), grid_data1: "
                                    << grid_data1[index] << ", and grid_data2: " << grid_data2[index] << std::endl;
                            passed = false;
                        }
                    }
                }
            }
        }
    }

    return passed;
}
