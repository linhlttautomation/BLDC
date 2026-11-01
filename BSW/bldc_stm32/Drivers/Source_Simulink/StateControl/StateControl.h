/*
 * File: StateControl.h
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

#ifndef RTW_HEADER_StateControl_h_
#define RTW_HEADER_StateControl_h_
#ifndef StateControl_COMMON_INCLUDES_
#define StateControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* StateControl_COMMON_INCLUDES_ */

#include "StateControl_types.h"

/* Block states (default storage) for model 'StateControl' */
typedef struct {
  uint8_T is_active_c3_StateControl;   /* '<S2>/Chart' */
  uint8_T is_c3_StateControl;          /* '<S2>/Chart' */
} DW_StateControl_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_StateControl_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_StateControl_f_T rtdw;
  RT_MODEL_StateControl_T rtm;
} MdlrefDW_StateControl_T;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern Test_StateControl_In_t Test_StateControl_In;/* '<Root>/Test_StateControl_In' */
extern Test_Protection_In_t Test_Protection_In;/* '<Root>/Test_Protection_In' */
extern Test_StateControl_Out_t Test_StateControl_Out;/*  */

/* Model reference registration function */
extern void StateControl_initialize(const char_T **rt_errorStatus,
  RT_MODEL_StateControl_T *const StateControl_M);
extern void StateControl(DW_StateControl_f_T *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'StateControl'
 * '<S1>'   : 'StateControl/StateControlTask'
 * '<S2>'   : 'StateControl/StateControlTask/StateControlMainFunction'
 * '<S3>'   : 'StateControl/StateControlTask/StateControlMainFunction/Chart'
 */
#endif                                 /* RTW_HEADER_StateControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
