#ifndef OS_H
#define OS_H

#include "Os_Types.h"
#include "Sys_Port.h"

/* ==========================================
 * AUTOSAR OS Standard APIs
 * - Only this header file must be included
 *   by the ASW layer
 * ========================================== */

/* Kernel control APIs */
void StartOS(AppModeType Mode);
void ShutdownOS(StatusType Error);

/* Task control APIs */
StatusType ActivateTask(TaskType TaskID);
StatusType TerminateTask(void);
StatusType ChainTask(TaskType TaskID);
StatusType GetTaskID(TaskRefType TaskIDRef);

/* Event control APIs */
StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
StatusType WaitEvent(EventMaskType Mask);
StatusType ClearEvent(EventMaskType Mask);
StatusType GetEvent(TaskType TaskID, EventMaskType *Event);

/* Alarm control APIs */
StatusType SetRelAlarm(Os_AlarmType AlarmID, TickType Increment, TickType Cycle);
StatusType SetAbsAlarm(Os_AlarmType AlarmID, TickType Start, TickType Cycle);
StatusType GetAlarm(Os_AlarmType AlarmID, TickType *TickRef);
StatusType CancelAlarm(Os_AlarmType AlarmID);

/* Resource control APIs */
StatusType GetResource(ResourceType ResID);
StatusType ReleaseResource(ResourceType ResID);
void SuspendOSInterrupts(void);
void ResumeOSInterrupts(void);

/* Hook function APIs */
void StartupHook(void);
void ShutdownHook(StatusType Error);
void ErrorHook(StatusType Error);

/* ===============================================
 * Porting Hardware-specific functions
 * - Located in Core/Port in each Target folder
 * =============================================== */
//extern BaseType_t Sys_Port_IsISR(void);

#endif /* OS_H */
