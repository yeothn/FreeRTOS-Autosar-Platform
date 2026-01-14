/* ==========================================
 * AUTOSAR OS Queue Extension APIs
 * - Imitate the Autosar RingBuffer for the
 *   Queued Communication using FreeRTOS APIs
 * ========================================== */

#include "Os_Queue.h"

QueueHandle_t Os_QueueCreate(
		uint32 queueLength,
		uint32 itemSize,
		uint8* bufferPtr,
		StaticQueue_t* QCBPtr) {
	return xQueueCreateStatic(queueLength, itemSize, bufferPtr, QCBPtr);
}

StatusType Os_QueueSend(QueueHandle_t queue, const void *itemPtr) {
	BaseType_t ret;

	/* check if the function is called by Interrupt */
	if (Sys_Port_IsISR() == TRUE) { // Interrupt call
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		ret = xQueueSendFromISR(queue, itemPtr, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // request context-switching
	} else {
		ret = xQueueSend(queue, itemPtr, 0);
	}

	if (ret != pdTRUE) {
		return E_OS_NOFUNC;
	}
	return E_OK;
}
StatusType Os_QueueReceive(QueueHandle_t queue, void* buffer) {
	BaseType_t ret;

	/* check if the function is called by Interrupt */
	if (Sys_Port_IsISR() == TRUE) { // Interrupt call
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		ret = xQueueReceiveFromISR(queue, buffer, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken); // request context-switching
	} else {
		ret = xQueueReceive(queue, buffer, 0);
	}

	if (ret != pdTRUE) {
		return E_OS_NOFUNC;
	}
	return E_OK;
}
