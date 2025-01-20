#ifndef DISPLAY_H
#define DISPLAY_H

#define DISPLAY_BASE 0x3F200000  // Example base address for the Raspberry Pi display (adjust if needed)

// Function prototypes
void display_init(void);
void display_write(char *str);

#endif
