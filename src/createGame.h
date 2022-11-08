#ifndef __CREATEGAME_H__
#define __CREATEGAME_H__

#include "ADT/array.h"
# include "ADT/mesinkata.h"
#include <stdio.h>

// int stringLength (char* str);
// /*  Fungsi yang menerima sebuah parameter str bertipe string
//     Kemudian mengembalikan panjang dari string tersebut */

// Word toKata(char* str);
// /*  Fungsi yang menerima sebuah paramater str bertipe string
//     Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */

void createGame(TabKata* daftarGame);
/*  I.S. TabKata terdefinisi, inputGame terdefinisi
    F.S. Menambahkan inputGame sebagai elemen dari TabKata */

#endif