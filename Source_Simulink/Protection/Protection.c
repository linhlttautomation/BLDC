/*
 * File: Protection.c
 *
 * Code generated for Simulink model 'Protection'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov  1 12:53:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Protection.h"
#include "rtwtypes.h"
#include "Protection_types.h"
#include "Protection_private.h"

/* Output and update for referenced model: 'Protection' */
void Protection(DW_Protection_f_T *localDW)
{
  boolean_T rtb_Compare;

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport generated from: '<Root>/In Bus Element'
   */
  rtb_Compare = (Test_Protection_In.Protection_In1 >= 0.0F);

  /* MATLAB Function: '<S4>/MATLAB Function' */
  if (!localDW->Fault_Active) {
    if (rtb_Compare) {
      localDW->Fault_Timer += 0.01F;
    } else {
      localDW->Fault_Timer = 0.0F;
    }

    if (localDW->Fault_Timer >= 2.0F) {
      localDW->Fault_Active = true;
      localDW->Recovery_Timer = 0.0F;

      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S8>/Constant'
       */
      Test_Protection_Out.Protection_Out1 = NORMAL;
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S9>/Constant'
       */
      Test_Protection_Out.Protection_Out1 = ERROR;
    }
  } else {
    if (!rtb_Compare) {
      localDW->Recovery_Timer += 0.01F;
    } else {
      localDW->Recovery_Timer = 0.0F;
    }

    if (localDW->Recovery_Timer >= 3.0F) {
      localDW->Fault_Active = false;
      localDW->Fault_Timer = 0.0F;

      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S9>/Constant'
       */
      Test_Protection_Out.Protection_Out1 = ERROR;
    } else {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S8>/Constant'
       */
      Test_Protection_Out.Protection_Out1 = NORMAL;
    }
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S6>/Constant'
   *  Inport generated from: '<Root>/In Bus Element'
   */
  if (Test_Protection_In.Protection_In2 > 0.0F) {
    Test_Protection_Out.Protection_Out2 = NORMAL;
  } else {
    Test_Protection_Out.Protection_Out2 = ERROR;
  }

  /* End of Switch: '<S2>/Switch' */
}

/* Model initialize function */
void Protection_initialize(const char_T **rt_errorStatus, RT_MODEL_Protection_T *
  const Protection_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Protection_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
