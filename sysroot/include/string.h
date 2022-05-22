#ifndef __STRING_H
#define __STRING_H

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);

#ifdef __cplusplus
}
#endif

#endif