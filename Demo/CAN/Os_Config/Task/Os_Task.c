#include "Os.h"
#include "Os_Task.h"
#include "Os_Cfg.h"

#include "Rte_Swc_Sensor.h"
#include "Rte_ACC.h"
#include "Rte_Swc_Display.h"

/* Runnables */
//extern void Runnable_ACC_Init(void);
//extern void Runnable_ACC_Step(void);
//extern void Runnable_Swc_Display_Step(void);
//extern void Runnable_Swc_Sensor_Step(void);

void Task_Init_Func(void *pvParameters) {
    SetRelAlarm(ALARM_ID_10ms, 10, 10);
    SetRelAlarm(ALARM_ID_50ms, 50, 50);
    SetRelAlarm(ALARM_ID_100ms, 100, 100);
    TerminateTask();
}


void Task_10ms(void *pvParameters) {
	EventMaskType currentEvt;
	Runnable_ACC_Init();

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_10ms, &currentEvt);

		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/*----- Start Task Body -----*/
			Rte_ACC_CopyInput();

			Runnable_ACC_Step();

			Rte_ACC_CopyOutput();
		}
	}
}

void Task_50ms(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_50ms, &currentEvt);

		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/*----- Start Task Body -----*/
			Runnable_Swc_Sensor_Step();

			Rte_Swc_Sensor_CopyOutput();
		}
	}
}

void Task_100ms(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_100ms, &currentEvt);
		if (currentEvt & EVT_WAKEUP) {
			ClearEvent(EVT_WAKEUP);

			/*----- Start Task Body -----*/
			Rte_Swc_Display_CopyInput();

			Runnable_Swc_Display_Step();
		}
	}
}
