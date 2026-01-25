
/* Hardware specific function for Interrupt-detection
 *
 * In FreeRTOS, Interrupt must use ISR-version of call
 * like xTaskNotify vs. xTaskNotifyFromISR
 *
 * Since the method to detect the Interrupt-state varies
 * with the manufacturer of the hardware, this function
 * must be implemented separately for each Hardware type.
 *
 * The function Os_Port_IsISR will be called from
 * Source/Services/OsWrapper/Os_Port.h */

/* Interrupt detection for ARM Cortex-M */
#include "Sys_Port.h"

BaseType_t Sys_Port_IsISR(void) {
    if (__get_IPSR() != 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}
