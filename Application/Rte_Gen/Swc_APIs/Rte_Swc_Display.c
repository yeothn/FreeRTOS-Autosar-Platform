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
/* Client 1 (Client 2: Swc_Sensor) */
Std_ReturnType Rte_Call_SwcDisplay_RP_Math_Calculate(uint32 input, uint32 *result) {
	/* Lock to prevent other Client(Sensor) handles the data(shared buffer) */
	GetResource(RES_CSIF_MATH);

	/* --- [Critical Section Start] --- */

	/* Arguments -> Shared Buffer */
	Rte_Buffer_MathJob.input_val = input; // Shared Buffer is defined in Rte_Data
	Rte_Buffer_MathJob.clientID = TASK_ID_DISPLAY;

	/* Blocking Call */
	/* Task-Display becomes blocked, Task-Server works */
	Rte_Internal_Call_Blocking(TASK_ID_MATH, RTE_EVT_REQ, RTE_EVT_ACK);

	/* Shared Buffer -> Output */
	*result = Rte_Buffer_MathJob.result_val;

	/* --- [Critical Section End] --- */
	ReleaseResource(RES_CSIF_MATH);

	return RTE_E_OK;
}
