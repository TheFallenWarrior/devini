void outportb(unsigned short _port, unsigned short _data){
    __asm__ __volatile__ ("out %1, %0" : : "dN" (_port), "a" (_data));
}