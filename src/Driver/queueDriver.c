# include "../ADT/queue.h"

int main(){
    STARTINPUT();
    Queue q;
    CreateQueue(&q);
    enqueue(&q, currentWord);
    printf("udah sekali");
    STARTINPUT();
    enqueue(&q, currentWord);
    if (isEmpty(q)){
        printf("kosong");
    }else{
        printf("%d", length(q));
    }
    return 0;
}
