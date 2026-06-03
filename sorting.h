#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <string>

using namespace std;

void countingSortInt(
    vector<int>& arr,
    bool verbose,
    long long& comps,
    long long& swaps,
    double& durationMs
);

void countingSortString(
    vector<string>& arr,
    bool verbose,
    long long& comps,
    long long& swaps,
    double& durationMs
);

void bubbleSortInt(
    vector<int>& arr,
    long long& comps,
    long long& swaps,
    double& durationMs
);

void makeAscending(
    vector<int>& arr
);

#endif