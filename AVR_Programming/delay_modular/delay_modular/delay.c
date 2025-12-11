/*
 * delay.c
 *
 * Created: 02-12-2025 20:31:40
 *  Author: chinn
 */ 
#include<avr/io.h>
#include "delay.h"

void timer0_init(void)
{
	//TIMER 0 CTC MODE
	TCNT0=0;
	OCR0A=249;
	TCCR0A|=(1<<WGM01);
	TCCR0A&=~(1<<WGM00);
	//PRESCALAR=64
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TCCR0B&=~(1<<CS02);
}
void delay_ms(uint16_t ms)
{
	
while(ms--)
{
	while(!(TIFR0&(1<<OCF0A))); //1 ms delay
	TIFR0|=(1<<OCF0A);
}
}
