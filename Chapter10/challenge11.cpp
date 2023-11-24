#include <iostream>
#include <cctype> // For toupper and tolower functions

using namespace std;

void upper(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = toupper(str[i]);
    }
}

void lower(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}

void reverse(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    char input[MAX_SIZE];

    // Get input from the user
    cout << "Enter a string: ";
    cin.getline(input, MAX_SIZE);

    // Display the original string
    cout << "Original string: " << input << endl;

    // Perform operations on the string
    reverse(input);
    cout << "After reversing: " << input << endl;

    lower(input);
    cout << "After converting to lowercase: " << input << endl;

    upper(input);
    cout << "After converting to uppercase: " << input << endl;

    return 0;
}
