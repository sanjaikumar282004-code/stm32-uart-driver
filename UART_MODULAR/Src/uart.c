/*
 * uart.c
 *
 *  Created on: May 9, 2026
 *      Author: sanja
 */
#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define LED     (1U<<5)
#define PERIPHCLK 16000000
#define BAUDRATE 115200

void uart_init()
{
	//Enable clock for GPIOA AND GPIOC
		RCC->AHB1ENR |= GPIOAEN;

		//set pa2 to alternate function mode
		GPIOA->MODER |= (1U<<5);
		GPIOA->MODER &= ~(1U<<4);

		RCC->APB1ENR |= (1U<<17);

		GPIOA->AFR[0] &= ~(1U<<11);
		GPIOA->AFR[0] |= (1U<<10);
		GPIOA->AFR[0] |= (1U<<9);
		GPIOA->AFR[0] |= (1U<<8);

		USART2->BRR = (PERIPHCLK + (BAUDRATE/2))/BAUDRATE;

		USART2->CR1 |= (1U<<13);
		USART2->CR1 |= (1U<<3);
}

void uart_write(int ch)
{
	while((USART2->SR & (1U<<7))==0){}

	USART2->DR = (ch & 0xff);

}
