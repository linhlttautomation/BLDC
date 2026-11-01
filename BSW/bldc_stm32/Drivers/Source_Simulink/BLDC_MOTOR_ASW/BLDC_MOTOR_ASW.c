/*
 * File: BLDC_MOTOR_ASW.c
 *
 * Code generated for Simulink model 'BLDC_MOTOR_ASW'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov  1 12:53:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BLDC_MOTOR_ASW.h"
#include "BLDC_MOTOR_ASW_types.h"
#include "StateControl.h"
#include "CalibAdc.h"
#include "Protection.h"
#include "Controller.h"

/* Exported block signals */
Test_Input_t Test_Input;               /* '<Root>/Test_Input' */
Test_CalibAdc_t Test_CalibAdc;         /* '<Root>/Test_CalibAdc' */
Test_StateControl_In_t Test_StateControl_In;/* '<Root>/Test_StateControl_In' */
Test_Output_t Test_Output;             /* '<Root>/Controller' */
Test_StateControl_Out_t Test_StateControl_Out;/* '<Root>/StateControl' */
Test_Protection_Out_t Test_Protection_Out;/* '<Root>/Protection' */
Test_Protection_In_t Test_Protection_In;/* '<Root>/CalibAdc' */

/* Block states (default storage) */
DW_BLDC_MOTOR_ASW_T BLDC_MOTOR_ASW_DW;

/* Real-time model */
static RT_MODEL_BLDC_MOTOR_ASW_T BLDC_MOTOR_ASW_M_;
RT_MODEL_BLDC_MOTOR_ASW_T *const BLDC_MOTOR_ASW_M = &BLDC_MOTOR_ASW_M_;

/* Model step function for TID1 */
void Controller_Function(void)         /* Explicit Task: Controller_D1 */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Controller_D1' */

  /* ModelReference generated from: '<Root>/Controller' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  ControllerTask();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Controller_D1' */
}

/* Model step function for TID2 */
void Protection_Function(void)         /* Explicit Task: Protection_D1 */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Protection_D1' */

  /* ModelReference generated from: '<Root>/Protection' */
  Protection(&(BLDC_MOTOR_ASW_DW.Protection_InstanceData.rtdw));

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Protection_D1' */
}

/* Model step function for TID3 */
void CalibAdc_Function(void)           /* Explicit Task: CalibAdc_D2 */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/CalibAdc_D2' */

  /* ModelReference generated from: '<Root>/CalibAdc' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  CalibAdc();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/CalibAdc_D2' */
}

/* Model step function for TID4 */
void StateControl_Function(void)       /* Explicit Task: StateControl_D2 */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/StateControl_D2' */

  /* ModelReference generated from: '<Root>/StateControl' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  StateControl(&(BLDC_MOTOR_ASW_DW.StateControl_InstanceData.rtdw));

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/StateControl_D2' */
}

/* Model initialize function */
void BLDC_MOTOR_ASW_initialize(void)
{
  /* Model Initialize function for ModelReference Block: '<Root>/CalibAdc' */
  CalibAdc_initialize(rtmGetErrorStatusPointer(BLDC_MOTOR_ASW_M),
                      &(BLDC_MOTOR_ASW_DW.CalibAdc_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/Controller' */
  Controller_initialize(rtmGetErrorStatusPointer(BLDC_MOTOR_ASW_M),
                        &(BLDC_MOTOR_ASW_DW.Controller_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/Protection' */
  Protection_initialize(rtmGetErrorStatusPointer(BLDC_MOTOR_ASW_M),
                        &(BLDC_MOTOR_ASW_DW.Protection_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/StateControl' */
  StateControl_initialize(rtmGetErrorStatusPointer(BLDC_MOTOR_ASW_M),
    &(BLDC_MOTOR_ASW_DW.StateControl_InstanceData.rtm));
}

/* Model terminate function */
void BLDC_MOTOR_ASW_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
