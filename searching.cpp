#include "searching.h"

#include <iostream>
#include <chrono>

using namespace std;

// ==========================================
// MODUL SEARCHING (FIBONACCI SEARCH)
// ==========================================

int fibonacciSearchInt(const vector<int>& arr, int target, int& steps, double& durationMs) {
    steps = 0;
    auto start = chrono::high_resolution_clock::now();

    int n = arr.size();
    int fibM2 = 0;  
    int fibM1 = 1;  
    int fibM = fibM2 + fibM1;  

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        steps++;
        int i = min(offset + fibM2, n - 1);
        
        cout << "[TRACE] Langkah " << steps << ": Memeriksa indeks " << i << " (Nilai: " << arr[i] << "), Status Fibonacci: F(" << fibM << ")\n";

        if (arr[i] < target) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            auto end = chrono::high_resolution_clock::now();
            durationMs = chrono::duration<double, milli>(end - start).count();
            return i; 
        }
    }

    if (fibM1 && offset + 1 < n && arr[offset + 1] == target) {
        steps++;
        auto end = chrono::high_resolution_clock::now();
        durationMs = chrono::duration<double, milli>(end - start).count();
        return offset + 1;
    }

    auto end = chrono::high_resolution_clock::now();
    durationMs = chrono::duration<double, milli>(end - start).count();
    return -1; 
}

int fibonacciSearchString(const vector<string>& arr, const string& target, int& steps, double& durationMs) {
    steps = 0;
    auto start = chrono::high_resolution_clock::now();

    int n = arr.size();
    int fibM2 = 0; int fibM1 = 1; int fibM = fibM2 + fibM1;

    while (fibM < n) {
        fibM2 = fibM1; fibM1 = fibM; fibM = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        steps++;
        int i = min(offset + fibM2, n - 1);

        cout << "[TRACE] Langkah " << steps << ": Memeriksa indeks " << i << " (Nilai: \"" << arr[i] << "\"), Status Fibonacci: F(" << fibM << ")\n";

        if (arr[i] < target) {
            fibM = fibM1; fibM1 = fibM2; fibM2 = fibM - fibM1; offset = i;
        } else if (arr[i] > target) {
            fibM = fibM2; fibM1 = fibM1 - fibM2; fibM2 = fibM - fibM1;
        } else {
            auto end = chrono::high_resolution_clock::now();
            durationMs = chrono::duration<double, milli>(end - start).count();
            return i;
        }
    }

    if (fibM1 && offset + 1 < n && arr[offset + 1] == target) {
        steps++;
        auto end = chrono::high_resolution_clock::now();
        durationMs = chrono::duration<double, milli>(end - start).count();
        return offset + 1;
    }

    auto end = chrono::high_resolution_clock::now();
    durationMs = chrono::duration<double, milli>(end - start).count();
    return -1;
}