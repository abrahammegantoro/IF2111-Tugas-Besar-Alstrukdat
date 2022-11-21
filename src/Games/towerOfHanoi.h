#ifndef TOWER_OF_HANOI
#define TOWER_OF_HANOI

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/stack.h"
#include "../boolean.h"

int playTowerOfHanoi();
/* Memainkan game tower of hanoi dan mengembalikan skor permainan */

boolean moveDisk(Stack* Tout, Stack* Tin);
/* Memindahkan Disk dari Tout ke Tin, jika berhasil mengembalikan nilai true */

void printTower(Stack T1, Stack T2, Stack T3);
/* Menampilkan tower ke layar
   I.S. Sembarang
   F.S. Tower ditampilkan ke layar */

void printGuideToH();
/* Mencetak panduan permainan
   I.S. sembarang
   F.S. Panduan tercetak pada layar */

#endif