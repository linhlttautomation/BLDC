/*
 * File: Controller.c
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

#include "Controller.h"
#include "rtwtypes.h"
#include "Controller_private.h"
#include "rt_atan2f_snf.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Controller_types.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<S2>/Chart1' */
#define Controller_IN_OpenLoop         ((uint8_T)1U)
#define Controller_IN_Startup          ((uint8_T)2U)

/* System initialize for referenced model: 'Controller' */
void Controller_Init(DW_Controller_f_T *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
  localDW->Integrator_IC_LOADING = 1U;

  /* InitializeConditions for RateLimiter: '<S239>/Rate Limiter' */
  localDW->PrevY = 95.5F;

  /* InitializeConditions for RateLimiter: '<S239>/Rate Limiter1' */
  localDW->PrevY_f = -95.5F;

  /* InitializeConditions for DiscreteIntegrator: '<S222>/Integrator' */
  localDW->Integrator_DSTATE_c = Controller_ConstB.Constant;

  /* InitializeConditions for DiscreteIntegrator: '<S104>/Integrator' */
  localDW->Integrator_IC_LOADING_e = 1U;
}

/* Output and update for referenced model: 'Controller' */
void ControllerTask(B_Controller_c_T *localB, DW_Controller_f_T *localDW,
                    ZCE_Controller_T *localZCE)
{
  int32_T tmp_1;
  real32_T rtb_DeadZone;
  real32_T rtb_DeadZone_i;
  real32_T rtb_IntegralGain_f;
  real32_T rtb_IntegralGain_k;
  real32_T rtb_Integrator_l;
  real32_T rtb_Sum1_o;
  real32_T rtb_Sum3;
  real32_T rtb_Sum3_j;
  real32_T rtb_Sum6_o;
  real32_T rtb_Sum_e;
  real32_T rtb_Sum_ox_tmp;
  real32_T rtb_Sum_p;
  real32_T rtb_add_b;
  real32_T rtb_elect2mech;
  uint32_T rtb_PositionToCount;
  uint16_T rtb_Saturation_a;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_NOT_n;
  boolean_T rtb_Switch2_k;
  boolean_T rtb_bEnableOpenLoop;

  /* Chart: '<S2>/Chart1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  if (localDW->is_active_c1_Controller == 0U) {
    localDW->is_active_c1_Controller = 1U;
    localDW->is_c1_Controller = Controller_IN_Startup;
    rtb_bEnableOpenLoop = false;
  } else if (localDW->is_c1_Controller == Controller_IN_OpenLoop) {
    rtb_bEnableOpenLoop = true;
    if (!Test_Input.Input1) {
      localDW->is_c1_Controller = Controller_IN_Startup;
      rtb_bEnableOpenLoop = false;
    }
  } else {
    /* case IN_Startup: */
    rtb_bEnableOpenLoop = false;
    if (Test_Input.Input1) {
      localDW->is_c1_Controller = Controller_IN_OpenLoop;
      rtb_bEnableOpenLoop = true;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* Logic: '<S6>/NOT' incorporates:
   *  Logic: '<S186>/AND'
   */
  rtb_NOT_n = !rtb_bEnableOpenLoop;

  /* Sum: '<S160>/Add1' incorporates:
   *  Constant: '<S160>/Filter_Constant'
   *  Constant: '<S160>/One'
   *  Delay: '<S2>/Delay1'
   *  Product: '<S160>/Product'
   *  Product: '<S160>/Product1'
   *  UnitDelay: '<S160>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = localDW->Delay1_DSTATE * 0.01F + 0.99F *
    localDW->UnitDelay_DSTATE;

  /* Sum: '<S168>/Add1' incorporates:
   *  Constant: '<S168>/Filter_Constant'
   *  Constant: '<S168>/One'
   *  Delay: '<S2>/Delay3'
   *  Product: '<S168>/Product'
   *  Product: '<S168>/Product1'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_a = localDW->Delay3_DSTATE * 0.01F + 0.99F *
    localDW->UnitDelay_DSTATE_a;

  /* Sum: '<S127>/Sum6' incorporates:
   *  Delay: '<S2>/Delay3'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  rtb_Integrator_l = localDW->Delay3_DSTATE - localDW->UnitDelay_DSTATE_a;

  /* Sum: '<S141>/Sum3' incorporates:
   *  Delay: '<S2>/Delay1'
   *  Gain: '<S144>/ScalingR'
   *  Sum: '<S125>/Sum6'
   *  UnitDelay: '<S160>/Unit Delay'
   */
  rtb_Sum3 = (localDW->Delay1_DSTATE - localDW->UnitDelay_DSTATE) - 1.45234621F *
    rtb_Integrator_l;

  /* Delay: '<S143>/Delay1' incorporates:
   *  Logic: '<S6>/NOT'
   */
  if ((((localZCE->Delay1_Reset_ZCE == POS_ZCSIG) != (int32_T)rtb_NOT_n) &&
       (localZCE->Delay1_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtb_NOT_n) {
    localDW->Delay1_DSTATE_o = 0.0F;
  }

  localZCE->Delay1_Reset_ZCE = rtb_NOT_n;

  /* Delay: '<S143>/Delay' incorporates:
   *  Logic: '<S6>/NOT'
   */
  if ((((localZCE->Delay_Reset_ZCE == POS_ZCSIG) != (int32_T)rtb_NOT_n) &&
       (localZCE->Delay_Reset_ZCE != UNINITIALIZED_ZCSIG)) || rtb_NOT_n) {
    localDW->Delay_DSTATE = 0.0F;
  }

  localZCE->Delay_Reset_ZCE = rtb_NOT_n;

  /* Sum: '<S143>/Sum1' incorporates:
   *  Delay: '<S143>/Delay'
   *  Delay: '<S143>/Delay1'
   *  Gain: '<S143>/Gain1'
   *  Gain: '<S143>/Gain2'
   *  Sum: '<S143>/Sum'
   */
  localDW->Delay_DSTATE = (rtb_Sum3 + localDW->Delay1_DSTATE_o) * 4.99995E-5F +
    0.99998F * localDW->Delay_DSTATE;

  /* Sum: '<S141>/Sum1' incorporates:
   *  Delay: '<S143>/Delay'
   *  Gain: '<S144>/ScalingL'
   */
  rtb_Sum1_o = localDW->Delay_DSTATE - 0.000280375738F * rtb_Integrator_l;

  /* Sum: '<S147>/Add1' incorporates:
   *  Constant: '<S147>/Filter_Constant'
   *  Constant: '<S147>/One'
   *  Product: '<S147>/Product'
   *  Product: '<S147>/Product1'
   *  UnitDelay: '<S147>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_b = rtb_Sum1_o * 0.00199801126F + 0.998002F *
    localDW->UnitDelay_DSTATE_b;

  /* Sum: '<S156>/Add1' incorporates:
   *  Constant: '<S156>/Filter_Constant'
   *  Constant: '<S156>/One'
   *  Delay: '<S2>/Delay'
   *  Product: '<S156>/Product'
   *  Product: '<S156>/Product1'
   *  UnitDelay: '<S156>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_c = localDW->Delay_DSTATE_f * 0.01F + 0.99F *
    localDW->UnitDelay_DSTATE_c;

  /* Sum: '<S164>/Add1' incorporates:
   *  Constant: '<S164>/Filter_Constant'
   *  Constant: '<S164>/One'
   *  Delay: '<S2>/Delay2'
   *  Product: '<S164>/Product'
   *  Product: '<S164>/Product1'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_m = localDW->Delay2_DSTATE * 0.01F + 0.99F *
    localDW->UnitDelay_DSTATE_m;

  /* Sum: '<S126>/Sum6' incorporates:
   *  Delay: '<S2>/Delay2'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  rtb_Integrator_l = localDW->Delay2_DSTATE - localDW->UnitDelay_DSTATE_m;

  /* Sum: '<S134>/Sum3' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S137>/ScalingR'
   *  Sum: '<S124>/Sum6'
   *  UnitDelay: '<S156>/Unit Delay'
   */
  rtb_Sum3_j = (localDW->Delay_DSTATE_f - localDW->UnitDelay_DSTATE_c) -
    1.45234621F * rtb_Integrator_l;

  /* Delay: '<S136>/Delay1' incorporates:
   *  Logic: '<S6>/NOT'
   */
  if ((((localZCE->Delay1_Reset_ZCE_b == POS_ZCSIG) != (int32_T)rtb_NOT_n) &&
       (localZCE->Delay1_Reset_ZCE_b != UNINITIALIZED_ZCSIG)) || rtb_NOT_n) {
    localDW->Delay1_DSTATE_h = 0.0F;
  }

  localZCE->Delay1_Reset_ZCE_b = rtb_NOT_n;

  /* Delay: '<S136>/Delay' incorporates:
   *  Logic: '<S6>/NOT'
   */
  if ((((localZCE->Delay_Reset_ZCE_j == POS_ZCSIG) != (int32_T)rtb_NOT_n) &&
       (localZCE->Delay_Reset_ZCE_j != UNINITIALIZED_ZCSIG)) || rtb_NOT_n) {
    localDW->Delay_DSTATE_k = 0.0F;
  }

  localZCE->Delay_Reset_ZCE_j = rtb_NOT_n;

  /* Sum: '<S136>/Sum1' incorporates:
   *  Delay: '<S136>/Delay'
   *  Delay: '<S136>/Delay1'
   *  Gain: '<S136>/Gain1'
   *  Gain: '<S136>/Gain2'
   *  Sum: '<S136>/Sum'
   */
  localDW->Delay_DSTATE_k = (rtb_Sum3_j + localDW->Delay1_DSTATE_h) *
    4.99995E-5F + 0.99998F * localDW->Delay_DSTATE_k;

  /* Sum: '<S134>/Sum1' incorporates:
   *  Delay: '<S136>/Delay'
   *  Gain: '<S137>/ScalingL'
   */
  rtb_Integrator_l = localDW->Delay_DSTATE_k - 0.000280375738F *
    rtb_Integrator_l;

  /* Sum: '<S140>/Add1' incorporates:
   *  Constant: '<S140>/Filter_Constant'
   *  Constant: '<S140>/One'
   *  Product: '<S140>/Product'
   *  Product: '<S140>/Product1'
   *  UnitDelay: '<S140>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_d = rtb_Integrator_l * 0.00199801126F + 0.998002F *
    localDW->UnitDelay_DSTATE_d;

  /* Switch: '<S141>/Switch' incorporates:
   *  Constant: '<S134>/Constant'
   *  Constant: '<S141>/Constant'
   *  Logic: '<S6>/NOT'
   *  Sum: '<S139>/Sum'
   *  Sum: '<S146>/Sum'
   *  Switch: '<S134>/Switch'
   *  UnitDelay: '<S140>/Unit Delay'
   *  UnitDelay: '<S147>/Unit Delay'
   */
  if (rtb_NOT_n) {
    rtb_IntegralGain_f = 0.0F;
    rtb_Sum1_o = 1.0E-6F;
  } else {
    rtb_IntegralGain_f = rtb_Sum1_o - localDW->UnitDelay_DSTATE_b;
    rtb_Sum1_o = rtb_Integrator_l - localDW->UnitDelay_DSTATE_d;
  }

  /* Outputs for Atomic SubSystem: '<S131>/atan2' */
  /* Outputs for Atomic SubSystem: '<S132>/Per Unit' */
  /* Gain: '<S133>/Gain' incorporates:
   *  Switch: '<S132>/Switch'
   *  Switch: '<S134>/Switch'
   *  Switch: '<S141>/Switch'
   *  Trigonometry: '<S132>/Atan2'
   */
  rtb_Sum1_o = 0.159154937F * rt_atan2f_snf(rtb_IntegralGain_f, rtb_Sum1_o);

  /* Switch: '<S133>/Switch' incorporates:
   *  Switch: '<S132>/Switch'
   */
  if (!(rtb_Sum1_o >= 0.0F)) {
    /* AlgorithmDescriptorDelegate generated from: '<S132>/a16' incorporates:
     *  Bias: '<S133>/Bias'
     */
    rtb_Sum1_o++;
  }

  /* End of Switch: '<S133>/Switch' */
  /* End of Outputs for SubSystem: '<S132>/Per Unit' */
  /* End of Outputs for SubSystem: '<S131>/atan2' */

  /* Abs: '<S9>/Abs' incorporates:
   *  Abs: '<S17>/Abs'
   *  Abs: '<S18>/Abs'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Switch: '<S17>/Switch'
   *  Switch: '<S18>/Switch'
   */
  rtb_add_b = fabsf(Test_Input.Input2);

  /* Switch: '<S9>/Switch2' incorporates:
   *  Abs: '<S9>/Abs'
   */
  rtb_Switch2_k = (rtb_add_b > 0.1F);

  /* Outputs for Enabled SubSystem: '<S174>/Accumulate' incorporates:
   *  EnablePort: '<S175>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S175>/Subsystem' incorporates:
   *  EnablePort: '<S176>/Enable'
   */
  /* Delay: '<S175>/Delay' */
  if (localDW->Delay_DSTATE_i) {
    /* SignalConversion generated from: '<S176>/Input' incorporates:
     *  Gain: '<S9>/Gain'
     *  Inport generated from: '<Root>/In Bus Element'
     */
    localB->Input = 0.0010471975F * Test_Input.Input2;
  }

  /* End of Delay: '<S175>/Delay' */
  /* End of Outputs for SubSystem: '<S175>/Subsystem' */

  /* Sum: '<S175>/Add' incorporates:
   *  UnitDelay: '<S174>/Unit Delay'
   */
  rtb_DeadZone_i = localB->Input + localDW->UnitDelay_DSTATE_k;

  /* DataTypeConversion: '<S175>/Data Type Conversion' */
  rtb_IntegralGain_f = floorf(rtb_DeadZone_i);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    tmp_1 = (int16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
  } else {
    tmp_1 = (int16_T)(uint16_T)rtb_IntegralGain_f;
  }

  /* Sum: '<S175>/Add1' incorporates:
   *  DataTypeConversion: '<S175>/Data Type Conversion'
   *  DataTypeConversion: '<S175>/Data Type Conversion1'
   *  UnitDelay: '<S174>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_k = rtb_DeadZone_i - (real32_T)tmp_1;

  /* Update for Delay: '<S175>/Delay' incorporates:
   *  Constant: '<S175>/Constant'
   */
  localDW->Delay_DSTATE_i = true;

  /* End of Outputs for SubSystem: '<S174>/Accumulate' */

  /* Switch: '<S9>/Switch' incorporates:
   *  UnitDelay: '<S174>/Unit Delay'
   */
  if (rtb_Switch2_k) {
    rtb_Integrator_l = rtb_Sum1_o;
  } else {
    rtb_Integrator_l = localDW->UnitDelay_DSTATE_k;
  }

  /* End of Switch: '<S9>/Switch' */

  /* If: '<S182>/If' incorporates:
   *  Constant: '<S183>/Constant'
   *  RelationalOperator: '<S183>/Compare'
   */
  if (rtb_Integrator_l < 0.0F) {
    /* Outputs for IfAction SubSystem: '<S182>/If Action Subsystem' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    /* DataTypeConversion: '<S184>/Convert_uint16' */
    rtb_IntegralGain_f = floorf(rtb_Integrator_l);
    if (rtIsInfF(rtb_IntegralGain_f)) {
      rtb_IntegralGain_f = 0.0F;
    } else {
      rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
    }

    if (rtb_IntegralGain_f < 0.0F) {
      tmp_1 = (int16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
    } else {
      tmp_1 = (int16_T)(uint16_T)rtb_IntegralGain_f;
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  DataTypeConversion: '<S184>/Convert_back'
     *  DataTypeConversion: '<S184>/Convert_uint16'
     */
    rtb_Integrator_l -= (real32_T)tmp_1;

    /* End of Outputs for SubSystem: '<S182>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S182>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    /* DataTypeConversion: '<S185>/Convert_uint16' */
    rtb_IntegralGain_f = truncf(rtb_Integrator_l);
    if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
      rtb_IntegralGain_f = 0.0F;
    } else {
      rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
    }

    /* Sum: '<S185>/Sum' incorporates:
     *  DataTypeConversion: '<S185>/Convert_back'
     *  DataTypeConversion: '<S185>/Convert_uint16'
     */
    rtb_Integrator_l -= (real32_T)(int16_T)(uint16_T)rtb_IntegralGain_f;

    /* End of Outputs for SubSystem: '<S182>/If Action Subsystem1' */
  }

  /* End of If: '<S182>/If' */

  /* Gain: '<S12>/indexing' */
  rtb_Integrator_l *= 800.0F;

  /* DataTypeConversion: '<S12>/Get_Integer' */
  rtb_IntegralGain_f = truncf(rtb_Integrator_l);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    rtb_Saturation_a = (uint16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
  } else {
    rtb_Saturation_a = (uint16_T)rtb_IntegralGain_f;
  }

  /* End of DataTypeConversion: '<S12>/Get_Integer' */

  /* Sum: '<S12>/Sum2' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion1'
   */
  rtb_IntegralGain_f = rtb_Integrator_l - (real32_T)rtb_Saturation_a;

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/sine_table_values'
   *  Sum: '<S12>/Sum'
   */
  rtb_Integrator_l = rtCP_sine_table_values_Value[rtb_Saturation_a];

  /* Sum: '<S181>/Sum4' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  Product: '<S181>/Product'
   *  Selector: '<S12>/Lookup'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S181>/Sum3'
   */
  rtb_DeadZone_i = (rtCP_sine_table_values_Value[(int32_T)(rtb_Saturation_a + 1U)]
                    - rtb_Integrator_l) * rtb_IntegralGain_f + rtb_Integrator_l;

  /* Outputs for Atomic SubSystem: '<S15>/Two phase CRL wrap' */
  /* AlgorithmDescriptorDelegate generated from: '<S16>/a16' incorporates:
   *  Delay: '<S2>/Delay2'
   *  Delay: '<S2>/Delay3'
   *  Gain: '<S16>/one_by_sqrt3'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Sum: '<S16>/a_plus_2b'
   */
  localDW->Delay2_DSTATE = Test_Input.Input3;
  localDW->Delay3_DSTATE = ((Test_Input.Input3 + Test_Input.Input4) +
    Test_Input.Input4) * 0.577350259F;

  /* End of Outputs for SubSystem: '<S15>/Two phase CRL wrap' */

  /* Selector: '<S12>/Lookup' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S181>/Sum5'
   */
  rtb_Integrator_l = rtCP_sine_table_values_Value[(int32_T)(rtb_Saturation_a +
    200U)];

  /* Sum: '<S181>/Sum6' incorporates:
   *  Constant: '<S12>/offset'
   *  Constant: '<S12>/sine_table_values'
   *  Product: '<S181>/Product1'
   *  Selector: '<S12>/Lookup'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S181>/Sum5'
   */
  rtb_Sum6_o = (rtCP_sine_table_values_Value[(int32_T)(rtb_Saturation_a + 201U)]
                - rtb_Integrator_l) * rtb_IntegralGain_f + rtb_Integrator_l;

  /* Logic: '<S17>/NOT' incorporates:
   *  Logic: '<S186>/AND'
   *  Logic: '<S18>/NOT'
   */
  rtb_bEnableOpenLoop = !rtb_Switch2_k;

  /* DiscreteIntegrator: '<S53>/Integrator' incorporates:
   *  Logic: '<S17>/NOT'
   *  UnitDelay: '<S17>/Unit Delay'
   */
  if (localDW->Integrator_IC_LOADING != 0) {
    localDW->Integrator_DSTATE = localDW->UnitDelay_DSTATE_b1;
  }

  if (rtb_bEnableOpenLoop || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = localDW->UnitDelay_DSTATE_b1;
  }

  /* Outputs for Atomic SubSystem: '<S178>/Two inputs CRL' */
  /* Sum: '<S17>/Sum1' incorporates:
   *  Constant: '<S13>/Constant'
   *  Delay: '<S2>/Delay2'
   *  Delay: '<S2>/Delay3'
   *  Product: '<S179>/acos'
   *  Product: '<S179>/bsin'
   *  Sum: '<S179>/sum_Ds'
   */
  rtb_Sum_ox_tmp = 0.0F - (localDW->Delay2_DSTATE * rtb_Sum6_o +
    localDW->Delay3_DSTATE * rtb_DeadZone_i);

  /* End of Outputs for SubSystem: '<S178>/Two inputs CRL' */

  /* Sum: '<S62>/Sum' incorporates:
   *  DiscreteIntegrator: '<S53>/Integrator'
   *  Gain: '<S58>/Proportional Gain'
   *  Sum: '<S17>/Sum1'
   */
  rtb_Sum_p = rtb_Sum_ox_tmp * 0.1F + localDW->Integrator_DSTATE;

  /* Switch: '<S17>/Switch' incorporates:
   *  Saturate: '<S17>/Saturation'
   */
  if (rtb_Switch2_k) {
    /* Saturate: '<S60>/Saturation' */
    if (rtb_Sum_p > 13.8564062F) {
      localDW->UnitDelay_DSTATE_b1 = 13.8564062F;
    } else if (rtb_Sum_p < -13.8564062F) {
      localDW->UnitDelay_DSTATE_b1 = -13.8564062F;
    } else {
      localDW->UnitDelay_DSTATE_b1 = rtb_Sum_p;
    }

    /* End of Saturate: '<S60>/Saturation' */
  } else if (rtb_add_b > 191.0F) {
    /* Saturate: '<S17>/Saturation' */
    localDW->UnitDelay_DSTATE_b1 = 191.0F;
  } else if (rtb_add_b < 95.5F) {
    /* Saturate: '<S17>/Saturation' */
    localDW->UnitDelay_DSTATE_b1 = 95.5F;
  } else {
    /* Saturate: '<S17>/Saturation' */
    localDW->UnitDelay_DSTATE_b1 = rtb_add_b;
  }

  /* RateLimiter: '<S239>/Rate Limiter' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  rtb_IntegralGain_f = Test_Input.Input2 - localDW->PrevY;
  if (rtb_IntegralGain_f > 0.0005F) {
    /* RateLimiter: '<S239>/Rate Limiter' */
    localDW->PrevY += 0.0005F;
  } else if (rtb_IntegralGain_f < -0.0005F) {
    /* RateLimiter: '<S239>/Rate Limiter' */
    localDW->PrevY -= 0.0005F;
  } else {
    /* RateLimiter: '<S239>/Rate Limiter' */
    localDW->PrevY = Test_Input.Input2;
  }

  /* End of RateLimiter: '<S239>/Rate Limiter' */

  /* RateLimiter: '<S239>/Rate Limiter1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  rtb_IntegralGain_f = Test_Input.Input2 - localDW->PrevY_f;
  if (rtb_IntegralGain_f > 0.0005F) {
    /* RateLimiter: '<S239>/Rate Limiter1' */
    localDW->PrevY_f += 0.0005F;
  } else if (rtb_IntegralGain_f < -0.0005F) {
    /* RateLimiter: '<S239>/Rate Limiter1' */
    localDW->PrevY_f -= 0.0005F;
  } else {
    /* RateLimiter: '<S239>/Rate Limiter1' */
    localDW->PrevY_f = Test_Input.Input2;
  }

  /* End of RateLimiter: '<S239>/Rate Limiter1' */

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant1'
   *  Inport generated from: '<Root>/In Bus Element'
   *  Switch: '<S187>/Switch1'
   *  Switch: '<S239>/Switch'
   */
  if (rtb_Switch2_k) {
    /* Switch: '<S239>/Switch' incorporates:
     *  Inport generated from: '<Root>/In Bus Element'
     */
    if (Test_Input.Input2 >= 0.0F) {
      rtb_IntegralGain_f = localDW->PrevY;
    } else {
      rtb_IntegralGain_f = localDW->PrevY_f;
    }
  } else if (Test_Input.Input2 > 0.0F) {
    /* Switch: '<S187>/Switch1' incorporates:
     *  Constant: '<S187>/Constant'
     *  Switch: '<S239>/Switch'
     */
    rtb_IntegralGain_f = 95.5F;
  } else {
    rtb_IntegralGain_f = -95.5F;
  }

  /* Sum: '<S243>/Add1' incorporates:
   *  Constant: '<S243>/Filter_Constant'
   *  Constant: '<S243>/One'
   *  Product: '<S243>/Product'
   *  Product: '<S243>/Product1'
   *  Switch: '<S187>/Switch'
   *  UnitDelay: '<S243>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_de = rtb_IntegralGain_f * 0.01F + 0.99F *
    localDW->UnitDelay_DSTATE_de;

  /* Gain: '<S123>/PositionToCount' */
  rtb_IntegralGain_f = truncf(4.2949673E+9F * rtb_Sum1_o);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 4.2949673E+9F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    rtb_PositionToCount = (uint32_T)-(int32_T)(uint32_T)-rtb_IntegralGain_f;
  } else {
    rtb_PositionToCount = (uint32_T)rtb_IntegralGain_f;
  }

  /* End of Gain: '<S123>/PositionToCount' */

  /* Sum: '<S150>/Add1' incorporates:
   *  Constant: '<S150>/Filter_Constant'
   *  Constant: '<S150>/One'
   *  DataTypeConversion: '<S152>/DTC'
   *  Delay: '<S123>/Delay'
   *  Gain: '<S123>/SpeedGain'
   *  Product: '<S150>/Product'
   *  Product: '<S150>/Product1'
   *  Sum: '<S123>/SpeedCount'
   *  UnitDelay: '<S150>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE_di = (real32_T)((int32_T)rtb_PositionToCount -
    (int32_T)localDW->Delay_DSTATE_a[localDW->CircBufIdx]) * 6.98491931E-9F *
    0.01F + 0.99F * localDW->UnitDelay_DSTATE_di;

  /* Gain: '<S6>/elect2mech' incorporates:
   *  UnitDelay: '<S150>/Unit Delay'
   */
  rtb_elect2mech = 0.2F * localDW->UnitDelay_DSTATE_di;

  /* Sum: '<S186>/Sum' incorporates:
   *  UnitDelay: '<S243>/Unit Delay'
   */
  rtb_Integrator_l = localDW->UnitDelay_DSTATE_de - rtb_elect2mech;

  /* Logic: '<S186>/NOT' incorporates:
   *  Logic: '<S186>/AND'
   */
  rtb_NOT_n = (rtb_NOT_n || rtb_bEnableOpenLoop);

  /* DiscreteIntegrator: '<S222>/Integrator' */
  if (rtb_NOT_n || (localDW->Integrator_PrevResetState_f != 0)) {
    localDW->Integrator_DSTATE_c = Controller_ConstB.Constant;
  }

  /* Sum: '<S231>/Sum' incorporates:
   *  DiscreteIntegrator: '<S222>/Integrator'
   *  Gain: '<S227>/Proportional Gain'
   */
  rtb_DeadZone = 0.05F * rtb_Integrator_l + localDW->Integrator_DSTATE_c;

  /* Saturate: '<S229>/Saturation' */
  if (rtb_DeadZone > 7.77F) {
    rtb_IntegralGain_f = 7.77F;
  } else if (rtb_DeadZone < -7.77F) {
    rtb_IntegralGain_f = -7.77F;
  } else {
    rtb_IntegralGain_f = rtb_DeadZone;
  }

  /* Outputs for Atomic SubSystem: '<S178>/Two inputs CRL' */
  /* Sum: '<S18>/Sum1' incorporates:
   *  Delay: '<S2>/Delay2'
   *  Delay: '<S2>/Delay3'
   *  Product: '<S179>/asin'
   *  Product: '<S179>/bcos'
   *  Saturate: '<S229>/Saturation'
   *  Sum: '<S179>/sum_Qs'
   */
  rtb_IntegralGain_k = rtb_IntegralGain_f - (localDW->Delay3_DSTATE * rtb_Sum6_o
    - localDW->Delay2_DSTATE * rtb_DeadZone_i);

  /* End of Outputs for SubSystem: '<S178>/Two inputs CRL' */

  /* DiscreteIntegrator: '<S104>/Integrator' incorporates:
   *  UnitDelay: '<S18>/Unit Delay'
   */
  if (localDW->Integrator_IC_LOADING_e != 0) {
    localDW->Integrator_DSTATE_h = localDW->UnitDelay_DSTATE_o;
  }

  if (rtb_bEnableOpenLoop || (localDW->Integrator_PrevResetState_h != 0)) {
    localDW->Integrator_DSTATE_h = localDW->UnitDelay_DSTATE_o;
  }

  /* Sum: '<S113>/Sum' incorporates:
   *  DiscreteIntegrator: '<S104>/Integrator'
   *  Gain: '<S109>/Proportional Gain'
   */
  rtb_Sum_e = 0.1F * rtb_IntegralGain_k + localDW->Integrator_DSTATE_h;

  /* Switch: '<S18>/Switch' incorporates:
   *  Saturate: '<S18>/Saturation'
   */
  if (rtb_Switch2_k) {
    /* Saturate: '<S111>/Saturation' */
    if (rtb_Sum_e > 13.8564062F) {
      localDW->UnitDelay_DSTATE_o = 13.8564062F;
    } else if (rtb_Sum_e < -13.8564062F) {
      localDW->UnitDelay_DSTATE_o = -13.8564062F;
    } else {
      localDW->UnitDelay_DSTATE_o = rtb_Sum_e;
    }

    /* End of Saturate: '<S111>/Saturation' */
  } else if (rtb_add_b > 191.0F) {
    /* Saturate: '<S18>/Saturation' */
    localDW->UnitDelay_DSTATE_o = 191.0F;
  } else if (rtb_add_b < 95.5F) {
    /* Saturate: '<S18>/Saturation' */
    localDW->UnitDelay_DSTATE_o = 95.5F;
  } else {
    /* Saturate: '<S18>/Saturation' */
    localDW->UnitDelay_DSTATE_o = rtb_add_b;
  }

  /* Outputs for Atomic SubSystem: '<S171>/Two inputs CRL' */
  /* AlgorithmDescriptorDelegate generated from: '<S172>/a16' incorporates:
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   *  Product: '<S172>/dcos'
   *  Product: '<S172>/dsin'
   *  Product: '<S172>/qcos'
   *  Product: '<S172>/qsin'
   *  Sum: '<S172>/sum_alpha'
   *  Sum: '<S172>/sum_beta'
   *  UnitDelay: '<S17>/Unit Delay'
   *  UnitDelay: '<S18>/Unit Delay'
   */
  localDW->Delay_DSTATE_f = localDW->UnitDelay_DSTATE_b1 * rtb_Sum6_o -
    localDW->UnitDelay_DSTATE_o * rtb_DeadZone_i;
  localDW->Delay1_DSTATE = localDW->UnitDelay_DSTATE_o * rtb_Sum6_o +
    localDW->UnitDelay_DSTATE_b1 * rtb_DeadZone_i;

  /* End of Outputs for SubSystem: '<S171>/Two inputs CRL' */

  /* Gain: '<S170>/one_by_two' incorporates:
   *  Delay: '<S2>/Delay'
   */
  rtb_IntegralGain_f = 0.5F * localDW->Delay_DSTATE_f;

  /* Gain: '<S170>/sqrt3_by_two' incorporates:
   *  Delay: '<S2>/Delay1'
   */
  rtb_DeadZone_i = 0.866025388F * localDW->Delay1_DSTATE;

  /* Sum: '<S170>/add_b' */
  rtb_add_b = rtb_DeadZone_i - rtb_IntegralGain_f;

  /* Sum: '<S170>/add_c' */
  rtb_DeadZone_i = (0.0F - rtb_IntegralGain_f) - rtb_DeadZone_i;

  /* Fcn: '<S10>/Fcn' incorporates:
   *  Delay: '<S2>/Delay'
   *  MinMax: '<S10>/Max'
   *  MinMax: '<S10>/Max1'
   */
  rtb_Sum6_o = (fmaxf(fmaxf(localDW->Delay_DSTATE_f, rtb_add_b), rtb_DeadZone_i)
                + fminf(fminf(localDW->Delay_DSTATE_f, rtb_add_b),
                        rtb_DeadZone_i)) * -0.5F;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Delay: '<S2>/Delay'
   *  Inport generated from: '<Root>/In Bus Element'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_IntegralGain_f = floorf(((localDW->Delay_DSTATE_f + rtb_Sum6_o) /
    Test_Input.Input5 + 0.5F) * 1599.0F);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    /* Saturate: '<S10>/Saturation' */
    rtb_Saturation_a = (uint16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
  } else {
    /* Saturate: '<S10>/Saturation' */
    rtb_Saturation_a = (uint16_T)rtb_IntegralGain_f;
  }

  /* End of Gain: '<S10>/Gain1' */

  /* Saturate: '<S10>/Saturation' */
  if (rtb_Saturation_a <= 1599) {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output1 = rtb_Saturation_a;
  } else {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output1 = 1599U;
  }

  /* Gain: '<S10>/Gain8' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_IntegralGain_f = floorf(((rtb_add_b + rtb_Sum6_o) / Test_Input.Input5 +
    0.5F) * 1599.0F);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    /* Saturate: '<S10>/Saturation2' */
    rtb_Saturation_a = (uint16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
  } else {
    /* Saturate: '<S10>/Saturation2' */
    rtb_Saturation_a = (uint16_T)rtb_IntegralGain_f;
  }

  /* End of Gain: '<S10>/Gain8' */

  /* Saturate: '<S10>/Saturation2' */
  if (rtb_Saturation_a <= 1599) {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output2 = rtb_Saturation_a;
  } else {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output2 = 1599U;
  }

  /* Gain: '<S10>/Gain11' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_IntegralGain_f = floorf(((rtb_DeadZone_i + rtb_Sum6_o) / Test_Input.Input5
    + 0.5F) * 1599.0F);
  if (rtIsNaNF(rtb_IntegralGain_f) || rtIsInfF(rtb_IntegralGain_f)) {
    rtb_IntegralGain_f = 0.0F;
  } else {
    rtb_IntegralGain_f = fmodf(rtb_IntegralGain_f, 65536.0F);
  }

  if (rtb_IntegralGain_f < 0.0F) {
    /* Saturate: '<S10>/Saturation1' */
    rtb_Saturation_a = (uint16_T)-(int16_T)(uint16_T)-rtb_IntegralGain_f;
  } else {
    /* Saturate: '<S10>/Saturation1' */
    rtb_Saturation_a = (uint16_T)rtb_IntegralGain_f;
  }

  /* End of Gain: '<S10>/Gain11' */

  /* Saturate: '<S10>/Saturation1' */
  if (rtb_Saturation_a <= 1599) {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output3 = rtb_Saturation_a;
  } else {
    /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
    Test_Output.Output3 = 1599U;
  }

  /* BusCreator generated from: '<S1>/Test_Output_BusCreator' */
  Test_Output.Output4 = rtb_elect2mech;
  Test_Output.Output6 = false;
  Test_Output.Output7 = 0.0F;
  Test_Output.Output8 = 0.0F;
  Test_Output.Output9 = 0.0F;
  Test_Output.Output5 = rtb_Sum1_o;

  /* DeadZone: '<S97>/DeadZone' */
  if (rtb_Sum_e > 13.8564062F) {
    rtb_DeadZone_i = rtb_Sum_e - 13.8564062F;
  } else if (rtb_Sum_e >= -13.8564062F) {
    rtb_DeadZone_i = 0.0F;
  } else {
    rtb_DeadZone_i = rtb_Sum_e - -13.8564062F;
  }

  /* End of DeadZone: '<S97>/DeadZone' */

  /* Gain: '<S101>/Integral Gain' */
  rtb_IntegralGain_k *= 0.01F;

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  Constant: '<S95>/Constant'
   *  Constant: '<S95>/Constant2'
   *  RelationalOperator: '<S95>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_i > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S95>/Switch2' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  Constant: '<S95>/Constant3'
   *  Constant: '<S95>/Constant4'
   *  RelationalOperator: '<S95>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain_k > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Logic: '<S95>/AND3' incorporates:
   *  Constant: '<S95>/Clamping_zero'
   *  RelationalOperator: '<S95>/Equal1'
   *  RelationalOperator: '<S95>/Relational Operator'
   *  Switch: '<S95>/Switch1'
   *  Switch: '<S95>/Switch2'
   */
  rtb_Switch2_k = ((rtb_DeadZone_i != 0.0F) && (tmp == tmp_0));

  /* DeadZone: '<S215>/DeadZone' */
  if (rtb_DeadZone > 7.77F) {
    rtb_DeadZone -= 7.77F;
  } else if (rtb_DeadZone >= -7.77F) {
    rtb_DeadZone = 0.0F;
  } else {
    rtb_DeadZone -= -7.77F;
  }

  /* End of DeadZone: '<S215>/DeadZone' */

  /* Gain: '<S219>/Integral Gain' */
  rtb_Integrator_l *= 0.001F;

  /* DeadZone: '<S46>/DeadZone' */
  if (rtb_Sum_p > 13.8564062F) {
    rtb_DeadZone_i = rtb_Sum_p - 13.8564062F;
  } else if (rtb_Sum_p >= -13.8564062F) {
    rtb_DeadZone_i = 0.0F;
  } else {
    rtb_DeadZone_i = rtb_Sum_p - -13.8564062F;
  }

  /* End of DeadZone: '<S46>/DeadZone' */

  /* Gain: '<S50>/Integral Gain' */
  rtb_IntegralGain_f = rtb_Sum_ox_tmp * 0.01F;

  /* Update for Delay: '<S143>/Delay1' */
  localDW->Delay1_DSTATE_o = rtb_Sum3;

  /* Update for Delay: '<S136>/Delay1' */
  localDW->Delay1_DSTATE_h = rtb_Sum3_j;

  /* Update for DiscreteIntegrator: '<S53>/Integrator' */
  localDW->Integrator_IC_LOADING = 0U;

  /* Switch: '<S44>/Switch1' incorporates:
   *  Constant: '<S44>/Clamping_zero'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S44>/Constant2'
   *  RelationalOperator: '<S44>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_i > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S44>/Switch2' incorporates:
   *  Constant: '<S44>/Clamping_zero'
   *  Constant: '<S44>/Constant3'
   *  Constant: '<S44>/Constant4'
   *  RelationalOperator: '<S44>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain_f > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Clamping_zero'
   *  Constant: '<S44>/Constant1'
   *  Logic: '<S44>/AND3'
   *  RelationalOperator: '<S44>/Equal1'
   *  RelationalOperator: '<S44>/Relational Operator'
   *  Switch: '<S44>/Switch1'
   *  Switch: '<S44>/Switch2'
   */
  if ((rtb_DeadZone_i != 0.0F) && (tmp == tmp_0)) {
    rtb_IntegralGain_f = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S53>/Integrator' incorporates:
   *  Logic: '<S17>/NOT'
   *  Switch: '<S44>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IntegralGain_f;
  localDW->Integrator_PrevResetState = (int8_T)rtb_bEnableOpenLoop;

  /* Update for Delay: '<S123>/Delay' */
  localDW->Delay_DSTATE_a[localDW->CircBufIdx] = rtb_PositionToCount;
  if (localDW->CircBufIdx < 9U) {
    localDW->CircBufIdx++;
  } else {
    localDW->CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S123>/Delay' */

  /* Switch: '<S213>/Switch1' incorporates:
   *  Constant: '<S213>/Clamping_zero'
   *  Constant: '<S213>/Constant'
   *  Constant: '<S213>/Constant2'
   *  RelationalOperator: '<S213>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S213>/Switch2' incorporates:
   *  Constant: '<S213>/Clamping_zero'
   *  Constant: '<S213>/Constant3'
   *  Constant: '<S213>/Constant4'
   *  RelationalOperator: '<S213>/fix for DT propagation issue1'
   */
  if (rtb_Integrator_l > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S213>/Switch' incorporates:
   *  Constant: '<S213>/Clamping_zero'
   *  Constant: '<S213>/Constant1'
   *  Logic: '<S213>/AND3'
   *  RelationalOperator: '<S213>/Equal1'
   *  RelationalOperator: '<S213>/Relational Operator'
   *  Switch: '<S213>/Switch1'
   *  Switch: '<S213>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_Integrator_l = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S222>/Integrator' incorporates:
   *  Switch: '<S213>/Switch'
   */
  localDW->Integrator_DSTATE_c += rtb_Integrator_l;
  localDW->Integrator_PrevResetState_f = (int8_T)rtb_NOT_n;

  /* Update for DiscreteIntegrator: '<S104>/Integrator' */
  localDW->Integrator_IC_LOADING_e = 0U;

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Constant1'
   */
  if (rtb_Switch2_k) {
    rtb_IntegralGain_k = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S104>/Integrator' incorporates:
   *  Logic: '<S17>/NOT'
   *  Switch: '<S95>/Switch'
   */
  localDW->Integrator_DSTATE_h += rtb_IntegralGain_k;
  localDW->Integrator_PrevResetState_h = (int8_T)rtb_bEnableOpenLoop;
}

/* Model initialize function */
void Controller_initialize(const char_T **rt_errorStatus, RT_MODEL_Controller_T *
  const Controller_M, ZCE_Controller_T *localZCE)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(Controller_M, rt_errorStatus);
  localZCE->Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  localZCE->Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  localZCE->Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  localZCE->Delay_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
