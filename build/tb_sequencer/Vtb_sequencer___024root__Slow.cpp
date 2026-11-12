// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sequencer.h for the primary calling header

#include "Vtb_sequencer__pch.h"
#include "Vtb_sequencer__Syms.h"
#include "Vtb_sequencer___024root.h"

void Vtb_sequencer___024root___ctor_var_reset(Vtb_sequencer___024root* vlSelf);

Vtb_sequencer___024root::Vtb_sequencer___024root(Vtb_sequencer__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_sequencer___024root___ctor_var_reset(this);
}

void Vtb_sequencer___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_sequencer___024root::~Vtb_sequencer___024root() {
}
