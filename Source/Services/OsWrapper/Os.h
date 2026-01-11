#ifndef OS_H
#define OS_H

#include "Os_Types.h"

/* ==========================================
 * AUTOSAR OS Standard APIs
 * - Only this header file must be included
 *   by the ASW layer
 * ========================================== */

/* Kernel control APIs */
void StartOS(AppModeType Mode);

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


#endif /* OS_H */
