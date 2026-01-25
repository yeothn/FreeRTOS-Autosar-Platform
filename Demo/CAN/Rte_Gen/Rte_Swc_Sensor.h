#ifndef RTE_SWC_SENSOR_H
#define RTE_SWC_SENSOR_H

#include "Rte_Types.h"
#include "Bsw_IoHwAb.h"

void Runnable_Swc_Sensor_Step(void);

void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_distFront(uint16 u);
void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_flgObj(uint8 u);
void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vObjRel(uint16 u);
void Rte_IWrite_Runnable_Swc_Sensor_Step_P_AccData_vVeh(uint16 u);
void Rte_Swc_Sensor_CopyOutput(void);

void Rte_Call_RP_IoHwAb_Get_Button(uint8 *status);
#define Rte_Call_RP_IoHwAb_Set_Led(status) (Bsw_IoHwAb_Set_Led_Green(status))

#endif /* RTE_SWC_SENSOR_H */
