/*
 * timer_ctc.c
 *
 * Created: 27-11-2025 21:07:38
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	
	for (int i=0; i<100; i++)
	{
		while(!(TIFR0&(1<<OCF0A)))
		TIFR0|=(1<<OCF0A);
	}
	
	
}
int main(void)
{
	TCNT0=0; //
	OCR0A=0x9C;
	TCCR0A&=~(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	TCCR0B|=(1<<CS02|1<<CS00);
	TCCR0B&=~(1<<CS01);
	
	DDRB|=(1<<DDB5);
		
		    /* Replace with your application code */
		    while (1) 
		    {
				PORTB^=(1<<PB5);
				delay_1s();
		
    }
}

