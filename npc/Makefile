#设置变量
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

VSRC = ./vsrc/top.v
CSRC = ./csrc/main.cpp
#VSRC = $(wildcard ./vsrc/*.v)
#CSRC = $(wildcard ./csrc/*.cpp)
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -cc --exe
#VERILATOR_FLAGS += -MMD
VERILATOR_FLAGS += --trace

sim:
	@$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo
	@echo "-- Verilator tracing "
	@echo
	@echo "-- VERILATOR-----------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VSRC) $(CSRC) 
	make -C obj_dir -f Vtop.mk Vtop
	@echo
	@echo "To see waveforms,open vlt_dump.vcd in a waveform viewer"
	@echo 


-include ../Makefile
