#include <stdio.h>
#include "ADT/array.h"

void quit()
{
    printf("Apakah Anda ingin menyimpan file dan perubahannya pada sistem? (Y/N) : ");
    STARTWORD();

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
        STARTWORD();
    }

    if (WordCompare(toKata("Y"), currentWord))
    {
        printf("Program akan melakukan penyimpanan\n");
    } else if (WordCompare(toKata("N"), currentWord));
    {
        printf("Terima kasih sudah bermain!\n");
    }
}

int main()
{
    quit();
    return 0;
}