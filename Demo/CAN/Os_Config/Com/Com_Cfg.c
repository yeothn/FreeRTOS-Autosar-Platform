#include "Com_Cfg.h"

/* ==========================================
 * Communication Configuration Table
 * - User configuration
 * ========================================== */

/* --- CAN Communication --- */

/* Communication PDU Buffers */
static uint8 RxBuffer_ACC[8];
static uint8 RxBuffer_Display[8];

#define COM_CH_CAN1 0
#define COM_CH_CAN2 1

const Com_RxConfigType Com_RxConfigTable[COM_RX_PDU_COUNT] = {
	{
		.NetworkID = PDU_ID_ACC_RX,
		.Length = 8, // CAN
		.Channel = COM_CH_CAN1,
		.DestBuffer = RxBuffer_ACC
	},
	{
		.NetworkID = PDU_ID_DISPLAY_RX,
		.Length = 8, // CAN
		.Channel = COM_CH_CAN2,
		.DestBuffer = RxBuffer_Display
	}
};

const Com_TxConfigType Com_TxConfigTable[COM_TX_PDU_COUNT] = {
	{
		.NetworkID = PDU_ID_SENSOR_TX,
		.Length = 8, // CAN
		.Channel = COM_CH_CAN1
	},
	{
		.NetworkID = PDU_ID_ACC_TX,
		.Length = 8, // CAN
		.Channel = COM_CH_CAN2
	}
};

/* --- Handle for internal S-R Communication --- */

/* --- Queue for C-S Communication --- */
