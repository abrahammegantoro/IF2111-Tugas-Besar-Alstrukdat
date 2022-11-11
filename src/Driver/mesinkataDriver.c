#include <stdio.h>
#include "../ADT/mesinkata.h"

int main()
{
    printf("Akan membandingkan kata 'HMIF ITB' dengan input user");

    Word kata1 = toKata("HMIF");
    printf("\nKata pertama : ");
    PrintWord(kata1);

    Word kata2 = toKata("ITB");
    printf("\nKata kedua : ");
    PrintWord(kata2);

    concatWord(&kata1, kata2);
    printf("\nHasil concat kata : ");
    PrintWord(kata1);

    printf("\nMasukkan kata : ");

    STARTINPUT();
    Word input = GetWord();
    ADVWORD();

    while (!EndWord)
    {
        concatWord(&input, currentWord);
        ADVWORD();
    }

    PrintWord(input);

    printf("\nBerhasil mengubah input user menjadi tipe data Word.\n");

    if (WordCompare(kata1, input))
    {
        printf("\nInput user ADALAH 'HMIF ITB'.\n");
    } else
    {
        printf("\nInput user BUKAN 'HMIF ITB'.\n");
    }

    return 0;
}

/* 

======================= Contoh penggunaan =======================
Misalkan input user = 'SUDO', maka program akan mengirim output :
-------------------------------------------------------
Akan membandingkan kata 'HMIF ITB' dengan input user
Masukkan kata : SUDO
Kata saat ini : SUDO
Panjang kata (termasuk spasi): 4

Berhasil mengubah input user menjadi tipe data Word.
Input user BUKAN 'HMIF ITB'.
-------------------------------------------------------
*Note : fungsi stringLength sudah dipanggil di fungsi toKata,
        sehingga tidak dipanggil lagi di driver mesin kata.

*/