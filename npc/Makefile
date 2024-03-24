#设置变量
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

# VSRC = ./vsrc/ALU.v
# CSRC = ./csrc/sim_alu.cpp
VSRC = $(wildcard ./vsrc/*.v)
CSRC = $(wildcard ./csrc/main.cpp)
#VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -cc --exe
VERILATOR_FLAGS += -MMD
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --top-module CPU

sim:
	@$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo
	@echo "-- Verilator tracing "
	@echo
	@echo "-- VERILATOR-----------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VSRC) $(CSRC) 
	make -C obj_dir -f VCPU.mk VCPU
	@echo
	@echo "To see waveforms,open waveform.vcd in a waveform viewer"
	@echo 


-include ../Makefile

clean:
	rm -rf obj_dir
