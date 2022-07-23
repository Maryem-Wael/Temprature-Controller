################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 

S_DEPS += \
./startup/startup_stm32.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/inc" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/device" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/CMSIS/core" -I"D:/Smbe/Coding-for-Embedded-Software/Task3/PID/Drivers/inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@" "$<"

