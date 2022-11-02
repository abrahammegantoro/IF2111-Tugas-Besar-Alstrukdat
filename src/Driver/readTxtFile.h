#ifndef READ_FILE_TXT
#define READ_FILE_TXT

/* MODUL .txt file reader */

#include "../ADT/mesinkata.c"
#include "../ADT/array.c"

void readTxt(char* filesrc, TabKata* listGame);
/* Membaca file .txt dan menyimpan isinya ke dalam array of Word
I.S. listGame terdefinisi mungkin kosong tetapi tidak penuh
F.S. Isi listGame bertambah dari isi file .txt
*/

#endif