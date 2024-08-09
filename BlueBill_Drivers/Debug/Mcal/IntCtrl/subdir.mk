################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/IntCtrl/IntCtrl.c 

OBJS += \
./Mcal/IntCtrl/IntCtrl.o 

C_DEPS += \
./Mcal/IntCtrl/IntCtrl.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/IntCtrl/%.o Mcal/IntCtrl/%.su Mcal/IntCtrl/%.cyclo: ../Mcal/IntCtrl/%.c Mcal/IntCtrl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Mcal-2f-IntCtrl

clean-Mcal-2f-IntCtrl:
	-$(RM) ./Mcal/IntCtrl/IntCtrl.cyclo ./Mcal/IntCtrl/IntCtrl.d ./Mcal/IntCtrl/IntCtrl.o ./Mcal/IntCtrl/IntCtrl.su

.PHONY: clean-Mcal-2f-IntCtrl

