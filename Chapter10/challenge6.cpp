#include <iostream>
#include <cctype>

using namespace std;

// Function to count the number of vowels in a C-string
int countVowels(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ++count;
        }
    }
    return count;
}

// Function to count the number of consonants in a C-string
int countConsonants(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char ch = tolower(str[i]);
        if (isalpha(ch) && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            ++count;
        }
    }
    return count;
}

int main() {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    // Main program loop
    while (true) {
        // Display menu
        cout << "\nMenu:\n"
             << "A) Count the number of vowels in the string\n"
             << "B) Count the number of consonants in the string\n"
             << "C) Count both the vowels and consonants in the string\n"
             << "D) Enter another string\n"
             << "E) Exit the program\n";

        // Get user choice
        char choice;
        cout << "Enter your choice (A/B/C/D/E): ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        // Perform the chosen operation
        switch (choice) {
            case 'A':
                cout << "Number of vowels: " << countVowels(input) << endl;
                break;
            case 'B':
                cout << "Number of consonants: " << countConsonants(input) << endl;
                break;
            case 'C':
                cout << "Number of vowels: " << countVowels(input) << endl;
                cout << "Number of consonants: " << countConsonants(input) << endl;
                break;
            case 'D':
                cout << "Enter a string: ";
                cin.getline(input, MAX_LENGTH);
                break;
            case 'E':
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter A, B, C, D, or E.\n";
        }
    }

    return 0;
}
