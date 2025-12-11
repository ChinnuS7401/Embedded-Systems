/*
 * external_interrupt.c
 *
 * Created: 06-12-2025 20:19:23
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect) //interrupt service routine for external interrupt 0
{
	PORTB^=(1<<PB5);//toggle led
	_delay_ms(10000);
}
int main(void)
{
	sei(); //enabling global interrupt
	EIFR|=(1<<INTF0); //clear interrupt flag initially
	DDRB|=(1<<DDB5)|(1<<DDB4);// making port b as output port
	DDRD&=~(1<<DDD2);
	EIMSK|=(1<<INT0);// enabling external interrupt 0
	EICRA|=(1<<ISC00)|(1<<ISC01);// configuring interrupt for rising edge
    /* Replace with your application code */
    while (1) 
    {
		PORTB&=~(1<<PB5);
		PORTB^=(1<<PB4);
		_delay_ms(1000);
    }
}

