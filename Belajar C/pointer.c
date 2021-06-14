#include <stdio.h>
/* void fun(int arr[], int len, int *min, int *max)
{
    *min = *max = arr[0];
    int i;
    for (i=1; i<len; i++)
    {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

int main()
{
    int arr[] = {2,3,4,5,6,11,13,22,365,63,1};
    int min, max;
    int len = sizeof(arr)/sizeof(arr[0]);
    fun(arr, len, &min, &max);
    printf("Nilai minimum pada array adalah %d dan nilai maksimumnya adalah %d", min, max);
    return 0;
} */

/*find mid*/

int *findMid(int arr[], int n)
{
    return &arr[n/2];
}

int main()
{
    int a[] = {1,3,5,7,9,11,13};
    int n = sizeof(a)/sizeof(a[0]);
    int *mid = findMid(a, n);
    printf("%d", *mid);
    return 0;
}