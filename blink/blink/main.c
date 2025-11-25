/*
 * blink.c
 *
 * Created: 18-11-2025 12:42:05
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   DDRD=0b00000100; //Second pin of port D as output port.
    while (1) 
    {
	PORTD=0B00000100; //led on
	_delay_ms(1000);
	PORTD=0B00000000; //led off
	_delay_ms(1000);
		
    }
}

