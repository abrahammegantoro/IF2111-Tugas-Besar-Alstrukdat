#ifndef READ_FILE_TXT
#define READ_FILE_TXT

/* MODUL .txt file reader */
#include "../ADT/mesinkata.h"
#include "../ADT/array.h"
#include "../ADT/stack.h"
#include "../scoreboard.h"
#include <stdio.h>
# include "../boolean.h"

boolean readTxt(char* filesrc, TabKata* listGame, Stack* historyGame, ListScore* scoreboard);
/* Membaca file .txt dan menyimpan isinya ke dalam array of Word
I.S. listGame terdefinisi mungkin kosong tetapi tidak penuh
F.S. Isi listGame bertambah dari isi file .txt
*/

#endif