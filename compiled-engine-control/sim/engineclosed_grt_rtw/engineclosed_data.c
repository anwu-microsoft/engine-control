/*
 * engineclosed_data.c
 *
 * Code generation for model "engineclosed".
 *
 * Model version              : 1.132
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jun  6 13:30:26 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "engineclosed.h"
#include "engineclosed_private.h"

/* Block parameters (default storage) */
P_engineclosed_T engineclosed_P = {
  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S64>/Integrator'
   */
  8.973,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by:
   *   '<S37>/DeadZone'
   *   '<S85>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by:
   *   '<S37>/DeadZone'
   *   '<S85>/Saturation'
   */
  70.0,

  /* Expression: 0.152
   * Referenced by: '<S2>/mass(k)'
   */
  0.152,

  /* Expression: -1
   * Referenced by: '<S2>/trigger'
   */
  -1.0,

  /* Expression: 0.152
   * Referenced by: '<S2>/Init'
   */
  0.152,

  /* Expression: 0.152
   * Referenced by: '<S2>/Unit Delay'
   */
  0.152,

  /* Expression: 8.973
   * Referenced by: '<S3>/Throttle Ang.'
   */
  8.973,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: pi/30
   * Referenced by: '<S3>/rpm to rad//s'
   */
  0.10471975511965977,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S64>/Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S37>/ZeroGain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S37>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S110>/trigger'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S110>/Unit Delay'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S110>/Gain'
   */
  -1.0,

  /* Expression: 209.48
   * Referenced by: '<S4>/w = T//J w0 = 209 rad//s'
   */
  209.48,

  /* Expression: 30/pi
   * Referenced by: '<Root>/rad//s to rpm'
   */
  9.5492965855137211,

  /* Expression: 2
   * Referenced by: '<S6>/Step'
   */
  2.0,

  /* Expression: 25
   * Referenced by: '<S6>/Step'
   */
  25.0,

  /* Expression: 20
   * Referenced by: '<S6>/Step'
   */
  20.0,

  /* Expression: 8
   * Referenced by: '<S6>/Step1'
   */
  8.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S6>/Step1'
   */
  5.0,

  /* Expression: 5
   * Referenced by: '<Root>/Speed Setpoint'
   */
  5.0,

  /* Expression: 2000
   * Referenced by: '<Root>/Speed Setpoint'
   */
  2000.0,

  /* Expression: 3000
   * Referenced by: '<Root>/Speed Setpoint'
   */
  3000.0,

  /* Expression: pi
   * Referenced by: '<S109>/Constant'
   */
  3.1415926535897931,

  /* Expression: 15.0
   * Referenced by: '<S1>/Spark Advance (degrees BTDC)'
   */
  15.0,

  /* Expression: 1/14.6
   * Referenced by: '<S1>/Stoichiometric Fuel'
   */
  0.0684931506849315,

  /* Expression: 1
   * Referenced by: '<S4>/Constant'
   */
  1.0,

  /* Expression: 1/0.14
   * Referenced by: '<S4>/Inverse Inertia, 1//J'
   */
  7.1428571428571423,

  /* Expression: 90
   * Referenced by: '<S5>/0 <= theta <= 90'
   */
  90.0,

  /* Expression: 0
   * Referenced by: '<S5>/0 <= theta <= 90'
   */
  0.0,

  /* Expression: 1.0
   * Referenced by: '<S5>/Atmospheric Pressure, Pa (bar)'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S5>/Intake'
   */
  0.0,

  /* Expression: .543
   * Referenced by: '<S107>/p0 = 0.543 bar'
   */
  0.543,

  /* Expression: 1.0
   * Referenced by: '<S108>/Sonic Flow '
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S108>/Switch'
   */
  0.5,

  /* Expression: 0.41328
   * Referenced by: '<S107>/RT//Vm'
   */
  0.41328,

  /* Expression: 0
   * Referenced by: '<S109>/Get Crank Angle IC 0'
   */
  0.0
};
