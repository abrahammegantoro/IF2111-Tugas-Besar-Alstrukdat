#ifndef PLAY_GAME_H
#define PLAY_GAME_H

#include <stdio.h>
#include "./ADT/queue.h"
#include "./ADT/mesinkata.h"
#include "./ADT/stack.h"

// Include game
#include "./Games/dinerdash.h"
#include "./Games/rng.h"
#include "./Games/atcGame.h"
#include "./Games/towerOfHanoi.h"

void printLoading(Word gameName);
/* Menampilkan loading screen ke layar */

void playGame(Queue* queueGame, Stack* historyGame);
/* Memainkan game yang ada pada defaultGame
I.S. queueGame terdefinisi, mungkin kosong
F.S. Game teratas dimainkan
*/

#endif