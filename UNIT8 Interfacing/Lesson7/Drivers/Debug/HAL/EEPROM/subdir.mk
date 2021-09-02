################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM/I2C_Slave_EEPROM.c 

OBJS += \
./HAL/EEPROM/I2C_Slave_EEPROM.o 

C_DEPS += \
./HAL/EEPROM/I2C_Slave_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM/I2C_Slave_EEPROM.o: ../HAL/EEPROM/I2C_Slave_EEPROM.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/HAL" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/HAL/KEYPAD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/HAL/LCD" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/HAL/SEV_SEG" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/STM32F103C6_Drivers" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/STM32F103C6_Drivers/LIB" -I"F:/OSAMAA/Embedded System/Learn In Depth/UNIT 8 Interfacing/Lesson7/Drivers/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"HAL/EEPROM/I2C_Slave_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

