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

void deleteGame(TabKata* file, Queue antrianGame, Stack *historyGame){
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTINPUT();
    int noGameInteger = WordToInt(currentWord);
    Word deletedGame = (*file).TI[noGameInteger - 1];
    if(noGameInteger > 6 && noGameInteger <= (*file).Neff && !isExist((*file).TI[noGameInteger], antrianGame)){
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

    } else {
        printf("Game gagal dihapus\n");
    }
}