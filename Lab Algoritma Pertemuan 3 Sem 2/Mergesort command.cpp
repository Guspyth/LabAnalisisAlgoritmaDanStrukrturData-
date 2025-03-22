#include <iostream>  // Library untuk input-output
using namespace std;

// Fungsi untuk menggabungkan dua bagian array yang sudah diurutkan
void merge(int arr[], int l, int m, int r) {
    int x, y, z;
    int n1 = m - l + 1; // Panjang subarray kiri
    int n2 = r - m;     // Panjang subarray kanan
    
    int L[n1], R[n2]; // Membuat array sementara untuk menyimpan nilai

    // Menyalin data ke dalam array sementara
    for (x = 0; x < n1; x++)
        L[x] = arr[l + x];
    for (y = 0; y < n2; y++)
        R[y] = arr[m + 1 + y];

    x = 0; // Indeks awal subarray kiri
    y = 0; // Indeks awal subarray kanan
    z = l; // Indeks awal array utama
    
    // Menggabungkan kembali dua subarray dalam urutan yang benar
    while (x < n1 && y < n2) {
        if (L[x] <= R[y]) {  // Jika elemen dari subarray kiri lebih kecil atau sama
            arr[z] = L[x];
            x++;
        } else {  // Jika elemen dari subarray kanan lebih kecil
            arr[z] = R[y];
            y++;
        }
        z++;
    }

    // Menyalin sisa elemen dari subarray kiri jika ada
    while (x < n1) {
        arr[z] = L[x];
        x++;
        z++;
    }

    // Menyalin sisa elemen dari subarray kanan jika ada
    while (y < n2) {
        arr[z] = R[y];
        y++;
        z++;
    }
}

// Fungsi rekursif untuk membagi array dan memanggil merge
void mergeSort(int arr[], int l, int r) {
    if (l < r) {  
        int m = l + (r - l) / 2;  // Menentukan titik tengah array

        mergeSort(arr, l, m);   // Rekursi untuk bagian kiri
        mergeSort(arr, m + 1, r); // Rekursi untuk bagian kanan

        merge(arr, l, m, r); // Menggabungkan hasil sorting dari bagian kiri dan kanan
    }
}

// Fungsi untuk menampilkan elemen array
void show(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";  // Menampilkan elemen array dengan spasi
}

int main() {
    int size;
    cout << "\nMasukan Banyak Data : ";
    cin >> size;  // Input jumlah elemen array

    int arr[size];  // Deklarasi array dengan panjang sesuai input
    for (int i = 0; i < size; i++) {
        cout << "\nMasukan Data array ke-" << i << " : ";
        cin >> arr[i];  // Input elemen array satu per satu
    }

    mergeSort(arr, 0, size - 1);  // Memanggil fungsi mergeSort

    cout << "\nHasil\n";
    show(arr, size);  // Menampilkan hasil sorting

    return 0;
}

