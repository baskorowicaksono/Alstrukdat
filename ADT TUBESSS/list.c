#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
ListDin MakeList(){
    ListDin list;
    list.A = (Elmt *) malloc(InitialSize * sizeof(Elmt));
    list.Neff = 0;
    list.Capacity = InitialSize;
    return list;
}


/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(ListDin *list){
    free((*list).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsListEmpty(ListDin list)
{
return list.Neff == 0;
}
/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int LengthList(ListDin list){
    if (!IsListEmpty(list)){
        return list.Neff;
    }
    else{
        return 0;
    }
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElType GetName(ListDin list, IdxType i)
{
    return list.A[i].name;
}
/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
Elmt Get(ListDin list, IdxType i)
{
    return list.A[i];
}
IdxType GetAmount(ListDin list, IdxType i)
{
    return list.A[i].amount;
}

int GetCapacity(ListDin list)
{
    return list.Capacity - LengthList(list);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
 boolean SearchB(ListDin T, ElType X){
    if (IsListEmpty(T)){
        return false;
    }
    boolean found = false;
    int i;
    for(i= 0; i <= LengthList(T) - 1; i++){
        if (GetName(T,i) == X){
            found = true;
            break;
        }
    }
    return found;
}
IdxType Search1(ListDin T, ElType X)
//fungsi ini hanya akan dijalankan ketika fungsi SearchB menghasilkan output True
{
    int i,result;
    for(i= 0; i <= LengthList(T) - 1; i++){
        if (GetName(T, i) == X){
            result = i;
            break;
        }
    }
    return result;
}


void InsertAt(ListDin *list, ElType el, IdxType i) {
    int length = LengthList(*list);
    int capacity = GetCapacity(*list);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Elmt *array = (Elmt *) malloc(desiredCapacity * sizeof(Elmt));
        for (int a = 0; a < length; a++) {
            array[a] = Get(*list, a);
        }
        free(list->A);

        list->A = array;
        list->Capacity = desiredCapacity;
    }
    if (SearchB(*list,el)){
        list->A[Search1(*list,el)].amount += 1;
    }
    else{
        for (int a = length - 1; a >= i; a--) {
            list->A[a + 1] = list->A[a];
        }

        list->A[i].name = el;
        list->A[i].amount = 1;
        list->Neff++;
    }

}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(ListDin *list, ElType el) {
    int insertAt = LengthList(*list);
    InsertAt(list, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(ListDin *list, ElType el) {
    InsertAt(list, el, 0);
}

void DeleteElement(ListDin *list, ElType X)
{
    if (SearchB(*list,X)){
        if (list->A[Search1(*list,X)].amount == 1){
            list->A[Search1(*list,X)].amount = 0;
            if( Search1(*list,X) != LengthList(*list)-1){
                int j;
                for (j = Search1(*list,X); j <= LengthList(*list) - 1; j++){
                    list->A[j] = list->A[j+1];
                }
                list->Neff--;
            }
            else{
                list->Neff--;
                Elmt *array = (Elmt *) malloc(list->Capacity * sizeof(Elmt));
                for (int a = 0; a < LengthList(*list); a++) {
                    array[a] = Get(*list, a);
                }
                free(list->A);
                list->A = array;
            }

        }
        else{
            IdxType index = Search1(*list,X);
            list->A[index].amount--;
        }
    }
}

void PrintInfoDin (ListDin L)
/* menampilkan komponen ke layar*/
{
    int i, j;
    j = 1;
    for (i = 0; i < L.Neff; i++){
        printf("%d. %d\n",j, L.A[i].name);
        j++;
    }
}

void PrintListDin (ListDin L)
/* menampilkan komponen ke layar beserta jumlah masing-masing komponen*/
{
    int i, j;
    j = 1;
    for (i = 0; i < L.Neff; i++){
        printf("%d. %d (%d)\n",j, L.A[i].name, L.A[i].amount);
        j++;
    }
}

