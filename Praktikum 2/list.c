/* Nama     : Baskoro Adi Wicaksono
    NIM     : 18219113

maap saya nyerah pak, suwusah:( */

#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void MakeEmpty (List *T);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas IdxMax-IdxMin+1 */

int Length (List L)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
/* *** Daya tampung container *** */
{
    if (IsEmpty(L)){
        return 0;
    }
    else{
        return L.Neff;
    }
}
int MaxLength (List L)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list */
{
    return IdxMax;
}
/* *** Selektor INDEKS *** */
IdxType FirstIdx (List L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}
IdxType LastIdx (List L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{

}
/* *** Menghasilkan sebuah elemen *** */
ElType Get (List L, IdxType i)
/* Prekondisi : list tidak kosong, i antara FirsLIdx(T)..LasLIdx(T) */
/* Mengirimkan elemen list yang ke-i */
{
    return L.A[i]
}
/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set (List *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
{

}
void SetNeff (List *L, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/
{
    if(i <= 100 && i>= 0){
        return 1;
    }
    else{
        return 0;
    }
}
boolean IsIdxEff (List L, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */
{
    if((i >= FirstIdx(L)) && (i <= LastIdx(L))){
        return 1;
    }
    else{
        return 0;
    }
}

/* ********** Operasi-operasi ********** */
IdxType Search (List L, ElType v);
/* I.S. L, i, v terdefinisi.
/* F.S. Mengembalikan indeks lojik elemen pertama L yang bernilai v (jika ada), */
/* atau mengembalikan IdxUndef jika tidak ada. */
{
    IdxType i,v;
    while((i < LastIdx(L)) && (Get(L,i) != v)){
        i += 1;
    }
    if (Get(L,i) == v){
        return i
    }
    else{
        return IdxUndef
    }
}
void InsertFirst (List *L, ElType v);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
{
    List *L;
    L = (List *) malloc(sizeof(List));
    L ->

}
void InsertAt (List *L, IdxType i, ElType v);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
void InsertLast (List *L, ElType v);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
void DeleteFirst (List *L, ElType *F);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
void DeleteAt (List *L, IdxType i);
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
void DeleteLast (List *L, ElType *F);
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
void Concat (List L1, List L2, List *L3);
/* I.S. L1 ≠ L2, L1 ≠ L3, dan L3 ≠ L2; L1, L2 mungkin kosong */
/* F.S. L3 adalah hasil Konkatenasi ("Menyambung") dua buah list, L2 */
/* ditaruh di belakang L1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty (List L);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
    if(!list){
        return 1;
    }
    else{
        return 0;
    }
}

#endif
