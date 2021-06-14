#include <stdio.h>

int main(){
    int i,b,x;
    printf("definisikan ukuran array = ");
    scanf("%d", &b);

    int temp = 0;
    int a[b];
    for(i = 0; i < b; i++){
        printf("Isikan array a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("Masukkan nilai yang ingin dicari = ");
    scanf("%d", &x);

    for(i = 0; i < b; i++){
        if(a[i] == x){
            temp += 1;
        }
    }
    printf("nilai kemunculan %d adalah %d", x, temp);
}
