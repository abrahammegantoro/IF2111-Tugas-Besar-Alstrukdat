#ifndef LIST_REKURSIF
#define LIST_REKURSIF

#include "../boolean.h"

/* Definisi Type */
typedef int infotypeLr;
typedef struct tElmtlistLr *addrLr;
typedef struct tElmtlistLr
{
    infotypeLr info;
    addrLr next;
} ElmtListLr;

/* Definisi list : */
/* ListRek kosong : L = Nil */
typedef addrLr ListRek;

/* Deklarasi  nama untuk variabel kerja */
/*    L : ListRek */
/*    P : addrLr   */
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next

/* *** Manajemen Memori *** */
addrLr AlokasiLr(infotypeLr X);
/* Mengirimkan addrLr hasil AlokasiLr sebuah elemen */
/* Jika AlokasiLr berhasil, maka addrLr tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika AlokasiLr gagal, mengirimkan Nil */
void DealokasiLr(addrLr P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrLr P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListRek */
int IsEmptyLr(ListRek L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneElmtLr(ListRek L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infotypeLr FirstElmtLr(ListRek L);
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
ListRek TailLr(ListRek L);
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */

/* *** Konstruktor *** */
ListRek Konso(infotypeLr e, ListRek L);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika AlokasiLr gagal, mengirimkan L. */
ListRek KonsB(ListRek L, infotypeLr e);
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika AlokasiLr e gagal, mengirimkan L */

/* *** Operasi Lain *** */
ListRek Copy(ListRek L);
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada AlokasiLr gagal, mengirimkan L */
void MCopy(ListRek Lin, ListRek *Lout);
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
ListRek Concat(ListRek L1, ListRek L2);
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada AlokasiLr gagal, menghasilkan Nil */
void MConcat(ListRek L1, ListRek L2, ListRek *LHsl);
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
void PrintList(ListRek L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
int NbElmtList(ListRek L);
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
boolean SearchLr(ListRek L, infotypeLr X);
/* Mengirim true jika X adalah anggota list, false jika tidak */

#endif