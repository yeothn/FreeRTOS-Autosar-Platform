#include "Os.h"
#include "Os_Task.h"
#include "Os_Cfg.h"


/* Lifecycle Hooks */
extern void Rte_Runnable_Sensor_End(void);
extern void Rte_Runnable_Display_Start(void);

/* Runnables */
extern void Runnable_Step_Sensor(void);
extern void Runnable_Step_Display(void);

extern void Rte_Server_Math_MainFunction(void);

void Task_Init_Func(void) {
    SetRelAlarm(ALARM_ID_SENSOR, 500, 500);
    SetRelAlarm(ALARM_ID_DISPLAY, 1000, 1000);
    TerminateTask();
}

void Task_Sensor(void *pvParameters) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_WAKEUP);
		GetEvent(TASK_ID_SENSOR, &currentEvt);

		if (currentEvt & EVT_WAKEUP) {
			LED_Toggle2();
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
			LED_Toggle3();
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

/* Example BSW Function for Testing (for Swc_Display.c) */
/* Actually, this function must be located in Core/Bsw due to the HW-dependancy */
void LED_Toggle1(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
}

void LED_Toggle2(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
}

void LED_Toggle3(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}

void LED_Toggle4(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}

void LED_On(void) {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
}

void LED_Off(void) {
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
}
