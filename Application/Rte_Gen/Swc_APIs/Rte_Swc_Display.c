#include "Rte_Core.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/
#include "Rte_Swc_Display.h"
#include "Rte_Core.h"
#include "Rte_Data.h"
#include "Os_Cfg.h"
#include "Os_Task.h"

/* Examples */
/* Explicit Implementation */
Std_ReturnType Rte_Read_RP_VehicleSpeed_SpeedVal(uint32 *speed) {
	// Rte_Hdl_VehicleSpeed is defined in Rte_Data
	return Rte_Internal_Read(&Rte_Hdl_VehicleSpeed, speed);
}

/* Implicit Implementation */
/* Copy the value to the Shadow Buffer*/
static uint32 Shadow_Display_VehicleSpeed = 0; // Shadow Buffer

/* Lifecycle API: called before the start of Runnable */
void Rte_Runnable_Display_Start(void) {
	Rte_Internal_Read(&Rte_Hdl_VehicleSpeed, &Shadow_Display_VehicleSpeed);
}

/* Implicit Read Implementation */
uint32 Rte_IRead_RP_VehicleSpeed_SpeedVal(void) {
	return Shadow_Display_VehicleSpeed;
}

/* Server-Client Communication */
Std_ReturnType Rte_Call_SwcDisplay_RP_Math_Calculate(uint32 input, uint32 *result) {
	RTE_CALL_BLOCKING_ENGINE(
			RES_CSIF_MATH, 								// Lock Resource
			TASK_ID_DISPLAY, 							// Client TaskID
			TASK_ID_MATH, 								// Server TaskID
			Rte_Buffer_MathJob, 						// Shared Data Buffer
			RTE_EVT_REQ, 								// Request Event Mask
			RTE_EVT_ACK, 								// Acknowledge Event Mask
			{Rte_Buffer_MathJob.input_val = input;}, 	// Input Operation
			{*result = Rte_Buffer_MathJob.result_val;}	// Output Operation
		);

	return RTE_E_OK;
}
