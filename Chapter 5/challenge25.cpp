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

    // Read names from the file until there is no more data
    string name;
    while (getline(inputFile, name)) {
        names.push_back(name);
    }

    // Close the file
    inputFile.close();

    // Display the names
    cout << "Names from the file:" << endl;
    for (const string& student : names) {
        cout << student << endl;
    }

    return 0;
}
