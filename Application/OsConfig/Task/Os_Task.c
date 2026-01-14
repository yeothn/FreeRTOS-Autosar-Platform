#include "Os.h"
#include "Os_Task.h"
#include "Os_Cfg.h"


/* Lifecycle Hooks */
extern void Rte_Runnable_Sensor_End(void);
extern void Rte_Runnable_Display_Start(void);

/* Runnables */
extern void Runnable_Step_Sensor(void);
extern void Runnable_Step_Display(void);
extern void Runnable_Step_Control(void);

extern void Rte_Server_Math_MainFunction(void);

void Task_Init_Func(void *pvParameters) {
    SetRelAlarm(ALARM_ID_SENSOR, 100, 100);
    SetRelAlarm(ALARM_ID_CONTROL, 500, 500);
    SetRelAlarm(ALARM_ID_DISPLAY, 500, 500);
    TerminateTask();
}

void Task_Sensor(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_SENSOR, &currentEvt);

		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/* Execute Sensor Runnable */
			Runnable_Step_Sensor();
			Rte_Runnable_Sensor_End(); // For Implicit Communication: Shadow->Global (copy)
		}
	}
}

void Task_Display(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_DISPLAY, &currentEvt);

		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/* Execute Display Runnable */
			Rte_Runnable_Display_Start(); // For Implicit Communication: Global->Shadow (copy)
			Runnable_Step_Display();
		}
	}
}


void Task_Math(void *pvParameters) {

	while(1) {
		/* Wait for the Request */
		WaitEvent(RTE_EVT_REQ);

		/* If activated, call the RTE Dispatcher */
		Rte_Server_Math_MainFunction();
	}
}

void Task_Control(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_CONTROL, &currentEvt);
		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/* Execute Control Runnable */
			Runnable_Step_Control();
		}
	}
}
