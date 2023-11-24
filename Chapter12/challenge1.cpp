#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Get the file name from the user
    cout << "Enter the name of the file: ";
    string fileName;
    getline(cin, fileName);

    // Open the file
    ifstream inputFile(fileName);

    // Check if the file is successfully opened
    if (!inputFile) {
        cerr << "Error: Unable to open the file.\n";
        return 1; // Exit the program with an error code
    }

    // Display the first 10 lines of the file
    string line;
    int lineCount = 0;

    while (getline(inputFile, line) && lineCount < 10) {
        cout << line << endl;
        lineCount++;
    }

    // Check if the entire file has been displayed
    if (lineCount < 10 && inputFile.eof()) {
        cout << "Entire file has been displayed.\n";
    }

    // Close the file
    inputFile.close();

    return 0;
}
