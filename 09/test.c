#include <stdio.h>

int main(void) {
    FILE *fp;
    int i;
    // fp = fopen("greeting.txt", "w");
    if ((fp = fopen("greeting.txt", "w"))== NULL) {
        printf("ERROR: Cannot open!\n");
    } else {
        for (i = 0; i < 3; i++) {
            fprintf(fp, "HAPPY NEW YEAR %d!\n", i+2019);
        }
        fclose(fp);
    }
    return 0;
}