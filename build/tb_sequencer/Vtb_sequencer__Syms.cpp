// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_sequencer__pch.h"
#include "Vtb_sequencer.h"
#include "Vtb_sequencer___024root.h"

// FUNCTIONS
Vtb_sequencer__Syms::~Vtb_sequencer__Syms()
{
}

Vtb_sequencer__Syms::Vtb_sequencer__Syms(VerilatedContext* contextp, const char* namep, Vtb_sequencer* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_sequencer.configure(this, name(), "tb_sequencer", "tb_sequencer", -9, VerilatedScope::SCOPE_OTHER);
}
