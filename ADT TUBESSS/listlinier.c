#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressList Alokasi (infotypeList X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressList P;

    
    P = (addressList) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    else
    {
        return Nil;
    }
    
}

void Dealokasi (addressList *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressList Search (List L, infotypeList X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressList P;
    boolean Found;

    P = First(L);
    Found = false;
    while ((P != Nil) && (!Found))
    {
        if (X == Info(P))
        {
            Found = true;
        }
        else
        {
            P = Next(P);
        }
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressList P;

    P = Alokasi(X);
    if (P != Nil)
    {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotypeList X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressList P;

    P = Alokasi(X);

    if (P != Nil)
    {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotypeList *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressList P;

    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;

    Dealokasi(&P);
}

void DelVLast (List *L, infotypeList *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressList P;

    DelLast(L, &P);
    (*X) = Info(P);

    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (List *L, addressList P, addressList Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, addressList P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressList Last;
    
    Last = First(*L);
    if (First(*L) == Nil)
    {
      InsertFirst(L, P);
    } 
    else 
    {
      while (Next(Last) != Nil)
      {
        Last = Next(Last);
      }
      InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P) = First(*L);
    First(*L) = Next(First(*L));
}

void DelP (List *L, infotypeList X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressList P, Prec, Pdel;
    boolean Found;

    P = First(*L);
    Prec = Nil;
    Found = false;

    while ((P != Nil) && (!Found))
    {
        if (Info(P) == X)
        {
            Found = true;
        }
        else
        {
            Prec = P;
            P = Next(P);
        }
    }
    if (Found == true)
    {
        if (Prec == Nil)
        {
            DelFirst(L, &Pdel);
            Dealokasi(&Pdel);
        } 
        else
        {
            DelAfter(L, &Pdel, Prec);
            Dealokasi(&Pdel);
        }
    }
}

void DelLast (List *L, addressList *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    addressList Last, PrecLast;
  
    Last = First(*L);
    PrecLast = Nil;
    while (Next(Last) != Nil) 
    {
        PrecLast = Last;
        Last = Next(Last);;
    }
  
    (*P) = Last;
    if (PrecLast == Nil)
    {
        First(*L) = Nil;
    } 
    else
    {
        Next(PrecLast) = Nil;
    }
}

void DelAfter (List *L, addressList *Pdel, addressList Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
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
    addressList P;
    int i;
    int n;
    P = First(L);
    n = NbElmt(L);

    if (!IsEmptyList(L))
    {
        /* printf("[%d",Info(P));
        P = Next(P);
        while (P != Nil)
        {
            printf(",%d", Info(P));
            P = Next(P);
        }
        printf("]"); */
        int j = 1;
        while (P != Nil){
            printf("%d. Pelanggan %d\n", j, Info(P));
            j++;
            P = Next(P);
        }
    } 
    else
    {
        printf("[]");
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    addressList P;
    int i;

    i = 0;
    P = First(L);
    while (P != Nil)
    {
       i++;
       P = Next(P);
    }
    return i;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeList Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    infotypeList Max;
    addressList P;

    P = First(L);
    Max = Info(P);
    P = Next(P);
    while (P != Nil)
    {
      if (Max < Info(P))
      {
        Max = Info(P);
      }
      P = Next(P);
    }
    return Max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    addressList P;

    CreateEmptyList(L3);
    if (!IsEmptyList(*L1))
    {
        First(*L3) = First(*L1);
        P = First(*L1);
        while(Next(P) != Nil)
        {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L2);
    }
    CreateEmptyList(L1);
    CreateEmptyList(L2);
}

void DelAll (List *L){
    addressList P;
    P = First(*L);
    while (P!=NULL){
        First(*L) = Next(First(*L));
        Next(P) = NULL;
        Dealokasi(&P);
        P = First(*L);
    }
}

void CopyList (List L1, List *L2)
/* I.S. L1 sembarang */
/* F.S. L2 adalah hasil copy L1 */
{

    addressList P1, P2;
    boolean gagal = false;
    CreateEmptyList(L2);
    P1 = First(L1);
    while ((P1!=NULL)&&(!gagal)){
        P2 = Alokasi(Info(P1));
        if (P2!=NULL){
            InsertLast(L2,P2);
            P1 = Next(P1);
        }
        else{
            gagal = true;
            DelAll(L2);
        }
    }
}