# include "listGame.h"
#include <stdio.h>

void listGame(TabKata x){
    int i;
    if (x.Neff == 0) {
        printf("Tabel kosong\n");
    } else {
        int k = 0;
        for (i=IdxMin - 1; i<x.Neff; i++){
            printf("%d. ", k+1);
            k++;
            for(int j = 0; j < x.TI[i].Length; j++) {
            printf("%c", x.TI[i].TabWord[j]);
        }
        printf("\n");
        }
    }
}

// TabKata start(){
//     printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
//     TabKata Game;
//     MakeEmpty(&Game);
//     readTxt("./data/config.txt", &Game);
//     return Game;
// }

// int main(){
//     listGame(start());
//     return 0;
// }