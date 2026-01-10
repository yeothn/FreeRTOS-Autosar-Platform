#ifndef OS_H
#define OS_H

#include "Os_Types.h"

/* ==========================================
 * AUTOSAR OS Standard APIs
 * - Only this header file must be included
 *   by the ASW layer
 * ========================================== */

/* Kernal control */
void StartOS(AppModeType Mode);

/* Task control */
StatusType ActivateTask(TaskType TaskID);
StatusType TerminateTask(void);
StatusType ChainTask(TaskType TaskID);
StatusType GetTaskID(TaskRefType TaskIDRef);

/* Event control */
StatusType SetEvent(TaskType TaskID, EventMaskType Mask);
StatusType WaitEvent(EventMaskType Mask);
StatusType ClearEvent(EventMaskType Mask);
StatusType GetEvent(TaskType TaskID, EventMaskType *Event);

#endif /* OS_H */
