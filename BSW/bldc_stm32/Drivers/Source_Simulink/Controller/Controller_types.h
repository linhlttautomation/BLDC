/*
 * File: Controller_types.h
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

#ifndef RTW_HEADER_Controller_types_h_
#define RTW_HEADER_Controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Test_Input_t_
#define DEFINED_TYPEDEF_FOR_Test_Input_t_

typedef struct {
  boolean_T Input1;
  boolean_T Input2;
  boolean_T Input3;
  real32_T Input4;
  real32_T Input5;
  real32_T Input6;
  real32_T Input7;
} Test_Input_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Test_Output_t_
#define DEFINED_TYPEDEF_FOR_Test_Output_t_

typedef struct {
  boolean_T Output1;
  boolean_T Output2;
  boolean_T Output3;
  boolean_T Output4;
  boolean_T Output6;
  real32_T Output7;
  real32_T Output8;
  real32_T Output9;
  boolean_T Output5;
} Test_Output_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Controller_T RT_MODEL_Controller_T;

#endif                                 /* RTW_HEADER_Controller_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
