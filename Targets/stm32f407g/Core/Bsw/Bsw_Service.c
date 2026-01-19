#include "Bsw_Service.h"

void Bsw_Initialize(void) {
	/* Initialize functions of BSW, called by Os.c - StartOS */
	Bsw_Mcal_CAN_Init();

}
