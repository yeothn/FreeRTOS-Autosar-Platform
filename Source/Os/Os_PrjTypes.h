#ifndef OS_PRJTYPES_H
#define OS_PRJTYPES_H

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "event_groups.h"

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

/* Task Function Handle Type */
typedef TaskFunction_t Os_TaskFunctionHandleType;

/* Alarm Handle Type */
typedef TimerHandle_t Os_TimerHandleType;

/* Timer Buffer Type */
typedef StaticTimer_t Os_TimerBufferType;

/* Resource Handle Type */
typedef SemaphoreHandle_t Os_ResourceHandleType;

/* Resource Buffer Type */
typedef StaticSemaphore_t Os_ResourceBufferType;

/* Event Handle Type */
typedef EventGroupHandle_t Os_EventHandleType;

/* Event Buffer Type */
typedef StaticEventGroup_t Os_EventBufferType;



#endif /* OS_PRJTYPES_H */
