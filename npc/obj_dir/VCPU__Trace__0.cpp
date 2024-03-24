// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCPU__Syms.h"


void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VCPU___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_h30d46aab__0;
    VlWide<3>/*95:0*/ __Vtemp_h90cacd45__0;
    VlWide<3>/*95:0*/ __Vtemp_h8d140931__0;
    VlWide<3>/*95:0*/ __Vtemp_he2583b2f__0;
    VlWide<4>/*127:0*/ __Vtemp_hf6529a5d__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+1,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+2,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit));
        bufp->chgBit(oldp+3,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+4,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+5,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit));
        bufp->chgCData(oldp+6,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+7,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+8,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__key_list[2]),2);
        bufp->chgBit(oldp+9,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+10,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
        bufp->chgBit(oldp+11,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[0]));
        bufp->chgBit(oldp+12,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__key_list[1]));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+13,(vlSelf->CPU__DOT__ImmGen_inst__DOT__immI),32);
        bufp->chgCData(oldp+14,(vlSelf->CPU__DOT__ALUBsrc),2);
        bufp->chgBit(oldp+15,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__hit));
        __Vtemp_h30d46aab__0[0U] = vlSelf->CPU__DOT__ImmGen_inst__DOT__immI;
        __Vtemp_h30d46aab__0[1U] = 9U;
        __Vtemp_h30d46aab__0[2U] = 0U;
        bufp->chgWData(oldp+16,(__Vtemp_h30d46aab__0),66);
        bufp->chgQData(oldp+19,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+21,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+23,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+24,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+25,(vlSelf->CPU__DOT__PCAsrc));
        bufp->chgBit(oldp+26,(vlSelf->CPU__DOT__PCBsrc));
        bufp->chgIData(oldp+27,(vlSelf->CPU__DOT__busA),32);
        bufp->chgIData(oldp+28,(vlSelf->CPU__DOT__busW),32);
        bufp->chgBit(oldp+29,(vlSelf->CPU__DOT__Zero));
        bufp->chgIData(oldp+30,(vlSelf->CPU__DOT__ALUa),32);
        bufp->chgIData(oldp+31,(vlSelf->CPU__DOT__ALUb),32);
        bufp->chgIData(oldp+32,(vlSelf->CPU__DOT__ALUout),32);
        bufp->chgIData(oldp+33,((0x1fU & vlSelf->CPU__DOT__ALUb)),32);
        __Vtemp_h90cacd45__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->CPU__DOT__PC))));
        __Vtemp_h90cacd45__0[1U] = ((vlSelf->CPU__DOT__busA 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->CPU__DOT__PC))) 
                                                       >> 0x20U)));
        __Vtemp_h90cacd45__0[2U] = (vlSelf->CPU__DOT__busA 
                                    >> 0x1fU);
        bufp->chgWData(oldp+34,(__Vtemp_h90cacd45__0),66);
        bufp->chgQData(oldp+37,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+39,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+41,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+42,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+43,(vlSelf->CPU__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
        bufp->chgQData(oldp+44,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+46,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+48,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+49,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+50,(vlSelf->CPU__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
        bufp->chgQData(oldp+51,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),34);
        bufp->chgQData(oldp+53,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),34);
        bufp->chgQData(oldp+55,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[2]),34);
        bufp->chgIData(oldp+57,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+58,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+59,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+60,(vlSelf->CPU__DOT__Mux31MultiBit_inst__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
        bufp->chgIData(oldp+61,(vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa),32);
        bufp->chgIData(oldp+62,(vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb),32);
        bufp->chgIData(oldp+63,((vlSelf->CPU__DOT__PcGen_inst__DOT__ADDa 
                                 + vlSelf->CPU__DOT__PcGen_inst__DOT__ADDb)),32);
        bufp->chgIData(oldp+64,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+65,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst1__DOT__MuxKey_inst__DOT__i0__DOT__hit));
        __Vtemp_h8d140931__0[0U] = (IData)((0x100000000ULL 
                                            | (QData)((IData)(vlSelf->CPU__DOT__busA))));
        __Vtemp_h8d140931__0[1U] = ((vlSelf->CPU__DOT__PC 
                                     << 1U) | (IData)(
                                                      ((0x100000000ULL 
                                                        | (QData)((IData)(vlSelf->CPU__DOT__busA))) 
                                                       >> 0x20U)));
        __Vtemp_h8d140931__0[2U] = (vlSelf->CPU__DOT__PC 
                                    >> 0x1fU);
        bufp->chgWData(oldp+66,(__Vtemp_h8d140931__0),66);
        bufp->chgQData(oldp+69,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[0]),33);
        bufp->chgQData(oldp+71,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__pair_list[1]),33);
        bufp->chgIData(oldp+73,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+74,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+75,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+76,(vlSelf->CPU__DOT__PcGen_inst__DOT__Mux21MultiBit_inst2__DOT__MuxKey_inst__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+77,(vlSelf->CPU__DOT__PC),32);
        bufp->chgIData(oldp+78,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[0]),32);
        bufp->chgIData(oldp+79,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[1]),32);
        bufp->chgIData(oldp+80,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[2]),32);
        bufp->chgIData(oldp+81,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[3]),32);
        bufp->chgIData(oldp+82,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[4]),32);
        bufp->chgIData(oldp+83,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[5]),32);
        bufp->chgIData(oldp+84,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[6]),32);
        bufp->chgIData(oldp+85,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[7]),32);
        bufp->chgIData(oldp+86,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[8]),32);
        bufp->chgIData(oldp+87,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[9]),32);
        bufp->chgIData(oldp+88,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[10]),32);
        bufp->chgIData(oldp+89,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[11]),32);
        bufp->chgIData(oldp+90,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[12]),32);
        bufp->chgIData(oldp+91,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[13]),32);
        bufp->chgIData(oldp+92,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[14]),32);
        bufp->chgIData(oldp+93,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[15]),32);
        bufp->chgIData(oldp+94,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[16]),32);
        bufp->chgIData(oldp+95,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[17]),32);
        bufp->chgIData(oldp+96,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[18]),32);
        bufp->chgIData(oldp+97,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[19]),32);
        bufp->chgIData(oldp+98,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[20]),32);
        bufp->chgIData(oldp+99,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[21]),32);
        bufp->chgIData(oldp+100,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[22]),32);
        bufp->chgIData(oldp+101,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[23]),32);
        bufp->chgIData(oldp+102,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[24]),32);
        bufp->chgIData(oldp+103,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[25]),32);
        bufp->chgIData(oldp+104,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[26]),32);
        bufp->chgIData(oldp+105,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[27]),32);
        bufp->chgIData(oldp+106,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[28]),32);
        bufp->chgIData(oldp+107,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[29]),32);
        bufp->chgIData(oldp+108,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[30]),32);
        bufp->chgIData(oldp+109,(vlSelf->CPU__DOT__RegisterFile_inst__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+110,(vlSelf->clk));
    bufp->chgBit(oldp+111,(vlSelf->rst));
    bufp->chgIData(oldp+112,(vlSelf->InstrMemRdAddr),32);
    bufp->chgIData(oldp+113,(vlSelf->Instr),32);
    bufp->chgBit(oldp+114,(vlSelf->MemOper));
    bufp->chgBit(oldp+115,(vlSelf->MemWrEn));
    bufp->chgIData(oldp+116,(vlSelf->MemAddr),32);
    bufp->chgIData(oldp+117,(vlSelf->MemDATAOut),32);
    bufp->chgIData(oldp+118,(vlSelf->MemDATAIn),32);
    bufp->chgCData(oldp+119,((0x1fU & (vlSelf->Instr 
                                       >> 0xfU))),5);
    bufp->chgCData(oldp+120,((0x1fU & (vlSelf->Instr 
                                       >> 0x14U))),5);
    bufp->chgCData(oldp+121,((0x1fU & (vlSelf->Instr 
                                       >> 7U))),5);
    bufp->chgBit(oldp+122,((0x100U == (0x7c0U & ((0x7f0U 
                                                  & (vlSelf->Instr 
                                                     << 4U)) 
                                                 | ((0xeU 
                                                     & (vlSelf->Instr 
                                                        >> 0xbU)) 
                                                    | (1U 
                                                       & (vlSelf->Instr 
                                                          >> 0x1eU))))))));
    bufp->chgCData(oldp+123,((0x7fU & vlSelf->Instr)),7);
    bufp->chgCData(oldp+124,((7U & (vlSelf->Instr >> 0xcU))),3);
    bufp->chgCData(oldp+125,((vlSelf->Instr >> 0x19U)),7);
    bufp->chgIData(oldp+126,((0xfffff000U & vlSelf->Instr)),32);
    bufp->chgIData(oldp+127,((((- (IData)((vlSelf->Instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->Instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->Instr 
                                                 >> 7U))))),32);
    bufp->chgIData(oldp+128,((((- (IData)((vlSelf->Instr 
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
    bufp->chgIData(oldp+129,((((- (IData)((vlSelf->Instr 
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
    bufp->chgWData(oldp+130,(__Vtemp_he2583b2f__0),66);
    __Vtemp_hf6529a5d__0[0U] = 4U;
    __Vtemp_hf6529a5d__0[1U] = (2U | (vlSelf->CPU__DOT__ImmGen_inst__DOT__immI 
                                      << 2U));
    __Vtemp_hf6529a5d__0[2U] = (4U | ((vlSelf->MemDATAIn 
                                       << 4U) | (vlSelf->CPU__DOT__ImmGen_inst__DOT__immI 
                                                 >> 0x1eU)));
    __Vtemp_hf6529a5d__0[3U] = (vlSelf->MemDATAIn >> 0x1cU);
    bufp->chgWData(oldp+133,(__Vtemp_hf6529a5d__0),102);
}

void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_cleanup\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
