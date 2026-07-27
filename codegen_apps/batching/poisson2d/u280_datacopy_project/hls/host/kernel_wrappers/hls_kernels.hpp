// Auto-generated at 2026-07-24 21:22:43.630300 by ops-translator

#pragma once

#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <ops_hls_rt_support.h>

extern float dx;
extern float dy;
extern float dy_2;
extern float dx_2;
extern float dx_2_plus_dy_2_mult_2;
extern float dx_2_dy_2;

// user kernel files
#include "poisson_kernel_populate_kernel.hpp"
#include "poisson_kernel_update_kernel.hpp"
#include "poisson_kernel_initialguess_kernel.hpp"
#include "outerloop_0.hpp"

