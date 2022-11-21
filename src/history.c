#include <stdio.h>
#include "history.h"

void history(Stack historyGame, Word Command) {
    int n = WordToInt(Command);
    infotype dump;
    if (n <= 0) {
        printf("Jumlah perintah history tidak valid.\n\n");
    } else {
        if (IsEmptyStack(historyGame)) {
            printf("Belum ada Game yang pernah dimainkan.\n\n");
        } else {
            printf("Berikut adalah daftar Game yang telah dimainkan\n");
            int count = 1;
            while (!IsEmptyStack(historyGame) && n > 0) {
                printf("  %d. ", count);
                PrintWord(InfoTop(historyGame));
                Pop(&historyGame, &dump);
                count++; n--;
                printf("\n");
            }
            printf("\n");
        }
    }
}