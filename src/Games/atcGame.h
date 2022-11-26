#ifndef AIR_TRAFFIC_CONTROL_H
#define AIR_TRAFFIC_CONTROL_H

#include <stdio.h>
#include "../ADT/queue.h"
#include "../ADT/mesinkata.h"
#include "../ADT/array.h"

typedef struct {
    Queue Pesawat[100];
    Word ID[100];
    int NEff;
} Langit;

extern boolean isOver;

int playAtc();
/* Menjalankan game Air Traffic Control 
   I.S. sembarang
   F.S. Game Air Traffic Control selesai dijalankan */

void createPesawat(Queue *Pesawat, int ID, char color);
/* Membuat queue pesawat di langit dengan panjang random
   I.S. sembarang
   F.S. Queue pesawat terdefinisi */

void createBandara(Queue *Bandara);
/* Membuat queue bandara
   I.S. sembarang
   F.S. Queue bandara terdefinisi */


void printLangit(Langit L);
/* Mencetak langit yang sedang ada
   I.S. Langit terdefinsii
   F.S. Langit tercetak pada layar */

void printBandara(Queue B, char warna);
/* Mencetak langit yang sedang ada
   I.S. Langit terdefinsii
   F.S. Langit tercetak pada layar */

void printGuide();
/* Mencetak panduan permainan
   I.S. sembarang
   F.S. Panduan tercetak pada layar */

void printStatus(Queue M, Queue B, Langit L);
/* Mencetak status bandara dan langit
   I.S. sembarang
   F.S. Status tercetak pada layar */

void insertPesawat(Langit *L, Queue Pesawat);
/* Memasukan pesawat ke langit
   I.S. Pesawat dan langit terdefinisi, langit mungkin kosong
   F.S. Pesawat berada dalam langit */

void insertLanding(Queue *Bandara, TabKata *Landing);
/* Memasukkan Array Pesawat ke Bandara
   I.S. Array Landing mungkin kosong atau berisi satu
   F.S. Array Landing kosong, dipindah ke Bandara */

void updateStatus(Queue *M, Queue *B, Langit *L, TabKata *LandingM, TabKata *LandingB);
/* Mengupdate status bandara dan langit 
   I.S. Langit dan bandara terdefinisi
   F.S. Langit dan bandara terupdate */

void accPesawat(Langit *L, Word comm);
/* Mempercepat pesawat mendarat
   I.S. Pesawat pilihan berada pada posisi sembarang dan command valid
   F.S. Pesawat berada pada head queue */

boolean isCommVal(Word comm, Langit L);
/* Mengembalikan nilai true jika command valid */


#endif