#include "Rte_Core.h"

/* ==================================================
 * RTE APIs for SWC: Swc_Sensor
 * - Manual implementation of RTE Code
 * ==================================================*/
#include "Rte_Swc_Sensor.h"
#include "Rte_Core.h"
#include "Os_Cfg.h"
#include "Os_Task.h"
#include "Bsw_Com.h"
#include "Com_Cfg.h"

/* Outport Buffer for Implicit communication */
static uint16 VFB_Swc_Sensor_distFront = 0;
static uint8 VFB_Swc_Sensor_flgObj = 0;
static uint16 VFB_Swc_Sensor_vObjRel = 0;
static uint16 VFB_Swc_Sensor_vVeh = 0;

/* Implicit Write Implementation for Swc_Sensor */
void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_distFront(uint16 u) {
	VFB_Swc_Sensor_distFront = u;
}

void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_flgObj(uint8 u) {
	VFB_Swc_Sensor_flgObj = u;
}

void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vObjRel(uint16 u) {
	VFB_Swc_Sensor_vObjRel = u;
}

void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vVeh(uint16 u) {
	VFB_Swc_Sensor_vVeh = u;
}

void Rte_Swc_Sensor_CopyOutput(void) {
	Pdu_ACCDataType txData = {0,};

	/* Update txData */
	txData.distFront = VFB_Swc_Sensor_distFront;
	txData.flgObj = VFB_Swc_Sensor_flgObj;
	txData.vObjRel = VFB_Swc_Sensor_vObjRel;
	txData.vVeh = VFB_Swc_Sensor_vVeh;

	/* Send the txData (CAN_ID: PDU_ID_SENSOR_TX) */
	Bsw_Com_SendMsg(PDU_ID_SENSOR_TX, (uint8*)&txData, sizeof(Pdu_ACCDataType));
}


/* BSW Intra-Partition Call */
void Rte_Call_RP_IoHwAb_Get_Button(uint8 *status) {
	/* Polling Counter */

	static uint8 button_counter = 0;
	const uint8 debounce_threshold = 5;

	uint8 buffer = 0;
	Bsw_IoHwAb_Get_Button(&buffer);

	switch (buffer) {
	case 0:
		button_counter = 0;
		break;
	case 1:
		if (button_counter < debounce_threshold) {
			button_counter++;
		}
		break;
	}

	*status = (button_counter >= debounce_threshold) ? 1 : 0;
}

