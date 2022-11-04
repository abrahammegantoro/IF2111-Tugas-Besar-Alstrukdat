# include "start.h"

void start(TabKata* Game){
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    readTxt("../../data/config.txt", &Game);
}