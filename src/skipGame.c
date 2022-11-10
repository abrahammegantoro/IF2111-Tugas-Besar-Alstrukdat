#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "skipGame.h"

void skipGame (Queue* queueGame, Word command) {
    int n = 0, j = 0, i;
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
            runRNG();
        } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
            printLoading(val);
            runDinnerDash();
        } else if (WordCompare(HEAD(*queueGame), toKata("ATC GAME"))) {
            printLoading(val);
            playAtc();
        } else if (WordCompare(HEAD(*queueGame), toKata("DINOSAUR IN EARTH")) || WordCompare(HEAD(*queueGame), toKata("RISEWOMAN")) || WordCompare(HEAD(*queueGame), toKata("EIFFEL TOWER"))) {
            printf("Game "); PrintWord(HEAD(*queueGame)); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n\n");
        } else {
            printLoading(val);
            printf("Game Over! Skor akhir: %d\n\n", rand());
        }
        sleep(3);
    }
    dequeue(queueGame, &val);
}