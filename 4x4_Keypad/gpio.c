#include "gpio.h"



char keypad[ROWS][COLS] = {
		{'1', '2', '3', 'A'},
		{'4', '5', '6', 'B'},
		{'7', '8', '9', 'C'},
		{'*', '0', '#', 'D'},
};

uint8_t row_pins[ROWS] = {0, 1, 2, 3};
uint8_t col_pins[COLS] = {5, 6, 7, 8};



void gpio_init(void)
{
    RCC->AHB1ENR |= (1U << 2);     // Enable GPIOC clock

    // Configure row pins (PC0-PC3) as output
    for (int i = 0; i < ROWS; ++i) {
        GPIOC->MODER |= (1U << (row_pins[i] * 2));   // Set as output mode
        GPIOC->OTYPER &= ~(1U << (row_pins[i]));     // Push-pull mode
        GPIOC->PUPDR &= ~(3U << (row_pins[i] * 2));  // No pull-up, no pull-down
    }

    // Configure column pins (PC5-PC8) as input with pull-up
    for (int i = 0; i < COLS; ++i) {
        GPIOC->MODER &= ~(3U << (col_pins[i] * 2));  // Set as input mode
        GPIOC->PUPDR |= (1U << (col_pins[i] * 2));   // Enable pull-up resistor
    }
}

char keypad_read(void)
{
    for (int row = 0; row < ROWS; row++) {
        // Set all rows HIGH
        GPIOC->BSRR = (0xF << 0);
        GPIOC->BSRR = (1 << (row_pins[row] + 16)); // Set current row LOW

        // Read columns
        for (int col = 0; col < COLS; col++) {
            if ((GPIOC->IDR & (1 << col_pins[col])) == 0) { // If LOW detected

                // Debounce: Wait for 20ms and check again
                for (volatile int i = 0; i < 20000; i++);

                if ((GPIOC->IDR & (1 << col_pins[col])) == 0) { // Confirm key press
                    char pressedKey = keypad[row][col];

                    while ((GPIOC->IDR & (1U << col_pins[col])) == 0); // Wait for key release

                    return pressedKey;
                }
            }
        }
    }

    return 0;
}


