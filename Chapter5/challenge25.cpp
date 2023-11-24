#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Open the file
    ifstream inputFile("LineUp.txt");

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1; // Exit with an error code
    }

    // Vector to store names
    vector<string> names;

    // Read names from the file
    string name;
    while (getline(inputFile, name)) {
        names.push_back(name);
    }

    // Close the file
    inputFile.close();

    // Display the names in reverse order
    cout << "Names in reverse order:" << endl;
    for (int i = names.size() - 1; i >= 0; --i) {
        cout << names[i] << endl;
    }

    return 0;
}
