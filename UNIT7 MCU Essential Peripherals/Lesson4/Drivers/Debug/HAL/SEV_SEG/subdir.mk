################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SEV_SEG/SEG_config.c \
../HAL/SEV_SEG/SEG_program.c 

OBJS += \
./HAL/SEV_SEG/SEG_config.o \
./HAL/SEV_SEG/SEG_program.o 

C_DEPS += \
./HAL/SEV_SEG/SEG_config.d \
./HAL/SEV_SEG/SEG_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SEV_SEG/SEG_config.o: ../HAL/SEV_SEG/SEG_config.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/MCAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"HAL/SEV_SEG/SEG_config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/SEV_SEG/SEG_program.o: ../HAL/SEV_SEG/SEG_program.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/MCAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/MCAL/GPIO" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"HAL/SEV_SEG/SEG_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

