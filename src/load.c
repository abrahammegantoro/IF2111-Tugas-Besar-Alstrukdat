# include "load.h"

void load(Word currentWord, TabKata* Game){
    getFile(currentWord);
    char* fileName = WordToStr(unionWord(FDIR, getFile(currentWord)));
    
    readTxt(fileName, &Game);
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    return Game;
}