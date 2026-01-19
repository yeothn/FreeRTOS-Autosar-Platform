#ifndef RTE_SWC_MATH_H
#define RTE_SWC_MATH_H

#include "Rte_Types.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/

/* Actual Math logic (Runnable) from ASW Layer (Swc_Math) */
extern void Runnable_Math_Multiply(uint32 input, uint32 *output);

/* Server Dispatcher */
void Rte_Server_Math_MainFunction(void);

#endif /* RTE_SWC_MATH_H */
