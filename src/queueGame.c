# include "queueGame.h"
#include <stdio.h>

void displayQueueGame(Queue antrianGame){
    if (!isEmpty(antrianGame)){
        printf("Berikut adalah daftar antrian game-mu\n");
        int i = IDX_HEAD(antrianGame);
        int j = 1;
        while (i != IDX_TAIL(antrianGame)){
            printf("%d. %s\n", j, antrianGame.buffer[i]);
            i++;
            j++;
        }
        printf("%d. %s\n", j, antrianGame.buffer[i]);
    } else {
        printf("Belum ada daftar antrian.\n");
    }
}
    
void queueGame(TabKata file, Queue* antrianGame){
    displayQueueGame(*antrianGame);
    listGame(file);
    
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTINPUT();
    int tambahAntrianGame = WordToInt(currentWord)-1;
    if(IsIdxValid(file, tambahAntrianGame)){
        enqueue(antrianGame, file.TI[tambahAntrianGame]);
    }
}