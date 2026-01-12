#include "Rte_Core.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/
#include "Rte_Swc_Display.h"
#include "Rte_Data.h"

/* Examples */
Std_ReturnType Rte_Read_RP_VehicleSpeed_SpeedVal(uint32 *speed) {
	// Rte_Hdl_VehicleSpeed is defined in Rte_Data
	return Rte_Internal_Read(&Rte_Hdl_VehicleSpeed, speed);
}
