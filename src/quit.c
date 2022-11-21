#include <stdio.h>
#include "ADT/array.h"
#include "quit.h"

void quit(TabKata Game, Queue* antrianGame, Stack historyGame)
{
    printf("Apakah Anda ingin menyimpan file dan perubahannya pada sistem? (Y/N) : ");
    STARTINPUT();

    while (!WordCompare(toKata("Y"), currentWord) && !WordCompare(toKata("N"), currentWord))
    {
        if (WordCompare(toKata("y"), currentWord) || WordCompare(toKata("n"), currentWord))
        {
            printf("Tolong masukkan command dengan huruf besar ^_^\n");
        } else
        {
            printf("Tolong masukkan input yang valid!\n");
        }

        printf("Apakah Anda ingin menyimpan file dan perubahannya pada sistem? (Y/N) : ");
        STARTINPUT();
    }

    if (WordCompare(toKata("Y"), currentWord))
    {
        printf("Masukkan nama file <filename.txt> : ");
        STARTINPUT();
        save(Game, currentWord, historyGame);
    }

    ElType val;
    while(!isEmpty(*antrianGame)){
        dequeue(antrianGame, &val);
    }
    printf("Terima kasih sudah bermain!\n");
}
/**
int main()
{
    TabKata Game;
    Make Empty(&Game);
    
    quit(Game);
    return 0;
}
**/