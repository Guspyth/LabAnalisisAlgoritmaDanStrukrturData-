#include <iostream>
using namespace std;

void swap (int arr[], int pos1, int pos2) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) { // Quick Sort descending
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Menampilkan array setelah setiap langkah partitioning
        for (int k = 0; k <= high; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nProses Quick Sort:\n";
    quicksort(arr, 0, n - 1);

    cout << "\nArray setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

