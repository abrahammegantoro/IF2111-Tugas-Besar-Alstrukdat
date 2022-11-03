#include <stdio.h>
#include "createGame.h"

void createGame(TabKata* daftarGame, Word inputGame)
/*  I.S. TabKata terdefinisi, inputGame terdefinisi
    F.S. Menambahkan inputGame sebagai elemen dari TabKata */
{
    if (IsFull(*daftarGame))
    {
        printf("Maaf, jumlah maksimum game sudah tercapai.\n");
    } else
    {
        (*daftarGame).TI[(*daftarGame).Neff] = inputGame;
        (*daftarGame).Neff += 1;
        printf("Game berhasil ditambahkan\n");
    }
}

/* Implementasi ketika command creategame dipanggil

int main(){
    printf("ENTER COMMAND: ");
    STARTWORD();

    // Testing
    PrintWord(currentWord);
    PrintWord(toKata("CREATE GAME"));

    Word command = GetWord();

    if (WordCompare(toKata("CREATE GAME"), command))
    {
        printf("Masukkan nama game yang akan ditambahkan: ");
        STARTWORD();
        Word newGame = GetWord();

        TabKata currentGame;
        MakeEmpty(&currentGame);
        createGame(&currentGame, newGame);

        TulisIsi(currentGame);
    }
    return 0;
}

*/