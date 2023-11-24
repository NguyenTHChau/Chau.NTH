#include <iostream>
using namespace std;

// Function to calculate the median of an array
double calculateMedian(const int* arr, int size) {
    if (size <= 0) {
        return 0.0; // Return 0 if the array is empty
    }

    // Use pointer notation to access array elements
    const int* middle = arr + size / 2;

    // Check if the array has an even number of elements
    if (size % 2 == 0) {
        // If even, calculate the mean of the two middle values
        const int* middle2 = middle - 1;
        return static_cast<double>(*middle + *middle2) / 2.0;
    } else {
        // If odd, return the middle value
        return static_cast<double>(*middle);
    }
}

int main() {
    const int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};

    // Call the function to calculate the median
    double median = calculateMedian(arr, size);

    // Display the result
    cout << "Median: " << median << std::endl;

    return 0;
}
