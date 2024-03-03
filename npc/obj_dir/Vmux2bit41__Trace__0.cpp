// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux2bit41__Syms.h"


void Vmux2bit41___024root__trace_chg_sub_0(Vmux2bit41___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmux2bit41___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2bit41___024root__trace_chg_top_0\n"); );
    // Init
    Vmux2bit41___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux2bit41___024root*>(voidSelf);
    Vmux2bit41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmux2bit41___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vmux2bit41___024root__trace_chg_sub_0(Vmux2bit41___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux2bit41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2bit41___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->x0),2);
    bufp->chgCData(oldp+1,(vlSelf->x1),2);
    bufp->chgCData(oldp+2,(vlSelf->x2),2);
    bufp->chgCData(oldp+3,(vlSelf->x3),2);
    bufp->chgCData(oldp+4,(vlSelf->Y),2);
    bufp->chgCData(oldp+5,(vlSelf->F),2);
}

void Vmux2bit41___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux2bit41___024root__trace_cleanup\n"); );
    // Init
    Vmux2bit41___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux2bit41___024root*>(voidSelf);
    Vmux2bit41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
