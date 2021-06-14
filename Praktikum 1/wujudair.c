#include <stdio.h>
/* Nama : Baskoro Adi Wicaksono
    NIM : 18219113 */
int main()
{
    int suhu;
    scanf("%d", &suhu);

    if (suhu < 0)
    {
        printf("PADAT\n");
    }
    else if (suhu == 0)
    {
        printf("PADAT-CAIR\n");
    }
    else if (suhu > 0 && suhu < 100)
    {
        printf("CAIR\n");
    }
    else if (suhu == 100)
    {
        printf("CAIR-GAS\n");
    }
    else if (suhu > 100)
    {
        printf("GAS\n");
    }
    return 0;
    
}