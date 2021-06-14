#include <stdio.h>
#include "string.h"

typedef struct {
    int ID[20];
    char team[20][8];
    int salah[20];
    int benar[20];
    float hasil[20];
} Team;

void main (){
    Team tim;
    int i,n;
    scanf("%d", &n);
    while (n < 1 && n > 20){
        printf("input salah");
        scanf("%d", &n);
    }
    for(i = 0; i < n;i++){
        scanf("%d %s %d %d", &tim.ID[i], &tim.team[i][8], &tim.benar[i], &tim.salah);
    }
    
    for (i = 0; i < n; i++){
        tim.hasil[i] = (float)tim.benar[i]*4 - tim.salah[i]*1.5;
    }
    Team temp;
    for (i = 0; i < n; i++){
        if (tim.hasil[i] < tim.hasil[i+1]){
            temp.ID[i] = tim.ID[i];
            temp.team[i][8] = tim.team[i][8];
            temp.benar[i] = tim.benar[i];
            temp.salah[i] = tim.salah[i];
            temp.hasil[i] = tim.hasil[i];

            tim.ID[i] = tim.ID[i+1];
            tim.team[i][8] = tim.team[i+1][8];
            tim.benar[i] = tim.benar[i];
            tim.salah[i]  = tim.salah[i+1];
            tim.hasil[i] = tim.hasil[i+1];

            
            tim.ID[i+1] = temp.ID[i];
            tim.team[i+1][8] = temp.team[i][8];
            tim.benar[i+1] = temp.benar[i];
            tim.salah[i+1] = temp.salah[i];
            tim.hasil[i+1] = temp.hasil[i];
        }
    }

    for(i = 0; i < n; i++){
        printf("%d %s %f", tim.ID[i], tim.team[i][8], tim.hasil[i]);
    }
}