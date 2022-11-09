# include "start.h"

void start(TabKata* Game){
    if(readTxt("./data/config.txt", Game)){
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
}

