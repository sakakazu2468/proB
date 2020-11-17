#include <stdio.h>

int main(void) {
  int results[4] = {70, 75, 50, 90};
  int *ptr = results;
  int i, sum = 0;
  double ans;
  for (i = 0; i < 4; i++) {
    sum += *(ptr + i);
  }
  ans = (double)sum/4.0;
  printf("avg=%.2f\n", ans);
}
