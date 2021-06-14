#include <stdio.h>

int main()
{
    int T, i;
    scanf("%d\n", &T);
    while (T <= 0 || T >= 100){
            printf("input out of range, ulangi\n");
            scanf("%d\n", &T);
        }
    int bilangan1[T];           //ini pembilang
    int bilangan2[T];           //ini penyebut
    for (i = 0; i < T*2- 1; i++){
        scanf("%d %d\n", &bilangan1[i], &bilangan2[i]);
        while (bilangan1[i] <= 0 || bilangan1[i] >= 100 || bilangan2[i] <= 0 || bilangan2[i] >= 100){
            printf("input out of range, ulangi\n");
            scanf("%d %d\n", &bilangan1[i], &bilangan2[i]);
        }
    }
    int index = 0;
    while (index <= T*2){
        int penyebut = bilangan2[index];
        if (bilangan2[index] != bilangan2[index + 1]){
            penyebut = bilangan2[index] * bilangan2[index + 1];
            bilangan1[index] *= bilangan2[index + 1];
            bilangan1[index + 1] *= bilangan2[index];
        }
        int pembilang = bilangan1[index] + bilangan1[index + 1];
        if (penyebut > pembilang){
            if ((penyebut % pembilang) == 0){
                printf("%d/%d\n",1,(penyebut/pembilang));
            }

            else{
                int sisa = penyebut % pembilang;
                if((penyebut % sisa) == 0 && (pembilang % sisa) == 0){
                    printf("%d/%d\n",(pembilang/sisa),(penyebut/sisa));
                }
                else{
                    printf("%d/%d\n",pembilang,penyebut);
                }
            }
        }
        else if (penyebut == pembilang){
            printf("%d\n",1);
        }
        else{
            if ((pembilang % penyebut) == 0){
                printf("%d\n", pembilang/penyebut);
            }
            else{
                int sisa = pembilang % penyebut;
                if((penyebut % sisa) == 0 && (pembilang % sisa) == 0){
                    printf("%d/%d\n",(pembilang/sisa),(penyebut/sisa));
                }
                else{
                    printf("%d/%d\n",pembilang,penyebut);
                }
            }
        }
        index += 2;
    }
    system("pause");
    return 0;
}