/* =======================================
 * Sensor/Actuator SWC: Swc_Display
 * ======================================= */

#include "Rte_Swc_Display.h"

void Runnable_Swc_Display_Step(void) {
	uint16 vDes = Rte_IRead_Runnable_Swc_Display_Step_R_AccData_vDes();

	/* virtual algorithm */
	if (vDes > 119) {
		Rte_Call_RP_IoHwAb_Set_Led1(0);
		Rte_Call_RP_IoHwAb_Set_Led2(1);
	}
	else if (vDes <= 100){
		Rte_Call_RP_IoHwAb_Set_Led1(1);
		Rte_Call_RP_IoHwAb_Set_Led2(0);
	}
	else {
		Rte_Call_RP_IoHwAb_Set_Led1(0);
		Rte_Call_RP_IoHwAb_Set_Led2(0);
	}
}
