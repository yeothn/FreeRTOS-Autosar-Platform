#include "Os.h"

/* =============================
 * Define the Application data
 * =============================*/
#include "Rte_Data.h"

/* Examples */
static uint32 VFB_Buffer_VehicleSpeed = 0U; // Init. Value: 0
static uint8 VFB_Buffer_EngineState = 0U; // Init. Value: 0

const Rte_DataHandleType Rte_Hdl_VehicleSpeed = {
	.ValuePtr = (void*)&VFB_Buffer_VehicleSpeed,
	.Size = sizeof(uint32),
	.LockID = RESOURCE_VEHICLESPEED // Defined in Os_Cfg.h
};

const Rte_DataHandleType Rte_Hdl_EngineState = {
	.ValuePtr = (void*)&VFB_Buffer_EngineState,
	.Size = sizeof(uint8),
	.LockID = RESOURCE_ENGINESTATUS // Defined in Os_Cfg.h
};

/* Shared-Buffer instance */
/* volatile because multiple tasks can change the value */
volatile Rte_Csif_Math_Type Rte_Buffer_MathJob = {0}; // initialize with 0s

/* Queue Config Struct for Queued communication */
static Rte_QCBType Rte_QCB_DTC; // Queue Control Block
static uint8 Rte_Queue_DTC_Data[5*sizeof(uint32)]; // Storage Area
Rte_QueueConfigType Rte_Queue_DTC = {
		.Handle = NULL,
		.QCBPtr = &Rte_QCB_DTC,
		.BufferPtr = Rte_Queue_DTC_Data,
		.Length = 5,
		.ItemSize = sizeof(uint32)
};

