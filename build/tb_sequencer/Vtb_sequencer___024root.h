// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sequencer.h for the primary calling header

#ifndef VERILATED_VTB_SEQUENCER___024ROOT_H_
#define VERILATED_VTB_SEQUENCER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_sequencer__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sequencer___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_sequencer__DOT__clk;
    CData/*0:0*/ tb_sequencer__DOT__rst;
    CData/*1:0*/ tb_sequencer__DOT__imm_class;
    CData/*4:0*/ tb_sequencer__DOT__reg_op;
    CData/*3:0*/ tb_sequencer__DOT__cond;
    CData/*0:0*/ tb_sequencer__DOT__l;
    CData/*0:0*/ tb_sequencer__DOT__z;
    CData/*0:0*/ tb_sequencer__DOT__n;
    CData/*0:0*/ tb_sequencer__DOT__c;
    CData/*0:0*/ tb_sequencer__DOT__v;
    CData/*0:0*/ tb_sequencer__DOT__halted;
    CData/*0:0*/ tb_sequencer__DOT__error;
    CData/*0:0*/ tb_sequencer__DOT__loop_we;
    CData/*0:0*/ tb_sequencer__DOT__dut__DOT__do_ctrl;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_sequencer__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*11:0*/ tb_sequencer__DOT__imm12;
    SData/*11:0*/ tb_sequencer__DOT__pc;
    SData/*15:0*/ tb_sequencer__DOT__shadow;
    SData/*11:0*/ tb_sequencer__DOT__error_code;
    SData/*11:0*/ tb_sequencer__DOT__dut__DOT__pc_next_c;
    IData/*23:0*/ tb_sequencer__DOT__loop_reg;
    IData/*23:0*/ tb_sequencer__DOT__loop_in;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hdd3ed70c__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_sequencer__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_sequencer___024root(Vtb_sequencer__Syms* symsp, const char* v__name);
    ~Vtb_sequencer___024root();
    VL_UNCOPYABLE(Vtb_sequencer___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
