################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o: D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c Middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/App" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/Sa" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Task" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Config" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Com" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S Middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o: D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c Middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/App" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/Sa" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Task" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Config" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Com" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c Middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/App" -I"D:/yeoth/Projects/Frautos/Apps/CAN/SWC/Sa" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Task" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Config" -I"D:/yeoth/Projects/Frautos/Apps/CAN/Os_Config/Com" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER

clean-Middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER:
	-$(RM) ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.cyclo ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.su ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.su ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./Middleware/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Middleware-2f-ThirdParty-2f-SEGGER-2f-SEGGER

