#include <stdio.h>
#include "../ADT/stack.h"

int main()
{
    Stack S;
    CreateEmptyStack(&S);

    printf("1. Stack berhasil dibuat\n");
    printf("2. Apakah Stack kosong? ");

    if(IsEmptyStack(S))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    Push(&S, toKata("5"));
    Push(&S, toKata("4"));
    Push(&S, toKata("3"));
    Push(&S, toKata("2"));
    Push(&S, toKata("1"));

    printf("3. Berhasil menambahkan infotype ke dalam Stack\n");
    printf("4. Apakah Stack kosong? ");

    if(IsEmptyStack(S))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }
    
    printf("5. Apakah Stack penuh? ");

    if(IsFullStack(S))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    infotype word;
    printf("6. Isi Stack :\n");
    while (!IsEmptyStack(S))
    {
        printf("       ");
        PrintWord(InfoTop(S));
        printf("\n");
        Pop(&S, &word);
    }

    printf("7. Berhasil mengosongkan Stack\n");
    printf("8. Apakah Stack kosong? ");

    if(IsEmptyStack(S))
    {
        printf("Ya\n");
    } else
    {
        printf("Tidak\n");
    }

    return 0;
}

// Cara penggunaan driver : gcc -o stack ../ADT/stack.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c stackDriver.c