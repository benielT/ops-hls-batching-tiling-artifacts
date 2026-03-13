#
# The following environment variables should be predefined:
#
# OPS_INSTALL_PATH
# OPS_COMPILER (gnu,intel,etc)
#

include $(OPS_INSTALL_PATH)/../makefiles/Makefile.common
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.mpi
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.cuda
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.hip
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.hdf5

PLATFORM=xilinx_u280_gen3x16_xdma_1_202211_1
HLS_TARGET_MODE=hw
HLS_JOBS=100
include $(OPS_INSTALL_PATH)/../makefiles/Makefile_hls.mk

HEADERS=jac3D7pt_kernel.h

OPS_FILES=jac3D7pt.cpp

OPS_GENERATED_SUFFIX=_ops

OTHER_FILES=


APP=jac3D7pt
MAIN_SRC=jac3D7pt

OPS_GENERATOR_VERBOSE=1
# OPS_FPGA_ONLY=1 #Enable if building FPGA only mode
OPS_TARGET_CONFIG_FILE= ./config_u280.json

TARGETS=hls #tiled openmp mpi mpi_tiled mpi_openmp cuda mpi_cuda mpi_cuda_tiled hip mpi_hip mpi_hip_tiled ompoffload mpi_ompoffload mpi_ompoffload_tiled sycl mpi_sycl mpi_sycl_tiled openacc mpi_openacc mpi_openacc_tiled

########  PRFOFILE OPTIONS (ONLY ENABLE ONE OPTION) ######

#Enable if wanted to profile
CXXFLAGS += -DPROFILE
#Enable if wanted to power_profile
#CXXFLAGS += -DPOWER_PROFILE

########  VERIFICATION OPTIONS  ######
#Enable if wanted to verify
# CXXFLAGS += -DVERIFICATION

######## ASYN_DISPATCH OPTION ########
#Enable if wanted to use asynchronous dispatch
# CXXFLAGS += -DASYNC_DISPATCH

######## BATCHING OPTION ########
# Enable if wanted to use batching
# CXXFLAGS += -DBATCHING

######## TILING OPTION ########
TILE_SIZE_X=256
TILE_SIZE_Y=256
TILE_BANKS=8
CXXFLAGS += -DOPS_TILING -DOPS_MAXTILESIZE_X=$(TILE_SIZE_X) -DOPS_MAXTILESIZE_Y=$(TILE_SIZE_Y) -DOPS_HLS_ROW_TILES=$(TILE_BANKS)
VPP_FLAGS += -DOPS_TILING -DOPS_MAXTILESIZE_X=$(TILE_SIZE_X) -DOPS_MAXTILESIZE_Y=$(TILE_SIZE_Y) -DOPS_HLS_ROW_TILES=$(TILE_BANKS)
########  DEBUG OPTIONS  ######
#Enable if wanted to debug
#CXXFLAGS += -DDEBUG_LOG
#VPP_FLAGS += -DDEBUG_LOG
# CXXFLAGS += -g
# VPP_FLAGS += -g

#include $(OPS_INSTALL_PATH)/../makefiles/Makefile.c_app_legacy
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.c_app

