#include "rng.h"

int getRandom() {
    int num;
    srand(time(0));
    num = rand() % 100 + 1;
    return num;    
}
void getX(int *x) {
    printf("Tebakan : ");
    STARTINPUT();
    if (currentWord.Length == 1) {
        *x = currentWord.TabWord[0] - '0';
    } else if (currentWord.Length == 2) {
        *x = (currentWord.TabWord[0] - '0') * 10 + (currentWord.TabWord[1] - '0');
    } else if (currentWord.Length == 3) {
        *x = (currentWord.TabWord[0] - '0') * 100 + (currentWord.TabWord[1] - '0') * 10 + (currentWord.TabWord[2] - '0');
    } else {
        *x = 9999;
    }
}

boolean checkX(int x) {
    if (x >= 1 && x <= 100) {
        return true;
    } else {
        return false;
    }
}
void runRNG() {
    int num = getRandom();
    int x;
    int try = 10;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("X adalah sebuah bilangan bulat antara 1 dan 100.\n");
    printf("Anda memiliki 10 kesempatan untuk menebak X.\n");
    getX(&x);
    while (x != num && try > 0) {
        while (!checkX(x)) {
            printf("Tebakan Anda tidak valid. Silahkan masukkan angka antara 1 dan 100.\n");
            getX(&x);
        }
        if (x > num) {
            printf("Lebih kecil\n");
        } else {
            printf("Lebih besar\n");
        }
        printf("Sisa kesempatan : %d\n", --try);
        getX(&x);
    }
    if (x == num) {
        printf("Selamat! Anda berhasil menebak X.\n");
    } else {
        printf("Anda telah kehabisan kesempatan. X adalah %d.\n", num);
    }
    printf("======= Skor Anda : %d =======\n", try * 1000);
}