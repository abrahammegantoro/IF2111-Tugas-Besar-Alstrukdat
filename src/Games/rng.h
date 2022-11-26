#ifndef RNG_H
#define RNG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

int getRandom();
/* Mengembalikan angka random */

void getX(int *x);
/* Mengisi x dengan angka random
    I.S. x terdefinisi
    F.S. x terisi dengan angka random */

boolean checkX(int x);
/* Mengembalikan true jika x adalah angka antara 1 dan 100 */

int runRNG();
/* Memainkan game RNG dan mengembalikan skor permainan */

#endif