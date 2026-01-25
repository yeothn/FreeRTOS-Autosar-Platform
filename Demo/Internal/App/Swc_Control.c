#include "Rte_Swc_Control.h"

void Runnable_Step_Control(void) {
	uint32 receivedData = 0;
	Std_ReturnType status;

	/* Check Queue */
	status = Rte_Receive_RP_DTC_Code(&receivedData);

	if (status == RTE_E_OK) {
		if (receivedData == 1) {
			Rte_Call_RP_IoHwAb_Toggle_Led();
		}
	}
	else if (status == RTE_E_NO_DATA) {
		/* Do nothing */
	}
}
