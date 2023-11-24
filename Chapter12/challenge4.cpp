#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to display the last 10 lines of the file
void displayTail(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Unable to open the file.\n";
        return;
    }

    vector<string> lines;
    string line;

    // Read all lines from the file
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    // Calculate the starting index based on the number of lines
    int startIndex = max(0, static_cast<int>(lines.size()) - 10);

    // Display the last 10 lines or the entire file
    for (int i = startIndex; i < lines.size(); ++i) {
        cout << lines[i] << endl;
    }
}

int main() {
    // Prompt the user for the file name
    cout << "Enter the name of the file: ";
    string fileName;
    cin >> fileName;

    // Display the last 10 lines of the file
    cout << "\nLast 10 lines of the file:\n";
    displayTail(fileName);

    return 0;
}
