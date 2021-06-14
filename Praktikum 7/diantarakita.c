/* Nama     : Baskoro Adi Wicaksono
    NIM     : 18219113
    Tanggal : 5 November 2020
    Topik   : List Sirkuler
    Praktikum 7 */


#include "diantarakita.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nil;
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
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
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
boolean FSearch (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */
{
    address Pt;
    if (IsEmpty(L)) {
        return false;
    }
    else {
        Pt = First(L);
        while ((Next(Pt) != First(L)) && (Info(Pt) != X)) {
            Pt = Next(Pt);
    } /* Next(Pt) = First(L) or Pt = P */
    return Info(Pt) == X;
}
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P, last;
    DeleteElement(L,X);
    P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            Next(P) = P;
        }
        else /* L tidak kosong */{
            last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            } /* Next(last) = First(L) ==> elemen terakhir */
            Next(P) = First(*L);
            Next(last) = P;
        }
        First(*L) = P;
    }
}
void InsertLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P, last;
    DeleteElement(L,X);
    if (IsEmpty(*L)) {
        InsertFirst(L,X);
    }
    else {
        P = Alokasi(X);
        if (P != Nil) {
            last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            } /* Next(last) = First(L) */
            Next(last) = P;
            Next(P) = First(*L);
        }
    }
}
void InsertAfter (List *L, infotype X, infotype Y)
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
{
    if (!IsEmpty(*L)){
        if (FSearch(*L,X)){
            if (FSearch(*L,Y)){
                DeleteElement(L,Y);
            }
            address P = Alokasi(Y);
            address prec = First(*L);
            while ((Next(prec) != First(*L)) && (Info(prec) != X)) {
                prec = Next(prec);
            }
            Next(P) = Next(prec);
            Next(prec) = P;

        }
    }
}
void InsertBefore (List *L, infotype X, infotype Y)
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */
{
    if (!IsEmpty(*L)){
        if (FSearch(*L,X)){
            if (FSearch(*L,Y)){
                DeleteElement(L,Y);
            }
            address P = Alokasi(Y);
            address prec = First(*L);
            address b = Nil;
            while ((Next(prec) != First(*L)) && (Info(prec) != X)) {
                b = prec;
                prec = Next(prec);
            }
            if (b == Nil) { /* kasus satu elemen */
                InsertFirst(L,Y);
            }
            else{
            Next(b) = P;
            Next(P) = prec;
            }
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P, last;
    P = First(*L); *X = Info(P);
    if (Next(First(*L)) == First(*L)) { /* satu elemen */
        First(*L) = Nil;
    }
    else {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        } /* Next(last) = First(L) */
        First(*L) = Next(First(*L)); Next(last) = First(*L);
    }
    Dealokasi(&P);
}

void DeleteLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address Last, PrecLast;
    Last = First(*L); PrecLast = Nil;
    while (Next(Last) != First(*L)) {
        PrecLast = Last; Last = Next(Last);
        } /* Next(Last) = First(*L) */
    if (PrecLast == Nil) { /* kasus satu elemen */
        First(*L) = Nil;
    }
    else {
        Next(PrecLast) = First(*L);
    }
    *X = Info(Last);
    Dealokasi(&Last);
}
void DeleteElement (List *L, infotype X)
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen */
{
    if (FSearch(*L,X)){
        address el = First(*L);
        address Precel = Nil;
         while ((Next(el) != First(*L)) && (Info(el) != X)) {
            el = Next(el); Precel = el;
        }
        if (Precel == Nil){
            First(*L) = Nil;
        }
        else{
            Next(Precel) = First(*L);
        }
        Dealokasi(&el);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    if (IsEmpty(L)) {
        printf("List Kosong \n");
    }
    else {
        P = First(L);
        printf("List: \n");
        do{
            printf("%d \n", Info(P));
            P = Next(P);
    }
    while (P != First(L));
    }
}

/** int NbElmt (List L)
 Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong
{
    if (!IsEmpty(L)){
        int i = 0;
        address P = First(L);
        while (Next(P) != First(L)){
            i++;
            P = Next(P);
        }
        i++;
        return i;
    }
    else{
        return 0
    }
}
**/

int CountElement (List L)
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L */
{
    if (!IsEmpty(L)){
        int i = 0;
        address P = First(L);
        while (Next(P) != First(L)){
            i++;
            P = Next(P);
        }
        i++;
        return i;
    }
    else{
        return 0;
    }
}
/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L)
/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */
{
    infotype X;
    DeleteLast(L,&X);
    InsertFirst(L,X);
}
