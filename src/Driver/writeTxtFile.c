#include <stdio.h>
#include "writeTxtFile.h"

/* Implementasi writeTxtFile.h */
void writeTxt(char* filetarget, TabKata listGame, TabKata historyGame) {
    // KAMUS
    FILE *file;
    int i, j;
    printf("ini sih bisa");
    // ALGORITMA
    file = fopen(filetarget, "w");

    printf("berhasil");
    fprintf(file, "%d\n", listGame.Neff);
    for (i = 0; i < listGame.Neff; i++) {
        for (j = 0; j < listGame.TI[i].Length; j++) {
            fprintf(file, "%c", listGame.TI[i].TabWord[j]);
        }
        fprintf(file, "\n");
    }

    fprintf(file, "%d\n", historyGame.Neff);
    for (i = 0; i < historyGame.Neff; i++) {
        for (j = 0; j < historyGame.TI[i].Length; j++) {
            fprintf(file, "%c", historyGame.TI[i].TabWord[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}