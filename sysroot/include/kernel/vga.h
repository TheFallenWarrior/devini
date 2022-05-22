#ifndef __KERNEL_VGA_H
#define __KERNEL_VGA_H

#ifdef __cplusplus
extern "C" {
#endif

extern void cls();
extern void settextcolor(unsigned char bg, unsigned char fg);
extern void init_vga();
extern void putch(unsigned char c);

#ifdef __cplusplus
}
#endif

#endif