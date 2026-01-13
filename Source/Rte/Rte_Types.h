#ifndef RTE_TYPES_H
#define RTE_TYPES_H

/* ===============================================
 * AUTOSAR Types
 * - Define Autosar RTE types
 * =============================================== */

#include <stdint.h>
#include "Std_Types.h"
#include "Os_Types.h"
#include "Rte_PrjTypes.h"

/* RTE Specific Error Codes (Autosar Spec.) */
#define RTE_E_OK 				E_OK
#define RTE_E_INVALID			((Std_ReturnType)0x01)
#define RTE_E_MAX_AGE_EXCEEDED	((Std_ReturnType)0x02)
#define RTE_E_NO_DATA			((Std_ReturnType)0x03)
#define RTE_E_TRANSMIT_ECK		((Std_ReturnType)0x04)
#define RTE_E_LIMIT 			((Std_ReturnType)0x05)
#define RTE_E_LOST_DATA			((Std_ReturnType)0x06)

/* RTE Internal Error Code */
#define RTE_E_SEG_FAULT 		((Std_ReturnType)0xA0) // Memory Access Error
#define RTE_E_TIMEOUT 			((Std_ReturnType)0xA1) // OS Wait Timeout

/* Generic Handle for Data Management (Static Allocation) */
typedef struct {
	void* ValuePtr; 		// Data VFB Address
	uint16 Size; 			// size of data (sizeof)
	ResourceType LockID;	// OS Resource ID for data protection
} Rte_DataHandleType;

/* Ring Buffer Control struct for Queued Communication */
typedef struct {
	Rte_QueueHandleType Handle;
	Rte_QCBType* QCBPtr;
	uint8* BufferPtr;
	uint32 Length;
	uint32 ItemSize;;
} Rte_QueueConfigType;

#endif /* RTE_TYPES_H */
