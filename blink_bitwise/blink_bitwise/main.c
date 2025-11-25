/*
 * blink_bitwise.c
 *
 * Created: 18-11-2025 19:09:32
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<DDD2);// P2 of portD as output port
    /* Replace with your application code */
    while (1) 
    {
		PORTD|=(1<<PD2);// led on
		_delay_ms(1000);
		PORTD&=~(1<<PD2);//led off
		_delay_ms(1000);
    }
}

