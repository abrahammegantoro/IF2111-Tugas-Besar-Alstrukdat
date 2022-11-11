#ifndef DINNERDASH_H
#define DINNERDASH_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/queuedash.h"
#include "../ADT/mesinkata.h"

void addOrder(QueueDash *q);
/* Menambahkan order ke dalam queue
   I.S. q sembarang mungkin kosong
   F.S. q bertambah order baru */

boolean isEnd(QueueDash q, int ctr);
/* Mengembalikan nilai true apabila antrian sudah melebihi pada queue 7 atau ctr bernilai 2  */

void identifyCommand(QueueDash q, int *isCook, int* id);
/* Mengecek command valid dan mengembalikan nilainya ke isCook dan id
   I.S. q terdefinisi, isCook dan id sembarang
   F.S. Command terbaca, mengembalikan isCook 1 jika valid dan id sesuai.
        Jika tidak valid isCook 0, id 9999 */

void cook(QueueDash qM, QueueDash *q, int food, boolean *valid);
/* Memasak makanan yang dipilih
   I.S. qM terdefinisi tidak kosong, food terdefinisi, q sembarang, valid sembarang
   F.S. valid bernilai true jika makanan ada pada qM, q bertambah */

void serve(QueueDash *qM, QueueDash *q, int food, boolean *valid, int *saldo);
/* Menyajikan makanan yang dipilih
   I.S. qM, q sembarang mungkin kosong, food id makanan, saldo sembarang 
   F.S. Jika makanan ada dalam antrian makanan jadi, valid bernilai true,
        makanan dihapus dari qM dan q, saldo bertambah */

void reduceTime(QueueDash *q);
/* Memperbarui waktu makanan yang dimasak dan siap disajikan
   I.S. q terdefinsi
   F.S. Makanan yang ada pada q berkurang waktu memasak dan ketahanannya */

void runDinerDash();
/* Menjalankan game Diner Dash 
   I.S. sembarang
   F.S. Diner Dash selesain dijalankan */


#endif