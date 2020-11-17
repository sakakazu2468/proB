#include <stdio.h>
#include <stdlib.h>

#define RED		0
#define GREEN		1
#define WAITING_TIME	30
#define COLOR_NO		2

void shingo(int color);

int main(void) {
	int shingo1, shingo2, shingo3;

	shingo1 = rand() % COLOR_NO;
          shingo(shingo1);

	shingo2 = rand() % COLOR_NO;
          shingo(shingo2);

	shingo3 = rand() % COLOR_NO;
          shingo(shingo3);

	return 0;
}

void shingo(int color) {
    int time;
    if (color == RED) {
          printf("Red light. Waiting...\n");
          time = 0;
          while (time < WAITING_TIME) {
                time++;
          }
    }
    else if (color == GREEN) {
          printf("Green light. Go!\n");
    }
    else {
          printf("Be careful...");
    }

}
