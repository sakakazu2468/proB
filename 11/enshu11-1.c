#include <stdio.h>
#include <stdlib.h>

int main() {
    char *pdata;
    int i=0;
    
    pdata = (char *)malloc(sizeof(char)*256);    
    if (pdata == NULL) {
        printf("No memory!\n");
    } else {
        scanf("%s", pdata);
        while (pdata[i] != '\0') {
            printf("%c", pdata[i]);
            i++;
        }
        printf("\n");
        free(pdata);
    }
    
    return 0;
}