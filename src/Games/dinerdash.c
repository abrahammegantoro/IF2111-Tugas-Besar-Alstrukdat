#include "dinerdash.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void addOrder(QueueDash *q)
{
    FoodType val;
    val.foodID = IDX_TAIL(*q) + 1;
    val.cookDuration = rand() % 5 + 1;
    val.sustain = rand() % 5 + 1;
    val.price = (rand() % 50 + 10) * 1000;
    enqueueFood(q, val);
}

boolean isEnd(QueueDash q, int ctr)
{
    return ((lengthDash(q) > 7) || (ctr == 2));
}

void identifyCommand(QueueDash q, int *isCook, int *id)
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

void cook(QueueDash qO, QueueDash *q, int food, boolean *valid)
{
    if (isMember(qO, food))
    {
        int idx = getIdx(qO, food);
        enqueueFood(q, qO.buffer[idx]);
        (*valid) = true;
    }
    else
    {
        (*valid) = false;
    }
}

void serve(QueueDash *qO, QueueDash *q, int food, boolean *valid, int *saldo)
{
    if (isMember((*q), food))
    {
        int idx = getIdx((*q), food);
        if ((*q).buffer[idx].cookDuration == 0)
        {
            if (HEAD_ID(*qO) == food)
            {
                (*saldo) += qO->buffer[qO->idxHead].price;
                dequeueFood(qO);
                (*valid) = true;
                (*q).buffer[idx].foodID = NIL;
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

void reduceTime(QueueDash *q)
{
    for (int i = 0; i < lengthDash(*q); i++)
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
                (*q).buffer[i].foodID = NIL;
            }
        }
    }
}

void printDescription(QueueDash q, boolean isValid, int isCook, int id)
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
            if (id == HEAD_ID(q))
            {
                printf("Gagal menyajikan M%d karena belum siap\n", id);
            }
            else
            {
                printf("Gagal menyajikan M%d karena M%d belum selesai\n", id, HEAD_ID(q));
            }
        }
    }
    printf("================================================================\n");
    if (isValid) {
        if (isCook == 1) {
            printf("                                           _            \n                                          | |           \n  _ __ ___   ___ _ __ ___   __ _ ___  __ _| | __        \n | '_ ` _ \\ / _ \\ '_ ` _ \\ / _` / __|/ _` | |/ /        \n | | | | | |  __/ | | | | | (_| \\__ \\ (_| |   <   _  _  _ \n |_| |_| |_|\\___|_| |_| |_|\\__,_|___/\\__,_|_|\\_\\ (_)(_)(_)\n                                                        \n");
            printf("================================================================\n");
        } else if (isCook == 0) {
            printf("                                   _ _ _                       \n                                  (_|_) |                      \n  _ __ ___   ___ _ __  _   _  __ _ _ _| | ____ _ _ __          \n | '_ ` _ \\ / _ \\ '_ \\| | | |/ _` | | | |/ / _` | '_ \\         \n | | | | | |  __/ | | | |_| | (_| | | |   < (_| | | | |  _  _  _ \n |_| |_| |_|\\___|_| |_|\\__, |\\__,_| |_|_|\\_\\__,_|_| |_| (_)(_)(_)\n                        __/ |    _/ |                          \n                       |___/    |__/                           \n");
            printf("================================================================\n");
        } else {
            printf("     _    _                   \n    | |  (_)                  \n ___| | ___ _ __              \n/ __| |/ / | '_ \\             \n\\__ \\   <| | |_) |  _  _  _ \n|___/_|\\_\\_| .__/  (_)(_)(_)\n           | |                \n           |_|                \n");
            printf("================================================================\n");
        }
    }
}
void runDinerDash()
{  
    system("cls");
    
    QueueDash qOrder, qCook;
    int isCook, id, customerCtr;
    char inputAction[10];
    int saldo;

    boolean isValid, isFirst;

    CreateQueueDash(&qOrder);
    CreateQueueDash(&qCook);
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
        printf("[===================== Selamat Datang di =====================]\n");
        printf("                                                            _\n  _____  _                   _____            _            / )\n |  __ \\(_)                 |  __ \\          | |     |||| / /\n | |  | |_ _ __   ___ _ __  | |  | | __ _ ___| |__   ||||/ /\n | |  | | | '_ \\ / _ \\ '__| | |  | |/ _` / __| '_ \\  \\__(_/\n | |__| | | | | |  __/ |    | |__| | (_| \\__ \\ | | |  ||//\n |_____/|_|_| |_|\\___|_|    |_____/ \\__,_|___/_| |_|  ||/\n                                                     (|| \n                                                      \"\"");
        printf("\n[=============================================================]\n\n");
        printf("SALDO : %d\n", saldo);
        displayQueueMenu(qOrder);
        displayQueueCook(qCook);
        displayQueueServe(qCook, qOrder);
        if (isValid) {
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
        }
        if (customerCtr == 2) {
            printDescription(qOrder, isValid, isCook, id);
        }
        if (isValid)
        {
            addOrder(&qOrder);
        }
        if (!isEnd(qOrder, customerCtr))
        {
            printDescription(qOrder, isValid, isCook, id);
        }
        sleep(2);
        system("cls");
    }
    printf(" ___ __                                                  __ ___ \n");
    printf("|  _/ /                                                  \\ \\_  |\n");
    printf("| || |    __ _  __ _ _ __ ___   ___  _____   _____ _ __   | || |\n");
    printf("| / /    / _` |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / / _ \\ '__|   \\ \\ |\n");
    printf("| \\ \\   | (_| | (_| | | | | | |  __/ (_) \\ V /  __/ |      / / |\n");
    printf("| || |   \\__, |\\__,_|_| |_| |_|\\___|\\___/ \\_/ \\___|_|     | || |\n");
    printf("|___\\_\\   __/ |                                          /_/___|\n");
    printf("         |___/                                                 \n");
    printf("===============================================================\n");
    printf("\t\t\tSKOR KAMU : %d\t\t\t\t\t\n", saldo);
    printf("===============================================================\n");
}