/*
 * blink_3sec.c
 *
 * Created: 18-11-2025 17:54:53
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB=0B00100000;
    /* Replace with your application code */
    while (1) 
    {
		PORTB=0b00100000;
		_delay_ms(3000);
		PORTB=0b00000000;
		_delay_ms(3000);
    }
}

