# ifndef __QUEUEGAME_H__
# define __QUEUEGAME_H__

# include "ADT/queue.h"
# include "ADT/array.h"
# include "ADT/mesinkata.h"
# include "listGame.h"
# include <stdio.h>
# include "boolean.h"

void displayQueueGame(Queue antrianGame);
/* Menampilkan daftar antrian game yang ada */

void queueGame(TabKata file, Queue* antrianGame);
/* Menambahkan antrian yang diinput user ke dalam queue Game dari listGame yang ada */

# endif