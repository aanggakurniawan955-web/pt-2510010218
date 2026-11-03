#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Pesanan {
    string nama;
    int halaman;
    char warna;
    long long total;
    string kategori;
};

string rapikanNama(const string& teks) {
    string hasil;
    bool awalKata = true;

    for (char ch : teks) {
        unsigned char c = static_cast<unsigned char>(ch);

        if (isspace(c)) {
            if (!hasil.empty() && hasil.back() != ' ') {
                hasil += ' ';
            }
            awalKata = true;
        } else {
            if (awalKata) {
                hasil += static_cast<char>(toupper(c));
                awalKata = false;
            } else {
                hasil += static_cast<char>(tolower(c));
            }
        }
    }

    while (!hasil.empty() && hasil.back() == ' ') {
        hasil.pop_back();
    }
    return hasil;
}

bool namaValid(const string& nama) {
    bool adaHuruf = false;

    for (char ch : nama) {
        unsigned char c = static_cast<unsigned char>(ch);

        if (isdigit(c)) {
            return false;
        }
        if (isalpha(c)) {
            adaHuruf = true;
        } else if (!isspace(c) && ch != '\'' && ch != '-') {
            return false;
        }
    }
    return adaHuruf;
}

int bacaBilangan(const string& pesan, int minimum, int maksimum) {
    int nilai;

    while (true) {
        cout << pesan;
        if (cin >> nilai && nilai >= minimum && nilai <= maksimum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nilai;
        }

        cout << "Input tidak valid. Masukkan angka "
             << minimum << " sampai " << maksimum << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char bacaWarna() {
    string pilihan;

    while (true) {
        cout << "Fotokopi berwarna? (Y/T): ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (pilihan.size() == 1) {
            char c = static_cast<char>(toupper(
                static_cast<unsigned char>(pilihan[0])
            ));
            if (c == 'Y' || c == 'T') {
                return c;
            }
        }

        cout << "Pilihan harus Y atau T.\n";
    }
}

int main() {
    vector<Pesanan> daftar;
    int jumlahPesanan;

    cout << "=====================================\n";
    cout << "       PROGRAM FOTOKOPI KAMPUS\n";
    cout << "=====================================\n";

    jumlahPesanan = bacaBilangan("Masukkan jumlah pesanan (1-100): ", 1, 100);

    for (int i = 0; i < jumlahPesanan; ++i) {
        Pesanan p{};

        cout << "\n--- Pesanan ke-" << i + 1 << " ---\n";

        while (true) {
            cout << "Nama pelanggan: ";
            getline(cin, p.nama);

            if (namaValid(p.nama)) {
                p.nama = rapikanNama(p.nama);
                break;
            }
            cout << "Nama tidak valid. Gunakan huruf dan spasi, tanpa angka.\n";
        }

        p.halaman = bacaBilangan("Jumlah halaman (1-1000): ", 1, 1000);
        p.warna = bacaWarna();

        int hargaPerHalaman;
        if (p.halaman <= 50) {
            hargaPerHalaman = 300;
        } else if (p.halaman <= 200) {
            hargaPerHalaman = 250;
        } else {
            hargaPerHalaman = 200;
        }

        p.total = static_cast<long long>(p.halaman) * hargaPerHalaman;

        if (p.warna == 'Y') {
            p.total *= 2;
        }

        if (p.halaman <= 50) {
            p.kategori = "Kecil";
        } else if (p.halaman <= 200) {
            p.kategori = "Sedang";
        } else {
            p.kategori = "Besar";
        }

        cout << "Kategori pesanan : " << p.kategori << '\n';
        cout << "Total biaya      : Rp " << p.total << '\n';

        daftar.push_back(p);
    }

    long long totalHalaman = 0;
    long long totalPendapatan = 0;
    int jumlahKecil = 0, jumlahSedang = 0, jumlahBesar = 0;
    size_t indeksTerbesar = 0;

    for (size_t i = 0; i < daftar.size(); ++i) {
        totalHalaman += daftar[i].halaman;
        totalPendapatan += daftar[i].total;

        if (daftar[i].kategori == "Kecil") {
            ++jumlahKecil;
        } else if (daftar[i].kategori == "Sedang") {
            ++jumlahSedang;
        } else {
            ++jumlahBesar;
        }

        if (daftar[i].total > daftar[indeksTerbesar].total) {
            indeksTerbesar = i;
        }
    }

    double rataRataHalaman =
        static_cast<double>(totalHalaman) / daftar.size();

    cout << "\n=====================================\n";
    cout << "          RINGKASAN PESANAN\n";
    cout << "=====================================\n";
    cout << left << setw(20) << "Nama"
         << setw(12) << "Halaman"
         << setw(12) << "Warna"
         << setw(12) << "Kategori"
         << "Total Biaya\n";

    for (const Pesanan& p : daftar) {
        cout << left << setw(20) << p.nama
             << setw(12) << p.halaman
             << setw(12) << (p.warna == 'Y' ? "Ya" : "Tidak")
             << setw(12) << p.kategori
             << "Rp " << p.total << '\n';
    }

    cout << "\nJumlah pesanan       : " << daftar.size() << '\n';
    cout << "Total seluruh halaman: " << totalHalaman << '\n';
    cout << "Total pendapatan     : Rp " << totalPendapatan << '\n';
    cout << fixed << setprecision(2);
    cout << "Rata-rata halaman    : " << rataRataHalaman << '\n';
    cout << "Pesanan terbesar     : " << daftar[indeksTerbesar].nama
         << " (Rp " << daftar[indeksTerbesar].total << ")\n";

    cout << "\nJumlah kategori:\n";
    cout << "Kecil  : " << jumlahKecil << '\n';
    cout << "Sedang : " << jumlahSedang << '\n';
    cout << "Besar  : " << jumlahBesar << '\n';

    cout << "\n=====================================\n";
    cout << "       GRAFIK JUMLAH PESANAN\n";
    cout << "=====================================\n";

    int nilaiMaksimum = max({jumlahKecil, jumlahSedang, jumlahBesar});
    for (int baris = nilaiMaksimum; baris >= 1; --baris) {
        cout << setw(3) << baris << " | ";
        cout << (jumlahKecil >= baris ? "# " : "  ");
        cout << (jumlahSedang >= baris ? "# " : "  ");
        cout << (jumlahBesar >= baris ? "#" : "") << '\n';
    }
    cout << "    +-------\n";
    cout << "      K  S  B\n";
    cout << "      Kecil Sedang Besar\n";

    cout << "\nProgram selesai. Terima kasih.\n";
    return 0;
}
