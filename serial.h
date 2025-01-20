#ifndef SERIAL_H
#define SERIAL_H

// Base address for UART0 (specific to Raspberry Pi 3/4 or your emulator)
#define UART0_BASE 0x3F201000  // For Raspberry Pi 3/4 (adjust for your platform)

// UART0 Register Offsets (based on the hardware specification)
#define UART0_DR   (*(volatile unsigned int *)(UART0_BASE + 0x00))  // Data register
#define UART0_FR   (*(volatile unsigned int *)(UART0_BASE + 0x18))  // Flag register
#define UART0_IBRD (*(volatile unsigned int *)(UART0_BASE + 0x24))  // Integer baud rate divisor
#define UART0_FBRD (*(volatile unsigned int *)(UART0_BASE + 0x28))  // Fractional baud rate divisor
#define UART0_LCRH (*(volatile unsigned int *)(UART0_BASE + 0x2C))  // Line control register
#define UART0_CTL  (*(volatile unsigned int *)(UART0_BASE + 0x30))  // Control register

// UART Flag Register (FR) Bits
#define UART_FR_TXFF (1 << 5)  // Transmit FIFO full flag

// Function prototypes
void uart_init(void);
void uart_send(char c);
void uart_write(const char *msg);

#endif  // SERIAL_H
