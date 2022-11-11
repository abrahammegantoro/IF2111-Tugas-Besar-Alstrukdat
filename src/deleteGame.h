# ifndef __DELETEGAME_H__
# define __DELETEGAME_H__

# include <stdio.h>
# include "ADT/array.h"
# include "ADT/mesinkata.h"
# include "listGame.h"
# include "boolean.h"
# include "ADT/queue.h"

boolean isExist(ElType Kata, Queue antrian);
/* Mengecek apakah List Game pada array global terdapat pada Queue global antrian */

void deleteGame(TabKata* file, Queue antrianGame);
/* Menghapus game yang tersedia pada array global*/
/* I.S Array dan Queue terdefinisi. mungkin kosong */
/* F.S game pada array global dihapus sesuai urutan yang dimasukkan oleh user */


#endif