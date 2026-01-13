#ifndef BSW_IOHWAB_H
#define BSW_IOHWAB_H

#include "Std_Types.h"

/* ===============================================
 * Hardware Abstraction
 * - Hardware-specific BSW-Layer Abstraction
 * - Target HW: ARM Cortex M4
 * =============================================== */

void Bsw_IoHwAb_Set_Led_Green(uint8 status);
void Bsw_IoHwAb_Set_Led_Orange(uint8 status);
void Bsw_IoHwAb_Set_Led_Red(uint8 status);
void Bsw_IoHwAb_Set_Led_Blue(uint8 status);

void Bsw_IoHwAb_Toggle_Led_Green(void);
void Bsw_IoHwAb_Toggle_Led_Orange(void);
void Bsw_IoHwAb_Toggle_Led_Red(void);
void Bsw_IoHwAb_Toggle_Led_Blue(void);

#endif /* BSW_IOHWAB_H */
