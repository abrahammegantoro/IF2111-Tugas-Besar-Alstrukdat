#include "dinnerdash.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void addOrder(Queue *q)
{
    ElType val;
    val.foodID = IDX_TAIL(*q) + 1;
    val.cookDuration = rand() % 5 + 1;
    val.sustain = rand() % 5 + 1;
    val.price = (rand() % 50 + 10) * 1000;
    enqueue(q, val);
}

boolean isEnd(Queue q, int ctr)
{
    return ((length(q) == 7) || (ctr == 2));
}

void identifyCommand(Queue q, int *isCook, int *id)
{
    Word cook, serve, skip;
    cook.Length = 4;
    cook.TabWord[0] = 'C';
    cook.TabWord[1] = 'O';
    cook.TabWord[2] = 'O';
    cook.TabWord[3] = 'K';
    serve.Length = 5;
    serve.TabWord[0] = 'S';
    serve.TabWord[1] = 'E';
    serve.TabWord[2] = 'R';
    serve.TabWord[3] = 'V';
    serve.TabWord[4] = 'E';
    skip.Length = 4;
    skip.TabWord[0] = 'S';
    skip.TabWord[1] = 'K';
    skip.TabWord[2] = 'I';
    skip.TabWord[3] = 'P';

    if (!WordCompare(currentWord, skip))
    {
        (*isCook) = NIL;
        (*id) = NIL;
        if (WordCompare(currentWord, cook))
        {
            (*isCook) = 1;
        }
        else if (WordCompare(currentWord, serve))
        {
            (*isCook) = 0;
        }
        ADVWORD();
        if (currentWord.TabWord[0] == 'M')
        {
            if (currentWord.Length == 2)
            {
                (*id) = currentWord.TabWord[1] - '0';
            }
            else if (currentWord.Length == 3)
            {
                (*id) = (currentWord.TabWord[1] - '0') * 10 + (currentWord.TabWord[2] - '0');
            }
        }
        boolean isIndex = isMember(q, (*id));
        if (!isIndex)
        {
            (*id) = NIL;
        }
    }
    else
    {
        (*isCook) = 9999;
        (*id) = 9999;
    }
    while (!EndWord) {
        ADVWORD();
    }
}

void cook(Queue qO, Queue *q, int food, boolean *valid)
{
    if (isMember(qO, food))
    {
        int idx = getIdx(qO, food);
        enqueue(q, qO.buffer[idx]);
        (*valid) = true;
    }
    else
    {
        (*valid) = false;
    }
}

void serve(Queue *qO, Queue *q, int food, boolean *valid, int *saldo)
{
    if (isMember((*q), food))
    {
        int idx = getIdx((*q), food);
        if ((*q).buffer[idx].cookDuration == 0)
        {
            if (HEAD(*qO) == food)
            {
                (*saldo) += qO->buffer[qO->idxHead].price;
                dequeue(qO);
                (*valid) = true;
                (*q).buffer[idx].foodID = NIL;
                (*q).buffer[idx].sustain = NIL;
            }
            else
            {
                (*valid) = false;
            }
        }
        else
        {
            (*valid) = false;
        }
    }
    else
    {
        (*valid) = false;
    }
}

void reduceTime(Queue *q)
{
    for (int i = 0; i < length(*q); i++)
    {
        if ((*q).buffer[i].cookDuration != 0)
        {
            (*q).buffer[i].cookDuration--;
        }
        else
        {
            if ((*q).buffer[i].sustain > 0)
            {
                (*q).buffer[i].sustain--;
            }
            else if ((*q).buffer[i].sustain == 0)
            {
                (*q).buffer[i].sustain = NIL;
                (*q).buffer[i].foodID = NIL;
            }
        }
    }
}

void printDescription(Queue q, boolean isValid, int isCook, int id)
{
    if (isValid)
    {
        if (isCook == 1)
        {
            printf("Berhasil memasak M%d\n", id);
        }
        else if (isCook == 0)
        {
            printf("Berhasil menyajikan M%d\n", id);
        }
        else
        {
            printf("Berhasil melewati 1 putaran\n");
        }
    }
    else
    {
        if (isCook == 0)
        {
            if (id == HEAD(q))
            {
                printf("Gagal menyajikan M%d karena belum siap\n", id);
            }
            else
            {
                printf("Gagal menyajikan M%d karena M%d belum selesai\n", id, HEAD(q));
            }
        }
    }
    printf("================================================================\n");
}
void runDinnerDash()
{
    Queue qOrder, qCook;
    int isCook, id, customerCtr;
    char inputAction[10];
    int saldo;

    boolean isValid, isFirst;

    CreateQueue(&qOrder);
    CreateQueue(&qCook);
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
    {
        addOrder(&qOrder);
    }
    customerCtr = 0;
    saldo = 0;
    isValid = false;
    while (!isEnd(qOrder, customerCtr))
    {
        printf("SALDO : %d\n", saldo);
        if ((isValid) && (isCook == 9999))
        {
            addOrder(&qOrder);
        }
        displayQueueMenu(qOrder);
        displayQueueCook(qCook);
        displayQueueServe(qCook, qOrder);
        if ((isValid) && (isCook == 9999)) {
            reduceTime(&qCook);
        }
        isValid = false;
        printf("MASUKKAN COMMAND : ");
        STARTINPUT();
        identifyCommand(qOrder, &isCook, &id);
        while (isCook == NIL || id == NIL)
        {
            if (isCook == NIL)
            {
                printf("COMMAND TIDAK VALID\n");
            }
            else
            {
                if (id == NIL)
                {
                    printf("ID MAKANAN TIDAK VALID\n");
                }
            }
            printf("MASUKKAN COMMAND : ");
            STARTINPUT();
            identifyCommand(qOrder, &isCook, &id);
        }
        if (isCook == 1)
        {
            cook(qOrder, &qCook, id, &isValid);
        }
        else if (isCook == 0)
        {
            serve(&qOrder, &qCook, id, &isValid, &saldo);
            if (isValid)
            {
                customerCtr++;
            }
        }
        else
        {
            isValid = true;
            addOrder(&qOrder);
            reduceTime(&qCook);
        }
        if (customerCtr == 2) {
            printDescription(qOrder, isValid, isCook, id);
        }
        if (!isEnd(qOrder, customerCtr))
        {
            printDescription(qOrder, isValid, isCook, id);
        }
        sleep(1);
        system("cls");
    }
    printf("========= GAME BERAKHIR ==========\n");
    printf("          SKOR KAMU : %d     \n", saldo);
    printf("==================================");
}