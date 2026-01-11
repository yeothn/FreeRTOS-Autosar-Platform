# Phase 2: OS Abstraction Layer Implementation Status

## 1. Type Definitions
- [x] **OsType & Basic Types**: Define Os standard types to align with OSEK specifications.

## 2. Task Management APIs
- [x] **ActivateTask**: Transfer a task from the *Suspended* state to the *Ready* state.
- [x] **TerminateTask**: Move the calling task from the *Running* state to the *Suspended* state.
- [x] **ChainTask**: Terminate the calling task and activate the succeeding task immediately.
- [x] **GetTaskID**: Retrieve the identifier (TaskID) of the currently running task.

## 3. Event Management APIs
- [x] **SetEvent**: Set the events of a given task (mapped to FreeRTOS Task Notification).
- [x] **WaitEvent**: Wait for the state of an event to be set (Blocking behavior).
- [x] **ClearEvent**: Clear the event bits of the calling task.
- [x] **GetEvent**: Return the current event mask of a specific task.

## 4. Kernel Control
- [x] **StartOS**: Initialize internal kernel data structures (task creation) and start the scheduler.
- [x] **ShutdownOS**: Abort the system execution safely in case of fatal errors.

## 5. Alarm & Counter Management
- [x] **SetRelAlarm**: Trigger an alarm after a relative tick count.
- [x] **SetAbsAlarm**: Trigger an alarm when the system counter reaches a specific absolute value.
- [x] **CancelAlarm**: Stop a running alarm.
- [x] **GetAlarm**: Retrieve the number of ticks remaining until the next alarm expiration.

## 6. Resource Management
- [x] **GetResource**: Enter a critical section or acquire a mutex for a shared resource.
- [x] **ReleaseResource**: Exit a critical section or release a mutex.

## 7. System Hooks 
- [x] **ErrorHook**: Callback function invoked when an API returns an error status.
- [x] **StartupHook**: Callback function invoked by `StartOS` before the scheduler starts.
- [x] **ShutdownHook**: Callback function invoked by `ShutdownOS`.

# Phase 3: RTE (Runtime Environment) Implementation Status

## 1. RTE Infrastructure & Static Allocation
- [ ] **Rte_Type.h**: Define AUTOSAR standard types (`Std_ReturnType`, `uint8`, `Rte_DataHandleType`, etc.).
- [ ] **Rte_Factory (Queue)**: Implement wrapper for `xQueueCreateStatic` to create communication channels without dynamic allocation.
- [ ] **Rte_Factory (EventGroup)**: Implement wrapper for `xEventGroupCreateStatic` for Client-Server synchronization.

## 2. Lifecycle Management APIs
- [ ] **Rte_Start**: Initialize RTE internal data structures and communication objects.
- [ ] **Rte_Stop**: Disable RTE communication and cleanup resources (if needed).

## 3. Explicit Communication (Sender-Receiver)
- [ ] **Rte_Write (Unqueued)**: Write data to a global variable or length-1 Queue (Overwrite mode).
- [ ] **Rte_Read (Unqueued)**: Read the most recent data immediately (Peek/Copy).
- [ ] **Rte_Send (Queued)**: Send an event/data to a FIFO Queue.
- [ ] **Rte_Receive (Queued)**: Consume an event/data from a FIFO Queue.

## 4. Implicit Communication (Data Consistency)
- [ ] **Buffer Definitions**: Define Global Buffers (Last Known Value) and Task Local Buffers (Shadow).
- [ ] **Rte_IRead**: Read data from the Task Local Buffer (No OS overhead).
- [ ] **Rte_IWrite**: Write data to the Task Local Buffer.
- [ ] **Rte_PreTaskHook (Copy-In)**: Atomic copy from Global Buffer to Local Buffer at Task start.
- [ ] **Rte_PostTaskHook (Copy-Out)**: Atomic copy from Local Buffer to Global Buffer at Task end.

## 5. Client-Server Communication
- [ ] **Rte_Call (Intra-Partition)**: Direct function call implementation for server runnables in the same task/core.
- [ ] **Rte_Call (Inter-Task)**: Blocking call implementation using EventGroups (Wait for Server completion).
- [ ] **Server_Runnable**: Skeleton code for processing requests and triggering the completion event.