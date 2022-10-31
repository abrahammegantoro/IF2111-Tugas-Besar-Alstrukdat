#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include "../ADT/queue.h"
#include <stdlib.h>
#include "../boolean.h"

void cook();
void serve();
int identifyAction(); /* 0 Masak 1 Serve*/
void runDinnerDash();
boolean isEnd();

#endif