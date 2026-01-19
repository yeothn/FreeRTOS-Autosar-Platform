#include "Bsw_Com.h"
#include "Bsw_Mcal_Can.h"
#include "Com_Cfg.h"
#include "Os.h"
#include <string.h> // for memcpy

/* Transmit */
void Bsw_Com_SendMsg(uint32 PduID, uint8 *pData, uint8 len) {
	uint32 id = Com_TxConfigTable[PduID].NetworkID;
	uint8 chn = Com_TxConfigTable[PduID].Channel;
	Bsw_Mcal_CAN_Write(chn, id, pData, len);
}

/* Receive */
void Bsw_Com_RxIndication(uint8 chn, uint32 id, uint8 *pData, uint8 len) {
	/* Find right ID along the table (for-loop) */
	/* For bigger communication, better search algorithm should be adopted */
	for (uint8 i = 0; i < COM_RX_PDU_COUNT; i++) {
		if ((Com_RxConfigTable[i].NetworkID == id) &&
				(Com_RxConfigTable[i].Channel == chn)) {
			uint8 copyLen = (len > Com_RxConfigTable[i].Length) ?
					Com_RxConfigTable[i].Length : len;

			/* memcpy to the DestBuffer */
			memcpy(Com_RxConfigTable[i].DestBuffer, pData, copyLen);
			return;
		}
	}
}

void Bsw_Com_GetRxData(uint32 PduID, uint8 *pOutData) {
	SuspendOSInterrupts();
	memcpy(pOutData, Com_RxConfigTable[PduID].DestBuffer, Com_RxConfigTable[PduID].Length);
	ResumeOSInterrupts();
}
