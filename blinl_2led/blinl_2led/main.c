/*
 * blinl_2led.c
 *
 * Created: 18-11-2025 19:27:07
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<DDD2)|(1<<DDD3);
    /* Replace with your application code */
    while (1) 
    {
		// LED1 0N and LED 2 OFF
		PORTD|=(1<<PD2);
		PORTD&=~(1<<PD3);
		_delay_ms(5000);
		
		//LED 1 OFF and LED 2 OFF
		PORTD&=~(1<<PD2);
		PORTD&=~(1<<PD3);
		_delay_ms(3000);
		
		//LED 1 OFF and LED 2 ON
		PORTD&=(1<<PD2);
		PORTD|=(1<<PD3);
		_delay_ms(5000);
		
		//LED 1 ON and LED 2 ON
		
		PORTD|=(1<<PD2);
		PORTD|=(1<<PD3);
		_delay_ms(3000);
		
    }
}

