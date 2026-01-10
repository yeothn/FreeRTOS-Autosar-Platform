/*
 * task_led.c
 *
 *  Created on: 2026. 1. 10.
 *      Author: yeoth
 */
#include "task_led.h"

#define TASK_STACK_SIZE_LED 128

static StackType_t xStack_task_led1[TASK_STACK_SIZE_LED];
static StaticTask_t TCB_led1;

static StackType_t xStack_task_led2[TASK_STACK_SIZE_LED];
static StaticTask_t TCB_led2;

void task_led1(void* pvParameters) {
	(void) pvParameters;

	TickType_t xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	const TickType_t wait_tick = pdMS_TO_TICKS(100); // 100ms interval

	while(1) {
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12); // Toggle GPIO_12 (Green LED)
		vTaskDelayUntil(&xLastWakeTime, wait_tick); // Wait for 100ms after last delay
	}
}

void task_led2(void* pvParameters) {
	(void) pvParameters;

	TickType_t xLastWakeTime;

	xLastWakeTime = xTaskGetTickCount();

	const TickType_t wait_tick = pdMS_TO_TICKS(500); // 500ms interval

	while(1) {
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15); // Toggle GPIO_15 (Blue LED)
		vTaskDelayUntil(&xLastWakeTime, wait_tick); // Wait for 100ms after last delay
	}
}

void Init_App_Task(void) {
	xTaskCreateStatic(task_led1, "Task_led1", TASK_STACK_SIZE_LED, NULL, 2, xStack_task_led1, &TCB_led1);
	xTaskCreateStatic(task_led2, "Task_led2", TASK_STACK_SIZE_LED, NULL, 2, xStack_task_led2, &TCB_led2);
}
