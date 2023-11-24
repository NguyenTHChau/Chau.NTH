#include <iostream>
#include <cstring>

using namespace std;

// Function to display the contents of a C-string backward
void displayBackward(const char* str) {
    int length = strlen(str);

    // Display the string backward
    for (int i = length - 1; i >= 0; --i) {
        cout << str[i];
    }

    cout << endl;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    // Ask the user to input a string
    cout << "Enter a string: ";
    cin.getline(input, MAX_LENGTH);

    // Call the function to display the string backward
    cout << "Backward: ";
    displayBackward(input);

    return 0;
}
