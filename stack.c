#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S, int Size)
/* I.S.: sembarang; */
/* F.S.: Terbentuk sebuah stack S yang kosong berkapasitas Size */
/* jadi indeksnya antara 0..Size-1 */
/* Ciri stack kosong: TOP bernilai Nil */
{
(*S).T = (infotype*) malloc (Size *(sizeof(infotype)));
if ((*S).T != NULL){
    Size(*S) = Size;
    Top(*S) = Nil;
}
else{
    Size(*S) = 0;
}
}
/*** destruktor ***/
void Destruct(Stack *S)
/* destruktor: dealokasi seluruh tabel memori sekaligus */
{
    Size(*S) = 0;
    free((*S).T);
}
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == Nil);
}
boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == Size(S) - 1);
}
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S.: S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S.: X menjadi TOP yang baru, TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S.: S tidak mungkin kosong */
/* F.S.: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
}
