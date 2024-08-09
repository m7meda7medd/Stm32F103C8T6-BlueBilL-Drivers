################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Systick/systick.c 

OBJS += \
./Mcal/Systick/systick.o 

C_DEPS += \
./Mcal/Systick/systick.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Systick/%.o Mcal/Systick/%.su Mcal/Systick/%.cyclo: ../Mcal/Systick/%.c Mcal/Systick/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-Systick

clean-Mcal-2f-Systick:
	-$(RM) ./Mcal/Systick/systick.cyclo ./Mcal/Systick/systick.d ./Mcal/Systick/systick.o ./Mcal/Systick/systick.su

.PHONY: clean-Mcal-2f-Systick

