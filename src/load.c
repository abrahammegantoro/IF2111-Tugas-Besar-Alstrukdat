# include "load.h"
#include <stdio.h>

void load(Word file, TabKata* Game, Stack* historyGame){
    char* fileName = WordToStr(unionWord(FDIR, file));

    TabKata addedGame;
    MakeEmpty(&addedGame);

    // readTxt(fileName, Game);
    if (readTxt(fileName, &addedGame, historyGame)){
        (*Game) = addedGame;
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
    }
}