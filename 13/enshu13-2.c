#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int zakoBattle(int hp);
int bossBattle(int hp);

int main(void) {
    int hp = 100;
    int i;
    int end = 0;
    for (i=0; i<10; i++) {
        hp = zakoBattle(hp);
        if (hp <= 0) {
            printf("You lose...\n");
            break;
        } 
    }
    if (hp > 0) {
        hp = bossBattle(hp);
        if (hp > 0) {
            printf("You killed the BOSS!\n");
        } else {
            printf("You lose...\n");
        }
    }

    return 0;
}

int zakoBattle(int hp) {
    srand((unsigned int)time(NULL));
    int zakohp = 5;
    int zakoAtack, playerAtack;
    while (1) {
        playerAtack = rand()%3;
        zakohp -= playerAtack;
        if (zakohp < 0) {
            printf("killed zako\n");
            break;
        }
        zakoAtack = rand()%3;
        hp -= zakoAtack;
        if (hp < 0) {
            break;
        }
    }
    return hp;
}

int bossBattle(int hp) {
    srand((unsigned int)time(NULL));
    int bosshp = 60;
    int bossAtack, playerAtack;
    while (1) {
        playerAtack = rand()%3;
        bosshp -= playerAtack;
        if (bosshp < 0) {
            break;
        }
        bossAtack = rand()%3;
        hp -= bossAtack;
        if (hp < 0) {
            break;
        }
    }
    return hp;
}