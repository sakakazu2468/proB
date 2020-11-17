#include <stdio.h>
#include <string.h>

char* addName(char* familyname, char* firstname, char* name) {
  int i;
  int j;
  for (i = 0; i < strlen(familyname); i++) {
    name[i] = familyname[i];
  }
  name[i] = ' ';
  for (j = 0; j < strlen(firstname); j++) {
    name[i+j+1] = firstname[j];
  }
  name[i+j+1] = '\0';
}

int main(void) {
  char familyname[256];
  char firstname[256];
  char name[10];

  printf("input familyname:");
  scanf("%s", familyname);
  printf("input firstname:");
  scanf("%s", firstname);

  if (strlen(familyname)+strlen(firstname) < 10) {
    addName(familyname, firstname, name);
    printf("name: %s\n", name);
  } else {
    printf("too long!\n");
  }
  
  return 0;
}
