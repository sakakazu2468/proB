#include <stdio.h>
#include <string.h>


struct electrical_products {
  char name[256];
  int price;
} microwave, electronic_dictionaly;

int comparePrice(struct electrical_products microwave, struct electrical_products electronic_dictionaly) {
  if (microwave.price > electronic_dictionaly.price) {
    return 1; 
  } else if (microwave.price < electronic_dictionaly.price) {
    return 2;
  } else {
    return 0;
  }
}

int main(void) {
  int higher;
  strcpy(microwave.name, "RE-SS8X");
  microwave.price = 23790;
  strcpy(electronic_dictionaly.name, "XD-SX4900");
  electronic_dictionaly.price = 33500;
  
  higher = comparePrice(microwave, electronic_dictionaly);
  if (higher == 1) {
    printf("%s\n", microwave.name);
  } else if (higher == 2) {
    printf("%s\n", electronic_dictionaly.name);
  }
  
  return 0;
}
