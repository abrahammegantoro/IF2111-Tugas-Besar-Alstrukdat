#include "../boolean.h"
#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
addrLr AlokasiLr(infotypeLr X)
/* Mengirimkan addrLr hasil AlokasiLr sebuah elemen */
/* Jika AlokasiLr berhasil, maka addrLr tidak NULL, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = NULL */
/* Jika AlokasiLr gagal, mengirimkan NULL */
{
    ElmtListLr *P = (ElmtListLr *)malloc(sizeof(ElmtListLr));
    if (P != NULL)
    {
        Info(P) = X;
        Next(P) = NULL;
        return P;
    }
    return NULL;
}

void DealokasiLr(addrLr P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrLr P */
{
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmptyLr(ListRek L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
    return (L == NULL);
}

int IsOneElmtLr(ListRek L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
    if (!IsEmptyLr(L))
    {
        return IsEmptyLr(Next(L));
    }
    else
    {
        return 0;
    }
}

/* *** Selektor *** */
infotypeLr FirstElmtLr(ListRek L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
    return Info(L);
}

ListRek TailLr(ListRek L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
    return (Next(L));
}

/* *** Konstruktor *** */
ListRek Konso(infotypeLr e, ListRek L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika AlokasiLr gagal, mengirimkan L. */
{
    addrLr P = AlokasiLr(e);
    if (P != NULL)
    {
        Next(P) = L;
        return P;
    }
    return L;
}

ListRek KonsB(ListRek L, infotypeLr e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika AlokasiLr e gagal, mengirimkan L */
{
    if (IsEmptyLr(L))
    {
        return AlokasiLr(e);
    }
    else
    {
        Next(L) = KonsB(TailLr(L), e);
        return L;
    }
}

/* *** Operasi Lain *** */
ListRek Copy(ListRek L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada AlokasiLr gagal, mengirimkan L */
{
    if (IsEmptyLr(L))
        return NULL;
    else
        return Konso(FirstElmtLr(L), Copy(TailLr(L)));
}

void MCopy(ListRek Lin, ListRek *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
    ListRek temp;

    if (IsEmptyLr(Lin))
        *Lout = NULL;
    else
    {
        MCopy(TailLr(Lin), &temp);
        (*Lout) = Konso(FirstElmtLr(Lin), temp);
    }
}

ListRek Concat(ListRek L1, ListRek L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada AlokasiLr gagal, menghasilkan NULL */
{
    if (IsEmptyLr(L1))
        return Copy(L2);
    else
        return Konso(FirstElmtLr(L1), Concat(TailLr(L1), L2));
}
void MConcat(ListRek L1, ListRek L2, ListRek *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
    ListRek temp;
    if (IsEmptyLr(L1))
        *LHsl = Copy(L2);
    else
    {
        MConcat(TailLr(L1), L2, &temp);
        *LHsl = Konso(FirstElmtLr(L1), temp);
    }
}

void PrintList(ListRek L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
    if (!IsEmptyLr(L))
    {
        printf("%d\n", FirstElmtLr(L));
        PrintList(TailLr(L));
    }
}

int NbElmtList(ListRek L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
    if (IsEmptyLr(L))
        return 0;
    else
        return 1 + NbElmtList(Next(L));
}

boolean SearchLr(ListRek L, infotypeLr X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
    if (IsEmptyLr(L))
        return false;

    else
    {
        if (FirstElmtLr(L) == X)
            return true;
        else
            return SearchLr(TailLr(L), X);
    }
}