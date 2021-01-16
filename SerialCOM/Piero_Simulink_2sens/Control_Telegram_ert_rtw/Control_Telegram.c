/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Control_Telegram.c
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
#include "Control_Telegram_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Control_T_IN_Primera_etiqueta_X (7UL)
#define Control_Telegram_IN_Adelante   (1UL)
#define Control_Telegram_IN_Atras      (2UL)
#define Control_Telegram_IN_Derecha    (3UL)
#define Control_Telegram_IN_Evita_obs  (4UL)
#define Control_Telegram_IN_Izquierda  (5UL)
#define Control_Telegram_IN_Parar      (6UL)
#define Control_Telegram_IN_espera     (9UL)
#define Control_Telegram_IN_espera1    (10UL)
#define Control_Telegram_IN_nada       (11UL)
#define Control__IN_Primera_etiqueta_X1 (8UL)

/* Block signals (default storage) */
B_Control_Telegram_T Control_Telegram_B;

/* Block states (default storage) */
DW_Control_Telegram_T Control_Telegram_DW;

/* Real-time model */
static RT_MODEL_Control_Telegram_T Control_Telegram_M_;
RT_MODEL_Control_Telegram_T *const Control_Telegram_M = &Control_Telegram_M_;
static void rate_monotonic_scheduler(void);
real_T sMultiWord2Double(const uint32_T u1[], int16_T n1, int16_T e1)
{
  real_T y;
  uint32_T cb;
  uint32_T u1i;
  int16_T exp_0;
  int16_T i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648UL) != 0UL) {
    cb = 1UL;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648UL) != 0UL);
  isNegative2 = ((u2[n2 - 1] & 2147483648UL) != 0UL);
  cb1 = 1UL;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    cb2 = 1UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1UL;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) > 0;
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  uint32_T su1;
  uint32_T u2i;
  int16_T i;
  int16_T y;
  su1 = u1[n - 1] & 2147483648UL;
  if ((u2[n - 1] & 2147483648UL) != su1) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) < 0;
}

int32_T div_repeat_s32_floor(int32_T numerator, int32_T denominator, uint16_T
  nRepeatSub)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  if (denominator == 0L) {
    quotient = numerator >= 0L ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0L ? ~(uint32_T)numerator + 1UL : (uint32_T)
      numerator;
    absDenominator = denominator < 0L ? ~(uint32_T)denominator + 1UL : (uint32_T)
      denominator;
    if ((numerator < 0L) != (denominator < 0L)) {
      quotient = -(int32_T)div_nzp_repeat_u32_ceiling(absNumerator,
        absDenominator, nRepeatSub);
    } else {
      quotient = (int32_T)div_nzp_repeat_u32(absNumerator, absDenominator,
        nRepeatSub);
    }
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T denominator,
  uint16_T nRepeatSub)
{
  uint32_T quotient;
  uint16_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648UL);
    numerator <<= 1UL;
    quotient <<= 1UL;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  if (numerator > 0UL) {
    quotient++;
  }

  return quotient;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint16_T
  nRepeatSub)
{
  uint32_T quotient;
  uint16_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648UL);
    numerator <<= 1UL;
    quotient <<= 1UL;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Control_Telegram_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Control_Telegram_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Control_Telegram_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(Control_Telegram_M, 3));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  Control_Telegram_M->Timing.RateInteraction.TID0_1 =
    (Control_Telegram_M->Timing.TaskCounters.TID[1] == 0);

  /* tid 1 shares data with slower tid rate: 3 */
  if (Control_Telegram_M->Timing.TaskCounters.TID[1] == 0) {
    Control_Telegram_M->Timing.RateInteraction.TID1_3 =
      (Control_Telegram_M->Timing.TaskCounters.TID[3] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Control_Telegram_M->Timing.TaskCounters.TID[1])++;
  if ((Control_Telegram_M->Timing.TaskCounters.TID[1]) > 2) {/* Sample time: [0.03s, 0.0s] */
    Control_Telegram_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Control_Telegram_M->Timing.TaskCounters.TID[2])++;
  if ((Control_Telegram_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [1.0s, 0.0s] */
    Control_Telegram_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Control_Telegram_M->Timing.TaskCounters.TID[3])++;
  if ((Control_Telegram_M->Timing.TaskCounters.TID[3]) > 104) {/* Sample time: [1.05s, 0.0s] */
    Control_Telegram_M->Timing.TaskCounters.TID[3] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void Control_Telegram_step0(void)      /* Sample time: [0.01s, 0.0s] */
{
  codertarget_arduinobase_int_h_T *obj;
  int64m_T tmp;
  int64m_T tmp_2;
  real_T rtb_Sum_idx_1;
  real_T rtb_TSamp_idx_0;
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint32_T u;
  int16_T rtb_DataTypeConversion_h_idx_1;
  int16_T rtb_DataTypeConversion_h_idx__0;
  int16_T rtb_IntegertoBitConverter_idx_1;
  int16_T rtb_IntegertoBitConverter_idx_2;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Control_Telegram_DW.EnabledSubsystem_SubsysRanBC);

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Control_Telegram_DW.obj_b.Protocol !=
      Control_Telegram_P.SerialReceive_Protocol) {
    Control_Telegram_DW.obj_b.Protocol =
      Control_Telegram_P.SerialReceive_Protocol;
  }

  /* MATLABSystem: '<Root>/Serial Receive' */
  MW_Serial_read(3, Control_Telegram_DW.obj_b.DataSizeInBytes,
                 &Control_Telegram_B.SerialReceive_o1,
                 &Control_Telegram_B.SerialReceive_o2);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (Control_Telegram_B.SerialReceive_o2 > 0) {
    /* Inport: '<S3>/In1' */
    Control_Telegram_B.In1 = Control_Telegram_B.SerialReceive_o1;
    srUpdateBC(Control_Telegram_DW.EnabledSubsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* Chart: '<Root>/Chart' */
  if (Control_Telegram_DW.is_active_c3_Control_Telegram == 0U) {
    Control_Telegram_DW.is_active_c3_Control_Telegram = 1U;
    Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_nada;
    Control_Telegram_B.v_i = 0.0;
    Control_Telegram_B.v_d = 0.0;
    Control_Telegram_B.modo = 0.0;
  } else {
    switch (Control_Telegram_DW.is_c3_Control_Telegram) {
     case Control_Telegram_IN_Adelante:
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
      Control_Telegram_B.modo = 1.0;
      break;

     case Control_Telegram_IN_Atras:
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
      Control_Telegram_B.modo = 1.0;
      break;

     case Control_Telegram_IN_Derecha:
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
      Control_Telegram_B.modo = 1.0;
      break;

     case Control_Telegram_IN_Evita_obs:
      if (Control_Telegram_B.In1 == 88) {
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control__IN_Primera_etiqueta_X1;
      }
      break;

     case Control_Telegram_IN_Izquierda:
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
      Control_Telegram_B.modo = 1.0;
      break;

     case Control_Telegram_IN_Parar:
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
      Control_Telegram_B.modo = 1.0;
      break;

     case Control_T_IN_Primera_etiqueta_X:
      switch (Control_Telegram_B.In1) {
       case 65:
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control_Telegram_IN_Izquierda;
        if (Control_Telegram_B.v_d <= 0.4) {
          Control_Telegram_B.v_d += 0.05;
        }

        if (Control_Telegram_B.v_i >= -0.2) {
          Control_Telegram_B.v_i -= 0.02;
        }
        break;

       case 82:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_nada;
        Control_Telegram_B.v_i = 0.0;
        Control_Telegram_B.v_d = 0.0;
        Control_Telegram_B.modo = 0.0;
        break;

       case 68:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_Derecha;
        if (Control_Telegram_B.v_i <= 0.4) {
          Control_Telegram_B.v_i += 0.05;
        }

        if (Control_Telegram_B.v_d >= -0.2) {
          Control_Telegram_B.v_d -= 0.02;
        }
        break;

       case 87:
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control_Telegram_IN_Adelante;
        if ((Control_Telegram_B.v_i <= 0.4) && (Control_Telegram_B.v_d <= 0.4))
        {
          Control_Telegram_B.v_i += 0.05;
          Control_Telegram_B.v_d += 0.05;
        }
        break;

       case 83:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_Atras;
        if ((Control_Telegram_B.v_d >= -0.2) && (Control_Telegram_B.v_i >= -0.2))
        {
          Control_Telegram_B.v_d -= 0.05;
          Control_Telegram_B.v_i -= 0.05;
        }
        break;

       case 32:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_Parar;
        Control_Telegram_B.v_i = 0.0;
        Control_Telegram_B.v_d = 0.0;
        break;

       case 77:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
        Control_Telegram_B.modo = 1.0;
        break;
      }
      break;

     case Control__IN_Primera_etiqueta_X1:
      switch (Control_Telegram_B.In1) {
       case 77:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera;
        Control_Telegram_B.modo = 1.0;
        break;

       case 69:
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control_Telegram_IN_Evita_obs;
        Control_Telegram_B.modo = 2.0;
        break;

       case 82:
        Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_nada;
        Control_Telegram_B.v_i = 0.0;
        Control_Telegram_B.v_d = 0.0;
        Control_Telegram_B.modo = 0.0;
        break;
      }
      break;

     case Control_Telegram_IN_espera:
      if (Control_Telegram_B.In1 == 88) {
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control_T_IN_Primera_etiqueta_X;
      }
      break;

     case Control_Telegram_IN_espera1:
      if (Control_Telegram_B.In1 == 88) {
        Control_Telegram_DW.is_c3_Control_Telegram =
          Control__IN_Primera_etiqueta_X1;
      }
      break;

     default:
      /* case IN_nada: */
      Control_Telegram_DW.is_c3_Control_Telegram = Control_Telegram_IN_espera1;
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* S-Function (MisEncoders): '<S112>/encoders' */
  MisEncoders_Outputs_wrapper(&Control_Telegram_B.encoders[0],
    &Control_Telegram_DW.encoders_DSTATE, &Control_Telegram_P.encoders_P1, 1,
    &Control_Telegram_P.encoders_P2, 1, &Control_Telegram_P.encoders_P3, 1,
    &Control_Telegram_P.encoders_P4, 1, &Control_Telegram_P.encoders_P5, 1,
    &Control_Telegram_P.encoders_P6, 1);

  /* DataStoreRead: '<S2>/Data Store Read' */
  Control_Telegram_B.DataStoreRead = Control_Telegram_DW.led;

  /* S-Function (scominttobit): '<S2>/Integer to Bit Converter' */
  /* Integer to Bit Conversion */
  u = (uint32_T)Control_Telegram_B.DataStoreRead >> 1;
  rtb_IntegertoBitConverter_idx_2 = (int16_T)u & 1;
  u >>= 1;
  rtb_IntegertoBitConverter_idx_1 = (int16_T)u & 1;
  u >>= 1;

  /* Gain: '<S112>/Gain' */
  tmp_0 = (uint32_T)Control_Telegram_P.Gain_Gain;
  tmp_1 = (uint32_T)Control_Telegram_B.encoders[0];
  sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

  /* SampleTimeMath: '<S113>/TSamp'
   *
   * About '<S113>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Control_Telegram_B.rtb_Sum_idx_0 = sMultiWord2Double
    (&Control_Telegram_P.TSamp_WtEt.chunks[0U], 2, 0) * 4.0;
  Control_Telegram_B.rtb_TSamp_m = sMultiWord2Double(&tmp.chunks[0U], 2, 0) *
    1.1368683772161603E-13 * Control_Telegram_B.rtb_Sum_idx_0;

  /* Sum: '<S113>/Diff' incorporates:
   *  UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  Control_Telegram_B.Diff[0] = Control_Telegram_B.rtb_TSamp_m -
    Control_Telegram_DW.UD_DSTATE[0];

  /* SampleTimeMath: '<S113>/TSamp'
   *
   * About '<S113>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_idx_0 = Control_Telegram_B.rtb_TSamp_m;

  /* Gain: '<S112>/Gain' */
  tmp_0 = (uint32_T)Control_Telegram_P.Gain_Gain;
  tmp_1 = (uint32_T)Control_Telegram_B.encoders[1];
  sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp_2.chunks[0U], 2);

  /* SampleTimeMath: '<S113>/TSamp'
   *
   * About '<S113>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Control_Telegram_B.rtb_TSamp_m = sMultiWord2Double(&tmp_2.chunks[0U], 2, 0) *
    1.1368683772161603E-13 * Control_Telegram_B.rtb_Sum_idx_0;

  /* Sum: '<S113>/Diff' incorporates:
   *  UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  Control_Telegram_B.Diff[1] = Control_Telegram_B.rtb_TSamp_m -
    Control_Telegram_DW.UD_DSTATE[1];

  /* RateTransition generated from: '<Root>/Switch1' */
  if (Control_Telegram_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Switch1' */
    Control_Telegram_B.TmpRTBAtSwitch1Inport1[0] =
      Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[0];
    Control_Telegram_B.TmpRTBAtSwitch1Inport1[1] =
      Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[1];
  }

  /* End of RateTransition generated from: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant8'
   *  Constant: '<Root>/Constant9'
   *  RateTransition generated from: '<Root>/Switch1'
   *  RelationalOperator: '<Root>/Equal'
   *  RelationalOperator: '<Root>/Equal1'
   *  Switch: '<Root>/Switch'
   */
  if (Control_Telegram_B.modo == Control_Telegram_P.Constant9_Value) {
    tmp = Control_Telegram_B.TmpRTBAtSwitch1Inport1[0];
    Control_Telegram_B.rtb_Sum_idx_0 = sMultiWord2Double(&tmp.chunks[0U], 2, 0) *
      9.3132257461547852E-10;
    tmp = Control_Telegram_B.TmpRTBAtSwitch1Inport1[1];
    rtb_Sum_idx_1 = sMultiWord2Double(&tmp.chunks[0U], 2, 0) *
      9.3132257461547852E-10;
  } else if (Control_Telegram_B.modo == Control_Telegram_P.Constant8_Value) {
    /* Switch: '<Root>/Switch' */
    Control_Telegram_B.rtb_Sum_idx_0 = Control_Telegram_B.v_i;
    rtb_Sum_idx_1 = Control_Telegram_B.v_d;
  } else {
    Control_Telegram_B.rtb_Sum_idx_0 = Control_Telegram_P.Constant10_Value[0];
    rtb_Sum_idx_1 = Control_Telegram_P.Constant10_Value[1];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S7>/Sum' incorporates:
   *  Memory: '<S7>/Memory'
   */
  Control_Telegram_B.rtb_Sum_idx_0 -= Control_Telegram_DW.Memory_PreviousInput[0];
  rtb_Sum_idx_1 -= Control_Telegram_DW.Memory_PreviousInput[1];

  /* Gain: '<S96>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S88>/Filter'
   *  Gain: '<S87>/Derivative Gain'
   *  Sum: '<S88>/SumD'
   */
  Control_Telegram_B.FilterCoefficient = (Control_Telegram_P.PIDIzda_D *
    Control_Telegram_B.rtb_Sum_idx_0 - Control_Telegram_DW.Filter_DSTATE) *
    Control_Telegram_P.PIDIzda_N;

  /* Gain: '<S48>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S40>/Filter'
   *  Gain: '<S39>/Derivative Gain'
   *  Sum: '<S40>/SumD'
   */
  Control_Telegram_B.FilterCoefficient_a = (Control_Telegram_P.PIDDcha_D *
    rtb_Sum_idx_1 - Control_Telegram_DW.Filter_DSTATE_o) *
    Control_Telegram_P.PIDDcha_N;

  /* Sum: '<S102>/Sum' incorporates:
   *  DiscreteIntegrator: '<S93>/Integrator'
   *  Gain: '<S98>/Proportional Gain'
   */
  Control_Telegram_B.Switch_o = (Control_Telegram_P.PIDIzda_P *
    Control_Telegram_B.rtb_Sum_idx_0 + Control_Telegram_DW.Integrator_DSTATE) +
    Control_Telegram_B.FilterCoefficient;

  /* Saturate: '<S100>/Saturation' */
  if (Control_Telegram_B.Switch_o >
      Control_Telegram_P.PIDIzda_UpperSaturationLimit) {
    Control_Telegram_B.Switch_o =
      Control_Telegram_P.PIDIzda_UpperSaturationLimit;
  } else {
    if (Control_Telegram_B.Switch_o <
        Control_Telegram_P.PIDIzda_LowerSaturationLimit) {
      Control_Telegram_B.Switch_o =
        Control_Telegram_P.PIDIzda_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S100>/Saturation' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  Control_Telegram_B.Switch_o = floor(Control_Telegram_B.Switch_o);
  if (rtIsNaN(Control_Telegram_B.Switch_o) || rtIsInf
      (Control_Telegram_B.Switch_o)) {
    Control_Telegram_B.Switch_o = 0.0;
  } else {
    Control_Telegram_B.Switch_o = fmod(Control_Telegram_B.Switch_o, 65536.0);
  }

  Control_Telegram_B.Saturation_h = Control_Telegram_B.Switch_o < 0.0 ?
    -(int16_T)(uint16_T)-Control_Telegram_B.Switch_o : (int16_T)(uint16_T)
    Control_Telegram_B.Switch_o;

  /* Sum: '<S54>/Sum' incorporates:
   *  DiscreteIntegrator: '<S45>/Integrator'
   *  Gain: '<S50>/Proportional Gain'
   */
  Control_Telegram_B.Switch_o = (Control_Telegram_P.PIDDcha_P * rtb_Sum_idx_1 +
    Control_Telegram_DW.Integrator_DSTATE_o) +
    Control_Telegram_B.FilterCoefficient_a;

  /* Saturate: '<S52>/Saturation' */
  if (Control_Telegram_B.Switch_o >
      Control_Telegram_P.PIDDcha_UpperSaturationLimit) {
    Control_Telegram_B.Switch_o =
      Control_Telegram_P.PIDDcha_UpperSaturationLimit;
  } else {
    if (Control_Telegram_B.Switch_o <
        Control_Telegram_P.PIDDcha_LowerSaturationLimit) {
      Control_Telegram_B.Switch_o =
        Control_Telegram_P.PIDDcha_LowerSaturationLimit;
    }
  }

  /* End of Saturate: '<S52>/Saturation' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  Control_Telegram_B.Switch_o = floor(Control_Telegram_B.Switch_o);
  if (rtIsNaN(Control_Telegram_B.Switch_o) || rtIsInf
      (Control_Telegram_B.Switch_o)) {
    Control_Telegram_B.Switch_o = 0.0;
  } else {
    Control_Telegram_B.Switch_o = fmod(Control_Telegram_B.Switch_o, 65536.0);
  }

  rtb_DataTypeConversion_h_idx_1 = Control_Telegram_B.Switch_o < 0.0 ? -(int16_T)
    (uint16_T)-Control_Telegram_B.Switch_o : (int16_T)(uint16_T)
    Control_Telegram_B.Switch_o;

  /* DiscreteFilter: '<S111>/Mdelo Rueda Izda' */
  Control_Telegram_DW.MdeloRuedaIzda_states = (int16_T)(div_repeat_s32_floor
    (((int32_T)Control_Telegram_B.Saturation_h << 14) - (int32_T)
     Control_Telegram_P.MdeloRuedaIzda_DenCoef[1L] *
     Control_Telegram_DW.MdeloRuedaIzda_states,
     Control_Telegram_P.MdeloRuedaIzda_DenCoef[0], 14U) >> 14);

  /* DiscreteFilter: '<S111>/Mdelo Rueda Dcha' */
  Control_Telegram_DW.MdeloRuedaDcha_states = (int16_T)(div_repeat_s32_floor
    (((int32_T)rtb_DataTypeConversion_h_idx_1 << 14) - (int32_T)
     Control_Telegram_P.MdeloRuedaDcha_DenCoef[1L] *
     Control_Telegram_DW.MdeloRuedaDcha_states,
     Control_Telegram_P.MdeloRuedaDcha_DenCoef[0], 14U) >> 14);

  /* Switch: '<S110>/Environment Switch' incorporates:
   *  Constant: '<S110>/Switch Control'
   */
  if (Control_Telegram_P.SwitchControl_Value) {
    /* SignalConversion: '<S110>/Numerical Unity' incorporates:
     *  DataTypeConversion: '<S111>/Data Type Conversion'
     *  DiscreteFilter: '<S111>/Mdelo Rueda Dcha'
     *  DiscreteFilter: '<S111>/Mdelo Rueda Izda'
     */
    Control_Telegram_B.NumericalUnity[0] = (real_T)((int32_T)
      Control_Telegram_P.MdeloRuedaIzda_NumCoef *
      Control_Telegram_DW.MdeloRuedaIzda_states) * 1.4901161193847656E-8;
    Control_Telegram_B.NumericalUnity[1] = (real_T)((int32_T)
      Control_Telegram_P.MdeloRuedaDcha_NumCoef *
      Control_Telegram_DW.MdeloRuedaDcha_states) * 1.4901161193847656E-8;
  } else {
    /* SignalConversion: '<S110>/Numerical Unity' */
    Control_Telegram_B.NumericalUnity[0] = Control_Telegram_B.Diff[0];
    Control_Telegram_B.NumericalUnity[1] = Control_Telegram_B.Diff[1];
  }

  /* End of Switch: '<S110>/Environment Switch' */

  /* Saturate: '<S114>/Saturation3' */
  if (rtb_DataTypeConversion_h_idx_1 > Control_Telegram_P.Saturation3_UpperSat)
  {
    /* Saturate: '<S114>/Saturation3' */
    Control_Telegram_B.Saturation3 = Control_Telegram_P.Saturation3_UpperSat;
  } else if (rtb_DataTypeConversion_h_idx_1 <
             Control_Telegram_P.Saturation3_LowerSat) {
    /* Saturate: '<S114>/Saturation3' */
    Control_Telegram_B.Saturation3 = Control_Telegram_P.Saturation3_LowerSat;
  } else {
    /* Saturate: '<S114>/Saturation3' */
    Control_Telegram_B.Saturation3 = rtb_DataTypeConversion_h_idx_1;
  }

  /* End of Saturate: '<S114>/Saturation3' */

  /* MATLABSystem: '<S114>/Dcha_Adelante' */
  obj = &Control_Telegram_DW.obj_l;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_l.PinPWM);
  if (Control_Telegram_B.Saturation3 < 255.0) {
    Control_Telegram_B.Switch_o = Control_Telegram_B.Saturation3;
  } else {
    Control_Telegram_B.Switch_o = 255.0;
  }

  if (!(Control_Telegram_B.Switch_o > 0.0)) {
    Control_Telegram_B.Switch_o = 0.0;
  }

  MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_l.MW_PWM_HANDLE,
                      Control_Telegram_B.Switch_o);

  /* End of MATLABSystem: '<S114>/Dcha_Adelante' */

  /* Saturate: '<S114>/Saturation2' */
  if (rtb_DataTypeConversion_h_idx_1 > Control_Telegram_P.Saturation2_UpperSat)
  {
    rtb_DataTypeConversion_h_idx__0 = Control_Telegram_P.Saturation2_UpperSat;
  } else if (rtb_DataTypeConversion_h_idx_1 <
             Control_Telegram_P.Saturation2_LowerSat) {
    rtb_DataTypeConversion_h_idx__0 = Control_Telegram_P.Saturation2_LowerSat;
  } else {
    rtb_DataTypeConversion_h_idx__0 = rtb_DataTypeConversion_h_idx_1;
  }

  /* End of Saturate: '<S114>/Saturation2' */

  /* Gain: '<S114>/Gain2' */
  Control_Telegram_B.Gain2 = (uint8_T)(((int32_T)Control_Telegram_P.Gain2_Gain *
    rtb_DataTypeConversion_h_idx__0) >> 15);

  /* MATLABSystem: '<S114>/Dcha_Atras' */
  obj = &Control_Telegram_DW.obj_n;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_n.PinPWM);
  MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_n.MW_PWM_HANDLE, (real_T)
                      Control_Telegram_B.Gain2);

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Constant: '<S116>/Constant'
   */
  Control_Telegram_B.Compare = (rtb_DataTypeConversion_h_idx_1 !=
    Control_Telegram_P.CompareToConstant1_const);

  /* MATLABSystem: '<S114>/Digital Output2' */
  writeDigitalPin(6, (uint8_T)Control_Telegram_B.Compare);

  /* RelationalOperator: '<S115>/Compare' incorporates:
   *  Constant: '<S115>/Constant'
   */
  Control_Telegram_B.Compare_a = (Control_Telegram_B.Saturation_h !=
    Control_Telegram_P.CompareToConstant_const);

  /* MATLABSystem: '<S114>/Digital Output4' */
  writeDigitalPin(11, (uint8_T)Control_Telegram_B.Compare_a);

  /* Saturate: '<S114>/Saturation1' */
  if (Control_Telegram_B.Saturation_h >
      Control_Telegram_P.Saturation1_UpperSat_k) {
    rtb_DataTypeConversion_h_idx_1 = Control_Telegram_P.Saturation1_UpperSat_k;
  } else if (Control_Telegram_B.Saturation_h <
             Control_Telegram_P.Saturation1_LowerSat_p) {
    rtb_DataTypeConversion_h_idx_1 = Control_Telegram_P.Saturation1_LowerSat_p;
  } else {
    rtb_DataTypeConversion_h_idx_1 = Control_Telegram_B.Saturation_h;
  }

  /* End of Saturate: '<S114>/Saturation1' */

  /* Gain: '<S114>/Gain' */
  Control_Telegram_B.Gain = (uint8_T)(((int32_T)Control_Telegram_P.Gain_Gain_d *
    rtb_DataTypeConversion_h_idx_1) >> 15);

  /* MATLABSystem: '<S114>/Izq_Atras' */
  obj = &Control_Telegram_DW.obj_d;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_d.PinPWM);
  MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_d.MW_PWM_HANDLE, (real_T)
                      Control_Telegram_B.Gain);

  /* Saturate: '<S114>/Saturation' */
  if (Control_Telegram_B.Saturation_h > Control_Telegram_P.Saturation_UpperSat_o)
  {
    /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
     *  Saturate: '<S114>/Saturation'
     */
    Control_Telegram_B.Saturation_h = Control_Telegram_P.Saturation_UpperSat_o;
  } else {
    if (Control_Telegram_B.Saturation_h <
        Control_Telegram_P.Saturation_LowerSat_f) {
      /* DataTypeConversion: '<S10>/Data Type Conversion' incorporates:
       *  Saturate: '<S114>/Saturation'
       */
      Control_Telegram_B.Saturation_h = Control_Telegram_P.Saturation_LowerSat_f;
    }
  }

  /* End of Saturate: '<S114>/Saturation' */

  /* MATLABSystem: '<S114>/Izq_Adelante' */
  obj = &Control_Telegram_DW.obj_p;
  obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_p.PinPWM);
  if (Control_Telegram_B.Saturation_h < 255.0) {
    Control_Telegram_B.Switch_o = Control_Telegram_B.Saturation_h;
  } else {
    Control_Telegram_B.Switch_o = 255.0;
  }

  if (!(Control_Telegram_B.Switch_o > 0.0)) {
    Control_Telegram_B.Switch_o = 0.0;
  }

  MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_p.MW_PWM_HANDLE,
                      Control_Telegram_B.Switch_o);

  /* End of MATLABSystem: '<S114>/Izq_Adelante' */

  /* DiscretePulseGenerator: '<S2>/Pulse Generator' */
  Control_Telegram_B.Switch_o = (Control_Telegram_DW.clockTickCounter <
    Control_Telegram_P.PulseGenerator_Duty) &&
    (Control_Telegram_DW.clockTickCounter >= 0L) ?
    Control_Telegram_P.PulseGenerator_Amp : 0.0;
  if (Control_Telegram_DW.clockTickCounter >=
      Control_Telegram_P.PulseGenerator_Period - 1.0) {
    Control_Telegram_DW.clockTickCounter = 0L;
  } else {
    Control_Telegram_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S2>/Pulse Generator' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  S-Function (scominttobit): '<S2>/Integer to Bit Converter'
   */
  if (!(((int16_T)u & 1) > Control_Telegram_P.Switch_Threshold)) {
    Control_Telegram_B.Switch_o = Control_Telegram_P.Constant_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* MATLABSystem: '<S2>/Blue' incorporates:
   *  Logic: '<S2>/Logical Operator2'
   *  S-Function (scominttobit): '<S2>/Integer to Bit Converter'
   */
  writeDigitalPin(49, (uint8_T)((Control_Telegram_B.Switch_o != 0.0) &&
    (((int16_T)(uint32_T)Control_Telegram_B.DataStoreRead & 1) != 0)));

  /* MATLABSystem: '<S2>/Green' incorporates:
   *  Logic: '<S2>/Logical Operator'
   */
  writeDigitalPin(53, (uint8_T)((Control_Telegram_B.Switch_o != 0.0) &&
    (rtb_IntegertoBitConverter_idx_1 != 0)));

  /* MATLABSystem: '<S2>/Red' incorporates:
   *  Logic: '<S2>/Logical Operator1'
   */
  writeDigitalPin(51, (uint8_T)((Control_Telegram_B.Switch_o != 0.0) &&
    (rtb_IntegertoBitConverter_idx_2 != 0)));

  /* Update for S-Function (MisEncoders): '<S112>/encoders' */

  /* S-Function "MisEncoders_wrapper" Block: <S112>/encoders */
  MisEncoders_Update_wrapper(&Control_Telegram_B.encoders[0],
    &Control_Telegram_DW.encoders_DSTATE, &Control_Telegram_P.encoders_P1, 1,
    &Control_Telegram_P.encoders_P2, 1, &Control_Telegram_P.encoders_P3, 1,
    &Control_Telegram_P.encoders_P4, 1, &Control_Telegram_P.encoders_P5, 1,
    &Control_Telegram_P.encoders_P6, 1);

  /* Update for UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  Control_Telegram_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;

  /* Update for Memory: '<S7>/Memory' */
  Control_Telegram_DW.Memory_PreviousInput[0] =
    Control_Telegram_B.NumericalUnity[0];

  /* Update for UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  Control_Telegram_DW.UD_DSTATE[1] = Control_Telegram_B.rtb_TSamp_m;

  /* Update for Memory: '<S7>/Memory' */
  Control_Telegram_DW.Memory_PreviousInput[1] =
    Control_Telegram_B.NumericalUnity[1];

  /* Update for DiscreteIntegrator: '<S93>/Integrator' incorporates:
   *  Gain: '<S90>/Integral Gain'
   */
  Control_Telegram_DW.Integrator_DSTATE += Control_Telegram_P.PIDIzda_I *
    Control_Telegram_B.rtb_Sum_idx_0 * Control_Telegram_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S88>/Filter' */
  Control_Telegram_DW.Filter_DSTATE += Control_Telegram_P.Filter_gainval *
    Control_Telegram_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
   *  Gain: '<S42>/Integral Gain'
   */
  Control_Telegram_DW.Integrator_DSTATE_o += Control_Telegram_P.PIDDcha_I *
    rtb_Sum_idx_1 * Control_Telegram_P.Integrator_gainval_p;

  /* Update for DiscreteIntegrator: '<S40>/Filter' */
  Control_Telegram_DW.Filter_DSTATE_o += Control_Telegram_P.Filter_gainval_n *
    Control_Telegram_B.FilterCoefficient_a;

  /* External mode */
  rtExtModeUploadCheckTrigger(4);
  rtExtModeUpload(0, (real_T)Control_Telegram_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Control_Telegram_M)!=-1) &&
        !((rtmGetTFinal(Control_Telegram_M)-Control_Telegram_M->Timing.taskTime0)
          > Control_Telegram_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Control_Telegram_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Control_Telegram_M)) {
      rtmSetErrorStatus(Control_Telegram_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Control_Telegram_M->Timing.taskTime0 =
    ((time_T)(++Control_Telegram_M->Timing.clockTick0)) *
    Control_Telegram_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Control_Telegram_step1(void)      /* Sample time: [0.03s, 0.0s] */
{
  const int64m_T *u0_0;
  real_T u0;
  uint32_T tmp;
  uint32_T tmp_0;

  /* S-Function (Sensores_VL53L0X_I2C): '<S9>/S-Function Builder' */
  Sensores_VL53L0X_I2C_Outputs_wrapper(&Control_Telegram_B.SFunctionBuilder_o1,
    &Control_Telegram_B.SFunctionBuilder_o2,
    &Control_Telegram_DW.SFunctionBuilder_DSTATE);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  Control_Telegram_B.DataTypeConversion[0] =
    Control_Telegram_B.SFunctionBuilder_o1;
  Control_Telegram_B.DataTypeConversion[1] =
    Control_Telegram_B.SFunctionBuilder_o2;

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  u0 = (real_T)Control_Telegram_B.SFunctionBuilder_o1 /
    Control_Telegram_P.Constant11_Value;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > Control_Telegram_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[0] = Control_Telegram_P.Saturation_UpperSat;
  } else if (u0 < Control_Telegram_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[0] = Control_Telegram_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[0] = u0;
  }

  /* Product: '<Root>/Divide' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  u0 = (real_T)Control_Telegram_B.SFunctionBuilder_o2 /
    Control_Telegram_P.Constant11_Value;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > Control_Telegram_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[1] = Control_Telegram_P.Saturation_UpperSat;
  } else if (u0 < Control_Telegram_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[1] = Control_Telegram_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Control_Telegram_B.Saturation[1] = u0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  u0 = floor(Control_Telegram_B.Saturation[0]);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  Control_Telegram_B.DataTypeConversion_g[0] = (uint8_T)(u0 < 0.0 ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-u0 : (int16_T)(uint8_T)u0);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  u0 = floor(Control_Telegram_B.Saturation[1]);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 256.0);
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  Control_Telegram_B.DataTypeConversion_g[1] = (uint8_T)(u0 < 0.0 ? (int16_T)
    (uint8_T)-(int8_T)(uint8_T)-u0 : (int16_T)(uint8_T)u0);

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   */
  if (Control_Telegram_M->Timing.RateInteraction.TID1_3) {
    Control_Telegram_DW.RateTransition_Buffer[0] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[1] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[2] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[3] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[4] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[5] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[6] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[7] =
      Control_Telegram_P.Constant6_Value;
    Control_Telegram_DW.RateTransition_Buffer[8] =
      Control_Telegram_P.Constant_Value_c;
    Control_Telegram_DW.RateTransition_Buffer[9] =
      Control_Telegram_B.DataTypeConversion_g[0];
    Control_Telegram_DW.RateTransition_Buffer[10] =
      Control_Telegram_P.Constant1_Value;
    Control_Telegram_DW.RateTransition_Buffer[11] =
      Control_Telegram_B.DataTypeConversion_g[1];
    Control_Telegram_DW.RateTransition_Buffer[12] =
      Control_Telegram_P.Constant3_Value;
    Control_Telegram_DW.RateTransition_Buffer[13] =
      Control_Telegram_P.Constant7_Value;
    Control_Telegram_DW.RateTransition_Buffer[14] =
      Control_Telegram_P.Constant4_Value;
    Control_Telegram_DW.RateTransition_Buffer[15] =
      Control_Telegram_P.Constant7_Value;
    Control_Telegram_DW.RateTransition_Buffer[16] =
      Control_Telegram_P.Constant5_Value;
    Control_Telegram_DW.RateTransition_Buffer[17] =
      Control_Telegram_P.Constant7_Value;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* SignalConversion generated from: '<Root>/Gain1' */
  Control_Telegram_B.TmpSignalConversionAtGain1Inpor[0] =
    Control_Telegram_B.SFunctionBuilder_o2;
  Control_Telegram_B.TmpSignalConversionAtGain1Inpor[1] =
    Control_Telegram_B.SFunctionBuilder_o1;

  /* Gain: '<Root>/Gain1' */
  tmp = (uint32_T)Control_Telegram_P.Gain1_Gain;
  tmp_0 = (uint32_T)Control_Telegram_B.TmpSignalConversionAtGain1Inpor[0];
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &Control_Telegram_B.Gain1[0].chunks[0U], 2);

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  u0_0 = &Control_Telegram_B.Gain1[0];
  if (sMultiWordGt(&u0_0->chunks[0U],
                   &Control_Telegram_P.Saturation1_UpperSat.chunks[0U], 2)) {
    u0_0 = &Control_Telegram_P.Saturation1_UpperSat;
  } else if (sMultiWordLt(&u0_0->chunks[0U],
                          &Control_Telegram_P.Saturation1_LowerSat.chunks[0U], 2))
  {
    u0_0 = &Control_Telegram_P.Saturation1_LowerSat;
  } else {
    u0_0 = &Control_Telegram_B.Gain1[0];
  }

  /* RateTransition generated from: '<Root>/Switch1' */
  Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[0] = *u0_0;

  /* Gain: '<Root>/Gain1' */
  tmp = (uint32_T)Control_Telegram_P.Gain1_Gain;
  tmp_0 = (uint32_T)Control_Telegram_B.TmpSignalConversionAtGain1Inpor[1];
  sMultiWordMul(&tmp, 1, &tmp_0, 1, &Control_Telegram_B.Gain1[1].chunks[0U], 2);

  /* Saturate: '<Root>/Saturation1' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  u0_0 = &Control_Telegram_B.Gain1[1];
  if (sMultiWordGt(&u0_0->chunks[0U],
                   &Control_Telegram_P.Saturation1_UpperSat.chunks[0U], 2)) {
    u0_0 = &Control_Telegram_P.Saturation1_UpperSat;
  } else if (sMultiWordLt(&u0_0->chunks[0U],
                          &Control_Telegram_P.Saturation1_LowerSat.chunks[0U], 2))
  {
    u0_0 = &Control_Telegram_P.Saturation1_LowerSat;
  } else {
    u0_0 = &Control_Telegram_B.Gain1[1];
  }

  /* RateTransition generated from: '<Root>/Switch1' */
  Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[1] = *u0_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/rojo parpadeando'
   *  DataStoreRead: '<S6>/Data Store Read'
   *  DataStoreWrite: '<S6>/Data Store Write'
   */
  if (Control_Telegram_DW.VBateria > Control_Telegram_P.Switch_Threshold_p) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Sum: '<S6>/Add'
     *  Switch: '<S6>/obs_dcha'
     */
    if (Control_Telegram_B.DataTypeConversion[1] -
        Control_Telegram_B.DataTypeConversion[0] >
        Control_Telegram_P.Switch1_Threshold) {
      /* Switch: '<S6>/obs_izq' */
      if (Control_Telegram_B.DataTypeConversion[0] >
          Control_Telegram_P.obs_izq_Threshold) {
        /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
         *  Constant: '<S6>/verde'
         */
        Control_Telegram_DW.led = Control_Telegram_P.verde_Value;
      } else {
        /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
         *  Constant: '<S6>/azul (obs_izq)'
         */
        Control_Telegram_DW.led = Control_Telegram_P.azulobs_izq_Value;
      }

      /* End of Switch: '<S6>/obs_izq' */
    } else if (Control_Telegram_B.DataTypeConversion[1] >
               Control_Telegram_P.obs_dcha_Threshold) {
      /* Switch: '<S6>/obs_dcha' incorporates:
       *  Constant: '<S6>/verde'
       *  DataStoreWrite: '<S6>/Data Store Write'
       */
      Control_Telegram_DW.led = Control_Telegram_P.verde_Value;
    } else {
      /* DataStoreWrite: '<S6>/Data Store Write' incorporates:
       *  Constant: '<S6>/amarillo (obs_dcha)'
       */
      Control_Telegram_DW.led = Control_Telegram_P.amarilloobs_dcha_Value;
    }

    /* End of Switch: '<S6>/Switch1' */
  } else {
    Control_Telegram_DW.led = Control_Telegram_P.rojoparpadeando_Value;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Update for S-Function (Sensores_VL53L0X_I2C): '<S9>/S-Function Builder' */

  /* S-Function "Sensores_VL53L0X_I2C_wrapper" Block: <S9>/S-Function Builder */
  Sensores_VL53L0X_I2C_Update_wrapper(&Control_Telegram_B.SFunctionBuilder_o1,
    &Control_Telegram_B.SFunctionBuilder_o2,
    &Control_Telegram_DW.SFunctionBuilder_DSTATE);
  rtExtModeUpload(1, (real_T)((Control_Telegram_M->Timing.clockTick1) * 0.03));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.03, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Control_Telegram_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Control_Telegram_step2(void)      /* Sample time: [1.0s, 0.0s] */
{
  codertarget_arduinobase_in_hr_T *obj;
  uint16_T rtb_Bateria_0;

  /* MATLABSystem: '<S8>/Bateria' */
  if (Control_Telegram_DW.obj_c.SampleTime !=
      Control_Telegram_P.Bateria_SampleTime) {
    Control_Telegram_DW.obj_c.SampleTime = Control_Telegram_P.Bateria_SampleTime;
  }

  obj = &Control_Telegram_DW.obj_c;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  MW_AnalogInSingle_ReadResult
    (Control_Telegram_DW.obj_c.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &rtb_Bateria_0, 3);

  /* Gain: '<S8>/Gain' incorporates:
   *  DataStoreWrite: '<S8>/Data Store Write1'
   *  MATLABSystem: '<S8>/Bateria'
   */
  Control_Telegram_DW.VBateria = (real_T)Control_Telegram_P.Gain_Gain_n *
    4.76837158203125E-7 * (real_T)rtb_Bateria_0;
  rtExtModeUpload(2, (real_T)((Control_Telegram_M->Timing.clockTick2) * 1.0));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Control_Telegram_M->Timing.clockTick2++;
}

/* Model step function for TID3 */
void Control_Telegram_step3(void)      /* Sample time: [1.05s, 0.0s] */
{
  static const char_T tmp[9] = "sensores";
  int16_T i;
  char_T labelTerminated[9];
  uint8_T dataIn[18];
  for (i = 0; i < 18; i++) {
    /* RateTransition: '<Root>/Rate Transition' */
    Control_Telegram_B.RateTransition[i] =
      Control_Telegram_DW.RateTransition_Buffer[i];
  }

  /* MATLABSystem: '<Root>/Serial Transmit' */
  if (Control_Telegram_DW.obj.Protocol !=
      Control_Telegram_P.SerialTransmit_Protocol) {
    Control_Telegram_DW.obj.Protocol =
      Control_Telegram_P.SerialTransmit_Protocol;
  }

  for (i = 0; i < 18; i++) {
    dataIn[i] = Control_Telegram_B.RateTransition[i];
  }

  for (i = 0; i < 9; i++) {
    labelTerminated[i] = tmp[i];
  }

  MW_Serial_write(Control_Telegram_DW.obj.port, &dataIn[0], 18.0,
                  Control_Telegram_DW.obj.dataSizeInBytes,
                  Control_Telegram_DW.obj.sendModeEnum,
                  Control_Telegram_DW.obj.dataType,
                  Control_Telegram_DW.obj.sendFormatEnum, 2.0, &labelTerminated
                  [0]);

  /* End of MATLABSystem: '<Root>/Serial Transmit' */
  rtExtModeUpload(3, (real_T)((Control_Telegram_M->Timing.clockTick3) * 1.05));

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.05, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Control_Telegram_M->Timing.clockTick3++;
}

/* Model initialize function */
void Control_Telegram_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(Control_Telegram_M, -1);
  Control_Telegram_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Control_Telegram_M->Sizes.checksums[0] = (381385820U);
  Control_Telegram_M->Sizes.checksums[1] = (3917662077U);
  Control_Telegram_M->Sizes.checksums[2] = (3816226728U);
  Control_Telegram_M->Sizes.checksums[3] = (1364095386U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
    Control_Telegram_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &Control_Telegram_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Control_Telegram_M->extModeInfo,
      &Control_Telegram_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Control_Telegram_M->extModeInfo,
                        Control_Telegram_M->Sizes.checksums);
    rteiSetTPtr(Control_Telegram_M->extModeInfo, rtmGetTPtr(Control_Telegram_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Control_Telegram_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 44;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_in_hr_T *obj_0;
    codertarget_arduinobase_int_h_T *obj;
    real_T tmp;
    uint8_T tmp_0;

    /* Start for RateTransition generated from: '<Root>/Switch1' */
    Control_Telegram_B.TmpRTBAtSwitch1Inport1[0] =
      Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC;
    Control_Telegram_B.TmpRTBAtSwitch1Inport1[1] =
      Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    Control_Telegram_DW.led = Control_Telegram_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    Control_Telegram_DW.VBateria =
      Control_Telegram_P.DataStoreMemory1_InitialValue;

    /* InitializeConditions for S-Function (MisEncoders): '<S112>/encoders' */

    /* S-Function Block: <S112>/encoders */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Control_Telegram_DW.encoders_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for UnitDelay: '<S113>/UD'
     *
     * Block description for '<S113>/UD':
     *
     *  Store in Global RAM
     */
    Control_Telegram_DW.UD_DSTATE[0] =
      Control_Telegram_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateTransition generated from: '<Root>/Switch1' */
    Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[0] =
      Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC;

    /* InitializeConditions for UnitDelay: '<S113>/UD'
     *
     * Block description for '<S113>/UD':
     *
     *  Store in Global RAM
     */
    Control_Telegram_DW.UD_DSTATE[1] =
      Control_Telegram_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateTransition generated from: '<Root>/Switch1' */
    Control_Telegram_DW.TmpRTBAtSwitch1Inport1_Buffer0[1] =
      Control_Telegram_P.TmpRTBAtSwitch1Inport1_InitialC;

    /* InitializeConditions for Memory: '<S7>/Memory' */
    Control_Telegram_DW.Memory_PreviousInput[0] =
      Control_Telegram_P.Memory_InitialCondition;
    Control_Telegram_DW.Memory_PreviousInput[1] =
      Control_Telegram_P.Memory_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S93>/Integrator' */
    Control_Telegram_DW.Integrator_DSTATE =
      Control_Telegram_P.PIDIzda_InitialConditionForInte;

    /* InitializeConditions for DiscreteIntegrator: '<S88>/Filter' */
    Control_Telegram_DW.Filter_DSTATE =
      Control_Telegram_P.PIDIzda_InitialConditionForFilt;

    /* InitializeConditions for DiscreteIntegrator: '<S45>/Integrator' */
    Control_Telegram_DW.Integrator_DSTATE_o =
      Control_Telegram_P.PIDDcha_InitialConditionForInte;

    /* InitializeConditions for DiscreteIntegrator: '<S40>/Filter' */
    Control_Telegram_DW.Filter_DSTATE_o =
      Control_Telegram_P.PIDDcha_InitialConditionForFilt;

    /* InitializeConditions for DiscreteFilter: '<S111>/Mdelo Rueda Izda' */
    Control_Telegram_DW.MdeloRuedaIzda_states =
      Control_Telegram_P.MdeloRuedaIzda_InitialStates;

    /* InitializeConditions for DiscreteFilter: '<S111>/Mdelo Rueda Dcha' */
    Control_Telegram_DW.MdeloRuedaDcha_states =
      Control_Telegram_P.MdeloRuedaDcha_InitialStates;

    /* InitializeConditions for S-Function (Sensores_VL53L0X_I2C): '<S9>/S-Function Builder' */

    /* S-Function Block: <S9>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          Control_Telegram_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S3>/q' incorporates:
     *  Inport: '<S3>/In1'
     */
    Control_Telegram_B.In1 = Control_Telegram_P.q_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Control_Telegram_DW.obj_b.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_b.Protocol =
      Control_Telegram_P.SerialReceive_Protocol;
    Control_Telegram_DW.obj_b.isInitialized = 1L;
    Control_Telegram_DW.obj_b.DataTypeWidth = 1U;
    Control_Telegram_DW.obj_b.DataSizeInBytes =
      Control_Telegram_DW.obj_b.DataTypeWidth;
    MW_SCI_Open(3);
    Control_Telegram_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Dcha_Adelante' */
    Control_Telegram_DW.obj_l.matlabCodegenIsDeleted = true;
    Control_Telegram_DW.obj_l.isInitialized = 0L;
    Control_Telegram_DW.obj_l.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_l.PinPWM = 8UL;
    obj = &Control_Telegram_DW.obj_l;
    Control_Telegram_DW.obj_l.isSetupComplete = false;
    Control_Telegram_DW.obj_l.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(Control_Telegram_DW.obj_l.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_l.PinPWM);
    MW_PWM_Start(Control_Telegram_DW.obj_l.MW_PWM_HANDLE);
    Control_Telegram_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Dcha_Atras' */
    Control_Telegram_DW.obj_n.matlabCodegenIsDeleted = true;
    Control_Telegram_DW.obj_n.isInitialized = 0L;
    Control_Telegram_DW.obj_n.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_n.PinPWM = 7UL;
    obj = &Control_Telegram_DW.obj_n;
    Control_Telegram_DW.obj_n.isSetupComplete = false;
    Control_Telegram_DW.obj_n.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(Control_Telegram_DW.obj_n.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_n.PinPWM);
    MW_PWM_Start(Control_Telegram_DW.obj_n.MW_PWM_HANDLE);
    Control_Telegram_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Digital Output2' */
    Control_Telegram_DW.obj_eu.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_eu.isInitialized = 1L;
    digitalIOSetup(6, 1);
    Control_Telegram_DW.obj_eu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Digital Output4' */
    Control_Telegram_DW.obj_e.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_e.isInitialized = 1L;
    digitalIOSetup(11, 1);
    Control_Telegram_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Izq_Atras' */
    Control_Telegram_DW.obj_d.matlabCodegenIsDeleted = true;
    Control_Telegram_DW.obj_d.isInitialized = 0L;
    Control_Telegram_DW.obj_d.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_d.PinPWM = 10UL;
    obj = &Control_Telegram_DW.obj_d;
    Control_Telegram_DW.obj_d.isSetupComplete = false;
    Control_Telegram_DW.obj_d.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(Control_Telegram_DW.obj_d.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_d.PinPWM);
    MW_PWM_Start(Control_Telegram_DW.obj_d.MW_PWM_HANDLE);
    Control_Telegram_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S114>/Izq_Adelante' */
    Control_Telegram_DW.obj_p.matlabCodegenIsDeleted = true;
    Control_Telegram_DW.obj_p.isInitialized = 0L;
    Control_Telegram_DW.obj_p.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_p.PinPWM = 9UL;
    obj = &Control_Telegram_DW.obj_p;
    Control_Telegram_DW.obj_p.isSetupComplete = false;
    Control_Telegram_DW.obj_p.isInitialized = 1L;
    obj->MW_PWM_HANDLE = MW_PWM_Open(Control_Telegram_DW.obj_p.PinPWM, 0.0, 0.0);
    obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_p.PinPWM);
    MW_PWM_Start(Control_Telegram_DW.obj_p.MW_PWM_HANDLE);
    Control_Telegram_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Blue' */
    Control_Telegram_DW.obj_l0.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_l0.isInitialized = 1L;
    digitalIOSetup(49, 1);
    Control_Telegram_DW.obj_l0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Green' */
    Control_Telegram_DW.obj_j.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(53, 1);
    Control_Telegram_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Red' */
    Control_Telegram_DW.obj_m.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_m.isInitialized = 1L;
    digitalIOSetup(51, 1);
    Control_Telegram_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Bateria' */
    Control_Telegram_DW.obj_c.matlabCodegenIsDeleted = true;
    Control_Telegram_DW.obj_c.isInitialized = 0L;
    Control_Telegram_DW.obj_c.SampleTime = -1.0;
    Control_Telegram_DW.obj_c.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj_c.SampleTime = Control_Telegram_P.Bateria_SampleTime;
    obj_0 = &Control_Telegram_DW.obj_c;
    Control_Telegram_DW.obj_c.isSetupComplete = false;
    Control_Telegram_DW.obj_c.isInitialized = 1L;
    obj_0->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    Control_Telegram_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Serial Transmit' */
    Control_Telegram_DW.obj.matlabCodegenIsDeleted = false;
    Control_Telegram_DW.obj.Protocol =
      Control_Telegram_P.SerialTransmit_Protocol;
    Control_Telegram_DW.obj.isInitialized = 1L;
    Control_Telegram_DW.obj.port = 3.0;
    Control_Telegram_DW.obj.dataSizeInBytes = 1.0;
    Control_Telegram_DW.obj.dataType = 0.0;
    Control_Telegram_DW.obj.sendModeEnum = 0.0;
    Control_Telegram_DW.obj.sendFormatEnum = 0.0;
    tmp = rt_roundd_snf(Control_Telegram_DW.obj.port);
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    MW_SCI_Open(tmp_0);
    Control_Telegram_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Serial Transmit' */
  }
}

/* Model terminate function */
void Control_Telegram_terminate(void)
{
  codertarget_arduinobase_in_hr_T *obj_0;
  codertarget_arduinobase_int_h_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Control_Telegram_DW.obj_b.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S114>/Dcha_Adelante' */
  obj = &Control_Telegram_DW.obj_l;
  if (!Control_Telegram_DW.obj_l.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Control_Telegram_DW.obj_l.isInitialized == 1L) &&
        Control_Telegram_DW.obj_l.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_l.PinPWM);
      MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_l.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_l.PinPWM);
      MW_PWM_Close(Control_Telegram_DW.obj_l.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S114>/Dcha_Adelante' */

  /* Terminate for MATLABSystem: '<S114>/Dcha_Atras' */
  obj = &Control_Telegram_DW.obj_n;
  if (!Control_Telegram_DW.obj_n.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Control_Telegram_DW.obj_n.isInitialized == 1L) &&
        Control_Telegram_DW.obj_n.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_n.PinPWM);
      MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_n.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_n.PinPWM);
      MW_PWM_Close(Control_Telegram_DW.obj_n.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S114>/Dcha_Atras' */

  /* Terminate for MATLABSystem: '<S114>/Digital Output2' */
  if (!Control_Telegram_DW.obj_eu.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_eu.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S114>/Digital Output2' */

  /* Terminate for MATLABSystem: '<S114>/Digital Output4' */
  if (!Control_Telegram_DW.obj_e.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S114>/Digital Output4' */

  /* Terminate for MATLABSystem: '<S114>/Izq_Atras' */
  obj = &Control_Telegram_DW.obj_d;
  if (!Control_Telegram_DW.obj_d.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Control_Telegram_DW.obj_d.isInitialized == 1L) &&
        Control_Telegram_DW.obj_d.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_d.PinPWM);
      MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_d.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_d.PinPWM);
      MW_PWM_Close(Control_Telegram_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S114>/Izq_Atras' */

  /* Terminate for MATLABSystem: '<S114>/Izq_Adelante' */
  obj = &Control_Telegram_DW.obj_p;
  if (!Control_Telegram_DW.obj_p.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Control_Telegram_DW.obj_p.isInitialized == 1L) &&
        Control_Telegram_DW.obj_p.isSetupComplete) {
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_p.PinPWM);
      MW_PWM_SetDutyCycle(Control_Telegram_DW.obj_p.MW_PWM_HANDLE, 0.0);
      obj->MW_PWM_HANDLE = MW_PWM_GetHandle(Control_Telegram_DW.obj_p.PinPWM);
      MW_PWM_Close(Control_Telegram_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S114>/Izq_Adelante' */

  /* Terminate for MATLABSystem: '<S2>/Blue' */
  if (!Control_Telegram_DW.obj_l0.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_l0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Blue' */

  /* Terminate for MATLABSystem: '<S2>/Green' */
  if (!Control_Telegram_DW.obj_j.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Green' */

  /* Terminate for MATLABSystem: '<S2>/Red' */
  if (!Control_Telegram_DW.obj_m.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Red' */

  /* Terminate for MATLABSystem: '<S8>/Bateria' */
  obj_0 = &Control_Telegram_DW.obj_c;
  if (!Control_Telegram_DW.obj_c.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Control_Telegram_DW.obj_c.isInitialized == 1L) &&
        Control_Telegram_DW.obj_c.isSetupComplete) {
      obj_0->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close(obj_0->AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Bateria' */

  /* Terminate for MATLABSystem: '<Root>/Serial Transmit' */
  if (!Control_Telegram_DW.obj.matlabCodegenIsDeleted) {
    Control_Telegram_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
