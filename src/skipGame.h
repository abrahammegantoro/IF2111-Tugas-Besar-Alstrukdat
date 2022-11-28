#ifndef __SKIP_GAME_H__
#define __SKIP_GAME_H__

#include <stdio.h>
#include "./ADT/queue.h"
#include "./ADT/mesinkata.h"
#include "./ADT/listlinier.h"
#include "playGame.h"
# include "./Games/rng.h"
# include "./Games/dinerdash.h"
# include "./Games/atcGame.h"

int skipGame (Queue* queueGame, Word command, Stack* historyGame);
/* Melewatkan permainan sebanyak n
I.S. queueGame terdefinisi, mungkin kosong
F.S. Memainkan game pada Top queueGame sekarang
*/

#endif