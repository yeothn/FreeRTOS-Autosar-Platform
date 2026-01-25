#include "Rte_Core.h"

/* ==================================================
 * RTE Application APIs
 * - Implementation of the Application Specific APIs
 * ==================================================*/
#include "Rte_Swc_Math.h"
#include "Rte_Core.h"
#include "Rte_Data.h"
#include "Os_Cfg.h"
#include "Os_Task.h"

/* Server Dispatcher */
void Rte_Server_Math_MainFunction(void) {
	/* Task_ID_SERVER is defined in Os_Cfg */
	/* RTE_EVT_REQ, RTE_EVT_ACK are defined in Os_Task */

	EventMaskType currentEvents;

	/* check the current Event */
	GetEvent(TASK_ID_MATH, &currentEvents);

	if ((currentEvents & RTE_EVT_REQ) != 0) {
		ClearEvent(RTE_EVT_REQ);

		/* Read data from the Shared buffer */
		uint32 in = Rte_Buffer_MathJob.input_val; // Shared buffer is defined in Rte_Data
		TaskType requesterID = Rte_Buffer_MathJob.clientID;

		/* Execute the ASW calculation */
		uint32 out = 0;
		Runnable_Math_Multiply(in, &out);

		/* Write the result in the shared buffer */
		Rte_Buffer_MathJob.result_val = out;

		/* Send the Acknowlege to the Client */
		Rte_Internal_Serve_Ack(requesterID, RTE_EVT_ACK);

	}
}
