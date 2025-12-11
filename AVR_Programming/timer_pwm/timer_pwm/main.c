/*
 * timer_pwm.c
 *
 * Created: 29-11-2025 21:01:21
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	DDRD|=(1<<DDD6); //Configuring PD6 as output port
	
	//CONFIGURING FOR PHASE CORRECT PWM
	TCCR0A|=(1<<WGM00);
	TCCR0A&=~(1<<WGM01);
	//Configuring for non inverting mode
	TCCR0A|=(1<<COM0A1);
	TCCR0B&=~(1<<COM0A0);
	//Configuring for pre scalar=8
	TCCR0B&=~(1<<CS02);
	TCCR0B&=~(1<<CS00);
	TCCR0B|=(1<<CS01);
	
	//OCR0A=128;
	
    /* Replace with your application code */
    while (1) 
    {
		for (int i=0;i<=256;i++)
		{
			OCR0A=i;
			_delay_ms(10);
		}
		for(int i=256;i>0;i--)
		{
			OCR0A=i;
			_delay_ms(10);
		}
    }
}

