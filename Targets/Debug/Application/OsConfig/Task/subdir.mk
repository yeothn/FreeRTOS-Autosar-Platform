################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/yeoth/Projects/Frautos/Application/OsConfig/Task/Os_Task.c 

OBJS += \
./Application/OsConfig/Task/Os_Task.o 

C_DEPS += \
./Application/OsConfig/Task/Os_Task.d 


# Each subdirectory must supply rules for building sources it contributes
Application/OsConfig/Task/Os_Task.o: D:/yeoth/Projects/Frautos/Application/OsConfig/Task/Os_Task.c Application/OsConfig/Task/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs" -I"D:/yeoth/Projects/Frautos/Application/App" -I"D:/yeoth/Projects/Frautos/Application/Sa" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Task" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-OsConfig-2f-Task

clean-Application-2f-OsConfig-2f-Task:
	-$(RM) ./Application/OsConfig/Task/Os_Task.cyclo ./Application/OsConfig/Task/Os_Task.d ./Application/OsConfig/Task/Os_Task.o ./Application/OsConfig/Task/Os_Task.su

.PHONY: clean-Application-2f-OsConfig-2f-Task

