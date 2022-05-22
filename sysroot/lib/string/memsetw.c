unsigned short *memsetw(unsigned short *dest, unsigned short val, int count){
    for(int i=0;i<count;i++) dest[i] = val;
    return dest;
}