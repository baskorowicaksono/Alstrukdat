#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"


boolean isValid (int pendaftar, int kuota, int pisang[pendaftar], int sumpisang, int start)
{
    int first = pisang[start];
    boolean found = false;
    int i = 0;
    while (!found && (i < pendaftar)){
        if((first + pisang[i]) != sumpisang){
            found = true;
            }
        else{
            i++;
            }
    }
    if (!found){
        if(start != pendaftar){
            return isValid(pendaftar, kuota, pisang, sumpisang, (start + 1));
        }
        else{
            return found;
        }
    }
    else{
        return found;
    }

}
int main()
{
    int pendaftar, kuota,sumpisang, i, start;
    scanf("%d %d\n", &pendaftar, &kuota);
    int pisang[pendaftar];
    for (i = 0; i < pendaftar; i++){
        scanf("%d",&pisang[i]);
    }
    scanf("%d\n", sumpisang);
    boolean valid = isValid(pendaftar, kuota, &pisang[pendaftar], sumpisang, start);
    if (!valid){
        printf("ketemu");
    }
    else{
        printf("gak ketemu :(");
    }
    return 0;
}


