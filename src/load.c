# include "load.h"
#include <stdio.h>

void load(Word file, TabKata* Game, Stack* historyGame, ListScore* scoreboard) {
    char* fileName = WordToStr(unionWord(FDIR, file));

    TabKata addedGame;
    MakeEmpty(&addedGame);

    // readTxt(fileName, Game);
    if (readTxt(fileName, &addedGame, historyGame, scoreboard)) {
        (*Game) = addedGame;
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n\n");
    }
}