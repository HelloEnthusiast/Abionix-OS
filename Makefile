CC = arm-none-eabi-gcc
CFLAGS = -nostdlib -ffreestanding -O2 -g
LDFLAGS = -T linker.ld

# Objects
OBJS = kernel.o serial.o

# Target output
TARGET = kernel.img

$(TARGET): $(OBJS)
    $(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

# Kernel object compilation
kernel.o: kernel.c
    $(CC) $(CFLAGS) -c kernel.c -o kernel.o

# Serial object compilation
serial.o: serial.c serial.h
    $(CC) $(CFLAGS) -c serial.c -o serial.o

clean:
    rm -f $(OBJS) $(TARGET)
