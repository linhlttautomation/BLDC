/*
 * File: Controller_Gates.c
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

#include "rtwtypes.h"
#include "Controller_Gates.h"

/* Output and update for atomic system: '<S2>/Gates' */
void Controller_Gates(real32_T rtu_Emf_abc, real32_T rtu_Emf_abc_p, real32_T
                      rtu_Emf_abc_e, boolean_T *rty_Gates, boolean_T
                      *rty_Gates_p, boolean_T *rty_Gates_e, boolean_T
                      *rty_Gates_d, boolean_T *rty_Gates_o, boolean_T
                      *rty_Gates_f)
{
  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  *rty_Gates = (rtu_Emf_abc > 0.0F);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  *rty_Gates_p = (rtu_Emf_abc < 0.0F);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  *rty_Gates_e = (rtu_Emf_abc_p > 0.0F);

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  *rty_Gates_d = (rtu_Emf_abc_p < 0.0F);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  *rty_Gates_o = (rtu_Emf_abc_e > 0.0F);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  *rty_Gates_f = (rtu_Emf_abc_e < 0.0F);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
