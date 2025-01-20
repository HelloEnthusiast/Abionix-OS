#include "serial.h"

// Initialize UART0 for communication
void uart_init(void) {
    // Disable UART0 while configuring
    UART0_CTL = 0;

    // Set baud rate (example for 9600 baud, adjust based on clock frequency)
    UART0_IBRD = 104;  // Integer part of baud rate divisor (for 16 MHz clock)
    UART0_FBRD = 11;   // Fractional part of baud rate divisor

    // Set line control (8 data bits, no parity, 1 stop bit)
    UART0_LCRH = 0x60;  // 0x60: 8 data bits, no parity, 1 stop bit

    // Enable UART0, TX, and RX
    UART0_CTL = 0x301;  // 0x301: Enable UART, Enable TX, Enable RX
}

// Send a single character via UART0
void uart_send(char c) {
    // Wait for the UART TX FIFO to not be full
    while (UART0_FR & UART_FR_TXFF) {
        // Wait here until the UART FIFO is not full
    }

    // Write the character to the data register to send it
    UART0_DR = c;
}

// Send a string of characters via UART0
void uart_write(const char *msg) {
    while (*msg) {
        uart_send(*msg);  // Send each character in the string
        msg++;
    }
}
