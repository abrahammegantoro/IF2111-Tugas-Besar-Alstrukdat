#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define NilM 0
#define MaxElM 100

// typedef int bool;
typedef int keytypeM;
typedef int valuetype;
typedef int addressM;

typedef struct
{
	keytypeM Key;
	valuetype Value;
} infotypeM;

typedef struct
{
	infotypeM Elements[MaxElM];
	addressM Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil scoreboard = nama score */ 
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElM */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElM */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytypeM k);
/* Mengembalikan nilai value dengan key k dari M */

void InsertMapSorted(Map *M, keytypeM k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytypeM k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytypeM k);
/* Mengembalikan true jika k adalah member dari M */

#endif
