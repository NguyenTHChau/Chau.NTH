#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_SIZE = 100;

    char inputString[MAX_SIZE];

    // Get user input
    cout << "Enter a series of single-digit numbers: ";
    cin.getline(inputString, MAX_SIZE);

    // Initialize variables for sum, highest, and lowest digits
    int sum = 0;
    char highestDigit = '0';
    char lowestDigit = '9';

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(inputString); ++i) {
        if (isdigit(inputString[i])) {
            // Convert the character to an integer
            int digit = inputString[i] - '0';

            // Update sum
            sum += digit;

            // Update highest and lowest digits
            if (inputString[i] > highestDigit) {
                highestDigit = inputString[i];
            }
            if (inputString[i] < lowestDigit) {
                lowestDigit = inputString[i];
            }
        }
    }

    // Display results
    cout << "Sum of single-digit numbers: " << sum << endl;
    cout << "Highest digit: " << highestDigit << endl;
    cout << "Lowest digit: " << lowestDigit << endl;

    return 0;
}
