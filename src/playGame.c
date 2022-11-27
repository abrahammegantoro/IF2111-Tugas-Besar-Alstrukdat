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
    clear();
}

// Game yang diload dan game yang dibuat akan dipisah karena perlu ada penanganan game yang sedang maintenance (game yang bukan game RNG, Dine Dash, atau game buatan)
int playGame(Queue *queueGame, Stack* historyGame) {
    ElType val;
    int score;
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
            score = runRNG();
        } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
            printLoading(HEAD(*queueGame));
            score = runDinerDash();
        } else if (WordCompare(HEAD(*queueGame), toKata("ATC GAME"))) {
            printLoading(HEAD(*queueGame));
            score = playAtc();
        } else if (WordCompare(HEAD(*queueGame), toKata("HANGMAN"))) {
            printLoading(HEAD(*queueGame));
            score = hangman();
        } else if (WordCompare(HEAD(*queueGame), toKata("TOWER OF HANOI"))) {
            printLoading(HEAD(*queueGame));
            score = playTowerOfHanoi();
        } else if (WordCompare(HEAD(*queueGame), toKata("SNAKE ON METEOR"))) {
            printLoading(HEAD(*queueGame));
            score = RunSnakeOnMeteor();
        } else if (WordCompare(HEAD(*queueGame), toKata("THE GLASS GAME"))) {
            printLoading(HEAD(*queueGame));
            score = playTheGlassGame();
        } else {
            printLoading(HEAD(*queueGame));
            score = rand();
            printf("Game Over! Skor akhir: %d\n", score);
            
        }
        dequeue(queueGame, &val);
        Push(historyGame, val);
    } else {
        printf("Kamu tidak memiliki antrian Game apapun.\n");
        score = NIL;
    }
    return score;
}

int selectGame(TabKata listGame, Queue queueGame) {
    int idx = 0;
    if (isEmpty(queueGame)) {
        idx = NIL;
    } else {
        Word gameName = HEAD(queueGame);
        boolean found = false;
        while ((!found) && (idx < listGame.Neff)) {
            if (WordCompare(gameName, listGame.TI[idx])) {
                found = true;
            } else {
                idx ++;
            }
        }
    }
    return idx;
}