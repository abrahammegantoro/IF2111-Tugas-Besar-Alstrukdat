#include <stdio.h>
#include "../ADT/array.h"

int main() {
    TabKata Arr;
    MakeEmpty(&Arr);

    printf("Jumlah elemen awal: %d\n", NbElmt(Arr));
    printf("Apakah kosong: %d\n", IsEmpty(Arr));
    for (int i = 1; i <= 25; i++) {
        SetEl(&Arr, i, toKata("DUMMY"));
    } 
    printf("\nJumlah elemen: %d\n", NbElmt(Arr));
    TulisIsi(Arr);

    printf("ID minimum: %d\nID maksimum: %d", IdxMinTab(Arr), IdxMaxTab(Arr));
    printf("Cek elemen ke-19\n");
    PrintWord(Arr.TI[19]);
    printf("\n");

    return 0;
}