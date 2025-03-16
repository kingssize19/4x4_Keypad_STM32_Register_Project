# Password Entry Application

**This application allows password entry using a keypad and displays the password in the terminal. The user enters a 4-digit password, and each character is hidden by an asterisk (*). After entering the password, the user can press the # key to display the entered password.**

**This simple application demonstrates password entry functionality using a keypad and UART communication in a microcontroller-based system.**


## Features 

* **Password Entry :** The user enters a 4-digit password, and each character is masked with \*.
* **Password Display :** The user can press the # key to reveal the entered password int the terminal.
* **Start Password Entry :** The password entry process starts by pressing the A key.
* **Reset :** The user can reset the password entry by pressing the A key again.
* **Password Length :** This application supports a 4-character password.


## Usage Instructions

**1. Start Entering the Password :**

* Press the A key to begin entering the password.
* The terminal will display the message "Enter password: ".

**2. Enter the Password :**

* As the user enters the password, each key press is replaced by an asterisk (*) on the terminal.
* Continue entering until you have entered 4 characters.

**3. View the Entered Password :**

* After entering the 4-character password, press the # key to display the password in the terminal.

**4. Reset the Password :**

* To reset the password entry, press the A key again to start the process over.

## Code Explanation

**1. GPIO and UART Initialization :**

* The gpio_init() and uart_init() functions are used to initialize the necessary hardware for communication.

**2. Start Password Entry :**

* When the A key is pressed, the password entry process begins, and the message "Enter password: " is sent to the terminal.

**3. Password Storage :**

* As the user enters each key, it is stored in the password array, and * is sent to the terminal to mask the character.

**4. Display Password :**

* Once 4 characters have been entered, pressing the # key will display the entered password in the terminal.


## Setup and Configuration

**1. Required Software :**

* Use an IDE (e.g. STM32CubeIDE) to develop the firmware.
* Ensure that UART and GPIO peripherals are correctly configured.

**2. Connections :**

* Connect the keypad to your microcontroller.
* Set up UART communication (typically using a USB-to-UART adapter).

**3. Compiling and Running :**

* Compile the code and upload it to your microcontroller.
* Connect to the terminal to test the password entry and display functionality.















