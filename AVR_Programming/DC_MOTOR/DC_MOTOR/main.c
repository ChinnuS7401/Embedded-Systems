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
		// direction 2
		PORTD|=(1<<PD2);
		PORTD&=~(1<<PD3);
		_delay_ms(5000);
		
		//motor off
		PORTD&=~(1<<PD2);
		PORTD&=~(1<<PD3);
		_delay_ms(3000);
		
		//direction 1
		PORTD&=(1<<PD2);
		PORTD|=(1<<PD3);
		_delay_ms(5000);
		
		//invalid condition
		
		PORTD|=(1<<PD2);
		PORTD|=(1<<PD3);
		_delay_ms(3000);
		
    }
}

