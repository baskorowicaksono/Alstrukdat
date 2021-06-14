#include <stdio.h>
#include "queue.h"

/********** Prototype **********/
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Head(Q) == 0 && Tail(Q) == MaxEl(Q) - 1);
}
int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q
kosong */
/*** Kreator ***/
{
    return (Tail(Q) - Head(Q) + 1);
}
void CreateEmpty(Queue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc (Max *sizeof(infotype));
    if ((*Q).T == NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        }
    else{
        MaxEl(*Q) = 0;
        }
}
/*** Destruktor ***/
void DeAlokasi(Queue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL bergeser ke kanan */
/* Jika Tail(Q)=MaxEl-1, maka geser isi tabel, shg Head(Q)=0 */
{
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
    }
    else{
        if (Head(*Q) != 0 && Tail(*Q) == MaxEl(*Q) - 1){
                address i,j;
                i = Head(*Q); j = 0;
                do{
                    *((*Q).T+j) = *((*Q).T+i);
                    i++; j++;
                } while(i <= Tail(*Q));
                Tail(*Q) = NBElmt(*Q) - 1;
                Head(*Q) = 0;

            }
        }
    Tail(*Q)++;
    InfoTail(*Q) = X;
}
void Dequeue(Queue * Q, infotype* X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD bergeser ke kanan;
Q mungkin kosong */
{
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Head(*Q);
    }
    else{
        Head(*Q)++;
    }
}

