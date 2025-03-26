#include <iostream>
#include <string>
using namespace std;

class PeminjamanBuku {
private:
    string nama;
    string npm;
    string judulBuku;
    string penulisBuku;

public:
    // Setter untuk data peminjam
    void setPeminjam(string nama, string npm) {
        this->nama = nama;
        this->npm = npm;
    }

    // Setter untuk data buku
    void setBuku(string judul, string penulis) {
        this->judulBuku = judul;
        this->penulisBuku = penulis;
    }

    // Menampilkan informasi peminjam dan buku yang dipinjam
    void tampilkanData() {
        cout << "\nName  : " << nama << endl;
        cout << "NPM   : " << npm << endl;
        cout << "Books borrowed :\n" << endl;
        cout << judulBuku << " by " << penulisBuku << endl;
        cout << "\nHarap kembalikan buku / s setelah 1 bulan." << endl;
    }
};

int main() {
    PeminjamanBuku peminjam;
    string nama, npm, judul, penulis;
    int pilihan, jumlahBuku;

    cout << "Enter your name : ";
    getline(cin, nama);
    cout << "Enter your NPM  : ";
    cin >> npm;
    cin.ignore();  // Membersihkan buffer input

    peminjam.setPeminjam(nama, npm);

    cout << "\nChoose an option :\n";
    cout << "1. Borrow a book\n";
    cout << "2. Return a book\n";
    cout << "\nEnter your choice (1/2) : ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        cout << "\nEnter the number of books you want to borrow : ";
        cin >> jumlahBuku;
        cin.ignore();

        for (int i = 0; i < jumlahBuku; i++) {
            cout << "\nEnter book " << i + 1 << " title   : ";
            getline(cin, judul);
            cout << "Enter book " << i + 1 << " author  : ";
            getline(cin, penulis);

            peminjam.setBuku(judul, penulis);
        }
        peminjam.tampilkanData();
    } else if (pilihan == 2) {
        cout << "\nThank you for returning the book!" << endl;
    } else {
        cout << "\nInvalid choice!" << endl;
    }

    return 0;
}

