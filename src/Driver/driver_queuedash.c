#include <stdio.h>
#include "../ADT/queuedash.h"

int main() {
    QueueDash Q;
    CreateQueueDash(&Q);
    printf("Apakah queue kosong?\n");
    if (isEmptyDash(Q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    printf("Mengisi queue dengan 4 elemen\n");
    FoodType val, val2, val3, val4;
    val.foodID = 1;
    val.cookDuration = 2;
    val.sustain = 3;
    val.price = 4000;
    val2.foodID = 2;
    val2.cookDuration = 0;
    val2.sustain = 1;
    val2.price = 5000;
    val3.foodID = NIL;
    val3.cookDuration = 4;
    val3.sustain = 5;
    val3.price = 6000;
    val4.foodID = 4;
    val4.cookDuration = 6;
    val4.sustain = 7;
    val4.price = 7000;

    enqueueFood(&Q, val);
    enqueueFood(&Q, val2);
    enqueueFood(&Q, val3);
    enqueueFood(&Q, val4);
    displayQueueCook(Q);
    displayQueueMenu(Q);
    displayQueueServe(Q, Q);

    printf("Apakah queue kosong?\n");
    if (isEmptyDash(Q)) {
        printf("Ya\n");
    } else {
        printf("Tidak\n");
    }
    printf("Panjang queue: %d\n", lengthDash(Q));
    printf("Dequeue Q 1x\n");
    dequeueFood(&Q);
    printf("Panjang queue setelah dequeue: %d\n", lengthDash(Q));
    return 0;
}