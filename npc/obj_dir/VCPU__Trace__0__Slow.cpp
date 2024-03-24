// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


VL_ATTR_COLD void VCPU___024root__trace_init_sub__TOP__0(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+111,"clk", false,-1);
    tracep->declBit(c+112,"rst", false,-1);
    tracep->declBus(c+113,"InstrMemRdAddr", false,-1, 31,0);
    tracep->declBus(c+114,"Instr", false,-1, 31,0);
    tracep->declBit(c+115,"MemOper", false,-1);
    tracep->declBit(c+116,"MemWrEn", false,-1);
    tracep->declBus(c+117,"MemAddr", false,-1, 31,0);
    tracep->declBus(c+118,"MemDATAOut", false,-1, 31,0);
    tracep->declBus(c+119,"MemDATAIn", false,-1, 31,0);
    tracep->pushNamePrefix("CPU ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+111,"clk", false,-1);
    tracep->declBit(c+112,"rst", false,-1);
    tracep->declBus(c+113,"InstrMemRdAddr", false,-1, 31,0);
    tracep->declBus(c+114,"Instr", false,-1, 31,0);
    tracep->declBit(c+115,"MemOper", false,-1);
    tracep->declBit(c+116,"MemWrEn", false,-1);
    tracep->declBus(c+117,"MemAddr", false,-1, 31,0);
    tracep->declBus(c+118,"MemDATAOut", false,-1, 31,0);
    tracep->declBus(c+119,"MemDATAIn", false,-1, 31,0);
    tracep->declBit(c+26,"PCAsrc", false,-1);
    tracep->declBit(c+27,"PCBsrc", false,-1);
    tracep->declBus(c+14,"Imm", false,-1, 31,0);
    tracep->declBus(c+28,"busA", false,-1, 31,0);
    tracep->declBus(c+119,"busB", false,-1, 31,0);
    tracep->declBus(c+29,"busW", false,-1, 31,0);
    tracep->declBus(c+78,"PC", false,-1, 31,0);
    tracep->declBus(c+139,"Branch", false,-1, 2,0);
    tracep->declBit(c+140,"Less", false,-1);
    tracep->declBit(c+30,"Zero", false,-1);
    tracep->declBus(c+120,"rs1", false,-1, 4,0);
    tracep->declBus(c+121,"rs2", false,-1, 4,0);
    tracep->declBus(c+122,"rd", false,-1, 4,0);
    tracep->declBit(c+123,"RegWr", false,-1);
    tracep->declBus(c+124,"op", false,-1, 6,0);
    tracep->declBus(c+125,"func3", false,-1, 2,0);
    tracep->declBus(c+126,"func7", false,-1, 6,0);
    tracep->declBus(c+139,"ExtOp", false,-1, 2,0);
    tracep->declBit(c+140,"ALUAsrc", false,-1);
    tracep->declBus(c+15,"ALUBsrc", false,-1, 1,0);
    tracep->declBus(c+141,"ALUctr", false,-1, 3,0);
    tracep->declBit(c+140,"MemtoReg", false,-1);
    tracep->declBit(c+140,"MemWr", false,-1);
    tracep->declBit(c+115,"MemOp", false,-1);
    tracep->declBus(c+31,"ALUa", false,-1, 31,0);
    tracep->declBus(c+32,"ALUb", false,-1, 31,0);
    tracep->declBus(c+33,"ALUout", false,-1, 31,0);
    tracep->pushNamePrefix("ALU_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+31,"A", false,-1, 31,0);
    tracep->declBus(c+32,"B", false,-1, 31,0);
    tracep->declBus(c+141,"ALUctr", false,-1, 3,0);
    tracep->declBit(c+30,"zero", false,-1);
    tracep->declBus(c+33,"ALUout", false,-1, 31,0);
    tracep->declBus(c+34,"shift_amount", false,-1, 31,0);
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+142,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("BranchCond_inst ");
    tracep->declBus(c+139,"Branch", false,-1, 2,0);
    tracep->declBit(c+140,"Less", false,-1);
    tracep->declBit(c+30,"Zero", false,-1);
    tracep->declBit(c+26,"PCAsrc", false,-1);
    tracep->declBit(c+27,"PCBsrc", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Decoder_inst ");
    tracep->declBus(c+124,"op", false,-1, 6,0);
    tracep->declBus(c+125,"func3", false,-1, 2,0);
    tracep->declBus(c+126,"func7", false,-1, 6,0);
    tracep->declBus(c+139,"ExtOp", false,-1, 2,0);
    tracep->declBit(c+123,"RegWr", false,-1);
    tracep->declBit(c+140,"ALUAsrc", false,-1);
    tracep->declBus(c+15,"ALUBsrc", false,-1, 1,0);
    tracep->declBus(c+141,"ALUctr", false,-1, 3,0);
    tracep->declBus(c+139,"Branch", false,-1, 2,0);
    tracep->declBit(c+140,"MemtoReg", false,-1);
    tracep->declBit(c+140,"MemWr", false,-1);
    tracep->declBit(c+115,"MemOp", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ImmGen_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"Instr", false,-1, 31,0);
    tracep->declBus(c+139,"ExtOp", false,-1, 2,0);
    tracep->declBus(c+14,"Imm", false,-1, 31,0);
    tracep->declBus(c+14,"immI", false,-1, 31,0);
    tracep->declBus(c+127,"immU", false,-1, 31,0);
    tracep->declBus(c+128,"immS", false,-1, 31,0);
    tracep->declBus(c+129,"immB", false,-1, 31,0);
    tracep->declBus(c+130,"immJ", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Mux21MultiBit_inst1 ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+28,"in0", false,-1, 31,0);
    tracep->declBus(c+78,"in1", false,-1, 31,0);
    tracep->declBit(c+140,"Sel", false,-1);
    tracep->declBus(c+31,"Dout", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKey_inst ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+31,"out", false,-1, 31,0);
    tracep->declBus(c+140,"key", false,-1, 0,0);
    tracep->declArray(c+35,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+31,"out", false,-1, 31,0);
    tracep->declBus(c+140,"key", false,-1, 0,0);
    tracep->declBus(c+146,"default_out", false,-1, 31,0);
    tracep->declArray(c+35,"lut", false,-1, 65,0);
    tracep->declBus(c+147,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+38+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+42+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+44,"lut_out", false,-1, 31,0);
    tracep->declBit(c+3,"hit", false,-1);
    tracep->declBus(c+148,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("Mux21MultiBit_inst2 ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+33,"in0", false,-1, 31,0);
    tracep->declBus(c+118,"in1", false,-1, 31,0);
    tracep->declBit(c+140,"Sel", false,-1);
    tracep->declBus(c+29,"Dout", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKey_inst ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+29,"out", false,-1, 31,0);
    tracep->declBus(c+140,"key", false,-1, 0,0);
    tracep->declArray(c+131,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+29,"out", false,-1, 31,0);
    tracep->declBus(c+140,"key", false,-1, 0,0);
    tracep->declBus(c+146,"default_out", false,-1, 31,0);
    tracep->declArray(c+131,"lut", false,-1, 65,0);
    tracep->declBus(c+147,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+45+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+4+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+49+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+51,"lut_out", false,-1, 31,0);
    tracep->declBit(c+6,"hit", false,-1);
    tracep->declBus(c+148,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("Mux31MultiBit_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+119,"in0", false,-1, 31,0);
    tracep->declBus(c+14,"in1", false,-1, 31,0);
    tracep->declBus(c+149,"in2", false,-1, 31,0);
    tracep->declBus(c+15,"Sel", false,-1, 1,0);
    tracep->declBus(c+32,"Dout", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKey_inst ");
    tracep->declBus(c+150,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+143,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+32,"out", false,-1, 31,0);
    tracep->declBus(c+15,"key", false,-1, 1,0);
    tracep->declArray(c+134,"lut", false,-1, 101,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+150,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+143,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+32,"out", false,-1, 31,0);
    tracep->declBus(c+15,"key", false,-1, 1,0);
    tracep->declBus(c+146,"default_out", false,-1, 31,0);
    tracep->declArray(c+134,"lut", false,-1, 101,0);
    tracep->declBus(c+151,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declQuad(c+52+i*2,"pair_list", true,(i+0), 33,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 1,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+58+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+61,"lut_out", false,-1, 31,0);
    tracep->declBit(c+16,"hit", false,-1);
    tracep->declBus(c+152,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("PcGen_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+111,"clk", false,-1);
    tracep->declBit(c+112,"rst", false,-1);
    tracep->declBit(c+26,"PCAsrc", false,-1);
    tracep->declBit(c+27,"PCBsrc", false,-1);
    tracep->declBus(c+14,"Imm", false,-1, 31,0);
    tracep->declBus(c+28,"rs1", false,-1, 31,0);
    tracep->declBus(c+78,"PC", false,-1, 31,0);
    tracep->declBus(c+153,"RESET_VAL", false,-1, 31,0);
    tracep->declBus(c+62,"ADDa", false,-1, 31,0);
    tracep->declBus(c+63,"ADDb", false,-1, 31,0);
    tracep->declBus(c+64,"NextPC", false,-1, 31,0);
    tracep->pushNamePrefix("AdderMultiBit_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"A", false,-1, 31,0);
    tracep->declBus(c+63,"B", false,-1, 31,0);
    tracep->declBus(c+64,"Dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("Mux21MultiBit_inst1 ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+149,"in0", false,-1, 31,0);
    tracep->declBus(c+14,"in1", false,-1, 31,0);
    tracep->declBit(c+26,"Sel", false,-1);
    tracep->declBus(c+62,"Dout", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKey_inst ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+62,"out", false,-1, 31,0);
    tracep->declBus(c+26,"key", false,-1, 0,0);
    tracep->declArray(c+17,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+62,"out", false,-1, 31,0);
    tracep->declBus(c+26,"key", false,-1, 0,0);
    tracep->declBus(c+146,"default_out", false,-1, 31,0);
    tracep->declArray(c+17,"lut", false,-1, 65,0);
    tracep->declBus(c+147,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+20+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+10+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+24+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+65,"lut_out", false,-1, 31,0);
    tracep->declBit(c+66,"hit", false,-1);
    tracep->declBus(c+148,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("Mux21MultiBit_inst2 ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+78,"in0", false,-1, 31,0);
    tracep->declBus(c+28,"in1", false,-1, 31,0);
    tracep->declBit(c+27,"Sel", false,-1);
    tracep->declBus(c+63,"Dout", false,-1, 31,0);
    tracep->pushNamePrefix("MuxKey_inst ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+63,"out", false,-1, 31,0);
    tracep->declBus(c+27,"key", false,-1, 0,0);
    tracep->declArray(c+67,"lut", false,-1, 65,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+143,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+144,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+145,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+63,"out", false,-1, 31,0);
    tracep->declBus(c+27,"key", false,-1, 0,0);
    tracep->declBus(c+146,"default_out", false,-1, 31,0);
    tracep->declArray(c+67,"lut", false,-1, 65,0);
    tracep->declBus(c+147,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 2; ++i) {
        tracep->declQuad(c+70+i*2,"pair_list", true,(i+0), 32,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+12+i*1,"key_list", true,(i+0), 0,0);
    }
    for (int i = 0; i < 2; ++i) {
        tracep->declBus(c+74+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+76,"lut_out", false,-1, 31,0);
    tracep->declBit(c+77,"hit", false,-1);
    tracep->declBus(c+148,"i", false,-1, 31,0);
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("PreDecoder_inst ");
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+114,"Instr", false,-1, 31,0);
    tracep->declBus(c+124,"op", false,-1, 6,0);
    tracep->declBus(c+120,"rs1", false,-1, 4,0);
    tracep->declBus(c+121,"rs2", false,-1, 4,0);
    tracep->declBus(c+122,"rd", false,-1, 4,0);
    tracep->declBus(c+125,"func3", false,-1, 2,0);
    tracep->declBus(c+126,"func7", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RegisterFile_inst ");
    tracep->declBus(c+154,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+138,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+111,"Wrclk", false,-1);
    tracep->declBus(c+120,"Ra", false,-1, 4,0);
    tracep->declBus(c+121,"Rb", false,-1, 4,0);
    tracep->declBus(c+122,"Rw", false,-1, 4,0);
    tracep->declBus(c+29,"busW", false,-1, 31,0);
    tracep->declBit(c+123,"RegWr", false,-1);
    tracep->declBus(c+28,"busA", false,-1, 31,0);
    tracep->declBus(c+119,"busB", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+79+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VCPU___024root__trace_init_top(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_top\n"); );
    // Body
    VCPU___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VCPU___024root__trace_register(VCPU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VCPU___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VCPU___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VCPU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCPU___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_h30d46aab__0;
    VlWide<3>/*95:0*/ __Vtemp_h90cacd45__0;
    VlWide<3>/*95:0*/ __Vtemp_h8d140931__0;
    VlWide<3>/*95:0*/ __Vtemp_he2583b2f__0;
    VlWide<4>/*127:0*/ __Vtemp_hf6529a5d__0;
    // Body
    bufp->fullBit(oldp+1,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+2,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+3,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    bufp->fullBit(oldp+4,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+5,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+6,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    bufp->fullCData(oldp+7,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]),2);
    bufp->fullCData(oldp+8,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]),2);
    bufp->fullCData(oldp+9,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[2]),2);
    bufp->fullBit(oldp+10,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+11,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
    bufp->fullBit(oldp+12,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
    bufp->fullBit(oldp+13,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
    bufp->fullIData(oldp+14,(vlSelf->CPU__DOT__ImmGen_inst__DOT__immI),32);
    bufp->fullCData(oldp+15,(vlSelf->CPU__DOT__ALUBsrc),2);
    bufp->fullBit(oldp+16,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    __Vtemp_h30d46aab__0[0U] = vlSelf->CPU__DOT__ImmGen_inst__DOT__immI;
    __Vtemp_h30d46aab__0[1U] = 9U;
    __Vtemp_h30d46aab__0[2U] = 0U;
    bufp->fullWData(oldp+17,(__Vtemp_h30d46aab__0),66);
    bufp->fullQData(oldp+20,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+22,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+24,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+25,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    bufp->fullBit(oldp+26,(vlSelf->CPU__DOT__PCAsrc));
    bufp->fullBit(oldp+27,(vlSelf->CPU__DOT__PCBsrc));
    bufp->fullIData(oldp+28,(vlSelf->CPU__DOT__busA),32);
    bufp->fullIData(oldp+29,(vlSelf->CPU__DOT__busW),32);
    bufp->fullBit(oldp+30,(vlSelf->CPU__DOT__Zero));
    bufp->fullIData(oldp+31,(vlSelf->CPU__DOT__ALUa),32);
    bufp->fullIData(oldp+32,(vlSelf->CPU__DOT__ALUb),32);
    bufp->fullIData(oldp+33,(vlSelf->CPU__DOT__ALUout),32);
    bufp->fullIData(oldp+34,((0x1fU & vlSelf->CPU__DOT__ALUb)),32);
    __Vtemp_h90cacd45__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->CPU__DOT__PC))));
    __Vtemp_h90cacd45__0[1U] = ((vlSelf->CPU__DOT__busA 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->CPU__DOT__PC))) 
                                                   >> 0x20U)));
    __Vtemp_h90cacd45__0[2U] = (vlSelf->CPU__DOT__busA 
                                >> 0x1fU);
    bufp->fullWData(oldp+35,(__Vtemp_h90cacd45__0),66);
    bufp->fullQData(oldp+38,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+40,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+42,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+43,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+44,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
    bufp->fullQData(oldp+45,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+47,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+49,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+50,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+51,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
    bufp->fullQData(oldp+52,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),34);
    bufp->fullQData(oldp+54,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),34);
    bufp->fullQData(oldp+56,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[2]),34);
    bufp->fullIData(oldp+58,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+59,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+60,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+61,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
    bufp->fullIData(oldp+62,(vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa),32);
    bufp->fullIData(oldp+63,(vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb),32);
    bufp->fullIData(oldp+64,((vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa 
                              + vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb)),32);
    bufp->fullIData(oldp+65,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+66,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    __Vtemp_h8d140931__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->CPU__DOT__busA))));
    __Vtemp_h8d140931__0[1U] = ((vlSelf->CPU__DOT__PC 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->CPU__DOT__busA))) 
                                                   >> 0x20U)));
    __Vtemp_h8d140931__0[2U] = (vlSelf->CPU__DOT__PC 
                                >> 0x1fU);
    bufp->fullWData(oldp+67,(__Vtemp_h8d140931__0),66);
    bufp->fullQData(oldp+70,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
    bufp->fullQData(oldp+72,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
    bufp->fullIData(oldp+74,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+75,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+76,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+77,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+78,(vlSelf->CPU__DOT__PC),32);
    bufp->fullIData(oldp+79,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[0]),32);
    bufp->fullIData(oldp+80,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[1]),32);
    bufp->fullIData(oldp+81,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[2]),32);
    bufp->fullIData(oldp+82,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[3]),32);
    bufp->fullIData(oldp+83,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[4]),32);
    bufp->fullIData(oldp+84,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[5]),32);
    bufp->fullIData(oldp+85,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[6]),32);
    bufp->fullIData(oldp+86,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[7]),32);
    bufp->fullIData(oldp+87,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[8]),32);
    bufp->fullIData(oldp+88,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[9]),32);
    bufp->fullIData(oldp+89,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[10]),32);
    bufp->fullIData(oldp+90,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[11]),32);
    bufp->fullIData(oldp+91,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[12]),32);
    bufp->fullIData(oldp+92,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[13]),32);
    bufp->fullIData(oldp+93,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[14]),32);
    bufp->fullIData(oldp+94,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[15]),32);
    bufp->fullIData(oldp+95,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[16]),32);
    bufp->fullIData(oldp+96,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[17]),32);
    bufp->fullIData(oldp+97,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[18]),32);
    bufp->fullIData(oldp+98,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[19]),32);
    bufp->fullIData(oldp+99,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[20]),32);
    bufp->fullIData(oldp+100,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[21]),32);
    bufp->fullIData(oldp+101,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[22]),32);
    bufp->fullIData(oldp+102,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[23]),32);
    bufp->fullIData(oldp+103,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[24]),32);
    bufp->fullIData(oldp+104,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[25]),32);
    bufp->fullIData(oldp+105,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[26]),32);
    bufp->fullIData(oldp+106,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[27]),32);
    bufp->fullIData(oldp+107,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[28]),32);
    bufp->fullIData(oldp+108,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[29]),32);
    bufp->fullIData(oldp+109,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[30]),32);
    bufp->fullIData(oldp+110,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[31]),32);
    bufp->fullBit(oldp+111,(vlSelf->clk));
    bufp->fullBit(oldp+112,(vlSelf->rst));
    bufp->fullIData(oldp+113,(vlSelf->InstrMemRdAddr),32);
    bufp->fullIData(oldp+114,(vlSelf->Instr),32);
    bufp->fullBit(oldp+115,(vlSelf->MemOper));
    bufp->fullBit(oldp+116,(vlSelf->MemWrEn));
    bufp->fullIData(oldp+117,(vlSelf->MemAddr),32);
    bufp->fullIData(oldp+118,(vlSelf->MemDATAOut),32);
    bufp->fullIData(oldp+119,(vlSelf->MemDATAIn),32);
    bufp->fullCData(oldp+120,((0x1fU & (vlSelf->Instr 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+121,((0x1fU & (vlSelf->Instr 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+122,((0x1fU & (vlSelf->Instr 
                                        >> 7U))),5);
    bufp->fullBit(oldp+123,((0x100U == (0x7c0U & ((0x7f0U 
                                                   & (vlSelf->Instr 
                                                      << 4U)) 
                                                  | ((0xeU 
                                                      & (vlSelf->Instr 
                                                         >> 0xbU)) 
                                                     | (1U 
                                                        & (vlSelf->Instr 
                                                           >> 0x1eU))))))));
    bufp->fullCData(oldp+124,((0x7fU & vlSelf->Instr)),7);
    bufp->fullCData(oldp+125,((7U & (vlSelf->Instr 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+126,((vlSelf->Instr >> 0x19U)),7);
    bufp->fullIData(oldp+127,((0xfffff000U & vlSelf->Instr)),32);
    bufp->fullIData(oldp+128,((((- (IData)((vlSelf->Instr 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->Instr 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->Instr 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+129,((((- (IData)((vlSelf->Instr 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0x800U 
                                             & (vlSelf->Instr 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->Instr 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->Instr 
                                                     >> 7U)))))),32);
    bufp->fullIData(oldp+130,((((- (IData)((vlSelf->Instr 
                                            >> 0x1fU))) 
                                << 0x14U) | ((0xff000U 
                                              & vlSelf->Instr) 
                                             | ((0x800U 
                                                 & (vlSelf->Instr 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlSelf->Instr 
                                                      >> 0x14U)))))),32);
    __Vtemp_he2583b2f__0[0U] = (IData)((0x100000000ULL 
                                        | (QData)((IData)(vlSelf->MemDATAOut))));
    __Vtemp_he2583b2f__0[1U] = ((vlSelf->CPU__DOT__ALUout 
                                 << 1U) | (IData)((
                                                   (0x100000000ULL 
                                                    | (QData)((IData)(vlSelf->MemDATAOut))) 
                                                   >> 0x20U)));
    __Vtemp_he2583b2f__0[2U] = (vlSelf->CPU__DOT__ALUout 
                                >> 0x1fU);
    bufp->fullWData(oldp+131,(__Vtemp_he2583b2f__0),66);
    __Vtemp_hf6529a5d__0[0U] = 4U;
    __Vtemp_hf6529a5d__0[1U] = (2U | (vlSelf->CPU__DOT__ImmGen_inst__DOT__immI 
                                      << 2U));
    __Vtemp_hf6529a5d__0[2U] = (4U | ((vlSelf->MemDATAIn 
                                       << 4U) | (vlSelf->CPU__DOT__ImmGen_inst__DOT__immI 
                                                 >> 0x1eU)));
    __Vtemp_hf6529a5d__0[3U] = (vlSelf->MemDATAIn >> 0x1cU);
    bufp->fullWData(oldp+134,(__Vtemp_hf6529a5d__0),102);
    bufp->fullIData(oldp+138,(0x20U),32);
    bufp->fullCData(oldp+139,(0U),3);
    bufp->fullBit(oldp+140,(0U));
    bufp->fullCData(oldp+141,(0U),4);
    bufp->fullIData(oldp+142,(vlSelf->CPU__DOT__ALU_inst__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+143,(2U),32);
    bufp->fullIData(oldp+144,(1U),32);
    bufp->fullIData(oldp+145,(0U),32);
    bufp->fullIData(oldp+146,(0U),32);
    bufp->fullIData(oldp+147,(0x21U),32);
    bufp->fullIData(oldp+148,(2U),32);
    bufp->fullIData(oldp+149,(4U),32);
    bufp->fullIData(oldp+150,(3U),32);
    bufp->fullIData(oldp+151,(0x22U),32);
    bufp->fullIData(oldp+152,(3U),32);
    bufp->fullIData(oldp+153,(0x80000000U),32);
    bufp->fullIData(oldp+154,(5U),32);
}
