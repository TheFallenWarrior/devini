#ifndef __KERNEL_SYS_H
#define __KERNEL_SYS_H

#ifdef __cplusplus
extern "C" {
#endif

#define sti() __asm__ volatile("sti")
#define cli() __asm__ volatile("cli")
#define hlt() __asm__ volatile("hlt")

extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned short _data);

#ifdef __cplusplus
}
#endif

#endif