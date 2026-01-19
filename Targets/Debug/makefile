################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/Rte/subdir.mk
-include Source/Os/subdir.mk
-include Middleware/ThirdParty/SEGGER/SEGGER/Syscalls/subdir.mk
-include Middleware/ThirdParty/SEGGER/SEGGER/subdir.mk
-include Middleware/ThirdParty/SEGGER/Rec/subdir.mk
-include Middleware/ThirdParty/SEGGER/OS/subdir.mk
-include Middleware/ThirdParty/SEGGER/Config/subdir.mk
-include Middleware/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F/subdir.mk
-include Middleware/ThirdParty/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Sys/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include Core/Bsw/subdir.mk
-include Application/SWC/Sa/subdir.mk
-include Application/SWC/App/subdir.mk
-include Application/Rte_Gen/subdir.mk
-include Application/Os_Config/Task/subdir.mk
-include Application/Os_Config/Config/subdir.mk
-include Application/Os_Config/Com/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := stm32f407g
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm32f407g.elf \

MAP_FILES += \
stm32f407g.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32f407g.list \


# All Target
all: main-build

# Main-build Target
main-build: stm32f407g.elf secondary-outputs

# Tool invocations
stm32f407g.elf stm32f407g.map: $(OBJS) $(USER_OBJS) D:\yeoth\Projects\Frautos\Targets\stm32f407g\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "stm32f407g.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\yeoth\Projects\Frautos\Targets\stm32f407g\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32f407g.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32f407g.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32f407g.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout stm32f407g.elf stm32f407g.list stm32f407g.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
