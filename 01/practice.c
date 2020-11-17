#include <stdio.h>

int main(int argc, char const* argv[])
{

  int a=3, b=4;
  int *p1, *p2;
  p1=&a, p2=&b;
  a = (a+b)/2;
  *p2 += 1;
  printf("p1 = %p\n", p1);
  printf("p2 = %p\n", p2);
  printf("*p1 = %d\n", *p1);
  printf("*p2 = %d\n", *p2);
  p1 += 1;
  printf("p1 = %p\n", p1);
  printf("p2 = %p\n", p2);
  printf("*p1 = %d\n", *p1);
  printf("*p2 = %d\n", *p2);
  return 0;
}
