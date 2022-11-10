#include <stdio.h>
#include "createGame.h"

void createGame(TabKata* daftarGame)
/*  I.S. TabKata terdefinisi, inputGame terdefinisi
    F.S. Menambahkan inputGame sebagai elemen dari TabKata */
{
    printf("Masukkan nama game yang akan ditambahkan: ");
    STARTINPUT();
    printf("\n");
    if (IsFull(*daftarGame))
    {
        printf("Maaf, jumlah maksimum game sudah tercapai.\n");
    } else
    {
        Word gameName = currentWord;
        ADVWORD();
        while (!EndWord) {
            concatWord(&gameName, currentWord);
            ADVWORD();
        }

        int i = 0;
        boolean found = false;

        while (i != (*daftarGame).Neff && !found)
        {
            if (WordCompare((*daftarGame).TI[i], gameName))
            {
                found = true;
            }
            else
            {
                i += 1;
            }
        }

        if (!found)
        {
            (*daftarGame).TI[(*daftarGame).Neff] = gameName;
            (*daftarGame).Neff += 1;
            printf("Game berhasil ditambahkan\n");
        } else
        {
            printf("Gagal menambahkan Game! Game sudah terdapat di dalam list game\n");
        }
    }
}