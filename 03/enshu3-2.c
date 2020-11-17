#include <stdio.h>
#include <stdlib.h>

void jankenshoubu(int *results) {
  int com = rand()%3;
  int player;
  printf("gu-:0, tyoki:1, pa-:2\n");
  scanf("%d", &player);
  printf("you:");
  if (player==0) {
    printf("gu-, ");
  } else if (player==1) {
    printf("tyoki, ");
  } else if (player==2) {
    printf("pa-, ");
  }
  printf("com:");
  if (com==0) {
    printf("gu-\n");
  } else if (com==1) {
    printf("tyoki\n");
  } else if (com==2) {
    printf("pa-\n");
  }

  if (((player-com)%3==-1) || ((player-com)%3==2)) {
    printf("win.");
    results[0] += 1;
  } else if (((player-com)%3==-2) || ((player-com)%3==1)) {
    printf("lose.");
    results[1] += 1;
  } else {
    printf("draw.");
  }
}

int main(void) {
  int results[2] = {0, 0};
  int bon = 3;
  int winn = bon/2+1;
  while ((results[0] < winn) && (results[1] < winn)) {
    jankenshoubu(results); 
    printf("%d-%d\n\n",results[0], results[1]);
  } 
  if (results[0] > results[1]) {
    printf("You win!\n");
  } else {
    printf("You lose.\n");
  }
}
