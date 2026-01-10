#ifndef OS_PORT_H
#define OS_PORT_H

#include "FreeRTOS.h"
#include "task.h"

/* ===============================================
 * Project-specific Type definition
 * - Re-define FreeRTOS Types as Project-specific
 *   OS Types (Not Autosar Standard)
 * =============================================== */

/* Stack Type */
typedef StackType_t  Os_StackType;

/* Task Control Block Type */
typedef StaticTask_t Os_TCBType;

/* Task Handle Type */
typedef TaskHandle_t Os_TaskHandleType;


/* ===============================================
 * Porting Hardware-specific functions
 * - Located in Core/Port in each Target folder
 * =============================================== */
extern BaseType_t Os_Port_IsISR(void);

#endif /* OS_PORT_H */
