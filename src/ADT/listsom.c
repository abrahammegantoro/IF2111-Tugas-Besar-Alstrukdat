#include "listsom.h"

/* PROTOTYPE POINT */
/****************** PEMBUATAN POINT ******************/
Point MakePoint(int X, int Y) {
    Point P;
    PosX(P) = X;
    PosY(P) = Y;
    return P;
}
/* Membentuk sebuah Point dari komponen-komponennya */

boolean IsEQPoint(Point P1, Point P2) {
    return ((PosX(P1) == PosX(P2)) && (PosY(P1) == PosY(P2)));
}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptySnake(ListSnake L) {
    return (Head(L) == NilSOM && Tail(L) == NilSOM);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptySnake(ListSnake *L) {
    Head(*L) = NilSOM;
    Tail(*L) = NilSOM;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
somaddress AlokasiSnake(Point X) {
    somaddress P = (somaddress) malloc (sizeof(ElmtSnake));
    if (P != NilSOM) {
        InfoPos(P) = X;
        NextPos(P) = NilSOM;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nilSONilSOM, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NilSOM, Prev(P)=NilSOM */
/* Jika alokasi gagal, mengirimkan NilSOM */

void DealokasiSnake(somaddress P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
int LengthSnake(ListSnake L) {
    somaddress P = Head(L);
    int count = 0;
    while (P != NilSOM) {
        count++;
        P = NextPos(P);
    }
    return count;
}

somaddress SearchSnake(ListSnake L, Point X) {
    somaddress P = Head(L);
    while (P != NilSOM) {
        if (IsEQPoint(InfoPos(P), X)) {
            return P;
        }
        P = NextPos(P);
    }
    return NilSOM;
}

int SearchIdxSnake(ListSnake L, Point X) {
    somaddress P = Head(L);
    int i = 0;
    while (P != NilSOM) {
        if (IsEQPoint(InfoPos(P), X)) {
            return i;
        }
        P = NextPos(P);
        i++;
    }
    return NilIdx;
}

void InsVFirstSnake(ListSnake *L, Point X) {
    somaddress P = AlokasiSnake(X);
    if (P != NilSOM) {
        if (IsEmptySnake(*L)) {
            Head(*L) = P;
            Tail(*L) = P;
        } else {
            NextPos(P) = Head(*L);
            Head(*L) = P;
        }
    }
}

void InsVLastSnake(ListSnake *L, Point X) {
    somaddress P = AlokasiSnake(X);
    if (P != NilSOM) {
        if (IsEmptySnake(*L)) {
            Head(*L) = P;
            Tail(*L) = P;
        } else {
            NextPos(Tail(*L)) = P;
            Tail(*L) = P;
        }
    }
}

void DelVFirstSnake(ListSnake *L, Point *X) {
    if (!IsEmptySnake(*L)) {
        somaddress P = Head(*L);
        *X = InfoPos(P);
        if (Head(*L) == Tail(*L)) {
            Head(*L) = NilSOM;
            Tail(*L) = NilSOM;
        } else {
            Head(*L) = NextPos(P);
        }
        DealokasiSnake(P);
    }
}

void DelVLastSnake(ListSnake *L, Point *X) {
    if (!IsEmptySnake(*L)) {
        somaddress P = Tail(*L);
        *X = InfoPos(P);
        if (Head(*L) == Tail(*L)) {
            Head(*L) = NilSOM;
            Tail(*L) = NilSOM;
        } else {
            somaddress Q = Head(*L);
            while (NextPos(Q) != Tail(*L)) {
                Q = NextPos(Q);
            }
            Tail(*L) = Q;
            NextPos(Q) = NilSOM;
        }
        DealokasiSnake(P);
    }
}

void DelPSnake(ListSnake *L, Point X) {
    if (!IsEmptySnake(*L)) {
        if (IsEQPoint(InfoPos(Head(*L)), X)) {
            DelVFirstSnake(L, &X);
        } else if (IsEQPoint(InfoPos(Tail(*L)), X)) {
            DelVLastSnake(L, &X);
        } else {
            somaddress P = Head(*L);
            while (NextPos(P) != NilSOM && !IsEQPoint(InfoPos(NextPos(P)), X)) {
                P = NextPos(P);
            }
            if (NextPos(P) != NilSOM) {
                somaddress Q = NextPos(P);
                NextPos(P) = NextPos(Q);
                DealokasiSnake(Q);
            }
        }
    }
}

boolean SearchObstacle(ListObstacle L, Point P) {
    if(IsEQPoint(MakePoint(L.obsA.x, L.obsA.y), P) || IsEQPoint(MakePoint(L.obsB.x, L.obsB.y), P) || IsEQPoint(MakePoint(L.obsC.x, L.obsC.y), P)) {
        return true;
    } else {
        return false;
    }
}

void PrintInfoSnake(ListSnake L) {
    somaddress P = Head(L);
    if (IsEmptySnake(L)) {
        printf("List kosong");
    } else {
        int i = 1;
        while (P != NilSOM) {
            printf("Index ke-%d : (%d,%d) ",i ,InfoPos(P).x, InfoPos(P).y);
            P = NextPos(P);
            i++;
        }
    }
    printf("\n");
}