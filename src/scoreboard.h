#ifndef scoreboard_H
#define scoreboard_H
#include <stdio.h>
#include"Driver/readTxtFile.h"
#include"ADT/map.h"
#include"ADT/set.h"
typedef struct {
    Map Score;
    Set Nama;
} ListScore;

void CreateListScore(ListScore *scoreBoard);
void printScoreboard(TabKata listGame, ListScore *scoreBoard);
void insertScore(Set *S, Map *M);
#endif