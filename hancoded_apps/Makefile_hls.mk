# Defining XSA platforms
XSA_PLATFORMS := vck5000 v80

# Checks for XILINX_VITIS
ifndef XILINX_VITIS
$(error XILINX_VITIS variable is not set. Please set it using "source <Vitis_install_path>/Vitis/<Version>/settings64.sh" and rerun.)
endif

# Checks for XILINX_VITIS
ifndef XILINX_HLS
$(error XILINX_HLS variable is not set. Please set it using "source <Vitis_install_path>/Vitis/<Version>/settings64.sh" and rerun.)
endif

# Checks for XILINX_XRT
ifndef XILINX_XRT
$(error XILINX_XRT variable is not set. Please set it using "source /opt/xilinx/xrt/setup.sh" and rerun.)
endif

# Check PLATFORM 
ifeq ($(PLATFORM),)
ifneq ($(DEVICE),)
$(warning WARNING: DEVICE is deprecated in make command. Please use PLATFORM instead.)
PLATFORM := $(DEVICE)
else
$(error PLATFORM not set. Please set the PLATFORM properly and rerun.)
endif
else
$(info hls platform: $(PLATFORM))
endif

# define OPS_HLS_XSA_PLATFORM if PLATFORM is in XSA_PLATFORMS
$(foreach P,$(XSA_PLATFORMS), \
	$(if $(findstring $(P),$(PLATFORM)), \
		$(eval OPS_HLS_XSA_PLATFORM := 1) \
	) \
)

ifdef OPS_HLS_XSA_PLATFORM
$(info Found XSA platform)
else
$(info Found non XSA platform)
endif

# Check HLS_JOBS
ifeq ($(HLS_JOBS),)
HLS_JOBS = 10
endif

ifeq ($(HLS_TARGET_MODE),sw_emu)
$(info hls mode: SW_EMU)
else ifeq ($(HLS_TARGET_MODE),hw_emu)
$(info hls mode: HW_EMU)
else ifeq ($(HLS_TARGET_MODE),hw)
$(info hls mode: HW)
else
$(error hls build mode is not set: please set HLS_TARGET_MODE=<sw_emu/hw_emu/hw>)
endif

# Set remote IP Cache for faster compilation 
ifndef HLS_IP_CACHE_DIR
	HLS_IP_CACHE_DIR = $(shell pwd)/IP_CACHE
endif
# OPS include paths
# OPS_HLS_DEVICE_INC = -I$(OPS_INSTALL_PATH)/hls/include/device/ -I$(OPS_INSTALL_PATH)/hls/L1/include/
# OPS_HLS_HOST_INC = -I$(OPS_INSTALL_PATH)/c/include/ -I$(OPS_INSTALL_PATH)/hls/include/host/ -I$(OPS_INSTALL_PATH)/hls/ext/xcl2/ -I$(OPS_INSTALL_PATH)/hls/L1/include/ -I$(OPS_INSTALL_PATH)/hls/L2/include/

CC  := gcc
CXX  := g++

ifdef DEBUG
	CCFLAGS   := -O0 -std=c99 -fPIC -Wall -ffloat-store -g
	CXXFLAGS   := -O0 -fPIC -Wall -ffloat-store -g -std=c++11
else
	CCFLAGS   := -O3 -std=c99 -fPIC -Wall -ffloat-store -g -ftree-vectorize -fopenmp
	CXXFLAGS   := -O3 -fPIC -Wall -ffloat-store -g -std=c++11 -fopenmp
endif
CXXLINK := -lstdc++
FMODS   := -J$(F_INC_MOD)
OMPFLAGS := -fopenmp
ifdef THREADED
	THREADING_FLAGS ?= -fopenmp
endif
MPI_LINK = -lmpi_cxx

VPP=v++
VPP_FLAGS= --target $(HLS_TARGET_MODE) --platform $(PLATFORM) --hls.jobs $(HLS_JOBS) --remote_ip_cache $(HLS_IP_CACHE_DIR)
HLS_LDFLAGS= -lxilinxopencl -lpthread -lrt -lstdc++ -L$(XILINX_XRT)/lib/ -Wl,-rpath-link,$(XILINX_XRT)/lib 
HLS_CXXFLAGS= -I$(XILINX_XRT)/include/ -I$(XILINX_VIVADO)/include/ -DVITIS_PLATFORM=$(PLATFORM) -D__USE_XOPEN2K8 -I$(XILINX_HLS)/include/ -fmessage-length=0 

