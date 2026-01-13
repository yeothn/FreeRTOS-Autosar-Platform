#ifndef RTE_SWC_DISPLAY_H
#define RTE_SWC_DISPLAY_H

#include "Rte_Types.h"
#include "Bsw_IoHwAb.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/

/* Examples */
/* Naming Convention: Rte_Read_<PortName>_<DataElement> */

/* Explicit Implementation */
Std_ReturnType Rte_Read_RP_VehicleSpeed_SpeedVal(uint32 *speed);

/* Implicit Implementation */
void Rte_Runnable_Display_Start(void);
uint32 Rte_IRead_RP_VehicleSpeed_SpeedVal(void);

/* Server-Client Communication */
#define Rte_Call_RP_Math_Calculate Rte_Call_SwcDisplay_RP_Math_Calculate // for Re-Usability
Std_ReturnType Rte_Call_SwcDisplay_RP_Math_Calculate(uint32 input, uint32 *result);

/* BSW Intra-Partition Call */
#define Rte_Call_RP_IoHwAb_Set_Led(status) (Bsw_IoHwAb_Set_Led_Green(status))
#define Rte_Call_RP_IoHwAb_Toggle_Led() (Bsw_IoHwAb_Toggle_Led_Orange())

#endif /* RTE_GEN_SWC_APIS_RTE_SWC_DISPLAY_H_ */
