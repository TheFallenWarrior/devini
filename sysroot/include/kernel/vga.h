#ifndef __KERNEL_VGA_H
#define __KERNEL_VGA_H

#ifdef __cplusplus
extern "C" {
#endif

extern void cls();
extern void settextcolor(unsigned char bg, unsigned char fg);
extern void init_vga();
extern void putch(unsigned char c);

#define VGA_BLACK   0x0
#define VGA_BLUE    0x1
#define VGA_GREEN   0x2
#define VGA_CYAN    0x3
#define VGA_RED     0x4
#define VGA_MAGENTA 0x5
#define VGA_YELLOW  0x6
#define VGA_WHITE   0x7
#define VGA_GRAY            0x8
#define VGA_BRIGHT_BLUE     0x9
#define VGA_BRIGHT_GREEN    0xa
#define VGA_BRIGHT_CYAN     0xb
#define VGA_BRIGHT_RED      0xc
#define VGA_PINK            0xd
#define VGA_BRIGHT_YELLOW   0xe
#define VGA_BRIGHT_WHITE    0xf

#ifdef __cplusplus
}
#endif

#endif