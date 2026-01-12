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

