#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "playGame.h"

/* Implementasi playGame.h */

void printLoading(Word gameName) {
    printf("Loading "); PrintWord(gameName); printf(" ");
    for (int i = 0; i < 3; i++) {
        printf("."); sleep(1);
    }
    system("cls");
}

// Game yang diload dan game yang dibuat akan dipisah karena perlu ada penanganan game yang sedang maintenance (game yang bukan game RNG, Dine Dash, atau game buatan)
void playGame(Queue *queueGame) {
    ElType val;
    srand(time(NULL));

    if(!isEmpty(*queueGame)) {

        // Mencetak list game
        printf("Berikut adalah daftar Game-mu\n");
        for (int i = 0; i < length(*queueGame); i++) {
            printf("  %d. ", i);
            dequeue(queueGame, &val);
            PrintWord(val);
            enqueue(queueGame, val);
            printf("\n");
        }
        
        if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
            printLoading(HEAD(*queueGame));
            /* Masukan prosedur game RNG */
            sleep(3);
        } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
            printLoading(HEAD(*queueGame));
            /* Masukan prosedur game Diner DASH */
            sleep(3);
        } else if (WordCompare(HEAD(*queueGame), toKata("DINOSAUR IN EARTH")) || WordCompare(HEAD(*queueGame), toKata("RISEWOMAN")) || WordCompare(HEAD(*queueGame), toKata("EIFFEL TOWER"))) {
            printf("Game "); PrintWord(HEAD(*queueGame)); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
        } else {
            printLoading(HEAD(*queueGame));
            printf("Game Over! Skor akhir: %d\n", rand());
        }
        dequeue(queueGame, &val);
    
    } else {
        printf("Kamu tidak memiliki antrian Game apapun.\n");
    }
}