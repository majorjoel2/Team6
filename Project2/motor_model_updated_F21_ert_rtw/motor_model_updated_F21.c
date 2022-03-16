/*
 * motor_model_updated_F21.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motor_model_updated_F21".
 *
 * Model version              : 4.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Mar  9 17:41:43 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_model_updated_F21.h"
#include "motor_model_updated_F21_private.h"

/* Block signals (default storage) */
B_motor_model_updated_F21_T motor_model_updated_F21_B;

/* Continuous states */
X_motor_model_updated_F21_T motor_model_updated_F21_X;

/* Block states (default storage) */
DW_motor_model_updated_F21_T motor_model_updated_F21_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_motor_model_updated_F21_T motor_model_updated_F21_Y;

/* Real-time model */
static RT_MODEL_motor_model_updated__T motor_model_updated_F21_M_;
RT_MODEL_motor_model_updated__T *const motor_model_updated_F21_M =
  &motor_model_updated_F21_M_;
const int64m_T motor_model_updated_F21_sfix64_ = { { 0UL, 0UL }/* chunks */
};

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

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  motor_model_updated_F21_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  motor_model_updated_F21_step();
  motor_model_updated_F21_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  motor_model_updated_F21_step();
  motor_model_updated_F21_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  motor_model_updated_F21_step();
  motor_model_updated_F21_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S2>/Motor Direction1'
 *    '<S2>/Motor Direction 2'
 *    '<S2>/Constant Position'
 */
void motor_model_upd_MotorDirection1(RT_MODEL_motor_model_updated__T * const
  motor_model_updated_F21_M, real_T *rty_IN1, real_T *rty_IN2,
  P_MotorDirection1_motor_model_T *localP)
{
  if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
    /* Constant: '<S5>/Constant' */
    *rty_IN1 = localP->Constant_Value;

    /* Constant: '<S5>/Constant1' */
    *rty_IN2 = localP->Constant1_Value;
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

/* Model step function */
void motor_model_updated_F21_step(void)
{
  /* local block i/o variables */
  real_T rtb_Merge1;
  real_T rtb_Merge2;
  if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
    /* set solver stop time */
    if (!(motor_model_updated_F21_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&motor_model_updated_F21_M->solverInfo,
                            ((motor_model_updated_F21_M->Timing.clockTickH0 + 1)
        * motor_model_updated_F21_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&motor_model_updated_F21_M->solverInfo,
                            ((motor_model_updated_F21_M->Timing.clockTick0 + 1) *
        motor_model_updated_F21_M->Timing.stepSize0 +
        motor_model_updated_F21_M->Timing.clockTickH0 *
        motor_model_updated_F21_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(motor_model_updated_F21_M)) {
    motor_model_updated_F21_M->Timing.t[0] = rtsiGetT
      (&motor_model_updated_F21_M->solverInfo);
  }

  {
    codertarget_arduinobase_inter_T *obj;
    real_T rtb_Abs;
    real_T rtb_Abs1;
    real_T *lastU;
    int32_T rtb_Encoder_0;
    uint32_T tmp;
    uint32_T tmp_0;
    uint8_T tmp_1;

    /* MATLABSystem: '<S2>/Encoder' */
    if (motor_model_updated_F21_DW.obj.SampleTime !=
        motor_model_updated_F21_P.Encoder_SampleTime) {
      motor_model_updated_F21_DW.obj.SampleTime =
        motor_model_updated_F21_P.Encoder_SampleTime;
    }

    if (motor_model_updated_F21_DW.obj.TunablePropsChanged) {
      motor_model_updated_F21_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(motor_model_updated_F21_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' incorporates:
     *  MATLABSystem: '<S2>/Encoder'
     */
    tmp = (uint32_T)motor_model_updated_F21_P.angular_positionrelative_countC;
    tmp_0 = (uint32_T)rtb_Encoder_0;
    sMultiWordMul(&tmp, 1, &tmp_0, 1,
                  &motor_model_updated_F21_B.angular_positionrelative_countC.chunks
                  [0U], 2);

    /* Outport: '<Root>/motorPos_Out' incorporates:
     *  Gain: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
     */
    motor_model_updated_F21_Y.motorPos_Out =
      motor_model_updated_F21_B.angular_positionrelative_countC;
    if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
      /* Gain: '<Root>/gain' incorporates:
       *  Constant: '<Root>/desiredPosition'
       */
      motor_model_updated_F21_B.Setpoint = motor_model_updated_F21_P.gain_Gain *
        motor_model_updated_F21_P.desiredPosition_Value;
    }

    /* Sum: '<Root>/Sum1' */
    motor_model_updated_F21_B.ErrorSignal = motor_model_updated_F21_B.Setpoint -
      sMultiWord2Double
      (&motor_model_updated_F21_B.angular_positionrelative_countC.chunks[0U], 2,
       0) * 4.6566128730773926E-10;

    /* Derivative: '<S1>/Derivative1' */
    rtb_Abs = motor_model_updated_F21_M->Timing.t[0];
    if ((motor_model_updated_F21_DW.TimeStampA >= rtb_Abs) &&
        (motor_model_updated_F21_DW.TimeStampB >= rtb_Abs)) {
      rtb_Abs = 0.0;
    } else {
      rtb_Abs1 = motor_model_updated_F21_DW.TimeStampA;
      lastU = &motor_model_updated_F21_DW.LastUAtTimeA;
      if (motor_model_updated_F21_DW.TimeStampA <
          motor_model_updated_F21_DW.TimeStampB) {
        if (motor_model_updated_F21_DW.TimeStampB < rtb_Abs) {
          rtb_Abs1 = motor_model_updated_F21_DW.TimeStampB;
          lastU = &motor_model_updated_F21_DW.LastUAtTimeB;
        }
      } else if (motor_model_updated_F21_DW.TimeStampA >= rtb_Abs) {
        rtb_Abs1 = motor_model_updated_F21_DW.TimeStampB;
        lastU = &motor_model_updated_F21_DW.LastUAtTimeB;
      }

      rtb_Abs = (motor_model_updated_F21_B.ErrorSignal - *lastU) / (rtb_Abs -
        rtb_Abs1);
    }

    /* End of Derivative: '<S1>/Derivative1' */

    /* Sum: '<S1>/Sum4' incorporates:
     *  Gain: '<S1>/Kd'
     *  Gain: '<S1>/Ki'
     *  Gain: '<S1>/Kp'
     *  Integrator: '<S1>/Integrator1'
     */
    rtb_Abs = (motor_model_updated_F21_P.Kp_Gain *
               motor_model_updated_F21_B.ErrorSignal +
               motor_model_updated_F21_P.Kd_Gain * rtb_Abs) +
      motor_model_updated_F21_P.Ki_Gain *
      motor_model_updated_F21_X.Integrator1_CSTATE;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Abs > motor_model_updated_F21_P.Saturation_UpperSat) {
      rtb_Abs = motor_model_updated_F21_P.Saturation_UpperSat;
    } else if (rtb_Abs < motor_model_updated_F21_P.Saturation_LowerSat) {
      rtb_Abs = motor_model_updated_F21_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Abs: '<S2>/Abs1' */
    rtb_Abs1 = fabs(motor_model_updated_F21_B.ErrorSignal);

    /* If: '<S2>/Choose Direction' */
    if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
      if ((rtb_Abs > 0.0) && (rtb_Abs1 > 3.0)) {
        motor_model_updated_F21_DW.ChooseDirection_ActiveSubsystem = 0;
      } else if ((rtb_Abs < 0.0) && (rtb_Abs1 > 3.0)) {
        motor_model_updated_F21_DW.ChooseDirection_ActiveSubsystem = 1;
      } else {
        motor_model_updated_F21_DW.ChooseDirection_ActiveSubsystem = 2;
      }
    }

    switch (motor_model_updated_F21_DW.ChooseDirection_ActiveSubsystem) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S2>/Motor Direction1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      motor_model_upd_MotorDirection1(motor_model_updated_F21_M, &rtb_Merge1,
        &rtb_Merge2, &motor_model_updated_F21_P.MotorDirection1);

      /* End of Outputs for SubSystem: '<S2>/Motor Direction1' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S2>/Motor Direction 2' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      motor_model_upd_MotorDirection1(motor_model_updated_F21_M, &rtb_Merge1,
        &rtb_Merge2, &motor_model_updated_F21_P.MotorDirection2);

      /* End of Outputs for SubSystem: '<S2>/Motor Direction 2' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S2>/Constant Position' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      motor_model_upd_MotorDirection1(motor_model_updated_F21_M, &rtb_Merge1,
        &rtb_Merge2, &motor_model_updated_F21_P.ConstantPosition);

      /* End of Outputs for SubSystem: '<S2>/Constant Position' */
      break;
    }

    /* End of If: '<S2>/Choose Direction' */

    /* MATLABSystem: '<S2>/Enable' */
    obj = &motor_model_updated_F21_DW.obj_b;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

    /* Gain: '<S2>/Gain' incorporates:
     *  Abs: '<S2>/Abs'
     */
    rtb_Abs = motor_model_updated_F21_P.Gain_Gain * fabs(rtb_Abs);

    /* MATLABSystem: '<S2>/Enable' */
    if (!(rtb_Abs <= 255.0)) {
      rtb_Abs = 255.0;
    }

    if (!(rtb_Abs >= 0.0)) {
      rtb_Abs = 0.0;
    }

    MW_PWM_SetDutyCycle
      (motor_model_updated_F21_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, rtb_Abs);
    if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
      /* MATLABSystem: '<S2>/Driver In1' */
      rtb_Abs = rt_roundd_snf(rtb_Merge1);
      if (rtb_Abs < 256.0) {
        if (rtb_Abs >= 0.0) {
          tmp_1 = (uint8_T)rtb_Abs;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint8_T;
      }

      writeDigitalPin(30, tmp_1);

      /* End of MATLABSystem: '<S2>/Driver In1' */

      /* MATLABSystem: '<S2>/Driver In2' */
      rtb_Abs = rt_roundd_snf(rtb_Merge2);
      if (rtb_Abs < 256.0) {
        if (rtb_Abs >= 0.0) {
          tmp_1 = (uint8_T)rtb_Abs;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint8_T;
      }

      writeDigitalPin(31, tmp_1);

      /* End of MATLABSystem: '<S2>/Driver In2' */
    }
  }

  if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S1>/Derivative1' */
    if (motor_model_updated_F21_DW.TimeStampA == (rtInf)) {
      motor_model_updated_F21_DW.TimeStampA =
        motor_model_updated_F21_M->Timing.t[0];
      lastU = &motor_model_updated_F21_DW.LastUAtTimeA;
    } else if (motor_model_updated_F21_DW.TimeStampB == (rtInf)) {
      motor_model_updated_F21_DW.TimeStampB =
        motor_model_updated_F21_M->Timing.t[0];
      lastU = &motor_model_updated_F21_DW.LastUAtTimeB;
    } else if (motor_model_updated_F21_DW.TimeStampA <
               motor_model_updated_F21_DW.TimeStampB) {
      motor_model_updated_F21_DW.TimeStampA =
        motor_model_updated_F21_M->Timing.t[0];
      lastU = &motor_model_updated_F21_DW.LastUAtTimeA;
    } else {
      motor_model_updated_F21_DW.TimeStampB =
        motor_model_updated_F21_M->Timing.t[0];
      lastU = &motor_model_updated_F21_DW.LastUAtTimeB;
    }

    *lastU = motor_model_updated_F21_B.ErrorSignal;

    /* End of Update for Derivative: '<S1>/Derivative1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(motor_model_updated_F21_M)) {
    rt_ertODEUpdateContinuousStates(&motor_model_updated_F21_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++motor_model_updated_F21_M->Timing.clockTick0)) {
      ++motor_model_updated_F21_M->Timing.clockTickH0;
    }

    motor_model_updated_F21_M->Timing.t[0] = rtsiGetSolverStopTime
      (&motor_model_updated_F21_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      motor_model_updated_F21_M->Timing.clockTick1++;
      if (!motor_model_updated_F21_M->Timing.clockTick1) {
        motor_model_updated_F21_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void motor_model_updated_F21_derivatives(void)
{
  XDot_motor_model_updated_F21_T *_rtXdot;
  _rtXdot = ((XDot_motor_model_updated_F21_T *)
             motor_model_updated_F21_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = motor_model_updated_F21_B.ErrorSignal;
}

/* Model initialize function */
void motor_model_updated_F21_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motor_model_updated_F21_M, 0,
                sizeof(RT_MODEL_motor_model_updated__T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_model_updated_F21_M->solverInfo,
                          &motor_model_updated_F21_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_model_updated_F21_M->solverInfo, &rtmGetTPtr
                (motor_model_updated_F21_M));
    rtsiSetStepSizePtr(&motor_model_updated_F21_M->solverInfo,
                       &motor_model_updated_F21_M->Timing.stepSize0);
    rtsiSetdXPtr(&motor_model_updated_F21_M->solverInfo,
                 &motor_model_updated_F21_M->derivs);
    rtsiSetContStatesPtr(&motor_model_updated_F21_M->solverInfo, (real_T **)
                         &motor_model_updated_F21_M->contStates);
    rtsiSetNumContStatesPtr(&motor_model_updated_F21_M->solverInfo,
      &motor_model_updated_F21_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&motor_model_updated_F21_M->solverInfo,
      &motor_model_updated_F21_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&motor_model_updated_F21_M->solverInfo,
      &motor_model_updated_F21_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&motor_model_updated_F21_M->solverInfo,
      &motor_model_updated_F21_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&motor_model_updated_F21_M->solverInfo,
                          (&rtmGetErrorStatus(motor_model_updated_F21_M)));
    rtsiSetRTModelPtr(&motor_model_updated_F21_M->solverInfo,
                      motor_model_updated_F21_M);
  }

  rtsiSetSimTimeStep(&motor_model_updated_F21_M->solverInfo, MAJOR_TIME_STEP);
  motor_model_updated_F21_M->intgData.y = motor_model_updated_F21_M->odeY;
  motor_model_updated_F21_M->intgData.f[0] = motor_model_updated_F21_M->odeF[0];
  motor_model_updated_F21_M->intgData.f[1] = motor_model_updated_F21_M->odeF[1];
  motor_model_updated_F21_M->intgData.f[2] = motor_model_updated_F21_M->odeF[2];
  motor_model_updated_F21_M->intgData.f[3] = motor_model_updated_F21_M->odeF[3];
  motor_model_updated_F21_M->contStates = ((X_motor_model_updated_F21_T *)
    &motor_model_updated_F21_X);
  rtsiSetSolverData(&motor_model_updated_F21_M->solverInfo, (void *)
                    &motor_model_updated_F21_M->intgData);
  rtsiSetSolverName(&motor_model_updated_F21_M->solverInfo,"ode4");
  rtmSetTPtr(motor_model_updated_F21_M,
             &motor_model_updated_F21_M->Timing.tArray[0]);
  motor_model_updated_F21_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &motor_model_updated_F21_B), 0,
                sizeof(B_motor_model_updated_F21_T));

  /* states (continuous) */
  {
    (void) memset((void *)&motor_model_updated_F21_X, 0,
                  sizeof(X_motor_model_updated_F21_T));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_model_updated_F21_DW, 0,
                sizeof(DW_motor_model_updated_F21_T));

  /* external outputs */
  motor_model_updated_F21_Y.motorPos_Out = motor_model_updated_F21_sfix64_;

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<S2>/Encoder' */
    motor_model_updated_F21_DW.obj.Index = 0U;
    motor_model_updated_F21_DW.obj.matlabCodegenIsDeleted = false;
    motor_model_updated_F21_DW.objisempty = true;
    motor_model_updated_F21_DW.obj.SampleTime =
      motor_model_updated_F21_P.Encoder_SampleTime;
    motor_model_updated_F21_DW.obj.isSetupComplete = false;
    motor_model_updated_F21_DW.obj.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &motor_model_updated_F21_DW.obj.Index);
    motor_model_updated_F21_DW.obj.isSetupComplete = true;
    motor_model_updated_F21_DW.obj.TunablePropsChanged = false;

    /* Start for If: '<S2>/Choose Direction' */
    motor_model_updated_F21_DW.ChooseDirection_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<S2>/Enable' */
    motor_model_updated_F21_DW.obj_b.matlabCodegenIsDeleted = true;
    motor_model_updated_F21_DW.obj_b.isInitialized = 0L;
    motor_model_updated_F21_DW.obj_b.matlabCodegenIsDeleted = false;
    motor_model_updated_F21_DW.objisempty_k = true;
    obj = &motor_model_updated_F21_DW.obj_b;
    motor_model_updated_F21_DW.obj_b.isSetupComplete = false;
    motor_model_updated_F21_DW.obj_b.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    motor_model_updated_F21_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Driver In1' */
    motor_model_updated_F21_DW.obj_l.matlabCodegenIsDeleted = false;
    motor_model_updated_F21_DW.objisempty_b = true;
    motor_model_updated_F21_DW.obj_l.isInitialized = 1L;
    digitalIOSetup(30, 1);
    motor_model_updated_F21_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Driver In2' */
    motor_model_updated_F21_DW.obj_f.matlabCodegenIsDeleted = false;
    motor_model_updated_F21_DW.objisempty_e = true;
    motor_model_updated_F21_DW.obj_f.isInitialized = 1L;
    digitalIOSetup(31, 1);
    motor_model_updated_F21_DW.obj_f.isSetupComplete = true;
  }

  /* InitializeConditions for Derivative: '<S1>/Derivative1' */
  motor_model_updated_F21_DW.TimeStampA = (rtInf);
  motor_model_updated_F21_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  motor_model_updated_F21_X.Integrator1_CSTATE =
    motor_model_updated_F21_P.Integrator1_IC;

  /* InitializeConditions for MATLABSystem: '<S2>/Encoder' */
  MW_EncoderReset(motor_model_updated_F21_DW.obj.Index);
}

/* Model terminate function */
void motor_model_updated_F21_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<S2>/Encoder' */
  if (!motor_model_updated_F21_DW.obj.matlabCodegenIsDeleted) {
    motor_model_updated_F21_DW.obj.matlabCodegenIsDeleted = true;
    if ((motor_model_updated_F21_DW.obj.isInitialized == 1L) &&
        motor_model_updated_F21_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Encoder' */

  /* Terminate for MATLABSystem: '<S2>/Enable' */
  obj = &motor_model_updated_F21_DW.obj_b;
  if (!motor_model_updated_F21_DW.obj_b.matlabCodegenIsDeleted) {
    motor_model_updated_F21_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((motor_model_updated_F21_DW.obj_b.isInitialized == 1L) &&
        motor_model_updated_F21_DW.obj_b.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (motor_model_updated_F21_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(motor_model_updated_F21_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Enable' */

  /* Terminate for MATLABSystem: '<S2>/Driver In1' */
  if (!motor_model_updated_F21_DW.obj_l.matlabCodegenIsDeleted) {
    motor_model_updated_F21_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Driver In1' */

  /* Terminate for MATLABSystem: '<S2>/Driver In2' */
  if (!motor_model_updated_F21_DW.obj_f.matlabCodegenIsDeleted) {
    motor_model_updated_F21_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S2>/Driver In2' */
}
