#include <iostream>

using namespace std;

// Function to create a new array that is one element larger than the argument array
int* copyAndEnlargeArray(const int* arr, int size) {
    // Create a new array with one more element
    int* enlargedArray = new int[size + 1];

    // Set the first element of the new array to 0
    enlargedArray[0] = 0;

    // Copy the elements from the argument array to the new array
    for (int i = 0; i < size; ++i) {
        enlargedArray[i + 1] = arr[i];
    }

    // Return a pointer to the new array
    return enlargedArray;
}

int main() {
    // Test the function
    const int size = 3;
    int originalArray[size] = {1, 2, 3};

    // Call the function to copy and enlarge the array
    int* enlargedArray = copyAndEnlargeArray(originalArray, size + 1);

    // Display the original and enlarged arrays
    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << originalArray[i] << " ";
    }

    cout << "\nEnlarged Array: ";
    for (int i = 0; i < size + 1; ++i) {
        cout << enlargedArray[i] << " ";
    }

    // Don't forget to free the dynamically allocated memory
    delete[] enlargedArray;

    return 0;
}
