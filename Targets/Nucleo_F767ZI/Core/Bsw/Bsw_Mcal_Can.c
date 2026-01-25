#include "main.h"
#include "Com_Cfg.h"
#include "Bsw_Com.h"
#include "Bsw_Mcal_Can.h"

extern CAN_HandleTypeDef hcan1;
extern CAN_HandleTypeDef hcan2;
extern CAN_HandleTypeDef hcan3;

static void Bsw_Mcal_CAN1_Setup(void);
static void Bsw_Mcal_CAN2_Setup(void);
static void Bsw_Mcal_CAN3_Setup(void);

void Bsw_Mcal_CAN_Init(void) {
	//MX_CAN1_Init(); // called in main.c
	//MX_CAN2_Init();
	if (CAN1_ACTIVE) {
		Bsw_Mcal_CAN1_Setup();
	}
	if (CAN2_ACTIVE) {
		Bsw_Mcal_CAN2_Setup();
	}
	if (CAN3_ACTIVE) {
		Bsw_Mcal_CAN3_Setup();
	}
}

static void Bsw_Mcal_CAN1_Setup(void) {
	CAN_FilterTypeDef sFilterCfg;

	sFilterCfg.FilterBank = 0;
	sFilterCfg.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterCfg.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterCfg.FilterIdHigh = 0x0000;
	sFilterCfg.FilterIdLow = 0x0000;
	sFilterCfg.FilterMaskIdHigh = 0x0000;
	sFilterCfg.FilterMaskIdLow = 0x0000;
	sFilterCfg.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterCfg.FilterActivation = ENABLE;
	sFilterCfg.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&hcan1, &sFilterCfg) != HAL_OK) {
		/* Error */
	}

	HAL_CAN_Start(&hcan1);

	/* DMA-Simliar implementation */
	/* Call CPU if data arrive */
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

static void Bsw_Mcal_CAN2_Setup(void) {
	CAN_FilterTypeDef sFilterCfg;

		sFilterCfg.FilterBank = 14;
		sFilterCfg.FilterMode = CAN_FILTERMODE_IDMASK;
		sFilterCfg.FilterScale = CAN_FILTERSCALE_32BIT;
		sFilterCfg.FilterIdHigh = 0x0000;
		sFilterCfg.FilterIdLow = 0x0000;
		sFilterCfg.FilterMaskIdHigh = 0x0000;
		sFilterCfg.FilterMaskIdLow = 0x0000;
		sFilterCfg.FilterFIFOAssignment = CAN_RX_FIFO0;
		sFilterCfg.FilterActivation = ENABLE;
		sFilterCfg.SlaveStartFilterBank = 14;

		/* stm32f407 - filter config for can2 must be set by can1 */
		if (HAL_CAN_ConfigFilter(&hcan1, &sFilterCfg) != HAL_OK) {
			/* Error */
		}

		HAL_CAN_Start(&hcan2);

		/* DMA-Simliar implementation */
		/* Call CPU if data arrive */
		HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);
}

static void Bsw_Mcal_CAN3_Setup(void) {
	CAN_FilterTypeDef sFilterCfg;

	sFilterCfg.FilterBank = 0;
	sFilterCfg.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterCfg.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterCfg.FilterIdHigh = 0x0000;
	sFilterCfg.FilterIdLow = 0x0000;
	sFilterCfg.FilterMaskIdHigh = 0x0000;
	sFilterCfg.FilterMaskIdLow = 0x0000;
	sFilterCfg.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterCfg.FilterActivation = ENABLE;
	sFilterCfg.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&hcan3, &sFilterCfg) != HAL_OK) {
		/* Error */
	}

	HAL_CAN_Start(&hcan3);

	/* DMA-Simliar implementation */
	/* Call CPU if data arrive */
	HAL_CAN_ActivateNotification(&hcan3, CAN_IT_RX_FIFO0_MSG_PENDING);
}


/* Non-blocking data transmit */
void Bsw_Mcal_CAN_Write(uint8 chn, uint32 id, uint8 *pData, uint8 len) {
	/* select channel */
	CAN_HandleTypeDef *hcan_ptr = NULL_PTR;
	switch(chn) {
		case 0: hcan_ptr = &hcan1; break;
		case 1: hcan_ptr = &hcan2; break;
		case 2: hcan_ptr = &hcan3; break;
		default: return;
	}

	CAN_TxHeaderTypeDef TxHeader;
	uint32 TxMailbox;

	TxHeader.StdId = id;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.DLC = len;
	TxHeader.TransmitGlobalTime = DISABLE;

	/* Put to the Hardware Mailbox, and return */
	HAL_CAN_AddTxMessage(hcan_ptr, &TxHeader, pData, &TxMailbox);
}


/* Pending Interrupt Callback (overwrite weak-function) */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	CAN_RxHeaderTypeDef RxHeader;
	uint8 RxData[8];

	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);

	/* Take the data from Register */
	if(hcan->Instance == CAN1) {
		Bsw_Com_RxIndication(0, RxHeader.StdId, RxData, RxHeader.DLC);
	} else if (hcan->Instance == CAN2) {
		Bsw_Com_RxIndication(1, RxHeader.StdId, RxData, RxHeader.DLC);
	} else if (hcan->Instance == CAN3) {

	}
}
