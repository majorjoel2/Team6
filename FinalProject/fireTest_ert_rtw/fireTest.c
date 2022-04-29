/*
 * fireTest.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "fireTest".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sun Apr 24 18:15:09 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "fireTest.h"
#include "fireTest_private.h"

/* Block states (default storage) */
DW_fireTest_T fireTest_DW;

/* Real-time model */
static RT_MODEL_fireTest_T fireTest_M_;
RT_MODEL_fireTest_T *const fireTest_M = &fireTest_M_;
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

/* Model step function */
void fireTest_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/pinState'
   */
  tmp = rt_roundd_snf(fireTest_P.pinState_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  writeDigitalPin(9, tmp_0);

  /* End of MATLABSystem: '<Root>/Digital Output' */
  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++fireTest_M->Timing.clockTick0)) {
    ++fireTest_M->Timing.clockTickH0;
  }

  fireTest_M->Timing.taskTime0 = fireTest_M->Timing.clockTick0 *
    fireTest_M->Timing.stepSize0 + fireTest_M->Timing.clockTickH0 *
    fireTest_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void fireTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)fireTest_M, 0,
                sizeof(RT_MODEL_fireTest_T));
  rtmSetTFinal(fireTest_M, -1);
  fireTest_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  fireTest_M->Sizes.checksums[0] = (1293902971U);
  fireTest_M->Sizes.checksums[1] = (1073332950U);
  fireTest_M->Sizes.checksums[2] = (1579519827U);
  fireTest_M->Sizes.checksums[3] = (4187657359U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    fireTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(fireTest_M->extModeInfo,
      &fireTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(fireTest_M->extModeInfo, fireTest_M->Sizes.checksums);
    rteiSetTPtr(fireTest_M->extModeInfo, rtmGetTPtr(fireTest_M));
  }

  /* states (dwork) */
  (void) memset((void *)&fireTest_DW, 0,
                sizeof(DW_fireTest_T));

  /* Start for MATLABSystem: '<Root>/Digital Output' */
  fireTest_DW.obj.matlabCodegenIsDeleted = false;
  fireTest_DW.objisempty = true;
  fireTest_DW.obj.isInitialized = 1L;
  digitalIOSetup(9, 1);
  fireTest_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void fireTest_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!fireTest_DW.obj.matlabCodegenIsDeleted) {
    fireTest_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */
}
