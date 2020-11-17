#include <stdio.h>
#include <stdlib.h>

#define SUB         3

void input(int unit[], int mark[]) {
  int i;
  for (i = 0; i < SUB; i++) {
    printf("unit%d\'s number? : ", i+1);
    scanf("%d", &unit[i]);
    printf("unit%d\'s mark? : ", i+1);
    scanf("%d", &mark[i]);
  }
}

float calc(int unit[], int mark[]) {
  int mark_sum = 0, unit_sum = 0;
  int i;

  for (int i = 0; i < SUB; i++) {
    mark_sum += mark[i] * unit[i];
    unit_sum += unit[i];
  }

  return (float)mark_sum / (float)unit_sum;
}

int main(void) {
  int unit[SUB];
  int mark[SUB];
  float gpa;

  input(unit, mark);

  gpa = calc(unit, mark);
  printf("GPA : %.1f\n", gpa);
  
  return 0;
}
