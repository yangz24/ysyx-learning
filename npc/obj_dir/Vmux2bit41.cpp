// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux2bit41.h"
#include "Vmux2bit41__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux2bit41::Vmux2bit41(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmux2bit41__Syms(contextp(), _vcname__, this)}
    , x0{vlSymsp->TOP.x0}
    , x1{vlSymsp->TOP.x1}
    , x2{vlSymsp->TOP.x2}
    , x3{vlSymsp->TOP.x3}
    , Y{vlSymsp->TOP.Y}
    , F{vlSymsp->TOP.F}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmux2bit41::Vmux2bit41(const char* _vcname__)
    : Vmux2bit41(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmux2bit41::~Vmux2bit41() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmux2bit41___024root___eval_debug_assertions(Vmux2bit41___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux2bit41___024root___eval_static(Vmux2bit41___024root* vlSelf);
void Vmux2bit41___024root___eval_initial(Vmux2bit41___024root* vlSelf);
void Vmux2bit41___024root___eval_settle(Vmux2bit41___024root* vlSelf);
void Vmux2bit41___024root___eval(Vmux2bit41___024root* vlSelf);

void Vmux2bit41::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux2bit41::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux2bit41___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmux2bit41___024root___eval_static(&(vlSymsp->TOP));
        Vmux2bit41___024root___eval_initial(&(vlSymsp->TOP));
        Vmux2bit41___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmux2bit41___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmux2bit41::eventsPending() { return false; }

uint64_t Vmux2bit41::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmux2bit41::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmux2bit41___024root___eval_final(Vmux2bit41___024root* vlSelf);

VL_ATTR_COLD void Vmux2bit41::final() {
    Vmux2bit41___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmux2bit41::hierName() const { return vlSymsp->name(); }
const char* Vmux2bit41::modelName() const { return "Vmux2bit41"; }
unsigned Vmux2bit41::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmux2bit41::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmux2bit41___024root__trace_init_top(Vmux2bit41___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux2bit41___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux2bit41___024root*>(voidSelf);
    Vmux2bit41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmux2bit41___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmux2bit41___024root__trace_register(Vmux2bit41___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux2bit41::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmux2bit41::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmux2bit41___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
