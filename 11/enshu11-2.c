#include <stdio.h>
#include <stdlib.h>

struct MovieRanking {
    char title[256];
    double income;
    int released;
    struct MovieRanking *pnext;
};
typedef struct MovieRanking Movies;

int main() {
    Movies *phead = NULL;
    Movies *pdata;
    Movies *ptail = NULL, *ptmp;
    char input;

    while (1) {
        printf("1) Add\n");
        printf("2) Show\n");
        printf("3) Quit\n");
        printf("Enter your choice: ");
        input = getchar();
        scanf("%*c");
        if (input == '1') {
            pdata = (Movies *)malloc(sizeof(Movies));
            if (pdata == NULL) {
                printf("unable to allocate memory");
            } else {
                printf("title:");
                scanf("%[^\n]", pdata->title);
                scanf("%*c");
                printf("income:");
                scanf("%lf", &(pdata->income));
                scanf("%*c");
                printf("released:");
                scanf("%d", &(pdata->released));
                scanf("%*c");
                pdata->pnext = NULL;
                if (phead == NULL) {
                    phead = pdata;
                    ptail = phead;
                } else {
                    ptail->pnext = pdata;
                    ptail = pdata;
                }
            }
        } else if (input == '2') {
            pdata = phead;
            while (pdata != NULL) {     
                printf("title:%s\n", pdata->title);
                printf("income:%.2lf\n", pdata->income);
                printf("released:%d\n", pdata->released);
                pdata = pdata->pnext;
            }
        } else if (input == '3') {
            pdata = phead;
            while (pdata != NULL) {
                ptmp = pdata->pnext;
                free(pdata);
                pdata = ptmp;
            }    
            break;
        } else {
            printf("Warong input, try again.\n");
        }
    }
    return 0;
}