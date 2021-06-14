#define Nil NULL
typedef int ElType;
typedef struct tNode *address;
typedef struct tNode { ElType info; address next; } Node;

/* Definisi list: */
/* List kosong: First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last,
maka Next(Last) = First */

typedef struct {
address First;
} List;

/* Selektor */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

void InsertFirst (List *L, ElType X)
{
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen ber

-address P sebagai elemen pertama */

/* Kamus Lokal */
address P, last;
/* Algoritma */
P = Alokasi(X);
if (P != Nil) {
    if (IsEmpty(*L)) {
        Next(P) = P;
    }
    else /* L tidak kosong */ {
    last = First(*L);
    while (Next(last) != First(*L)) {
        last = Next(last);
    } /* Next(last) = First(L) ==> elemen terakhir */
    Next(P) = First(*L);
    Next(last) = P;
    }
    First(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec)
/* I.S. Prec pastilah node dari list; P sudah dialokasi */
/* F.S. Insert P sebagai node sesudah node beralamat Prec */
/*karena ada Prec, maka prekondisi list tidak kosong*/
{
        Next(P) = Next(Prec);
        Next(Prec) = P;
}
void InsertLast(List *L, ElType X) {
/* I.S. List L terdefinisi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
/* Kamus Lokal */
    address P, last;
    /* Algoritma */
    if (IsEmpty(*L)) {
        InsertFirst(L,X);
    }
    else {
        P = Alokasi(X);
        if (P != Nil) {
            last = First(*L);
            while (Next(last) != First(*L)) {
                last = Next(last);
            } /* Next(last) = First(L) */
            Next(last) = P;
            Next(P) = First(*L);
            }
        }
}

void DeleteFirst(List *L, ElType *X) {
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
/* Kamus Lokal */
    address P, last;
    /* Algoritma */
    P = First(*L); *X = Info(P);
    if (Next(First(*L)) == First(*L)) { /* satu elemen */
        First(*L) = Nil;
    }
    else {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        } /* Next(last) = First(L) */
        First(*L) = Next(First(*L)); Next(last) = First(*L);
        }
    Dealokasi(&P);
}


void DeleteLast(List *L, ElType *X) {
/* I.S. List tidak kosong */
/* F.S. X adalah elemen terakhir list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/* Kamus Lokal */
    address Last, PrecLast;
    /* Algoritma */
    Last = First(*L); PrecLast = Nil;
    while (Next(Last) != First(*L)) {
        PrecLast = Last; Last = Next(Last);
    } /* Next(Last) = First(*L) */
    if (PrecLast == Nil) { /* kasus satu elemen */
        First(*L) = Nil;
    }
    else {
        Next(PrecLast) = First(*L);
    }
    *X = Info(Last);
    Dealokasi(&Last);
}

void DeleteAfter(List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list.
Next(Prec)!=Nil */
/* F.S. Menghapus Next(Prec): */
/* Pdel adalah alamat elemen list yang dihapus */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Pdel);
    Dealokasi(&Pdel);
}
