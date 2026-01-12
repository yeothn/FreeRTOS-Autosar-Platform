#include "Rte_Core.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/
#include "Rte_Swc_Sensor.h"
#include "Rte_Data.h"

/* Examples */
Std_ReturnType Rte_Write_PP_VehicleSpeed_SpeedVal(uint32 speed) {
	// Rte_Hdl_VehicleSpeed is defined in Rte_Data
	return Rte_Internal_Write(&Rte_Hdl_VehicleSpeed, &speed);
}

Std_ReturnType Rte_Write_PP_EngineState_Status(uint8 status) {
	// Rte_Hdl_EngineState is defined in Rte_Data
	return Rte_Internal_Write(&Rte_Hdl_EngineState, &status);
}
