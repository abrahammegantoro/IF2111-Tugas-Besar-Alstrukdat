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

somaddress SearchSnake(ListSnake L, Point X);

int SearchIdxSnake(ListSnake L, Point X);

void InsVFirstSnake(ListSnake *L, Point X);

void InsVLastSnake(ListSnake *L, Point X);

void DelVFirstSnake(ListSnake *L, Point *X);

void DelVLastSnake(ListSnake *L, Point *X);

void DelPSnake(ListSnake *L, Point X);

boolean SearchObstacle(ListObstacle L, Point P);



#endif