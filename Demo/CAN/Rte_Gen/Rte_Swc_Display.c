#include "Rte_Core.h"

/* ==================================================
 * RTE APIs for SWC: Swc_Display
 * - Manual implementation of RTE Code
 * ==================================================*/
#include "Rte_Swc_Display.h"
#include "Rte_Core.h"
#include "Os_Cfg.h"
#include "Os_Task.h"
#include "Bsw_Com.h"
#include "Com_Cfg.h"

/* Input port Buffers for implicit communication */
static uint16 VFB_Swc_Display_vDes = 0;

/* Implicit Read Implementation for Swc_Display.c */
uint16 Rte_IRead_Runnable_Swc_Display_Step_R_AccData_vDes(void) {
	return VFB_Swc_Display_vDes;
}

void Rte_Swc_Display_CopyInput(void) {
	Pdu_DisplayDataType rxData;

	/* Receive the rxData (CAN_ID: PDU_ID_DISPLAY_RX) */
	Bsw_Com_GetRxData(PDU_ID_DISPLAY_RX, (uint8*)&rxData);

	/* Update shadow variables */
	VFB_Swc_Display_vDes = rxData.vDes;
}
