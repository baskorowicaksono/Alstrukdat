#include <stdio.h>

int rec(int N)
{
    if (N <= 1){
        return 0;
    }
    else if (N == 2){
        return 1;
    }
    else if (N == 3){
        return 1 + rec(N-1);
    }
    else{
        return rec(N-1) + rec(N-2) + rec(N-3);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N <= 0 || N > 35){
        printf("Input salah, ulangi!\n");
        scanf("%d", &N);
    }
    int x = rec(N);
    printf("%d",x);
    return 0;
}

