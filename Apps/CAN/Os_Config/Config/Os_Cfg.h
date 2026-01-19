#ifndef OS_CFG_H
#define OS_CFG_H

#include "Os_Types.h"

/* ========================
 * Priority Definitions
 * ======================== */
#define OS_PRIORITY_IDLE        0
#define OS_PRIORITY_LOWEST      1
#define OS_PRIORITY_MEDIUM      2
#define OS_PRIORITY_HIGH        3
#define OS_PRIORITY_REALTIME    4

/* ========================
 * Event Definitions
 * ======================== */
#define EVT_WAKEUP  ((EventMaskType)0x01)
#define RTE_EVT_REQ ((EventMaskType)0x02)
#define RTE_EVT_ACK ((EventMaskType)0x04)

/* =====================
 * Task Definition
 * ===================== */

/* Task Set Definition */
typedef enum {
	TASK_ID_INIT = 0,
	TASK_ID_10ms,
	TASK_ID_50ms,
	TASK_ID_100ms,
	OS_TASK_COUNT
} Os_TaskID_Enum;

extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];

/* =====================
 * Alarm Definition
 * ===================== */

/* Alarm Set Definition */
typedef enum {
	ALARM_ID_10ms = 0,
	ALARM_ID_50ms,
	ALARM_ID_100ms,
	OS_ALARM_COUNT
} Os_AlarmID_Enum;

extern const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT];

/* =====================
 * Resource Definition
 * ===================== */

/* Resoucre ID Definition */
typedef enum {
	/* ACC Resources */
	RESOURCE_ACC_DISTFRONT,
	RESOURCE_ACC_FLGOBJ,
	RESOURCE_ACC_VOBJREL,
	RESOURCE_ACC_VVEH,
	OS_RESOURCE_COUNT
} Os_ResourceID_Enum;

#endif /* OS_CFG_H */
