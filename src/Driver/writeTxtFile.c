#include <stdio.h>
#include "writeTxtFile.h"

/* Implementasi writeTxtFile.h */
void writeTxt(char* filetarget, TabKata listGame, Stack historyGame, ListScore *scoreboard) {
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
    for (i = 0; i < listGame.Neff; i++) {
        fprintf(file, "%d\n", scoreboard[i].Nama.Count);
        for (j = 0; j < scoreboard[i].Nama.Count; j++) {
            for (int k = 0; k < scoreboard[i].Nama.Elements[scoreboard[i].Score.Elements[j].Key].Length; k++) {
                fprintf(file, "%c", scoreboard[i].Nama.Elements[scoreboard[i].Score.Elements[j].Key].TabWord[k]);
            }
            fprintf(file, " ");
            fprintf(file, "%d\n", scoreboard[i].Score.Elements[j].Value);
        }
    }
    fprintf(file, " ");

    fclose(file);
}