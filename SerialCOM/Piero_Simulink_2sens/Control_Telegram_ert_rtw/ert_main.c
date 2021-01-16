/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
boolean_T isRateRunning[4] = { 0, 0, 0, 0 };

boolean_T need2runFlags[4] = { 0, 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[4];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  Control_Telegram_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  Control_Telegram_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  isRateRunning[0]--;
  for (i = 1; i < 4; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 4; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;

#ifndef _MW_ARDUINO_LOOP_

      sei();

#endif;

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        Control_Telegram_step1();

        /* Get model outputs here */
        break;

       case 2 :
        Control_Telegram_step2();

        /* Get model outputs here */
        break;

       case 3 :
        Control_Telegram_step3();

        /* Get model outputs here */
        break;

       default :
        break;
      }

#ifndef _MW_ARDUINO_LOOP_

      cli();

#endif;

      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }

  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.01;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Control_Telegram_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  Control_Telegram_initialize();
  cli();
  sei();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Control_Telegram_M));
  rtExtModeCheckInit(4);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Control_Telegram_M->extModeInfo, 4, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Control_Telegram_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(Control_Telegram_M) == (NULL)) && !rtmGetStopRequested
    (Control_Telegram_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Control_Telegram_M->extModeInfo, 4, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Control_Telegram_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(Control_Telegram_M) == (NULL)) &&
                      !rtmGetStopRequested(Control_Telegram_M));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Control_Telegram_terminate();
  rtExtModeShutdown(4);
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
