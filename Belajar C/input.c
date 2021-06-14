/*pada program ini akan dijelaskan mengenai scanf.
scanf ekuivalen terhadap input */

#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Masukkan bilangan yang pertama\n");
    scanf("%d", &a);
    printf("Masukkan bilangan yang kedua\n");
    scanf("%d", &b);
    printf("Masukkan bilangan yang ketiga\n");
    scanf("%d", &c);
    
    printf("Hasil dari (%d + %d)* %d adalah &d ", a,b,c, (a+b)*c);
    return 0;
}