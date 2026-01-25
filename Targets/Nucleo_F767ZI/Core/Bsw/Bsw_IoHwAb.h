#ifndef BSW_IOHWAB_H
#define BSW_IOHWAB_H

#include "Std_Types.h"

/* ===============================================
 * Hardware Abstraction
 * - Hardware-specific BSW-Layer Abstraction
 * - Target HW: STM32F767ZI
 * =============================================== */

void Bsw_IoHwAb_Set_Led_Green(uint8 status);
void Bsw_IoHwAb_Set_Led_Blue(uint8 status);
void Bsw_IoHwAb_Set_Led_Red(uint8 status);

void Bsw_IoHwAb_Get_Button(uint8 *status);

void Bsw_IoHwAb_Toggle_Led_Green(void);
void Bsw_IoHwAb_Toggle_Led_Blue(void);
void Bsw_IoHwAb_Toggle_Led_Red(void);

#endif /* BSW_IOHWAB_H */
