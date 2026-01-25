/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ACC.h
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

#ifndef ACC_h_
#define ACC_h_
#ifndef ACC_COMMON_INCLUDES_
#define ACC_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ACC.h"
#endif                                 /* ACC_COMMON_INCLUDES_ */

#include "ACC_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  float32 vDes;                        /* '<Root>/Chart' */
  float32 PrevY;                       /* '<Root>/Rate Limiter' */
  float32 distSafe;                    /* '<Root>/Chart' */
  uint8 is_active_c3_ACC;              /* '<Root>/Chart' */
  uint8 is_c3_ACC;                     /* '<Root>/Chart' */
} ARID_DEF_ACC_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ACC_T ACC_ARID_DEF;    /* '<Root>/Chart' */

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
 * '<Root>' : 'ACC'
 * '<S1>'   : 'ACC/Chart'
 */
#endif                                 /* ACC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
