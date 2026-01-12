#ifndef OS_CFG_H
#define OS_CFG_H

/* ==========================================
 * Task ID Definition
 * - User configuration
 * ========================================== */

#include "Os_Types.h"

/* Task Set Definition */
typedef enum {
	TASK_ID_INIT = 0,
	TASK_ID_500ms,
	OS_TASK_COUNT
} Os_TaskID_Enum;

extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];


/* Alarm Set Definition */
typedef enum {
	ALARM_ID_500ms = 0,
	OS_ALARM_COUNT
} Os_AlarmID_Enum;

extern const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT];

/* Resoucre ID Definition */
typedef enum {
	RESOURCE_SCHEDULER = 0,
	RESOURCE_VEHICLESPEED,
	RESOURCE_ENGINESTATUS,
	OS_RESOURCE_COUNT
} Os_ResourceID_Enum;

#endif /* OS_CFG_H */
