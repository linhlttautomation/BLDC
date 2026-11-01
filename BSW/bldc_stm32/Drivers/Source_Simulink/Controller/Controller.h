/*
 * File: Controller.h
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

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_Controller_T rtm;
} MdlrefDW_Controller_T;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern Test_Input_t Test_Input;        /* '<Root>/Test_Input' */
extern Test_Output_t Test_Output;      /*  */

/* Model reference registration function */
extern void Controller_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Controller_T *const Controller_M);
extern void ControllerTask(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion4' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/ControllerTask'
 * '<S2>'   : 'Controller/ControllerTask/ControllerMainFunction'
 * '<S3>'   : 'Controller/ControllerTask/ControllerMainFunction/Decoder'
 * '<S4>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates'
 * '<S5>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero'
 * '<S6>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero1'
 * '<S7>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero2'
 * '<S8>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero3'
 * '<S9>'   : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero4'
 * '<S10>'  : 'Controller/ControllerTask/ControllerMainFunction/Gates/Compare To Zero5'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
