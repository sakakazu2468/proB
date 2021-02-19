#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CarSales {
    char carmaker[256];
    int carsales2020;
    int carsales2019;
    struct CarSales *pnext;
};
typedef struct CarSales Cars;

Cars* add(void) {
    Cars* pdata = (Cars *)malloc(sizeof(Cars));
    printf("maker:");
    scanf("%[^\n]", pdata->carmaker);
    scanf("%*c");
    printf("carsales2020:");
    scanf("%d", &(pdata->carsales2020));
    scanf("%*c");
    printf("carsales2019:");
    scanf("%d", &(pdata->carsales2019));
    scanf("%*c");
    pdata->pnext = NULL;
    return pdata;
}

void show(Cars* phead) {
    Cars* pdata = phead;
    while (pdata != NULL) {     
        printf("maker:%s\n", pdata->carmaker);
        printf("carsales2020:%d\n", pdata->carsales2020);
        printf("carsakes2019:%d\n", pdata->carsales2019);
        pdata = pdata->pnext;
    }
}

Cars* delete(Cars* phead) {
    Cars* pdata = phead;
    Cars *ptmp, *pprev;
    char input[256];

    printf("input delete name:");
    scanf("%s", input);
    scanf("%*c");
    
    while (pdata != NULL) {     
        if (strcmp(pdata->carmaker, input) == 0) {
            if (pdata == phead) {
                ptmp = pdata;
                phead = pdata->pnext;
            } else {
                ptmp = pdata;
                pprev->pnext = pdata->pnext;
            }
            free(ptmp);
        }
        pprev = pdata;
        pdata = pdata->pnext;
    }
    return phead;
}

Cars* finput() {
    FILE *fp;
    char filename[256];
    Cars* ptmp = (Cars *)malloc(sizeof(Cars));
    Cars* pdata = (Cars *)malloc(sizeof(Cars));
    Cars* phead = (Cars *)malloc(sizeof(Cars));
    int freturn;

    printf("input file name:");
    scanf("%s", filename);
    scanf("%*c");
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("file is not exists\n");
    } else {
        fscanf(fp, "%[^,],%d,%d%*c", phead->carmaker, &(phead->carsales2020), &(phead->carsales2019));
        phead->pnext = pdata;
        while ((freturn = fscanf(fp, "%[^,],%d,%d%*c", ptmp->carmaker, &(ptmp->carsales2020), &(ptmp->carsales2019))) != EOF) {
            ptmp->pnext = NULL;
            pdata = ptmp;
            printf("%s\n", pdata->carmaker);
            Cars* ptmp = (Cars *)malloc(sizeof(Cars));
            pdata->pnext = ptmp;
        }
    }
    return phead;
}

void save(Cars* phead) {
    Cars* pdata = phead;
    char filename[256];
    FILE *fp;

    printf("input file name:");
    scanf("%s", filename);
    scanf("%*c");

    fp = fopen(filename, "w");
    while (pdata != NULL) {     
        fprintf(fp, "maker:%s\n", pdata->carmaker);
        fprintf(fp, "carsales2020:%d\n", pdata->carsales2020);
        fprintf(fp, "carsales2019:%d\n", pdata->carsales2019);
        pdata = pdata->pnext;
    }
}

Cars* bubbleSortCarsales(Cars *phead) {
    int complete_flag = 0;
    Cars *pdata;
    Cars *pprev;
    Cars *ptmp;
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

void search(Cars* phead) {
    Cars* pdata = phead;
    char input[256];

    printf("input search name:");
    scanf("%s", input);
    scanf("%*c");
    
    while (pdata != NULL) {     
        if (strcmp(pdata->carmaker, input) == 0) {
            printf("maker:%s\n", pdata->carmaker);
            printf("carsales2020:%d\n", pdata->carsales2020);
            printf("carsakes2019:%d\n", pdata->carsales2019);
        } 
        pdata = pdata->pnext;   
    }
}

void quit(Cars* phead) {
    Cars* pdata = phead;
    Cars* ptmp; 
    while (pdata != NULL) {
        ptmp = pdata->pnext;
        free(pdata);
        pdata = ptmp;
    }   
}

int main(void) {
    Cars *phead = NULL;
    Cars *pdata;
    Cars *ptail = NULL, *ptmp;

    char input;

    while (1) {
        printf("1) Add\n");
        printf("2) Show\n");
        printf("3) Delete\n");
        printf("4) File Input\n");
        printf("5) Save\n");
        printf("7) search\n");
        printf("8) quit\n");
        printf("Enter your choice: ");
        input = getchar();
        scanf("%*c");
        if (input == '1') {
            pdata = add();
            if (phead == NULL) {
                phead = pdata;
                ptail = phead;
            } else {
                ptail->pnext = pdata;
                ptail = pdata;
            }
        } else if (input == '2') {
            show(phead);
        } else if (input == '3') {
            phead = delete(phead);
        } else if (input == '4') {
            phead = finput();
        } else if (input == '5') {
            save(phead);
        } else if (input == '6') {
            pdata = phead;
            if (phead->pnext != NULL ) {
                phead = bubbleSortCarsales(phead);    
            } else {
                printf("Only one element!\n");
            }
        } else if (input == '7') {
            search(phead);
        } else if (input == '8') {
            quit(phead);
        }
    }
    return 0;
}