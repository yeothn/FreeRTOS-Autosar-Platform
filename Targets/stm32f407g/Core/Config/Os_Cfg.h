#ifndef OS_CFG_H
#define OS_CFG_H

/* ==========================================
 * Task ID Definition
 * - User configuration
 * ========================================== */

#include "Os_Types.h"

typedef enum {
	TASK_ID_INIT = 0,
	TASK_ID_100ms,
	OS_TASK_COUNT
} Os_TaskType_Enum;

extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];

#endif /* OS_CFG_H */
