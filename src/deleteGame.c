# include "deleteGame.h"
#include <stdio.h>

void deleteGame(TabKata* file){
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTINPUT();
    int noGameInteger = WordToInt(currentWord);

    if(IsIdxValid(*file, noGameInteger)){
        int j = noGameInteger-1;
        for (j ; j < MaxNbEl(*file) ; j++){
            (*file).TI[j] = (*file).TI[j+1];
        }
        (*file).Neff--;
        printf("Game berhasil dihapus\n");

    } else {
        printf("Game gagal dihapus\n");
    }
}