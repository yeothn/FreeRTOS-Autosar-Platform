#ifndef RTE_SWC_CONTROL_H
#define RTE_SWC_CONTROL_H

#include "Rte_Types.h"
#include "Rte_Data.h"
#include "Bsw_IoHwAb.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/

/* Queued Sender-Receiver Communication */
#define Rte_Receive_RP_DTC_Code(ptr) \
    (Os_QueueReceive(Rte_Queue_DTC.Handle, (ptr)) == E_OK ? RTE_E_OK : RTE_E_NO_DATA)

/* Port Interface - BSW Intra-Partition */
#define Rte_Call_RP_IoHwAb_Toggle_Led() \
    (Bsw_IoHwAb_Toggle_Led_Blue())

#endif /* RTE_SWC_CONTROL_H */
