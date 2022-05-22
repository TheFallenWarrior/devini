//A lazy fix for displaying numbers
#include <kernel/vga.h>

void put_int(int n){
    if(n<0){
        putch('c');
        n = -n;
    }
    if(n>9) put_int(n/10);
    putch(n%10+'0');
}
