#include <stdint.h>
#include <assert.h>

int const BITS = 32;
typedef uint32_t my_uint_t;
#ifdef RUN
#include <stdio.h>
//typedef unsigned long long int myuint_t;
#else
#endif


// returns the index of the first non-zero bit
uint8_t imp(my_uint_t i) {
    char n = 1;
    if (!(i & 0xffff)) { n += 16; i >>= 16; }
    if (!(i & 0x00ff)) { n += 8;  i >>= 8; }
    if (!(i & 0x000f)) { n += 4;  i >>= 4; }
    if (!(i & 0x0003)) { n += 2;  i >>= 2; }
    return (i) ? (n+((i+1) & 0x01)) : 0;
}

uint8_t imp_nobranch(my_uint_t i) {
  char n = 1;
  int s1 = !(i & 0xffff) << 4;
  n += s1; i >>= s1;
  int s2 = !(i & 0x00ff) << 3;
  n += s2;  i >>= s2;
  int s3 = !(i & 0x000f) << 2;
  n += s3;  i >>= s3;
  int s4 = !(i & 0x0003) << 1;
  n += s4;  i >>= s4;
  // Still does have one branch...
  return (i) ? (n+((i+1) & 0x01)) : 0;
}

uint8_t ref(my_uint_t word) {
    int i = 0;
    if(!word)
        return 0;
    for(int cnt = 0; cnt < 32; cnt++)
        if(((1ul << i++) & word) != 0)
            return i;
    return 0; // notreached
}

uint8_t musl (my_uint_t x)
{
  static const char debruijn32[32] = {
    0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13,
    31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
  };
  return x ? debruijn32[(x&-x)*0x076be629 >> 27]+1 : 0;
}

