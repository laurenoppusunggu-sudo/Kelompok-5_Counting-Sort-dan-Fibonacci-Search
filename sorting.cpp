#include "sorting.h"

#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

// ==========================================
// MODUL SORTING (COUNTING SORT & BUBBLE)
// ==========================================

// --- Integer Counting Sort ---
void countingSortInt(vector<int>& arr, bool verbose, long long& comps, long long& swaps, double& durationMs) {
    comps = 0; 
    swaps = 0;
    if (arr.empty()) return;

    auto start = chrono::high_resolution_clock::now();

    int maxVal = arr[0];
int minVal = arr[0];

for (size_t i = 1; i < arr.size(); i++) {

    comps++;
    if (arr[i] > maxVal)
        maxVal = arr[i];

    comps++;
    if (arr[i] < minVal)
        minVal = arr[i];
}
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    vector<int> output(arr.size());

    if (verbose) {
        cout << "\n[TRACE] Menghitung frekuensi elemen (Min: " << minVal << ", Max: " << maxVal << ")\n";
    }

    for (size_t i = 0; i < arr.size(); i++) {
        count[arr[i] - minVal]++;
    }

    if (verbose && arr.size() <= 20) {
        cout << "[TRACE] Larik Frekuensi Terhitung: ";
        for (int i = 0; i < range; i++) {
            if (count[i] > 0) cout << "(" << (i + minVal) << ":" << count[i] << ") ";
        }
        cout << "\n";
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
        swaps++; 
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }

    auto end = chrono::high_resolution_clock::now();
    durationMs = chrono::duration<double, milli>(end - start).count();
}

// --- String Counting Sort ---
void countingSortString(vector<string>& arr, bool verbose, long long& comps, long long& swaps, double& durationMs) {
    comps = 0; 
    swaps = 0;
    if (arr.empty()) return;

    auto start = chrono::high_resolution_clock::now();

    vector<string> distinct = arr;
    sort(distinct.begin(), distinct.end());
    distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());

    int range = distinct.size();
    vector<int> count(range, 0);
    vector<string> output(arr.size());

    for (size_t i = 0; i < arr.size(); i++) {
        int idx = lower_bound(distinct.begin(), distinct.end(), arr[i]) - distinct.begin();
        count[idx]++;
    }

    if (verbose && arr.size() <= 20) {
        cout << "\n[TRACE] Frekuensi Kata Terhitung:\n";
        for (int i = 0; i < range; i++) {
            cout << "  \"" << distinct[i] << "\": " << count[i] << "\n";
        }
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        int idx = lower_bound(distinct.begin(), distinct.end(), arr[i]) - distinct.begin();
        output[count[idx] - 1] = arr[i];
        count[idx]--;
        swaps++;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }

    auto end = chrono::high_resolution_clock::now();
    durationMs = chrono::duration<double, milli>(end - start).count();
}

// --- Bubble Sort ---
void bubbleSortInt(vector<int>& arr, long long& comps, long long& swaps, double& durationMs) {
    comps = 0; swaps = 0;
    size_t n = arr.size();
    auto start = chrono::high_resolution_clock::now();

    for (size_t i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            comps++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    auto end = chrono::high_resolution_clock::now();
    durationMs = chrono::duration<double, milli>(end - start).count();
}
void makeAscending(vector<int>& arr)
{
    long long comps = 0;
    long long swaps = 0;
    double duration = 0;

    countingSortInt(
        arr,
        false,
        comps,
        swaps,
        duration
    );
}
