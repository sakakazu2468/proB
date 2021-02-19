#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int judge(int player1, int player2) {
    if (((player1-player2)%3==-1) || ((player1-player2)%3==2)) {
        return 1;
    } else if (((player1-player2)%3==-2) || ((player1-player2)%3==1)) {
        return 2;
    } else {
        return 0;
    }
}

void jankendata(int* p1win, int* p2win, FILE* fp) {
    int player1, player2, result, i;
    int n = 256;
    for (i = 0; i < n; i++) {
        while (1) {
            player1 = rand()%3;
            player2 = rand()%3;
            result = judge(player1, player2);
            if (result != 0) {
                break;
            }
        }
        if (result == 1) {
            *p1win += 1;
        } else if (result == 2){
            *p2win += 1;
        }
        fprintf(fp, "GAME%d:player%d win\n", i+1, result);
    }
}

int main(void) {
    int p1win, p2win;
    FILE* fp;

    p1win = 0;
    p2win = 0;
    fp = fopen("jankendata.txt", "a");
    jankendata(&p1win, &p2win, fp);
    fclose(fp);
    printf("player1, wins:%d, percent:%.1f\n", p1win, (double)p1win/256*100);
    printf("player2, wins:%d, percent:%.1f\n", p2win, (double)p2win/256*100);
    return 0;
}