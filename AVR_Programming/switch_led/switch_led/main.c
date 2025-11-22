/*
 * switch_led.c
 *
 * Created: 20-11-2025 20:42:43
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRD&=~(1<<DDD2); //PORT D as input port
	DDRB|=(1<<DDB5); //PORT B as output port
    /* Replace with your application code */
    while (1) 
    {
		if (PIND &(1<<PD2))
		{
			PORTB|=(1<<PB5);
		}
		else
		{
			PORTB&=~(1<<PB5);
		}
    }
}

