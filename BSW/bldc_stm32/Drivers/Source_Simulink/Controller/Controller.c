/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.176
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov  1 13:05:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_Decoder.h"
#include "Controller_Gates.h"
#include "rtwtypes.h"
#include "Controller_types.h"
#include "Controller_private.h"

/* Output and update for referenced model: 'Controller' */
void ControllerTask(void)
{
  real32_T rtb_Sum1;
  real32_T rtb_Sum2;
  real32_T rtb_Sum3;
  boolean_T rtb_TmpSignalConversionAtDecode[3];

  /* SignalConversion generated from: '<S2>/Decoder' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  rtb_TmpSignalConversionAtDecode[0] = Test_Input.Input1;
  rtb_TmpSignalConversionAtDecode[1] = Test_Input.Input2;
  rtb_TmpSignalConversionAtDecode[2] = Test_Input.Input3;

  /* Outputs for Atomic SubSystem: '<S2>/Decoder' */
  Controller_Decoder(rtb_TmpSignalConversionAtDecode, &rtb_Sum2, &rtb_Sum1,
                     &rtb_Sum3);

  /* End of Outputs for SubSystem: '<S2>/Decoder' */

  /* Outputs for Atomic SubSystem: '<S2>/Gates' */
  Controller_Gates(rtb_Sum2, rtb_Sum1, rtb_Sum3, &Test_Output.Output1,
                   &Test_Output.Output2, &Test_Output.Output3,
                   &Test_Output.Output4, &Test_Output.Output5,
                   &Test_Output.Output6);

  /* End of Outputs for SubSystem: '<S2>/Gates' */

  /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
  Test_Output.Output7 = 0.0F;
  Test_Output.Output8 = 0.0F;
  Test_Output.Output9 = 0.0F;
}

/* Model initialize function */
void Controller_initialize(const char_T **rt_errorStatus, RT_MODEL_Controller_T *
  const Controller_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Controller_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
