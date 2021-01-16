/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_Telegram.h
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

#ifndef RTW_HEADER_Control_Telegram_h_
#define RTW_HEADER_Control_Telegram_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Control_Telegram_COMMON_INCLUDES_
#define Control_Telegram_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_arduino_digitalio.h"
#include "MW_SerialRead.h"
#include "MW_SerialWrite.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Control_Telegram_COMMON_INCLUDES_ */

#include "Control_Telegram_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  int64m_T TmpRTBAtSwitch1Inport1[2];  /* '<Root>/Saturation1' */
  int64m_T Gain1[2];                   /* '<Root>/Gain1' */
  real_T DataStoreRead;                /* '<S2>/Data Store Read' */
  real_T Diff[2];                      /* '<S113>/Diff' */
  real_T NumericalUnity[2];            /* '<S110>/Numerical Unity' */
  real_T DataTypeConversion[2];        /* '<S6>/Data Type Conversion' */
  real_T Saturation[2];                /* '<Root>/Saturation' */
  real_T v_d;                          /* '<Root>/Chart' */
  real_T v_i;                          /* '<Root>/Chart' */
  real_T modo;                         /* '<Root>/Chart' */
  real_T FilterCoefficient_a;          /* '<S48>/Filter Coefficient' */
  real_T FilterCoefficient;            /* '<S96>/Filter Coefficient' */
  real_T Switch_o;                     /* '<S2>/Switch' */
  real_T rtb_TSamp_m;
  real_T rtb_Sum_idx_0;
  int32_T encoders[2];                 /* '<S112>/encoders' */
  int32_T SFunctionBuilder_o1;         /* '<S9>/S-Function Builder' */
  int32_T SFunctionBuilder_o2;         /* '<S9>/S-Function Builder' */
  int32_T TmpSignalConversionAtGain1Inpor[2];/* '<Root>/Subsystem' */
  int16_T Saturation3;                 /* '<S114>/Saturation3' */
  int16_T Saturation_h;                /* '<S114>/Saturation' */
  uint8_T Gain2;                       /* '<S114>/Gain2' */
  uint8_T Gain;                        /* '<S114>/Gain' */
  uint8_T DataTypeConversion_g[2];     /* '<Root>/Data Type Conversion' */
  uint8_T RateTransition[18];          /* '<Root>/Rate Transition' */
  uint8_T SerialReceive_o1;            /* '<Root>/Serial Receive' */
  uint8_T SerialReceive_o2;            /* '<Root>/Serial Receive' */
  uint8_T In1;                         /* '<S3>/In1' */
  boolean_T Compare;                   /* '<S116>/Compare' */
  boolean_T Compare_a;                 /* '<S115>/Compare' */
} B_Control_Telegram_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_i_hrt_T obj; /* '<Root>/Serial Transmit' */
  codertarget_arduinobase_inter_T obj_b;/* '<Root>/Serial Receive' */
  codertarget_arduinobase_in_hr_T obj_c;/* '<S8>/Bateria' */
  codertarget_arduinobase_int_h_T obj_d;/* '<S114>/Izq_Atras' */
  codertarget_arduinobase_int_h_T obj_p;/* '<S114>/Izq_Adelante' */
  codertarget_arduinobase_int_h_T obj_n;/* '<S114>/Dcha_Atras' */
  codertarget_arduinobase_int_h_T obj_l;/* '<S114>/Dcha_Adelante' */
  codertarget_arduinobase_block_T obj_e;/* '<S114>/Digital Output4' */
  codertarget_arduinobase_block_T obj_eu;/* '<S114>/Digital Output2' */
  codertarget_arduinobase_block_T obj_m;/* '<S2>/Red' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/Green' */
  codertarget_arduinobase_block_T obj_l0;/* '<S2>/Blue' */
  real_T encoders_DSTATE;              /* '<S112>/encoders' */
  real_T UD_DSTATE[2];                 /* '<S113>/UD' */
  real_T Integrator_DSTATE;            /* '<S93>/Integrator' */
  real_T Filter_DSTATE;                /* '<S88>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S45>/Integrator' */
  real_T Filter_DSTATE_o;              /* '<S40>/Filter' */
  real_T SFunctionBuilder_DSTATE;      /* '<S9>/S-Function Builder' */
  real_T Memory_PreviousInput[2];      /* '<S7>/Memory' */
  real_T led;                          /* '<Root>/Data Store Memory' */
  real_T VBateria;                     /* '<Root>/Data Store Memory1' */
  int64m_T TmpRTBAtSwitch1Inport1_Buffer0[2];/* synthesized block */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<S2>/Pulse Generator' */
  uint32_T is_c3_Control_Telegram;     /* '<Root>/Chart' */
  int16_T MdeloRuedaIzda_states;       /* '<S111>/Mdelo Rueda Izda' */
  int16_T MdeloRuedaDcha_states;       /* '<S111>/Mdelo Rueda Dcha' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<Root>/Enabled Subsystem' */
  uint8_T RateTransition_Buffer[18];   /* '<Root>/Rate Transition' */
  uint8_T is_active_c3_Control_Telegram;/* '<Root>/Chart' */
} DW_Control_Telegram_T;

/* Parameters (default storage) */
struct P_Control_Telegram_T_ {
  real_T PIDIzda_D;                    /* Mask Parameter: PIDIzda_D
                                        * Referenced by: '<S87>/Derivative Gain'
                                        */
  real_T PIDDcha_D;                    /* Mask Parameter: PIDDcha_D
                                        * Referenced by: '<S39>/Derivative Gain'
                                        */
  real_T PIDDcha_I;                    /* Mask Parameter: PIDDcha_I
                                        * Referenced by: '<S42>/Integral Gain'
                                        */
  real_T PIDIzda_I;                    /* Mask Parameter: PIDIzda_I
                                        * Referenced by: '<S90>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S113>/UD'
                               */
  real_T PIDIzda_InitialConditionForFilt;
                              /* Mask Parameter: PIDIzda_InitialConditionForFilt
                               * Referenced by: '<S88>/Filter'
                               */
  real_T PIDDcha_InitialConditionForFilt;
                              /* Mask Parameter: PIDDcha_InitialConditionForFilt
                               * Referenced by: '<S40>/Filter'
                               */
  real_T PIDIzda_InitialConditionForInte;
                              /* Mask Parameter: PIDIzda_InitialConditionForInte
                               * Referenced by: '<S93>/Integrator'
                               */
  real_T PIDDcha_InitialConditionForInte;
                              /* Mask Parameter: PIDDcha_InitialConditionForInte
                               * Referenced by: '<S45>/Integrator'
                               */
  real_T PIDIzda_LowerSaturationLimit;
                                 /* Mask Parameter: PIDIzda_LowerSaturationLimit
                                  * Referenced by: '<S100>/Saturation'
                                  */
  real_T PIDDcha_LowerSaturationLimit;
                                 /* Mask Parameter: PIDDcha_LowerSaturationLimit
                                  * Referenced by: '<S52>/Saturation'
                                  */
  real_T PIDIzda_N;                    /* Mask Parameter: PIDIzda_N
                                        * Referenced by: '<S96>/Filter Coefficient'
                                        */
  real_T PIDDcha_N;                    /* Mask Parameter: PIDDcha_N
                                        * Referenced by: '<S48>/Filter Coefficient'
                                        */
  real_T PIDIzda_P;                    /* Mask Parameter: PIDIzda_P
                                        * Referenced by: '<S98>/Proportional Gain'
                                        */
  real_T PIDDcha_P;                    /* Mask Parameter: PIDDcha_P
                                        * Referenced by: '<S50>/Proportional Gain'
                                        */
  real_T PIDIzda_UpperSaturationLimit;
                                 /* Mask Parameter: PIDIzda_UpperSaturationLimit
                                  * Referenced by: '<S100>/Saturation'
                                  */
  real_T PIDDcha_UpperSaturationLimit;
                                 /* Mask Parameter: PIDDcha_UpperSaturationLimit
                                  * Referenced by: '<S52>/Saturation'
                                  */
  int16_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S116>/Constant'
                                      */
  int16_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S115>/Constant'
                                       */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T SerialReceive_Protocol;       /* Expression: 0
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T SerialTransmit_Protocol;      /* Expression: 0
                                        * Referenced by: '<Root>/Serial Transmit'
                                        */
  real_T azulobs_izq_Value;            /* Expression: 1
                                        * Referenced by: '<S6>/azul (obs_izq)'
                                        */
  real_T obs_izq_Threshold;            /* Expression: 500
                                        * Referenced by: '<S6>/obs_izq'
                                        */
  real_T amarilloobs_dcha_Value;       /* Expression: 6
                                        * Referenced by: '<S6>/amarillo (obs_dcha)'
                                        */
  real_T obs_dcha_Threshold;           /* Expression: 500
                                        * Referenced by: '<S6>/obs_dcha'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T rojoparpadeando_Value;        /* Expression: 10
                                        * Referenced by: '<S6>/rojo parpadeando'
                                        */
  real_T Constant10_Value[2];          /* Expression: [0 0]
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Bateria_SampleTime;           /* Expression: 1
                                        * Referenced by: '<S8>/Bateria'
                                        */
  real_T Constant9_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S88>/Filter'
                                        */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S45>/Integrator'
                                      */
  real_T Filter_gainval_n;             /* Computed Parameter: Filter_gainval_n
                                        * Referenced by: '<S40>/Filter'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S2>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S2>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S2>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S2>/Switch'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T Constant11_Value;             /* Expression: 10
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T verde_Value;                  /* Expression: 4
                                        * Referenced by: '<S6>/verde'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 11
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  int64m_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S113>/TSamp'
                                        */
  int64m_T TmpRTBAtSwitch1Inport1_InitialC;
                          /* Computed Parameter: TmpRTBAtSwitch1Inport1_InitialC
                           * Referenced by: synthesized block
                           */
  int64m_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  int64m_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S112>/Gain'
                                        */
  int16_T MdeloRuedaIzda_InitialStates;
                             /* Computed Parameter: MdeloRuedaIzda_InitialStates
                              * Referenced by: '<S111>/Mdelo Rueda Izda'
                              */
  int16_T MdeloRuedaDcha_InitialStates;
                             /* Computed Parameter: MdeloRuedaDcha_InitialStates
                              * Referenced by: '<S111>/Mdelo Rueda Dcha'
                              */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S114>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S114>/Saturation3'
                                      */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S114>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S114>/Saturation2'
                                      */
  int16_T Saturation1_UpperSat_k;  /* Computed Parameter: Saturation1_UpperSat_k
                                    * Referenced by: '<S114>/Saturation1'
                                    */
  int16_T Saturation1_LowerSat_p;  /* Computed Parameter: Saturation1_LowerSat_p
                                    * Referenced by: '<S114>/Saturation1'
                                    */
  int16_T Saturation_UpperSat_o;    /* Computed Parameter: Saturation_UpperSat_o
                                     * Referenced by: '<S114>/Saturation'
                                     */
  int16_T Saturation_LowerSat_f;    /* Computed Parameter: Saturation_LowerSat_f
                                     * Referenced by: '<S114>/Saturation'
                                     */
  int16_T MdeloRuedaIzda_DenCoef[2];
                                   /* Computed Parameter: MdeloRuedaIzda_DenCoef
                                    * Referenced by: '<S111>/Mdelo Rueda Izda'
                                    */
  int16_T MdeloRuedaDcha_DenCoef[2];
                                   /* Computed Parameter: MdeloRuedaDcha_DenCoef
                                    * Referenced by: '<S111>/Mdelo Rueda Dcha'
                                    */
  int16_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S114>/Gain2'
                                        */
  int16_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S114>/Gain'
                                        */
  int16_T MdeloRuedaIzda_NumCoef;  /* Computed Parameter: MdeloRuedaIzda_NumCoef
                                    * Referenced by: '<S111>/Mdelo Rueda Izda'
                                    */
  int16_T MdeloRuedaDcha_NumCoef;  /* Computed Parameter: MdeloRuedaDcha_NumCoef
                                    * Referenced by: '<S111>/Mdelo Rueda Dcha'
                                    */
  uint16_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S8>/Gain'
                                        */
  boolean_T SwitchControl_Value;       /* Expression: switch_mode
                                        * Referenced by: '<S110>/Switch Control'
                                        */
  uint8_T q_Y0;                        /* Computed Parameter: q_Y0
                                        * Referenced by: '<S3>/q'
                                        */
  uint8_T encoders_P1;                 /* Expression: uint8(0)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T encoders_P2;                 /* Expression: uint8(2)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T encoders_P3;                 /* Expression: uint8(3)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T encoders_P4;                 /* Expression: uint8(1)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T encoders_P5;                 /* Expression: uint8(19)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T encoders_P6;                 /* Expression: uint8(18)
                                        * Referenced by: '<S112>/encoders'
                                        */
  uint8_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  uint8_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  uint8_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<Root>/Constant5'
                                        */
  uint8_T Constant6_Value;             /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<Root>/Constant6'
                                        */
  uint8_T Constant7_Value;             /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<Root>/Constant7'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Control_Telegram_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID1_3;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Control_Telegram_T Control_Telegram_P;

/* Block signals (default storage) */
extern B_Control_Telegram_T Control_Telegram_B;

/* Block states (default storage) */
extern DW_Control_Telegram_T Control_Telegram_DW;

/* External function called from main */
extern void Control_Telegram_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Control_Telegram_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Control_Telegram_initialize(void);
extern void Control_Telegram_step0(void);
extern void Control_Telegram_step1(void);
extern void Control_Telegram_step2(void);
extern void Control_Telegram_step3(void);
extern void Control_Telegram_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_Telegram_T *const Control_Telegram_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Control_Telegram'
 * '<S1>'   : 'Control_Telegram/Chart'
 * '<S2>'   : 'Control_Telegram/Control LED'
 * '<S3>'   : 'Control_Telegram/Enabled Subsystem'
 * '<S4>'   : 'Control_Telegram/Sensores Pablo'
 * '<S5>'   : 'Control_Telegram/Subsystem'
 * '<S6>'   : 'Control_Telegram/Subsystem1'
 * '<S7>'   : 'Control_Telegram/sistema control ruedas Piero'
 * '<S8>'   : 'Control_Telegram/supervisor bateria'
 * '<S9>'   : 'Control_Telegram/Sensores Pablo/SENSORES'
 * '<S10>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador'
 * '<S11>'  : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY'
 * '<S12>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha'
 * '<S13>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda'
 * '<S14>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Anti-windup'
 * '<S15>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/D Gain'
 * '<S16>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Filter'
 * '<S17>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Filter ICs'
 * '<S18>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/I Gain'
 * '<S19>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Ideal P Gain'
 * '<S20>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Ideal P Gain Fdbk'
 * '<S21>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Integrator'
 * '<S22>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Integrator ICs'
 * '<S23>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/N Copy'
 * '<S24>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/N Gain'
 * '<S25>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/P Copy'
 * '<S26>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Parallel P Gain'
 * '<S27>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Reset Signal'
 * '<S28>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Saturation'
 * '<S29>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Saturation Fdbk'
 * '<S30>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Sum'
 * '<S31>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Sum Fdbk'
 * '<S32>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tracking Mode'
 * '<S33>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tracking Mode Sum'
 * '<S34>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tsamp - Integral'
 * '<S35>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tsamp - Ngain'
 * '<S36>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/postSat Signal'
 * '<S37>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/preSat Signal'
 * '<S38>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Anti-windup/Passthrough'
 * '<S39>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/D Gain/Internal Parameters'
 * '<S40>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Filter/Disc. Forward Euler Filter'
 * '<S41>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Filter ICs/Internal IC - Filter'
 * '<S42>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/I Gain/Internal Parameters'
 * '<S43>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Ideal P Gain/Passthrough'
 * '<S44>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Ideal P Gain Fdbk/Disabled'
 * '<S45>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Integrator/Discrete'
 * '<S46>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Integrator ICs/Internal IC'
 * '<S47>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/N Copy/Disabled'
 * '<S48>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/N Gain/Internal Parameters'
 * '<S49>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/P Copy/Disabled'
 * '<S50>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Parallel P Gain/Internal Parameters'
 * '<S51>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Reset Signal/Disabled'
 * '<S52>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Saturation/Enabled'
 * '<S53>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Saturation Fdbk/Disabled'
 * '<S54>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Sum/Sum_PID'
 * '<S55>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Sum Fdbk/Disabled'
 * '<S56>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tracking Mode/Disabled'
 * '<S57>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tracking Mode Sum/Passthrough'
 * '<S58>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tsamp - Integral/Passthrough'
 * '<S59>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/Tsamp - Ngain/Passthrough'
 * '<S60>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/postSat Signal/Forward_Path'
 * '<S61>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Dcha/preSat Signal/Forward_Path'
 * '<S62>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Anti-windup'
 * '<S63>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/D Gain'
 * '<S64>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Filter'
 * '<S65>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Filter ICs'
 * '<S66>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/I Gain'
 * '<S67>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Ideal P Gain'
 * '<S68>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Ideal P Gain Fdbk'
 * '<S69>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Integrator'
 * '<S70>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Integrator ICs'
 * '<S71>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/N Copy'
 * '<S72>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/N Gain'
 * '<S73>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/P Copy'
 * '<S74>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Parallel P Gain'
 * '<S75>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Reset Signal'
 * '<S76>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Saturation'
 * '<S77>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Saturation Fdbk'
 * '<S78>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Sum'
 * '<S79>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Sum Fdbk'
 * '<S80>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tracking Mode'
 * '<S81>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tracking Mode Sum'
 * '<S82>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tsamp - Integral'
 * '<S83>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tsamp - Ngain'
 * '<S84>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/postSat Signal'
 * '<S85>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/preSat Signal'
 * '<S86>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Anti-windup/Passthrough'
 * '<S87>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/D Gain/Internal Parameters'
 * '<S88>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Filter/Disc. Forward Euler Filter'
 * '<S89>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Filter ICs/Internal IC - Filter'
 * '<S90>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/I Gain/Internal Parameters'
 * '<S91>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Ideal P Gain/Passthrough'
 * '<S92>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Ideal P Gain Fdbk/Disabled'
 * '<S93>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Integrator/Discrete'
 * '<S94>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Integrator ICs/Internal IC'
 * '<S95>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/N Copy/Disabled'
 * '<S96>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/N Gain/Internal Parameters'
 * '<S97>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/P Copy/Disabled'
 * '<S98>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Parallel P Gain/Internal Parameters'
 * '<S99>'  : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Reset Signal/Disabled'
 * '<S100>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Saturation/Enabled'
 * '<S101>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Saturation Fdbk/Disabled'
 * '<S102>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Sum/Sum_PID'
 * '<S103>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Sum Fdbk/Disabled'
 * '<S104>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tracking Mode/Disabled'
 * '<S105>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tracking Mode Sum/Passthrough'
 * '<S106>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tsamp - Integral/Passthrough'
 * '<S107>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/Tsamp - Ngain/Passthrough'
 * '<S108>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/postSat Signal/Forward_Path'
 * '<S109>' : 'Control_Telegram/sistema control ruedas Piero/Controlador/PID Izda/preSat Signal/Forward_Path'
 * '<S110>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/Environment Controller'
 * '<S111>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/Modelo PieroDIY'
 * '<S112>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/PieroDIY-HW'
 * '<S113>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/PieroDIY-HW/Discrete Derivative'
 * '<S114>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/PieroDIY-HW/Driver mootor'
 * '<S115>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/PieroDIY-HW/Driver mootor/Compare To Constant'
 * '<S116>' : 'Control_Telegram/sistema control ruedas Piero/PIERO_DIY/PieroDIY-HW/Driver mootor/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_Control_Telegram_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
