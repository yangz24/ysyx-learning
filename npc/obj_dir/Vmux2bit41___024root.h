// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux2bit41.h for the primary calling header

#ifndef VERILATED_VMUX2BIT41___024ROOT_H_
#define VERILATED_VMUX2BIT41___024ROOT_H_  // guard

#include "verilated.h"

class Vmux2bit41__Syms;

class Vmux2bit41___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(x0,1,0);
    VL_IN8(x1,1,0);
    VL_IN8(x2,1,0);
    VL_IN8(x3,1,0);
    VL_IN8(Y,1,0);
    VL_OUT8(F,1,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmux2bit41__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmux2bit41___024root(Vmux2bit41__Syms* symsp, const char* v__name);
    ~Vmux2bit41___024root();
    VL_UNCOPYABLE(Vmux2bit41___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
