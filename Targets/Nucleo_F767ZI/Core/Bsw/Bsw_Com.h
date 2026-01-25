#ifndef BSW_COM_H
#define BSW_COM_H

#include "Std_Types.h"

/* Transmit function called by Application */
void Bsw_Com_SendMsg(uint32 PduID, uint8 *pData, uint8 len);
void Bsw_Com_GetRxData(uint32 PduID, uint8 *pOutData);

/* Receive function called by MCAL */
void Bsw_Com_RxIndication(uint8 chn, uint32 id, uint8 *pData, uint8 len);

#endif /* BSW_COM_H_ */
