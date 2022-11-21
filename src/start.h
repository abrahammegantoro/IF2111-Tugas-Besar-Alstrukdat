#ifndef __START_H__
#define __START_H__

#include<stdio.h>
#include"Driver/readTxtFile.h"
# include "ADT/array.h"

void start(TabKata* Game, Stack* historyGame);
/* Memulai program BNMO dan membaca file config.txt serta menyimpan isi file tersebut ke dalam array global */
/* I.S. array terdefinisi, program dalam main menu */
/* F.S. file config.txt berhasil dibaca dan isi file disimpan ke dalam array global, program BNMO dapat dijalankan */

#endif