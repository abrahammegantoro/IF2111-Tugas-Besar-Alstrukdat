#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "skipGame.h"

int skipGame (Queue* queueGame, Word command, Stack* historyGame) {
    int n = 0, j = 0, i;
    int score = NIL;
    ElType val;
    srand(time(NULL));

    n = WordToInt(command);

    printf("Berikut adalah daftar Game-mu\n");
    for (i = 0; i < length(*queueGame); i++) {
        printf("  %d. ", i + 1);
        dequeue(queueGame, &val);
        PrintWord(val);
        enqueue(queueGame, val);
        printf("\n");
    }
    
    while (n > 0 && !isEmpty(*queueGame) && j != n) {
        dequeue(queueGame, &val);
        j++;
    }
    
    if (isEmpty(*queueGame)) {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    } else {
        val = HEAD(*queueGame);
        if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
            printLoading(val);
            score = runRNG();
        } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
            printLoading(val);
            score = runDinerDash();
        } else if (WordCompare(HEAD(*queueGame), toKata("ATC GAME"))) {
            printLoading(val);
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
            printLoading(val);
            score = rand();
            printf("Game Over! Skor akhir: %d\n", score);
        }
        sleep(3);
    }
    return score;
}