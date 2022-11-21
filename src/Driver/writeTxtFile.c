#include <stdio.h>
#include "writeTxtFile.h"

/* Implementasi writeTxtFile.h */
void writeTxt(char* filetarget, TabKata listGame, Stack historyGame) {
    // KAMUS
    FILE *file;
    int i, j;
    // ALGORITMA
    file = fopen(filetarget, "w");

    fprintf(file, "%d\n", listGame.Neff);
    for (i = 0; i < listGame.Neff; i++) {
        for (j = 0; j < listGame.TI[i].Length; j++) {
            fprintf(file, "%c", listGame.TI[i].TabWord[j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "%d\n", NbElmtStack(historyGame));
    infotype temp;
    while (!IsEmptyStack(historyGame)) {
        Pop(&historyGame, &temp);
        for (j = 0; j < temp.Length; j++) {
            fprintf(file, "%c", temp.TabWord[j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, " ");

    fclose(file);
}