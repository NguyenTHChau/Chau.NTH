#include <iostream>

using namespace std;

// Function to create a new array that is twice the size of the argument array
int* doubleSizeArray(const int* arr, int size) {
    // Create a new array with twice the size
    int* doubledArray = new int[2 * size];

    // Copy the contents of the argument array to the new array
    for (int i = 0; i < size; ++i) {
        doubledArray[i] = arr[i];
    }

    // Initialize the unused elements with 0
    for (int i = size; i < 2 * size; ++i) {
        doubledArray[i] = 0;
    }

    // Return a pointer to the new array
    return doubledArray;
}

int main() {
    // Test the function
    const int size = 3;
    int originalArray[size] = {1, 2, 3};

    // Call the function to double the size of the array
    int* doubledArray = doubleSizeArray(originalArray, size);

    // Display the original and doubled arrays
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << originalArray[i] << " ";
    }

    cout << "\nDoubled Array: ";
    for (int i = 0; i < 2 * size; ++i) {
        cout << doubledArray[i] << " ";
    }

    // Don't forget to free the dynamically allocated memory
    delete[] doubledArray;

    return 0;
}
