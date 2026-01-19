################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.c \
D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.c \
D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.c \
D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.c 

OBJS += \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.o \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.o \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.o \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.o 

C_DEPS += \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.d \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.d \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.d \
./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.o: D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.c Application/Rte_Gen/Swc_APIs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs" -I"D:/yeoth/Projects/Frautos/Application/App" -I"D:/yeoth/Projects/Frautos/Application/Sa" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Task" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.o: D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.c Application/Rte_Gen/Swc_APIs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs" -I"D:/yeoth/Projects/Frautos/Application/App" -I"D:/yeoth/Projects/Frautos/Application/Sa" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Task" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.o: D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.c Application/Rte_Gen/Swc_APIs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs" -I"D:/yeoth/Projects/Frautos/Application/App" -I"D:/yeoth/Projects/Frautos/Application/Sa" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Task" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.o: D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.c Application/Rte_Gen/Swc_APIs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Bsw -I../Core/Inc -I../Core/Sys -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen" -I"D:/yeoth/Projects/Frautos/Application/Rte_Gen/Swc_APIs" -I"D:/yeoth/Projects/Frautos/Application/App" -I"D:/yeoth/Projects/Frautos/Application/Sa" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Task" -I"D:/yeoth/Projects/Frautos/Application/OsConfig/Config" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-Rte_Gen-2f-Swc_APIs

clean-Application-2f-Rte_Gen-2f-Swc_APIs:
	-$(RM) ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.cyclo ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.d ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.o ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Control.su ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.cyclo ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.d ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.o ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Display.su ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.cyclo ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.d ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.o ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Math.su ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.cyclo ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.d ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.o ./Application/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.su

.PHONY: clean-Application-2f-Rte_Gen-2f-Swc_APIs

