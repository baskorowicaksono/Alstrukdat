/* Nama : Baskoro Adi Wicaksono
    NIM : 18219113 */
#include <stdio.h>

int main()
{
    int X,N;
    int i = 1;
    int Sum = 0;
    scanf("%d", &X);
    while (X != 9999)
    {
        printf("%d\n", X);
        Sum += X;
        i += 1;
        scanf("%d", &X);
    }
    printf("Jumlah : %d\n", Sum);
    printf("Banyaknya bilangan : %d\n", i-1);
    return 0;
}