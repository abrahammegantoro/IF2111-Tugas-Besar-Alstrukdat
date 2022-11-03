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
void playGame(Queue *queueGame) {
    // KAMUS
    int i, j, option;
    ElType val;
    srand(time(NULL));

    // ALGORITMA
    if(!IsEmpty(*queueGame)) {
        printf("Berikut adalah daftar Game-mu\n");

        // Mencetak list game
        for (i = 0; i < length(*queueGame); i++) {
            printf("%d. ", i);
            dequeue(queueGame, &val);
            tulisGame(val);
            enqueue(queueGame, val);
            printf("\n");
        }
        if (isEmpty(*queueGame)) {
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        } else {
            printf("Loading "); tulisGame(HEAD(*queueGame)); printf(" ...\n\n");
            if (WordCompare(HEAD(*queueGame), toKata("RNG"))) {
                printf("Loading RNG ...\n\n");
                /* Masukan prosedur game RNG */
            } else if (WordCompare(HEAD(*queueGame), toKata("Diner DASH"))) {
                printf("Loading Diner DASH ...\n\n");
                /* Masukan prosedur game Diner DASH */
            } else if (WordCompare(HEAD(*queueGame), toKata("DINOSAUR IN EARTH")) || WordCompare(HEAD(*queueGame), toKata("RISEWOMAN")) || WordCompare(HEAD(*queueGame), toKata("EIFFEL TOWER"))) {
                printf("Game "); tulisGame(HEAD(*queueGame)); printf(" masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
            } else {
                printf("Game Over! Skor akhir: %d\n", rand());
            }
            dequeue(queueGame, &val);
        }
    } else {
        printf("Kamu tidak memiliki antrian Game apapun.\n");
    }
}