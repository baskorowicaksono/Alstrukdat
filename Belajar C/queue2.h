/* File: queue.h */
#include "boolean.h"
#include <stdlib.h>
#define Nil -1
#define MaxEl 100
/* Definisi elemen dan address */
typedef struct {
int id;     /*id dari proses*/
int lama;   /*waktu yang dibutuhkan untuk berproses*/
}infotype;
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue: */
/* Versi I: tabel dinamik, Head dan Tail eksplisit,
ukuran disimpan */
typedef struct {
infotype *T; /* tabel penyimpan elemen */
address HEAD; /* alamat penghapusan */
int COUNT; /* banyak elemen pada queue */
} Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/********** AKSES (Selektor) **********/
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define Count(Q) (Q).COUNT
/********** Prototype **********/
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q
kosong */
/*** Kreator ***/
void CreateEmpty(Queue *Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
/*** Destruktor ***/
void DeAlokasi(Queue *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL bergeser ke kanan */
/* Jika Tail(Q)=MaxEl-1, maka geser isi tabel, shg Head(Q)=0 */
void Dequeue(Queue * Q, infotype* X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD bergeser ke kanan;

Q mungkin kosong */

