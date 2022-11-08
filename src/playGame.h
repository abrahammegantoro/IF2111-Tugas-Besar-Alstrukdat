#ifndef PLAY_GAME_H
#define PLAY_GAME_H

#include <stdio.h>
#include "./ADT/queue.h"
#include "./ADT/mesinkata.h"

void printLoading(Word gameName);
/* Menampilkan loading screen ke layar */

void playGame(Queue* queueGame);
/* Memainkan game yang ada pada defaultGame
I.S. queueGame terdefinisi, mungkin kosong
F.S. Game teratas dimainkan
*/

#endif