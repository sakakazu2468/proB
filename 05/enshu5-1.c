#include <stdio.h>
#include <string.h>

struct family {
  char familyName[256];
  char firstName[256];
  int age;
} father, mother;

int main(void) {
  struct family child;
  strcpy(father.familyName, "Kouka");
  strcpy(father.firstName, "Tarou");
  father.age = 35;
  strcpy(mother.familyName, "Kouka");
  strcpy(mother.firstName, "Hanako");
  mother.age = 30;

  child = mother;
  strcpy(child.firstName, "ichirou");
  child.age = 0;
  
  printf("Happy to have a child ! \n");
  printf("name: %s\n", child.firstName);
  printf("age: %d\n", child.age);

  return 0;
} 
