#include <iostream>

    using namespace std; 

// Function to dynamically allocate an array of integers
int* allocateIntArray(int numElements) {
    // Dynamically allocate an array of integers
    return new int[numElements];
}

// Main function
int main() {
 

    int numElements;

    // Get the number of elements from the user
    cout << "Enter the number of elements: ";
    cin >> numElements;

    // Call the function to allocate the array
    int* dynamicArray = allocateIntArray(numElements);

    // Use the dynamically allocated array as needed
    // ...

    // Don't forget to free the allocated memory when done
    delete[] dynamicArray;

    return 0;
}
