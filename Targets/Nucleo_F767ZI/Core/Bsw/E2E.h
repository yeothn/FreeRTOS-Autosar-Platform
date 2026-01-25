#ifndef E2E_H
#define E2E_H

#include "Std_Types.h"

typedef uint8 E2E_PCheckStatusType;

/* 1. E2E Library Error Codes */
#define E2E_E_INPUTERR_NULL     0x13U
#define E2E_E_INPUTERR_WRONG    0x17U
#define E2E_E_INTERR            0x19U
#define E2E_E_OK                0x00U
#define E2E_E_INVALID           0xFFU

/* 2. E2E Protection Wrapper (E2EPW) Status Bits */
#define E2EPW_STATUS_OK             0x00U
#define E2EPW_STATUS_REPEATED       0x01U
#define E2EPW_STATUS_OKSOMELOST     0x20U
#define E2EPW_STATUS_ERROR          0x40U

#endif /* E2E_H */
