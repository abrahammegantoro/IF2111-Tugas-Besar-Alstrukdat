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
void playGame(TabKata defaultGame, TabKata createdGame) {
    // KAMUS
    int i, j, option;
    srand(time(NULL));

    // ALGORITMA
    if(!IsEmpty(defaultGame)) {
        printf("Berikut adalah daftar Game-mu\n");

        // Mencetak list game
        for (i = 0; i < defaultGame.Neff + createdGame.Neff; i++) {
            printf("%d. ", i + 1);
            if (i < defaultGame.Neff) {
                tulisGame(defaultGame.TI[i]);
            } else {
                tulisGame(createdGame.TI[i - createdGame.Neff]);
            }
            printf("\n");
        }

        // Memilih game
        scanf("ENTER GAME: %d", &option);
        while (option < 1 || option > defaultGame.Neff + createdGame.Neff) {
            printf("Game yang dipilih tidak valid. Silakan masukan ulang game.");
            scanf("ENTER GAME: %d", &option);
        }

        if (option >= defaultGame.Neff) {
            printf("Loading ");
            tulisGame(createdGame.TI[option - defaultGame.Neff - 1]);
            printf(" ...\n\n");
            printf("Game Over! Skor akhir: %d\n", rand());
        } else {
            if (isKataEq(defaultGame.TI[option - 1], toKata("RNG"))) {
                printf("Loading RNG ...\n\n");
                /* Masukan prosedur game RNG */
            } else if (isKataEq(defaultGame.TI[option - 1], toKata("Diner DASH"))) {
                printf("Loading Diner DASH ...\n\n");
                /* Masukan prosedur game Diner DASH */
            } else {
                printf("Game ");
                tulisGame(defaultGame.TI[i - 1]);
                printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            }
        }
    } else {
        printf("Kamu tidak memiliki Game apapun.\n");
    }
}