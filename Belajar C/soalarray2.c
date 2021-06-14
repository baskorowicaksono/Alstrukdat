#include <stdio.h>
#include <stdbool.h>


int main() {
    int i,b,j;
    bool temp;

    temp = false;
    printf("definisikan ukuran array = ");
    scanf("%d", &b);

    int a[b];
    for(i = 0; i < b; i++){
        printf("Isikan array a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for(i = 0; i < b; i++){
        for(j = i+1; j<b; j++){
            if (a[i] == a[j]){
                temp = true;
            }
        }
}
    if(temp){
        printf("Ada elemen berulang");
    }
    else{
        printf("gaada");
    }
    return 0;
}

