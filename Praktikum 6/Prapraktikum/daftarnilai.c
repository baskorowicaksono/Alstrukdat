/*Baskoro Adi Wicaksono
18219113
26 Oktober 2020
Praktikum 6
ADT List Linier*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List L;
    infotype x;
    address P;

    CreateEmpty(&L);
    scanf("%d\n", &x);
    while (x >= 0 && x <= 100){
        InsVLast(&L,x);
        scanf("%d", &x);
    }

    if (IsEmpty(L)) {
        printf("Daftar nilai kosong");
        printf("\n");
    }
    else{
        printf("%d\n",NbElmt(L));
        printf("%d\n",Max(L));
        printf("%d\n",Min(L));
        printf("%.2f\n",Average(L));
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
    return 0;
}
