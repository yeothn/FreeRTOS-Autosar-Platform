/* ======================================
 * Sensor/Actuator SWC - Sensor(Example)
 * ====================================== */

#include "Rte_Swc_Sensor.h"

/* Example */
void Runnable_Step_Sensor(void) {
	Rte_Call_RP_IoHwAb_Toggle_Led(); // for checking

	static uint32 rawValue = 0;
	uint32 calculatedSpeed = 0;

	/* Create Raw-Value */
	rawValue += 10;
	if (rawValue > 50) rawValue = 0; // 0, 10, 20, 30, 40, 50, 0, ...

	/* [Client] Call the Math Server for Calculation */
	Rte_Call_RP_Math_Calculate(rawValue, &calculatedSpeed); // Calculate Speed from rawValue
	// 0, 20, 40, 60, 80, 100, 0, ...

	/* Implicit Send the calculated value to the Display*/
	//Rte_Write_PP_VehicleSpeed_SpeedVal(calculatedValue); // Explicit
	Rte_IWrite_PP_VehicleSpeed_SpeedVal(calculatedSpeed); // Implicit

	/* Get the Button state, and send the signal by falling edge */
	uint8 btnState = 0;
	static uint8 preBtnState = 0; // for Edge detection

	Rte_Call_RP_IoHwAb_Get_Button(&btnState);

	if (btnState == 1 && preBtnState == 0) {
		uint32 data = 1;
		void* dtcPayload = &data;
		Rte_Send_PP_DTC_Code(dtcPayload);

	}
	preBtnState = btnState;
}
