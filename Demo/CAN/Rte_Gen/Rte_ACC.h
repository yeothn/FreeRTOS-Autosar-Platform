#ifndef Rte_ACC_h
#define Rte_ACC_h
#include "Rte_Types.h"
#include "E2E.h"
#include "Compiler.h"

/* Runnable function */
void Runnable_ACC_Step(void);
void Runnable_ACC_Init(void);

/* Data access functions */
#define Rte_IRead_Runnable_ACC_Step_R_SensorData_distFront Rte_IRead_ACC_Runnable_ACC_Step_R_SensorData_distFront
uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_distFront(void);

#define Rte_IRead_Runnable_ACC_Step_R_SensorData_flgObj Rte_IRead_ACC_Runnable_ACC_Step_R_SensorData_flgObj
uint8 Rte_IRead_Runnable_ACC_Step_R_SensorData_flgObj(void);

#define Rte_IRead_Runnable_ACC_Step_R_SensorData_vObjRel Rte_IRead_ACC_Runnable_ACC_Step_R_SensorData_vObjRel
uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_vObjRel(void);

#define Rte_IRead_Runnable_ACC_Step_R_SensorData_vVeh Rte_IRead_ACC_Runnable_ACC_Step_R_SensorData_vVeh
uint16 Rte_IRead_Runnable_ACC_Step_R_SensorData_vVeh(void);

/* Receive the input data from CAN-RX and distribure */
void Rte_ACC_CopyInput(void);

/* Data write function */
#define Rte_IWrite_Runnable_ACC_Step_P_DisplayData_vDes Rte_IWrite_ACC_Runnable_ACC_Step_P_DisplayData_vDes
void Rte_IWrite_Runnable_ACC_Step_P_DisplayData_vDes(uint16 u);

/* Send the output data to CAN-TX */
void Rte_ACC_CopyOutput(void);

#endif
