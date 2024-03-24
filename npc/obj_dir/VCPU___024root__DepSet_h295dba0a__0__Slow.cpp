// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VCPU___024root.h"

VL_ATTR_COLD void VCPU___024root___eval_static(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_static\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_initial(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial\n"); );
    // Body
    VCPU___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] = 4U;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] = 4ULL;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0U] = 2U;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1U] = 1U;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[2U] = 0U;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] = 4U;
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] = 0x200000004ULL;
    vlSelf->MemWrEn = 0U;
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1U] = 0U;
}

VL_ATTR_COLD void VCPU___024root___eval_final(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_final\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_triggers__stl(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_settle(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VCPU___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/CPU.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VCPU___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VCPU___024root____Vdpiimwrap_CPU__DOT__PreDecoder_inst__DOT__npc_trap_TOP();
extern const VlUnpacked<CData/*0:0*/, 16> VCPU__ConstPool__TABLE_hdbd9196c_0;
extern const VlUnpacked<CData/*0:0*/, 16> VCPU__ConstPool__TABLE_ha1b09cb8_0;

VL_ATTR_COLD void VCPU___024root___stl_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((0x73U == vlSelf->Instr)) {
        VCPU___024root____Vdpiimwrap_CPU__DOT__PreDecoder_inst__DOT__npc_trap_TOP();
    }
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = (1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                 [0U]));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = (1U & ((IData)(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
                 | (~ vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                    [1U])));
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = (1U & (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                 [0U]));
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit 
        = (1U & ((IData)(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit) 
                 | (~ vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list
                    [1U])));
    vlSelf->InstrMemRdAddr = vlSelf->CPU__DOT__PC;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1U] 
        = (QData)((IData)(vlSelf->CPU__DOT__PC));
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0U] 
        = (0x100000000ULL | (QData)((IData)(vlSelf->CPU__DOT__PC)));
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
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->MemDATAOut;
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1U] 
        = vlSelf->CPU__DOT__PC;
    vlSelf->CPU__DOT__busA = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0U] 
        = vlSelf->CPU__DOT__PC;
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

VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VCPU___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___ctor_var_reset(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->InstrMemRdAddr = VL_RAND_RESET_I(32);
    vlSelf->Instr = VL_RAND_RESET_I(32);
    vlSelf->MemOper = VL_RAND_RESET_I(1);
    vlSelf->MemWrEn = VL_RAND_RESET_I(1);
    vlSelf->MemAddr = VL_RAND_RESET_I(32);
    vlSelf->MemDATAOut = VL_RAND_RESET_I(32);
    vlSelf->MemDATAIn = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PCAsrc = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__PCBsrc = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__busA = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__busW = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__Zero = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__ALUBsrc = VL_RAND_RESET_I(2);
    vlSelf->CPU__DOT__ALUa = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__ALUb = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__ALUout = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__Decoder_inst__DOT__MemOp__out__strong__out1 = 0;
    vlSelf->CPU__DOT__ImmGen_inst__DOT__immI = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(34);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__ALU_inst__DOT__unnamedblk1__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(33);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
