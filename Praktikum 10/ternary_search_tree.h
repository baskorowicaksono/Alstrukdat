/* ADT Ternary Search Tree */
/* Implementasi dengan menggunakan pointer */

#ifndef _TERNARY_SEARCH_TREE_H_
#define _TERNARY_SEARCH_TREE_H_

/* Modul lain yang digunakan : */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define Nil 0

/* *** Definisi Type Pohon Ternary *** */
typedef int infotype;
typedef struct tNode *addrNode;
typedef struct tNode {
	infotype info;
	addrNode left;
	addrNode middle;
	addrNode right;
} Node;

/* Definisi Pohon Ternary : */
/* Pohon Ternary kosong : P = Nil */
typedef addrNode TernaryTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Middle(P) (P)->middle
#define Right(P) (P)->right

/* *** Konstruktor *** */
TernaryTree Tree (infotype Akar);
/* Menghasilkan sebuah pohon ternary dengan nilai info root = Akar */
/* left, middle, dan right bernilai Nil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/* Manajemen Memory */
addrNode AlokNode (infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokNode (addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (TernaryTree P);
/* Mengirimkan true jika P adalah pohon ternary kosong */
boolean IsTreeOneElmt (TernaryTree P);
/* Mengirimkan true jika P adalah pohon ternary tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft (TernaryTree P);
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerMiddle (TernaryTree P);
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unermiddle: hanya mempunyai subpohon tengah */
boolean IsUnerRight (TernaryTree P);
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBinary (TernaryTree P);
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon biner: mempunyai 2 dari 3 subpohon (kiri, tengah, kanan)*/
boolean IsTernary (TernaryTree P);
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon ternary lengkap: mempunyai seluruh subpohon kiri, tengah, kanan*/

/* *** Traversal *** */
void PrintTree (TernaryTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, pohon tengah, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   () adalah pohon kosong
   (A()()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()()())(C()()())(D()()())) adalah pohon dengan akar A dan subpohon kiri (B()()()) dan subpohon tengah (C()()()) dan subpohon kanan (D()()()) */

/* *** Searching *** */
int CountElmt (TernaryTree P, infotype X);
/* Mengirimkan jumlah kemunculan nilai X pada node P (P bisa kosong) */
infotype GetSmallest (TernaryTree P);
/* Mengirimkan nilai node infotype (int) terkecil pada P (P tidak kosong) */
infotype GetLargest (TernaryTree P);
/* Mengirimkan nilai node infotype (int) terbesar pada P (P tidak kosong) */
infotype GetMode (TernaryTree P);
/* Mengirimkan nilai node infotype (int) dengan kemunculan paling banyak (modus) pada P (P tidak kosong)*/

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (TernaryTree P);
/* Mengirimkan banyaknya elemen (node) pohon ternary P */
int NbUniqueElmt (TernaryTree P);
/* Mengirimkan banyaknya elemen (node) dengan infotype unik pada pohon ternary P */
int NbDaun (TernaryTree P);
/* Mengirimkan banyaknya daun (node) pohon ternary P */
/* Prekondisi: P tidak kosong */
int Tinggi (TernaryTree P);
/* Pohon ternary mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim tinggi dari pohon, contoh:
   () --> 0
   (A()()()) --> 1
   (A(B()()())()()) --> 2 */

/* *** Operasi lain *** */
void AddElmt (TernaryTree *P, infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun sesuai definisi ternary search tree */
void DelDaun (TernaryTree *P, infotype X);
/* I.S. P tidak kosong, ada 1 daun bernilai X. */
/* F.S. Menghapus 1 daun bernilai X dari P. */

#endif
