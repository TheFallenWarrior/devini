#ifndef __STDIO_H
#define __STDIO_H

#ifdef __cplusplus
extern "C" {
#endif

extern void puts(unsigned char *str);
extern void putint(int n);
//extern int printf(const char* __restrict str, ...); //This is not ready yet

#ifdef __cplusplus
}
#endif

#endif
