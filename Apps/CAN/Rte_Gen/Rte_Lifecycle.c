#include "Rte.h"
#include "Rte_Types.h"

#include <string.h> // for memset

/* RTE Status flag for debugging */
static boolean Rte_Initialized = 0;

Std_ReturnType Rte_Start(void) {
	Rte_Initialized = 1;

	/* Initialization here */

	return RTE_E_OK;
}

Std_ReturnType Rte_Stop(void) {
	Rte_Initialized = 0;

	return RTE_E_OK;
}
