#ifndef RTE_SWC_SENSOR_H
#define RTE_SWC_SENSOR_H

#include "Rte_Types.h"
#include "Rte_Data.h"
#include "Bsw_IoHwAb.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/

/* Examples */
/* Naming Convention: Rte_Write_<PortName>_<DataElement> */

/* Explicit Implementation */
Std_ReturnType Rte_Write_PP_VehicleSpeed_SpeedVal(uint32 speed); // PP: Provided Port (Sender)
Std_ReturnType Rte_Write_PP_EngineState_Status(uint8 status);

/* Implicit Implementation */
void Rte_IWrite_PP_VehicleSpeed_SpeedVal(uint32 speed);
void Rte_Runnable_Sensor_End(void);

/* Server-Client Communication */
#define Rte_Call_RP_Math_Calculate Rte_Call_SwcSensor_RP_Math_Calculate // for Re-Usability
Std_ReturnType Rte_Call_SwcSensor_RP_Math_Calculate(uint32 input, uint32 *result);

/* Queued Sender-Receiver Communication */
#define Rte_Send_PP_DTC_Code(dtcPayload) \
    (Os_QueueSend(Rte_Queue_DTC.Handle, (dtcPayload)) == E_OK ? RTE_E_OK : RTE_E_NO_DATA)

/* BSW Intra-Partition Call */
#define Rte_Call_RP_IoHwAb_Toggle_Led() (Bsw_IoHwAb_Toggle_Led_Orange())
void Rte_Call_RP_IoHwAb_Get_Button(uint8 *status);

#endif /* RTE_SWC_SENSOR_H */
