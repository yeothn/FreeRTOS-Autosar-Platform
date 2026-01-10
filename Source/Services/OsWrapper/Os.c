#include "Os.h"
#include "Os_Cfg.h"

#include "FreeRTOS.h"
#include "task.h"

/* ==========================================
 * AUTOSAR OS Standard APIs
 * - Implement Autosar Standard APIs using
 *   FreeRTOS APIs
 * ========================================== */

static Os_TaskHandleType Os_TaskHandles[OS_TASK_COUNT];
extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];

/* Initialize and Task creation */
static void Os_KernelInit(void) {
	for (int i = 0; i < OS_TASK_COUNT; i++) {
		Os_TaskHandles[i] = xTaskCreateStatic(
				Os_TaskConfig[i].TaskFunc,	// Function handle
				Os_TaskConfig[i].TaskName, 	// Task Name
				Os_TaskConfig[i].StackSize, // Task Stack Size
				NULL, 						// Parameter
				Os_TaskConfig[i].Priority,  // Task Priority
				(Os_StackType*) Os_TaskConfig[i].StackBuffer,
				(Os_TCBType*) Os_TaskConfig[i].TaskBuffer
				);
		configASSERT(Os_TaskHandles[i]);

		/* Tasks except Init-Task must be explicitly activated */
		if (Os_TaskConfig[i].TaskID != TASK_ID_INIT) {
			vTaskSuspend(Os_TaskHandles[i]);
		}
	}
}

/* ===============================
 * OS Execution Standard APIs
 * =============================== */

/* [Standard API] StartOS */
void StartOS(AppModeType Mode) {
	(void)Mode; // Not used

	/* Task creation */
	Os_KernelInit();

	/* Start Tasks */
	vTaskStartScheduler();
}


/* ===============================
 * Task Management Standard APIs
 * =============================== */

/* [Standard API] ActivateTask */
StatusType ActivateTask(TaskType TaskID) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	/* wake up the suspended task */
	vTaskResume(Os_TaskHandles[TaskID]);

	return E_OS_OK;
}

/* [Standard API] TerminateTask */
StatusType TerminateTask(void) {
	/* Suspend the current task */
	vTaskSuspend(NULL);

	return E_OS_OK; // placeholder
}

/* [Standard API] ChainTask */
StatusType ChainTask(TaskType TaskID) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	/* Activate the next Task */
	vTaskResume(Os_TaskHandles[TaskID]);

	/* Suspend the current task */
	vTaskSuspend(NULL);

	return E_OS_OK; // placeholder
}

/* [Standard API] GetTaskID */
StatusType GetTaskID(TaskRefType TaskIDRef) {
	Os_TaskHandleType currentHandle = xTaskGetCurrentTaskHandle();

	/* compare task handles to find the TaskID */
	for (int i = 0; i < OS_TASK_COUNT; i++) {
		if (Os_TaskHandles[i] == currentHandle) {
			*TaskIDRef = (TaskType)i;
			return E_OS_OK;
		}
	}
	return E_OS_ID; // Error: Task not found
}

/* ===============================
 * Event Management Standard APIs
 * =============================== */

/* [Standard API] SetEvent */
StatusType SetEvent(TaskType TaskID, EventMaskType Mask) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	if (Os_Port_IsISR() == pdTRUE) { // Interrupt call
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xTaskNotifyFromISR(Os_TaskHandles[TaskID], Mask, eSetBits, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	} else { // Normal call
		xTaskNotify(Os_TaskHandles[TaskID], Mask, eSetBits);
	}
	return E_OS_OK;
}

/* [Standard API] WaitEvent */
StatusType WaitEvent(EventMaskType Mask) {
	EventMaskType currentEvents;

	/* wait until the desired event arrives */
	while (1) {
		/* Check the current event state */
		xTaskNotifyWait(0, 0, &currentEvents, 0);

		/* compare the event(=Mask) */
		if ((currentEvents & Mask) != 0) {
			return E_OS_OK;
		}

		/* Block until SetEvent with the desired event */
		xTaskNotifyWait(0, 0, &currentEvents, portMAX_DELAY);
	}
}

/* [Standard API] ClearEvent */
StatusType ClearEvent(EventMaskType Mask) {
	EventMaskType currentEvents; // dummy

	/* Clear the bit of Event (Mask) */
	xTaskNotifyWait(0, Mask, &currentEvents, 0);

	return E_OS_OK;
}

/* [Standard API] GetEvent */
StatusType GetEvent(TaskType TaskID, EventMaskType *Event) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	/* clear no bit to return the current value */
	uint32_t currentValue;
	currentValue = ulTaskNotifyValueClear(Os_TaskHandles[TaskID], 0);

	*Event = (EventMaskType)currentValue;

	return E_OS_OK;
}

