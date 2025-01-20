// uart.c
#include "uart.h"

#define UART0_BASE 0x3F201000

void uart_init() {
    // Simplified UART initialization for educational purposes
}

void uart_putc(char c) {
    while (*(volatile unsigned int *)(UART0_BASE + 0x18) & 0x20);
    *(volatile unsigned int *)(UART0_BASE) = c;
}

void uart_puts(const char *str) {
    while (*str) {
        uart_putc(*str++);
    }
}

char uart_getc() {
    while (*(volatile unsigned int *)(UART0_BASE + 0x18) & 0x10);
    return *(volatile unsigned int *)(UART0_BASE);
}

void uart_gets(char *buffer, int maxlen) {
    int i = 0;
    char c;
    while (i < maxlen - 1) {
        c = uart_getc();
        if (c == '\n' || c == '\r') break;
        buffer[i++] = c;
        uart_putc(c); // Echo
    }
    buffer[i] = '\0';
}
