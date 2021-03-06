#include "mesin_kar.h"

/**
 * Menghitung jumlah kemunculan karakter pada suatu pita karakter
 * needle merupakan huruf yang akan dihitung
 * filename merupakan nama file
 * Fungsi mengembalikan jumlah karakter yang muncul pada pita karakter
 */

 /* State Mesin */
extern char CC;
extern boolean EOP;

/*
  pada implementasi (mesin_kar.c), perlu ditambahkan variabel static
  global yang menyimpan pembacaan file pita.
*/

void START(char* filename)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita

Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */
{
    pita = fopen(filename,"r");
    ADV();
}

void ADV()
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,

CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita,"%c",&CC);
    if (IsEOP) {
        fclose(pita);
    }
}

char GetCC()
/* Mengembalikan karakter yang sedang terbaca di jendela.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : mengembalikan karakter yang sedang terbaca di jendela
*/
{
    i = 0;
    while ((CC != MARK) && (CC != BLANK)){
        C
    }

}

boolean IsEOP()
/* Mengecek apakah pita telah selesai dibaca
I.S. : Pita telah terbaca
F.S. : Menegmbalikan true jika pita telah selesai terbaca, false jika sebaliknya
*/
{
    if (CC == MARK){
        return true
    }
}

int count_char(char needle, char *filename) {
    int count = 0;
    START(filename);
    while (!IsEOP()) {
        if (GetCC() == needle) {
            count++;
        }
        ADV();
    }

    return count;
}
