#include "Rte_Core.h"
#include "Os.h"
#include <string.h> // for memcpy

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

/* Start Lifecycle */
Std_ReturnType Rte_Internal_Start(void) {
	/* placeholder for Init value, copy logic etc. */

	return RTE_E_OK;
}
