#include "Rte.h"
#include "Rte_Data.h"
#include "Rte_Types.h"

#include <string.h> // for memset

/* RTE Status flag for debugging */
static boolean Rte_Initialized = 0;

Std_ReturnType Rte_Start(void) {
	Rte_Initialized = 1;

	/* 1. Initialize Global VFB Variables defined in Rte_Data for S-R Communication */
	if (Rte_Hdl_VehicleSpeed.ValuePtr != NULL) {
		memset(Rte_Hdl_VehicleSpeed.ValuePtr, 0, Rte_Hdl_VehicleSpeed.Size);
	}
	if (Rte_Hdl_EngineState.ValuePtr != NULL) {
		memset(Rte_Hdl_EngineState.ValuePtr, 0, Rte_Hdl_EngineState.Size);
	}

	/* 2. Initialize Shared Buffers defined in Rte_Data for C-S Communication */
	Rte_Buffer_MathJob.clientID = 0;
	Rte_Buffer_MathJob.input_val = 0;
	Rte_Buffer_MathJob.result_val = 0;

	/* 3. Initialize Queue defined in Rte_Data for Queued Communictaion */
	if (Rte_Queue_DTC.Handle == NULL) {
		Rte_Queue_DTC.Handle = Os_QueueCreate(
				Rte_Queue_DTC.Length,
				Rte_Queue_DTC.ItemSize,
				Rte_Queue_DTC.BufferPtr,
				Rte_Queue_DTC.QCBPtr);
	}

	return RTE_E_OK;
}

Std_ReturnType Rte_Stop(void) {
	Rte_Initialized = 0;

	return RTE_E_OK;
}
