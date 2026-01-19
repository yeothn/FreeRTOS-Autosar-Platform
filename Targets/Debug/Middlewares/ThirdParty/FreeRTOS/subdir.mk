################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/croutine.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/event_groups.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/list.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/queue.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/stream_buffer.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/tasks.c \
D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/timers.c 

OBJS += \
./Middlewares/ThirdParty/FreeRTOS/croutine.o \
./Middlewares/ThirdParty/FreeRTOS/event_groups.o \
./Middlewares/ThirdParty/FreeRTOS/list.o \
./Middlewares/ThirdParty/FreeRTOS/queue.o \
./Middlewares/ThirdParty/FreeRTOS/stream_buffer.o \
./Middlewares/ThirdParty/FreeRTOS/tasks.o \
./Middlewares/ThirdParty/FreeRTOS/timers.o 

C_DEPS += \
./Middlewares/ThirdParty/FreeRTOS/croutine.d \
./Middlewares/ThirdParty/FreeRTOS/event_groups.d \
./Middlewares/ThirdParty/FreeRTOS/list.d \
./Middlewares/ThirdParty/FreeRTOS/queue.d \
./Middlewares/ThirdParty/FreeRTOS/stream_buffer.d \
./Middlewares/ThirdParty/FreeRTOS/tasks.d \
./Middlewares/ThirdParty/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ThirdParty/FreeRTOS/croutine.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/croutine.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/event_groups.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/event_groups.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/list.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/list.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/queue.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/queue.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/stream_buffer.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/stream_buffer.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/tasks.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/tasks.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThirdParty/FreeRTOS/timers.o: D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/timers.c Middlewares/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/include" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/Config" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/OS" -I"D:/yeoth/Projects/Frautos/Middlewares/ThirdParty/SEGGER/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ThirdParty-2f-FreeRTOS

clean-Middlewares-2f-ThirdParty-2f-FreeRTOS:
	-$(RM) ./Middlewares/ThirdParty/FreeRTOS/croutine.cyclo ./Middlewares/ThirdParty/FreeRTOS/croutine.d ./Middlewares/ThirdParty/FreeRTOS/croutine.o ./Middlewares/ThirdParty/FreeRTOS/croutine.su ./Middlewares/ThirdParty/FreeRTOS/event_groups.cyclo ./Middlewares/ThirdParty/FreeRTOS/event_groups.d ./Middlewares/ThirdParty/FreeRTOS/event_groups.o ./Middlewares/ThirdParty/FreeRTOS/event_groups.su ./Middlewares/ThirdParty/FreeRTOS/list.cyclo ./Middlewares/ThirdParty/FreeRTOS/list.d ./Middlewares/ThirdParty/FreeRTOS/list.o ./Middlewares/ThirdParty/FreeRTOS/list.su ./Middlewares/ThirdParty/FreeRTOS/queue.cyclo ./Middlewares/ThirdParty/FreeRTOS/queue.d ./Middlewares/ThirdParty/FreeRTOS/queue.o ./Middlewares/ThirdParty/FreeRTOS/queue.su ./Middlewares/ThirdParty/FreeRTOS/stream_buffer.cyclo ./Middlewares/ThirdParty/FreeRTOS/stream_buffer.d ./Middlewares/ThirdParty/FreeRTOS/stream_buffer.o ./Middlewares/ThirdParty/FreeRTOS/stream_buffer.su ./Middlewares/ThirdParty/FreeRTOS/tasks.cyclo ./Middlewares/ThirdParty/FreeRTOS/tasks.d ./Middlewares/ThirdParty/FreeRTOS/tasks.o ./Middlewares/ThirdParty/FreeRTOS/tasks.su ./Middlewares/ThirdParty/FreeRTOS/timers.cyclo ./Middlewares/ThirdParty/FreeRTOS/timers.d ./Middlewares/ThirdParty/FreeRTOS/timers.o ./Middlewares/ThirdParty/FreeRTOS/timers.su

.PHONY: clean-Middlewares-2f-ThirdParty-2f-FreeRTOS

