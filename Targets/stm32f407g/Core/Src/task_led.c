#include "Os.h"
#include "task_led.h"
#include "Os_Cfg.h"

#define EVT_BLINK   ((EventMaskType)0x01)

void Task_Init_Func(void) {
    SetRelAlarm(ALARM_ID_100ms, 1000, 1000);
    TerminateTask();
}

void Task_100ms_Func(void) {
    EventMaskType currentEvt;

    while(1) {
        WaitEvent(EVT_BLINK);
        GetEvent(TASK_ID_100ms, &currentEvt);

        if (currentEvt & EVT_BLINK) {
        	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        	ClearEvent(EVT_BLINK);
        }
    }
}
