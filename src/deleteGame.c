# include "deleteGame.h"
#include <stdio.h>

boolean isExist(ElType Kata, Queue antrian){
    boolean found = false;
    int i = IDX_HEAD(antrian);
    if (!isEmpty(antrian)){
        while (i <= IDX_TAIL(antrian) && !found){
            if (WordCompare(Kata, antrian.buffer[i])){
                found = true;
            }
            i++;
        }
    }
    return found;
}

void deleteGame(TabKata* file, Queue antrianGame, Stack *historyGame, ListScore *scoreBoard){
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTINPUT();
    int noGameInteger = WordToInt(currentWord);
    Word deletedGame = (*file).TI[noGameInteger - 1];
    if(noGameInteger > 7 && noGameInteger <= (*file).Neff && !isExist(deletedGame, antrianGame)){
        int j;
        for (j = noGameInteger - 1 ; j < (*file).Neff ; j++){
            (*file).TI[j] = (*file).TI[j+1];
        }
        (*file).Neff--;
        printf("Game berhasil dihapus\n");

        // Deleting game from history
        Stack temp; CreateEmptyStack(&temp);
        infotype trf;
        while (!IsEmptyStack(*historyGame)) {
            Pop(historyGame, &trf);
            if (!WordCompare(trf, deletedGame)) {
                Push(&temp, trf);
            }
        }
        while (!IsEmptyStack(temp)) {
            Pop(&temp, &trf);
            Push(historyGame, trf);
        }
        // Deleting scoreboard
        CreateListScore(&(scoreBoard[noGameInteger - 1]));

    } else if (noGameInteger >= 1 && noGameInteger <= 7){
        printf("Game default tidak dapat dihapus!\n");
    } else if (isExist(deletedGame, antrianGame)){
        printf("Game masih dalam antrian, Game gagal dihapus!\n");
    } else if (noGameInteger < 1 || noGameInteger > (*file).Neff){
        printf("Game tidak ditemukan, Game gagal dihapus!\n");
    }
}