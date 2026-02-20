################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.c 

OBJS += \
./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.o 

C_DEPS += \
./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVER_DEV/Src/%.o DRIVER_DEV/Src/%.su DRIVER_DEV/Src/%.cyclo: ../DRIVER_DEV/Src/%.c DRIVER_DEV/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401C_DISCO -DSTM32F4 -DSTM32F401VCTx -c -I../Inc -I"C:/Users/chinn/OneDrive/Desktop/Embedded_Systems/stm32f401xx/STM/DRIVER_DEV/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DRIVER_DEV-2f-Src

clean-DRIVER_DEV-2f-Src:
	-$(RM) ./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.cyclo ./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.d ./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.o ./DRIVER_DEV/Src/STM32F401xx_GPIO_DRIVER.su

.PHONY: clean-DRIVER_DEV-2f-Src

