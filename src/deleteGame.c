# include "deleteGame.h"
#include <stdio.h>

boolean isExist(ElType Kata, Queue antrian){
    boolean found = false;
    int i = IDX_HEAD(antrian);
    while (i <= IDX_TAIL(antrian) && !found){
        if (WordCompare(Kata, antrian.buffer[i])){
            found = true;
        }
        i++;
    }
    return found;
}

void deleteGame(TabKata* file, Queue antrianGame){
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTINPUT();
    int noGameInteger = WordToInt(currentWord);

    if(noGameInteger > 6 && noGameInteger <= (*file).Neff && !isExist((*file).TI[noGameInteger], antrianGame)){
        int j;
        for (j = noGameInteger - 1 ; j < (*file).Neff ; j++){
            (*file).TI[j] = (*file).TI[j+1];
        }
        (*file).Neff--;
        printf("Game berhasil dihapus\n");

    } else {
        printf("Game gagal dihapus\n");
    }
}