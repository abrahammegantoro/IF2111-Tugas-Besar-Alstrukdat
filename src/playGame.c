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
void playGame(Queue *queueGame, Stack* historyGame) {
    ElType val;
    srand(time(NULL));

    if(!isEmpty(*queueGame)) {

        // Mencetak list game
        printf("Berikut adalah daftar Game-mu\n");
        for (int i = 0; i < length(*queueGame); i++) {
            printf("  %d. ", i+1);
            dequeue(queueGame, &val);
            PrintWord(val);
            enqueue(queueGame, val);
            printf("\n");
        }
        printf("\n");
        if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
            printLoading(HEAD(*queueGame));
            runRNG();
        } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
            printLoading(HEAD(*queueGame));
            runDinerDash();
        } else if (WordCompare(HEAD(*queueGame), toKata("ATC GAME"))) {
            printLoading(HEAD(*queueGame));
            playAtc();
        } else if (WordCompare(HEAD(*queueGame), toKata("HANGMAN"))) {
            printLoading(HEAD(*queueGame));
            // game hangman
        } else if (WordCompare(HEAD(*queueGame), toKata("TOWER OF HANOI"))) {
            printLoading(HEAD(*queueGame));
            playTowerOfHanoi();
        } else if (WordCompare(HEAD(*queueGame), toKata("SNAKE ON METEOR"))) {
            printLoading(HEAD(*queueGame));
            // game snake on meteor
        } else {
            printLoading(HEAD(*queueGame));
            printf("Game Over! Skor akhir: %d\n", rand());
        }
        sleep(3);
        dequeue(queueGame, &val);
        Push(historyGame, val);
    } else {
        printf("Kamu tidak memiliki antrian Game apapun.\n");
    }
}