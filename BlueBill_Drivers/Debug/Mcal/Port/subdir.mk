################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Port/PORT_config.c \
../Mcal/Port/PORT_interface.c 

OBJS += \
./Mcal/Port/PORT_config.o \
./Mcal/Port/PORT_interface.o 

C_DEPS += \
./Mcal/Port/PORT_config.d \
./Mcal/Port/PORT_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Port/%.o Mcal/Port/%.su Mcal/Port/%.cyclo: ../Mcal/Port/%.c Mcal/Port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-Port

clean-Mcal-2f-Port:
	-$(RM) ./Mcal/Port/PORT_config.cyclo ./Mcal/Port/PORT_config.d ./Mcal/Port/PORT_config.o ./Mcal/Port/PORT_config.su ./Mcal/Port/PORT_interface.cyclo ./Mcal/Port/PORT_interface.d ./Mcal/Port/PORT_interface.o ./Mcal/Port/PORT_interface.su

.PHONY: clean-Mcal-2f-Port

