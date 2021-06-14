/*  NIM  : 18219113
    Nama : Baskoro Adi Wicaksono
    Tanggal : 22 Oktober 2020
    Topik Praktikum : Praktikum 5
    Deskripsi   : ADT Map*/

#include "map.h"


/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).Count = 0;
}
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return (M.Count == 0);
}
bool IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return (M.Count == MaxEl);
}
/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
{
    int i = 0;
    while (i <= M.Count-1 && M.Elements[i].Key != k){
            i += 1;
    }
    if (i <= M.Count -1){
        return M.Elements[i].Value;
    }
}
void Insert(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMember(*M,k)) {
        (*M).Count += 1;
        (*M).Elements[((*M).Count)-1].Key = k;
        (*M).Elements[((*M).Count)-1].Value = v;
    }
}
void Delete(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if ((*M).Count == 1){
        (*M).Elements[0].Key = Nil;
        (*M).Elements[0].Value = Nil;
        (*M).Count -= 1;
    }
    else {
        int i = 0,j;
        while (i <= (*M).Count - 1 && (*M).Elements[i].Key != k){
            i += 1;
        }
        if (i <= (*M).Count - 1){
                for (j = i; j<=((*M).Count)-1; j++){
                        (*M).Elements[j].Key = (*M).Elements[j + 1].Key;
                        (*M).Elements[j].Value = (*M).Elements[j + 1].Value;
                }
        (*M).Count -= 1;
        }
    }
}
bool IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i = 0;
    while (i <= M.Count-1 && M.Elements[i].Key != k){
            i += 1;
    }
    if (i <= M.Count -1){
        return true;
    }
    else{
        return false;
    }
}


