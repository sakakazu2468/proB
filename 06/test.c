#include <stdio.h>

struct Student {
  char studnum[16];
  char name[256];
  int age;
  char email[50];

};


int main(void) {
  struct Student PA_class[250] = {{"C0114553", "sato jiro", 22, "c0114553ab"}, {"C0114557", "simizu kentaro", 22, "c0114557fk"}, {"C0114556", "watanabe akira", 21, "c9114556gy"}};
  struct Student *p;
  struct Student hoge = {"C0114553", "sato jiro", 22, "c0114553ab"};
  int i;
  p = PA_class;
  printf("%s\n", hoge.email);
  printf("%s\n", (&hoge)->email);
  printf("Student number: %s\n", (p+1)->studnum);
  for ( i = 0; i <= 2; i++) {
    printf("Name: %s\n",PA_class[i].name);
    printf("Age: %d\n",(p+i)->age);
    printf("Email: %s\n",(p+i)->email);
 }
  return 0;
}
