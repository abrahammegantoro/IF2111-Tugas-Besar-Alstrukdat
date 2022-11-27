#ifndef WRITE_FILE_TXT
#define WRITE_FILE_TXT

/* MODUL .txt file writer */

#include "readTxtFile.h"
#include <stdio.h>

void writeTxt(char* filetarget, TabKata listGame, Stack historyGame, ListScore *scoreboard);
/* Membaca file .txt dan menyimpan isinya ke dalam array of Word
I.S. listGame dan historyGame terdefinisi mungkin kosong tetapi tidak penuh
F.S. Isi listGame dan historyGame disimpan pada file .txt
*/

#endif