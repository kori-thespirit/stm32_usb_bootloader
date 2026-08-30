################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../library/Flash_STMF1.c 

OBJS += \
./library/Flash_STMF1.o 

C_DEPS += \
./library/Flash_STMF1.d 


# Each subdirectory must supply rules for building sources it contributes
library/%.o library/%.su library/%.cyclo: ../library/%.c library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"G:/Project_B/Boot_Loader/library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-library

clean-library:
	-$(RM) ./library/Flash_STMF1.cyclo ./library/Flash_STMF1.d ./library/Flash_STMF1.o ./library/Flash_STMF1.su

.PHONY: clean-library

