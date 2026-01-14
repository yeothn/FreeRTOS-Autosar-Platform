#ifndef OS_TASK_H
#define OS_TASK_H

#include "main.h"

#define EVT_WAKEUP  ((EventMaskType)0x01)
#define RTE_EVT_REQ ((EventMaskType)0x02)
#define RTE_EVT_ACK ((EventMaskType)0x04)

void Task_Init_Func(void *pvParameters);
void Task_Sensor(void *pvParameters);
void Task_Display(void *pvParameters);
void Task_Math(void *pvParameters);
void Task_Control(void *pvParameters);

#endif /* OS_TASK_H */
