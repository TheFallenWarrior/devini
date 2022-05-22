;Kernel entry point.
global start

section .multiboot
[BITS 32]
mbh_start:
    dd 0xe85250d6           ;magic number
    dd 0                    ;plataform
    dd mbh_end - mbh_start  ;header length

    ;checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (mbh_end - mbh_start))

    dw 0
    dw 0
    dd 8

mbh_end:

section .text
[BITS 32]

start:
    mov esp, stack_top
    extern main
    call main
    hlt

section .bss
stack_bottom:
    resb 4096 * 4

stack_top: