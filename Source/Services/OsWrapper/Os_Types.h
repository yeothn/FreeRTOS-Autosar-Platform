#ifndef OS_TYPES_H
#define OS_TYPES_H

/* ===============================================
 * AUTOSAR Standard Types
 * - Define Autosar OS types
 * =============================================== */

#include <stdint.h>
#include "Os_Port.h"

/* Function return type and macros */
typedef enum {
	E_OS_OK,
	E_OS_ID,
	E_OS_LIMIT,
	E_OS_RESOURCE,
	E_OS_CALLLEVEL,
	E_OS_NOFUNC,
	E_OS_VALUE,
	E_OS_ACCESS
} StatusType;

/* AppMode for StartOS */
typedef uint8_t AppModeType;
#define OSDEFAULTAPPMODE ((AppModeType)0)

/* Task */
typedef uint8_t TaskType;
typedef TaskType* TaskRefType;
typedef void (*TaskFuncType)(void); // Pointer of the task function: void Func(void)
typedef struct { // TaskConfig structure
	TaskType		TaskID;
	TaskFuncType	TaskFunc;
	const char* 	TaskName;
	uint32_t		Priority;
	uint16_t		StackSize;
	void*			StackBuffer;
	void* 			TaskBuffer;
	uint8_t			AutoStart;
} Os_TaskConfigType;

/* Event Type */
typedef uint32_t EventMaskType;

/* Alarm Type */
typedef uint32_t TickType;
typedef uint32_t Os_AlarmType; // Alarm ID
typedef enum {
	ALARM_ACTION_ACTIVATE_TASK,
	ALARM_ACTION_SET_EVENT
} Os_AlarmActionType;
typedef struct { // AlarmConfig structure
	Os_AlarmType 		AlarmID;
	Os_AlarmActionType 	Action;
	TaskType 			TaskID;
	EventMaskType 		EventMask;
} Os_AlarmConfigType;

/* Resource Type */
typedef uint32_t ResourceType;

#endif /* OS_TYPES_H */
