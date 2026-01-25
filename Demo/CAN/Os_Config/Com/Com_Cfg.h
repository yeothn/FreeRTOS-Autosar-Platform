#ifndef COM_CFG_H
#define COM_CFG_H

#include "Std_Types.h"
#include "Com_Types.h"

/* ==========================================
 * Communication Packet Configuration
 * - User configuration
 * ========================================== */

/* --- CAN Communication --- */

/* Activate CAN */
#define CAN1_ACTIVE 1
#define CAN2_ACTIVE 1
#define CAN3_ACTIVE 0

/* define CAN IDs */
#define CAN_ID_SENSOR_DATA 		0x100
#define CAN_ID_DISPLAY_DATA 	0x200

/* define PDU IDs */
typedef enum {
	PDU_ID_ACC_RX,
	PDU_ID_DISPLAY_RX,
	COM_RX_PDU_COUNT
} Com_PduID_RX_Enum;

typedef enum {
	PDU_ID_SENSOR_TX,
	PDU_ID_ACC_TX,
	COM_TX_PDU_COUNT
} Com_PduID_TX_Enum;

extern const Com_RxConfigType Com_RxConfigTable[COM_RX_PDU_COUNT];
extern const Com_TxConfigType Com_TxConfigTable[COM_TX_PDU_COUNT];

typedef struct {
	uint16 distFront;// Byte 0, 1
	uint16 vObjRel;	 // Byte 2, 3
	uint16 vVeh;	 // Byte 4, 5
	uint8 flgObj; 	 // Byte 6
	uint8 _padding[1];
} __attribute__((packed)) Pdu_ACCDataType;

typedef struct {
	uint16 vDes;// Byte 0, 1
	uint16 _padding[3];
} __attribute__((packed)) Pdu_DisplayDataType;

/* --- Handle for internal S-R Communication --- */

/* --- Queue for C-S Communication --- */

#endif /* COM_CFG_H */
