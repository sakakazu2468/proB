#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const* argv[])
{
  double a[15], b[15], sum;
  int n;
  printf("How many numbers? ");
  scanf ("%d", &n);
  if (n > 15){
    printf("n must be less than 15¥n");
    exit(1);
  }
  for (int i=0; i<n; i++){
    printf("Input adim[%d] = ", i);
    scanf ("%lf", &a[i]);
    printf("Input bdim[%d] = ", i);
    scanf ("%lf", &b[i]);
  }
  sum = 0;
  for (int i=0; i<n; i++){
    sum += a[i]*b[i];
  }
  printf("Answer = %f \n", sum);
  return 0;
}
