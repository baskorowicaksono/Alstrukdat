#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** Manajemen Memori ******************/
address Alokasi (ElType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address *P;
    *P = (ElType *) malloc(sizeof(ElType));
    if(*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
    return *P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    Next(*P) = Nil;
    free(*P);
}

void InsertFirst(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen baru X sebagai elemen pertama */
{
    address P = Alokasi(X);
    if (P != Nil){
        Next(P) = First(*L);
        if (IsEmpty(*L)){
            Last(*L) = P;
        }
        else{
            Prev(Next(P)) = First(*L);
        }
        First(*L) = P;
    }
}
void InsertAfter(List *L, address P, address Prec)
/* I.S. Prec pastilah node dari list; P sudah dialokasi */
/* F.S. Insert P sebagai node sesudah node beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
    Prev(P) = Prec;
    if (Next(P) == Nil){
        Last(*L) = P;
    }
    else{
        Prev(Next(P)) = P;
    }
}

void InsertLast(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru */
{
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            InsertFirst(L,X);
        }
        else{
            InsertAfter(L,P,Last(*L));
        }
    }
}

void DeleteFirst(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    address P = First(*L);
    *X = Info(P);
    if (Next(P) == Nil){    /*kasus 1 elemen*/
        Last(*L) = Nil;
    }
    else{
        Prev(Next(P)) = Nil;
    }
    First(*L) = Next(P);
    Dealokasi(&P);
}
void DeleteLast(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah elemen terakhir sebelum pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
{
    address P = First(*L);
    while (Next(P) != Nil){
        P = Next(P);
    }
    *X = Info(P);
    if (Prev(P) == Nil){
        First(*L) = Nil;
    }
    else{
        Prev(Last(*L)) = Nil;
        Next(Prev(P)) = Nil;
    }
    Last(*L) = Prev(P);
    Dealokasi(&P);
}
void DeleteAfter(List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list.

Next(Prec)!=Nil */

/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
{
    *Pdel = Next(Prec);
    if (Next(*Pdel) == Nil){
        Last(*L) = Prec;
    }
    else{
        Prev(Next(*Pdel)) = Prec;
    }
    Next(Prec) = Next(*Pdel);
    Prev(*Pdel) = Nil;

}
