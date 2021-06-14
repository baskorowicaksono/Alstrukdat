#include <stdio.h>

int main(){
    int i;
    int a[9] = {1,2,3,4,5,6,12,43,532};
    for(i = 0; i<9; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    for(i = 0; i<9; i++){
        printf("%d ", a[8-i]);
    }
    return 0;
}


