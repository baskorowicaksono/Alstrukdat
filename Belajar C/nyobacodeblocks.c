#include <stdio.h>
int main(){
    int a[10], i, x;
    for (i = 0; i < 10; i++){
        printf("Enter the input for index %d = ", i);
        scanf("%d", &a[i]);
    }
    printf("Masukkan nilai yang ingin dicari = ");
    scanf("%d", &x);
    i = 0;
    while ((i < 10) && (a[i] != x)){
            i += 1;
    }
    if (a[i] == x){
        printf("elemen %d ditemukan di array pada elemen indeks ke %d", x, i);
    }
    else{
        printf("kosong");
    }
}
