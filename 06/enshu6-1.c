#include <stdio.h>
#include <string.h>

#define NUM 4

struct team_data {
  char name[256];
  int points;
};

int findTopScorer(struct team_data *p) {
  int i;
  int max = -1;
  int ret;
  for (i = 0; i < NUM; i++) {
    if ((p+i)->points > max) {
      ret = i;
      max = (p+i)->points;
    }
  }
  return ret;
}

int main(void) {
  struct team_data soccer_team[NUM];
  struct team_data *p;
  int top_scorer;

  p = soccer_team;
  strcpy((p+0)->name, "kawasima");
  (p+0)->points = 0;
  strcpy((p+1)->name, "asano");
  (p+1)->points = 4;
  strcpy((p+2)->name, "nagatomo");
  (p+2)->points = 1;
  strcpy((p+3)->name, "haraguchi");
  (p+3)->points = 2;
  top_scorer = findTopScorer(p);
  printf("Top scorer is %s\n", (p+top_scorer)->name);
   
  return 0;
}
