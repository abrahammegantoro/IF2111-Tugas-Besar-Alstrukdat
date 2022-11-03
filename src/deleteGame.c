# include "deleteGame.h"

void deleteGame(char *filename, TabKata file){
    listGame(file);

    char* noGame;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD(noGame);
    int noGameInteger = StrToInt(noGame) - 1;

    if(IsIdxValid(file, noGameInteger)){
        int j = noGameInteger;
        for (j ; j < MaxNbEl(file) ; j++){
            file.TI[j] = file.TI[j+1];
        }
        printf("Game berhasil dihapus\n");

    } else {
        printf("Game gagal dihapus\n");
    }
}