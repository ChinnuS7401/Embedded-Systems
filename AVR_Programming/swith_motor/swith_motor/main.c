/*
 * swith_motor.c
 *
 * Created: 20-11-2025 21:08:13
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD|=((1<<DDD2)|(1<<DDD3)); //PORT D as output port
	DDRB&=~((1<<DDB5)|(1<<DDB4)); //PORT B as input port
	
    /* Replace with your application code */
    while (1) 
    {
		if (PINB &(1<<PB5))
		{
			PORTD|=(1<<PD2);
			PORTD&=~(1<<PD3);
		}
		else if (PINB&(1<<PB4))
		{
			PORTD&=~(1<<PD2);
			PORTD|=(1<<PD3);
		}
		else
		{
			PORTD&=~(1<<PD2);
			PORTD&=~(1<<PD3);
		}
	}
				
}

