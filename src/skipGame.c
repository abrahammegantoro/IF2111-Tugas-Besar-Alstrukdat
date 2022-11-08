#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "skipGame.h"

/* Implementasi skipGame.h */
// void tulisGame(Word Game) {
//     for (int i = 0; i < Game.Length; i++) {
//         printf("%c", Game.TabWord[i]);
//     }
// }

void skipGame (Queue* queueGame, Word command) {
    int n = 0, i;
    ElType val;
    srand(time(NULL));

    for (i = 0; i < command.Length; i++) {
        n = n * 10;
        n += command.TabWord[i] - '0';
    }

    if (!isEmpty(*queueGame)) {
        printf("Berikut adalah daftar Game-mu");
        for (i = 0; i < length(*queueGame); i++) {
            printf("%d. ", i);
            dequeue(queueGame, &val);
            PrintWord(val);
            enqueue(queueGame, val);
            printf("\n");
        }

        while (n > 0 && !isEmpty(*queueGame)) {
            dequeue(queueGame, &val);
        }
        if (isEmpty(*queueGame)) {
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        } else {
            printf("Loading "); PrintWord(HEAD(*queueGame)); printf(" ...\n\n");
            if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
                printf("Loading RNG ...\n\n");
                /* Masukan prosedur game RNG */
            } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
                printf("Loading Diner DASH ...\n\n");
                /* Masukan prosedur game Diner DASH */
            } else if (WordCompare(HEAD(*queueGame), toKata("DINOSAUR IN EARTH")) || WordCompare(HEAD(*queueGame), toKata("RISEWOMAN")) || WordCompare(HEAD(*queueGame), toKata("EIFFEL TOWER"))) {
                printf("Game "); PrintWord(HEAD(*queueGame)); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            } else {
                printf("Game Over! Skor akhir: %d\n", rand());
            }
            dequeue(queueGame, &val);
        }
    } else {
        printf("Antrian Game-mu kosong.\n");
    }
}