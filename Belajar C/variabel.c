#include <stdio.h>
int fun(int a, int b)
{
    int temp;
    temp = b;
    b = a;
    a = temp;
    printf("%d, %d, %d" , a,b,temp);
}

int main()
{
    fun(2,4);
    return 0;
}