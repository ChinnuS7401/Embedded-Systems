/*
 * trafficlight.c
 *
 * Created: 20-11-2025 10:53:09
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<DDD2)|(1<<DDD3)|(1<<DDD4);
    /* Replace with your application code */
    while (1) 
    {   // green led  on
		PORTD|=(1<<PB2);
		PORTD&=~(1<<PB3);
		PORTD&=~(1<<PB4);
		_delay_ms(3000);
		
		//yellow led on
		PORTD&=~(1<<PB2);
		PORTD|=(1<<PB3);
		PORTD&=~(1<<PB4);
		_delay_ms(1000);
		
		//red led on
		PORTD&=~(1<<PB2);
		PORTD&=~(1<<PB3);
		PORTD|=(1<<PB4);
		_delay_ms(5000);
		
    }
}

