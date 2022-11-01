# include <stdio.h>
# include "ADT/array.h"

void delete(char *filename, TabInt file){
    load(filename);

    printf("Berikut ini adalah daftar game yang tersedia\n");

    char c;

    c = fgetc(filename);
    int i = 0;

    while(!IsEOP(c)){
        file.TI[i] = c;
    }

    int noGame;
    scanf("Masukkan nomor game yang akan dihapus: %d", &noGame);
    if(IsIdxValid(file, noGame)){
        int j = noGame;
        for (j ; j < MaxNbEl ; j++){
            file.TI[j] = file.TI[j+1];
        }
        printf("Game berhasil dihapus\n");

    } else {
        printf("Game gagal dihapus\n");
    }
}