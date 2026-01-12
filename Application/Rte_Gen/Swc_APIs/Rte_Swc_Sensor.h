#ifndef RTE_SWC_SENSOR_H
#define RTE_SWC_SENSOR_H

#include "Rte_Types.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/

/* Examples */
/* Naming Convention: Rte_Write_<PortName>_<DataElement> */
Std_ReturnType Rte_Write_PP_VehicleSpeed_SpeedVal(uint32 speed); // PP: Provided Port (Sender)
Std_ReturnType Rte_Write_PP_EngineState_Status(uint8 status);

#endif /* RTE_SWC_SENSOR_H */
