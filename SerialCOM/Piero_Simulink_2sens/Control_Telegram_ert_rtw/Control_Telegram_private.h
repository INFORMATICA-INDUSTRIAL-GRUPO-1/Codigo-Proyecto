/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_Telegram_private.h
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

#ifndef RTW_HEADER_Control_Telegram_private_h_
#define RTW_HEADER_Control_Telegram_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void MisEncoders_Start_wrapper(real_T *xD,
    const uint8_T *enc_I, const int_T p_width0,
    const uint8_T *pinA_I, const int_T p_width1,
    const uint8_T *pinB_I, const int_T p_width2,
    const uint8_T *enc_D, const int_T p_width3,
    const uint8_T *pinA_D, const int_T p_width4,
    const uint8_T *pinB_D, const int_T p_width5);
  extern void MisEncoders_Outputs_wrapper(int32_T *pos,
    const real_T *xD,
    const uint8_T *enc_I, const int_T p_width0,
    const uint8_T *pinA_I, const int_T p_width1,
    const uint8_T *pinB_I, const int_T p_width2,
    const uint8_T *enc_D, const int_T p_width3,
    const uint8_T *pinA_D, const int_T p_width4,
    const uint8_T *pinB_D, const int_T p_width5);
  extern void MisEncoders_Update_wrapper(int32_T *pos,
    real_T *xD,
    const uint8_T *enc_I, const int_T p_width0,
    const uint8_T *pinA_I, const int_T p_width1,
    const uint8_T *pinB_I, const int_T p_width2,
    const uint8_T *enc_D, const int_T p_width3,
    const uint8_T *pinA_D, const int_T p_width4,
    const uint8_T *pinB_D, const int_T p_width5);
  extern void MisEncoders_Terminate_wrapper(real_T *xD,
    const uint8_T *enc_I, const int_T p_width0,
    const uint8_T *pinA_I, const int_T p_width1,
    const uint8_T *pinB_I, const int_T p_width2,
    const uint8_T *enc_D, const int_T p_width3,
    const uint8_T *pinA_D, const int_T p_width4,
    const uint8_T *pinB_D, const int_T p_width5);

#ifdef __cplusplus

}
#endif

extern void Sensores_VL53L0X_I2C_Start_wrapper(real_T *xD);
extern void Sensores_VL53L0X_I2C_Outputs_wrapper(int32_T *Sensor1,
  int32_T *Sensor2,
  const real_T *xD);
extern void Sensores_VL53L0X_I2C_Update_wrapper(int32_T *Sensor1,
  int32_T *Sensor2,
  real_T *xD);
extern void Sensores_VL53L0X_I2C_Terminate_wrapper(real_T *xD);
extern real_T rt_roundd_snf(real_T u);
extern real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1);
extern void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[],
  int16_T n2, uint32_T y[], int16_T n);
extern boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
extern int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n);
extern boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
extern int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator,
  uint16_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T
  denominator, uint16_T nRepeatSub);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint16_T nRepeatSub);

#endif                              /* RTW_HEADER_Control_Telegram_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
