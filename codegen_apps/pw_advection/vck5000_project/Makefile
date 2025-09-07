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

# PLATFORM=xilinx_u280_gen3x16_xdma_1_202211_1
PLATFORM=xilinx_vck5000_gen4x8_xdma_2_202210_1
HLS_TARGET_MODE=hw
HLS_JOBS=128
include $(OPS_INSTALL_PATH)/../makefiles/Makefile_hls.mk

HEADERS=pw_advect_kernel.h

OPS_FILES=pw_advect.cpp

OPS_GENERATED_SUFFIX=_ops

OTHER_FILES=


APP=pw_advect3d
MAIN_SRC=pw_advect

# OPS_GENERATOR_VERBOSE=1
# OPS_GENERATOR_DEBUG=1
ifeq ($(PLATFORM),xilinx_u280_gen3x16_xdma_1_202211_1)
OPS_TARGET_CONFIG_FILE= ./config_u280.json #U280 config file not yet available
else
OPS_TARGET_CONFIG_FILE= ./config_vck5000.json
endif


TARGETS=hls
########  PRFOFILE OPTIONS (ONLY ENABLE ONE OPTION) ######

#Enable if wanted to profile
CXXFLAGS += -DPROFILE
#Enable if wanted to power_profile
# CXXFLAGS += -DPOWER_PROFILE

########  VERIIFICATION OPTIONS  ######
#Enable if wanted to verify
#CXXFLAGS += -DVERIFICATION

######## ASYN_DISPATCH OPTION ########
#Enable if wanted to use asynchronous dispatch
# CXXFLAGS += -DASYNC_DISPATCH

######## BATCHING OPTION ########
# Enable if wanted to use batching
CXXFLAGS += -DBATCHING

########  DEBUG OPTIONS  ######
#Enable if wanted to debug
# CXXFLAGS += -DDEBUG_LOG
# VPP_FLAGS += -DDEBUG_LOG

#include $(OPS_INSTALL_PATH)/../makefiles/Makefile.c_app_legacy
include $(OPS_INSTALL_PATH)/../makefiles/Makefile.c_app



