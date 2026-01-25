#ifndef OS_TASK_H
#define OS_TASK_H

#include "main.h"

void Task_Init_Func(void *pvParameters);
void Task_10ms(void *pvParameters);
void Task_50ms(void *pvParameters);
void Task_100ms(void *pvParameters);

#endif /* OS_TASK_H */
