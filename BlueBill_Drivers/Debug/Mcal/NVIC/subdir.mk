################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/NVIC/NVIC_interface.c 

OBJS += \
./Mcal/NVIC/NVIC_interface.o 

C_DEPS += \
./Mcal/NVIC/NVIC_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/NVIC/%.o Mcal/NVIC/%.su Mcal/NVIC/%.cyclo: ../Mcal/NVIC/%.c Mcal/NVIC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-NVIC

clean-Mcal-2f-NVIC:
	-$(RM) ./Mcal/NVIC/NVIC_interface.cyclo ./Mcal/NVIC/NVIC_interface.d ./Mcal/NVIC/NVIC_interface.o ./Mcal/NVIC/NVIC_interface.su

.PHONY: clean-Mcal-2f-NVIC

