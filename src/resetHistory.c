#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "resetHistory.h"

void resetHistory(List* historyGame) {
    boolean valid = false;
    Word command;

    if (!IsEmptyList(*historyGame)) {
        do {
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (Y/N) ");
            STARTINPUT();
            if (!(WordCompare(currentWord, toKata("Y")) || WordCompare(currentWord, toKata("N")))) {
                printf("\nPerintah tidak valid, silahkan masukan ulang perintah.");
                sleep(1);
                system("cls");
            } else {
                command = currentWord;
                ADVWORD();
                if (EndWord) {
                    valid = true;
                } else {
                    printf("\nPerintah tidak valid, silahkan masukan ulang perintah.\n\n");
                    sleep(1);
                    system("cls");
                }
            }
        } while (!valid);

        if (WordCompare(command, toKata("Y"))) {
            CreateEmpty(historyGame);
            if (IsEmptyList(*historyGame)) {
                printf("\nHistory berhasil di-reset.\n\n");
            } else {
                printf("\nHistory gagal di-reset karena kesalahan sistem.\n\n");
            }
        } else {
            printf("\nHistory tidak jadi di-reset. ");
            history(*historyGame, toKata("100"));
        }
    } else {
        printf("HIstory game sudah ksoong.\n\n");
    }
}