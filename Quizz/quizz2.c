#include <stdio.h>
int a, b, c;
int f(int x) {
  return a*x;
}
int g() {
  int c;
  c=a;
  a=b;
  b=c;
  return c;
}
int main() {
  int x,y;
  a=2;
  b=3;
  c=4;
  x=f(a);
  y=g();
  printf("%d %d %d %d %d\n", x, y, a, b, c);
  return 0;
}
