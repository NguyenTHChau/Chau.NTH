#include <iostream>
#include <cstring>

using namespace std;

// Function to count the number of characters in a C-string
int countCharacters(const char* str) {
    return strlen(str);
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    cout << "Enter a string: ";
    cin.getline(input, MAX_LENGTH);

    // Call the function to count characters
    int charCount = countCharacters(input);

    // Display the function's return value
    cout << "Number of characters: " << charCount << endl;

    return 0;
}
