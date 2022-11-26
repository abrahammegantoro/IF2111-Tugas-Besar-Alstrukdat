#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElM */
/* Ciri Map kosong : count bernilai NilM */
{
    M->Count = NilM;
    int i;
    for(i = 0; i < MaxElM; i++){
        (*M).Elements[i].Value = 0;
    } 
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai NilM */
{
    return M.Count == NilM;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElM */
{
    return M.Count == MaxElM;
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytypeM k)
/* Mengembalikan nilai value dengan key k dari M */
{
    boolean found = false;
    addressM idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return M.Elements[idx].Value;
}

void InsertMapSorted(Map *M, keytypeM k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMemberMap(*M,k)) {
        if (IsEmptyMap(*M)) {
            (*M).Elements[0].Key = k;
            (*M).Elements[0].Value = v;
        } else {
            int i = (*M).Count - 1;
            while((*M).Elements[i].Value > v) {
                (*M).Elements[i + 1] = (*M).Elements[i];
                i--; 
            }
            (*M).Elements[i + 1].Key = k;
            (*M).Elements[i + 1].Value = v;
        }
        (*M).Count++;
    }
}
// 1 2 3 4  

void DeleteMap(Map *M, keytypeM k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    addressM idx = 0, iterator;

    if (!IsMemberMap(*M, k)) {
        return;
    }

    while (!found && (idx < M->Count)) {
        if (M->Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMemberMap(Map M, keytypeM k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    addressM idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}
