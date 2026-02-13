/*
 * UART_tx1.c
 *
 * Created: 31-12-2025 21:05:04
 * Author : chinn
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	char a='A';
	UBRR0H=0;
	UBRR0L=103; //SET BAUD RATE 9600
	UCSR0C|=((1<<UCSZ01)|(1<<UCSZ00));
	UCSR0C&=~((1<<UPM00)|(1<<UPM01)|(1<<USBS0));// NO PARITY, 1 STOP BIT
	UCSR0B|=(1<<TXEN0);
    /* Replace with your application code */
    while (1) 
    {
		UDR0=a;
		while(!(UCSR0A&(1<<UDRE0)));// wait until the transmission is complete
		_delay_ms(1000);
    }
}

