################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/MCAL/GPIO/GPIO.c 

OBJS += \
./STM32F103C6_Drivers/MCAL/GPIO/GPIO.o 

C_DEPS += \
./STM32F103C6_Drivers/MCAL/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/MCAL/GPIO/GPIO.o: ../STM32F103C6_Drivers/MCAL/GPIO/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I../Inc -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 7 MCU Essential peripherals/Lesson 4/Drivers/STM32F103C6_Drivers/MCAL/GPIO" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/MCAL/GPIO/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

