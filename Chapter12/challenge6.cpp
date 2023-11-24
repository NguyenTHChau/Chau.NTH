#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to search for and display occurrences of a string in a file
void searchAndDisplay(const string& filename, const string& searchStr) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Unable to open the file.\n";
        return;
    }

    string line;
    int occurrences = 0;

    // Read and search each line in the file
    while (getline(file, line)) {
        size_t found = line.find(searchStr);
        if (found != string::npos) {
            // Display the line containing the search string
            cout << line << endl;
            occurrences++;
        }
    }

    file.close();

    // Display the total number of occurrences
    cout << "\nTotal occurrences of \"" << searchStr << "\": " << occurrences << endl;
}

int main() {
    // Prompt the user for the file name and search string
    cout << "Enter the name of the file: ";
    string fileName;
    cin >> fileName;

    cout << "Enter the string to search for: ";
    string searchStr;
    cin >> searchStr;

    // Search for and display occurrences in the file
    cout << "\nLines containing \"" << searchStr << "\":\n";
    searchAndDisplay(fileName, searchStr);

    return 0;
}
