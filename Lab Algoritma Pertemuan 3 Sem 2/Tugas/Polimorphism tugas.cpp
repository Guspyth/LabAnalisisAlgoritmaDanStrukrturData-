#include <iostream>
#include <string>
using namespace std;

// Class dasar Mahasiswa
class Mahasiswa {
protected:
    string status; // Alumni atau Mahasiswa Aktif
    string nama;
    int umur;
    string jurusan;
    string fakultas;

public:
    // Konstruktor
    Mahasiswa(string s, string n, int u, string j, string f)
        : status(s), nama(n), umur(u), jurusan(j), fakultas(f) {}

    // Metode virtual untuk menampilkan informasi
    virtual void tampilkanInfo() {
        cout << "Status    : " << status << endl;
        cout << "Nama      : " << nama << endl;
        cout << "Umur      : " << umur << endl;
        cout << "Jurusan   : " << jurusan << endl;
        cout << "Fakultas  : " << fakultas << endl;
    }

    // Destructor virtual
    virtual ~Mahasiswa() {}
};

// Class MahasiswaAktif (turunan dari Mahasiswa)
class MahasiswaAktif : public Mahasiswa {
public:
    // Konstruktor
    MahasiswaAktif(string n, int u, string j, string f)
        : Mahasiswa("Mahasiswa Aktif", n, u, j, f) {}

    // Override metode tampilkanInfo
    void tampilkanInfo() override {
        cout << "== Data Mahasiswa Aktif ==" << endl;
        Mahasiswa::tampilkanInfo();
        cout << "--------------------------" << endl;
    }
};

// Class Alumni (turunan dari Mahasiswa)
class Alumni : public Mahasiswa {
public:
    // Konstruktor
    Alumni(string n, int u, string j, string f)
        : Mahasiswa("Alumni", n, u, j, f) {}

    // Override metode tampilkanInfo
    void tampilkanInfo() override {
        cout << "== Data Alumni ==" << endl;
        Mahasiswa::tampilkanInfo();
        cout << "-----------------" << endl;
    }
};

int main() {
    // Input dua data mahasiswa
    Mahasiswa *mhs1 = new MahasiswaAktif("Agus Nurfajri", 18, "Teknologi Informasi", "Fakultas Ilmu Komputer");
    Mahasiswa *mhs2 = new Alumni("Budi Santoso", 24, "Managemen", "Fakultas Ekonomi");

    // Menampilkan informasi menggunakan polymorphism
    mhs1->tampilkanInfo();
    mhs2->tampilkanInfo();

    // Bersihkan memori
    delete mhs1;
    delete mhs2;

    return 0;
}

