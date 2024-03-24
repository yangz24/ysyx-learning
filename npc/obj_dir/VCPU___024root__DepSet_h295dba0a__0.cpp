// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VCPU___024root.h"

void VCPU___024root____Vdpiimwrap_CPU__DOT__PreDecoder_inst__DOT__npc_trap_TOP();
extern const VlUnpacked<CData/*0:0*/, 16> VCPU__ConstPool__TABLE_hdbd9196c_0;
extern const VlUnpacked<CData/*0:0*/, 16> VCPU__ConstPool__TABLE_ha1b09cb8_0;

VL_INLINE_OPT void VCPU___024root___ico_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0x73U == vlSelf->Instr)) {
        VCPU___024root____Vdpiimwrap_CPU__DOT__PreDecoder_inst__DOT__npc_trap_TOP();
    }
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->MemDATAOut)));
    if ((0x100U != (0x7c0U & ((0x7f0U & (vlSelf->Instr 
                                         << 4U)) | 
                              ((0xeU & (vlSelf->Instr 
                                        >> 0xbU)) | 
                               (1U & (vlSelf->Instr 
                                      >> 0x1eU))))))) {
        vlSelf->CPU__DOT__Decoder_inst__DOT__MemOp__out__strong__out1 = 0U;
    }
    vlSelf->MemDATAIn = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0x14U))];
    vlSelf->CPU__DOT__busA = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->MemDATAOut;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[2U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0x14U))];
    vlSelf->CPU__DOT__ALUBsrc = ((0x100U == (0x7c0U 
                                             & ((0x7f0U 
                                                 & (vlSelf->Instr 
                                                    << 4U)) 
                                                | ((0xeU 
                                                    & (vlSelf->Instr 
                                                       >> 0xbU)) 
                                                   | (1U 
                                                      & (vlSelf->Instr 
                                                         >> 0x1eU))))))
                                  ? 1U : 0U);
    vlSelf->CPU__DOT__ImmGen_inst__DOT__immI = (((- (IData)(
                                                            (vlSelf->Instr 
                                                             >> 0x1fU))) 
                                                 << 0xcU) 
                                                | (vlSelf->Instr 
                                                   >> 0x14U));
    vlSelf->MemOper = vlSelf->CPU__DOT__Decoder_inst__DOT__MemOp__out__strong__out1;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[2U] 
        = (QData)((IData)(vlSelf->MemDATAIn));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__busA)));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__busA));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                             [0U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                                [1U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__ALUa = vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__ALUBsrc) == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__ALUBsrc) == 
              vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__ALUBsrc) == 
              vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__ImmGen_inst__DOT__immI)));
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__ImmGen_inst__DOT__immI)));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__ImmGen_inst__DOT__immI;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__ImmGen_inst__DOT__immI;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                       == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                          == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                          == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->CPU__DOT__ALUb = vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__ALUout = (vlSelf->CPU__DOT__ALUa 
                                + vlSelf->CPU__DOT__ALUb);
    vlSelf->CPU__DOT__Zero = (0U == vlSelf->CPU__DOT__ALUout);
    vlSelf->MemAddr = vlSelf->CPU__DOT__ALUout;
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__ALUout));
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__ALUout;
    vlSelf->__Vtableidx1 = ((IData)(vlSelf->CPU__DOT__Zero) 
                            << 3U);
    vlSelf->CPU__DOT__PCAsrc = VCPU__ConstPool__TABLE_hdbd9196c_0
        [vlSelf->__Vtableidx1];
    vlSelf->CPU__DOT__PCBsrc = VCPU__ConstPool__TABLE_ha1b09cb8_0
        [vlSelf->__Vtableidx1];
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                             [0U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                                [1U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__busW = vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PCAsrc) == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__PCAsrc) == 
              vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__PCAsrc) 
                       == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__PCAsrc) 
                          == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa = vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PCBsrc) == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__PCBsrc) == 
              vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__PCBsrc) 
                       == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__PCBsrc) 
                          == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb = vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
}

void VCPU___024root___eval_ico(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VCPU___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VCPU___024root___eval_act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_act\n"); );
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__CPU__DOT__RegisterFile_inst__DOT__rf__v1;
    __Vdlyvdim0__CPU__DOT__RegisterFile_inst__DOT__rf__v1 = 0;
    IData/*31:0*/ __Vdlyvval__CPU__DOT__RegisterFile_inst__DOT__rf__v1;
    __Vdlyvval__CPU__DOT__RegisterFile_inst__DOT__rf__v1 = 0;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__RegisterFile_inst__DOT__rf__v1;
    __Vdlyvset__CPU__DOT__RegisterFile_inst__DOT__rf__v1 = 0;
    // Body
    __Vdlyvset__CPU__DOT__RegisterFile_inst__DOT__rf__v1 = 0U;
    if ((0x100U == (0x7c0U & ((0x7f0U & (vlSelf->Instr 
                                         << 4U)) | 
                              ((0xeU & (vlSelf->Instr 
                                        >> 0xbU)) | 
                               (1U & (vlSelf->Instr 
                                      >> 0x1eU))))))) {
        __Vdlyvval__CPU__DOT__RegisterFile_inst__DOT__rf__v1 
            = vlSelf->CPU__DOT__busW;
        __Vdlyvset__CPU__DOT__RegisterFile_inst__DOT__rf__v1 = 1U;
        __Vdlyvdim0__CPU__DOT__RegisterFile_inst__DOT__rf__v1 
            = (0x1fU & (vlSelf->Instr >> 7U));
    }
    vlSelf->CPU__DOT__PC = ((IData)(vlSelf->rst) ? 0x80000000U
                             : (vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa 
                                + vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb));
    vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[0U] = 0U;
    if (__Vdlyvset__CPU__DOT__RegisterFile_inst__DOT__rf__v1) {
        vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[__Vdlyvdim0__CPU__DOT__RegisterFile_inst__DOT__rf__v1] 
            = __Vdlyvval__CPU__DOT__RegisterFile_inst__DOT__rf__v1;
    }
    vlSelf->MemDATAIn = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0x14U))];
    vlSelf->CPU__DOT__busA = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[2U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0x14U))];
    vlSelf->InstrMemRdAddr = vlSelf->CPU__DOT__PC;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__PC));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__PC)));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__PC;
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__PC;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[2U] 
        = (QData)((IData)(vlSelf->MemDATAIn));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__busA)));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__busA));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                             [0U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                                [1U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__ALUa = vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__1(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                       == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                          == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__ALUBsrc) 
                          == vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->CPU__DOT__ALUb = vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__ALUout = (vlSelf->CPU__DOT__ALUa 
                                + vlSelf->CPU__DOT__ALUb);
    vlSelf->CPU__DOT__Zero = (0U == vlSelf->CPU__DOT__ALUout);
    vlSelf->MemAddr = vlSelf->CPU__DOT__ALUout;
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__ALUout));
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__ALUout;
    vlSelf->__Vtableidx1 = ((IData)(vlSelf->CPU__DOT__Zero) 
                            << 3U);
    vlSelf->CPU__DOT__PCAsrc = VCPU__ConstPool__TABLE_hdbd9196c_0
        [vlSelf->__Vtableidx1];
    vlSelf->CPU__DOT__PCBsrc = VCPU__ConstPool__TABLE_ha1b09cb8_0
        [vlSelf->__Vtableidx1];
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                             [0U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)((1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                                [1U])))) & vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__busW = vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PCAsrc) == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__PCAsrc) == 
              vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__PCAsrc) 
                       == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__PCAsrc) 
                          == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa = vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PCBsrc) == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->CPU__DOT__PCBsrc) == 
              vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->CPU__DOT__PCBsrc) 
                       == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
        = (vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out 
           | ((- (IData)(((IData)(vlSelf->CPU__DOT__PCBsrc) 
                          == vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb = vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out;
}

void VCPU___024root___eval_nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VCPU___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        VCPU___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VCPU___024root___eval_triggers__ico(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
void VCPU___024root___eval_triggers__act(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU___024root___eval(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VCPU___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/CPU.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VCPU___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VCPU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VCPU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/CPU.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VCPU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/CPU.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VCPU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VCPU___024root___eval_debug_assertions(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
