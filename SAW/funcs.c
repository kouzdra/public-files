# include <stdint.h>

int loop(int a, int n) {
  int i = 0;
  while (i != n) {
    a += i;
    i ++;
  }
  return a;
}

int loop10(int a) {
  return loop(a, 10);
}

int fact(int n) {
  if (n == 0)
    return 1;
  return fact (n-1);
}

int fact6 (int m) {
  return fact (6);
}

int fact_mul(int m, int n) {
  if (n == 0)
    return 1;
  return m * fact_mul (m, n-1);
}

int fact6_mul (int m) {
  return fact_mul (m, 6);
}
