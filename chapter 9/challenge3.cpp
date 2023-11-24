#include <iostream>
#include <algorithm> // for std::sort
#include <iomanip>   // for std::setprecision

// Function to dynamically allocate an array of integers
int* allocateIntArray(int numElements) {
    // Dynamically allocate an array of integers
    return new int[numElements];
}

// Function to sort an array in ascending order
void sortArray(int* arr, int size) {
    std::sort(arr, arr + size);
}

// Function to calculate the average of an array (excluding the lowest value)
double calculateAverage(int* arr, int size) {
    // Sort the array in ascending order
    sortArray(arr, size);

    // Calculate the sum of all values except the lowest
    int sum = 0;
    for (int i = 1; i < size; ++i) {
        sum += arr[i];
    }

    // Calculate the average
    return static_cast<double>(sum) / (size - 1);
}

int main() {
    // Add the using namespace std; statement
    using namespace std;

    int numScores;

    // Get the number of test scores from the user
    cout << "Enter the number of test scores: ";
    cin >> numScores;

    // Call the function to allocate the array
    int* testScores = allocateIntArray(numScores);

    // Get test scores from the user
    cout << "Enter the test scores:\n";
    for (int i = 0; i < numScores; ++i) {
        cout << "Test score " << i + 1 << ": ";
        cin >> testScores[i];
    }

    // Call the function to calculate the average (excluding the lowest score)
    double average = calculateAverage(testScores, numScores);

    // Display the sorted list of test scores and the calculated average
    cout << "Sorted test scores:\n";
    for (int i = 0; i < numScores; ++i) {
        cout << testScores[i] << " ";
    }
    cout << "\nAverage (excluding the lowest score): " << fixed << setprecision(2) << average << endl;

    // Don't forget to free the allocated memory when done
    delete[] testScores;

    return 0;
}
