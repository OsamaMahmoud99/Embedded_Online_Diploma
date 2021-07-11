################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.c 

OBJS += \
./STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.o 

C_DEPS += \
./STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.o: ../STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I../Inc -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/MCAL/GPIO" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/MCAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 3/Drivers/STM32F103C6_Drivers/HAL/SEV_SEG" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/HAL/KEYPAD/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

