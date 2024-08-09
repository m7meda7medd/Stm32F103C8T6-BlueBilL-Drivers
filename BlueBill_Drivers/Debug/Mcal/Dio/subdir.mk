################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Dio/DIO_interface.c 

OBJS += \
./Mcal/Dio/DIO_interface.o 

C_DEPS += \
./Mcal/Dio/DIO_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Dio/%.o Mcal/Dio/%.su Mcal/Dio/%.cyclo: ../Mcal/Dio/%.c Mcal/Dio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-Dio

clean-Mcal-2f-Dio:
	-$(RM) ./Mcal/Dio/DIO_interface.cyclo ./Mcal/Dio/DIO_interface.d ./Mcal/Dio/DIO_interface.o ./Mcal/Dio/DIO_interface.su

.PHONY: clean-Mcal-2f-Dio

