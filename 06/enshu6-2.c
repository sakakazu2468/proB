#include <stdio.h>
#include <string.h>

typedef struct {
  char fullname[256];
  char position[256];
  int age;
  int salary;
} Employee;

void promoteEmployee(Employee *p, char *new_position, int new_salary) {
  strcpy(p->position, new_position);
  p->salary = new_salary;
}

int main(void) {
  Employee human = {"Sakamoto Kazuki", "katyou", 24, 300000};
  Employee *p;
  p = &human;
  char new_position[256] = "butyou";
  int new_salary = 400000;

  promoteEmployee(p, new_position, new_salary);

  printf("new position: %s\n", p->position);
  printf("new salary: %d\n", p->salary);
  return 0;
}
