/*
 * BMP280.c
 *
 * Created: 06-01-2026 20:44:31
 * Author : chinn
 */ 

#include <avr/io.h>
#include "uart.h"
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	UART_Init();
	uint8_t chip_id;
	
	//STEP1: SET PIN DIRECTION,
	DDRB|=(1<<DDB3)|(1<<DDB5)|(1<<DDB2);//MOSI,SCK,SS-OUTPUT PIN
	DDRB&=~(1<<DDB4);//MISO-INPUT PIN
	//STEP2: ENABLE SPI AND CONFIGURE AS MASTER
	SPCR|=(1<<SPIE)|(1<<MSTR)|(1<<SPR0); //SPIE=1,MSTR=1,SPR0=1
	SPCR&=~((1<<SPR1)|(1<<CPOL)|(1<<CPHA));//SPR1=0,CPOL=0,CPHA=0
	
    
	
	/* Replace with your application code */
    while (1) 
    {
		PORTB&=~(1<<PB2);//SELECTING SLAVE
		SPDR=(0XD0|0X80);//MSB=1 TO READ
		while(!(SPSR & (1<<SPIF)));//FLAG SET
		(void)SPDR;//READING SPDR , FOR DUMMY GARBAGE VALUE
		
		SPDR=0X00;// SENDING DUMMY TO READ THE DATA FROM BMP280
		while(!(SPSR & (1<<SPIF)));// WAITING UNTILL FLAG SET
		chip_id=SPDR;//READING CHIP ID
		PORTB|=(1<<PB2);//DE SELECTING SLAVE
		UART_TxHex(chip_id);
		_delay_ms(1000);
		
		
		
    }
}

