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

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : ListRek tidak kosong */
infotypeLr MaxList(ListRek L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    if (IsEmptyLr(L))
        return -99999;
    else
    {
        int max = MaxList(TailLr(L));
        if (FirstElmtLr(L) > max)
            return FirstElmtLr(L);
        else
            return max;
    }
}

infotypeLr MinList(ListRek L)
/* Mengirimkan nilai info(P) yang minimum */
{
    if (IsEmptyLr(L))
        return 99999;
    else
    {
        int min = MinList(TailLr(L));
        if (FirstElmtLr(L) < min)
            return FirstElmtLr(L);
        else
            return min;
    }
}

infotypeLr SumList(ListRek L)
/* Mengirimkan total jumlah elemen ListRek L */
{
    if (IsEmptyLr(L))
        return 0;
    else
    {
        return FirstElmtLr(L) + SumList(TailLr(L));
    }
}

float AverageList(ListRek L)
/* Mengirimkan nilai rata-rata elemen list L */
{
    return (float)SumList(L) / NbElmtList(L);
}

/*** Operasi-Operasi Lain ***/
ListRek InverseList(ListRek L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika AlokasiLr gagal, hasilnya list kosong */
{
    if (IsEmptyLr(L))
        return NULL;
    else
    {
        return KonsB(InverseList(TailLr(L)), FirstElmtLr(L));
    }
}

void SplitPosNeg(ListRek L, ListRek *L1, ListRek *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
{
    ListRek temp1, temp2;

    if (IsEmptyLr(L))
    {
        *L1 = NULL;
        *L2 = NULL;
    }
    else
    {
        SplitPosNeg(TailLr(L), &temp1, &temp2);
        if (FirstElmtLr(L) >= 0)
        {
            *L1 = Konso(FirstElmtLr(L), temp1);
            *L2 = temp2;
        }
        else
        {
            *L2 = Konso(FirstElmtLr(L), temp2);
            *L1 = temp1;
        }
    }
}

void SplitOnX(ListRek L, infotypeLr X, ListRek *L1, ListRek *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
{
    ListRek temp1, temp2;

    if (IsEmptyLr(L))
    {
        *L1 = NULL;
        *L2 = NULL;
    }
    else
    {
        SplitOnX(TailLr(L), X, &temp1, &temp2);
        if (FirstElmtLr(L) < X)
        {
            *L1 = Konso(FirstElmtLr(L), temp1);
            *L2 = temp2;
        }
        else
        {
            *L2 = Konso(FirstElmtLr(L), temp2);
            *L1 = temp1;
        }
    }
}

int ListCompare(ListRek L1, ListRek L2)
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
{
    if (IsEmptyLr(L1))
        if (IsEmptyLr(L2))
            return 0;
        else
            return -1;
    else
    {
        if (IsEmptyLr(L2))
            return 1;
        else if (FirstElmtLr(L1) > FirstElmtLr(L2))
            return 1;
        else if (FirstElmtLr(L1) < FirstElmtLr(L2))
            return -1;
        else
            return ListCompare(TailLr(L1), TailLr(L2));
    }
}

boolean IsAllExist(ListRek L1, ListRek L2)
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
{
    if (IsEmptyLr(L1))
        return false;
    else if (IsOneElmtLr(L1))
        return SearchLr(L2, FirstElmtLr(L1));
    else
        return (SearchLr(L2, FirstElmtLr(L1)) && IsAllExist(TailLr(L1), (L2)));
}