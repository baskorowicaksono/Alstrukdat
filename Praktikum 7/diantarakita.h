/* File : listsirkuler.h */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* List dengan 1 elemen: First(L) = Next(First(L)) */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=First(List) */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean FSearch (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsertLast (List *L, infotype X);
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsertAfter (List *L, infotype X, infotype Y);
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
void InsertBefore (List *L, infotype X, infotype Y);
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DeleteLast (List *L, infotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DeleteElement (List *L, infotype X);
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen. Jika X adalah elemen satu-satunya, F.S. List kosong. */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int CountElement (List L);
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L. Return 0 jika kosong. */

/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L);
/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */

#endif
