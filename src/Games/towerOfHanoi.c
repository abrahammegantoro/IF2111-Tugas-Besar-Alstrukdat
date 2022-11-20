#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "towerOfHanoi.h"

int playTowerOfHanoi() {
    int score = 10, turn = 1;
    float minus = 1;

    Stack T1, T2, T3;
    CreateEmptyStack(&T1);
    CreateEmptyStack(&T2);
    CreateEmptyStack(&T3);

    // Initialization
    for (int i = 4; i >= 0; i--) {
        Word disk; disk.Length = 0;
        for (int j = 0; j < (i * 2) + 1; j  ++) {
            disk.TabWord[disk.Length] = '#';
            disk.Length++;
        }
        Push(&T1, disk);
    }

    printGuideToH();
    
    Word Tin, Tout;
    boolean takeTurn;
    while (!(NbElmtStack(T3) == 5)) {
        takeTurn = false;
        printTower(T1, T2, T3);
        printf("\nTIANG ASAL   : ");
        STARTINPUT();
        
        if ((currentWord.Length == 1) && (currentWord.TabWord[0] - 'A' >= 0) && (currentWord.TabWord[0] - 'A' < 3)) {
            Tout = currentWord;
            printf("TIANG TUJUAN : ");
            STARTINPUT();
            if ((currentWord.Length == 1) && (currentWord.TabWord[0] - 'A' >= 0) && (currentWord.TabWord[0] - 'A' < 3)) {
                Tin = currentWord;
                if (WordCompare(Tin, Tout)) {
                    printf("\nTiang yang dipilih tidak boleh sama.");
                } else {
                    if (Tout.TabWord[0] == 'A') {
                        if (Tin.TabWord[0] == 'B') {
                            takeTurn = moveDisk(&T1, &T2);
                        } else {
                            takeTurn = moveDisk(&T1, &T3);
                        }
                    } else if (Tout.TabWord[0] == 'B') {
                        if (Tin.TabWord[0] == 'A') {
                            takeTurn = moveDisk(&T2, &T1);
                        } else {
                            takeTurn = moveDisk(&T2, &T3);
                        }
                    } else {
                        if (Tin.TabWord[0] == 'A') {
                            takeTurn = moveDisk(&T3, &T1);
                        } else {
                            takeTurn = moveDisk(&T3, &T2);
                        }
                    }
                    if (turn > 31 && minus < 9) {
                        minus = minus * 1.08;
                    }
                    if (takeTurn) {
                        printf("\nMemindahkan piringan ke %c...", Tin.TabWord[0]);
                        turn++;
                    }
                }
            } else {
                printf("\nMasukan tiang tidak valid.");
            }
        } else {
            printf("\nMasukan tiang tidak valid.");
        }
        sleep(2);
        system("cls");
    }
    if (turn > 31) {
        score = score - (int) minus;
    }
    printTower(T1, T2, T3);
    printf("\nKamu berhasil!\n\nSkor didapatkan: %d\n", score);
    return score;
}

boolean moveDisk(Stack* Tout, Stack* Tin) {
    if (IsEmptyStack(*Tout)) {
        printf("\nTiang asal kosong!\n");
        return false;
    }
    infotype moved, top;
    Pop(Tout, &moved);
    if (!IsEmptyStack(*Tin)) {
        if (InfoTop(*Tin).Length < moved.Length) {
            printf("\nPiringan tidak dapat menimpa piringan yang lebih kecil.\n");
            Push(Tout, moved);
            return false;
        }
    }
    Push(Tin, moved);
    return true;
}

void printTower(Stack T1, Stack T2, Stack T3) {
    infotype disk;
    for (int i = 0; i < 5; i++) {
        if (5 - i == NbElmtStack(T1)) {
            Pop(&T1, &disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
            PrintWord(disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
        } else {
            printf("    |    ");
        }
        printf(" ");
        if (5 - i == NbElmtStack(T2)) {
            Pop(&T2, &disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
            PrintWord(disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
        } else {
            printf("    |    ");
        }
        printf(" ");
        if (5 - i == NbElmtStack(T3)) {
            Pop(&T3, &disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
            PrintWord(disk);
            for (int j = disk.Length / 2; j < 4; j++) {
                printf(" ");
            }
        } else {
            printf("    |    ");
        }
        printf(" \n");
    }
    for (int i = 0; i < 3; i++) {
        printf(" /=====\\  ");
    }
    printf(" \n");
    for (int i = 0; i < 3; i++) {
        printf("    %c     ", 'A' + i);
    }
    printf(" \n");
}

void printGuideToH() {
    for (int i = 8; i > 0; i--) {
        printf(" _______                                        ___      _______                     __ \n|_     _|.-----.--.--.--.-----.----.    .-----.'  _|    |   |   |.---.-.-----.-----.|__|\n  |   |  |  _  |  |  |  |  -__|   _|    |  _  |   _|    |       ||  _  |     |  _  ||  |\n  |___|  |_____|________|_____|__|      |_____|__|      |___|___||___._|__|__|_____||__|\n\n================================== Petunjuk Permainan ==================================\n\n1. Permainan berakhir jika semua piringan berhasil dipindah ke tiang C.\n2. Hanya satu piringan yang dapat dipindahkan dalam satu putaran.\n3. Setiap putaran terdiri dari mengambil piringan bagian atas dari salah satu tumpukan\n   dan meletakkannya di atas tumpukan lainnya. Dengan kata lain, sebuah piringan hanya\n   dapat dipindahkan jika itu adalah piringan paling atas di tumpukan.\n4. Piringan yang lebih besar tidak boleh ditempatkan di atas piringan yang lebih kecil.\n\n========================================================================================\n\nPermainan akan dimulai dalam %d ...", i);
        sleep(1);
        system("cls");
    }
}