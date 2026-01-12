#ifndef RTE_PRJTYPES_H
#define RTE_PRJTYPES_H

#include "FreeRTOS.h"
#include "queue.h"

/* ===============================================
 * Project-specific Type definition
 * - Re-define FreeRTOS Types as Project-specific
 *   RTE Types (Not Autosar Standard)
 * =============================================== */

/* Queue Control Block Type */
typedef StaticQueue_t Rte_QCBType;

/* Queue Handle Type */
typedef QueueHandle_t Rte_QueueHandleType;



#endif /* RTE_RTE_PRJTYPES_H_ */
