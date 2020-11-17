#include <stdio.h>

typedef struct TVviewers {
  char name[256];
  char channel[256];
  double percent;
} TVVIEWERS;

TVVIEWERS changePercentage(TVVIEWERS programs, double new_percent) {
  programs.percent = new_percent; 
  return programs;
}

int main(void) {
  TVVIEWERS programs[5] = {{"todaio", "TBS", 12.34}, {"kiringakuru", "NHK", 10.56}, {"yoshimotoshinkigeki", "TVK", 9.81}, {"gurunai", "nittere", 15.14}, {"ohasuta", "TVtokyo", 9.99}};
  TVVIEWERS ret_per;

  ret_per = changePercentage(programs[3], 17.65);
  printf("new percentage is %.2f\n", ret_per.percent);

  return 0;
}
