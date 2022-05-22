#include <string.h>
#include <kernel/vga.h>

void puts(unsigned char *str){
    for(int i=0;i<strlen(str);i++) putch(str[i]);
}