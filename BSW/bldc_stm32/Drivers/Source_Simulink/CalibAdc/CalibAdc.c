/*
 * File: CalibAdc.c
 *
 * Code generated for Simulink model 'CalibAdc'.
 *
 * Model version                  : 1.51
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Oct 31 23:55:59 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CalibAdc.h"
#include "CalibAdc_types.h"
#include "rtwtypes.h"
#include "CalibAdc_Internal.h"
#include "CalibAdc_private.h"

/* Output and update for referenced model: 'CalibAdc' */
void CalibAdc(void)
{
  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Sum: '<S4>/Add'
   */
  Test_Protection_In.Protection_In1 = (Test_CalibAdc.AdcInput1 -
    CALIBADC_BIAS_V_ADC_TO_VOLT) * CALIBADC_GAIN_V_ADC_TO_VOLT;

  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Sum: '<S3>/Add'
   */
  Test_Protection_In.Protection_In2 = (Test_CalibAdc.AdcInput2 -
    CALIBADC_BIAS_I_ADC_TO_CURR) * CALIBADC_GAIN_I_ADC_TO_CURR;
}

/* Model initialize function */
void CalibAdc_initialize(const char_T **rt_errorStatus, RT_MODEL_CalibAdc_T *
  const CalibAdc_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(CalibAdc_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
