/*cara biar ngga runtine error gimana ga paham :(((*/

#include <stdio.h>
#include "circular_queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Q.HEAD == NIL && Q.TAIL == NIL);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (Q.HEAD == 0 && Q.TAIL == Q.MaxEl - 1);
}
int Length (Queue Q)
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
{
    if(!IsEmpty(Q)){
    return (Q.TAIL - Q.HEAD + 1);
    }
    else{
        return 0;
    }
}
int MaxLength (Queue Q)
/* Mengirimkan kapasitas jumlah elemen Q */
{
    return Q.MaxEl;
}

/* *** Kreator *** */
Queue CreateQueue (int Max)
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */
{
    Queue *Q;
    (*Q).Tab = (ElType *) malloc (Max *sizeof(ElType));
    if ((*Q).Tab == NULL) {
        (*Q).MaxEl = Max;
        (*Q).TAIL = NIL;
        (*Q).TAIL = NIL;
        }
    else{
        (*Q).MaxEl = 0;
        }
}

/* *** Destruktor *** */
void DeleteQueue (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */
{
    (*Q).MaxEl = 0;
    free((*Q).Tab);
}
/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
{
        if(IsEmpty(*Q)){
        (*Q).HEAD = 0;
        (*Q).TAIL = (*Q).HEAD;
        }
        else{
            if ((*Q).TAIL == MaxLength(*Q) - 1){
                (*Q).TAIL = ((*Q).TAIL+1)%MaxLength(*Q);
            }
            else{
                (*Q).TAIL++;
            }
        (*Q).Tab[(*Q).TAIL] = X;
        }
}
ElType Pop (Queue * Q)
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    ElType *B;
    *B = (*Q).Tab[(*Q).HEAD];
    if((*Q).HEAD == (*Q).TAIL){     /*Queue berisi hanya 1 elemen*/
        (*Q).HEAD = NIL;
        (*Q).TAIL = NIL;
    }
    else{
        if((*Q).HEAD == MaxLength(*Q) -1){
            (*Q).HEAD = ((*Q).HEAD+1)%MaxLength(*Q);
        }
        else{
            (*Q).HEAD++;
        }
    }
}
ElType Front (Queue Q)
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
{
    return Q.Tab[Q.HEAD];
}
/* *** Utilitas *** */
Queue CopyQueue (Queue Q)
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */
{
    Queue Qnew;
    int i;
    CreateQueue(MaxLength(Q));
    for(i = Q.HEAD;i <= Length(Q);i++){
        Qnew.Tab = Q.Tab;
    }

}
