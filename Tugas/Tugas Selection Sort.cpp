#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, maxIndex, temp; // Mengubah minIndex menjadi maxIndex

    for (i = 0; i < n - 1; i++) {
        maxIndex = i; // Mengubah minIndex menjadi maxIndex

        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) { // Mengubah tanda "<" menjadi ">"
                maxIndex = j;
            }
        }

        // Menukar elemen terbesar dengan elemen di posisi i
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;

        cout << "Iterasi ke-" << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, i;

    cout << "Masukan jumlah elemen: ";
    cin >> n;

    int arr[n];

    cout << "Masukan nilai elemen: ";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Data sebelum sorting: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Data setelah sorting: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

