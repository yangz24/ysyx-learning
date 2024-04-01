TOPNAME = CPU
# NXDC_FILES = constr/top.nxdc
INC_PATH ?= ./csrc/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert --trace

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# # constraint file
# SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
# $(SRC_AUTO_BIND): $(NXDC_FILES)
# 	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
# CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
# include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

IMG ?=

run: $(BIN)
	@$^ $(IMG)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all clean run




# #设置变量
# ifeq ($(VERILATOR_ROOT),)
# VERILATOR = verilator
# else
# export VERILATOR_ROOT
# VERILATOR = $(VERILATOR_ROOT)/bin/verilator
# endif



# VSRC = $(wildcard ./vsrc/*.v)
# CSRC = $(wildcard ./csrc/*.cpp)

# # VERILATOR_FLAGS += -Wall
# VERILATOR_FLAGS += -cc --exe
# VERILATOR_FLAGS += -MMD
# VERILATOR_FLAGS += --trace
# VERILATOR_FLAGS += --top-module CPU


# INC_PATH = ./csrc/include
# INCFLAGS = $(addprefix -I, $(INC_PATH))
# CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

# sim:
# 	@$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
# 	@echo
# 	@echo "-- Verilator tracing "
# 	@echo
# 	@echo "-- VERILATOR-----------------"
# 	$(VERILATOR) $(VERILATOR_FLAGS) $(VSRC) $(addprefix -CFLAGS , $(CXXFLAGS)) $(CSRC) $(CFLAGS)
# 	make -C obj_dir -f VCPU.mk VCPU
# 	@echo
# 	@echo "To see waveforms,open waveform.vcd in a waveform viewer"
# 	@echo 

# run: sim
# 	./obj_dir/VCPU

# -include ../Makefile

# clean:
# 	rm -rf obj_dir
