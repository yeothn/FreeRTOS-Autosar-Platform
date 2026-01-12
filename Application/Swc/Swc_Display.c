/* ===========================
 * SWC Application (Example)
 * ===========================*/

#include "Rte_Swc_Display.h"

/* Example BSW functions */
extern void LED_On(void);
extern void LED_Off(void);

/* Example */
void Runnable_Step_Display(void) {
	uint32 receivedSpeed = 0;
	uint32 displayedValue = 0;

	/* Implicit Receive the speed value from sensor */
	// status = Rte_Read_RP_VehicleSpeed_SpeedVal(&receivedSpeed); // Explicit
	receivedSpeed = Rte_IRead_RP_VehicleSpeed_SpeedVal(); // Implicit

	/* [Client] Call the Math Server for Calculation */
	Rte_Call_RP_Math_Calculate(receivedSpeed, &displayedValue);
	// 0, 40, 60, 120, 160, 200, 0, ...

	if (displayedValue > 100) {
		LED_On();
	} else {
		LED_Off();
	}
}
