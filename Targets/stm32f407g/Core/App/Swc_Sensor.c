/* ===========================
 * SWC Application (Example)
 * ===========================*/

#include "Rte_Swc_Sensor.h"

/* Example */
void Runnable_ReadAndSendSensor(void) {
	uint32 currentSpeed;
	uint8 currentStatus;

	/* Read value from Hardware with BSW function */
	// currentSpeed = HAL_Get_Speed_Sensor(); // Example
	// currentStatus = SomeEngineFunc();
	currentSpeed = 100; // Dummy value
	currentStatus = 1; // Dummy value

	/* Send data with RTE_Write */
	Rte_Write_PP_VehicleSpeed_SpeedVal(currentSpeed);
	Rte_Write_PP_EngineState_Status(currentStatus);
}
