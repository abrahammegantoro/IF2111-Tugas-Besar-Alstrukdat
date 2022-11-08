#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"

/* Implementasi playGame.h */

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
// void tulisGame(Word Game) {
//     for (int i = 0; i < Game.Length; i++) {
//         printf("%c", Game.TabWord[i]);
//     }
// }

// Game yang diload dan game yang dibuat akan dipisah karena perlu ada penanganan game yang sedang maintenance (game yang bukan game RNG, Dine Dash, atau game buatan)
void playGame(Queue *queueGame) {
    // KAMUS
    int i, j, option;
    ElType val;
    srand(time(NULL));

    // ALGORITMA
    if(!isEmpty(*queueGame)) {
        printf("Berikut adalah daftar Game-mu\n");

        // Mencetak list game
        for (i = 0; i < length(*queueGame); i++) {
            printf("%d. ", i);
            dequeue(queueGame, &val);
            PrintWord(val);
            enqueue(queueGame, val);
            printf("\n");
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
        printf("Kamu tidak memiliki antrian Game apapun.\n");
    }
}