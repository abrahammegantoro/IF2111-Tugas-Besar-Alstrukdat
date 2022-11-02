#include <stdio.h>
#include "readTxtFile.h"

/* Implementasi readTxtFile.h */

void readTxt(char* filesrc, TabKata* listGame) {
    // KAMUS
    int lines = 0, i;
    
    // ALGORTIMA
    STARTWORD(filesrc);
    for (i = 0; i < currentWord.Length - 1; i++) {
        lines *= 10;
        lines += currentWord.TabWord[i] - '0';
    }
    for (i = 0; i < lines; i++) {
        ADVWORD();
        SetEl(listGame, (*listGame).Neff, currentWord);
    }
}


/* Contoh penggunaan prosedur
int main() {
    TabKata Game;
    MakeEmpty(&Game);
    readTxt("../data/config.txt", &Game);
    TulisIsi(Game);
}
*/