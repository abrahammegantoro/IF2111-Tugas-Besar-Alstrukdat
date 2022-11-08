#include <stdio.h>
#include "../ADT/mesinkata.h"

int main()
{
    printf("Akan membandingkan kata 'HMIF ITB' dengan input user\n");
    printf("Masukkan kata : ");
    STARTWORD();

    // Testing apakah kata bisa dicetak ke layar
    PrintWord(currentWord);

    Word kata = GetWord();
    printf("\nBerhasil mengubah input user menjadi tipe data Word.\n");

    if (WordCompare(toKata("HMIF ITB"), kata))
    {
        printf("Input user ADALAH 'HMIF ITB'.\n");
    } else
    {
        printf("Input user BUKAN 'HMIF ITB'.\n");
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