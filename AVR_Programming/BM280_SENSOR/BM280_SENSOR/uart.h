/*
 * uart.h
 *
 * Created: 07-01-2026 10:19:40
 *  Author: chinn
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#ifndef UART_H_
#define UART_H_

void uart_init();
void uart_Txhex(uint8_t value);
void uartTx_string(char *str);
void uartTx_number(uint8_t);



#endif /* UART_H_ */