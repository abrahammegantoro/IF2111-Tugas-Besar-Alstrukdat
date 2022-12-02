#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/bintree.h"

// gcc -o bintree .\bintreeDriver.c ..\ADT\bintree.c ..\ADT\listrek.c

int main() {
    srand(time(NULL));

    printf("Pembuatan BinTree menggunakan fungsi (Preorder)\n");
    BinTree P1;
    P1 = Tree(rand() % 20, AlokNode(rand() % 20), AlokNode(rand() % 20));
    PrintPreorder(P1); printf("\n");
    DealokNode(Left(P1));
    DealokNode(Right(P1));
    DealokNode(P1);

    printf("\nPembuatan BinTree menggunakan fungsi (Inorder)\n");
    BinTree P2;
    MakeTree(rand() % 20, AlokNode(rand() % 20), AlokNode(rand() % 20), &P2);
    PrintInorder(P2); printf("\n");
    DealokNode(Left(P2));
    DealokNode(Right(P2));
    DealokNode(P2);

    printf("\nPembuatan BinTree 7 elemen dengan masukkan (bil. bulat) pengguna: \n");
    BinTree P3;
    P3 = BuildBalanceTree(7);
    printf("Mencetak hasil BinTree (Postorder)\n");
    PrintPostorder(P3); printf("\n");

    printf("\nMembuat BinTree satu elemen\n");
    BinTree P4;
    P4 = Tree(rand() % 20, NULL, NULL);
    PrintPreorder(P4); printf("\n");
    printf("Apakah BinTree kosong? %d\nApakah BinTree satu elemen? %d\n", IsTreeEmpty(P4), IsTreeOneElmt(P4));
    DealokNode(P4);

    printf("\nMembuat BinTree Uner dan Biner\n");
    BinTree P5;
    MakeTree(rand() % 20, AlokNode(rand() % 20), NULL, &P5);
    PrintInorder(P5); printf("\nBintree Uner Left? %d\n", IsUnerLeft(P5));
    PrintInorder(P5); printf("\nBintree Uner Right? %d\n", IsUnerRight(P5));
    PrintInorder(P5); printf("\nBintree Biner? %d\n", IsBiner(P5));
    printf("Pengecekan Skew BinTree\n");
    printf("\nSkew left? %d", IsSkewLeft(P5));
    printf("\nSkew right? %d\n", IsSkewRight(P5));


    DealokNode(Left(P5));
    DealokNode(P5);

    printf("\nMencari informasi dari BinTree\n");
    PrintTree(P3, 2);

    printf("Banyak elemen: %d\n", NbElmtLr(P3));
    printf("Banyak daun: %d\n", NbDaun(P3));
    printf("Tinggi: %d\n", Tinggi(P3));
    
    printf("\nMemodifikasi Tree\n");
    AddDaunTerkiri(&P3, 99);
    AddDaun(&P3, 99, 5, true);
    AddDaun(&P3, 99, 21, false);
    PrintTree(P3, 2); printf("\n");
    infotypeLr temp;
    DelDaunTerkiri(&P3, &temp);
    DelDaun(&P3, 21);
    PrintTree(P3, 2); printf("\n");

    ListRek L1, L2, L3;
    printf("\nMembuat list dari BinTree\n");
    L1 = MakeListDaun(P3);
    L2 = MakeListPreorder(P3);
    L3 = MakeListLevel(P3, 2);
    printf("List Daun\n"); PrintList(L1); printf("\n");
    printf("List Preorder\n"); PrintList(L2); printf("\n");
    printf("List Level 2\n"); PrintList(L3); printf("\n");

    printf("\nPencarian elemen <99> Tree\n");
    AddDaunTerkiri(&P3, 99);
    PrintTree(P3, 2); printf("\n");
    printf("Apakah ada elemen <99>? %d\n", BSearch(P3, 99));
}