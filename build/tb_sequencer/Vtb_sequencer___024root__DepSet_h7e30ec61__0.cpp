// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sequencer.h for the primary calling header

#include "Vtb_sequencer__pch.h"
#include "Vtb_sequencer__Syms.h"
#include "Vtb_sequencer___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_sequencer___024root___eval_initial__TOP__Vtiming__0(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    CData/*4:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__0__op;
    __Vtask_tb_sequencer__DOT__step_ctrl__0__op = 0;
    SData/*11:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__0__addr;
    __Vtask_tb_sequencer__DOT__step_ctrl__0__addr = 0;
    CData/*3:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__0__cd;
    __Vtask_tb_sequencer__DOT__step_ctrl__0__cd = 0;
    CData/*4:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__1__op;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__op = 0;
    SData/*11:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__1__addr;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__addr = 0;
    CData/*3:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__1__cd;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__cd = 0;
    CData/*4:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__2__op;
    __Vtask_tb_sequencer__DOT__step_ctrl__2__op = 0;
    SData/*11:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__2__addr;
    __Vtask_tb_sequencer__DOT__step_ctrl__2__addr = 0;
    CData/*3:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__2__cd;
    __Vtask_tb_sequencer__DOT__step_ctrl__2__cd = 0;
    CData/*4:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__3__op;
    __Vtask_tb_sequencer__DOT__step_ctrl__3__op = 0;
    SData/*11:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__3__addr;
    __Vtask_tb_sequencer__DOT__step_ctrl__3__addr = 0;
    CData/*3:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__3__cd;
    __Vtask_tb_sequencer__DOT__step_ctrl__3__cd = 0;
    CData/*4:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__4__op;
    __Vtask_tb_sequencer__DOT__step_ctrl__4__op = 0;
    SData/*11:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__4__addr;
    __Vtask_tb_sequencer__DOT__step_ctrl__4__addr = 0;
    CData/*3:0*/ __Vtask_tb_sequencer__DOT__step_ctrl__4__cd;
    __Vtask_tb_sequencer__DOT__step_ctrl__4__cd = 0;
    // Body
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 0U;
    vlSelf->tb_sequencer__DOT__cond = 0U;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = 0U;
    vlSelf->tb_sequencer__DOT__z = 0U;
    vlSelf->tb_sequencer__DOT__n = 0U;
    vlSelf->tb_sequencer__DOT__c = 0U;
    vlSelf->tb_sequencer__DOT__v = 0U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       63);
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       63);
    vlSelf->tb_sequencer__DOT__rst = 0U;
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       65);
    __Vtask_tb_sequencer__DOT__step_ctrl__0__cd = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__0__addr = 0x10U;
    __Vtask_tb_sequencer__DOT__step_ctrl__0__op = 1U;
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = __Vtask_tb_sequencer__DOT__step_ctrl__0__op;
    vlSelf->tb_sequencer__DOT__cond = __Vtask_tb_sequencer__DOT__step_ctrl__0__cd;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = __Vtask_tb_sequencer__DOT__step_ctrl__0__addr;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       45);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       46);
    if (VL_UNLIKELY((0x10U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:69: Assertion failed in %Ntb_sequencer: JMP: pc=%x, expected 010\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 69, "");
    }
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 1U;
    vlSelf->tb_sequencer__DOT__cond = 1U;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = 0x20U;
    vlSelf->tb_sequencer__DOT__z = 0U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       75);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       75);
    if (VL_UNLIKELY((0x11U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:76: Assertion failed in %Ntb_sequencer: JMP EQ (not taken): pc=%x, expected 011\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 76, "");
    }
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 1U;
    vlSelf->tb_sequencer__DOT__cond = 1U;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = 0x30U;
    vlSelf->tb_sequencer__DOT__z = 1U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       81);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       81);
    if (VL_UNLIKELY((0x30U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:82: Assertion failed in %Ntb_sequencer: JMP EQ (taken): pc=%x, expected 030\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 82, "");
    }
    vlSelf->tb_sequencer__DOT__z = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__cd = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__addr = 0x40U;
    __Vtask_tb_sequencer__DOT__step_ctrl__1__op = 2U;
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = __Vtask_tb_sequencer__DOT__step_ctrl__1__op;
    vlSelf->tb_sequencer__DOT__cond = __Vtask_tb_sequencer__DOT__step_ctrl__1__cd;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = __Vtask_tb_sequencer__DOT__step_ctrl__1__addr;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       45);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       46);
    if (VL_UNLIKELY((0x40U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:87: Assertion failed in %Ntb_sequencer: CALL: pc=%x, expected 040\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 87, "");
    }
    if (VL_UNLIKELY((0x31U != (0xfffU & (IData)(vlSelf->tb_sequencer__DOT__shadow))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:88: Assertion failed in %Ntb_sequencer: CALL: shadow=%x, expected 031\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(0xfffU & (IData)(vlSelf->tb_sequencer__DOT__shadow)));
        VL_STOP_MT("tb/tb_sequencer.sv", 88, "");
    }
    __Vtask_tb_sequencer__DOT__step_ctrl__2__cd = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__2__addr = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__2__op = 3U;
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = __Vtask_tb_sequencer__DOT__step_ctrl__2__op;
    vlSelf->tb_sequencer__DOT__cond = __Vtask_tb_sequencer__DOT__step_ctrl__2__cd;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = __Vtask_tb_sequencer__DOT__step_ctrl__2__addr;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       45);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       46);
    if (VL_UNLIKELY((0x31U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:92: Assertion failed in %Ntb_sequencer: RET: pc=%x, expected 031\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 92, "");
    }
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__loop_we = 1U;
    vlSelf->tb_sequencer__DOT__loop_in = 0x3050U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       97);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       97);
    vlSelf->tb_sequencer__DOT__loop_we = 0U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       99);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       99);
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 0U;
    vlSelf->tb_sequencer__DOT__cond = 0U;
    vlSelf->tb_sequencer__DOT__l = 1U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       102);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       102);
    if (VL_UNLIKELY((0x50U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:103: Assertion failed in %Ntb_sequencer: LOOP 1: pc=%x, expected 050\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 103, "");
    }
    if (VL_UNLIKELY((2U != (0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                      >> 0xcU))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:104: Assertion failed in %Ntb_sequencer: LOOP 1: cnt=%0#, expected 2\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                >> 0xcU)));
        VL_STOP_MT("tb/tb_sequencer.sv", 104, "");
    }
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 0U;
    vlSelf->tb_sequencer__DOT__cond = 0U;
    vlSelf->tb_sequencer__DOT__l = 1U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       108);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       108);
    if (VL_UNLIKELY((0x50U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:109: Assertion failed in %Ntb_sequencer: LOOP 2: pc=%x, expected 050\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 109, "");
    }
    if (VL_UNLIKELY((1U != (0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                      >> 0xcU))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:110: Assertion failed in %Ntb_sequencer: LOOP 2: cnt=%0#, expected 1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                >> 0xcU)));
        VL_STOP_MT("tb/tb_sequencer.sv", 110, "");
    }
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 0U;
    vlSelf->tb_sequencer__DOT__cond = 0U;
    vlSelf->tb_sequencer__DOT__l = 1U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       114);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       114);
    if (VL_UNLIKELY((0x51U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:115: Assertion failed in %Ntb_sequencer: LOOP 3: pc=%x, expected 051 (fall through)\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 115, "");
    }
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__loop_we = 1U;
    vlSelf->tb_sequencer__DOT__loop_in = 0x2060U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       120);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       120);
    vlSelf->tb_sequencer__DOT__loop_we = 0U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       122);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       122);
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = 1U;
    vlSelf->tb_sequencer__DOT__cond = 0U;
    vlSelf->tb_sequencer__DOT__l = 1U;
    vlSelf->tb_sequencer__DOT__imm12 = 0x70U;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       125);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       125);
    VL_WRITEF("JMP+L: loop_reg=%x l=%b imm_class=%b reg_op=%2# pc_next=%x pc=%x\n",
              24,vlSelf->tb_sequencer__DOT__loop_reg,
              1,(IData)(vlSelf->tb_sequencer__DOT__l),
              2,vlSelf->tb_sequencer__DOT__imm_class,
              5,(IData)(vlSelf->tb_sequencer__DOT__reg_op),
              12,vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c,
              12,(IData)(vlSelf->tb_sequencer__DOT__pc));
    if (VL_UNLIKELY((0x60U != (IData)(vlSelf->tb_sequencer__DOT__pc)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:129: Assertion failed in %Ntb_sequencer: JMP+L: pc=%x, expected 060\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__pc));
        VL_STOP_MT("tb/tb_sequencer.sv", 129, "");
    }
    if (VL_UNLIKELY((1U != (0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                      >> 0xcU))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:130: Assertion failed in %Ntb_sequencer: JMP+L: cnt=%0#, expected 1\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                >> 0xcU)));
        VL_STOP_MT("tb/tb_sequencer.sv", 130, "");
    }
    __Vtask_tb_sequencer__DOT__step_ctrl__3__cd = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__3__addr = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__3__op = 5U;
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = __Vtask_tb_sequencer__DOT__step_ctrl__3__op;
    vlSelf->tb_sequencer__DOT__cond = __Vtask_tb_sequencer__DOT__step_ctrl__3__cd;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = __Vtask_tb_sequencer__DOT__step_ctrl__3__addr;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       45);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       46);
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_sequencer__DOT__halted))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:134: Assertion failed in %Ntb_sequencer: HALT 0: not halted\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("tb/tb_sequencer.sv", 134, "");
    }
    vlSelf->tb_sequencer__DOT__reg_op = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = 0U;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__rst = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       139);
    vlSelf->tb_sequencer__DOT__rst = 0U;
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       139);
    VL_WRITEF("after reset: halted=%b error=%b\n",1,
              vlSelf->tb_sequencer__DOT__halted,1,(IData)(vlSelf->tb_sequencer__DOT__error));
    __Vtask_tb_sequencer__DOT__step_ctrl__4__cd = 0U;
    __Vtask_tb_sequencer__DOT__step_ctrl__4__addr = 0x123U;
    __Vtask_tb_sequencer__DOT__step_ctrl__4__op = 5U;
    vlSelf->tb_sequencer__DOT__imm_class = 2U;
    vlSelf->tb_sequencer__DOT__reg_op = __Vtask_tb_sequencer__DOT__step_ctrl__4__op;
    vlSelf->tb_sequencer__DOT__cond = __Vtask_tb_sequencer__DOT__step_ctrl__4__cd;
    vlSelf->tb_sequencer__DOT__l = 0U;
    vlSelf->tb_sequencer__DOT__imm12 = __Vtask_tb_sequencer__DOT__step_ctrl__4__addr;
    co_await vlSelf->__VtrigSched_hdd3ed70c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_sequencer.clk)", 
                                                       "tb/tb_sequencer.sv", 
                                                       45);
    co_await vlSelf->__VdlySched.delay(0x3e8ULL, nullptr, 
                                       "tb/tb_sequencer.sv", 
                                       46);
    VL_WRITEF("HALT123: halted=%b error=%b error_code=%x imm_class=%b reg_op=%2# imm12=%x\n",
              1,vlSelf->tb_sequencer__DOT__halted,1,
              (IData)(vlSelf->tb_sequencer__DOT__error),
              12,vlSelf->tb_sequencer__DOT__error_code,
              2,(IData)(vlSelf->tb_sequencer__DOT__imm_class),
              5,vlSelf->tb_sequencer__DOT__reg_op,12,
              (IData)(vlSelf->tb_sequencer__DOT__imm12));
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->tb_sequencer__DOT__error))))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:144: Assertion failed in %Ntb_sequencer: HALT 123: not error\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("tb/tb_sequencer.sv", 144, "");
    }
    if (VL_UNLIKELY((0x123U != (IData)(vlSelf->tb_sequencer__DOT__error_code)))) {
        VL_WRITEF("[%0t] %%Error: tb_sequencer.sv:145: Assertion failed in %Ntb_sequencer: HALT 123: code=%x, expected 123\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                  12,(IData)(vlSelf->tb_sequencer__DOT__error_code));
        VL_STOP_MT("tb/tb_sequencer.sv", 145, "");
    }
    VL_WRITEF("tb_sequencer: PASS\n");
    VL_FINISH_MT("tb/tb_sequencer.sv", 148, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sequencer___024root___dump_triggers__act(Vtb_sequencer___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sequencer___024root___eval_triggers__act(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_sequencer__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_sequencer__DOT__clk__0))));
    vlSelf->__VactTriggered.set(1U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_sequencer__DOT__clk__0 
        = vlSelf->tb_sequencer__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sequencer___024root___dump_triggers__act(vlSelf);
    }
#endif
}
