#include <iostream>  // Library untuk input-output
using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap (int arr[], int pos1, int pos2) {  
    int temp;
    temp = arr[pos1];   // Simpan nilai arr[pos1] ke dalam temp
    arr[pos1] = arr[pos2];  // Gantikan nilai arr[pos1] dengan arr[pos2]
    arr[pos2] = temp;   // Gantikan nilai arr[pos2] dengan nilai temp (arr[pos1] sebelumnya)
}

// Fungsi untuk melakukan partition pada Quick Sort
int partition (int arr[], int low, int high, int pivot) {  
    int i = low;  // Indeks untuk iterasi elemen dalam array
    int j = low;  // Indeks untuk menempatkan elemen yang lebih kecil atau sama dengan pivot

    while (i <= high) {  // Perulangan sampai i melebihi batas high
        if (arr[i] > pivot) {  // Jika elemen lebih besar dari pivot, lanjutkan iterasi
            i++;  
        }
        else {  
            swap (arr, i, j);  // Tukar elemen arr[i] dengan arr[j]
            i++;  
            j++;  
        }
    }
    return j - 1;  // Mengembalikan posisi akhir pivot setelah partitioning
}

// Fungsi rekursif untuk melakukan Quick Sort
void quicksort(int arr[], int low, int high) {  
    if (low < high) {  
        int pivot = arr[high];  // Memilih elemen terakhir sebagai pivot
        int pos = partition(arr, low, high, pivot);  // Lakukan partition pada array

        quicksort(arr, low, pos - 1);  // Rekursi untuk bagian kiri array
        quicksort(arr, pos + 1, high);  // Rekursi untuk bagian kanan array
    }
}

int main () {  
    int n;  
    cout << "Tentukan panjang array = ";  
    cin >> n;  // Input jumlah elemen array

    int arr[n];  // Deklarasi array dengan panjang n
    for (int i = 0; i < n; i++) {  
        cin >> arr[i];  // Input elemen array satu per satu
    }

    quicksort(arr, 0, n - 1);  // Memanggil fungsi Quick Sort untuk mengurutkan array

    cout << "Berikutnya adalah array yang telah di sortir = ";  
    for (int i = 0; i < n; i++) {  
        cout << arr[i] << "\t";  // Menampilkan elemen array yang telah diurutkan
    }  
}

