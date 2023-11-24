#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to dynamically allocate an array of integers
int* allocateIntArray(int numElements) {
    return new int[numElements];
}

// Function to calculate the average of an array
double calculateAverage(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// Function to calculate the median of an array
double calculateMedian(int* arr, int size) {
    sort(arr, arr + size);
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate the mode of an array
int calculateMode(int* arr, int size) {
    unordered_map<int, int> frequency;
    for (int i = 0; i < size; ++i) {
        frequency[arr[i]]++;
    }

    int mode = -1;
    int maxFrequency = 0;
    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            mode = pair.first;
            maxFrequency = pair.second;
        }
    }

    return mode;
}

int main() {
    // Get the num
