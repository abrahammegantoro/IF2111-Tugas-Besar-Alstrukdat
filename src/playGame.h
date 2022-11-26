#ifndef PLAY_GAME_H
#define PLAY_GAME_H

#include <stdio.h>
#include "./ADT/queue.h"
#include "./ADT/array.h"
#include "./ADT/mesinkata.h"
#include "./ADT/stack.h"

// Include game
#include "./Games/dinerdash.h"
#include "./Games/rng.h"
#include "./Games/atcGame.h"
#include "./Games/towerOfHanoi.h"
#include "./Games/hangman.h"
#include "./Games/snakeonmeteor.h"
#include "./Games/theGlassGame.h"

void printLoading(Word gameName);
/* Menampilkan loading screen ke layar */

int playGame(Queue* queueGame, Stack* historyGame);
/* Memainkan game yang ada pada defaultGame
I.S. queueGame terdefinisi, mungkin kosong
F.S. Game teratas dimainkan
*/

int selectGame(TabKata listGame, Queue queueGame);

#endif