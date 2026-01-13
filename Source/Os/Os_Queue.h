#ifndef OS_QUEUE_H
#define OS_QUEUE_H

#include "Std_Types.h"
#include "Os_Types.h"
#include "Sys_Port.h"
#include "Queue.h"

/* ==========================================
 * AUTOSAR OS Queue Extension APIs
 * - Imitate the Autosar RingBuffer for the
 *   Queued Communication using FreeRTOS APIs
 * ========================================== */

QueueHandle_t Os_QueueCreate(
		uint32 queueLength,
		uint32 itemSize,
		uint8* bufferPtr,
		StaticQueue_t* QCBPtr);

StatusType Os_QueueSend(QueueHandle_t queue, const void *item);
StatusType Os_QueueReceive(QueueHandle_t queue, void* buffer);

#endif /* OS_QUEUE_H */
