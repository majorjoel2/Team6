#include "motor_model_updated_F21.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  motor_model_updated_F21_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.001;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(motor_model_updated_F21_M, 0);
  motor_model_updated_F21_initialize();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(motor_model_updated_F21_M) == (NULL)) &&
    !rtmGetStopRequested(motor_model_updated_F21_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    stopRequested = !(
                      (rtmGetErrorStatus(motor_model_updated_F21_M) == (NULL)) &&
                      !rtmGetStopRequested(motor_model_updated_F21_M));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Terminate model */
  motor_model_updated_F21_terminate();
  cli();
  return 0;
}
