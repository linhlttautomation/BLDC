/*
 * File: Controller_private.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.186
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Nov 14 23:26:38 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_private_h_
#define RTW_HEADER_Controller_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Controller.h"
#include "Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_7x7Hr3MX2jW3[1002];

#define rtCP_sine_table_values_Value   rtCP_pooled_7x7Hr3MX2jW3  /* Computed Parameter: rtCP_sine_table_values_Value
                                                                  * Referenced by: '<S12>/sine_table_values'
                                                                  */

/* Invariant block signals (default storage) */
extern const ConstB_Controller_h_T Controller_ConstB;

#endif                                 /* RTW_HEADER_Controller_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
