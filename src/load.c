# include "load.h"
#include <stdio.h>

void load(Word currentWord, TabKata* Game){
    char* fileName = WordToStr(unionWord(FDIR, currentWord));
    
    readTxt(fileName, Game);
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}