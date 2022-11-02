#include<stdio.h>
#include"Driver/readTxtFile.h"
TabKata start(){
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    TabKata Game;
    MakeEmpty(&Game);
    readTxt("./data/config.txt", &Game);
    return Game;
}