#include <stdint.h>

#ifdef RUN
#include <stdio.h>
#endif

typedef int32_t my_int;

my_int ref (my_int n) {
  return n/2;
}

my_int imp (my_int n) {
  return n>>1;
}


#ifdef RUN

void test (my_int n) {
  printf ("div2(%d)=%d div2_opt(%d)=%d\n", n, ref(n), n, imp(n));
}

int main () {
  test (2);
  test (3);
  test (0xc3);
  test (0x3f);
  test (0x7f);
  test (0x80);
  return 0;
}
#endif
