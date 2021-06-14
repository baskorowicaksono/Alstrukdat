#include "ternary_search_tree.h"

/* *** Konstruktor *** */
TernaryTree Tree (infotype Akar)
/* Menghasilkan sebuah pohon ternary dengan nilai info root = Akar */
/* left, middle, dan right bernilai Nil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    TernaryTree New_tree = (TernaryTree) malloc(sizeof(TernaryTree));

    if (New_tree != Nil){
        Info(New_tree) = Akar;
        Left(New_tree) = Nil;
        Right(New_tree) = Nil;
        Middle(New_tree) = Nil;

        return New_tree;
    }
    else {

        return Nil;
    }
}
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode New_node = (addrNode) malloc(sizeof(Node));

    if (New_node != Nil){
        Info(New_node) = X;
        Left(New_node) = Nil;
        Right(New_node) = Nil;
        Middle(New_node) = Nil;

        return New_node;
    }
    else {

        return Nil;
    }
}

void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (TernaryTree P)
/* Mengirimkan true jika P adalah pohon ternary kosong */
{
    return P == Nil;
}
boolean IsTreeOneElmt (TernaryTree P)
/* Mengirimkan true jika P adalah pohon ternary tidak kosong dan hanya memiliki 1 elemen */
{
    if (!IsTreeEmpty(P)) {
		if (Left(P) == Nil && Right(P) == Nil && Middle(P) == Nil) {
			return true;
		}
		else {
			return false;
		}
	} else {
		return false;
	}
}

boolean IsUnerLeft (TernaryTree P)
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)) && IsTreeEmpty(Middle(P))) {
			return true;
		} 
        else {
		    return false;
		    }
    }
    else {
		return false;
	}
}
boolean IsUnerMiddle (TernaryTree P)
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unermiddle: hanya mempunyai subpohon tengah */
{
    if (!IsTreeEmpty(P)) {
		if (IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)) && !IsTreeEmpty(Middle(P))) {
			return true;
		} 
        else {
		    return false;
		    }
    }
    else {
		return false;
	}
}
boolean IsUnerRight (TernaryTree P)
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (!IsTreeEmpty(P)) {
		if (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)) && IsTreeEmpty(Middle(P))) {
			return true;
		} 
        else {
		    return false;
		    }
    }
    else {
		return false;
	}
}
boolean IsBinary (TernaryTree P)
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon biner: mempunyai 2 dari 3 subpohon (kiri, tengah, kanan)*/
{
    if (!IsTreeEmpty(P)) {
		if ((!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)) && IsTreeEmpty(Middle(P))) || (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)) && !IsTreeEmpty(Middle(P))) || (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)) && !IsTreeEmpty(Middle(P)))){
			return true;
		} 
        else {
		    return false;
		    }
    }
    else {
		return false;
	}
}
boolean IsTernary (TernaryTree P)
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon ternary lengkap: mempunyai seluruh subpohon kiri, tengah, kanan*/
{
    if (!IsTreeEmpty(P)) {
		if (!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)) && !IsTreeEmpty(Middle(P))) {
			return true;
		} 
        else {
		    return false;
		    }
    }
    else {
		return false;
	}
}
/* *** Traversal *** */
void PrintTree (TernaryTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, pohon tengah, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   () adalah pohon kosong
   (A()()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()()())(C()()())(D()()())) adalah pohon dengan akar A dan subpohon kiri (B()()()) dan subpohon tengah (C()()()) dan subpohon kanan (D()()()) */
{
    printf("()()");
}
/* *** Searching *** */
int CountElmt (TernaryTree P, infotype X)
/* Mengirimkan jumlah kemunculan nilai X pada node P (P bisa kosong) */
{
    int count = 0;
    if (IsTreeEmpty(P)){
        return 0;
    }
    else{
        if (Info(P) == X){
            count++;
        }
        else
        {
            return CountElmt(Left(P),X) + CountElmt(Right(P),X) + CountElmt(Middle(P),X);
        }
        
    }
}
infotype GetSmallest (TernaryTree P)
/* Mengirimkan nilai node infotype (int) terkecil pada P (P tidak kosong) */
{
    if (IsTreeOneElmt(P)){
        return Info(P);
    }
    else{
        return GetSmallest(Left(P));
    }    
}
infotype GetLargest (TernaryTree P)
/* Mengirimkan nilai node infotype (int) terbesar pada P (P tidak kosong) */
{
    if (IsTreeOneElmt(P)){
        return Info(P);
    }
    else{
        return GetLargest(Right(P));
    }    
}
infotype GetMode (TernaryTree P)
/* Mengirimkan nilai node infotype (int) dengan kemunculan paling banyak (modus) pada P (P tidak kosong)*/
{

    infotype mode = Info(P);
    if (CountElmt(P,Info(P)) < CountElmt(Left(P),Info(Left(P)))){
        mode = Info(Left(P));
        GetMode(Left(P));
    }
    else if (CountElmt(P,Info(P)) < CountElmt(Right(P),Info(Right(P)))){
        mode = Info(Right(P));
        GetMode(Right(P));
    }
    else if (CountElmt(P,Info(P)) < CountElmt(Middle(P),Info(Middle(P)))){
        mode = Info(Middle(P));
        GetMode(Middle(P));
    }
    return mode;

}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (TernaryTree P)
/* Mengirimkan banyaknya elemen (node) pohon ternary P */
{
    if (IsTreeEmpty(P)){
        return 0;
    }
	else {
		return (1 + NbElmt(Left(P)) + NbElmt(Right(P)) +NbElmt(Middle(P)));
	}
} 
int NbUniqueElmt (TernaryTree P)
/* Mengirimkan banyaknya elemen (node) dengan infotype unik pada pohon ternary P */
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else{
        if (IsTreeOneElmt(P)){
            return 1;
        }
        else{
            CountElmt(Left(P), Info(Left(P)));
        }
    }
}
int NbDaun (TernaryTree P)
/* Mengirimkan banyaknya daun (node) pohon ternary P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeEmpty(P)){
        return 0;
    }
    else {
        if (IsTreeOneElmt(P)){
            return 1;
        }
        else{
            return NbDaun(Left(P)) + NbDaun(Right(P)) + NbDaun(Middle(P));
        }
    }
}
int Tinggi (TernaryTree P)
/* Pohon ternary mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim tinggi dari pohon, contoh:
   () --> 0
   (A()()()) --> 1
   (A(B()()())()()) --> 2 */
{
   if (IsTreeEmpty(P)){
        return 0;
   }
   else{
        int Tinggi_l = Tinggi(Left(P));
        int Tinggi_r = Tinggi(Right(P));
        int Tinggi_m = Tinggi(Middle(P));

        if (Tinggi_l > Tinggi_r){
            if (Tinggi_l > Tinggi_m){
                return Tinggi_l + 1;
            }
            else{
                return Tinggi_m + 1;
            }
        }
        else{
            if (Tinggi_r > Tinggi_m){
                return Tinggi_r + 1;
            }
            else{
                return Tinggi_m + 1;
            }
        }
   }
}

/* *** Operasi lain *** */
void AddElmt (TernaryTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun sesuai definisi ternary search tree */
{
	if (IsTreeEmpty(*P)) {
		*P= Tree(X);
	}
    else{
        if (X < Info(*P)){
            AddElmt(&Left(*P),X);
        }
        else if (X == Info(*P)){
            AddElmt(&Left(*P), X);
        }
        else
        {
            AddElmt(&Right(*P), X);
        }
    }
}
void DelDaun (TernaryTree *P, infotype X)
/* I.S. P tidak kosong, ada 1 daun bernilai X. */
/* F.S. Menghapus 1 daun bernilai X dari P. */
{

    if (!IsTreeEmpty(*P)){

        if (IsTreeOneElmt(*P) && Info(*P) == X){
            addrNode temp = *P;
            *P = Nil;
            DealokNode(temp);
        }

        else {

            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
            DelDaun(&Middle(*P), X);
        }
    }
}

