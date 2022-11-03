#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playGame.h"

/* Implementasi playGame.h */

/*  Menerima sebuah parameter string bertipe string
    Mengirimkan panjang sebuah string */
int stringLength (char* string) {
	int len = 0;
	while (string[len] != '\0') {
		len++;
	}
	return len;
}

/*  Menerima sebuah paramater command bertipe string
    Mengirimkan kata yang elemen of arraynya berasal dari command */
Word toKata(char* command) {
	Word Kata;
	for (int i = 0; i < stringLength(command); i++) {
		Kata.TabWord[i] = command[i];
	}
	Kata.Length = stringLength(command);
	return Kata;
}

boolean isKataEq(Word Kata1, Word Kata2) {
    if (Kata1.Length != Kata2.Length) return false;
    for (int i = 0; i < Kata1.Length; i++) {
        if (Kata1.TabWord[i] != Kata2.TabWord[i]) return false;
    }
    return true;
}

void tulisGame(Word Game) {
    for (int i = 0; i < Game.Length; i++) {
        printf("%c", Game.TabWord[i]);
    }
}

// Game yang diload dan game yang dibuat akan dipisah karena perlu ada penanganan game yang sedang maintenance (game yang bukan game RNG, Dine Dash, atau game buatan)
void playGame(TabKata listGame) {
    // KAMUS
    int i, j, option;
    srand(time(NULL));

    // ALGORITMA
    if(!IsEmpty(listGame)) {
        printf("Berikut adalah daftar Game-mu\n");

        // Mencetak list game
        for (i = 0; i < listGame.Neff; i++) {
            printf("%d. ", i + 1);
            tulisGame(listGame.TI[i]);
            printf("\n");
        }

        // Memilih game
        scanf("ENTER GAME: %d", &option);
        while (option < 1 || option > listGame.Neff) {
            printf("\nGame yang dipilih tidak valid. Silakan masukan ulang game.\n");
            scanf("ENTER GAME: %d", &option);
        }
        switch (option)
        {
        case 1:
            printf("Loading RNG ...\n\n");
            /* Masukan prosedur game RNG */
            break;
        case 2:
            printf("Loading Diner DASH ...\n\n");
            /* Masukan prosedur game Diner DASH */
            break;
        case 3:
            printf("Game "); tulisGame(listGame.TI[option - 1]); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            break;
        case 4:
            printf("Game "); tulisGame(listGame.TI[option - 1]); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            break;
        case 5:
            printf("Game "); tulisGame(listGame.TI[option - 1]); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            break;
        default:
            printf("Loading "); tulisGame(listGame.TI[option - 1]); printf(" ...\n\nGame Over! Skor akhir: %d\n", rand());
            break;
        }
    } else {
        printf("Kamu tidak memiliki Game apapun.\n");
    }
}