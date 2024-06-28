TOPNAME = CPU
# INC_PATH变量未定义，则将其赋值为./csrc/include，否则保持原有的值不变。
INC_PATH ?= ./csrc/include
#verilator编译选项
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc   \
				-O3 --x-assign fast --x-initial fast --noassert --trace --trace-fst --trace-threads 2 -I./vsrc/include
#用于存储构建输出文件的目录路径
BUILD_DIR = ./build
#用于存储目标文件的目录路径
OBJ_DIR = $(BUILD_DIR)/obj_dir
#用于存储可执行文件的路径
BIN = $(BUILD_DIR)/$(TOPNAME)
# 定义了一个默认目标规则default，它依赖于BIN变量指定的可执行文件路径。这意味着在执行make命令时，会自动构建BIN指定的可执行文件。
default: $(BIN)
# 用于创建指定路径的文件夹。在这里，它的作用是在构建前确保BUILD_DIR指定的目录存在。mkdir -p命令会创建指定的目录，如果该目录已经存在则不会报错。
$(shell mkdir -p $(BUILD_DIR))

# 源文件
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

# verilator编译规则
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE

LDFLAGS += -lreadline
LDFLAGS += $(shell llvm-config --libs)



ARGS += --diff=/home/ginoyang/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so


$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

IMG ?= 

run: $(BIN)
	@$^  $(ARGS) $(IMG)

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
