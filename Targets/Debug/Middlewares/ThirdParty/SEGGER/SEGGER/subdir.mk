################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c Middlewares/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S Middlewares/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c Middlewares/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c Middlewares/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ThirdParty-2f-SEGGER-2f-SEGGER

clean-Middlewares-2f-ThirdParty-2f-SEGGER-2f-SEGGER:
	-$(RM) ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.cyclo ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.su ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.su ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./Middlewares/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Middlewares-2f-ThirdParty-2f-SEGGER-2f-SEGGER

