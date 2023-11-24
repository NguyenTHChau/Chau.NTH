#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system("pause")

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

    // Display the file contents 24 lines at a time
    const int LINES_PER_PAGE = 24;
    string line;
    int lineCount = 0;

    while (getline(inputFile, line)) {
        cout << line << endl;
        lineCount++;

        if (lineCount == LINES_PER_PAGE) {
            cout << "Press Enter to continue...";
            cin.ignore(); // Wait for the user to press Enter
            lineCount = 0; // Reset line count for the next page
            system("clear"); // Clear the screen (for Unix/Linux)
            // system("cls"); // Uncomment this line for Windows
        }
    }

    // Close the file
    inputFile.close();

    return 0;
}
