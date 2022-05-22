unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count){
    for(int i=0;i<count;i++) dest[i] = src[i];
    return dest;
}