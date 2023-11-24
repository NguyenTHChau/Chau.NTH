#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // Open the file
    ifstream inputFile("text.txt");

    // Check if the file is successfully opened
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    char ch;
    int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0;

    // Read characters from the file
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            uppercaseCount++;
        } else if (islower(ch)) {
            lowercaseCount++;
        } else if (isdigit(ch)) {
            digitCount++;
        }
    }

    // Close the file
    inputFile.close();

    // Display the results
    cout << "Uppercase letters: " << uppercaseCount << endl;
    cout << "Lowercase letters: " << lowercaseCount << endl;
    cout << "Digits: " << digitCount << endl;

    return 0;
}
