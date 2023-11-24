#include <iostream>
#include <fstream>

using namespace std;

// Function to write an array to a file
void arrayToFile(const char* fileName, const int* arr, int size) {
    ofstream outFile(fileName, ios::binary);

    if (!outFile) {
        cerr << "Error: Unable to open file for writing.\n";
        return;
    }

    outFile.write(reinterpret_cast<const char*>(arr), size * sizeof(int));
    outFile.close();
}

// Function to read data from a file into an array
void fileToArray(const char* fileName, int* arr, int size) {
    ifstream inFile(fileName, ios::binary);

    if (!inFile) {
        cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));
    inFile.close();
}

int main() {
    const char* fileName = "data.bin";
    const int arrSize = 5;
    int originalArray[arrSize] = {1, 2, 3, 4, 5};
    int newArray[arrSize] = {0}; // Initialize to zeros

    // Write the array to the file
    arrayToFile(fileName, originalArray, arrSize);

    // Read the data from the file into a new array
    fileToArray(fileName, newArray, arrSize);

    // Display the contents of the new array
    cout << "Contents of the array after reading from file:\n";
    for (int i = 0; i < arrSize; ++i) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    return 0;
}
