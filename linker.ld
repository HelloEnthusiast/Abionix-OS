ENTRY(kernel_main)

SECTIONS
{
    . = 0x10000; /* Starting address for the kernel */

    .text : {
        *(.text)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }
}
