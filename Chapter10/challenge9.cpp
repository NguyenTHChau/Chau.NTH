#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char mostFrequentChar(const char* cString) {
    int charCount[256] = {0};  // Assuming ASCII characters

    // Count the frequency of each character in the C-string
    for (int i = 0; i < strlen(cString); ++i) {
        charCount[static_cast<unsigned char>(cString[i])]++;
    }

    char mostFrequent = '\0';
    int maxCount = 0;

    // Find the character with the highest frequency
    for (int i = 0; i < 256; ++i) {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
            mostFrequent = static_cast<char>(i);
        }
    }

    return mostFrequent;
}

char mostFrequentChar(const string& str) {
    return mostFrequentChar(str.c_str());
}

int main() {
    // Test the function with a C-string
    const char* cString = "programming";
    cout << "Most frequent character in C-string: " << mostFrequentChar(cString) << endl;

    // Test the function with a string object
    string str = "cplusplus";
    cout << "Most frequent character in string object: " << mostFrequentChar(str) << endl;

    return 0;
}
