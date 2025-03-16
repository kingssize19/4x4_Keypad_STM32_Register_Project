# 4x4_Keypad_STM32_Register_Project

**This project implements a 4x4 matrix keypad interface using STM32F446RE NUCLEO microcontroller. The pressed key values are transmitted via USART to a terminal window.**

## Features

* Reads key presses from 4x4 keypad
* Transmits key values via USART
* Debounce handling to avoid false readings
* Configurable GPIO pins for rows and columns

## Hardware Requirements

* STM32 microcontroller (F446RE NUCLEO)
* 4x4 Keypad
* PC with a serial terminal (e.g. Docklight, RealTerm, Termite)

## Wiring Diagram

| Keypad Pin | STM32 Pin (GPIOC) |
|--|--|
| Row 1 | PC0 |
| Row 2 | PC1 |
| Row 3 | PC2 |
| Row 4 | PC3 |
| Col 1 | PC5 |
| Col 2 | PC6 |
| Col 3 | PC7 |
| Col 4 | PC8 |


## Software Implementation

**1. GPIO Initialization**
* Rows set as output
  * Push-pull
  * No pull-up, pull-down
* Columns set as input
  * Pull up

**2. Keypad Scanning Algorithm**
* Set all rows HIGH initially
* Pull each row LOW and check columns
* If a column reads LOW, the corresponding key is pressed

**3. USART Communication**
* Configure USART2 (115200 baud, 8N1)
* Transmit the pressed key value
























