# ifndef __QUEUEGAME_H__
# define __QUEUEGAME_H__

# include "queue.h"
# include "array.h"
# include "listGame.h"
# include <stdio.h>

void displayQueueGame(Queue antrianGame);
/* Menampilkan daftar antrian game yang ada */

void queueGame(TabKata file, Queue* antrianGame);
/* Menambahkan antrian yang diinput user ke dalam queue Game dari listGame yang ada */

# endif