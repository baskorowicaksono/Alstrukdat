#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesin_kar.h"
#include "graph.h"
#include "listlinier.h"
#include "list.h"
#include "point.h"
#include "circular_queue.h"
#include "stack.h"
#include "time.h"

boolean EndKata;
boolean stillplaying = true;
boolean isbuilding = false;
Kata CKata;
int panjang = 0;
int lebar = 0;
int nNode = 0;
POINT CurrentPos;   // POSISI PLAYER
POINT Base,Shop;    // POSISI BASE DAN SHOP
POINT Pelanggan[50];  // POSISI TIAP PELANGGAN
int duit = 10000;
Queue ListPesanan;
Stack CurrentPesanan,CurrentBuild;
ListDin Inventory;
Graph Kota;
int indexorder = 1;
// LIST COMMAND UNTUK TIAP ITEM


/////////////////////////////////// LIST COMMAND DALAM GAME //////////////////////////////////////////
void MOVE_CMD(){
     printf("MOVE");
     int i = 0;
     if (EQ(CurrentPos,Base)){
         printf("Kamu berada di base!\n");
     }
     else if (EQ(CurrentPos,Shop)){
         printf("Kamu berada di shop!\n");
         i++;
     }
     else{
         i = 2;
         while (NEQ(CurrentPos,Pelanggan[i-2])){      //ini masi bingung pelanggannya mulai berapa, ini asumsi kalo bangunan 0 ama 1 diisi base ama shop, koreksi yakk
            i++;
         }
         printf("Kamu berada di bangunan pelanggan %d!\n", i-2);
     }
     addressGraph Pemain =  SearchGraph(Kota, i);
     printf("Lokasi yang dapat dicapai: \n");
     //PrintLink(Kota,InfoGraph(Pemain));
     List L;
     L = Link(Pemain);
     //PrintInfo(L);
     addressList P;
     P = First(L);
     int j = 1;
     while (P != Nil){
        printf("%d. Pelanggan %d\n", j, Info(P));
        j++;
        P = Next(P);
     }
     printf("\n");
     printf("Nomor Tujuan :");
     int x;
     scanf("%d", &x);
     while (x <= 0 || x > j ){
         printf("Input salah, ulangi!\n");
         printf("Nomor Tujuan :");
         scanf("%d", &x);
     }
     int index;
     if (x == 1) {
        index = Info(First(L));
    }
     else
    {
        addressList temp = First(L);
        for (index = 1;index <= x; i++){
            temp = Next(temp);
        }
        index = Info(temp);
    }
    
     Geser(&CurrentPos,(CurrentPos.X-Pelanggan[index].X),(CurrentPos.Y-Pelanggan[index].Y));
     printf("Kamu telah mencapai lokasi ");
     printLokasi(CurrentPos);
}

void printLokasi(POINT Pos){
    if (Pos.X == Base.X && Pos.Y == Base.Y){
        printf("base");
    } else if (Pos.X == Shop.X && Pos.Y == Shop.Y){
        printf("shop");
    }  else {
        boolean found = false;
        int i = 0;
        while (!found && i<nNode){
            if (Pos.X == Pelanggan[i].X && Pos.Y == Pelanggan[i].Y){
                found = true;
            }
            else {
                i++;
            }
        }
        printf("pelanggan %d",i+1);
    }
}

void STATUS_CMD(){
    //  printf("Panjang = %d\nLebar = %d\nNode = %d\nBase di (%d,%d)\nShop di (%d,%d)\n",panjang,lebar,nNode,Base.X,Base.Y,Shop.X,Shop.Y);
    //  for (int i=0;i<nNode-2;i++){
    //      printf("Pelanggan ke %d di (%d,%d)\n",i+1,Pelanggan[i].X,Pelanggan[i].Y);
    //  }
    printf("Uang tersisa: $%d\n",duit);
    printf("Build yang sedang dikerjakan:");
    if (isbuilding){
        printf(" pesanan %d untuk pelanggan %d",CurrentPesanan.noOrder,CurrentPesanan.Pemesan);
    };
    printf("\nLokasi: pemain sedang berada pada ");
    printLokasi(CurrentPos);
    printf(".\nInventory anda:\n");
    PrintListDin(Inventory);
}

void STARTBUILD_CMD(){
    if (!isbuilding){
        if (NEQ(CurrentPos,Base)) {
            printf("Kembali ke base terlebih dahulu\n");
        }
        else{
        printf("STARTBUILD\n");
        isbuilding = true;
        PushQ(&ListPesanan,CurrentPesanan);  
        printf("Kamu telah memulai pesanan %d untuk pelanggan %d. \n", CurrentPesanan.noOrder , CurrentPesanan.Pemesan);
        // int n = 24;
        // InsertLastDin(&Inventory, n); //ini kek Build yang dikerjain bakal dimasukin ke inventory gitu (kek di contoh ada "Build Untuk Pesanan #3 (1)") bakal muncul di status ntar, 24 soalnya 0-23 bakal dibuat idnya komponen")
        // n++;
        }
    } else {
        printf("Kamu sudah memulai build!\n");
    }
}
// COMMAND Untuk CHECKORDER

void cetakComponent(Stack *Component){
    Stack Temp;
    CreateEmpty(&Temp);
    infotype X;
    int i = 0;
    while (!IsEmpty(*Component)){
        Pop(Component,&X);
        Push(&Temp,X);
    }
    while (!IsEmpty(Temp)){
        Pop(&Temp,&X);
        printf("%d. ",i+1);
        printItem(X);
        printf("\n");
        Push(Component,X);
        i++;
    }
}

void cetakPesanan(Queue *Pesanan){
    Stack X;
    IdxType Q;
    Q = Pesanan->HEAD;
    // printf("%d\n",Q);
    if(!IsEmptyQ(*Pesanan)){
        // printf("%d\n",Pesanan->TAIL);
        X = Front(*Pesanan);
        printf("Nomor Order: %d\n",X.noOrder);
        printf("Pemesan: Pelanggan %d\n",X.Pemesan);
        printf("Invoice : %d\n",X.TotalHarga);
        printf("Komponen:\n");
        cetakComponent(&X);
    } else {
        printf("Lagi gak ada pesanan! See you tomorrow!\n");
    }
}


void CHECKORDER_CMD(){
     cetakPesanan(&ListPesanan);
}

// COMMAND Untuk FINISHBUILD

boolean isEQS(Stack A,Stack B){
    boolean same = true;
    for (int i = 0; i<MaxElS;i++){
        if (A.T[i] != B.T[i]){
            same = false;
        }
    }
    return same;
}

void FINISHBUILD_CMD(){
    if (isbuilding){
        if (isEQS(CurrentBuild,CurrentPesanan)){
            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n",CurrentPesanan.noOrder,CurrentPesanan.Pemesan);
            InsertLastDin(&Inventory,(100)+CurrentPesanan.noOrder);
            isbuilding = false;
        } else {
            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
        }    
        
    } else {
        printf("Kamu belum memulai build!");
    }
}

// COMMAND UNTUK ADDCOMPONENT


// void tambahComponent(Stack *Component, infotype X){
//     while (IsEmpty(*Component)){
//         CreateEmpty(Component);
//         Push(Component,X);
//     }
//     while (!IsEmpty(*Component)){
//         Push(Component,X);
//     }
// }

void ADDCOMPONENT_CMD(){
    if (isbuilding){
        int komponen;
        printf("Komponen yang telah terpasang: \n");
        cetakComponent(&CurrentBuild);
        printf("Komponen yang tersedia: \n");
        PrintListDin(Inventory);
        // for (int i = 0 ; i<24 ; i++){
        //     printf("%d. ",i+1);printItem(i);
        printf("Komponen yang ingin dipasang: ");
        scanf("%d",&komponen);
        while (komponen > LengthList(Inventory)){
            printf("Komponen yang ingin dipasang: ");
            scanf("%d",&komponen);
        }
        if (SearchB(Inventory,Inventory.A[komponen-1].name)){
            Push(&CurrentBuild,Inventory.A[komponen-1].name);
            DeleteElement(&Inventory,Inventory.A[komponen-1].name);   
            printf("Komponen berhasil dipasang");
        } else {
            printf("Komponen tidak ada!");
        }
    } else {
        printf("Anda belum memulai build!\n");
    }
        
}

// COMMAND UNTUK REMOVE COMPONENT
// void lepasComponent(Stack *Component){
//     infotype X;
//     while (!IsEmpty(*Component)){
//         Pop(Component,&X);
//     }
// }

void REMOVECOMPONENT_CMD(){
     int X = 0;
     if (!IsEmpty(CurrentBuild)){
         Pop(&CurrentBuild,&X);
         InsertLastDin(&Inventory,X);
         printf("Komponen "); printItem(X);
         printf(" berhasil dicopot!");
     }
        
}


// LIST COMMAND UNTUK SHOP
void generatePesanan(Stack *Curr){
    int item = 0;    
    time_t t;
    srand((unsigned)time(&t));
    CreateEmpty(Curr);
    Curr->Pemesan = 1+rand()%(nNode-3);  
    Curr->noOrder = indexorder;
    indexorder += 1;    
    for (int i = 0;i<8;i++){
        srand((unsigned)time(&t)+rand());
        item = rand()%3+(3*i);
        Curr->TotalHarga += getHarga(item);
        Push(Curr,item);
        // printItem(Curr->T[Curr->TOP-1]);
        // printf("\n");
    };
    Curr->TotalHarga *= 1.02;
}

void PrintStack(Stack *Asal){
    Stack Temp;
    CreateEmpty(&Temp);
    infotype X;
    while (!IsEmpty(*Asal)){
        Pop(Asal,&X);
        Push(&Temp,X);
    }
    while (!IsEmpty(Temp)){
        Pop(&Temp,&X);
        printItem(X);
        Push(Asal,X);
    }
}


void SHOP_CMD(){
        int item,jumlah;
        printf("Komponen yang tersedia: \n");
        for (int i = 0 ; i<24 ; i++){
                printf("%d. ",i+1);printItem(i);printf(" - $%d\n",getHarga(i));
        }
        printf("Komponen yang ingin dibeli: ");
        scanf("%d",&item);
        printf("Masukan jumlah yang ingin dibeli: ");
        scanf("%d",&jumlah);
        if (getHarga(item-1)*jumlah <= duit){
                duit -= getHarga(item-1)*jumlah;
                for (int j = 0; j < jumlah;j++){
                    InsertLastDin(&Inventory,item-1);
                };
                printf("Dibeli! Sisa Uang : %d",duit);
                // Disini nambah command kalau itemnya udah kebeli cc: baskoro
        } else {
                printf("Uang tidak cukup!");
        }
}
void DELIVER_CMD(){
     if (CurrentPos == CurrentPesanan.Pemesan) {
         printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d!\n",CurrentPesanan.noOrder,CurrentPesanan.Pemesan);
     } else {
         printf("Pesanan #%d tidak berhasil diantarkan kepada pelanggan %d!\n",CurrentPesanan.noOrder,CurrentPesanan.Pemesan);
     }
}
void END_DAY_CMD(){
     generatePesanan(&CurrentPesanan);
     PushQ(&ListPesanan,CurrentPesanan);
     printf("Morning sunshine! Pesanan baru sudah datang!\n");
}
void SAVE_CMD(){
     for (int i = 0;i<24;i++){
         InsertLastDin(&Inventory,i);
     };
     PopQ(&ListPesanan);
     printf("CHEAT ACTIVATED!\n");
}
void MAP_CMD(){
     if ()
     {
         /* code */
     }
     
     printf("MAP");
}

void play()
{
    /* KAMUS LOKAL */
    Kata MOVE,STATUS,STARTBUILD,CHECKORDER,FINISHBUILD,ADDCOMPONENT,REMOVECOMPONENT,SHOP,DELIVER,END_DAY,SAVE,MAP,EXIT;
    MOVE.Length = 4;
    MOVE.TabKata[0] = 'M';
    MOVE.TabKata[1] = 'O';
    MOVE.TabKata[2] = 'V';
    MOVE.TabKata[3] = 'E';

    STATUS.Length = 6;
    STATUS.TabKata[0] = 'S';
    STATUS.TabKata[1] = 'T';
    STATUS.TabKata[2] = 'A';
    STATUS.TabKata[3] = 'T';
    STATUS.TabKata[4] = 'U';
    STATUS.TabKata[5] = 'S';

    STARTBUILD.Length = 10;
    STARTBUILD.TabKata[0] = 'S';
    STARTBUILD.TabKata[1] = 'T';
    STARTBUILD.TabKata[2] = 'A';
    STARTBUILD.TabKata[3] = 'R';
    STARTBUILD.TabKata[4] = 'T';
    STARTBUILD.TabKata[5] = 'B';
    STARTBUILD.TabKata[6] = 'U';
    STARTBUILD.TabKata[7] = 'I';
    STARTBUILD.TabKata[8] = 'L';
    STARTBUILD.TabKata[9] = 'D';

    CHECKORDER.Length = 10;
    CHECKORDER.TabKata[0] = 'C';
    CHECKORDER.TabKata[1] = 'H';
    CHECKORDER.TabKata[2] = 'E';
    CHECKORDER.TabKata[3] = 'C';
    CHECKORDER.TabKata[4] = 'K';
    CHECKORDER.TabKata[5] = 'O';
    CHECKORDER.TabKata[6] = 'R';
    CHECKORDER.TabKata[7] = 'D';
    CHECKORDER.TabKata[8] = 'E';
    CHECKORDER.TabKata[9] = 'R';

    FINISHBUILD.Length = 11;
    FINISHBUILD.TabKata[0] = 'F';
    FINISHBUILD.TabKata[1] = 'I';
    FINISHBUILD.TabKata[2] = 'N';
    FINISHBUILD.TabKata[3] = 'I';
    FINISHBUILD.TabKata[4] = 'S';
    FINISHBUILD.TabKata[5] = 'H';
    FINISHBUILD.TabKata[6] = 'B';
    FINISHBUILD.TabKata[7] = 'U';
    FINISHBUILD.TabKata[8] = 'I';
    FINISHBUILD.TabKata[9] = 'L';
    FINISHBUILD.TabKata[10] = 'D';

    ADDCOMPONENT.Length = 12;
    ADDCOMPONENT.TabKata[0] = 'A';
    ADDCOMPONENT.TabKata[1] = 'D';
    ADDCOMPONENT.TabKata[2] = 'D';
    ADDCOMPONENT.TabKata[3] = 'C';
    ADDCOMPONENT.TabKata[4] = 'O';
    ADDCOMPONENT.TabKata[5] = 'M';
    ADDCOMPONENT.TabKata[6] = 'P';
    ADDCOMPONENT.TabKata[7] = 'O';
    ADDCOMPONENT.TabKata[8] = 'N';
    ADDCOMPONENT.TabKata[9] = 'E';
    ADDCOMPONENT.TabKata[10] = 'N';
    ADDCOMPONENT.TabKata[11] = 'T';

    REMOVECOMPONENT.Length = 15;
    REMOVECOMPONENT.TabKata[0] = 'R';
    REMOVECOMPONENT.TabKata[1] = 'E';
    REMOVECOMPONENT.TabKata[2] = 'M';
    REMOVECOMPONENT.TabKata[3] = 'O';
    REMOVECOMPONENT.TabKata[4] = 'V';
    REMOVECOMPONENT.TabKata[5] = 'E';
    REMOVECOMPONENT.TabKata[6] = 'C';
    REMOVECOMPONENT.TabKata[7] = 'O';
    REMOVECOMPONENT.TabKata[8] = 'M';
    REMOVECOMPONENT.TabKata[9] = 'P';
    REMOVECOMPONENT.TabKata[10] = 'O';
    REMOVECOMPONENT.TabKata[11] = 'N';
    REMOVECOMPONENT.TabKata[12] = 'E';
    REMOVECOMPONENT.TabKata[13] = 'N';
    REMOVECOMPONENT.TabKata[14] = 'T';

    SHOP.Length = 4;
    SHOP.TabKata[0] = 'S';
    SHOP.TabKata[1] = 'H';
    SHOP.TabKata[2] = 'O';
    SHOP.TabKata[3] = 'P';

    DELIVER.Length = 7;
    DELIVER.TabKata[0] = 'D';
    DELIVER.TabKata[1] = 'E';
    DELIVER.TabKata[2] = 'L';
    DELIVER.TabKata[3] = 'I';
    DELIVER.TabKata[4] = 'V';
    DELIVER.TabKata[5] = 'E';
    DELIVER.TabKata[6] = 'R';

    END_DAY.Length = 7;
    END_DAY.TabKata[0] = 'E';
    END_DAY.TabKata[1] = 'N';
    END_DAY.TabKata[2] = 'D';
    END_DAY.TabKata[3] = '_';
    END_DAY.TabKata[4] = 'D';
    END_DAY.TabKata[5] = 'A';
    END_DAY.TabKata[6] = 'Y';

    SAVE.Length = 4;
    SAVE.TabKata[0] = 'S';
    SAVE.TabKata[1] = 'A';
    SAVE.TabKata[2] = 'V';
    SAVE.TabKata[3] = 'E';

    MAP.Length = 3;
    MAP.TabKata[0] = 'M';
    MAP.TabKata[1] = 'A';
    MAP.TabKata[2] = 'P';

    EXIT.Length = 4;
    EXIT.TabKata[0] = 'E';
    EXIT.TabKata[1] = 'X';
    EXIT.TabKata[2] = 'I';
    EXIT.TabKata[3] = 'T';
    int nReguler = 0;
    int nPanjang = 0;
    int nKata = 0;

    //

    /* ALGORITMA */
    printf("\nEnter Command : ");
    STARTKATAW();
    if (CMPKata(CKata,MOVE)){
        MOVE_CMD();
    }
    else if (CMPKata(CKata,STATUS)){
        STATUS_CMD();
    }

    else if (CMPKata(CKata,STARTBUILD)){
        STARTBUILD_CMD();
    }

    else if (CMPKata(CKata,CHECKORDER)){
        CHECKORDER_CMD();
    }

    else if (CMPKata(CKata,FINISHBUILD)){
        FINISHBUILD_CMD();
    }

    else if (CMPKata(CKata,ADDCOMPONENT)){
        ADDCOMPONENT_CMD();
    }

    else if (CMPKata(CKata,REMOVECOMPONENT)){
        REMOVECOMPONENT_CMD();
    }

    else if (CMPKata(CKata,SHOP)){
        SHOP_CMD();
    }

    else if (CMPKata(CKata,DELIVER)){
        DELIVER_CMD();
    }

    else if (CMPKata(CKata,END_DAY)){
        END_DAY_CMD();
    }

    else if (CMPKata(CKata,SAVE)){
        SAVE_CMD();
    }

    else if (CMPKata(CKata,MAP)){
        MAP_CMD();
    }

    else if (CMPKata(CKata,EXIT)){
        stillplaying = false;
        printf("Sampai jumpa!");
    }
    else {
        printf("Error!");
    }
}


void load() {
    // Inisialisasi Order Pertama
    ListPesanan = CreateQueue(10);
    CreateEmpty(&CurrentBuild);
    generatePesanan(&CurrentPesanan);
    PushQ(&ListPesanan,CurrentPesanan);
    int currentline = 0;
    char BLANK = '\n';
    int spaced = 0;
    STARTKATA(BLANK);
    while (!EndKata) {
        for (int i=0;i<CKata.Length;i++){
            if (currentline==0){
                if (spaced==0 && CKata.TabKata[i] != ' '){
                    panjang *= 10;
                    panjang += CKata.TabKata[i] - '0';
                } else if (CKata.TabKata[i] == ' '){
                    spaced += 1;
                } else if  (spaced == 1){
                    lebar *= 10;
                    lebar += CKata.TabKata[i] - '0';
                }
            }
            else if (currentline==1){
                nNode *= 10;
                nNode += CKata.TabKata[i] - '0';
            }
            else if (currentline==2){
                if (CKata.TabKata[i]=='B'){
                    // Do Nothing
                } else if (CKata.TabKata[i] == ' '){
                    spaced +=1;
                } else if (spaced==1){
                    Base.X *= 10;
                    Base.X += CKata.TabKata[i] - '0';
                } else if (spaced==2){
                    Base.Y *= 10;
                    Base.Y += CKata.TabKata[i] - '0';
                }
            }
            else if (currentline==3){
                if (CKata.TabKata[i]=='S'){
                    // Do Nothing
                } else if (CKata.TabKata[i] == ' '){
                    spaced +=1;
                } else if (spaced==1){
                    Shop.X *= 10;
                    Shop.X += CKata.TabKata[i] - '0';
                } else if (spaced==2){
                    Shop.Y *= 10;
                    Shop.Y += CKata.TabKata[i] - '0';
                }
            }
            else if (currentline>3 && currentline<nNode+2){
                if (CKata.TabKata[i]=='C'){
                    // Do Nothing
                } else if (CKata.TabKata[i] == ' '){
                    spaced +=1;
                } else if (spaced==1){
                    Pelanggan[currentline-4].X *= 10;
                    Pelanggan[currentline-4].X += CKata.TabKata[i] - '0';
                } else if (spaced==2){
                    Pelanggan[currentline-4].Y *= 10;
                    Pelanggan[currentline-4].Y += CKata.TabKata[i] - '0';
                }
            } else if(currentline>=nNode+2){
                if (CKata.TabKata[i]!=' '){
                    if (CKata.TabKata[i] - '0' == 1){
                        // printf("Edges di (%d,%d) ",currentline-nNode-1,(i/2)+1);
                    }
                }
            }
        }
        // printf(" Current Line: %d\n",currentline);
        currentline++;
        spaced = 0;
        ADVKATA(BLANK);
    }
    CurrentPos = Base;
}

void menu(){
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@                     @\n");
	printf("@      Welcome to     @\n");
	printf("@     Santo Tycoon    @\n");
	printf("@                     @\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@\n");
	// printf("\n Mending Rakit PC\n-Pak Santo\n");
	printf("\n===[  Menu  ]===\n1. New Game \n2. Load Game \n3. Exit\n");
	int inp;
	printf("Input: ");
	scanf("%d",&inp);
	while (inp<1 || inp>3){
		printf("Wrong Input: !\nInput:");
		scanf(" %d",&inp);
	}
	if (inp==1){
        load();
        while (stillplaying){
		    play();
        }
	}
	else if (inp==2){
		play();
	}
	else{
		printf("Sampai jumpa!");
	}
}

int main(){
    Base.X = 0;
    Base.Y = 0;
    Shop.X = 0;
    Shop.Y = 0;
	menu();
	return 0;
}
