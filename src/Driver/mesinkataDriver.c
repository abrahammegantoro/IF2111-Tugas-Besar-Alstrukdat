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
    printf("\nHasil concat kata : "); PrintWord(kata1);

    printf("\n\nMasukkan kata : ");

    STARTINPUT();
    Word input = GetWord();
    ADVWORD();

    while (!EndWord)
    {
        concatWord(&input, currentWord);
        ADVWORD();
    }

    printf("Kata saat ini : "); PrintWord(input);

    printf("\nBerhasil mengubah input user menjadi tipe data Word.");

    if (WordCompare(kata1, input))
    {
        printf("\nInput user ADALAH 'HMIF ITB'.\n");
    } else
    {
        printf("\nInput user BUKAN 'HMIF ITB'.\n");
    }

    printf("\nApabila input user terdiri dari huruf kapital, maka akan diubah menjadi huruf kecil semua\n");
    printf("Kata saat ini : "); PrintWord(toLower(input));
    printf("\n");

    return 0;
}

/* 

======================= Contoh penggunaan =======================
Misalkan input user = 'SUDO', maka program akan mengirim output :
-------------------------------------------------------
Akan membandingkan kata 'HMIF ITB' dengan input user
Kata pertama : HMIF
Kata kedua : ITB
Hasil concat kata : HMIF ITB

Masukkan kata : SUDO
Kata saat ini : SUDO
Berhasil mengubah input user menjadi tipe data Word.
Input user BUKAN 'HMIF ITB'.

Apabila input user terdiri dari huruf kapital, maka akan diubah menjadi huruf kecil semua
Kata saat ini : sudo
-------------------------------------------------------
*Note : fungsi stringLength sudah dipanggil di fungsi toKata,
        sehingga tidak dipanggil lagi di driver mesin kata.

*/