// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"

class VCPU__Syms;

class VCPU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(MemOper,0,0);
    VL_OUT8(MemWrEn,0,0);
    CData/*0:0*/ CPU__DOT__PCAsrc;
    CData/*0:0*/ CPU__DOT__PCBsrc;
    CData/*0:0*/ CPU__DOT__Zero;
    CData/*1:0*/ CPU__DOT__ALUBsrc;
    CData/*0:0*/ CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit;
    CData/*0:0*/ CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit;
    CData/*0:0*/ CPU__DOT__Decoder_inst__DOT__MemOp__out__strong__out1;
    CData/*0:0*/ CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit;
    CData/*0:0*/ CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit;
    CData/*0:0*/ CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit;
    CData/*3:0*/ __Vtableidx1;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT(InstrMemRdAddr,31,0);
    VL_IN(Instr,31,0);
    VL_OUT(MemAddr,31,0);
    VL_IN(MemDATAOut,31,0);
    VL_OUT(MemDATAIn,31,0);
    IData/*31:0*/ CPU__DOT__busA;
    IData/*31:0*/ CPU__DOT__busW;
    IData/*31:0*/ CPU__DOT__PC;
    IData/*31:0*/ CPU__DOT__ALUa;
    IData/*31:0*/ CPU__DOT__ALUb;
    IData/*31:0*/ CPU__DOT__ALUout;
    IData/*31:0*/ CPU__DOT__PcGen_inst__DOT__ADDa;
    IData/*31:0*/ CPU__DOT__PcGen_inst__DOT__ADDb;
    IData/*31:0*/ CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    IData/*31:0*/ CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    IData/*31:0*/ CPU__DOT__ImmGen_inst__DOT__immI;
    IData/*31:0*/ CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    IData/*31:0*/ CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    IData/*31:0*/ CPU__DOT__ALU_inst__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*32:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*32:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list;
    VlUnpacked<IData/*31:0*/, 32> CPU__DOT__RegisterFile_inst__DOT__rf;
    VlUnpacked<QData/*32:0*/, 2> CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*33:0*/, 3> CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*1:0*/, 3> CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 3> CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list;
    VlUnpacked<QData/*32:0*/, 2> CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*0:0*/, 2> CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 2> CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU___024root(VCPU__Syms* symsp, const char* v__name);
    ~VCPU___024root();
    VL_UNCOPYABLE(VCPU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
