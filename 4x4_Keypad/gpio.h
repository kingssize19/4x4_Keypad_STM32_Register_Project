#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"


#define ROWS	4
#define COLS	4


extern char keypad[ROWS][COLS];

void gpio_init(void);
char keypad_read(void);


#endif

