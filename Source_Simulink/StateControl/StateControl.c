/*
 * File: StateControl.c
 *
 * Code generated for Simulink model 'StateControl'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov  1 01:14:17 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "StateControl.h"
#include "rtwtypes.h"
#include "StateControl_types.h"
#include "StateControl_private.h"

/* Named constants for Chart: '<S2>/Chart' */
#define StateControl_IN_Off1           ((uint8_T)1U)
#define StateControl_IN_On             ((uint8_T)2U)

/* Output and update for referenced model: 'StateControl' */
void StateControl(DW_StateControl_f_T *localDW)
{
  /* Chart: '<S2>/Chart' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   *  Inport generated from: '<Root>/In Bus Element'
   */
  if (localDW->is_active_c3_StateControl == 0U) {
    localDW->is_active_c3_StateControl = 1U;
    localDW->is_c3_StateControl = StateControl_IN_Off1;

    /* BusCreator generated from: '<S1>/Test_StateControl_Out_BusCreator' */
    Test_StateControl_Out.StateControl_Out1 = OFF;
  } else if (localDW->is_c3_StateControl == StateControl_IN_Off1) {
    /* BusCreator generated from: '<S1>/Test_StateControl_Out_BusCreator' */
    Test_StateControl_Out.StateControl_Out1 = OFF;
    if ((Test_StateControl_In.StateControl_In1 == ON) &&
        (Test_Protection_In.Protection_In1 >= Test_Protection_In.Protection_In2)
        && (Test_Protection_In.Protection_In2 >= 400.0F)) {
      localDW->is_c3_StateControl = StateControl_IN_On;

      /* BusCreator generated from: '<S1>/Test_StateControl_Out_BusCreator' */
      Test_StateControl_Out.StateControl_Out1 = ON;
    }
  } else {
    /* BusCreator generated from: '<S1>/Test_StateControl_Out_BusCreator' */
    /* case IN_On: */
    Test_StateControl_Out.StateControl_Out1 = ON;
    if (Test_StateControl_In.StateControl_In1 == OFF) {
      localDW->is_c3_StateControl = StateControl_IN_Off1;

      /* BusCreator generated from: '<S1>/Test_StateControl_Out_BusCreator' */
      Test_StateControl_Out.StateControl_Out1 = OFF;
    }
  }

  /* End of Chart: '<S2>/Chart' */
}

/* Model initialize function */
void StateControl_initialize(const char_T **rt_errorStatus,
  RT_MODEL_StateControl_T *const StateControl_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(StateControl_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
