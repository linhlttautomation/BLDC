/*
 * File: Controller.h
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

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "zero_crossing_types.h"

/* Block signals for model 'Controller' */
typedef struct {
  real32_T Input;                      /* '<S176>/Input' */
} B_Controller_c_T;

/* Block states (default storage) for model 'Controller' */
typedef struct {
  real32_T Delay1_DSTATE;              /* '<S2>/Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S160>/Unit Delay' */
  real32_T Delay3_DSTATE;              /* '<S2>/Delay3' */
  real32_T UnitDelay_DSTATE_a;         /* '<S168>/Unit Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S143>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S143>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S147>/Unit Delay' */
  real32_T Delay_DSTATE_f;             /* '<S2>/Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S156>/Unit Delay' */
  real32_T Delay2_DSTATE;              /* '<S2>/Delay2' */
  real32_T UnitDelay_DSTATE_m;         /* '<S164>/Unit Delay' */
  real32_T Delay1_DSTATE_h;            /* '<S136>/Delay1' */
  real32_T Delay_DSTATE_k;             /* '<S136>/Delay' */
  real32_T UnitDelay_DSTATE_d;         /* '<S140>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S174>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b1;        /* '<S17>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S53>/Integrator' */
  real32_T UnitDelay_DSTATE_de;        /* '<S243>/Unit Delay' */
  real32_T UnitDelay_DSTATE_di;        /* '<S150>/Unit Delay' */
  real32_T Integrator_DSTATE_c;        /* '<S222>/Integrator' */
  real32_T UnitDelay_DSTATE_o;         /* '<S18>/Unit Delay' */
  real32_T Integrator_DSTATE_h;        /* '<S104>/Integrator' */
  uint32_T Delay_DSTATE_a[10];         /* '<S123>/Delay' */
  real32_T PrevY;                      /* '<S239>/Rate Limiter' */
  real32_T PrevY_f;                    /* '<S239>/Rate Limiter1' */
  uint32_T CircBufIdx;                 /* '<S123>/Delay' */
  boolean_T Delay_DSTATE_i;            /* '<S175>/Delay' */
  int8_T Integrator_PrevResetState;    /* '<S53>/Integrator' */
  int8_T Integrator_PrevResetState_f;  /* '<S222>/Integrator' */
  int8_T Integrator_PrevResetState_h;  /* '<S104>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S53>/Integrator' */
  uint8_T Integrator_IC_LOADING_e;     /* '<S104>/Integrator' */
  uint8_T is_active_c1_Controller;     /* '<S2>/Chart1' */
  uint8_T is_c1_Controller;            /* '<S2>/Chart1' */
} DW_Controller_f_T;

/* Zero-crossing (trigger) state for model 'Controller' */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S143>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S143>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S136>/Delay1' */
  ZCSigState Delay_Reset_ZCE_j;        /* '<S136>/Delay' */
} ZCE_Controller_T;

/* Invariant block signals for model 'Controller' */
typedef struct {
  const real32_T Constant;             /* '<S186>/Constant' */
} ConstB_Controller_h_T;

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Controller_c_T rtb;
  DW_Controller_f_T rtdw;
  RT_MODEL_Controller_T rtm;
  ZCE_Controller_T rtzce;
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
  RT_MODEL_Controller_T *const Controller_M, ZCE_Controller_T *localZCE);
extern void Controller_Init(DW_Controller_f_T *localDW);
extern void ControllerTask(B_Controller_c_T *localB, DW_Controller_f_T *localDW,
  ZCE_Controller_T *localZCE);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Duplicate' : Unused code path elimination
 * Block '<S121>/Data Type Conversion' : Unused code path elimination
 * Block '<S121>/Data Type Conversion1' : Unused code path elimination
 * Block '<S121>/FluxGain' : Unused code path elimination
 * Block '<S121>/Product' : Unused code path elimination
 * Block '<S121>/Product1' : Unused code path elimination
 * Block '<S121>/Product2' : Unused code path elimination
 * Block '<S121>/Product3' : Unused code path elimination
 * Block '<S121>/Product4' : Unused code path elimination
 * Block '<S121>/Sqrt' : Unused code path elimination
 * Block '<S121>/Sum' : Unused code path elimination
 * Block '<S121>/Sum1' : Unused code path elimination
 * Block '<S121>/TorqueGain' : Unused code path elimination
 * Block '<S121>/TorqueGainDatatype' : Unused code path elimination
 * Block '<S134>/AlphaDataProp2' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S140>/Data Type Duplicate' : Unused code path elimination
 * Block '<S136>/AlphaDataProp1' : Unused code path elimination
 * Block '<S141>/BetaDataProp2' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S143>/BetaDataProp1' : Unused code path elimination
 * Block '<S150>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S168>/Data Type Duplicate' : Unused code path elimination
 * Block '<S170>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S184>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Kalpha' : Eliminated nontunable gain of 1
 * Block '<S15>/Kbeta' : Eliminated nontunable gain of 1
 * Block '<S132>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/PositionGain' : Eliminated nontunable gain of 1
 * Block '<S170>/Ka' : Eliminated nontunable gain of 1
 * Block '<S170>/Kb' : Eliminated nontunable gain of 1
 * Block '<S170>/Kc' : Eliminated nontunable gain of 1
 * Block '<S174>/scaleIn' : Eliminated nontunable gain of 1
 * Block '<S174>/scaleOut' : Eliminated nontunable gain of 1
 * Block '<S12>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S182>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S173>/Offset' : Unused code path elimination
 * Block '<S173>/Unary_Minus' : Unused code path elimination
 * Block '<S180>/Offset' : Unused code path elimination
 * Block '<S180>/Unary_Minus' : Unused code path elimination
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
 * '<S3>'   : 'Controller/ControllerTask/ControllerMainFunction/Chart1'
 * '<S4>'   : 'Controller/ControllerTask/ControllerMainFunction/Clarke_Tranform'
 * '<S5>'   : 'Controller/ControllerTask/ControllerMainFunction/Current_Control'
 * '<S6>'   : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE'
 * '<S7>'   : 'Controller/ControllerTask/ControllerMainFunction/InvertClarke_Tranform'
 * '<S8>'   : 'Controller/ControllerTask/ControllerMainFunction/InvertPark_Tranform'
 * '<S9>'   : 'Controller/ControllerTask/ControllerMainFunction/Open_Loop_Control'
 * '<S10>'  : 'Controller/ControllerTask/ControllerMainFunction/PWM'
 * '<S11>'  : 'Controller/ControllerTask/ControllerMainFunction/Park_Tranform'
 * '<S12>'  : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup'
 * '<S13>'  : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control'
 * '<S14>'  : 'Controller/ControllerTask/ControllerMainFunction/Clarke_Tranform/Clarke Transform'
 * '<S15>'  : 'Controller/ControllerTask/ControllerMainFunction/Clarke_Tranform/Clarke Transform/Two phase input'
 * '<S16>'  : 'Controller/ControllerTask/ControllerMainFunction/Clarke_Tranform/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S17>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id'
 * '<S18>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq'
 * '<S19>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S20>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S21>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S22>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S23>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S24>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S25>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S26>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S27>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S28>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S29>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S30>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S31>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S32>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S33>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S34>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S35>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S36>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S37>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S38>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S39>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S40>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S41>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S42>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S43>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S44>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S45>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S46>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S47>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S48>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S49>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S50>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/Internal Parameters'
 * '<S51>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S52>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S53>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S54>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S55>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S56>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S57>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S58>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/Internal Parameters'
 * '<S59>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S60>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S61>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S62>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S63>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S64>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S65>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S66>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S67>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S68>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S69>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S70>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S71>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S72>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S73>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S74>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S75>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S76>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S77>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S78>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S79>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S80>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S81>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S82>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S83>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S84>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S85>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S86>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S87>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S88>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S89>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S90>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S91>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S92>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S93>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S94>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S95>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S96>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S97>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S98>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S99>'  : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S100>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S101>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/Internal Parameters'
 * '<S102>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S103>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S104>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S105>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S106>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S107>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S108>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S109>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/Internal Parameters'
 * '<S110>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S111>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S112>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S113>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S114>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S115>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S116>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S117>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S118>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S119>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S120>' : 'Controller/ControllerTask/ControllerMainFunction/Current_Control/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S121>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer'
 * '<S122>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/IIR Filter'
 * '<S123>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Speed Measurement'
 * '<S124>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem'
 * '<S125>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem1'
 * '<S126>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem2'
 * '<S127>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem3'
 * '<S128>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/Atan2'
 * '<S129>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha'
 * '<S130>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta'
 * '<S131>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/Atan2/Default'
 * '<S132>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/Atan2/Default/atan2'
 * '<S133>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S134>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default'
 * '<S135>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/IIR Filter'
 * '<S136>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/Integrator'
 * '<S137>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/Scaling'
 * '<S138>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter'
 * '<S139>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter/High-pass'
 * '<S140>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiAlpha/Default/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S141>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default'
 * '<S142>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/IIR Filter'
 * '<S143>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/Integrator'
 * '<S144>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/Scaling'
 * '<S145>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter'
 * '<S146>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter/High-pass'
 * '<S147>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Flux Observer/psiBeta/Default/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S148>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/IIR Filter/IIR Filter'
 * '<S149>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/IIR Filter/IIR Filter/Low-pass'
 * '<S150>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S151>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Speed Measurement/DT_Handle'
 * '<S152>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Speed Measurement/DT_Handle/floating-point'
 * '<S153>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem/IIR Filter'
 * '<S154>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem/IIR Filter/IIR Filter'
 * '<S155>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S156>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S157>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem1/IIR Filter'
 * '<S158>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem1/IIR Filter/IIR Filter'
 * '<S159>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem1/IIR Filter/IIR Filter/Low-pass'
 * '<S160>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S161>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem2/IIR Filter'
 * '<S162>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem2/IIR Filter/IIR Filter'
 * '<S163>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem2/IIR Filter/IIR Filter/Low-pass'
 * '<S164>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem2/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S165>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem3/IIR Filter'
 * '<S166>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem3/IIR Filter/IIR Filter'
 * '<S167>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem3/IIR Filter/IIR Filter/Low-pass'
 * '<S168>' : 'Controller/ControllerTask/ControllerMainFunction/EstimateSpeedMAndThetaE/Subsystem3/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S169>' : 'Controller/ControllerTask/ControllerMainFunction/InvertClarke_Tranform/Inverse Clarke Transform'
 * '<S170>' : 'Controller/ControllerTask/ControllerMainFunction/InvertClarke_Tranform/Inverse Clarke Transform/Two phase input'
 * '<S171>' : 'Controller/ControllerTask/ControllerMainFunction/InvertPark_Tranform/Inverse Park Transform'
 * '<S172>' : 'Controller/ControllerTask/ControllerMainFunction/InvertPark_Tranform/Inverse Park Transform/Two inputs CRL'
 * '<S173>' : 'Controller/ControllerTask/ControllerMainFunction/InvertPark_Tranform/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S174>' : 'Controller/ControllerTask/ControllerMainFunction/Open_Loop_Control/Position Generator'
 * '<S175>' : 'Controller/ControllerTask/ControllerMainFunction/Open_Loop_Control/Position Generator/Accumulate'
 * '<S176>' : 'Controller/ControllerTask/ControllerMainFunction/Open_Loop_Control/Position Generator/Accumulate/Subsystem'
 * '<S177>' : 'Controller/ControllerTask/ControllerMainFunction/PWM/MATLAB Function'
 * '<S178>' : 'Controller/ControllerTask/ControllerMainFunction/Park_Tranform/Park Transform'
 * '<S179>' : 'Controller/ControllerTask/ControllerMainFunction/Park_Tranform/Park Transform/Two inputs CRL'
 * '<S180>' : 'Controller/ControllerTask/ControllerMainFunction/Park_Tranform/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S181>' : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup/Interpolation'
 * '<S182>' : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup/WrapUp'
 * '<S183>' : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup/WrapUp/Compare To Zero'
 * '<S184>' : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup/WrapUp/If Action Subsystem'
 * '<S185>' : 'Controller/ControllerTask/ControllerMainFunction/Sine-Cosine_Lookup/WrapUp/If Action Subsystem1'
 * '<S186>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed'
 * '<S187>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector'
 * '<S188>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S189>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S190>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S191>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S192>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S193>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S194>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S195>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S196>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S197>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S198>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S199>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S200>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S201>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S202>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S203>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S204>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S205>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S206>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S207>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S208>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S209>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S210>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S211>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S212>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S213>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S214>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S215>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S216>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S217>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S218>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S219>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/Internal Parameters'
 * '<S220>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S221>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S222>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S223>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S224>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S225>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S226>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S227>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/Internal Parameters'
 * '<S228>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S229>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S230>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S231>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S232>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S233>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S234>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S235>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S236>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S237>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S238>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S239>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector/Absolute_Value'
 * '<S240>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector/Zero_Cancellation'
 * '<S241>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter'
 * '<S242>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S243>' : 'Controller/ControllerTask/ControllerMainFunction/Speed_Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
