#ifndef OS_TYPES_H
#define OS_TYPES_H

/* ===============================================
 * AUTOSAR Standard Types
 * - Define Autosar OS types
 * =============================================== */

#include <stdint.h>
#include "Os_Port.h"

/* Function return type and macros */
typedef uint8_t StatusType;
#define E_OS_OK 	((StatusType)0)
#define E_OS_ID 	((StatusType)1)
#define E_OS_LIMIT 	((StatusType)2)
#define E_OS_NOFUNC ((StatusType)3)

/* Task ID */
typedef uint8_t TaskType;
typedef TaskType* TaskRefType;

/* AppMode for StartOS */
typedef uint8_t AppModeType;
#define OSDEFAULTAPPMODE ((AppModeType)0)

/* Event Type */
typedef uint32_t EventMaskType;

/* Pointer of the task function: void Func(void) */
typedef void (*TaskFuncType)(void);

/* TaskConfig structure */
typedef struct {
	TaskType		TaskID;
	TaskFuncType	TaskFunc;
	const char* 	TaskName;
	uint32_t		Priority;
	uint16_t		StackSize;
	void*			StackBuffer;
	void* 			TaskBuffer;
} Os_TaskConfigType;

#endif /* OS_TYPES_H */
