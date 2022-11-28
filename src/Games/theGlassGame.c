#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "theGlassGame.h"

int playTheGlassGame() {
    int score = 0, addscore, max, lives, stage = 1;
    int moves;
    addrNode Jump;

    for (int i = 8; i > 0; i--) {
        clear();
        printf("\n ___    ___           _______               __     __      _______                       \n/   \\  |   |   /\\    |     __|.-----.--.--.|__|.--|  |    |     __|.---.-.--------.-----.\n[   ]  |   |  /  \\   |__     ||  _  |  |  ||  ||  _  |    |    |  ||  _  |        |  -__|\n\\___/  |___| /____\\  |_______||__   |_____||__||_____|    |_______||___._|__|__|__|_____|\n                                 |__|\n\n================================== Petunjuk Permainan ==================================\n\n1. Kamu telah dijebak oleh para penjahat karena ditawari uang dengan jumlah yang sangat\n   besar dengan syarat bermain game! Namun, ternyata permainan yang diberikan sangatlah\n   mematikan.\n2. Kamu sedang berada dalam akhir-akhir permainan Squid Game. Tugasmu adalah melewati\n   lantai kaca. Lantai kaca ini terbagi menjadi dua dan salah satunya sangatlah rapuh.\n3. Lantai kaca yang kamu pilih berpotensi untuk pecah dan membuatmu terjatuh.\n4. Setiap kali kamu terjatuh, kamu akan dibawa kembali ke awal stage dan nyawamu akan\n   berkurang. Ingat, nyawamu terbatas!\n5. Kumpulkan poin sebanyak banyaknya dengan pergi hingga titik paling jauh.\n6. Permainan akan berakhir ketika semua nyawamu habis.\n\n========================================================================================\n\nPermainan akan dimulai dalam %d ...", i);
        sleep(1);
    } 

    BinTree Glass;
    do {
        max = 0;
        lives = stage * 2 + 1;
        generateGlass(&Glass, stage * 3);
        do {
            Jump = Glass;
            moves = 0;
            addscore = 0;
            boolean isJumped = false;
            do {
                clear();
                if (lives < stage * 2 + 1 && !isJumped) printf("Kamu harus mengulang dari awal stage\n");
                Word stepBefore = currentWord;
                currentWord = toKata("LEFT");
                do {
                    printf("[ Stage: %d\tNyawa: %d ]\n", stage, lives);
                    if (!isJumped) printCharacter(toKata("NONE"), false);
                    else printCharacter(stepBefore, false);
                    if (!(WordCompare(currentWord, toKata("LEFT")) || WordCompare(currentWord, toKata("RIGHT"))) || !EndWord) printf("\nMasukkan hanya bisa LEFT / RIGHT");
                    printf("\nLEFT/RIGHT > ");
                    STARTINPUT();
                    clear();
                } while (!(WordCompare(currentWord, toKata("LEFT")) || WordCompare(currentWord, toKata("RIGHT"))) || !EndWord);
                isJumped = true;
                if (WordCompare(currentWord, toKata("LEFT"))) {
                    Jump = Left(Jump);
                } else {
                    Jump = Right(Jump);
                }
                moves++;
                if (Jump != NULL) addscore += addscore + 1;
            } while (Jump != NULL && moves < stage * 3);
            if (moves < stage * 3) {
                lives--;
                printf("[ Stage: %d\t Nyawa: %d ]\n", stage, lives);
                printCharacter(currentWord, true);
                printf("\nKamu terjatuh!");
                printf("\nLEFT/RIGHT > ");
                PrintWord(currentWord);
                sleep(2);
            }
            if (max < addscore) max = addscore;
        } while (lives > 0 && moves < stage * 3);
        score += max;
        if (lives > 0) {
            stage++;
            printf("Selamat! kamu berhasil melewati babak ini.\nSkor kamu sementara adalah %d\n\nSiap-siap untuk menuju babak berikutnya...", score);
            sleep(3);
        }
    } while (lives > 0);
    printf("\n\nPermainan berakhir! Skor akhir kamu: %d\n\n", score);

    return score;
}

void generateGlass(BinTree *Glass, int n) {
    srand(time(NULL));
    addrNode P = AlokNode(1);
    (*Glass) = P;
    for (int i = 0; i < n; i++) {
        srand(rand());
        addrNode PNext = AlokNode(1);

        if (rand() % 2 == 0) {
            Left(P) = PNext;
        } else {
            Right(P) = PNext;
        }

        P = PNext;
    }
}

void printCharacter(Word leftOrRight, boolean isCracked) {
    if (WordCompare(leftOrRight, toKata("LEFT"))) {
        if (!isCracked) printf("\n      \n      ()\n     /|\\\n     \\| \\\n      |\\\n      | |\n    ________   ________\n   [        ] [        ]\n   ");
        else printf("\n   \n     ()__\n     /\\\n     | \\\n   '   |\\\n    ' /  \\ .\n    _/    ._   ________\n   [.  ' -/ ] [        ]\n   ");
    } else if (WordCompare(leftOrRight, toKata("RIGHT"))) {
        if (!isCracked) printf("\n      \n                 ()\n                 /|\\\n                 \\| \\\n                  |\\\n                  | |\n    ________   ________\n   [        ] [        ]\n   ");
        else printf("\n   \n                ()__\n                /\\\n                | \\\n              '   |\\\n               ' /  \\ .\n    ________   _/    ._\n   [        ] [.  ' -/ ]\n   ");
    } else {
        printf("\n   \n   \n   \n   \n   \n   \n    ________   ________\n   [        ] [        ]\n   ");
    }
}