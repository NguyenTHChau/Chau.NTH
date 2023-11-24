#include <iostream>
#include <cstring>

using namespace std;

// Function to count the number of words in a C-string
int countWords(const char* str) {
    int wordCount = 0;
    bool inWord = false;

    // Iterate through each character in the string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Check if the current character is part of a word
        if (isalpha(str[i])) {
            if (!inWord) {
                // If entering a new word, increment the word count
                inWord = true;
                ++wordCount;
            }
        } else {
            // If the current character is not part of a word, set inWord to false
            inWord = false;
        }
    }

    return wordCount;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    cout << "Enter a string: ";
    cin.getline(input, MAX_LENGTH);

    // Call the function to count the number of words
    int result = countWords(input);

    // Display the result
    cout << "Number of words: " << result << endl;

    return 0;
}
