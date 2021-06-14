/* File: stack.h */
/* Implementasi Stack dalam bahasa C dengan alokasi dinamik */
#ifndef stack_H
#define stack_H
#include "boolean.h"

#define Nil -1

typedef int infotype; /* type elemen stack */
typedef int address; /* indeks tabel */
/* Versi II: dengan menyimpan tabel dinamik dan
alamat top secara eksplisit */
typedef struct {
infotype *T; /* tabel penyimpan elemen */
address TOP; /* alamat TOP: elemen puncak */
int Size; /* Ukuran stack */
} Stack;
/* Definisi stack S kosong: S.TOP = Nil */
/* Definisi akses: Get dan Set*/
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Size(S) (S).Size

/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S, int Size);
/* I.S.: sembarang; */
/* F.S.: Terbentuk sebuah stack S yang kosong berkapasitas Size */
/* jadi indeksnya antara 0..Size-1 */
/* Ciri stack kosong: TOP bernilai Nil */
/*** destruktor ***/
void Destruct(Stack *S);
/* destruktor: dealokasi seluruh tabel memori sekaligus */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/*********** Menambahkan sebuah elemen ke Stack **********/
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S.: S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S.: X menjadi TOP yang baru, TOP bertambah 1 */
/*********** Menghapus sebuah elemen Stack **********/
void Pop(Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S.: S tidak mungkin kosong */
/* F.S.: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
#endif
