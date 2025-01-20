#include "commands.h"

// Function to handle terminal commands
void terminal(char *input) {
    // Check command and print corresponding message
    if (strcmp(input, "help") == 0) {
        print_to_terminal("Help: Available commands are help, aboutUs, date&time.\n");
    } else if (strcmp(input, "aboutUs") == 0) {
        print_to_terminal("About Us: This is the Abionix OS.\n");
    } else if (strcmp(input, "date&time") == 0) {
        print_to_terminal("Date & Time: (Insert actual date/time here)\n");
    } else {
        print_to_terminal("Invalid command.\n");
    }
}

// Function to print messages to terminal (or serial console)
void print_to_terminal(const char *msg) {
    serial_write(msg);  // Using the serial interface for output
}
