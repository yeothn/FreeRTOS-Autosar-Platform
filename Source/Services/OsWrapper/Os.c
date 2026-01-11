#include "Os.h"
#include "Os_Cfg.h"

#include "FreeRTOS.h"
#include "task.h"

/* ==========================================
 * AUTOSAR OS Standard APIs
 * - Implement Autosar Standard APIs using
 *   FreeRTOS APIs
 * ========================================== */

/* ===============================
 * Internal Functions
 * =============================== */

/* Internal variables */
static Os_TaskHandleType Os_TaskHandles[OS_TASK_COUNT];
extern const Os_TaskConfigType Os_TaskConfig[OS_TASK_COUNT];

static Os_TimerHandleType Os_AlarmHandles[OS_ALARM_COUNT];
static Os_TimerBufferType Os_AlarmBuffers[OS_ALARM_COUNT];
static TickType Os_AlarmCycle[OS_ALARM_COUNT];
extern const Os_AlarmConfigType Os_AlarmConfig[OS_ALARM_COUNT];

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

static void Os_AlarmCallback(Os_TimerHandleType xTimer) {
	/* check the AlarmID*/
	uint32_t AlarmID = (uint32_t)pvTimerGetTimerID(xTimer);

	if (AlarmID >= OS_ALARM_COUNT) {
		return;
	}

	/* execute the designed action */
	const Os_AlarmConfigType *cfg = &Os_AlarmConfig[AlarmID];

	switch (cfg->Action) {
		case ALARM_ACTION_ACTIVATE_TASK:
			ActivateTask(cfg->TaskID);
			break;
		case ALARM_ACTION_SET_EVENT:
			SetEvent(cfg->TaskID, cfg->EventMask);
			break;
		default:
			break;
	}

	/* Re-start the One-shot timer for next period */
	if (Os_AlarmCycle[AlarmID] > 0) {
		xTimerChangePeriod(xTimer, Os_AlarmCycle[AlarmID], 0);
	}
}

/* ===============================
 * OS Execution Standard APIs
 * =============================== */

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

StatusType ActivateTask(TaskType TaskID) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	/* wake up the suspended task */
	vTaskResume(Os_TaskHandles[TaskID]);

	return E_OS_OK;
}

StatusType TerminateTask(void) {
	/* Suspend the current task */
	vTaskSuspend(NULL);

	return E_OS_OK; // placeholder
}

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

StatusType SetEvent(TaskType TaskID, EventMaskType Mask) {
	if (TaskID >= OS_TASK_COUNT) {
		return E_OS_ID;
	}

	if (Os_Port_IsISR() == pdTRUE) { // Interrupt call
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		xTaskNotifyFromISR(Os_TaskHandles[TaskID], Mask, eSetBits, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // demand context-switching
	} else { // Normal call
		xTaskNotify(Os_TaskHandles[TaskID], Mask, eSetBits);
	}
	return E_OS_OK;
}

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

StatusType ClearEvent(EventMaskType Mask) {
	EventMaskType currentEvents; // dummy

	/* Clear the bit of Event (Mask) */
	xTaskNotifyWait(0, Mask, &currentEvents, 0);

	return E_OS_OK;
}

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


/* ===============================
 * Alarm Management Standard APIs
 * =============================== */

StatusType SetRelAlarm(Os_AlarmType AlarmID, TickType Increment, TickType Cycle) {
	if (AlarmID >= OS_ALARM_COUNT) {
		return E_OS_ID;
	}
	if (Increment == 0) {
		return E_OS_VALUE;
	}

	/* Store cycle for the alarm callback */
	Os_AlarmCycle[AlarmID] = Cycle;

	/* Create FreeRTOS Timer if isn't created yet */
	if (Os_AlarmHandles[AlarmID] == NULL) {
		Os_AlarmHandles[AlarmID] = xTimerCreateStatic(
				"OsAlarm", 			// TimerName
				Increment,			// TimerPeriod
				pdFALSE,			// AutoReload (use Single-shot reset instead)
				(void*)AlarmID, 	// TimerID
				Os_AlarmCallback, 	// Callback function
				&Os_AlarmBuffers[AlarmID] // Timer Buffer
				);
	}

	/* Set Timer period and start */
	/* check if the function is called by Interrupt */
	BaseType_t ret;
	if (Os_Port_IsISR() == pdTRUE) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		ret = xTimerChangePeriodFromISR(Os_AlarmHandles[AlarmID], Increment, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // demand context-switching
	} else {
		ret = xTimerChangePeriod(Os_AlarmHandles[AlarmID], Increment, 0);
	}

	if (ret != pdPASS) return E_OS_LIMIT;
	return E_OS_OK;
}

StatusType SetAbsAlarm(Os_AlarmType AlarmID, TickType Start, TickType Cycle) {
	TickType CurrentTick;
	TickType Increment;

	if (AlarmID >= OS_ALARM_COUNT) {
		return E_OS_ID;
	}

	/* Store cycle for the alarm callback */
	Os_AlarmCycle[AlarmID] = Cycle;

	/* Get the current Tick to calculate Increment */
	/* check if the function is called by Interrupt */
	if (Os_Port_IsISR() == pdTRUE) {
		CurrentTick = xTaskGetTickCountFromISR();
	} else {
		CurrentTick = xTaskGetTickCount();
	}
	Increment = Start - CurrentTick;
	if (Increment == 0) Increment = 1;

	/* Create FreeRTOS Timer if isn't created yet */
	if (Os_AlarmHandles[AlarmID] == NULL) {
			Os_AlarmHandles[AlarmID] = xTimerCreateStatic(
					"OsAlarm", 			// TimerName
					Increment,			// TimerPeriod
					pdFALSE,			// AutoReload (use Single-shot reset instead)
					(void*)AlarmID, 	// TimerID
					Os_AlarmCallback, 	// Callback function
					&Os_AlarmBuffers[AlarmID] // Timer Buffer
					);
	}

	/* Set Timer period and start */
	/* check if the function is called by Interrupt */
	BaseType_t ret;
	if (Os_Port_IsISR() == pdTRUE) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		ret = xTimerChangePeriodFromISR(Os_AlarmHandles[AlarmID], Increment, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // demand context-switching
	} else {
		ret = xTimerChangePeriod(Os_AlarmHandles[AlarmID], Increment, 0);
	}

	if (ret != pdPASS) return E_OS_LIMIT;
	return E_OS_OK;
}

StatusType GetAlarm(Os_AlarmType AlarmID, TickType *TickRef) {
	TickType ExpireTime;
	TickType CurrentTick;

	if (AlarmID >= OS_ALARM_COUNT) {
		return E_OS_ID;
	}

	/* Check the Timer Handle validity */
	if (Os_AlarmHandles[AlarmID] == NULL ||
			xTimerIsTimerActive(Os_AlarmHandles[AlarmID]) == pdFALSE) {
		/* Alarm is not active */
		return E_OS_NOFUNC;
	}

	/* Check the timer expire-time and current tick */
	ExpireTime = xTimerGetExpiryTime(Os_AlarmHandles[AlarmID]);
	if (Os_Port_IsISR() == pdTRUE) {
		CurrentTick = xTaskGetTickCountFromISR();
	} else {
		CurrentTick = xTaskGetTickCount();
	}

	/* Calculate the remain time */
	*TickRef = ExpireTime - CurrentTick;

	return E_OS_OK;
}

StatusType CancelAlarm(Os_AlarmType AlarmID) {
	if (AlarmID >= OS_ALARM_COUNT) {
		return E_OS_ID;
	}
	if (Os_AlarmHandles[AlarmID] == NULL) return E_OS_NOFUNC;


	/* Stop the Timer */
	/* check if the function is called by Interrupt */
	BaseType_t ret;
	if (Os_Port_IsISR() == pdTRUE) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		ret = xTimerStopFromISR(Os_AlarmHandles[AlarmID], &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // demand context-switching
	} else {
		ret = xTimerStop(Os_AlarmHandles[AlarmID],0);
	}

	if (ret != pdPASS) return E_OS_LIMIT;

	/* Re-Initialize the cycle of the Alarm */
	Os_AlarmCycle[AlarmID] = 0;

	return E_OS_OK;
}

