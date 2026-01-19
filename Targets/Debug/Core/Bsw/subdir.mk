################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Bsw/Bsw_Com.c \
../Core/Bsw/Bsw_IoHwAb.c \
../Core/Bsw/Bsw_Mcal_Can.c \
../Core/Bsw/Bsw_Service.c \
../Core/Bsw/Bsw_Stub.c 

OBJS += \
./Core/Bsw/Bsw_Com.o \
./Core/Bsw/Bsw_IoHwAb.o \
./Core/Bsw/Bsw_Mcal_Can.o \
./Core/Bsw/Bsw_Service.o \
./Core/Bsw/Bsw_Stub.o 

C_DEPS += \
./Core/Bsw/Bsw_Com.d \
./Core/Bsw/Bsw_IoHwAb.d \
./Core/Bsw/Bsw_Mcal_Can.d \
./Core/Bsw/Bsw_Service.d \
./Core/Bsw/Bsw_Stub.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Bsw/%.o Core/Bsw/%.su Core/Bsw/%.cyclo: ../Core/Bsw/%.c Core/Bsw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/App" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/Sa" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Task" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Config" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Com" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Bsw

clean-Core-2f-Bsw:
	-$(RM) ./Core/Bsw/Bsw_Com.cyclo ./Core/Bsw/Bsw_Com.d ./Core/Bsw/Bsw_Com.o ./Core/Bsw/Bsw_Com.su ./Core/Bsw/Bsw_IoHwAb.cyclo ./Core/Bsw/Bsw_IoHwAb.d ./Core/Bsw/Bsw_IoHwAb.o ./Core/Bsw/Bsw_IoHwAb.su ./Core/Bsw/Bsw_Mcal_Can.cyclo ./Core/Bsw/Bsw_Mcal_Can.d ./Core/Bsw/Bsw_Mcal_Can.o ./Core/Bsw/Bsw_Mcal_Can.su ./Core/Bsw/Bsw_Service.cyclo ./Core/Bsw/Bsw_Service.d ./Core/Bsw/Bsw_Service.o ./Core/Bsw/Bsw_Service.su ./Core/Bsw/Bsw_Stub.cyclo ./Core/Bsw/Bsw_Stub.d ./Core/Bsw/Bsw_Stub.o ./Core/Bsw/Bsw_Stub.su

.PHONY: clean-Core-2f-Bsw

