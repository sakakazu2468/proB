#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void groundhogDay(int dayNumber) {
  int i, randNum;
  printf("day %d.\n", dayNumber);
  for (i = 0; i < 10; i++) {
    randNum = rand();
    if (randNum%2 == 1) {
      groundhogDay(dayNumber+1);
      break;
    }
  }
}

int main() {
  printf("I am a bad person...\n");
  groundhogDay(0);
  printf("I am a good person!\n");
  return 0;
}
