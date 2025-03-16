#include "uart.h"


void uart_init(void)
{
	//GPIOA Enable
	RCC->AHB1ENR |= (1U << 0);

	// USART2 Enable
	RCC->APB1ENR |= (1U << 17);

	// Alternate Function Mode
	GPIOA->MODER |= (2U << 4);
	// AF7 for Usart2 TX
	GPIOA->AFR[0] |= (7U << 8);

	// Transmitter Enable
	USART2->CR1 |= (1U << 3);
	// USART Enable
	USART2->CR1 |= (1U << 13);

	// Baudrate 115200
	USART2->BRR = 0x8B;

}

void send_char(char c)
{
	while (!(USART2->SR & (1U << 7)));		// is TX empty?
	USART2->DR = c; // write value
}

void send_string(char* str)
{
	while (*str) {
		send_char(*str++);
	}
}

