#include "dinnerdash.h"

void runDinnerDash(){
    printf("Menu");
    Queue q;
    char *action;
    int actionIdx, foodIdx, ctr;
    ctr = 0;
    while (!isEnd(q, ctr)) {
        scanf("%s", action);
        identifyAction(action, &actionIdx, &foodIdx);
        if (actionIdx == 0) {
            cook(&q, foodIdx);
        } else {
            serve(&q, foodIdx);
        }
    }
}