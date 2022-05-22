unsigned short *memcpyw(unsigned short *dest, const unsigned short *src, int count){
    for(int i=0;i<count;i++) dest[i] = src[i];
    return dest;
}