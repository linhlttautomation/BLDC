/*
 * File: BLDC_MOTOR_ASW_types.h
 *
 * Code generated for Simulink model 'BLDC_MOTOR_ASW'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov  1 19:29:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BLDC_MOTOR_ASW_types_h_
#define RTW_HEADER_BLDC_MOTOR_ASW_types_h_
#include "rtwtypes.h"
#include "Protection_Internal.h"
#include "StateControl_Internal.h"
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

#ifndef DEFINED_TYPEDEF_FOR_Test_Protection_Out_t_
#define DEFINED_TYPEDEF_FOR_Test_Protection_Out_t_

typedef struct {
  PROTECTION_STATUS Protection_Out1;
  PROTECTION_STATUS Protection_Out2;
} Test_Protection_Out_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Test_StateControl_Out_t_
#define DEFINED_TYPEDEF_FOR_Test_StateControl_Out_t_

typedef struct {
  STCTL_MODE_CONTROL StateControl_Out1;
} Test_StateControl_Out_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Test_CalibAdc_t_
#define DEFINED_TYPEDEF_FOR_Test_CalibAdc_t_

typedef struct {
  real32_T AdcInput1;
  real32_T AdcInput2;
} Test_CalibAdc_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Test_Protection_In_t_
#define DEFINED_TYPEDEF_FOR_Test_Protection_In_t_

typedef struct {
  real32_T Protection_In1;
  real32_T Protection_In2;
} Test_Protection_In_t;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_Test_StateControl_In_t_
#define DEFINED_TYPEDEF_FOR_Test_StateControl_In_t_

typedef struct {
  STCTL_MODE_CONTROL StateControl_In1;
} Test_StateControl_In_t;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_BLDC_MOTOR_ASW_T RT_MODEL_BLDC_MOTOR_ASW_T;

#endif                                 /* RTW_HEADER_BLDC_MOTOR_ASW_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
