#ifndef __LOAD_H__
# define __LOAD_H__

# include <stdio.h>
# include <stdlib.h>
# include "ADT/array.h"
# include "ADT/mesinkata.h"
# include "Driver/readTxtFile.h"

# define FDIR "./data/"

void load(Word currentWord, TabKata* Game, Stack* historyGame, ListScore* scoreboard);
/* Load file yang dimasukkan oleh user dan menyimpan isi dari file ke dalam array global */
/* I.S. Array terdefinisi, menerima input nama file dari user */
/* F.S. Load berhasil, isi file tersimpan di dalam array global Game */

# endif