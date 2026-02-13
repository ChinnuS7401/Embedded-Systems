/*
 * BM280_SENSOR.c
 *
 * Created: 07-01-2026 10:17:18
 * Author : chinn
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

#define SLAVE PB2

void spi_init()
{
	/*GPIO configuration in master mode*/
	DDRB |= ((1 << DDB3) | (1 << DDB5) | (1 << DDB2)); // MOSI, SCK & SS - OUTPUT
	DDRB &= ~(1 << DDB4); //MISO - INPUT
	/*Enabling SPI, Selecting MASTER, Selecting 1 MHz Clock Frequency*/
	SPCR |= ((1 << SPE) |( 1 << MSTR) | (1 << SPR0));
	SPCR &= ~((1 << SPR1) |( 1 << CPHA) | (1 << CPOL));
}

int main(void)
{
	spi_init();
	uart_init();
	uint8_t chip_id;

	/**/
	while (1)
	{
		PORTB &= ~(1 << SLAVE); //Selecting Slave - Making Active Low
		/*sending register address*/
		SPDR = 0XD0 | 0X80;
		while(!(SPSR & (1 << SPIF))); //waiting for transferring.
		(void)SPDR; // for cleaning reading the garbage value received.
		
		SPDR = 0X00; //reading the actual data we need.
		while(!(SPSR & (1 << SPIF))); //waiting for data transfer.
		chip_id = SPDR;
		PORTB |= (1 << SLAVE); //De-selecting slave
		
		uartTx_string("Chip ID : ");
		uart_Txhex(chip_id);
		//PORTB |= (1 << SLAVE); //De-selecting slave
		
		
		//uartTx_number(chip_id);
		// reading data from bmp280
		PORTB &= ~(1 << PB2); 
		SPDR=0xF4 & 0X7F;
		while(!(SPSR & (1<<SPIF)));
		(void) SPDR;
		
		SPDR=0X27;
		while(!(SPSR & (1<<SPIF)));
		(void) SPDR;
		PORTB |= (1 << PB2); //De-selecting slave
		// from 0xFA
		PORTB &= ~(1 << PB2); 
		SPDR=0XFA|0X80;
		while(!(SPSR & (1<<SPIF)));
		(void)SPDR;
		SPDR=0X00;
		while(!(SPSR & (1<<SPIF)));
		uint8_t msb=SPDR;
		//uartTx_number(msb);
		
		//from 0xFB
		//SPDR=0XFB|0X80;
		//while(!(SPSR & (1<<SPIF)));
		//(void)SPDR;
		SPDR=0X00;
		while(!(SPSR & (1<<SPIF)));
		uint8_t lsb=SPDR;
		//uartTx_number(lsb);
		
		//from 0xFC
		
		//SPDR=0XFC|0X80;
		//while(!(SPSR & (1<<SPIF)));
		//(void)SPDR;
		SPDR=0X00;
		while(!(SPSR & (1<<SPIF)));
		uint8_t xlsb=SPDR;
		
		
		
		uartTx_string("Temperature : ");
		uint32_t temp=((uint32_t)msb << 12)|((uint32_t)lsb << 4)|((uint32_t)xlsb >> 4);
		uartTx_number(temp);
		_delay_ms(3000);
		PORTB |= (1 << PB2); //De-selecting slave
	}
}

