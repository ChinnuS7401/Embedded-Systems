/*
 * internal_pullup.c
 *
 * Created: 22-11-2025 20:47:22
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD&=~(1<<DDD2);// PORT D input port
	PORTD|=(1<<PD2);// making internal pull up resistor
	DDRB|=(1<<DDB5);//PORT B output port
    /* Replace with your application code */
    while (1) 
    {
		if (!(PIND&(1<<PD2)))
		{
		PORTB|=(1<<PB5);
		}
		else
		{
			PORTB&=~(1<<PB5);
		}
		
    }
}

