# Tugas 5 – Perulangan C++

## Berkas
- `sinilai_v04.cpp`: program SiNilai v0.4 yang melengkapi starter code dosen.
- `contoh_masukan.txt`: data uji yang disediakan dalam materi dosen.

## Cara kompilasi
```bash
g++ -std=c++17 -Wall -Wextra -pedantic sinilai_v04.cpp -o sinilai_v04
```

Jalankan di Windows:
```powershell
.\sinilai_v04.exe
```

Uji dengan data contoh di Windows:
```powershell
Get-Content contoh_masukan.txt | .\sinilai_v04.exe
```

## Konsep perulangan
- `do-while` meminta jumlah mahasiswa ulang jika nilainya kurang dari 1.
- `for` memproses mahasiswa dari nomor 1 sampai jumlah mahasiswa.
- `total_nilai` adalah akumulator penjumlahan nilai akhir seluruh mahasiswa.
- `jumlah_lulus` adalah akumulator penghitung mahasiswa yang lulus.
- Rekap menghitung mahasiswa belum lulus dan rata-rata kelas.

## Deklarasi AI
AI yang digunakan: ChatGPT (OpenAI).

Tujuan: membantu memahami instruksi tugas, menjelaskan bagian TODO pada starter code, dan membantu memeriksa struktur program.

Prompt/ringkasan: meminta bantuan menyelesaikan Tugas 5 Perulangan C++ dari awal berdasarkan ZIP materi dan instruksi pada LMS.

Umpan balik/pemeriksaan: program dikompilasi menggunakan `g++ -std=c++17 -Wall -Wextra -pedantic` dan diuji dengan `contoh_masukan.txt`. Hasil pengujian dibandingkan dengan tabel kasus uji pada README materi dosen.

Catatan: sesuaikan deklarasi ini jika proses penggunaan AI atau pengujian yang kamu lakukan berbeda.
