#include <stdio.h>
#include "Save.h"
#include "./Driver/readTxtFile.c"

/* Implementasi save.h */

void save(TabKata listGame, TabKata createdGame, TabKata historyGame) {
    // KAMUS
    char name[80];
    FILE* target;
    TabKata allGame;

    // ALGORITMA
    scanf("%s", name);

    MakeEmpty(&allGame);
    SetTab(listGame, &allGame);
    for (int i = 0; i < createdGame.Neff; i++) {
        allGame.TI[allGame.Neff] = createdGame.TI[i];
        allGame.Neff++;
    }

    writeTxt(name, allGame, historyGame);
    
    target = fopen(name, "r");
    if (target != NULL) {
        printf("Save file berhasil disimpan.\n");
    } else {
        printf("Save file gagal disimpan.\n");
    }
    fclose(target);
}

int main() {
    TabKata game, history;
    MakeEmpty(&game); MakeEmpty(&history);
    readTxt("./Data/config.txt", &game);
    save(game, history);
}