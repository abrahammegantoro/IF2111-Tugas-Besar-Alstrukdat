#include "queueDash.h"
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

boolean isFullDash(QueueDash q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (lengthDash(q) == CAPACITYDASH);
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
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
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
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

boolean isMember(QueueDash q, int id) {
    boolean found = false;
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        if (q.buffer[i].foodID == id) {
            found = true;
        }
    }
    return found;
}

int getIdx(QueueDash q, int id) {
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

void deleteFoodID(QueueDash *q, int id) {
    for (int i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
    {
        if (q->buffer->foodID == id) 
        {
            q->buffer->foodID = NIL;
        }
    }
    
}

/* *** Display QueueDash *** */
void displayQueueMenu(QueueDash q) {
/* Proses : Menuliskan isi QueueDash dengan format yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */
    printf("\nDaftar Pesanan\n");
    printf("Makanan\t| Durasi memasak\t| Ketahanan\t| Harga\n");
    printf("------------------------------------------------------------\n");
    for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
    {
        printf("M%d\t| %d\t\t\t| %d\t\t| %d\n", (q).buffer[i].foodID, (q).buffer[i].cookDuration, (q).buffer[i].sustain, (q).buffer[i].price);
    }
}

void displayQueueCook(QueueDash q) {
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("-------------------------------\n");
    if (!isEmptyDash(q)) {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (q.buffer[i].cookDuration != 0) {
                printf("M%d\t| %d\n", (q).buffer[i].foodID, (q).buffer[i].cookDuration);
            }
        }
    } else {
        printf("\t|\n");
    }
}

void displayQueueServe(QueueDash q, QueueDash qO) {
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("----------------------------------\n");

    int count = 0;
    if (!isEmptyDash(q)) {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            if (q.buffer[i].cookDuration == 0 && q.buffer[i].sustain != NIL) {
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
