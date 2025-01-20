#include "uart.h"
#include "display.h"
#include "commands.h"

void kernel_main(void) {
    // Initialize UART for communication
    uart_init();

    // Initialize framebuffer (to set up display)
    framebuffer_init();

    // Initialize the terminal (if applicable)
    uart_write("Welcome to Abionix OS!\n");
    uart_write("Type 'help' for a list of commands.\n");

    // Display the welcome message
    write_to_display("Welcome to Abionix OS!\n");

    // Enter the main loop
    char input[100];

    while (1) {
        uart_write("> ");  // Show prompt
        uart_read(input, sizeof(input));  // Read user input (implementation depends on UART)
        process_command(input);  // Process the entered command
    }
}
