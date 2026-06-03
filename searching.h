#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include <string>

using namespace std;

int fibonacciSearchInt(
    const vector<int>& arr,
    int target,
    int& steps,
    double& durationMs
);

int fibonacciSearchString(
    const vector<string>& arr,
    const string& target,
    int& steps,
    double& durationMs
);

#endif