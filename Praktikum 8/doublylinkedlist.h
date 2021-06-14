#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

#define Nil NULL
typedef int ElType;
typedef struct tNode *address;
typedef struct tNode {
ElType info;
address prev;
address next;
} Node;
/* Definisi list: */
/* List kosong: First = Nil and Last = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Prev(P), Next(P) */
typedef struct {
address First; address Last;
} List;
/* Selektor */
#define Info(P) (P)->info
#define Prev(P) (P)->prev
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)

boolean IsEmpty (List L);
/* Mengirim true jika list kosong */

address Alokasi (ElType X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
void InsertFirst(List *L, ElType X);
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen baru X sebagai elemen pertama */
void InsertAfter(List *L, address P, address Prec);
/* I.S. Prec pastilah node dari list; P sudah dialokasi */
/* F.S. Insert P sebagai node sesudah node beralamat Prec */
void InsertLast(List *L, ElType X);
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru */
void DeleteFirst(List *L, ElType *X);
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DeleteLast(List *L, ElType *X);
/* I.S. List tidak kosong */
/* F.S. X adalah elemen terakhir sebelum pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
void DeleteAfter(List *L, address *Pdel, address Prec);
/* I.S. List tidak kosong. Prec adalah anggota list.

Next(Prec)!=Nil */

/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
#endif
