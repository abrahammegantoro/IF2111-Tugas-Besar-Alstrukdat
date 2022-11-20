#include <stdio.h>
#include "history.h"

void history(List historyGame, Word Command) {
    int n = WordToInt(Command);
    if (n <= 0) {
        printf("Jumlah perintah history tidak valid.\n\n");
    } else {
        if (IsEmptyList(historyGame)) {
            printf("Belum ada Game yang pernah dimainkan.\n\n");
        } else {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            int count = 1;
            address P = First(historyGame);
            while (P != Nil && count <= n) {
                printf("  %d. ", count);
                PrintWord(Info(P));
                P = Next(P);
                count++;
                printf("\n");
            }
            printf("\n");
        }
    }
}