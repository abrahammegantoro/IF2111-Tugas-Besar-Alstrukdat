#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/queuedash.h"
#include "../ADT/mesinkata.h"

void addOrder(Queue *q);

boolean isEnd(Queue q, int ctr);
void identifyCommand(Queue q, int *isCook, int* id);

void cook(Queue qM, Queue *q, int food, boolean *valid);
void serve(Queue *qM, Queue *q, int food, boolean *valid, int *saldo);
void reduceTime(Queue *q);
void runDinnerDash();


#endif