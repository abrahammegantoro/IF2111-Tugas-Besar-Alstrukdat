#ifndef __SAVE_H__
#define __SAVE_H__

#include "./Driver/writeTxtFile.h"
#include <stdio.h>

/* MODUL Save */

void save(TabKata listGame, Word filename, List historyGame);
/*  Menyimpan state game pemain saat ini ke dalam suatu file.
    I.S. File tujuan mungkin sudah ada / belum ada.
    F.S. State game pemain tersimpan dalam suatu file. Jika file sudah ada maka file tersebut akan tergantikan.
*/

#endif