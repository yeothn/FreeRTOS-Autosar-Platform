# Phase 2: OS Abstraction Layer Implementation Status

## 1. Type Definitions (Os_Types.h)
- [ ] **OsType & Basic Types**: Define standard types (`StatusType`, `TaskType`, `EventMaskType`, `AppModeType`) to align with OSEK specifications.

## 2. Task Management APIs (Os.c)
- [ ] **ActivateTask**: Transfer a task from the *Suspended* state to the *Ready* state.
- [ ] **TerminateTask**: Move the calling task from the *Running* state to the *Suspended* state.
- [ ] **ChainTask**: Terminate the calling task and activate the succeeding task immediately.
- [ ] **GetTaskID**: Retrieve the identifier (TaskID) of the currently running task.

## 3. Event Management APIs (Os.c)
- [ ] **SetEvent**: Set the events of a given task (mapped to FreeRTOS Task Notification).
- [ ] **WaitEvent**: Wait for the state of an event to be set (Blocking behavior).
- [ ] **ClearEvent**: Clear the event bits of the calling task.
- [ ] **GetEvent**: Return the current event mask of a specific task.

## 4. Kernel Control (Os.c)
- [ ] **StartOS**: Initialize internal kernel data structures (task creation) and start the scheduler.
