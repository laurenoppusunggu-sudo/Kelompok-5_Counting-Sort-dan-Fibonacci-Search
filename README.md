# Counting Sort dan Fibonacci Search

## Anggota Kelompok

* Lauren Miadina Oppu Sunggu (5253151052)
* Melati Asyila (5253151049)
* Berkat Revaldo Harefa (5253151035)

## DOSEN PENGAMPU
Ali Akbar Lubis, S.Kom., M.TI.

## Mata Kuliah
Struktur Data

## Deskripsi Program

Program ini dibuat untuk mengimplementasikan algoritma Counting Sort sebagai metode pengurutan data dan Fibonacci Search sebagai metode pencarian data. Program dikembangkan menggunakan bahasa pemrograman C++ dan dijalankan melalui antarmuka berbasis teks (CLI).

## Cara Kerja Program

1. Pengguna dapat memasukkan data secara manual, menghasilkan data secara acak, atau membaca data dari file teks.
2. Data yang diperoleh kemudian diurutkan menggunakan algoritma Counting Sort.
3. Setelah data terurut, pengguna dapat mencari nilai tertentu menggunakan algoritma Fibonacci Search.
4. Program menyediakan fitur benchmark untuk membandingkan performa Counting Sort dengan Bubble Sort berdasarkan waktu eksekusi dan jumlah operasi.
5. Hasil benchmark dapat diekspor ke dalam file teks (.txt) maupun file CSV (.csv).

## Fitur Program

* Input data manual
* Generate data acak
* Membaca data dari file teks
* Sorting menggunakan Counting Sort
* Searching menggunakan Fibonacci Search
* Benchmark Counting Sort vs Bubble Sort
* Export hasil benchmark ke file

## Studi Kasus

Program ini menggunakan studi kasus berupa analisis distribusi nilai ujian mahasiswa. Data nilai dipilih karena memiliki karakteristik yang sesuai dengan algoritma Counting Sort, yaitu berupa bilangan bulat dengan rentang nilai terbatas antara 0 sampai 100.

Pada studi kasus ini, data nilai mahasiswa dapat dimasukkan secara manual, dibaca dari file teks, atau dihasilkan secara acak oleh program. Data tersebut kemudian diurutkan menggunakan algoritma Counting Sort untuk mengetahui distribusi nilai dari yang terendah hingga tertinggi.

Setelah proses pengurutan selesai, algoritma Fibonacci Search digunakan untuk mencari nilai tertentu yang diinginkan pengguna. Program akan menampilkan posisi data yang ditemukan beserta langkah-langkah pencarian yang dilakukan.

Melalui studi kasus ini, pengguna dapat memahami bagaimana algoritma Counting Sort dan Fibonacci Search diterapkan dalam pengolahan data akademik serta mengetahui keunggulan kedua algoritma dalam proses pengurutan dan pencarian data secara efisien.

## Struktur File

* main.cpp : Program utama dan menu aplikasi
* sorting.cpp / sorting.h : Implementasi algoritma Counting Sort dan Bubble Sort
* searching.cpp / searching.h : Implementasi algoritma Fibonacci Search
* README_compile.txt : Petunjuk kompilasi dan menjalankan program
* Laporan Proyek_Kelompok5.pdf : Laporan pendamping proyek 
* Presentasi Proyek_Kelompok5.pptx : Slide presentasi proyek
* Hasil_Benchmark.txt : Hasil benchmark dalam format teks 
* Hasil_Benchmark.csv : Hasil benchmark dalam format CSV
* README.md : Dokumentasi dan penjelasan program

## Cara Kompilasi

Persyaratan:
- GCC / G++ Compiler

Cara Kompilasi:

g++ main.cpp sorting.cpp searching.cpp -o program

Cara Menjalankan:
.\program.exe

Keterangan:
Program mengimplementasikan algoritma Counting Sort dan Fibonacci Search
untuk proses pengurutan dan pencarian data.

## Tahun
2026
