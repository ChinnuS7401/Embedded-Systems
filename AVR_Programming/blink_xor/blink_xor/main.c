/*
 * blink_xor.c
 *
 * Created: 18-11-2025 19:21:08
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD|=(1<<DDD2);
    /* Replace with your application code */
    while (1) 
    {
		PORTD^=(1<<PD2);
		_delay_ms(1000);
    }
}

