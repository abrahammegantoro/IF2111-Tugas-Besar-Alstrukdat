#include <stdio.h>
#include "Save.h"
#include "./Driver/writeTxtFile.h"

/* Implementasi save.h */

void save(TabKata listGame, Word fileName) {
    // KAMUS
    char name[80] = "./data/";
    int i;
    FILE* target;

    // ALGORITMA
    for (i = 0; i < fileName.Length; i++) {
        name[8+i] = fileName.TabWord[i];
    }
    name[8+fileName.Length] = '\0';

    writeTxt(name, listGame);
    
    target = fopen(name, "r");
    if (target != NULL) {
        printf("Save file berhasil disimpan.\n");
    } else {
        printf("Save file gagal disimpan.\n");
    }
    fclose(target);
}