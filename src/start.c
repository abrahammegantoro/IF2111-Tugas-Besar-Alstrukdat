# include "start.h"

void start(TabKata* Game, Stack* historyGame){
    if(readTxt("./data/config.txt", Game, historyGame)){
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
    }
}

