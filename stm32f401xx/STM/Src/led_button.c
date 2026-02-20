/*
 * led_button.c
 *
 *  Created on: 20-Feb-2026
 *      Author: chinn
 */
#include "STM32F401xx_GPIO_DRIVER.h"

#define BTN_PRESSED  0  // Button is active low on Nucleo

void delay(void)
{
    for (uint32_t i = 0; i < 250000; i++);  // Debounce delay
}

int main(void)
{
    GPIO_Handle_t GpioLed, GpioBtn;

    // Configure LED (PA5)
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    // Configure Button (PC13 on Nucleo)
    GpioBtn.pGPIOx = GPIOC;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    // Enable clocks
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_PeriClockControl(GPIOC, ENABLE);

    // Initialize pins
    GPIO_Init(&GpioLed);
    GPIO_Init(&GpioBtn);

    while (1)
    {
        if (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == BTN_PRESSED)
        {
            delay();  // Debounce
            GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
        }
    }

    return 0;
}

