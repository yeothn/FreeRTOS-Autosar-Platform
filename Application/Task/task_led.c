#include "Os.h"
#include "task_led.h"
#include "Os_Cfg.h"

#define EVT_BLINK   ((EventMaskType)0x01)

extern void Runnable_ReadAndSendSensor(void);
extern void Runnable_UpdateDisplay(void);

void Task_Init_Func(void) {
    SetRelAlarm(ALARM_ID_500ms, 500, 500);
    TerminateTask();
}

void Task_500ms(void) {
	EventMaskType currentEvt;

	while(1) {
		WaitEvent(EVT_BLINK);
		GetEvent(TASK_ID_500ms, &currentEvt);

		if (currentEvt & EVT_BLINK) {
			/* Execute Sensor Runnable */
			Runnable_ReadAndSendSensor();

			/* Execute Display Runnable */
			Runnable_UpdateDisplay();
		}
		ClearEvent(EVT_BLINK);
	}
}

/* Example BSW Function for Testing (for Swc_Display.c) */
void LED_Toggle(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}
