################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.c \
../Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.c 

OBJS += \
./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.o \
./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.o 

C_DEPS += \
./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.d \
./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Rte_Gen/Swc_APIs/%.o Core/Rte_Gen/Swc_APIs/%.su Core/Rte_Gen/Swc_APIs/%.cyclo: ../Core/Rte_Gen/Swc_APIs/%.c Core/Rte_Gen/Swc_APIs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/App -I../Core/Inc -I../Core/Config -I../Core/Port -I../Core/Rte_Gen -I../Core/Rte_Gen/Swc_APIs -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Source/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Rte_Gen-2f-Swc_APIs

clean-Core-2f-Rte_Gen-2f-Swc_APIs:
	-$(RM) ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.cyclo ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.d ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.o ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Display.su ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.cyclo ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.d ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.o ./Core/Rte_Gen/Swc_APIs/Rte_Swc_Sensor.su

.PHONY: clean-Core-2f-Rte_Gen-2f-Swc_APIs

