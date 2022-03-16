/*
 * motor_model_updated_F21_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "motor_model_updated_F21".
 *
 * Model version              : 4.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Mar 16 17:14:59 2022
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_model_updated_F21.h"
#include "motor_model_updated_F21_private.h"

/* Block parameters (default storage) */
P_motor_model_updated_F21_T motor_model_updated_F21_P = {
  /* Expression: -1
   * Referenced by: '<S2>/Encoder'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/desiredPosition'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/gain'
   */
  1.0,

  /* Expression: 80
   * Referenced by: '<S1>/Kp'
   */
  80.0,

  /* Expression: 5
   * Referenced by: '<S1>/Kd'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Ki'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S2>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/Saturation'
   */
  -5.0,

  /* Expression: 255/5
   * Referenced by: '<S2>/Gain'
   */
  51.0,

  /* Computed Parameter: angular_positionrelative_countC
   * Referenced by: '<S2>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
   */
  1431655765,

  /* Start of '<S2>/Constant Position' */
  {
    /* Expression: 0
     * Referenced by: '<S3>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S3>/Constant1'
     */
    0.0
  }
  ,

  /* End of '<S2>/Constant Position' */

  /* Start of '<S2>/Motor Direction 2' */
  {
    /* Expression: 0
     * Referenced by: '<S4>/Constant'
     */
    0.0,

    /* Expression: 1
     * Referenced by: '<S4>/Constant1'
     */
    1.0
  }
  ,

  /* End of '<S2>/Motor Direction 2' */

  /* Start of '<S2>/Motor Direction1' */
  {
    /* Expression: 1
     * Referenced by: '<S5>/Constant'
     */
    1.0,

    /* Expression: 0
     * Referenced by: '<S5>/Constant1'
     */
    0.0
  }
  /* End of '<S2>/Motor Direction1' */
};
