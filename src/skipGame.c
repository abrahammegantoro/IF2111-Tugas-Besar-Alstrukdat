#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skipGame.h"

/* Implementasi skipGame.h */
void tulisGame(Word Game) {
    for (int i = 0; i < Game.Length; i++) {
        printf("%c", Game.TabWord[i]);
    }
}

void skipGame (Queue* queueGame) {
    // KAMUS
    int n, i;
    ElType val;
    srand(time(NULL));

    // ALGORITMA
    scanf("%d", &n);
    if (!isEmpty(*queueGame)) {
        printf("Berikut adalah daftar Game-mu");
        for (i = 0; i < length(*queueGame); i++) {
            printf("%d. ", i);
            dequeue(queueGame, &val);
            tulisGame(val);
            enqueue(queueGame, val);
            printf("\n");
        }

        while (n > 0 && !isEmpty(*queueGame)) {
            dequeue(queueGame, &val);
        }
        if (isEmpty(*queueGame)) {
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        } else {
            printf("Loading "); tulisGame(HEAD(*queueGame)); printf(" ...\n\n");
            if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
                /* Masukan prosedur game RNG */
            } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
                /* Masukan prosedur game Diner DASH */
            } else if (WordCompare(HEAD(*queueGame), toKata("DINOSAUR IN EARTH")) || WordCompare(HEAD(*queueGame), toKata("RISEWOMAN")) || WordCompare(HEAD(*queueGame), toKata("EIFFEL TOWER"))) {
                printf("Game Over! Skor akhir: %d\n", rand());
            }
            dequeue(queueGame, &val);
        }
    } else {
        printf("Antrian Game-mu kosong.\n");
    }
}