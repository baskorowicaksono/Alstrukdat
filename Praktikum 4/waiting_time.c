#include<stdio.h>
#include "circular_queue.h"

/**
 * Menghitung waktu tunggu x pada Q, yaitu berapa banyak elemen yang ada
 * di depan elemen x pada Queue Q tanpa mengubah isi dari Q.Tab
 */
int WaitingTime(Queue Q, int x) {
    // TODO: Implementasi fungsi
    //   I.S. Q sudah dialokasi, bisa kosong
    //   F.S. integer yang berisi "waktu tunggu" seperti definisi di atas
    //        jika x tidak ada pada antrean Q, kembalikan -1

    if (IsEmpty(Q)){
        return -1;
    }
    else{
        int i, tunggu;
        i = Q.HEAD; tunggu = 0;
        while(i <= Length(Q) && x > Q.Tab[i]){
                i++; tunggu++;
            }
        if(i <= Length(Q)){
            return tunggu;
        }

        else{       /*x < Q.Tab[Q.HEAD]*/
            return -1;
        }
    }
    return 0;
}
