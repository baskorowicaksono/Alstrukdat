/* Nama     : Baskoro Adi Wicaksono
    NIM     : 18219113

    kok gabisa juga ya pak ampun */

#include <stdio.h>

int main(){
    int hari,i;
    scanf("%d", &hari);
    int a[hari], b[hari], c[hari];
    for(i = 0 ; i < hari; i++){
        scanf("%d\t", &a[i]);
    }
    for(i = 0 ; i < hari; i++){
        scanf("%d\t", &b[i]);
    }
    for(i = 0 ; i < hari; i++){
        scanf("0", &c[i]);
    }
    for(i = 0 ; i < hari; i++){
        c[i] = a[i] + b[i];
        printf("%d %d\n", i+1, c[i]);
    }
    return 0;
}
