#include <stdio.h>

struct MovieRanking {
    char title[256];
    double income;
    int released;
};

int findTopGrossingMovie(struct MovieRanking movies[]) {
    int i;
    int ret;
    double topIncome = -1;
    for (i = 0; i < 10; i++) {
        if (topIncome < movies[i].income) {
            topIncome = movies[i].income;
            ret = i;
        }
    }
    return ret;
}

int main(void) {
    FILE *fp;
    int i = 0;
    int idx;
    struct MovieRanking movies[10];
    int ret;
    if ((fp = fopen("movieranking.txt", "r")) == NULL) {
        printf("file is not exists\n");
    } else {
        while ((ret = fscanf(fp, "%[^,],%lf,%d%*c", movies[i].title, &movies[i].income, &movies[i].released)) != EOF) { 
            i++;
        }
    }
    idx = findTopGrossingMovie(movies);
    printf("name:%s, income:%.3lf, released:%d", movies[idx].title, movies[idx].income, movies[idx].released);
    return 0;
}