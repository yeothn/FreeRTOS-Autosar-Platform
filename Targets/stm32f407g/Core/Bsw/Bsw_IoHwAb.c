#include "Bsw_IoHwAb.h"
#include "main.h" // for HAL

/* ===============================================
 * Hardware Abstraction
 * - Hardware-specific BSW-Layer Abstraction
 * - Target HW: ARM Cortex M4
 * =============================================== */


void Bsw_IoHwAb_Set_Led_Green(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, pinState);
}
void Bsw_IoHwAb_Set_Led_Orange(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, pinState);
}
void Bsw_IoHwAb_Set_Led_Red(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, pinState);
}
void Bsw_IoHwAb_Set_Led_Blue(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, pinState);
}

void Bsw_IoHwAb_Get_Button(uint8 *status) {
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	*status = (pinState == GPIO_PIN_SET) ? 1: 0;
}

void Bsw_IoHwAb_Toggle_Led_Green(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
}
void Bsw_IoHwAb_Toggle_Led_Orange(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
}
void Bsw_IoHwAb_Toggle_Led_Red(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
}
void Bsw_IoHwAb_Toggle_Led_Blue(void) {
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}
