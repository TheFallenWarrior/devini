#include <kernel/sys.h>
#include <stdio.h>
#include <string.h>

unsigned short *txtptr; //define the text pointer
int attrib = 0x07; //define the blank color
int csr_x = 0, csr_y = 0;

void move_csr(){ //update hardware cursor
    unsigned tmp;

    tmp = csr_y*80 + csr_x;

    outportb(0x3d4, 14);
    outportb(0x3d5, tmp >> 8);
    outportb(0x3d4, 15);
    outportb(0x3d5, tmp);
}

void cls(){
    unsigned blank = 0x20 | (attrib << 8);

    for(int i=0;i<25;i++) memsetw(txtptr + i*80, blank, 80);

    csr_x = 0;
    csr_y = 0;
    move_csr();
}

void scroll(){ // scroll the text on screen
    unsigned blank, tmp;

    blank = 0x20 | (attrib<<8); //set blank as a space with the "attrib" color

    if(csr_y>=25){
        tmp = csr_y - 24;
        memcpyw(txtptr, txtptr + tmp*80, (25-tmp)*160);
        memsetw(txtptr + (25-tmp)*80, blank, 80);
        csr_y = 24;
    }
}

void putch(unsigned char c){
    unsigned short *where;
    unsigned att = attrib << 8;

    if(c == 0x08){ //Backspace
        if(csr_x != 0) csr_x--;
    }

    else if(c == 0x09){ //Tab
        csr_x = (csr_x+8) & ~(7);
    }

    else if(c == '\r'){ //CR
        csr_x = 0;
    }

    else if(c == '\n'){ //LF
        csr_x = 0;
        csr_y++;
    }

    else if(c >= ' '){ //Any printable character
        where = txtptr + (csr_y*80 + csr_x);
        *where = c | att;
        csr_x++;
    }

    if(csr_x >= 80){ //Break the line if we hit the end
        csr_x = 0;
        csr_y++;
    }

    scroll();
    move_csr();
}

void settextcolor(unsigned char fg, unsigned char bg){
    attrib = (bg << 4) | (fg & 0x0f);
}

void init_vga(){
    txtptr = (unsigned short *)0x0b8000;
    cls();
    settextcolor(7, 0);
}