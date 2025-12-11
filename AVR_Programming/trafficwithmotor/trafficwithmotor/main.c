/*
 * traffic_motor.c
 *
 * Created: 24-11-2025 21:54:15
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void redlight();
void yellowlight();
void greenlight();
void motor();
void clearlight();


int main(void)
{
	DDRD&=~(1<<DDD1);  //port D input port
	PORTD|=(1<<PD1); // internal pull up
	DDRB|=(1<<DDB1)|(1<<DDB2)|(1<<DDB3)|(1<<DDB4)|(1<<DDB5);// port B output port
    
    while (1) 
    {
		
		if (!(PIND&(1<<PD1)))
		{
			redlight();
			motor();
		}
		else
		{
		redlight();
		_delay_ms(5000);
		yellowlight();
		_delay_ms(2000);
		greenlight();
		_delay_ms(5000);
		yellowlight();
		_delay_ms(2000);
		}
    }
}
void redlight()
{
	clearlight();
	PORTB|=(1<<PB3);
	//_delay_ms(5000);
}
void greenlight()
{
	clearlight();
	PORTB|=(1<<PB1);
	//_delay_ms(5000);
}
void yellowlight()
{
	clearlight();
	PORTB|=(1<<PB2);
	//_delay_ms(2000);
}
void motor()
{
	redlight();
	PORTB|=(1<<PB4);
	PORTB&=~(1<<PB5);
	_delay_ms(3000);
	PORTB&=~(1<<PB4);
	PORTB|=(1<<PB5);
	_delay_ms(3000);
	PORTB&=~(1<<PB4);
	PORTB&=~(1<<PB5);
}
void clearlight()
{
	PORTB&=~((1<<PB3)|(1<<PB2)|(1<<PB1));
}
	

