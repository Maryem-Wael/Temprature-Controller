################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/GPIO.c \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/SPI.c \
../Drivers/src/TC72.c \
../Drivers/src/USART.c \
../Drivers/src/Util.c \
../Drivers/src/device.c \
../Drivers/src/poller.c \
../Drivers/src/system_stm32f4xx.c 

OBJS += \
./Drivers/src/GPIO.o \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/SPI.o \
./Drivers/src/TC72.o \
./Drivers/src/USART.o \
./Drivers/src/Util.o \
./Drivers/src/device.o \
./Drivers/src/poller.o \
./Drivers/src/system_stm32f4xx.o 

C_DEPS += \
./Drivers/src/GPIO.d \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/SPI.d \
./Drivers/src/TC72.d \
./Drivers/src/USART.d \
./Drivers/src/Util.d \
./Drivers/src/device.d \
./Drivers/src/poller.d \
./Drivers/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c Drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/inc" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/device" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/core" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

