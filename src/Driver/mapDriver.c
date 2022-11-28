#include <stdio.h>
#include "../ADT/map.h"

void PrintMap(Map M)
{
    int i = 0;
    printf("[");
    while (i != M.Count)
    {
        printf("<");
        printf("%d", M.Elements[i].Key);
        printf(",");
        printf("%d", M.Elements[i].Value);
        printf(">");
        i += 1;

        if (i != M.Count)
        {
            printf(",");
        }
    }
    printf("]\n");
}

int main()
{
    Map M;
    CreateEmptyMap(&M);

    printf("1. Map berhasil dibuat\n");
    printf("2. Apakah Map kosong? ");

    if(IsEmptyMap(M))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    InsertMapSorted(&M, 1, 1000);
    InsertMapSorted(&M, 3, 3000);
    InsertMapSorted(&M, 2, 4000);
    InsertMapSorted(&M, 5, 2500);
    InsertMapSorted(&M, 4, 5000);

    printf("3. Berhasil menambahkan key dan value ke dalam Set terurut sesuai value\n");
    printf("4. Apakah Map kosong? ");

    if(IsEmptyMap(M))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }
    
    printf("5. Apakah Map penuh? ");

    if(IsFullMap(M))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    printf("6. Isi Map : "); PrintMap(M);
    printf("7. Apakah 7 merupakan key dari Map? ");

    if(IsMemberMap(M, 7))
    {
        printf("Ya\n");
    } else
    {
        printf("Bukan\n");
    }

    printf("8. Apakah 3 merupakan key dari Map? ");

    if(IsMemberMap(M, 3))
    {
        printf("Ya\n");
    } else
    {
        printf("Bukan\n");
    }

    int val;
    val = Value(M, 3);
    printf("8. Value dari Key 3 : %d\n", val);

    DeleteMap(&M, 3);
    printf("9. Berhasil menghapus infotype dengan key 3\n");
    printf("   Isi Map : "); PrintMap(M);  

    return 0;
}

// Cara penggunaan driver : gcc -o map ../ADT/map.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c mapDriver.c