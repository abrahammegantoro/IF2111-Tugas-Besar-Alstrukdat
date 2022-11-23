#include <stdio.h>
#include "resethistory.h"
#include "history.h"

void resethistory(Stack *historyGame)
{
    printf("Apakah kamu yakin infin melakukan reset history? (Y/N) : ");
    STARTINPUT();
    
    if (WordCompare(toKata("Y"), currentWord))
    {
        CreateEmptyStack(historyGame);
        printf("History berhasil di-reset\n");
    } else if (WordCompare(toKata("N"), currentWord))
    {
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan :\n");

        int count = 1;
        infotype dump;
        Stack temp; CreateEmptyStack(&temp);

        while (!IsEmptyStack(*historyGame))
        {
            printf("  %d. ", count);
            PrintWord(InfoTop(*historyGame));
            Pop(historyGame, &dump);
            Push(&temp, dump);
            count++;
            printf("\n");
        }

        while (!IsEmptyStack(temp))
        {
            Pop(&temp, &dump);
            Push(historyGame, dump);
        }
    } else
    {
        printf("Tolong masukkan command yang valid!\n");
    }
}
