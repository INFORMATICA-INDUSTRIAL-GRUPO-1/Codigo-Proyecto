/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_Telegram_types.h
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

#ifndef RTW_HEADER_Control_Telegram_types_h_
#define RTW_HEADER_Control_Telegram_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigita_T;

#endif                               /*typedef_b_arduinodriver_ArduinoDigita_T*/

#ifndef struct_tag_KPrkuOK6ssObybfxqijZPC
#define struct_tag_KPrkuOK6ssObybfxqijZPC

struct tag_KPrkuOK6ssObybfxqijZPC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /*struct_tag_KPrkuOK6ssObybfxqijZPC*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_KPrkuOK6ssObybfxqijZPC codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

/* Custom Type definition for MATLABSystem: '<S8>/Bateria' */
#include "MW_SVD.h"
#ifndef struct_tag_ioKPFkOtLGdRlGav7pT3yD
#define struct_tag_ioKPFkOtLGdRlGav7pT3yD

struct tag_ioKPFkOtLGdRlGav7pT3yD
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_ioKPFkOtLGdRlGav7pT3yD*/

#ifndef typedef_c_arduinodriver_ArduinoSerial_T
#define typedef_c_arduinodriver_ArduinoSerial_T

typedef struct tag_ioKPFkOtLGdRlGav7pT3yD c_arduinodriver_ArduinoSerial_T;

#endif                               /*typedef_c_arduinodriver_ArduinoSerial_T*/

#ifndef struct_tag_2MXFmq8tqMwlyFFQKTNrDC
#define struct_tag_2MXFmq8tqMwlyFFQKTNrDC

struct tag_2MXFmq8tqMwlyFFQKTNrDC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T Protocol;
  uint16_T DataSizeInBytes;
  uint16_T DataTypeWidth;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_2MXFmq8tqMwlyFFQKTNrDC*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_2MXFmq8tqMwlyFFQKTNrDC codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

#ifndef struct_tag_lMInmD9zWRzKpUCrv0OfsC
#define struct_tag_lMInmD9zWRzKpUCrv0OfsC

struct tag_lMInmD9zWRzKpUCrv0OfsC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
  uint32_T PinPWM;
};

#endif                                 /*struct_tag_lMInmD9zWRzKpUCrv0OfsC*/

#ifndef typedef_codertarget_arduinobase_int_h_T
#define typedef_codertarget_arduinobase_int_h_T

typedef struct tag_lMInmD9zWRzKpUCrv0OfsC codertarget_arduinobase_int_h_T;

#endif                               /*typedef_codertarget_arduinobase_int_h_T*/

#ifndef struct_tag_Gc8EcsaAa6B4PVRJCSARvB
#define struct_tag_Gc8EcsaAa6B4PVRJCSARvB

struct tag_Gc8EcsaAa6B4PVRJCSARvB
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /*struct_tag_Gc8EcsaAa6B4PVRJCSARvB*/

#ifndef typedef_f_arduinodriver_ArduinoAnalog_T
#define typedef_f_arduinodriver_ArduinoAnalog_T

typedef struct tag_Gc8EcsaAa6B4PVRJCSARvB f_arduinodriver_ArduinoAnalog_T;

#endif                               /*typedef_f_arduinodriver_ArduinoAnalog_T*/

#ifndef struct_tag_IH4ZAEwYd2ouei4lGVnLsG
#define struct_tag_IH4ZAEwYd2ouei4lGVnLsG

struct tag_IH4ZAEwYd2ouei4lGVnLsG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_IH4ZAEwYd2ouei4lGVnLsG*/

#ifndef typedef_codertarget_arduinobase_in_hr_T
#define typedef_codertarget_arduinobase_in_hr_T

typedef struct tag_IH4ZAEwYd2ouei4lGVnLsG codertarget_arduinobase_in_hr_T;

#endif                               /*typedef_codertarget_arduinobase_in_hr_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_Control_Telegram_T
#define typedef_cell_wrap_Control_Telegram_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_Control_Telegram_T;

#endif                                 /*typedef_cell_wrap_Control_Telegram_T*/

#ifndef struct_tag_uKrQkorC4YuW9dPwXssOBF
#define struct_tag_uKrQkorC4YuW9dPwXssOBF

struct tag_uKrQkorC4YuW9dPwXssOBF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_Control_Telegram_T inputVarSize;
  real_T Protocol;
  real_T port;
  real_T dataSizeInBytes;
  real_T dataType;
  real_T sendModeEnum;
  real_T sendFormatEnum;
  c_arduinodriver_ArduinoSerial_T SerialDriverObj;
};

#endif                                 /*struct_tag_uKrQkorC4YuW9dPwXssOBF*/

#ifndef typedef_codertarget_arduinobase_i_hrt_T
#define typedef_codertarget_arduinobase_i_hrt_T

typedef struct tag_uKrQkorC4YuW9dPwXssOBF codertarget_arduinobase_i_hrt_T;

#endif                               /*typedef_codertarget_arduinobase_i_hrt_T*/

/* Parameters (default storage) */
typedef struct P_Control_Telegram_T_ P_Control_Telegram_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Control_Telegram_T RT_MODEL_Control_Telegram_T;

#endif                                /* RTW_HEADER_Control_Telegram_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
