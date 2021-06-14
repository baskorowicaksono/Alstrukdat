/*  NIM  : 18219113
    Nama : Baskoro Adi Wicaksono
    Tanggal : 22 Oktober 2020
    Topik Praktikum : Praktikum 5
    Deskripsi   : ADT Stack */

#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    ((*S).TOP) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return (S.TOP == Nil);
}

bool IsFull(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return (S.TOP == MaxEl);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    ((*S).TOP)++;
    (*S).T[(*S).TOP-1] = X;
}

void Pop(Stack *S, infotype *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = (*S).T[(*S).TOP-1];
    ((*S).TOP)--;
}

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
{
    if ((*S).TOP != MaxEl){
        Push(S, X);
    }
    else{

        Stack *Sout;
        CreateEmpty(Sout);
        infotype Y,Z;
        int i;
        for (i = MaxEl-1; i > 0; i--){
            Pop(S, Y);
            Push(Sout,Y);
        }
        Pop(S,Z);
        for (i = MaxEl-1; i > 0; i--){
            Pop(Sout, Y);
            Push(S,Y);
        Push(S,X);
        }
}
}
