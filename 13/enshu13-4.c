#include <stdio.h>

struct CarSales {
    char carmaker[256];
    int carsales2020;
    int carsales2019;
};

int findWorstSalesDrop(struct CarSales *sold1920) {
    double worst = 100;
    int worstidx;
    double per;
    int i;
    for (i = 0; i < 8; i++) {
        per = (double)sold1920[i].carsales2020/(double)sold1920[i].carsales2019;
        if (per < worst) {
            worstidx = i;
            worst = per;
        }
    }
    return worstidx;
}

int main(void) {
    struct CarSales sold1920[8];
    FILE *fp;
    int freturn;
    int i = 0;
    int ret;
    if ((fp = fopen("carsales.txt", "r")) == NULL) {
        printf("file if not exists\n");
    } else {
        while ((freturn = fscanf(fp, "%[^,],%d,%d%*c", sold1920[i].carmaker, &sold1920[i].carsales2020, &sold1920[i].carsales2019)) != EOF) {
            i++;
        }
        ret = findWorstSalesDrop(sold1920);
        printf("%s %d %d\n", sold1920[ret].carmaker, sold1920[ret].carsales2020, sold1920[ret].carsales2019);
    }
    return 0;
}