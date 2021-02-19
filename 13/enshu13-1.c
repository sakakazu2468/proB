#include <stdio.h>
#include <string.h>

char *shuffleString(char *str1, char *str2, char *shuffle) {
    int i = 0;
    while (str1[i] != '\0') {
        shuffle[i*2] = str1[i];
        shuffle[i*2+1] = str2[i];
        i++;
    }
    shuffle[i*2] = '\0';
    return shuffle;
}

int main(void) {
    char str1[10], str2[10], shuffle[10];
    while (1) {
        printf("input first str:");
        scanf("%s", str1);
        printf("input second str:");
        scanf("%s", str2);
        if (strlen(str1)+strlen(str2) <= 10) {
            break;
        } else {
            printf("too long! input again\n");
        }
    }
    printf("%s\n", shuffleString(str1, str2, shuffle));

    return 0;
}