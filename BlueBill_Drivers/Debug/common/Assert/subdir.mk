################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../common/Assert/assert.c 

OBJS += \
./common/Assert/assert.o 

C_DEPS += \
./common/Assert/assert.d 


# Each subdirectory must supply rules for building sources it contributes
common/Assert/%.o common/Assert/%.su common/Assert/%.cyclo: ../common/Assert/%.c common/Assert/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-common-2f-Assert

clean-common-2f-Assert:
	-$(RM) ./common/Assert/assert.cyclo ./common/Assert/assert.d ./common/Assert/assert.o ./common/Assert/assert.su

.PHONY: clean-common-2f-Assert

