#include <stdio.h>

int main()
{
    float t;
    char s;
    printf("Masukkan suhu: ");
    scanf("%f", &t);
    printf("Masukkan huruf konversi: ");
    scanf("%c", &s);

    float konversi;

    if (s == 'r')
        konversi = 4/5 * t;
        printf("%2f", konversi);
    if (s == "f")
        konversi = (9/5 *t) + 32;
        printf("%2f", konversi);
    if (s == "k")
        konversi = t + 273.15;
        printf("%2f", konversi);
    else
        printf("hurufnya salah bego");
    return 0;
}