#include <stdio.h>
#include "readTxtFile.h"

/* Implementasi readTxtFile.h */

void readTxt(char* filesrc, TabKata* listGame) {
    FILE* input = fopen(filesrc, "r");
    int lines = 0;
    
    if (input == NULL) {
        printf("File tidak ditemukan.\n");
    } else {
        STARTWORD(input);
        for (int i = 0; i < currentWord.Length; i++) {
            lines *= 10;
            lines += currentWord.TabWord[i] - '0';
        }
        for (int i = 0; i < lines; i++) {
            ADVWORD();
            SetEl(listGame, i, currentWord);
        }
    }
    fclose(input);
}
