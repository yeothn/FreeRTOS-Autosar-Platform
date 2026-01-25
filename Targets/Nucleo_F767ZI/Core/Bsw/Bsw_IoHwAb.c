#include "Bsw_IoHwAb.h"
#include "main.h" // for HAL

/* ===============================================
 * Hardware Abstraction
 * - Hardware-specific BSW-Layer Abstraction
 * - Target HW: STM32F767ZI
 * =============================================== */


void Bsw_IoHwAb_Set_Led_Green(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, pinState);
}
void Bsw_IoHwAb_Set_Led_Blue(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, pinState);
}
void Bsw_IoHwAb_Set_Led_Red(uint8 status) {
	GPIO_PinState pinState = (status == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, pinState);
}


void Bsw_IoHwAb_Get_Button(uint8 *status) {
	GPIO_PinState pinState = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	*status = (pinState == GPIO_PIN_SET) ? 1: 0;
}

void Bsw_IoHwAb_Toggle_Led_Green(void) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
}
void Bsw_IoHwAb_Toggle_Led_Blue(void) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
}
void Bsw_IoHwAb_Toggle_Led_Red(void) {
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
}

