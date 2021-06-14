/* Nama     : Baskoro Adi Wicaksono
    NIM     : 18219113
    Tanggal : 5 November 2020
    Topik   : List Sirkuler
    Praktikum 7 */
#include <stdio.h>
#include "diantarakita.h"
int GetnthElement(List L, int r)
{
    int i = 0;
    address P = First(L);
    int maju = (r % (CountElement(L)));
    while (i <= maju && Next(P) != First(L)){
        P = Next(P);
        i++;
    }
    return Info(P);
}
