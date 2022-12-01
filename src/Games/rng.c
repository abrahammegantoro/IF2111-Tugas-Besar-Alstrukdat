#include "rng.h"
#include <unistd.h>

int getRandom() {
    int num;
    srand(time(0));
    num = rand() % 100 + 1;
    return num;    
}
void getX(int *x) {
    int num = 0;
    printf(" ==> Tebak X : ");
    STARTINPUT();
    Word input = currentWord;
    ADVWORD();
    if (EndWord && input.Length != 0) {
        int i = 0;
        boolean found = false;
        while (i < input.Length && !found) {
            if (input.TabWord[i] < '0' || input.TabWord[i] > '9') {
                found = true;
            }
            i++;
        }
        if (found) {
            printf("Input tidak valid\n");
            getX(x);
        } else {
            for (int i = 0; i < input.Length; i++) {
                num = num * 10 + (input.TabWord[i] - '0');
            }
            *x = num;
        }
    } else {
        printf("Input tidak valid\n");
        getX(x);
    }
    while (!EndWord) {
        ADVWORD();
    }
    currentWord.Length = 0;
}

boolean checkX(int x) {
    if (x >= 1 && x <= 100) {
        return true;
    } else {
        return false;
    }
}
int runRNG() {
    printf(" .----------------.  .-----------------. .----------------. \n");
    printf("| .--------------. || .--------------. || .--------------. |\n");
    printf("| |  _______     | || | ____  _____  | || |    ______    | |\n");
    printf("| | |_   __ \\    | || ||_   \\|_   _| | || |  .' ___  |   | |\n");
    printf("| |   | |__) |   | || |  |   \\ | |   | || | / .'   \\_|   | |\n");
    printf("| |   |  __ /    | || |  | |\\ \\| |   | || | | |    ____  | |\n");
    printf("| |  _| |  \\ \\_  | || | _| |_\\   |_  | || | \\ `.___]  _| | |\n");
    printf("| | |____| |___| | || ||_____|\\____| | || |  `._____.'   | |\n");
    printf("| |              | || |              | || |              | |\n");
    printf("| '--------------' || '--------------' || '--------------' |\n");
    printf(" '----------------'  '----------------'  '----------------' \n");
    int num = getRandom();
    int x;
    int try = 10;
    int first = 0;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("X adalah sebuah bilangan bulat antara 1 dan 100.\n");
    printf("++++++++++++++++++++++\n");
    printf("Sisa kesempatan : %d\n", try);
    printf("++++++++++++++++++++++\n");
    getX(&x);
    while (!checkX(x)) {
        printf("Input tidak valid, masukkan antara 1 sampai 100\n");
        getX(&x);
    }
    while (x != num && try > 1) {
        if (x > num) {
            printf("~ LEBIH KECIL ~\n");
        } else {
            printf("~ LEBIH BESAR ~\n");
        }
        try--;
        printf("++++++++++++++++++++++\n");
        printf("Sisa kesempatan : %d\n", try);
        printf("++++++++++++++++++++++\n");
        getX(&x);
        while (!checkX(x)) {
            printf("Input tidak valid, masukkan antara 1 sampai 100\n");
            getX(&x);
        }        
    }
    if (x == num) {
        printf("Selamat! Anda berhasil menebak X.\n");
    } else {
        try--;
        printf("Anda telah kehabisan kesempatan. X adalah %d.\n", num);
    }
    printf(" ___ __                                                  __ ___ \n");
    printf("|  _/ /                                                  \\ \\_  |\n");
    printf("| || |    __ _  __ _ _ __ ___   ___  _____   _____ _ __   | || |\n");
    printf("| / /    / _` |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / / _ \\ '__|   \\ \\ |\n");
    printf("| \\ \\   | (_| | (_| | | | | | |  __/ (_) \\ V /  __/ |      / / |\n");
    printf("| || |   \\__, |\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_|     | || |\n");
    printf("|___\\_\\   __/ |                                          /_/___|\n");
    printf("         |___/                                                 \n");
    printf("===============================================================\n");
    printf("\t\t\tSKOR KAMU : %d\t\t\t\t\t\n", ((try) * 1000));
    printf("===============================================================\n");
    return ((try) * 1000);
}