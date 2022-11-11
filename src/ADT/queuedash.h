#ifndef QUEUEDASH_H
#define QUEUEDASH_H

#include "../boolean.h"

#define IDX_UNDEF -1
#define CAPACITYDASH 40
#define NIL -9999

/* Definisi elemen dan address */
typedef struct {
    int foodID;
    int cookDuration;
    int sustain;
    int price;
} FoodType;

typedef struct {
	FoodType buffer[CAPACITYDASH]; 
	int idxHead;
	int idxTail;
} QueueDash;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QueueDash, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define  HEAD_ID(q) (q).buffer[(q).idxHead].foodID
#define  TAIL_ID(q) (q).buffer[(q).idxTail].foodID

/* *** Kreator *** */
void CreateQueueDash(QueueDash *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyDash(QueueDash q);
/* Mengirim true jika q kosong: lihat definisi di atas */

int lengthDash(QueueDash q);
/* Mengirimkan banyaknya elemen QueueDash. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueueFood(QueueDash *q, FoodType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer. */

void dequeueFood(QueueDash *q);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. IDX_HEAD "mundur";
        q mungkin kosong */

boolean isMember(QueueDash q, int id);
/* Mengirimkan true jika terdapat id dalam queue Q dan sebaliknya */

int getIdx(QueueDash q, int id);
/* Mengirimkan index dengan elemen id didalam Queue Q, Queue Q pasti memiliki elemen id */

/* *** Display QueueDash *** */
void displayQueueMenu(QueueDash q);
/* Proses : Menuliskan isi QueueDash dengan format order yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */

void displayQueueCook(QueueDash q);
/* Proses : Menuliskan isi QueueDash dengan format cook yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */

void displayQueueServe(QueueDash q, QueueDash qO);
/* Proses : Menuliskan isi QueueDash dengan format serve yang sesuai*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: tertampilkan di layar sesuai format */

#endif