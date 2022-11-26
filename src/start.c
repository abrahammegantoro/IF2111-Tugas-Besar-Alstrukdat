# include "start.h"

void start(TabKata* Game, Stack* historyGame, ListScore* scoreBoard) {
    if(readTxt("./data/config.txt", Game, historyGame, scoreBoard)) {
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n\n");
    }
}

