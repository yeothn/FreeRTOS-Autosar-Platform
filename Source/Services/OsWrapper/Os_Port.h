#ifndef OS_PORT_H
#define OS_PORT_H

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

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

/* Alarm Handle Type */
typedef TimerHandle_t Os_TimerHandleType;

/* Timer Buffer Type */
typedef StaticTimer_t Os_TimerBufferType;


/* ===============================================
 * Porting Hardware-specific functions
 * - Located in Core/Port in each Target folder
 * =============================================== */
extern BaseType_t Os_Port_IsISR(void);

#endif /* OS_PORT_H */
