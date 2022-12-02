#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/listrek.h"

int main () {
    ListRek L1;

    printf("Percobaan alokasi integer <1> pada list\n");
    L1 = AlokasiLr(1);
    PrintList(L1);
    printf("List satu elemen: %d\n", IsOneElmtLr(L1));

    printf("\nMenambahkan 9 elemen list\n");
    for (int i = 2; i < 11; i++) {
        KonsB(L1, i);
    }
    PrintList(L1);

    ListRek L2;
    printf("\nMembuat 10 elemen list negatif\n");
    for (int i = 1; i < 11; i++) {
        L2 = Konso(-i, L2);
    }
    PrintList(L2);

    printf("\nMenyalin list pertama dan kedua\n");
    ListRek L1_copy = Copy(L1);
    ListRek L2_copy;
    MCopy(L2, &L2_copy);
    PrintList(L1_copy);
    PrintList(L2_copy);

    printf("\nMenggabungkan list pertama dan kedua ke dalam list ketiga\n");
    ListRek L3 = Concat(L1, L2);
    PrintList(L3);


    printf("\nMenggabungkan list salinan ke dalam list keempat (sudah dialokasi)\n");
    ListRek L4;
    MConcat(L1_copy, L2_copy, &L4);
    PrintList(L4);

    printf("\nJumlah elemen list gabungan adalah: %d dan %d\n", NbElmtList(L3), NbElmtList(L4));

    printf("Apakah angka <-20> ada pada list ketiga: %d\n", SearchLr(L3, -20));
    printf("Apakah angka <10> ada pada list keempat: %d\n", SearchLr(L4, 10));

    printf("\nDealokasi list pertama dan kedua\n");
    DealokasiLr(L1);
    DealokasiLr(L2);
}