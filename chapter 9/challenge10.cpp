#include <iostream>

using namespace std;

// Function to reverse the elements of an array
int* reverseArray(const int* arr, int size) {
    // Create a new array with the same size
    int* reversedArray = new int[size];

    // Copy and reverse the elements
    for (int i = 0; i < size; ++i) {
        reversedArray[i] = arr[size - 1 - i];
    }

    // Return a pointer to the reversed array
    return reversedArray;
}

int main() {
    // Test the function
    const int size = 5;
    int originalArray[size] = {1, 2, 3, 4, 5};

    // Call the function to reverse the array
    int* reversedArray = reverseArray(originalArray, size);

    // Display the original and reversed arrays
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << originalArray[i] << " ";
    }

    cout << "\nReversed Array: ";
    for (int i = 0; i < size; ++i) {
        cout << reversedArray[i] << " ";
    }

    // Don't forget to free the dynamically allocated memory
    delete[] reversedArray;

    return 0;
}
