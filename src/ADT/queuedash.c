#include "queuedash.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueueDash(QueueDash *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}


/* ********* Prototype ********* */
boolean isEmptyDash(QueueDash q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

int lengthDash(QueueDash q) {
/* Mengirimkan banyaknya elemen QueueDash. Mengirimkan 0 jika q kosong. */
    if (isEmptyDash(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void enqueueFood(QueueDash *q, FoodType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer. */
    if (isEmptyDash(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        IDX_TAIL(*q)++;
    }
    (*q).buffer[(*q).idxTail].foodID = val.foodID;
    (*q).buffer[(*q).idxTail].cookDuration = val.cookDuration;
    (*q).buffer[(*q).idxTail].sustain = val.sustain;
    (*q).buffer[(*q).idxTail].price = val.price;
}

void dequeueFood(QueueDash *q) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. IDX_HEAD "mundur";
        q mungkin kosong */
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

boolean isMember(QueueDash q, int id) {
/* Mengirimkan true jika terdapat id dalam queue Q dan sebaliknya */
    boolean found = false;
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        if (q.buffer[i].foodID == id) {
            found = true;
        }
    }
    return found;
}

int getIdx(QueueDash q, int id) {
/* Mengirimkan index dengan elemen id didalam Queue Q, Queue Q pasti memiliki elemen id */
    boolean found = false;
    int i = IDX_HEAD(q);
    while (!found) {
        if (q.buffer[i].foodID == id) {
            found = true;
        } else {
            i++;
        }
    }
    return i;
}


/* *** Display QueueDash *** */
void displayQueueMenu(QueueDash q) {
/* Proses : Menuliskan isi QueueDash dengan format queue order yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t| Durasi memasak\t| Ketahanan\t| Harga\n");
    printf("------------------------------------------------------------\n");
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
    {
        if (q.buffer[i].foodID != NIL) {
            printf("M%d\t| %d\t\t\t| %d\t\t| %d\n", (q).buffer[i].foodID, (q).buffer[i].cookDuration, (q).buffer[i].sustain, (q).buffer[i].price);
        }
    }
}

void displayQueueCook(QueueDash q) {
/* Proses : Menuliskan isi QueueDash dengan format queue cook yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("-------------------------------\n");
    if (!isEmptyDash(q)) {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (q.buffer[i].cookDuration != 0 && q.buffer[i].foodID != NIL) {
                printf("M%d\t| %d\n", (q).buffer[i].foodID, (q).buffer[i].cookDuration);
            }
        }
    } else {
        printf("\t|\n");
    }
}

void displayQueueServe(QueueDash q, QueueDash qO) {
/* Proses : Menuliskan isi QueueDash dengan format serve yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("----------------------------------\n");

    int count = 0;
    if (!isEmptyDash(q)) {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (q.buffer[i].cookDuration == 0 && q.buffer[i].foodID != NIL) {
                    if (isMember(qO, q.buffer[i].foodID)) {
                        count++;
                        printf("M%d\t| %d\n", (q).buffer[i].foodID, (q).buffer[i].sustain);
                    }
            }
        }
    }
    if (count == 0) {
        printf("\t|\n\n");
    } 
}
