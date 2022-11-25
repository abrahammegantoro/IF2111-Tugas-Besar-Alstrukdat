#include "../ADT/listsom.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SnakeHead 0
#define Fruit 111
#define Meteor 222
#define Obstacle 333
#define Empty -1


boolean IsGameOver(ListSnake S, ListObstacle obstacle);

void InitialSnake(ListSnake *S);

void InitialFood(ListSnake S, Point *fruit, ListObstacle obstacle);

void InitialMeteor(Point *meteor, Point fruit, ListObstacle obstacle);

void InitialObstacle(ListSnake S, ListObstacle *obstacle);

void ReadInput(ListSnake *S, Point meteor, ListObstacle obstacle);

boolean IsInputValid(Word input);

void MoveSnake(ListSnake *S, Point meteor, ListObstacle obstacle, Word Input);

void EatFruit(ListSnake *S, Point *fruit, Point Tail, ListObstacle obstacle);

void GrowSnake(ListSnake *S, Point Tail);

boolean IsHit(ListSnake *S, Point meteor);

void HitMeteor(ListSnake *S, Point meteor, boolean *isGameOver);

void DisplayRow(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle, int i);

void DisplayValue(int value);

void DisplaySpace(int value);

void DisplayMap(ListSnake S, Point fruit, Point meteor, ListObstacle obstacle);

int RunSnakeOnMeteor();

