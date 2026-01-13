#ifndef RTE_CORE_H
#define RTE_CORE_H

#include "Rte_Types.h"
#include "Os.h"

/* =======================================
 * Communication Engine: Sender-Receiver
 * ======================================= */

/* Rte_Write, Rte_Read */
Std_ReturnType Rte_Internal_Write(const Rte_DataHandleType *handle, const void *data);
Std_ReturnType Rte_Internal_Read(const Rte_DataHandleType *handle, void *data);


/* =======================================
 * Communication Engine: Server-Client
 * ======================================= */

/* Server-Client Communication */
Std_ReturnType Rte_Internal_Call_Blocking(TaskType serverTaskID, EventMaskType reqEvent, EventMaskType ackEvent);
Std_ReturnType Rte_Internal_Serve_Ack(TaskType clientTaskID, EventMaskType ackEvent);

/* Generic Client-Server Exchange Engine (Macro) */
#define RTE_CALL_BLOCKING_ENGINE(ResID, ClientID, ServerID, DataBuffer, reqEvent, ackEvent, InputOper, OutputOper) \
	do { \
		GetResource(ResID); \
		(DataBuffer).clientID = (ClientID); \
		InputOper; \
		Rte_Internal_Call_Blocking(ServerID, reqEvent, ackEvent); \
		OutputOper; \
		ReleaseResource(ResID); \
	} while(0)


Std_ReturnType Rte_Internal_Start(void);

#endif /* RTE_CORE_H */
