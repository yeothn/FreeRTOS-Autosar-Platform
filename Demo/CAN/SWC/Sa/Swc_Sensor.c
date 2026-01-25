/* =======================================
 * Sensor/Actuator SWC: Swc_Sensor
 * ======================================= */

#include "Rte_Swc_Sensor.h"

void Runnable_Swc_Sensor_Step(void) {

	uint16 distFront;
	uint8 flgObj = 0;
	uint16 vObjRel = 80;
	uint16 vVeh = 100;

	/* virtual algorithm */
	static uint16 distance = 200;

	/* Get the Button state, and send the signal by falling edge */
	uint8 btnState = 0;
	static uint8 preBtnState = 0; // for Edge detection
	static uint8 status = 0;

	Rte_Call_RP_IoHwAb_Get_Button(&btnState);

	if (btnState == 1 && preBtnState == 0) {
		status ^= 1; // Toggle value
	}
	flgObj = status;
	preBtnState = btnState;

	Rte_Call_RP_IoHwAb_Set_Led(flgObj);

	switch (flgObj) {
	case 0:
		distance = 200;
		break;
	case 1:
		if (distance <= 10) {
			vVeh = 80;
		}
		else {
			distance--;
		}
		break;
	}
	distFront = distance;

	Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_distFront(distFront);
	Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_flgObj(flgObj);
	Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vObjRel(vObjRel);
	Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vVeh(vVeh);
}
