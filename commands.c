#include "commands.h"
#include "uart.h"
#include "display.h"
#include <string.h>

// Declare the available commands and their functions
void command_help(void);
void command_aboutUs(void);
void command_datetime(void);

// Command function table
typedef struct {
    char *command;
    void (*function)(void);
} command_t;

command_t commands[] = {
    {"help", command_help},
    {"aboutUs", command_aboutUs},
    {"date&time", command_datetime},
    {NULL, NULL}  // End of the command list
};

// Function to process the input command
void process_command(char *input) {
    for (int i = 0; commands[i].command != NULL; i++) {
        if (strcmp(input, commands[i].command) == 0) {
            commands[i].function();
            return;
        }
    }
    // If no command matched
    uart_write("Invalid command. Type 'help' for a list of commands.\n");
}

// Implementation of the 'help' command
void command_help(void) {
    uart_write("Available commands:\n");
    uart_write("  help        - Show available commands\n");
    uart_write("  aboutUs     - Learn more about this OS\n");
    uart_write("  date&time   - Display current date and time\n");
}

// Implementation of the 'aboutUs' command
void command_aboutUs(void) {
    uart_write("Abionix OS\n");
    uart_write("This is a lightweight operating system for embedded devices.\n");
    uart_write("Developed by the Abionix team.\n");
}

// Implementation of the 'date&time' command
void command_datetime(void) {
    uart_write("Current date and time:\n");
    // For now, you can just display a static date/time for simplicity
    uart_write("2025-01-13 10:00:00\n");
}
