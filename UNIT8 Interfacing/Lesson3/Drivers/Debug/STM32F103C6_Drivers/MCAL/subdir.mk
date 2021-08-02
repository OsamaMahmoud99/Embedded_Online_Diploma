################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/MCAL/EXTI.c \
../STM32F103C6_Drivers/MCAL/GPIO.c \
../STM32F103C6_Drivers/MCAL/RCC.c \
../STM32F103C6_Drivers/MCAL/USART.c 

OBJS += \
./STM32F103C6_Drivers/MCAL/EXTI.o \
./STM32F103C6_Drivers/MCAL/GPIO.o \
./STM32F103C6_Drivers/MCAL/RCC.o \
./STM32F103C6_Drivers/MCAL/USART.o 

C_DEPS += \
./STM32F103C6_Drivers/MCAL/EXTI.d \
./STM32F103C6_Drivers/MCAL/GPIO.d \
./STM32F103C6_Drivers/MCAL/RCC.d \
./STM32F103C6_Drivers/MCAL/USART.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/MCAL/EXTI.o: ../STM32F103C6_Drivers/MCAL/EXTI.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/MCAL/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/MCAL/GPIO.o: ../STM32F103C6_Drivers/MCAL/GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/MCAL/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/MCAL/RCC.o: ../STM32F103C6_Drivers/MCAL/RCC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/MCAL/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/MCAL/USART.o: ../STM32F103C6_Drivers/MCAL/USART.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson3/Drivers/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/MCAL/USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

