#ifndef RTE_CORE_H
#define RTE_CORE_H

#include "Rte_Types.h"

/* ================================
 * Explicit Communication Engine
 * ================================ */

/* Rte_Write, Rte_Read */
Std_ReturnType Rte_Internal_Write(const Rte_DataHandleType *handle, const void *data);
Std_ReturnType Rte_Internal_Read(const Rte_DataHandleType *handle, void *data);

Std_ReturnType Rte_Internal_Start(void);

#endif /* RTE_CORE_H */
