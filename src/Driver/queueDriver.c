# include <stdio.h>
# include "../ADT/queue.h"

int main(){
    Queue q;
    CreateQueue(&q);
    if (isEmpty(q)){
        printf("Queue kosong\n"); //bukti is empty menunjukkan queue kosong
    }
    printf("Masukkan kata : ");
    STARTINPUT();
    while(!WordCompare(currentWord, toKata("Keluar"))){
        enqueue(&q, currentWord); //memasukkan kata ke dalam queue
        printf("Berhasil melakukan queue\n");
        printf("Masukkan kata lagi (Ketik \"Keluar\" untuk mengakhiri masukkan) : ");
        STARTINPUT();
    }
    while(!isEmpty(q)){
        printf("Banyak antrian : %d\n", length(q)); 
        dequeue(&q, &currentWord); //mengeluarkan kata dari dalam queue dengan sistem FIFO
        PrintWord(currentWord);
        printf("\n");
    }
    return 0;
}