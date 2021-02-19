#include <stdio.h>
#include <stdlib.h>

struct MovieRanking {
    char title[256];
    double income;
    int released;
    struct MovieRanking *pnext;
};
typedef struct MovieRanking Movies;

Movies* bubbleSortMovieIncome(Movies *phead) {
    int complete_flag = 0;
    Movies *pdata;
    Movies *pprev;
    Movies *ptmp;
    while (complete_flag == 0) {
        complete_flag = 1;
        pdata = phead;
        while (pdata->pnext != NULL) {
            if (pdata->released < pdata->pnext->released) {
                if (pdata == phead) {
                    phead = pdata->pnext;
                    ptmp = pdata->pnext->pnext;
                    phead->pnext = pdata;
                    phead->pnext->pnext = ptmp;
                    pprev = phead;
                } else {
                    pprev->pnext = pdata->pnext;
                    ptmp = pdata->pnext->pnext;
                    pprev->pnext->pnext = pdata;
                    pdata->pnext = ptmp;
                }
                complete_flag = 0;
            } else {
                pprev = pdata;
                pdata = pdata->pnext;
            }
        }
    }
    return phead;
}

int main() {
    Movies *phead = NULL;
    Movies *pdata;
    Movies *ptail = NULL, *ptmp;
    char input;
    int del_year;

    while (1) {
        printf("1) Add\n");
        printf("2) Show\n");
        printf("3) Quit\n");
        printf("4) Delete\n");
        printf("5) Sort\n");
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
        } else if (input == '4') {
            pdata = phead;
            printf("input year:");
            scanf("%d", &del_year);
            scanf("%*c");
            while (pdata != NULL) {
                if (pdata->released == del_year) {
                    if (pdata == phead) {
                        ptmp = pdata->pnext;
                        free(pdata);
                        phead = ptmp;
                        pdata = ptmp;
                    } else {
                        ptmp->pnext = pdata->pnext;
                        free(pdata);
                        pdata = ptmp->pnext;
                    }
                } else {
                    ptmp = pdata;
                    pdata = pdata->pnext;
                }
            }
        } else if (input == '5') {
            pdata = phead;
            if (phead->pnext != NULL ) {
                phead = bubbleSortMovieIncome(phead);    
            } else {
                printf("Only one element!\n");
            }
        } else {
            printf("Warong input, try again.\n");
        }
    }
    return 0;
}