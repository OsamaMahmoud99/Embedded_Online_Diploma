################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
OUT_IN_Config.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
OUT_IN_Config.list \

OBJCOPY_BIN += \
OUT_IN_Config.bin \


# All Target
all: OUT_IN_Config.elf secondary-outputs

# Tool invocations
OUT_IN_Config.elf: $(OBJS) $(USER_OBJS) F:\OSAMAA\Embedded\ System\Learn\ In\ Depth\UNIT\ 7\ MCU\ Essential\ peripherals\Lesson\ 1\Lab\OUT_IN_Config\STM32F030C6TX_FLASH.ld
	arm-none-eabi-gcc -o "OUT_IN_Config.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"F:\OSAMAA\Embedded System\Learn In Depth\UNIT 7 MCU Essential peripherals\Lesson 1\Lab\OUT_IN_Config\STM32F030C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="OUT_IN_Config.map" -Wl,--gc-sections -static -gdwarf-2 --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

OUT_IN_Config.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "OUT_IN_Config.list"
	@echo 'Finished building: $@'
	@echo ' '

OUT_IN_Config.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "OUT_IN_Config.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
