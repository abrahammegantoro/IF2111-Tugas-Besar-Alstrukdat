#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/queuedash.h"
#include "../ADT/mesinkata.h"

void addOrder(QueueDash *q);

boolean isEnd(QueueDash q, int ctr);
void identifyCommand(QueueDash q, int *isCook, int* id);

void cook(QueueDash qM, QueueDash *q, int food, boolean *valid);
void serve(QueueDash *qM, QueueDash *q, int food, boolean *valid, int *saldo);
void reduceTime(QueueDash *q);
void runDinnerDash();


#endif