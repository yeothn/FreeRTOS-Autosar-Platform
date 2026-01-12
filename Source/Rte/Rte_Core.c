#include "Rte_Core.h"
#include "Os.h"
#include <string.h> // for memcpy

/* ================================
 * Internal RTE Engine: Read-Write
 * ================================ */
Std_ReturnType Rte_Internal_Write(const Rte_DataHandleType *handle, const void *data) {
	/* Flow: Lock -> Copy -> Unlock */
	StatusType osStatus;

	/* Safety check */
	if ((handle == NULL) || (handle->ValuePtr == NULL) || (data == NULL)) {
		return RTE_E_INVALID;
	}

	/* Enter the critical section */
	osStatus = GetResource(handle->LockID);
	if (osStatus != E_OS_OK) {
		return RTE_E_LIMIT; // OS Error Mapping
	}

	/* Memory Copy (Generic) */
	memcpy(handle->ValuePtr, data, handle->Size);

	/* Exit the critical section */
	ReleaseResource(handle->LockID);

	return RTE_E_OK;
}

Std_ReturnType Rte_Internal_Read(const Rte_DataHandleType *handle, void *data) {
	/* Flow: Lock -> Copy -> Unlock */
	StatusType osStatus;

	/* Safety check */
	if ((handle == NULL) || (handle->ValuePtr == NULL) || (data == NULL)) {
		return RTE_E_INVALID;
	}

	/* Enter the critical section */
	osStatus = GetResource(handle->LockID);
	if (osStatus != E_OS_OK) {
		return RTE_E_LIMIT; // OS Error Mapping
	}

	/* Memory Copy (Generic) */
	memcpy(data, handle->ValuePtr, handle->Size);

	/* Exit the critical section */
	ReleaseResource(handle->LockID);

	return RTE_E_OK;
}

/* ==================================================
 * Internal RTE Engine: Server-Client Communication
 * ================================================== */
Std_ReturnType Rte_Internal_Call_Blocking(TaskType serverTaskID, EventMaskType reqEvent, EventMaskType ackEvent) {
	/* Wake-up the server (Trigger the Request) */
	SetEvent(serverTaskID, reqEvent);

	/* Wait for the response (Blocking) */
	WaitEvent(ackEvent);

	/* Clear the event for the next request */
	ClearEvent(ackEvent);

	return RTE_E_OK;
}

Std_ReturnType Rte_Internal_Serve_Ack(TaskType clientTaskID, EventMaskType ackEvent) {
	/* Wake-up the Client (Trigger the Acknowledge) */
	SetEvent(clientTaskID, ackEvent);
	return RTE_E_OK;
}

/* Start Lifecycle */
Std_ReturnType Rte_Internal_Start(void) {
	/* placeholder for Init value, copy logic etc. */

	return RTE_E_OK;
}
