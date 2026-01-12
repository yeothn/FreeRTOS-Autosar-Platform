#ifndef OS_TASK_H
#define OS_TASK_H

#include "main.h"

#define EVT_WAKEUP  ((EventMaskType)0x01)
#define RTE_EVT_REQ ((EventMaskType)0x02)
#define RTE_EVT_ACK ((EventMaskType)0x04)

void Task_Sensor(void *pvParameters);
void Task_Display(void *pvParameters);
void Task_Math(void *pvParameters);

void LED_Toggle1(void);
void LED_Toggle2(void);
void LED_Toggle3(void);
void LED_Toggle4(void);
void LED_On(void);
void LED_Off(void);

#endif /* OS_TASK_H */
