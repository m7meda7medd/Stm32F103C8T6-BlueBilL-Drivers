################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/RCC_new/RCC_interface.c 

OBJS += \
./Mcal/RCC_new/RCC_interface.o 

C_DEPS += \
./Mcal/RCC_new/RCC_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/RCC_new/%.o Mcal/RCC_new/%.su Mcal/RCC_new/%.cyclo: ../Mcal/RCC_new/%.c Mcal/RCC_new/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-RCC_new

clean-Mcal-2f-RCC_new:
	-$(RM) ./Mcal/RCC_new/RCC_interface.cyclo ./Mcal/RCC_new/RCC_interface.d ./Mcal/RCC_new/RCC_interface.o ./Mcal/RCC_new/RCC_interface.su

.PHONY: clean-Mcal-2f-RCC_new

