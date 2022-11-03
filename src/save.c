#include <stdio.h>
#include "Save.h"
#include "./Driver/readTxtFile.c"

/* Implementasi save.h */

void save(TabKata listGame, Word fileName) {
    // KAMUS
    char name[80];
    int i;
    FILE* target;
    TabKata allGame;

    // ALGORITMA
    for (i = 0; i < fileName.Length; i++) {
        name[i] = fileName.TabWord[i];
    }
    name[fileName.Length] = '\0';

    writeTxt(name, listGame);
    
    target = fopen(name, "r");
    if (target != NULL) {
        printf("Save file berhasil disimpan.\n");
    } else {
        printf("Save file gagal disimpan.\n");
    }
    fclose(target);
}