# include "queueGame.h"
#include <stdio.h>

void displayQueueGame(Queue antrianGame){
    if (!isEmpty(antrianGame)){
        printf("Berikut adalah daftar antrian game-mu\n");
        int i = IDX_HEAD(antrianGame);
        int j = 1;
        while (i != IDX_TAIL(antrianGame)){
            printf("  %d. ", j);
            PrintWord(antrianGame.buffer[i]);
            printf("\n");
            j++;
            i++;
        }
        printf("  %d. ", j);
        PrintWord(antrianGame.buffer[i]);
        printf("\n");
    } else {
        printf("Belum ada daftar antrian.\n");
    }
}
    
void queueGame(TabKata file, Queue* antrianGame){
    displayQueueGame(*antrianGame);
    printf("\n");
    listGame(file);
    
    printf("Nomor Game yang mau ditambahkan ke antrian: ");
    STARTINPUT();
    int tambahAntrianGame = WordToInt(currentWord);
    if(IsIdxEff(file, tambahAntrianGame)){
        enqueue(antrianGame, file.TI[tambahAntrianGame-1]);
        printf("Game berhasil dimasukkan dalam antrian.\n");
    } else {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
}
