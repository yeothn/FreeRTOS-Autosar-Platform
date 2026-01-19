#ifndef RTE_SWC_DISPLAY_H
#define RTE_SWC_DISPLAY_H

#include "Rte_Types.h"
#include "Bsw_IoHwAb.h"

void Runnable_Swc_Display_Step(void);

uint16 Rte_IRead_Runnable_Swc_Display_Step_R_AccData_vDes(void);
void Rte_Swc_Display_CopyInput(void);

#define Rte_Call_RP_IoHwAb_Set_Led1(status) (Bsw_IoHwAb_Set_Led_Blue(status))
#define Rte_Call_RP_IoHwAb_Set_Led2(status) (Bsw_IoHwAb_Set_Led_Red(status))

#endif /* RTE_SWC_DISPLAY_H */
