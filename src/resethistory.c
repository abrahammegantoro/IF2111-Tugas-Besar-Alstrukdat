#include <stdio.h>
#include "resethistory.h"
#include "history.h"

void resethistory(Stack *historyGame)
{
    printf("Apakah kamu yakin ingin melakukan reset history? (YA/TIDAK) : ");
    STARTINPUT();
    
    if (WordCompare(toKata("YA"), currentWord))
    {
        if (!IsEmptyStack(*historyGame))
        {
            CreateEmptyStack(historyGame);
            printf("History berhasil di-reset.\n");
        } else
        {
            printf("Belum ada game yang pernah dimainkan. History gagal dihapus.\n");
        }
    } else if (WordCompare(toKata("TIDAK"), currentWord))
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
            count += 1;
            
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
