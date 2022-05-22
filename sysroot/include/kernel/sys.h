#ifndef __KERNEL_SYS_H
#define __KERNEL_SYS_H

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned char inportb(unsigned short _port);
extern void outportb(unsigned short _port, unsigned short _data);

#ifdef __cplusplus
}
#endif

#endif