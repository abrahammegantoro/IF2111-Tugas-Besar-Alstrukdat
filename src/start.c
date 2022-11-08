# include "start.h"

void start(TabKata* Game){
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    TabKata Game;
    MakeEmpty(&Game);
    readTxt("./data/config.txt", &Game);
    return Game;
}
    readTxt("../../data/config.txt", &Game);
}

