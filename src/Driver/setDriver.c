#include <stdio.h>
#include "../ADT/set.h"

void PrintSet(Set S)
{
    int i = 0;
    printf("[");
    while (i != S.Count)
    {
        PrintWord(S.Elements[i]);
        i += 1;

        if (i != S.Count)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int main()
{
    Set S1;
    CreateEmptySet(&S1);

    printf("1.  Set 1 berhasil dibuat\n");
    printf("2.  Apakah Set 1 kosong? ");

    if(IsEmptySet(S1))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    InsertSet(&S1, toKata("1"));
    InsertSet(&S1, toKata("2"));
    InsertSet(&S1, toKata("3"));
    InsertSet(&S1, toKata("4"));
    InsertSet(&S1, toKata("5"));

    printf("3.  Berhasil menambahkan infotype ke dalam Set 1\n");
    printf("4.  Apakah Set 1 kosong? ");

    if(IsEmptySet(S1))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }
    
    printf("5.  Apakah Set 1 penuh? ");

    if(IsFullSet(S1))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    printf("6.  Isi Set 1 : "); PrintSet(S1);

    Set S2;
    CreateEmptySet(&S2);

    InsertSet(&S2, toKata("4"));
    InsertSet(&S2, toKata("5"));
    InsertSet(&S2, toKata("6"));
    InsertSet(&S2, toKata("7"));
    InsertSet(&S2, toKata("8"));

    printf("7.  Set 2 berhasil dibuat dan diisi dengan infotype\n");
    printf("8.  Isi Set 2 : "); PrintSet(S2);

    Set temp;
    CreateEmptySet(&temp);

    temp = SetUnion(S1, S2);
    printf("9.  Hasil Union Set 1 dan Set 2 \t: "); PrintSet(S1);

    temp = SetIntersection(S1, S2);
    printf("10. Hasil Intersection Set 1 dan Set 2 \t: "); PrintSet(S1);

    temp = SetSymmetricDifference(S1, S2);
    printf("11. Hasil Difference Set 1 dan Set 2 \t: "); PrintSet(S1);

    temp = SetSubtract(S1, S2);
    printf("12. Hasil Subtract Set 1 dan Set 2 \t: "); PrintSet(S1);

    return 0;
}

// Cara penggunaan driver : gcc -o set ../ADT/set.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c setDriver.c