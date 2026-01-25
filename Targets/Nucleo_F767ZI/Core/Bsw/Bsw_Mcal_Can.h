#ifndef BSW_MCAL_CAN_H
#define BSW_MCAL_CAN_H

#include "Std_Types.h"

void Bsw_Mcal_CAN_Init(void);
void Bsw_Mcal_CAN_Write(uint8 chn, uint32 id, uint8 *pData, uint8 len);

#endif /* BSW_MCAL_CAN_H */
