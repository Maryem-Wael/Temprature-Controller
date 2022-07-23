################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/syscalls.c 

OBJS += \
./src/main.o \
./src/syscalls.o 

C_DEPS += \
./src/main.d \
./src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -c -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/inc" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/device" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/core" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/Drivers/inc" -O0 -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

