################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Rte_Gen/Rte_Data.c 

OBJS += \
./Core/Rte_Gen/Rte_Data.o 

C_DEPS += \
./Core/Rte_Gen/Rte_Data.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Rte_Gen/%.o Core/Rte_Gen/%.su Core/Rte_Gen/%.cyclo: ../Core/Rte_Gen/%.c Core/Rte_Gen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/App -I../Core/Inc -I../Core/Config -I../Core/Port -I../Core/Rte_Gen -I../Core/Rte_Gen/Swc_APIs -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Os" -I"D:/yeoth/Projects/Frautos/Source/Rte" -I"D:/yeoth/Projects/Frautos/Source/Common" -I"D:/yeoth/Projects/Frautos/Source/App" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Rte_Gen

clean-Core-2f-Rte_Gen:
	-$(RM) ./Core/Rte_Gen/Rte_Data.cyclo ./Core/Rte_Gen/Rte_Data.d ./Core/Rte_Gen/Rte_Data.o ./Core/Rte_Gen/Rte_Data.su

.PHONY: clean-Core-2f-Rte_Gen

