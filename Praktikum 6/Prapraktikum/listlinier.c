#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (ElmtList *) malloc(sizeof(ElmtList));
    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    Next(*P) = Nil;
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address Prec, P;
    boolean found;

    Prec = Nil;
    P = First(L);
    while ((P != Nil) && (!found)) {
        if (Info(P) == X) {
            found = true;
        }
        else {
            Prec = P;
            P = Next(P);
        }
    }
    if (found) {
        return P;
    }
    else {
        Prec = Nil;
        return Prec;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;
    P = Alokasi(X);
    if (P != Nil){
        InsertFirst(L,P);
    }
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P = Alokasi(X);
    if (P != Nil){
        InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;
    P = First(*L);
    First(*L) = Next(P);
    *X = Info(P);
    Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
        Next(P) = First(*L);
        First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
        if (P != Nil){
            Next(P) = Next(Prec);
            Next(Prec) = P;
        }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;
    if (IsEmpty(*L)){
        InsertFirst(L,P);
    }
    else{
        if (P != Nil){
            Last = First(*L);
            while (Next(Last) != Nil){
                Last = Next(Last);
        }
        InsertAfter(L,P,Last);
        }
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P, Prec, Pdel;
    boolean found;

    P = First(*L);
    Prec = Nil;
    found = false;
    while ( (P != Nil) && (!found) ) {
        if (Info(P) == X) {
            found = true;
        }
        else {
            Prec = P;
            P = Next(P);
        }
    }
    if (found == true) {
        if (Prec == Nil) { // X merupakan elemen pertama
            DelFirst(L, &Pdel);
            Dealokasi(&Pdel);
        }
        else {  // X bukan merupkan elemen pertama
            DelAfter(L, &Pdel, Prec);
            Dealokasi(&Pdel);
        }
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address last, precLast;

    last = First(*L);
    precLast = Nil;
    while (Next(last) != Nil) {
        precLast = last;
        last = Next(last);
    }
    if (precLast == Nil) {
        DelFirst(L, P);
    }
    else {
        DelAfter(L, P, precLast);
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    address P;
    boolean found;

    P = First(*L);
    found = false;
    while ((P != Nil) && (!found)) {
        if (P == Prec) {
            found = true;
        }
        else {
            P = Next(P);
        }
    }

    *Pdel = Next(P);
    Next(P) = Next(Next(P));
    Next(*Pdel) = Nil;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;

    if (IsEmpty(L)) {
        printf("[]");
    }
    else { // list berisi
        P = First(L);
        printf("[%d", Info(P));
        P = Next(P);
        while (P != Nil) {
            printf(",%d", Info(P));
            P = Next(P);
        }
        printf("]");
    }
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int i = 0;
    address P = First(L);
    while (P != Nil){
        i++;
        P = Next(P);
    }
    return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    address P;
    infotype maxi;
    P = First(L);
    maxi = Info(P);
    while (Next(P) != Nil){
        P = Next(P);
        if (maxi < Info(P)){
            maxi = Info(P);
        }
    }
    return maxi;
}
address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    return (Search(L,Max(L)));
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    {
    address P;
    infotype mini;
    P = First(L);
    mini = Info(P);
    while (Next(P) != Nil){
        P = Next(P);
        if (mini > Info(P)){
            mini = Info(P);
        }
    }
    return mini;
}
}
address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    return Search(L,Min(L));
}
float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address P = First(L);
    float sum = 0;
    int count = 0;
    while (P != Nil){
        count++;
        sum += Info(P);
        P = Next(P);
    }
    float avg = sum/count;
    return avg;
}

/****************** PROSES TERHADAP LIST ******************/
void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P, Prec, Last;

    P = First((*L));
    Prec = Nil;

    while (P != Nil) {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    First(*L) = Last;
}
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address P1,P3,last;
    if (!IsEmpty(*L1)){
        while (P1 != Nil){
                InsertLast(L3,P1);
                P1 = Next(P1);
        }
        if(!IsEmpty(*L2)){
            last = First(*L3);
            while (Next(last)!= Nil){
                last = Next(last);
            }
            Next(last) = First(*L2);
        }

    }
    else{
        if(!IsEmpty(*L2)){
            last = First(*L3);
            while (Next(last)!= Nil){
                last = Next(last);
            }
            Next(last) = First(*L2);
        }

            }
}

