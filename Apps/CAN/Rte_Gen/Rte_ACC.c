
/* ==================================================
 * RTE APIs for SWC: ACC
 * - Manual implementation of RTE Code
 * ==================================================*/
#include "Rte_ACC.h"

#include "Rte_Core.h"
#include "Os_Cfg.h"
#include "Os_Task.h"
#include "Bsw_Com.h"
#include "Com_Cfg.h"

/* Input port Buffers for implicit communication */
static uint16 VFB_ACC_distFront = 0;
static uint8 VFB_ACC_flgObj = 0;
static uint16 VFB_ACC_vObjRel = 0;
static uint16 VFB_ACC_vVeh = 0;

/* Implicit Read Implementation for ACC.c */
uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_distFront(void) {
	return VFB_ACC_distFront;
}

uint8 Rte_IRead_Runnable_ACC_Step_R_SensorData_flgObj(void) {
	return VFB_ACC_flgObj;
}

uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_vObjRel(void) {
	return VFB_ACC_vObjRel;
}

uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_vVeh(void) {
	return VFB_ACC_vVeh;
}

void Rte_ACC_CopyInput(void) {
	Pdu_ACCDataType rxData;

	/* Receive the rxData (CAN_ID: PDU_ID_ACC_RX) */
	Bsw_Com_GetRxData(PDU_ID_ACC_RX, (uint8*)&rxData);

	/* Update shadow variables */
	VFB_ACC_distFront = rxData.distFront;
	VFB_ACC_vObjRel = rxData.vObjRel;
	VFB_ACC_vVeh = rxData.vVeh;
	VFB_ACC_flgObj = rxData.flgObj;
}

/* Outport Buffer for Implicit communication */
static uint16 VFB_ACC_vDes = 0;

/* Implicit Write Implementation for ACC */
void Rte_IWrite_Runnable_ACC_Step_P_DisplayData_vDes(uint16 u) {
	VFB_ACC_vDes = u;
}

void Rte_ACC_CopyOutput(void) {
	Pdu_DisplayDataType txData = {0,};

	/* Update txData */
	txData.vDes = VFB_ACC_vDes;

	/* Send the txData (CAN_ID: PDU_ID_ACC_TX) */
	Bsw_Com_SendMsg(PDU_ID_ACC_TX, (uint8*)&txData, sizeof(Pdu_DisplayDataType));
}
