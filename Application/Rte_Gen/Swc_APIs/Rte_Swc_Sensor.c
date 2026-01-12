#include "Rte_Core.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/
#include "Rte_Swc_Sensor.h"
#include "Rte_Core.h"
#include "Rte_Data.h"
#include "Os_Cfg.h"
#include "Os_Task.h"

/* Examples */
/* Explicit Implementation */
Std_ReturnType Rte_Write_PP_VehicleSpeed_SpeedVal(uint32 speed) {
	// Rte_Hdl_VehicleSpeed is defined in Rte_Data
	return Rte_Internal_Write(&Rte_Hdl_VehicleSpeed, &speed);
}

Std_ReturnType Rte_Write_PP_EngineState_Status(uint8 status) {
	// Rte_Hdl_EngineState is defined in Rte_Data
	return Rte_Internal_Write(&Rte_Hdl_EngineState, &status);
}

/* Implicit Implementation */
/* Copy the value to the Shadow Buffer*/
static uint32 Shadow_Display_VehicleSpeed = 0; // Shadow Buffer

/* Implicit Write Implementation */
void Rte_IWrite_PP_VehicleSpeed_SpeedVal(uint32 speed) {
	Shadow_Display_VehicleSpeed = speed;
}

/* Lifecycle API: called after the end of Runnable */
void Rte_Runnable_Sensor_End(void) {
	Rte_Internal_Write(&Rte_Hdl_VehicleSpeed, &Shadow_Display_VehicleSpeed);
}

/* Server-Client Communication */
/* Client 2 (Client 1: Swc_Display) */
Std_ReturnType Rte_Call_SwcSensor_RP_Math_Calculate(uint32 input, uint32 *result) {
	/* Lock to prevent other Client(Display) handles the data(shared buffer) */
	GetResource(RES_CSIF_MATH);

	/* --- [Critical Section Start] --- */

	/* Arguments -> Shared Buffer */
	Rte_Buffer_MathJob.input_val = input; // Shared Buffer is defined in Rte_Data
	Rte_Buffer_MathJob.clientID = TASK_ID_SENSOR;

	/* Blocking Call */
	/* Task-Display becomes blocked, Task-Server works */
	Rte_Internal_Call_Blocking(TASK_ID_MATH, RTE_EVT_REQ, RTE_EVT_ACK);

	/* Shared Buffer -> Output */
	*result = Rte_Buffer_MathJob.result_val;

	/* --- [Critical Section End] --- */
	ReleaseResource(RES_CSIF_MATH);

	return RTE_E_OK;
}
