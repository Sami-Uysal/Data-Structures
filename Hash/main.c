#include <stdio.h>

#define SIZE 10

int A[SIZE];

int HashFunction(int key) {
    // gelen key değerinden index üretecek
    return key % SIZE;
}

int Search(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        if (dizi[index] == veri) {
            return 1; // Veri bulundu
        }

        // Linear Probing: Bir sonraki boş yere geç
        index = (index + 1) % SIZE;
    }

    return 0; // Veri bulunamadı
}

int Insert(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        // Linear Probing: Bir sonraki boş yere geç
        index = (index + 1) % SIZE;
    }

    dizi[index] = veri;
    return 1; // Ekleme başarılı
}

int Delete(int dizi[], int veri) {
    int index = HashFunction(veri);

    while (dizi[index] != 0) {
        if (dizi[index] == veri) {
            dizi[index] = -1; // -1, silinmiş bir elemanı temsil eder
            return 1; // Silme başarılı
        }

        // Linear Probing: Bir sonraki boş yere geç
        index = (index + 1) % SIZE;
    }

    return 0; // Silinen veri bulunamadı
}

int main() {
    // Hash tablosunu sıfırla
    for (int i = 0; i < SIZE; ++i) {
        A[i] = 0;
    }

    // Verileri ekle
    Insert(A, 25);
    Insert(A, 35);
    Insert(A, 45);

    // Verileri ara
    printf("Search(25): %s\n", Search(A, 25) ? "Bulundu" : "Bulunamadı");
    printf("Search(30): %s\n", Search(A, 30) ? "Bulundu" : "Bulunamadı");

    // Veriyi sil
    printf("Delete(35): %s\n", Delete(A, 35) ? "Silindi" : "Silinecek veri bulunamadı");

    // Silinen veriyi ara
    printf("Search(35): %s\n", Search(A, 35) ? "Bulundu" : "Bulunamadı");

    return 0;
}