/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_Telegram_data.c
 *
 * Code generated for Simulink model 'Control_Telegram'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Sat Jan 16 19:15:58 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Control_Telegram.h"
#include "Control_Telegram_private.h"

/* Block parameters (default storage) */
P_Control_Telegram_T Control_Telegram_P = {
  /* Mask Parameter: PIDIzda_D
   * Referenced by: '<S87>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDDcha_D
   * Referenced by: '<S39>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDDcha_I
   * Referenced by: '<S42>/Integral Gain'
   */
  815.010847070688,

  /* Mask Parameter: PIDIzda_I
   * Referenced by: '<S90>/Integral Gain'
   */
  819.728444396404,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S113>/UD'
   */
  0.0,

  /* Mask Parameter: PIDIzda_InitialConditionForFilt
   * Referenced by: '<S88>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDDcha_InitialConditionForFilt
   * Referenced by: '<S40>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDIzda_InitialConditionForInte
   * Referenced by: '<S93>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDDcha_InitialConditionForInte
   * Referenced by: '<S45>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDIzda_LowerSaturationLimit
   * Referenced by: '<S100>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDDcha_LowerSaturationLimit
   * Referenced by: '<S52>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDIzda_N
   * Referenced by: '<S96>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDDcha_N
   * Referenced by: '<S48>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDIzda_P
   * Referenced by: '<S98>/Proportional Gain'
   */
  4.09864222198202,

  /* Mask Parameter: PIDDcha_P
   * Referenced by: '<S50>/Proportional Gain'
   */
  4.07505423535344,

  /* Mask Parameter: PIDIzda_UpperSaturationLimit
   * Referenced by: '<S100>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDDcha_UpperSaturationLimit
   * Referenced by: '<S52>/Saturation'
   */
  255.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S116>/Constant'
   */
  0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S115>/Constant'
   */
  0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Serial Receive'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Serial Transmit'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/azul (obs_izq)'
   */
  1.0,

  /* Expression: 500
   * Referenced by: '<S6>/obs_izq'
   */
  500.0,

  /* Expression: 6
   * Referenced by: '<S6>/amarillo (obs_dcha)'
   */
  6.0,

  /* Expression: 500
   * Referenced by: '<S6>/obs_dcha'
   */
  500.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S6>/rojo parpadeando'
   */
  10.0,

  /* Expression: [0 0]
   * Referenced by: '<Root>/Constant10'
   */
  { 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Constant8'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S8>/Bateria'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Constant9'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S93>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S88>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S45>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval_n
   * Referenced by: '<S40>/Filter'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S2>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S2>/Pulse Generator'
   */
  50.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S2>/Pulse Generator'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant11'
   */
  10.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 4
   * Referenced by: '<S6>/verde'
   */
  4.0,

  /* Expression: 11
   * Referenced by: '<S6>/Switch'
   */
  11.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S113>/TSamp'
   */
  { { 0x19UL, 0UL } },

  /* Computed Parameter: TmpRTBAtSwitch1Inport1_InitialC
   * Referenced by: synthesized block
   */
  { { 0UL, 0UL } },

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  { { 0x13333333UL, 0UL } },

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  { { 0UL, 0UL } },

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  429497,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S112>/Gain'
   */
  1238435225,

  /* Computed Parameter: MdeloRuedaIzda_InitialStates
   * Referenced by: '<S111>/Mdelo Rueda Izda'
   */
  0,

  /* Computed Parameter: MdeloRuedaDcha_InitialStates
   * Referenced by: '<S111>/Mdelo Rueda Dcha'
   */
  0,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S114>/Saturation3'
   */
  255,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S114>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S114>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S114>/Saturation2'
   */
  -255,

  /* Computed Parameter: Saturation1_UpperSat_k
   * Referenced by: '<S114>/Saturation1'
   */
  0,

  /* Computed Parameter: Saturation1_LowerSat_p
   * Referenced by: '<S114>/Saturation1'
   */
  -255,

  /* Computed Parameter: Saturation_UpperSat_o
   * Referenced by: '<S114>/Saturation'
   */
  255,

  /* Computed Parameter: Saturation_LowerSat_f
   * Referenced by: '<S114>/Saturation'
   */
  0,

  /* Computed Parameter: MdeloRuedaIzda_DenCoef
   * Referenced by: '<S111>/Mdelo Rueda Izda'
   */
  { 16384, -13209 },

  /* Computed Parameter: MdeloRuedaDcha_DenCoef
   * Referenced by: '<S111>/Mdelo Rueda Dcha'
   */
  { 16384, -13308 },

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S114>/Gain2'
   */
  -32768,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S114>/Gain'
   */
  -32768,

  /* Computed Parameter: MdeloRuedaIzda_NumCoef
   * Referenced by: '<S111>/Mdelo Rueda Izda'
   */
  28948,

  /* Computed Parameter: MdeloRuedaDcha_NumCoef
   * Referenced by: '<S111>/Mdelo Rueda Dcha'
   */
  28215,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<S8>/Gain'
   */
  51250U,

  /* Expression: switch_mode
   * Referenced by: '<S110>/Switch Control'
   */
  0,

  /* Computed Parameter: q_Y0
   * Referenced by: '<S3>/q'
   */
  0U,

  /* Expression: uint8(0)
   * Referenced by: '<S112>/encoders'
   */
  0U,

  /* Expression: uint8(2)
   * Referenced by: '<S112>/encoders'
   */
  2U,

  /* Expression: uint8(3)
   * Referenced by: '<S112>/encoders'
   */
  3U,

  /* Expression: uint8(1)
   * Referenced by: '<S112>/encoders'
   */
  1U,

  /* Expression: uint8(19)
   * Referenced by: '<S112>/encoders'
   */
  19U,

  /* Expression: uint8(18)
   * Referenced by: '<S112>/encoders'
   */
  18U,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<Root>/Constant'
   */
  251U,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<Root>/Constant1'
   */
  252U,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<Root>/Constant3'
   */
  253U,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<Root>/Constant4'
   */
  254U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<Root>/Constant5'
   */
  255U,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<Root>/Constant6'
   */
  0U,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<Root>/Constant7'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
