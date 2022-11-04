#include "mesinkata.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        // IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord()
{
    int i = 0;
    while (currentChar != MARK && currentChar != BLANK && i < NMax)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

Word GetWord()
/*  Fungsi yang menerima sebuah parameter currentWord bertipe Word
    Kemudian mengembalikan Word tersebut */
{
    return currentWord;
}

int stringLength(char *str)
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */
{
    int len = 0;
    while (str[len] != '\0')
    {
        len = len + 1;
    }

    return len;
}

Word toKata(char *str)
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */
{
    Word kata;
    kata.Length = stringLength(str);

    for (int i = 0; i < stringLength(str); i++)
    {
        kata.TabWord[i] = str[i];
    }

    return kata;
}

void PrintWord(Word kata)
/*  I.S. kata terdefinisi
    F.S. Program akan mencetak kata ke layar dan menghitung panjang katanya */
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabWord[i]);
    }
    printf("\nPanjang kata : %d\n", kata.Length);
}

boolean WordCompare(Word currentWord, Word inputWord)
/* Fungsi yang menerima dua parameter currentWord dan inputWord bertipe Word
   Kemudian mengembalikan sebuah boolean yang menyatakan apakah kedua Word adalah Word yang sama atau tidak */
{
    boolean found = false;
    int i = 0;

    if (currentWord.Length != inputWord.Length)
    {
        return found;
    }
    else
    {
        while (!found && i < currentWord.Length)
        {
            if (currentWord.TabWord[i] != inputWord.TabWord[i])
            {
                return found;
            }
            i += 1;
        }
        return !found;
    }
}

int StrToInt(char *str)
/* Fungsi yang menerima parameter berupa string dan mengembalikannya dalam bentuk integer */
{
    int i = 0;
    int res = 0;
    while (str[i] != '\0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return res;
}
