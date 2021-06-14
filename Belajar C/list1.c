#include <stdio.h>
#include <stdbool.h>
int main(){
    int i,b;
    bool temp = true;
    printf("definisikan ukuran array = ");
    scanf("%d", &b);

    int a[b];
    for(i = 0; i < b; i++){
        printf("Isikan array a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    i = 0;
    b -= 1;
    while ((i < b) && (temp = true)){
        if (a[i] != a[b]){
            temp = false;
        }
        else{
            temp = true;
        }
        i++;
        b--;
    }
    if(temp){
        printf("IsSimetrik");
        }

    else{
        printf("Not simetrik");
        }
}

