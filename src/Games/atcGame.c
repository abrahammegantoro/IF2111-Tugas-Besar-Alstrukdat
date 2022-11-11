#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "atcGame.h"

boolean isOver;

// int main() {
//     playAtc();
// }

void playAtc() {
    boolean isOver = false;
    srand(time(NULL));

    Queue BandaraM, BandaraB;
    createBandara(&BandaraB);
    createBandara(&BandaraM);

    TabKata LandingM, LandingB;
    MakeEmpty(&LandingM);
    MakeEmpty(&LandingB);

    printGuide();   

    Langit L; L.NEff = 0;

    int countM = 0, countB = 0, score = 0;
    float diff = 1;

    Queue Pesawat;
    int x = rand();
    if (x % 2 == 0) {
        createPesawat(&Pesawat, countM, 'M');
        countM++;
    } else {
        createPesawat(&Pesawat, countB, 'B');
        countB++;
    }
    insertPesawat(&L, Pesawat);

    while (!isOver) {
        system("cls");
        printf("SCORE: %d\n\n", score);
        printStatus(BandaraM, BandaraB, L);

        while (countM + countB < diff) {
            srand(rand());
            x = rand();
            if (x % 2 == 0) {
                createPesawat(&Pesawat, countM, 'M');
                countM++;
            } else {
                createPesawat(&Pesawat, countB, 'B');
                countB++;
            }
            insertPesawat(&L, Pesawat);
        }

        do {
            printf("MASUKKAN COMMAND: ");
            STARTINPUT();
            if (!isCommVal(currentWord, L)) {
                printf("\nCommand tidak valid.\n");
            }
        } while (!isCommVal(currentWord, L));

        if (!WordCompare(currentWord, toKata("SKIP"))) {
            accPesawat(&L, currentWord);
        }
        updateStatus(&BandaraM, &BandaraB, &L, &LandingM, &LandingB); 

        if (NbElmt(LandingM) > 1 || NbElmt(LandingB) > 1) {
            isOver = true;
        } else {
            if (NbElmt(LandingM) > 0) {
                insertLanding(&BandaraM, &LandingM);
                score += 100;
            } if (NbElmt(LandingB) > 0) {
                insertLanding(&BandaraB, &LandingB);
                score += 100;
            }
        }

        if (L.NEff < 30) diff = diff * 1.2;
        else diff = diff * 1.05;
    }
    printf("\n\n============================================================");
    printf("\nGame over! Skor akhir %d\n", score);
    printf("Terjadi kecelakaan pada pesawat ");
    if (LandingM.Neff > 1) {
        for (int i = 0; i < LandingM.Neff; i++) {
            PrintWord(LandingM.TI[i]);
            printf(" ");
        }
        if (LandingB.Neff > 1) printf("dan ");
    }
    if (LandingB.Neff > 1) {
        for (int i = 0; i < LandingB.Neff; i++) {
            PrintWord(LandingB.TI[i]);
            printf(" ");
        }
    }
    sleep(5);
    system("cls");
}

void createPesawat (Queue *Pesawat, int ID, char color) {
    Word num = intToWord(ID);
    srand(rand());

    for (int i = num.Length; i > 0; i--) {
        num.TabWord[i] = num.TabWord[i-1];
    }
    num.Length++;
    num.TabWord[0] = color;

    CreateQueue(Pesawat);

    int len = rand() % 9 + 6;
    for (int i = 1; i < len; i++) {
        enqueue(Pesawat, toKata("-"));
    }
    enqueue(Pesawat, num);
}

void createBandara(Queue *Bandara) {
    CreateQueue(Bandara);
    for (int i = 0; i < 10; i++) {
        enqueue(Bandara, toKata("  -  "));
    }
}

void printLangit(Langit L) {
    ElType temp;
    for (int i = 0; i < L.NEff; i++) {
        printf("o- ");
        for (int j = 0; j < length(L.Pesawat[i]); j++) {
            dequeue(&L.Pesawat[i], &temp);
            if (WordCompare(temp, toKata("-"))) {
                printf("  -  ");
            } else {
                if (temp.TabWord[0] == 'M') {
                    printf("\033[1;31m"); 
                } else {
                    printf("\033[1;35m");
                }
                printf("=[|=<");
                printf("\033[0m");
            }
            enqueue(&L.Pesawat[i], temp);
        }
        printf(" -o ");
        PrintWord(L.ID[i]);
        printf("\n\n");
    }
}

void printBandara(Queue B, char warna) {
    if (warna == 'M') {
        printf("\033[1;31m"); 
    } else{
        printf("\033[1;35m");
    }
    printf("+------------------------------------------------------+\n|                                                      |\n|  ");
    for (int i = 0; i < length(B); i++) {
        ElType dump;
        dequeue(&B, &dump);
        if (WordCompare(dump, toKata("  -  "))) {
            PrintWord(dump);
        } else {
            printf("=[|=<");
        }
        enqueue(&B, dump);
    }
    printf("  |\n|                                                      |\n+------------------------------------------------------+\n\n");
    printf("\033[0m");
}

void printGuide() {
    for (int i = 8; i >= 1; i--) {
        system("cls");
        printf("==================================================================\n");
        printf("                       Petunjuk Permainan\n");
        printf("==================================================================\n");
        printf("1. Permainan ini merupakan simulasi dari Air Traffic Control.\n2. Tugasmu adalah menjaga agar pesawat tidak bertubrukan saat ingin mendarat.\n3. Setiap satu putaran, setiap pesawat akan semakin dekat ke Bandara masing-masing\n4. Gunakan command <ID Pesawat> untuk mempercepat pesawat mendarat\n5. Gunakan command SKIP untuk melewati satu putaran\n6. Pastikan agar pesawat dengan warna sama tidak mendarat bersamaan.\n7. Selamat bermain!\n\n");
        printf("Game akan dimulai dalam %d ...", i);
        sleep(1);
    }
}

void printStatus(Queue M, Queue B, Langit L) {
    printf("Bandara Merah\n");
    printBandara(M, 'M');
    printf("Bandara Biru\n");
    printBandara(B, 'B');

    printf("[ Langit ]\n\n");
    printLangit(L);
}

void insertPesawat(Langit *L, Queue Pesawat) {
    ElType temp;
    (*L).Pesawat[(*L).NEff] = Pesawat;
    for (int i = 0; i < length(Pesawat); i++) {
        dequeue(&Pesawat, &temp);
        if (!WordCompare(temp, toKata("-"))) {
            (*L).ID[(*L).NEff] = temp;
        } 
        enqueue(&Pesawat, temp);
    }
    (*L).NEff++;
}

void insertLanding(Queue *Bandara, TabKata *Landing) {
    if (!IsEmpty(*Landing)) {
        ElType dump;
        dequeue(Bandara, &dump);
        enqueue(Bandara, (*Landing).TI[0]);
        MakeEmpty(Landing);
    }
}

void deletePesawat(Langit *L, Queue *Bandara, Word ID) {
    ElType dump;
    boolean found = false; 
    for (int i = 0; i < (*L).NEff - 1; i++) {
        if (WordCompare((*L).ID[i], ID)) {
            found = true;
        }
        if (found) {
            (*L).Pesawat[i] = (*L).Pesawat[i + 1];
            (*L).ID[i] = (*L).ID[i + 1];
        }
    }
    (*L).NEff--;
    dequeue(Bandara, &dump);
    enqueue(Bandara, toKata("P"));
}

void updateStatus(Queue *M, Queue *B, Langit *L, TabKata *LandingM, TabKata *LandingB) {
    ElType dump;
    dequeue(M, &dump);
    dequeue(B, &dump);
    enqueue(M, toKata("  -  "));
    enqueue(B, toKata("  -  "));

    for (int i = 0; i < (*L).NEff; i++) {
        if (!WordCompare(HEAD((*L).Pesawat[i]), toKata("-"))) {
            if (HEAD((*L).Pesawat[i]).TabWord[0] == 'M') {
                SetEl(LandingM, (*LandingM).Neff, (*L).ID[i]);
            } else {
                SetEl(LandingB, (*LandingB).Neff, (*L).ID[i]);
            }
            for (int j = i; j < (*L).NEff - 1; j ++) {
                (*L).Pesawat[j] = (*L).Pesawat[j + 1];
                (*L).ID[j] = (*L).ID[j + 1];
            }
            (*L).NEff--;
        } else {
            dequeue(&L->Pesawat[i], &dump);
        }
    }
}

void accPesawat(Langit *L, Word comm) {
    ElType dump;
    for (int i = 0; i < (*L).NEff; i++) {
        if (WordCompare((*L).ID[i], comm)) {
            while (WordCompare(HEAD((*L).Pesawat[i]), toKata("-"))) {
                dequeue(&L->Pesawat[i], &dump);
            }
        }
    }
}

boolean isCommVal(Word comm, Langit L) {
    if (WordCompare(currentWord, toKata("SKIP"))) {
        return true;
    } else {
        for (int i = 0; i < L.NEff; i++) {
            if (WordCompare(currentWord, L.ID[i])) {
                return true;
            }
        }
        return false;
    }
}
