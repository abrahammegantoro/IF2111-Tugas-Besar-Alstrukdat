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
        lines = WordToInt(currentWord);
        ADV();
        for (int i = 0; i < lines; i++) {
            ADV();
            ADVWORD();
            Word currentGame = currentWord;
            while (currentChar != '\n') {
                ADVWORD();
                currentGame.TabWord[currentGame.Length] = ' ';
                currentGame.Length++;
                for (int i = 0; i < currentWord.Length; i++) {
                    currentGame.TabWord[currentGame.Length] = currentWord.TabWord[i];
                    currentGame.Length++;
                }
            }
            SetEl(listGame, i, currentGame);
        }
    }
    fclose(input);
}