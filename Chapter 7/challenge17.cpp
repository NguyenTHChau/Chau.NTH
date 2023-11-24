#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read names from a file into a vector
vector<string> readNamesFromFile(const string& filename) {
    vector<string> names;
    ifstream inputFile(filename);

    if (inputFile) {
        string name;
        while (getline(inputFile, name)) {
            names.push_back(name);
        }
        inputFile.close();
    } else {
        cerr << "Error opening " << filename << " file.\n";
    }

    return names;
}

// Function to check if a name is among the most popular
bool isNamePopular(const vector<string>& names, const string& inputName) {
    // Convert input name to uppercase for case-insensitive comparison
    string upperInputName = inputName;
    transform(upperInputName.begin(), upperInputName.end(), upperInputName.begin(), ::toupper);

    // Check if the name is in the vector
    return find(names.begin(), names.end(), upperInputName) != names.end();
}

int main() {
    // Read girl names from GirlNames.txt file
    vector<string> girlNames = readNamesFromFile("GirlNames.txt");

    // Read boy names from BoyNames.txt file
    vector<string> boyNames = readNamesFromFile("BoyNames.txt");

    // Prompt user for names
    cout << "Enter a girl's name: ";
    string girlInput;
    getline(cin, girlInput);

    cout << "Enter a boy's name: ";
    string boyInput;
    getline(cin, boyInput);

    // Check if names are among the most popular and display messages
    if (!girlInput.empty()) {
        if (isNamePopular(girlNames, girlInput)) {
            cout << girlInput << " is among the most popular girl names.\n";
        } else {
            cout << girlInput << " is not among the most popular girl names.\n";
        }
    }

    if (!boyInput.empty()) {
        if (isNamePopular(boyNames, boyInput)) {
            cout << boyInput << " is among the most popular boy names.\n";
        } else {
            cout << boyInput << " is not among the most popular boy names.\n";
        }
    }

    return 0;
}
