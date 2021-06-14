#include <stdio.h>

int main()
{
    int var = 052;  /*ini tipe datanya oktal bukan desimal soale ada 0 ndek depan, jadi kudu diconvert */
    printf("%d", var); /* 2 x 8^0 + 5 x 8^1 + 0 x 8^2 = 42*/
    return 0;
}

