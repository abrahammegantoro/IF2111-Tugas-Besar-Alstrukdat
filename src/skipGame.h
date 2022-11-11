#ifndef __SKIP_GAME_H__
#define __SKIP_GAME_H__

#include <stdio.h>
#include "./ADT/queue.h"
#include "./ADT/mesinkata.h"
#include "playGame.h"
# include "./Games/rng.h"
# include "./Games/dinerdash.h"
# include "./Games/atcGame.h"

void skipGame (Queue* queueGame, Word command);
/* Melewatkan permainan sebanyak n
I.S. queueGame terdefinisi, mungkin kosong
F.S. Memainkan game pada Top queueGame sekarang
*/

#endif