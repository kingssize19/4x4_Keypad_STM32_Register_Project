#include "gpio.h"
#include "uart.h"

int main(void)
{
	gpio_init();

	uart_init();

	while (1) {
		char key = keypad_read();

		if (key != 0) {
			send_char(key);
			send_char('\n');
		}

	}
}
