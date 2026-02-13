################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DRIVERSS/Src/stm32f401xx_gpio_driver.c 

OBJS += \
./DRIVERSS/Src/stm32f401xx_gpio_driver.o 

C_DEPS += \
./DRIVERSS/Src/stm32f401xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
DRIVERSS/Src/%.o DRIVERSS/Src/%.su DRIVERSS/Src/%.cyclo: ../DRIVERSS/Src/%.c DRIVERSS/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401C_DISCO -DSTM32F4 -DSTM32F401VCTx -c -I../Inc -I"C:/Users/chinn/OneDrive/Desktop/Embedded_Systems/stm32f401xx/DRIVER_DEVELOPMENT/DRIVERSS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DRIVERSS-2f-Src

clean-DRIVERSS-2f-Src:
	-$(RM) ./DRIVERSS/Src/stm32f401xx_gpio_driver.cyclo ./DRIVERSS/Src/stm32f401xx_gpio_driver.d ./DRIVERSS/Src/stm32f401xx_gpio_driver.o ./DRIVERSS/Src/stm32f401xx_gpio_driver.su

.PHONY: clean-DRIVERSS-2f-Src

