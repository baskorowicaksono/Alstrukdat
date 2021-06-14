#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "boolean.h"

#define InitialSize 10


typedef int IdxType;
typedef int ElType;
typedef struct {ElType name; IdxType amount;} Elmt;
typedef struct {
    Elmt *A;
    int Capacity;
    int Neff;
} ListDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
ListDin MakeList();

/**
 * Destruktor
 * I.S. List terdefinisi
 * F.S. list->A terdealokasi
 */
void DeallocateList(ListDin *list);

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsListEmpty(ListDin list);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int LengthList(ListDin list);

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElType GetName(ListDin list, IdxType i);

/**
 * Fungsi untuk mendapatkan nama barang yang berada pada indeks i.
 * Prekondisi: list terdefinisi
 */
Elmt Get(ListDin list, IdxType i);
//Mengambil isi dari elemen list yaitu Elmt yang terdiri dari barang dan jumlahnya

IdxType GetAmount(ListDin list, IdxType i);
//Mengambil jumlah dari barang yang ada di penyimpanan indeks ke i

boolean SearchB(ListDin T, ElType X);
//menghasilkan output true jika elemen X berada pada list T

IdxType Search1(ListDin T, ElType X);
//menghasilkan output indeks dari elemen X yang berada pada list T
//fungsi ini dijalankan hanya jika output dari fungsi SearchB menghasilkan True

int GetCapacity(ListDin list);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(ListDin *list, ElType el, IdxType i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(ListDin *list, ElType el);

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(ListDin *list, ElType el);

void DeleteElement(ListDin *list, ElType X);
//prosedur untuk menghapus 1 BUAH elemen X.
//I.S. list terdefinisi
//F.S. jika jumlah elemen X > 1 maka jumlah barangnya dikurangi 1. jika jumlah barang dari elemen X adalah 1, maka elemen tersebut dihapuskan dari list. Jika elemen X tidak ada dalam list, list tetap.

void PrintInfoDin (ListDin L);
/* menampilkan komponen ke layar*/

void PrintListDin (ListDin L);
/* menampilkan komponen ke layar beserta jumlah masing-masing komponen*/

#endif
