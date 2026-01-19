################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Config/Template/Os_Cfg_Template.c \
../Core/Config/Template/Rte_Cfg_Template.c 

OBJS += \
./Core/Config/Template/Os_Cfg_Template.o \
./Core/Config/Template/Rte_Cfg_Template.o 

C_DEPS += \
./Core/Config/Template/Os_Cfg_Template.d \
./Core/Config/Template/Rte_Cfg_Template.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Config/Template/%.o Core/Config/Template/%.su Core/Config/Template/%.cyclo: ../Core/Config/Template/%.c Core/Config/Template/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Core/Config -I../Core/Port -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middleware/ThirdParty/SEGGER/SEGGER" -I"D:/yeoth/Projects/Frautos/Source/Services/OsWrapper" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Config-2f-Template

clean-Core-2f-Config-2f-Template:
	-$(RM) ./Core/Config/Template/Os_Cfg_Template.cyclo ./Core/Config/Template/Os_Cfg_Template.d ./Core/Config/Template/Os_Cfg_Template.o ./Core/Config/Template/Os_Cfg_Template.su ./Core/Config/Template/Rte_Cfg_Template.cyclo ./Core/Config/Template/Rte_Cfg_Template.d ./Core/Config/Template/Rte_Cfg_Template.o ./Core/Config/Template/Rte_Cfg_Template.su

.PHONY: clean-Core-2f-Config-2f-Template

