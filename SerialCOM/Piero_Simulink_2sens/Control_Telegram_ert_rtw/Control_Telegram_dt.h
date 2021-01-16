/*
 * Control_Telegram_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Control_Telegram".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Sat Jan 16 19:15:58 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(uint16_T),
  sizeof(int16_T),
  sizeof(int16_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int16_T),
  sizeof(codertarget_arduinobase_block_T),
  sizeof(codertarget_arduinobase_inter_T),
  sizeof(codertarget_arduinobase_i_hrt_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(codertarget_arduinobase_int_h_T),
  sizeof(codertarget_arduinobase_in_hr_T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int32_T",
  "int64m_T",
  "uint16_T",
  "int16_T",
  "int16_T",
  "int32_T",
  "int32_T",
  "int64m_T",
  "int16_T",
  "codertarget_arduinobase_block_T",
  "codertarget_arduinobase_inter_T",
  "codertarget_arduinobase_i_hrt_T",
  "int32_T",
  "int64m_T",
  "codertarget_arduinobase_int_h_T",
  "codertarget_arduinobase_in_hr_T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Control_Telegram_B.TmpRTBAtSwitch1Inport1[0]), 21, 0, 4 },

  { (char_T *)(&Control_Telegram_B.DataStoreRead), 0, 0, 12 },

  { (char_T *)(&Control_Telegram_B.encoders[0]), 6, 0, 6 },

  { (char_T *)(&Control_Telegram_B.Saturation3), 4, 0, 2 },

  { (char_T *)(&Control_Telegram_B.Gain2), 3, 0, 25 },

  { (char_T *)(&Control_Telegram_B.Compare), 8, 0, 2 }
  ,

  { (char_T *)(&Control_Telegram_DW.obj), 25, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.obj_b), 24, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.obj_c), 29, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.obj_d), 28, 0, 4 },

  { (char_T *)(&Control_Telegram_DW.obj_e), 23, 0, 5 },

  { (char_T *)(&Control_Telegram_DW.encoders_DSTATE), 0, 0, 12 },

  { (char_T *)(&Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[0]), 21, 0, 2
  },

  { (char_T *)(&Control_Telegram_DW.Scope1_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&Control_Telegram_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.is_c3_Control_Telegram), 7, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.MdeloRuedaIzda_states), 4, 0, 2 },

  { (char_T *)(&Control_Telegram_DW.EnabledSubsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Control_Telegram_DW.RateTransition_Buffer[0]), 3, 0, 19 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  19U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Control_Telegram_P.PIDIzda_D), 0, 0, 17 },

  { (char_T *)(&Control_Telegram_P.CompareToConstant1_const), 4, 0, 2 },

  { (char_T *)(&Control_Telegram_P.Constant_Value), 0, 0, 31 },

  { (char_T *)(&Control_Telegram_P.TSamp_WtEt), 27, 0, 1 },

  { (char_T *)(&Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC), 21, 0, 3 },

  { (char_T *)(&Control_Telegram_P.Gain1_Gain), 20, 0, 2 },

  { (char_T *)(&Control_Telegram_P.MdeloRuedaIzda_InitialStates), 4, 0, 18 },

  { (char_T *)(&Control_Telegram_P.Gain_Gain_n), 16, 0, 1 },

  { (char_T *)(&Control_Telegram_P.SwitchControl_Value), 8, 0, 1 },

  { (char_T *)(&Control_Telegram_P.q_Y0), 3, 0, 14 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  10U,
  rtPTransitions
};

/* [EOF] Control_Telegram_dt.h */
