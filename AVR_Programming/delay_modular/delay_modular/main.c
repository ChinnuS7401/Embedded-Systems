/*
 * delay_modular.c
 *
 * Created: 02-12-2025 20:25:22
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "delay.h" //user defined header files (usually in double quotes")


int main(void)
{
	DDRB|=(1<<DDB5); //PORT B output port
	timer0_init(); //user defined function for timer 0 configuration
    /* Replace with your application code */
    while (1) 
    {
		PORTB^=(1<<PB5);
		delay_ms(5000); //user defined function for delay
    }
}

