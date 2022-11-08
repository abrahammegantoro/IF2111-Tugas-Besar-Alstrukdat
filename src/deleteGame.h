# ifndef __DELETEGAME_H__
# define __DELETEGAME_H__

# include <stdio.h>
# include "ADT/array.h"
# include "ADT/mesinkata.h"
# include "listGame.h"
# include "boolean.h"
# include "ADT/queue.h"

boolean isExist(ElType Kata, Queue antrian);

void deleteGame(TabKata* file, Queue antrianGame);
/* Menghapus game yang tersedia */

#endif