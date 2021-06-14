#include <stdio.h>
#include <stdbool.h>

int main(){
    int a,b,i;
    bool temp = true;
    printf("berapa panjang array1 = ");
    scanf("%d", &a);
    printf("berapa panjang array2 = ");
    scanf("%d", &b);

    if (a != b){
        temp = false;
    }

    else{
        int m[a], n[b];
        for(i = 0; i < a; i++){
            printf("Isikan array m[%d] = ", i);
            scanf("%d", &m[i]);
        }
        printf("\n");
        for(i = 0; i < b; i++){
            printf("Isikan array n[%d] = ", i);
            scanf("%d", &n[i]);
        }

        i = 0;
        while ((i < a) && (temp = true)){
            if (m[i] == n[i]){
                temp = true;
            }
            else{
                temp = false;
            }
            i++;
        }
    }
    if(temp){
        printf("eq");
    }
    else{
        printf("not eq");
    }
    return 0;
}

