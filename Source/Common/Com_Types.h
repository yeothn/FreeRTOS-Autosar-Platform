#ifndef COM_TYPES_H
#define COM_TYPES_H

/* ===============================================
 * AUTOSAR Types
 * - Define Autosar COM types
 * =============================================== */

#include "Std_Types.h"

typedef struct {
	uint32 NetworkID;	// Physical ID
	uint8 Length;		// Data Length (DLC)
	uint8 Channel;		// Channel
	uint8* DestBuffer; 	// Destination Buffer Address
} Com_RxConfigType;

typedef struct {
	uint32 NetworkID;	// Physical ID
	uint8 Length;		// Data Length (DLC)
	uint8 Channel;		// Channel
} Com_TxConfigType;

#endif /* COM_TYPES_H */
