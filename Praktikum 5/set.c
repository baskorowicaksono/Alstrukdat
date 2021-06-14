/*  NIM  : 18219113
    Nama : Baskoro Adi Wicaksono
    Tanggal : 22 Oktober 2020
    Topik Praktikum : Praktikum 5
    Deskripsi   : ADT Set*/

#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = 0;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return (S.Count == 0);
}

bool IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return (S.Count == MaxEl);
}
/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
        if (!IsMember(*S, Elmt)){
            (*S).Count += 1;
            (*S).Elements[((*S).Count)-1] = Elmt;
        }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if ((*S).Count == 1){
        (*S).Elements[0] = Nil;
        (*S).Count -= 1;
    }
    else{
        int i = 0,j;
        while (i <= (*S).Count - 1 && (*S).Elements[i] != Elmt){
            i += 1;
        }
        if (i <= (*S).Count - 1){
                for (j = i; j<=((*S).Count)-1; j++){
                        (*S).Elements[j] = (*S).Elements[j + 1];
                }
        (*S).Count -= 1;

        }
    }
}
bool IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    int i = 0;
    while (i <= (S.Count) - 1 && S.Elements[i] != Elmt){
        i += 1;
    }
    if (i <= (S.Count) - 1){
        return true;
    }
    else{
        return false;
    }



}
