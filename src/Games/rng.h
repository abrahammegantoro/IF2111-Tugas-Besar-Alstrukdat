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
boolean checkX(int x);
void runRNG();
/* 
    I.S  :
    F.S. :
*/

#endif