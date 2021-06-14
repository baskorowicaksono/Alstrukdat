#include <stdio.h>
#include "queue2.h"

/********** Prototype **********/
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Count(Q) - 1 == Nil);
}
boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return Count(Q) == MaxEl;
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
        if (Count(*Q) == MaxEl(*Q)){
            (*Q).(COUNT - 1) = 0;
            }
        else{
            (*Q).(COUNT - 1) += 1;
            }
        }
    ((*Q).(COUNT - 1)) = X;
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


