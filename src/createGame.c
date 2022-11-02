#include <stdio.h>
#include "createGame.h"

int stringLength (char* str)
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

Word toKata(char* str)
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

void createGame(TabKata* daftarGame, char* inputGame)
/*  I.S. TabKata terdefinisi, inputGame terdefinisi
    F.S. Menambahkan inputGame sebagai elemen dari TabKata */
{
    if (IsFull(*daftarGame))
    {
        printf("Maaf, jumlah maksimum game sudah tercapai.\n");
    } else
    {
        Word newGame = toKata(inputGame);
        (*daftarGame).TI[(*daftarGame).Neff] = newGame;
        (*daftarGame).Neff += 1;
        printf("Game berhasil ditambahkan\n");
    }
}

/* Implementasi ketika command creategame dipanggil

int main(){
    char game[50]; // MaxEl dari Word
    printf("Masukkan nama game yang akan ditambahkan: ");
    scanf("%s", game);

    TabKata currentGame;
    MakeEmpty(&currentGame);
    createGame(&currentGame, game);

    TulisIsi(currentGame);
    return 0;
}

*/