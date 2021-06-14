/* Nama : Baskoro Adi Wicaksono
   NIM  : 18219113
   Tanggal : 19 November 2020
   Praktikum 9
   ADT Queue dengan List Linier */

#include <stdio.h>
#include "prioqueue.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X, int prio)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/* P=Nil jika alokasi gagal */
{
    *P = (ElmtQueue *) malloc(sizeof(ElmtQueue));
    if ((*P) != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
        Prio(*P) = prio;
    }
}
void Dealokasi(address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    Next(P) = Nil;
    free(P);
}
boolean IsEmpty(Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    if (!IsEmpty(Q)){
    address P = Head(Q);
    int i = 1;
    while (Next(P) != Nil){
        P = Next(P);
        i++;
    }
    return i;
    }
    else{
        return 0;
    }
}
/*** Kreator ***/
void CreateEmpty(Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/*** Primitif Enqueue/Dequeue ***/
void Enqueue(Queue *Q, infotype X, int prio)
/* Proses: Mengalokasi node X dan menambahkan X pada Q sesuai dengan prioritas

jika alokasi berhasil; jika alokasi gagal Q tetap */

/* I.S. Q mungkin kosong */
/* F.S. X menjadi elemen Q sesuai dengan urutan prioritas */
{
    address P;
    Alokasi(&P,X,prio);
    if (P != Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
            Tail(*Q) = Head(*Q);
            Next(Head(*Q)) = Nil;
        }
        else{
            address Prec = Head(*Q);
            while (Next(Prec) != Nil && Prio(P) <= Prio(Prec)){
                Prec = Next(Prec);
            }
            Next(P) = Next(Prec);
            Next(Prec) = P;
        }
    }
}
void Dequeue(Queue *Q, infotype *X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address P = Head(*Q);
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        CreateEmpty(Q);
    }
    else{
    Head(*Q) = Next(Head(*Q));
    }
    Dealokasi(P);
}

