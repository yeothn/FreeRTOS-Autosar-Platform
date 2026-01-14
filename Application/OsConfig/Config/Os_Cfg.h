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

/* =====================
 * Task Definition
 * ===================== */

/* Task Set Definition */
typedef enum {
	TASK_ID_INIT = 0,
	TASK_ID_SENSOR,
	TASK_ID_DISPLAY,
	TASK_ID_MATH,
	TASK_ID_CONTROL,
	OS_TASK_COUNT
} Os_TaskID_Enum;

extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];

/* =====================
 * Alarm Definition
 * ===================== */

/* Alarm Set Definition */
typedef enum {
	ALARM_ID_SENSOR = 0,
	ALARM_ID_DISPLAY,
	ALARM_ID_CONTROL,
	OS_ALARM_COUNT
} Os_AlarmID_Enum;

extern const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT];

/* =====================
 * Resource Definition
 * ===================== */

/* Resoucre ID Definition */
typedef enum {
	RESOURCE_SCHEDULER = 0,
	RESOURCE_VEHICLESPEED, // for Rte_Hdl_VehicleSpeed.LockID in Rte_Data
	RESOURCE_ENGINESTATUS, // for Rte_Hdl_EngineState.LockID in Rte_Data
	RES_CSIF_MATH, 		   // for the Client{Sensor, Display}-Server{Math} Communication
	OS_RESOURCE_COUNT
} Os_ResourceID_Enum;

#endif /* OS_CFG_H */
