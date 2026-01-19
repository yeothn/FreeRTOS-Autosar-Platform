/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.c
 *
 * Code generated for Simulink model 'ACC'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Jan 19 16:27:06 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ACC.h"
#include "Platform_Types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define ACC_IN_CruiseMode              ((uint8)1U)
#define ACC_IN_FollowMode              ((uint8)2U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_ACC_T ACC_ARID_DEF;           /* '<Root>/Chart' */

/* Model step function */
void Runnable_ACC_Step(void)
{
  float32 rtb_Gain1;
  sint32 rtb_DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/distFront'
   */
  rtb_DataTypeConversion = Rte_IRead_Runnable_ACC_Step_R_SensorData_distFront();

  /* Gain: '<Root>/Gain1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  Inport: '<Root>/vVeh'
   */
  rtb_Gain1 = 0.277777791F * (float32)
    Rte_IRead_Runnable_ACC_Step_R_SensorData_vVeh();

  /* Chart: '<Root>/Chart' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/flgObj'
   *  Inport: '<Root>/vObjRel'
   */
  if (ACC_ARID_DEF.is_active_c3_ACC == 0) {
    ACC_ARID_DEF.is_active_c3_ACC = 1U;
    ACC_ARID_DEF.is_c3_ACC = ACC_IN_CruiseMode;
    ACC_ARID_DEF.vDes = 27.7777786F;
  } else if (ACC_ARID_DEF.is_c3_ACC == ACC_IN_CruiseMode) {
    if ((Rte_IRead_Runnable_ACC_Step_R_SensorData_flgObj() != 0) &&
        (rtb_DataTypeConversion < ACC_ARID_DEF.distSafe)) {
      ACC_ARID_DEF.is_c3_ACC = ACC_IN_FollowMode;
    } else {
      ACC_ARID_DEF.vDes = 27.7777786F;
      ACC_ARID_DEF.distSafe = rtb_Gain1 * 1.5F + 5.0F;
    }

    /* case IN_FollowMode: */
  } else if ((rtb_DataTypeConversion > ACC_ARID_DEF.distSafe + 5.0F) ||
             (Rte_IRead_Runnable_ACC_Step_R_SensorData_flgObj() == 0)) {
    ACC_ARID_DEF.is_c3_ACC = ACC_IN_CruiseMode;
    ACC_ARID_DEF.vDes = 27.7777786F;
  } else {
    ACC_ARID_DEF.distSafe = rtb_Gain1 * 1.5F + 5.0F;
    ACC_ARID_DEF.vDes = (0.277777791F * (float32)
                         Rte_IRead_Runnable_ACC_Step_R_SensorData_vObjRel() +
                         rtb_Gain1) + ((float32)rtb_DataTypeConversion -
      ACC_ARID_DEF.distSafe) * 0.5F;
  }

  /* End of Chart: '<Root>/Chart' */

  /* RateLimiter: '<Root>/Rate Limiter' */
  rtb_Gain1 = ACC_ARID_DEF.vDes - ACC_ARID_DEF.PrevY;
  if (rtb_Gain1 > 0.015F) {
    /* Gain: '<Root>/Gain2' */
    ACC_ARID_DEF.PrevY += 0.015F;
  } else if (rtb_Gain1 < -0.03F) {
    /* Gain: '<Root>/Gain2' */
    ACC_ARID_DEF.PrevY -= 0.03F;
  } else {
    /* Gain: '<Root>/Gain2' */
    ACC_ARID_DEF.PrevY = ACC_ARID_DEF.vDes;
  }

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* Outport: '<Root>/vDes' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   *  Gain: '<Root>/Gain2'
   */
  Rte_IWrite_Runnable_ACC_Step_P_DisplayData_vDes((uint16)(3.6F *
    ACC_ARID_DEF.PrevY));
}

/* Model initialize function */
void Runnable_ACC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
