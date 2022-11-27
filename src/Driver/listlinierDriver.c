#include <stdio.h>
#include "../ADT/listlinier.h"

int main()
{
    List L1;
    CreateEmpty(&L1);
    printf("1. List berhasil dibuat\n");
    printf("   List kosong : "); PrintInfo(L1); printf("\n");

    InsVLast(&L1, toKata("6"));
    InsVLast(&L1, toKata("7"));
    InsVLast(&L1, toKata("8"));
    InsVFirst(&L1, toKata("5"));
    InsVFirst(&L1, toKata("4"));
    InsVFirst(&L1, toKata("3"));
    printf("2. Berhasil memasukkan infotype ke list\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    address p = Alokasi(toKata("1"));
    InsertFirst(&L1, p);
    address q = Alokasi(toKata("9"));
    InsertLast(&L1, q);
    address r = Alokasi(toKata("2"));
    InsertAfter(&L1, r, p);
    printf("3. Berhasil memasukkan infotype berdasarkan address ke dalam list\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    address satu;
    DelFirst(&L1, &satu);
    address semb;
    DelLast(&L1, &semb);

    DelP(&L1, toKata("2"));
    printf("4. Berhasil menghapus infotype pertama dan terakhir list berdasarkan address\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    infotype elmt_awal;
    DelVFirst(&L1, &elmt_awal);
    infotype elmt_akhir;
    DelVLast(&L1, &elmt_akhir);
    printf("5. Berhasil menghapus infotype pertama dan terakhir list\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    address b = Search(L1, toKata("7"));
    printf("6. Terdapat nilai 7 dalam list\n");

    address after = Alokasi(toKata("8"));
    InsertAfter(&L1, after, b);
    printf("7. Berhasil menambahkan infotype setelah address infotype 7\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    address ambil8;
    DelAfter(&L1, &ambil8, b);
    printf("8. Berhasil menghapus infotype setelah address infotype 7\n");
    printf("   List : "); PrintInfo(L1); printf("\n");

    Dealokasi(&ambil8);
    printf("9. Berhasil dealokasi infotype\n");

    return 0;
}

// Cara penggunaan driver : gcc -o listlinier ../ADT/listlinier.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c listlinierDriver.c