#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Function to capitalize the first character of each sentence in a C-string
void capitalizeSentences(char* str) {
    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Check if the current character is the first in a sentence
        if (i == 0 || (i > 0 && (str[i - 1] == '.' || str[i - 1] == '!' || str[i - 1] == '?'))) {
            // Capitalize the current character
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    cout << "Enter a string: ";
    cin.getline(input, MAX_LENGTH);

    // Call the function to capitalize the first character of each sentence
    capitalizeSentences(input);

    // Display the modified string
    cout << "Modified string: " << input << endl;

    return 0;
}
