/*
 * File: Controller_Decoder.c
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
#include "Controller_Decoder.h"

/* Output and update for atomic system: '<S2>/Decoder' */
void Controller_Decoder(const boolean_T rtu_Hall[3], real32_T *rty_Emf_abc,
  real32_T *rty_Emf_abc_m, real32_T *rty_Emf_abc_m1)
{
  boolean_T rtb_LogicalOperator1_idx_0;
  boolean_T rtb_LogicalOperator1_idx_1;
  boolean_T rtb_LogicalOperator1_idx_2;

  /* Logic: '<S3>/Logical Operator1' */
  rtb_LogicalOperator1_idx_0 = !rtu_Hall[0];
  rtb_LogicalOperator1_idx_1 = !rtu_Hall[1];
  rtb_LogicalOperator1_idx_2 = !rtu_Hall[2];

  /* DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
   *  Logic: '<S3>/Logical Operator3'
   */
  *rty_Emf_abc_m = (real32_T)(rtu_Hall[1] && rtb_LogicalOperator1_idx_2);

  /* DataTypeConversion: '<S3>/Data Type Conversion5' incorporates:
   *  Logic: '<S3>/Logical Operator6'
   */
  *rty_Emf_abc = (real32_T)(rtb_LogicalOperator1_idx_1 && rtu_Hall[2]);

  /* Sum: '<S3>/Sum1' */
  *rty_Emf_abc_m -= *rty_Emf_abc;

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  Logic: '<S3>/Logical Operator2'
   */
  *rty_Emf_abc = (real32_T)(rtu_Hall[0] && rtb_LogicalOperator1_idx_1);

  /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
   *  Logic: '<S3>/Logical Operator5'
   */
  *rty_Emf_abc_m1 = (real32_T)(rtb_LogicalOperator1_idx_0 && rtu_Hall[1]);

  /* Sum: '<S3>/Sum2' */
  *rty_Emf_abc -= *rty_Emf_abc_m1;

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  Logic: '<S3>/Logical Operator4'
   */
  *rty_Emf_abc_m1 = (real32_T)(rtb_LogicalOperator1_idx_0 && rtu_Hall[2]);

  /* Sum: '<S3>/Sum3' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion6'
   *  Logic: '<S3>/Logical Operator7'
   */
  *rty_Emf_abc_m1 -= (real32_T)(rtu_Hall[0] && rtb_LogicalOperator1_idx_2);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
