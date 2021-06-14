#include <stdio.h>
#include <stdbool.h>
int main(){
    int i,b;
    printf("definisikan ukuran array = ");
    scanf("%d", &b);

    int a[b];
    for(i = 0; i < b; i++){
        printf("Isikan array a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
    int m[b];
    for(i = 0; i < b; i++){
        printf("Isikan array m[%d] = ", i);
        scanf("%d", &m[i]);
    }

    int c[b];
    for(i = 0; i < b; i++){
        scanf("0", &c[i]);
    }
    printf("Array yang baru adalah berisi ");
    for(i = 0; i < b; i++){
        c[i] = a[i] + m[i];
        printf("%d ", c[i]);
    }
    return 0;
}
