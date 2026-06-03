#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "sorting.h"
#include "searching.h"

using namespace std;

// Struktur data untuk menyimpan baris hasil pengujian/benchmark
struct BenchmarkResult {
    int size;
    string condition;
    double countingTime; // dalam milidetik
    long long countingComps;
    long long countingSwaps;
    double bubbleTime;  // dalam milidetik
    long long bubbleComps;
    long long bubbleSwaps;
};

// Variabel Global Data
vector<int> globalIntArray;
vector<string> globalStringArray;
bool isDataTypeInt = true; // true = int, false = string
bool isDataLoaded = false;
bool isSorted = false;

// Wadah untuk menyimpan data benchmark hasil simulasi
vector<BenchmarkResult> currentBenchmarkResults;

// ==========================================
// UTILITY FUNCTIONS & DATA GENERATION
// ==========================================

void printArrayInt(const vector<int>& arr, int maxElements = 100) {
    int n = arr.size();
    int limit = min(n, maxElements);
    cout << "[";
    for (int i = 0; i < limit; i++) {
        cout << arr[i];
        if (i < limit - 1) cout << ", ";
    }
    if (n > maxElements) cout << ", ... (dipotong, total " << n << " elemen)";
    cout << "]\n";
}

void printArrayString(const vector<string>& arr, int maxElements = 100) {
    int n = arr.size();
    int limit = min(n, maxElements);
    cout << "[";
    for (int i = 0; i < limit; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i < limit - 1) cout << ", ";
    }
    if (n > maxElements) cout << ", ... (dipotong, total " << n << " elemen)";
    cout << "]\n";
}

vector<int> generateRandomInt(int n, int minVal, int maxVal) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
    return arr;
}

vector<string> generateRandomString(int n, int length = 5) {
    vector<string> arr(n);
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < length; j++) {
            s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        arr[i] = s;
    }
    return arr;
}

// ==========================================
// HANDLERS UNTUK ALUR KONTROL CLI
// ==========================================

void handleInputData() {
    cout << "\n=========================================\n";
    cout << "1. INPUT / GENERATE DATA\n";
    cout << "=========================================\n";
    cout << "Pilih Tipe Data:\n  [1] Integer\n  [2] String\nPilihan: ";
    int typeChoice; cin >> typeChoice;
    isDataTypeInt = (typeChoice == 1);

    cout << "\nPilih Sumber Data:\n  [1] Input Manual\n  [2] Generate Acak\n  [3] Baca dari File Teks\nPilihan: ";
    int srcChoice; cin >> srcChoice;

    int n = 0;
    if (srcChoice == 1 || srcChoice == 2) {
        cout << "Masukkan jumlah elemen (10 - 1000): "; cin >> n;
        if (n < 10) n = 10;
    }

    if (isDataTypeInt) {
        globalIntArray.clear();
        if (srcChoice == 1) {
            cout << "Masukkan " << n << " angka:\n";
            for (int i = 0; i < n; i++) { int val; cin >> val; globalIntArray.push_back(val); }
        } else if (srcChoice == 2) {
            int mn, mx;
            cout << "Batas Min acak: "; cin >> mn;
            cout << "Batas Max acak: "; cin >> mx;
            globalIntArray = generateRandomInt(n, mn, mx);
        } else if (srcChoice == 3) {
            string fn; cout << "Nama file teks (.txt): "; cin >> fn;
            ifstream infile(fn);
            if (!infile) {
                cout << "Gagal! Menggunakan data acak default...\n";
                globalIntArray = generateRandomInt(30, 1, 100);
            } else {
                int val; while (infile >> val) globalIntArray.push_back(val);
                infile.close();
            }
        }
        cout << "Data termuat: "; printArrayInt(globalIntArray);
    } else {
        globalStringArray.clear();
        if (srcChoice == 1) {
            cout << "Masukkan " << n << " string:\n";
            for (int i = 0; i < n; i++) { string val; cin >> val; globalStringArray.push_back(val); }
        } else if (srcChoice == 2) {
            globalStringArray = generateRandomString(n, 5);
        } else if (srcChoice == 3) {
            string fn; cout << "Nama file teks (.txt): "; cin >> fn;
            ifstream infile(fn);
            if (!infile) {
                globalStringArray = generateRandomString(20, 4);
            } else {
                string val; while (infile >> val) globalStringArray.push_back(val);
                infile.close();
            }
        }
        cout << "Data termuat: "; printArrayString(globalStringArray);
    }
    isDataLoaded = true;
    isSorted = false;
}

void handleSorting() {
    if (!isDataLoaded) { cout << "Data kosong! Jalankan Menu 1 Terlebih Dahulu.\n"; return; }
    cout << "\n=========================================\n";
    cout << "2. JALANKAN SORTING (COUNTING SORT + TRACE)\n";
    cout << "=========================================\n";

    long long comps = 0, swaps = 0; double duration = 0;
    if (isDataTypeInt) {
        cout << "Sebelum Sorting: "; printArrayInt(globalIntArray);
        countingSortInt(globalIntArray, (globalIntArray.size() <= 20), comps, swaps, duration);
        cout << "Sesudah Sorting: "; printArrayInt(globalIntArray);
    } else {
        cout << "Sebelum Sorting: "; printArrayString(globalStringArray);
        countingSortString(globalStringArray, (globalStringArray.size() <= 20), comps, swaps, duration);
        cout << "Sesudah Sorting: "; printArrayString(globalStringArray);
    }
    cout << "\nWaktu Eksekusi: " << fixed << setprecision(4) << duration << " ms\nOp Swaps/Placement: " << swaps << "\n";
    isSorted = true;
}

void handleSearching() {
   if (!isDataLoaded)
{
    cout << "Data belum dimuat!\n";
    return;
}

if (!isSorted)
{
    cout << "Data harus diurutkan terlebih dahulu menggunakan Menu 2!\n";
    return;
}
    cout << "\n=========================================\n";
    cout << "3. JALANKAN SEARCHING (FIBONACCI SEARCH + TRACE)\n";
    cout << "=========================================\n";

    int steps = 0; double duration = 0; int resIndex = -1;
    if (isDataTypeInt) {
        int target; cout << "Masukkan angka target pencarian: "; cin >> target;
        resIndex = fibonacciSearchInt(globalIntArray, target, steps, duration);
    } else {
        string target; cout << "Masukkan string target pencarian: "; cin >> target;
        resIndex = fibonacciSearchString(globalStringArray, target, steps, duration);
    }

    if (resIndex != -1) cout << "\n=> BERHASIL: Elemen ditemukan pada indeks ke-[" << resIndex << "]\n";
    else cout << "\n=> GAGAL: Elemen tidak ada dalam array!\n";
    cout << "Waktu Pencarian: " << duration << " ms | Total Langkah: " << steps << "\n";
}

void handleBenchmark() {
    cout << "\n=========================================\n";
    cout << "4. PERBANDINGAN & BENCHMARK VS BUBBLE SORT\n";
    cout << "=========================================\n";
    cout << "Melakukan kalkulasi benchmark untuk N = 100, 500, 1000, 5000, 10000...\n";

    vector<int> sizes = {100, 500, 1000, 5000, 10000};
    vector<string> conditions = {"Acak", "Terurut Naik", "Terurut Turun", "Banyak Duplikat"};
    currentBenchmarkResults.clear();

    for (int size : sizes) {
        for (const string& cond : conditions) {
            vector<int> baseData(size);
            if (cond == "Acak") baseData = generateRandomInt(size, 1, size * 2);
            else if (cond == "Terurut Naik"){baseData = generateRandomInt(size, 1, size * 2); makeAscending(baseData);}
            else if (cond == "Terurut Turun"){baseData = generateRandomInt(size, 1, size * 2); makeAscending(baseData); reverse(baseData.begin(), baseData.end());}
            else if (cond == "Banyak Duplikat") baseData = generateRandomInt(size, 1, 4);

            long long cComps = 0, cSwaps = 0; double cTime = 0;
            vector<int> cCopy = baseData;
            countingSortInt(cCopy, false, cComps, cSwaps, cTime);

            long long bComps = 0, bSwaps = 0; double bTime = 0;
            vector<int> bCopy = baseData;
            if (size <= 2000) bubbleSortInt(bCopy, bComps, bSwaps, bTime); 

            BenchmarkResult res = {size, cond, cTime, cComps, cSwaps, bTime, bComps, bSwaps};
            currentBenchmarkResults.push_back(res);
        }
    }

    cout << setfill('-') << setw(95) << "-" << endl;
    cout << setfill(' ') << "| " << setw(6) << "Ukuran" << " | " << setw(15) << "Kondisi" << " | " << setw(15) << "Count T(ms)" << " | " << setw(12) << "Count Swaps" << " | " << setw(15) << "Bubble T(ms)" << " | " << setw(12) << "Bubble Comp" << " |\n";
    cout << setfill('-') << setw(95) << "-" << endl;
    cout << setfill(' ');
    for (const auto& r : currentBenchmarkResults) {
        cout << "| " << setw(6) << r.size << " | " << setw(15) << r.condition << " | " << setw(15) << r.countingTime << " | " << setw(12) << r.countingSwaps << " | " << setw(15) << r.bubbleTime << " | " << setw(12) << r.bubbleComps << " |\n";
    }
    cout << setfill('-') << setw(95) << "-" << endl;
}

void handleExport() {
    if (currentBenchmarkResults.empty()) { cout << "Silakan jalankan menu 4 terlebih dahulu!\n"; return; }
    cout << "\nFormat Ekspor:\n  [1] File Teks (.txt)\n  [2] File Spreadsheet (.csv)\nPilihan: ";
    int p; cin >> p;
    if (p == 1) {
        ofstream out("Hasil_Benchmark.txt");
        out << "Ukuran\tKondisi\tCounting_Time(ms)\tBubble_Time(ms)\n";
        for (const auto& r : currentBenchmarkResults) {
            out << r.size << "\t" << r.condition << "\t" << r.countingTime << "\t" << r.bubbleTime << "\n";
        }
        out.close();
    } else {
        ofstream out("Hasil_Benchmark.csv");
        out << "Ukuran,Kondisi,CountingTime_ms,BubbleTime_ms\n";
        for (const auto& r : currentBenchmarkResults) {
            out << r.size << "," << r.condition << "," << r.countingTime << "," << r.bubbleTime << "\n";
        }
        out.close();
    }
    cout << "Data berhasil diekspor!\n";
}

// ==========================================
// MAIN CONTROLLER LOOP
// ==========================================
int main() {
    srand(time(0));
    int pilihan;
    do {
        cout << "\n=========================================\n";
        cout << "PROYEK STRUKTUR DATA\n";
        cout << "COUNTING SORT & FIBONACCI SEARCH\n";
        cout << "=========================================\n";
        cout << "1. Input / Generate Data\n";
        cout << "2. Jalankan Sorting  (Counting Sort + trace)\n";
        cout << "3. Jalankan Searching (Fibonacci Search + trace)\n";
        cout << "4. Perbandingan & Benchmark vs Bubble Sort\n";
        cout << "5. Ekspor Hasil ke File\n";
        cout << "6. Keluar\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih Menu [1-6]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: handleInputData(); break;
            case 2: handleSorting(); break;
            case 3: handleSearching(); break;
            case 4: handleBenchmark(); break;
            case 5: handleExport(); break;
            case 6: cout << "\nProgram Selesai! Terima kasih.\n"; break;
            default: cout << "\nPilihan menu tidak valid!\n"; break;
        }
    } while (pilihan != 6);
    return 0;
}