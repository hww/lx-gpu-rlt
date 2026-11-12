// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sequencer.h for the primary calling header

#include "Vtb_sequencer__pch.h"
#include "Vtb_sequencer___024root.h"

VlCoroutine Vtb_sequencer___024root___eval_initial__TOP__Vtiming__0(Vtb_sequencer___024root* vlSelf);
VlCoroutine Vtb_sequencer___024root___eval_initial__TOP__Vtiming__1(Vtb_sequencer___024root* vlSelf);

void Vtb_sequencer___024root___eval_initial(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_initial\n"); );
    // Body
    Vtb_sequencer___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_sequencer___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_sequencer__DOT__clk__0 
        = vlSelf->tb_sequencer__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtb_sequencer___024root___eval_initial__TOP__Vtiming__1(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_sequencer.sv", 
                                           31);
        vlSelf->tb_sequencer__DOT__clk = (1U & (~ (IData)(vlSelf->tb_sequencer__DOT__clk)));
    }
}

VL_INLINE_OPT void Vtb_sequencer___024root___act_comb__TOP__0(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___act_comb__TOP__0\n"); );
    // Init
    CData/*0:0*/ tb_sequencer__DOT__dut__DOT__active;
    tb_sequencer__DOT__dut__DOT__active = 0;
    CData/*0:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__Vfuncout;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd = 0;
    CData/*0:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz = 0;
    CData/*0:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn = 0;
    CData/*0:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc = 0;
    CData/*0:0*/ __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv = 0;
    // Body
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv 
        = vlSelf->tb_sequencer__DOT__v;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc 
        = vlSelf->tb_sequencer__DOT__c;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn 
        = vlSelf->tb_sequencer__DOT__n;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz 
        = vlSelf->tb_sequencer__DOT__z;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd 
        = vlSelf->tb_sequencer__DOT__cond;
    __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__Vfuncout 
        = (1U & ((8U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                  ? ((4U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                      ? ((2U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                          ? ((1U & (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))) 
                             && ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz) 
                                 | ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn) 
                                    != (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv))))
                          : ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? ((~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz)) 
                                 & ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn) 
                                    == (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv)))
                              : ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn) 
                                 != (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv))))
                      : ((2U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                          ? ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn) 
                                 == (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv))
                              : ((~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc)) 
                                 | (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz)))
                          : ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? ((IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc) 
                                 & (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz)))
                              : (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv)))))
                  : ((4U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                      ? ((2U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                          ? ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__vv)
                              : (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn)))
                          : ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__nn)
                              : (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc))))
                      : ((2U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                          ? ((1U & (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))
                              ? (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cc)
                              : (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz)))
                          : ((1U & (~ (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__cd))) 
                             || (IData)(__Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__zz))))));
    tb_sequencer__DOT__dut__DOT__active = __Vfunc_tb_sequencer__DOT__dut__DOT__cond_true__5__Vfuncout;
    vlSelf->tb_sequencer__DOT__dut__DOT__do_ctrl = 
        ((2U == (IData)(vlSelf->tb_sequencer__DOT__imm_class)) 
         & (IData)(tb_sequencer__DOT__dut__DOT__active));
    vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c 
        = (0xfffU & ((IData)(1U) + (IData)(vlSelf->tb_sequencer__DOT__pc)));
    if (vlSelf->tb_sequencer__DOT__dut__DOT__do_ctrl) {
        if ((1U & (~ ((IData)(vlSelf->tb_sequencer__DOT__reg_op) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelf->tb_sequencer__DOT__reg_op) 
                          >> 3U)))) {
                if ((4U & (IData)(vlSelf->tb_sequencer__DOT__reg_op))) {
                    if ((1U & (~ ((IData)(vlSelf->tb_sequencer__DOT__reg_op) 
                                  >> 1U)))) {
                        vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c 
                            = ((1U & (IData)(vlSelf->tb_sequencer__DOT__reg_op))
                                ? (0xfffU & ((IData)(1U) 
                                             + (IData)(vlSelf->tb_sequencer__DOT__pc)))
                                : 0U);
                    }
                } else if ((2U & (IData)(vlSelf->tb_sequencer__DOT__reg_op))) {
                    vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c 
                        = (0xfffU & ((1U & (IData)(vlSelf->tb_sequencer__DOT__reg_op))
                                      ? (IData)(vlSelf->tb_sequencer__DOT__shadow)
                                      : (IData)(vlSelf->tb_sequencer__DOT__imm12)));
                } else if ((1U & (IData)(vlSelf->tb_sequencer__DOT__reg_op))) {
                    vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c 
                        = vlSelf->tb_sequencer__DOT__imm12;
                }
            }
        }
    }
    if (((IData)(vlSelf->tb_sequencer__DOT__l) & (1U 
                                                  < 
                                                  (0xfffU 
                                                   & (vlSelf->tb_sequencer__DOT__loop_reg 
                                                      >> 0xcU))))) {
        vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c 
            = (0xfffU & vlSelf->tb_sequencer__DOT__loop_reg);
    }
}

void Vtb_sequencer___024root___eval_act(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_act\n"); );
    // Body
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_sequencer___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_sequencer___024root___nba_sequent__TOP__0(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*11:0*/ __Vdly__tb_sequencer__DOT__pc;
    __Vdly__tb_sequencer__DOT__pc = 0;
    IData/*23:0*/ __Vdly__tb_sequencer__DOT__loop_reg;
    __Vdly__tb_sequencer__DOT__loop_reg = 0;
    CData/*0:0*/ __Vdly__tb_sequencer__DOT__halted;
    __Vdly__tb_sequencer__DOT__halted = 0;
    CData/*0:0*/ __Vdly__tb_sequencer__DOT__error;
    __Vdly__tb_sequencer__DOT__error = 0;
    // Body
    __Vdly__tb_sequencer__DOT__error = vlSelf->tb_sequencer__DOT__error;
    __Vdly__tb_sequencer__DOT__halted = vlSelf->tb_sequencer__DOT__halted;
    __Vdly__tb_sequencer__DOT__loop_reg = vlSelf->tb_sequencer__DOT__loop_reg;
    __Vdly__tb_sequencer__DOT__pc = vlSelf->tb_sequencer__DOT__pc;
    if (VL_UNLIKELY(vlSelf->tb_sequencer__DOT__rst)) {
        VL_WRITEF("SEQ rst: halted<=0\n");
        __Vdly__tb_sequencer__DOT__pc = 0U;
        vlSelf->tb_sequencer__DOT__shadow = 0U;
        __Vdly__tb_sequencer__DOT__loop_reg = 0U;
        __Vdly__tb_sequencer__DOT__halted = 0U;
        __Vdly__tb_sequencer__DOT__error = 0U;
        vlSelf->tb_sequencer__DOT__error_code = 0U;
    } else if (VL_UNLIKELY((1U & (~ ((IData)(vlSelf->tb_sequencer__DOT__halted) 
                                     | (IData)(vlSelf->tb_sequencer__DOT__error)))))) {
        VL_WRITEF("FF: halted=%b error=%b imm_class=%b reg_op=%2# imm12=%x\n",
                  1,vlSelf->tb_sequencer__DOT__halted,
                  1,(IData)(vlSelf->tb_sequencer__DOT__error),
                  2,vlSelf->tb_sequencer__DOT__imm_class,
                  5,(IData)(vlSelf->tb_sequencer__DOT__reg_op),
                  12,vlSelf->tb_sequencer__DOT__imm12);
        if (vlSelf->tb_sequencer__DOT__loop_we) {
            __Vdly__tb_sequencer__DOT__loop_reg = vlSelf->tb_sequencer__DOT__loop_in;
        } else if (((IData)(vlSelf->tb_sequencer__DOT__l) 
                    & (1U < (0xfffU & (vlSelf->tb_sequencer__DOT__loop_reg 
                                       >> 0xcU))))) {
            __Vdly__tb_sequencer__DOT__loop_reg = (
                                                   (0xfff000U 
                                                    & (((vlSelf->tb_sequencer__DOT__loop_reg 
                                                         >> 0xcU) 
                                                        - (IData)(1U)) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & vlSelf->tb_sequencer__DOT__loop_reg));
        }
        if (vlSelf->tb_sequencer__DOT__dut__DOT__do_ctrl) {
            if ((2U == (IData)(vlSelf->tb_sequencer__DOT__reg_op))) {
                vlSelf->tb_sequencer__DOT__shadow = 
                    (0xfffU & ((IData)(1U) + (IData)(vlSelf->tb_sequencer__DOT__pc)));
            } else if ((5U == (IData)(vlSelf->tb_sequencer__DOT__reg_op))) {
                if ((0U == (IData)(vlSelf->tb_sequencer__DOT__imm12))) {
                    __Vdly__tb_sequencer__DOT__halted = 1U;
                } else {
                    __Vdly__tb_sequencer__DOT__error = 1U;
                    vlSelf->tb_sequencer__DOT__error_code 
                        = vlSelf->tb_sequencer__DOT__imm12;
                }
            }
        }
        __Vdly__tb_sequencer__DOT__pc = vlSelf->tb_sequencer__DOT__dut__DOT__pc_next_c;
    }
    vlSelf->tb_sequencer__DOT__halted = __Vdly__tb_sequencer__DOT__halted;
    vlSelf->tb_sequencer__DOT__error = __Vdly__tb_sequencer__DOT__error;
    vlSelf->tb_sequencer__DOT__pc = __Vdly__tb_sequencer__DOT__pc;
    vlSelf->tb_sequencer__DOT__loop_reg = __Vdly__tb_sequencer__DOT__loop_reg;
}

void Vtb_sequencer___024root___eval_nba(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sequencer___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_sequencer___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vtb_sequencer___024root___timing_resume(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___timing_resume\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hdd3ed70c__0.resume("@(posedge tb_sequencer.clk)");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_sequencer___024root___timing_commit(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___timing_commit\n"); );
    // Body
    if ((! (1ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hdd3ed70c__0.commit("@(posedge tb_sequencer.clk)");
    }
}

void Vtb_sequencer___024root___eval_triggers__act(Vtb_sequencer___024root* vlSelf);

bool Vtb_sequencer___024root___eval_phase__act(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_sequencer___024root___eval_triggers__act(vlSelf);
    Vtb_sequencer___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_sequencer___024root___timing_resume(vlSelf);
        Vtb_sequencer___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_sequencer___024root___eval_phase__nba(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_sequencer___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sequencer___024root___dump_triggers__nba(Vtb_sequencer___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sequencer___024root___dump_triggers__act(Vtb_sequencer___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_sequencer___024root___eval(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_sequencer___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_sequencer.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_sequencer___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_sequencer.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_sequencer___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_sequencer___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_sequencer___024root___eval_debug_assertions(Vtb_sequencer___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_sequencer__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sequencer___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
