#include <stdio.h>
#include "readTxtFile.h"

/* Implementasi readTxtFile.h */

boolean readTxt(char* filesrc, TabKata* listGame, Stack* historyGame, ListScore* scoreboard) {
    Stack inverted; CreateEmptyStack(&inverted);
    FILE* input = fopen(filesrc, "r");
    int linesgame = 0;
    int lineshistory = 0;
    int linesscore = 0;
    
    if (input == NULL) {
        printf("File tidak ditemukan.\n\n");
        return false;
    } else {
        STARTWORD(input);
        linesgame = WordToInt(currentWord);
        for (int i = 0; i < linesgame; i++) {
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
        ADV();
        if (currentChar != ' ') {
            ADVWORD();
            lineshistory = WordToInt(currentWord);
            for (int i = 0; i < lineshistory; i++) {
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
                Push(&inverted, currentGame);
            }
            infotype temp;
            while (!IsEmptyStack(inverted)) {
                Pop(&inverted, &temp);
                Push(historyGame, temp);
            }
        }
        
        for (int i = 0; i < linesgame; i++) {
            ADV();
            ADVWORD();
            linesscore = WordToInt(currentWord);
            for (int j = 0; j < linesscore; j++) {
                ADV();
                ADVWORD();
                InsertSet(&((*scoreboard).Nama), currentWord);
                ADVWORD();
                InsertMapSorted(&((*scoreboard).Score), j, WordToInt(currentWord));
            }
            scoreboard++;
        }
    }
    fclose(input);
    return true;
}