/* File: prioqueuelist.h */
#ifndef _PRIOQUEUELIST_H
#define _PRIOQUEUELIST_H
#include "boolean.h"
#include <stdlib.h>
#define Nil NULL

/* Deklarasi type elemen */
typedef int ElType;

/* Priority Queue dengan representasi berkait dengan pointer */
typedef struct tNode *address;
typedef struct tNode {
ElType Info;
int Prio;
address Next;
} Node;

/* Type PrioQueue dengan HEAD */
typedef struct {
address HEAD; /* alamat elemen pertama */
} PrioQueue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Prio(P) (P)->Prio
#define Info(P) (P)->Info


/* Prototype manajemen memori */
void Alokasi(address *P, ElType X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
void Dealokasi(address P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean IsEmpty(PrioQueue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
int NBElmt(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(PrioQueue *Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void Enqueue(PrioQueue *Q, ElType X);
/* Proses: Mengalokasi node X dan menambahkan X pada Q sesuai dengan prioritas

jika alokasi berhasil; jika alokasi gagal Q tetap */

/* I.S. Q mungkin kosong */
/* F.S. X menjadi elemen Q sesuai dengan urutan prioritas */
void Dequeue(PrioQueue *Q, ElType *X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif
