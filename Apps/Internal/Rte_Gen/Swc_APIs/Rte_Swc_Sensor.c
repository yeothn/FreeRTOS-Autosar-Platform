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
Std_ReturnType Rte_Call_SwcSensor_RP_Math_Calculate(uint32 input, uint32 *result) {
	RTE_CALL_BLOCKING_ENGINE(
			RES_CSIF_MATH, 								// Lock Resource
			TASK_ID_SENSOR, 							// Client TaskID
			TASK_ID_MATH, 								// Server TaskID
			Rte_Buffer_MathJob, 						// Shared Data Buffer
			RTE_EVT_REQ, 								// Request Event Mask
			RTE_EVT_ACK, 								// Acknowledge Event Mask
			{Rte_Buffer_MathJob.input_val = input;}, 	// Input Operation
			{*result = Rte_Buffer_MathJob.result_val;}	// Output Operation
		);
	return RTE_E_OK;
}

/* BSW Intra-Partition Call */
void Rte_Call_RP_IoHwAb_Get_Button(uint8 *status) {
	/* Polling Counter */

	static uint32 button_counter = 0;

	uint8 buffer = 0;
	Bsw_IoHwAb_Get_Button(&buffer);
	switch (buffer) {
	case 0:
		button_counter = 0;
		break;
	case 1:
		button_counter++;
		break;
	}

	*status = (button_counter >= 5) ? 1 : 0;
}
