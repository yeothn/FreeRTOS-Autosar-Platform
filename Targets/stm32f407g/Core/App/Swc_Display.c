/* ===========================
 * SWC Application (Example)
 * ===========================*/

#include "Rte_Swc_Display.h"

extern void LED_Toggle(void); // Example BSW function

/* Example */
void Runnable_UpdateDisplay(void) {
	uint32 displaySpeed = 0;
	Std_ReturnType status;

	/* Read the data from RTE */
	status = Rte_Read_RP_VehicleSpeed_SpeedVal(&displaySpeed);
	if (status == RTE_E_OK) {
		// Display the value with BSW function
		// Lcd_Print_Number(displaySpeed); // Example
		if (displaySpeed > 80) {
			LED_Toggle();
		}
	} else {
		// Error Handling
	}
}
