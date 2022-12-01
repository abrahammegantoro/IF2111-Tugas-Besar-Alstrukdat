#ifndef LISTSOM_H
#define LISTSOM_H

#include "../boolean.h"
#include "stdio.h"
#include "stdlib.h"

#define NilSOM NULL
#define NilIdx -1

typedef struct {
    int x;
    int y;
} Point;

typedef struct tElmtList *somaddress;
typedef struct tElmtList {
    Point infoPos;
    somaddress nextPos;
} ElmtSnake;

typedef struct {
    somaddress Head;
    somaddress Tail;
} ListSnake;

typedef struct {
    Point obsA;
    Point obsB;
    Point obsC;
} ListObstacle;

#define PosX(P) (P).x
#define PosY(P) (P).y
#define InfoPos(P) (P)->infoPos
#define NextPos(P) (P)->nextPos
#define Head(L) ((L).Head)
#define Tail(L) ((L).Tail)

/* PROTOTYPE POINT */
/****************** PEMBUATAN POINT ******************/
Point MakePoint(int X, int Y);
/* Membentuk sebuah Point dari komponen-komponennya */

boolean IsEQPoint(Point P1, Point P2);
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptySnake(ListSnake L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptySnake(ListSnake *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
somaddress AlokasiSnake(Point X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiSnake(somaddress P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
int LengthSnake (ListSnake L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

somaddress SearchSnake(ListSnake L, Point X);
/* Mengirimkan address dari list yang memiliki point X, Nil jika tidak ada*/

int SearchIdxSnake(ListSnake L, Point X);
/* Mengirimkan index dari list yang memiliki point X, NilIdx jika tidak ada*/

void InsVFirstSnake(ListSnake *L, Point X);
/* Menambahkan elemen pertama list */
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen pertama L */

void InsVLastSnake(ListSnake *L, Point X);
/* Menambahkan elemen terakhir list */
/* I.S. L mungkin kosong */
/* F.S. X ditambahkan sebagai elemen terakhir L */

void DelVFirstSnake(ListSnake *L, Point *X);
/* Menghapus elemen pertama list */
/* I.S. list tidak kosong */
/* F.S. X adalah nilai elemen pertama list sebelum penghapusan */

void DelVLastSnake(ListSnake *L, Point *X);
/* Menghapus elemen terakhir list */
/* I.S. list tidak kosong */
/* F.S. X adalah nilai elemen terakhir list sebelum penghapusan */

void DelPSnake(ListSnake *L, Point X);
/* Menghapus elemen list yang memiliki point X */
/* I.S. list tidak kosong */
/* F.S. list tidak berisi X */

boolean SearchObstacle(ListObstacle L, Point P);
/* Mengirimkan true jika P ada di salah satu obstacle */

void PrintInfoSnake(ListSnake L);
/* I.S. L terdefinisi */
/* F.S. Semua infoPos yang ada pada list dicetak ke layar */

#endif