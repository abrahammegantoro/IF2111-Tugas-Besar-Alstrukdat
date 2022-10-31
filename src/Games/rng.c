#include "rng.h"

int getRandom() {
    int num;
    srand(time(0));
    num = rand() % 100 + 1;
    return num;    
}

void runRNG() {
    int num = getRandom();
    int x;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\nTebakan : ");
    scanf("%d", &x);
    while (x != num) {
        if (x > num) {
            printf("Lebih kecil");
        } else {
            printf("Lebih besar");
        }
        printf("\nTebakan : ");
        scanf("%d", &x);
    }
    printf("Ya, X adalah %d", num);
}