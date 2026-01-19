#ifndef RTE_DATA_H
#define RTE_DATA_H

#include "Rte_Types.h"

/* =============================
 * Define the Application data
 * =============================*/
#include "Os_Cfg.h"
#include "Os_Queue.h"

/* Examples */
extern const Rte_DataHandleType Rte_Hdl_VehicleSpeed;
extern const Rte_DataHandleType Rte_Hdl_EngineState;

/* Define the server-client communication structure */
typedef struct {
	TaskType clientID; 	// TaskID of the client

	uint32 input_val; 	// [IN] Client -> Server
	uint32 result_val; 	// [OUT] Server -> Client
} Rte_Csif_Math_Type; // Csif: Client-Server-InterFace, Math: Name of the Swc

extern volatile Rte_Csif_Math_Type Rte_Buffer_MathJob; // Shared-Buffer instance
/* volatile because multiple tasks can change the value */

/* RingBuffer Hanlde for Queued communication */
extern Rte_QueueConfigType Rte_Queue_DTC;

#endif /* RTE_DATA_H */
