#include <stdio.h>
#include <stdlib.h>
#include "prioqueuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, ElType X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
{
    *P = (Node *) malloc(sizeof(Node));
    if ((*P) != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
void Dealokasi(address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    Next(P) = Nil;
    free(P);
}
boolean IsEmpty(PrioQueue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
{
    return Head(Q) == Nil;
}

int NBElmt(PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    address P = Head(Q);
    int i = 1;
    while (Next(P) != Nil){
        P = Next(P);
        i++;
    }
    return i;
}
/*** Kreator ***/
void CreateEmpty(PrioQueue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
}
/*** Primitif Enqueue/Dequeue ***/
void Enqueue(PrioQueue *Q, ElType X)
/* Proses: Mengalokasi node X dan menambahkan X pada Q sesuai dengan prioritas

jika alokasi berhasil; jika alokasi gagal Q tetap */

/* I.S. Q mungkin kosong */
/* F.S. X menjadi elemen Q sesuai dengan urutan prioritas */
{
    address P;
    Alokasi(&P,X);
    if (P != Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
        }
        else{
            address Prec = Head(*Q);
            while (Next(Prec) != Nil && Info(P) > Info(Prec)){
                Prec = Next(Prec);
            }
            Next(P) = Next(Prec);
            Next(Prec) = P;
        }
    }
}
void Dequeue(PrioQueue *Q, ElType *X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P = Head(*Q);
    *X = InfoHead(*Q);
    Head(*Q) = Next(Head(*Q));
    Dealokasi(P);
}
