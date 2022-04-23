/*
 * motor_model_updated_F21.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motor_model_updated_F21".
 *
 * Model version              : 4.12
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Sat Apr 23 12:17:30 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_model_updated_F21_h_
#define RTW_HEADER_motor_model_updated_F21_h_
#include <math.h>
#include <string.h>
#ifndef motor_model_updated_F21_COMMON_INCLUDES_
#define motor_model_updated_F21_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#endif                            /* motor_model_updated_F21_COMMON_INCLUDES_ */

#include "motor_model_updated_F21_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<S2>/Motor Direction1' */
typedef struct {
  int8_T MotorDirection1_SubsysRanBC;  /* '<S2>/Motor Direction1' */
} DW_MotorDirection1_motor_mode_T;

/* Block signals (default storage) */
typedef struct {
  real_T Setpoint;                     /* '<Root>/gain' */
  real_T ErrorSignal;                  /* '<Root>/Sum1' */
  real_T Abs;                          /* '<S2>/Abs' */
  int64m_T angular_positionrelative_countC;
  /* '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
} B_motor_model_updated_F21_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_m_T obj; /* '<S2>/Encoder' */
  codertarget_arduinobase_block_T obj_f;/* '<S2>/Driver In2' */
  codertarget_arduinobase_block_T obj_l;/* '<S2>/Driver In1' */
  codertarget_arduinobase_inter_T obj_b;/* '<S2>/Enable' */
  real_T TimeStampA;                   /* '<S1>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S1>/Derivative1' */
  real_T TimeStampB;                   /* '<S1>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S1>/Derivative1' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Motor;   /* synthesized block */

  int8_T ChooseDirection_ActiveSubsystem;/* '<S2>/Choose Direction' */
  boolean_T objisempty;                /* '<S2>/Encoder' */
  boolean_T objisempty_k;              /* '<S2>/Enable' */
  boolean_T objisempty_e;              /* '<S2>/Driver In2' */
  boolean_T objisempty_b;              /* '<S2>/Driver In1' */
  DW_MotorDirection1_motor_mode_T ConstantPosition;/* '<S2>/Constant Position' */
  DW_MotorDirection1_motor_mode_T MotorDirection2;/* '<S2>/Motor Direction 2' */
  DW_MotorDirection1_motor_mode_T MotorDirection1;/* '<S2>/Motor Direction1' */
} DW_motor_model_updated_F21_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
} X_motor_model_updated_F21_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
} XDot_motor_model_updated_F21_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
} XDis_motor_model_updated_F21_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int64m_T motorPos_Out;               /* '<Root>/motorPos_Out' */
} ExtY_motor_model_updated_F21_T;

/* Parameters for system: '<S2>/Motor Direction1' */
struct P_MotorDirection1_motor_model_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_motor_model_updated_F21_T_ {
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T desiredPosition_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/desiredPosition'
                                        */
  real_T gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/gain'
                                        */
  real_T Kp_Gain;                      /* Expression: 80
                                        * Referenced by: '<S1>/Kp'
                                        */
  real_T Kd_Gain;                      /* Expression: 5
                                        * Referenced by: '<S1>/Kd'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  real_T Ki_Gain;                      /* Expression: 1
                                        * Referenced by: '<S1>/Ki'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/5
                                        * Referenced by: '<S2>/Gain'
                                        */
  int32_T angular_positionrelative_countC;
                          /* Computed Parameter: angular_positionrelative_countC
                           * Referenced by: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                           */
  P_MotorDirection1_motor_model_T ConstantPosition;/* '<S2>/Constant Position' */
  P_MotorDirection1_motor_model_T MotorDirection2;/* '<S2>/Motor Direction 2' */
  P_MotorDirection1_motor_model_T MotorDirection1;/* '<S2>/Motor Direction1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_model_updated_F_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_motor_model_updated_F21_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[4][1];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_model_updated_F21_T motor_model_updated_F21_P;

/* Block signals (default storage) */
extern B_motor_model_updated_F21_T motor_model_updated_F21_B;

/* Continuous states (default storage) */
extern X_motor_model_updated_F21_T motor_model_updated_F21_X;

/* Block states (default storage) */
extern DW_motor_model_updated_F21_T motor_model_updated_F21_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_motor_model_updated_F21_T motor_model_updated_F21_Y;

/* External data declarations for dependent source files */
extern const int64m_T motor_model_updated_F21_sfix64_;/* int64m_T ground */

/* Model entry point functions */
extern void motor_model_updated_F21_initialize(void);
extern void motor_model_updated_F21_step(void);
extern void motor_model_updated_F21_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_model_updated__T *const motor_model_updated_F21_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'motor_model_updated_F21'
 * '<S1>'   : 'motor_model_updated_F21/Controller'
 * '<S2>'   : 'motor_model_updated_F21/Motor'
 * '<S3>'   : 'motor_model_updated_F21/Motor/Constant Position'
 * '<S4>'   : 'motor_model_updated_F21/Motor/Motor Direction 2'
 * '<S5>'   : 'motor_model_updated_F21/Motor/Motor Direction1'
 */
#endif                               /* RTW_HEADER_motor_model_updated_F21_h_ */
