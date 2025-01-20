// boot.S
.global _start

.section .text
_start:
    // Initialize stack pointer
    ldr x0, =stack_top
    mov sp, x0

    // Call the kernel entry point
    bl kernel_main

halt:
    b halt

.section .bss
.align 12
stack:
    .space 4096
stack_top:
