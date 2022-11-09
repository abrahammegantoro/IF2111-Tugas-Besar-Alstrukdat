# include "load.h"
#include <stdio.h>

void load(Word file, TabKata* Game){
    char* fileName = WordToStr(unionWord(FDIR, file));

    // readTxt(fileName, Game);
    if (readTxt(fileName, Game)){
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}