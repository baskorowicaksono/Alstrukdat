#include<stdio.h>

#define N_MAX 1000

int main() {
    int jumlahAntrean, nomorAntrean[N_MAX], nomorPertama;

    scanf("%d", &jumlahAntrean);
    for (int i = 0; i < jumlahAntrean; i++) {
        scanf("%d", &nomorAntrean[i]);
    }


    /**
     * Proses: mencari nomor yang akan keluar pertama sesuai urutan antrean
     *  I.S.: jumlahAntrean > 0, array nomorAntrean sudah diisi
     *  F.S.: nomor yang akan dipanggil pertama sesuai urutan antrean
     * Implementasikan logika pada soal di sini, memasukkan ke dalam variabel `nomorPertama`
     */
    nomorPertama = 999;
    nomorPertama = nomorAntrean[0];


    printf("%d\n", nomorPertama);
}
