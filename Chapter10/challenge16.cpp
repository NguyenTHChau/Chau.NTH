#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

string convertToPigLatin(const string& word) {
    // Check if the word is not empty
    if (word.empty()) {
        return word;
    }

    // Move the first letter to the end and append "ay"
    return word.substr(1) + static_cast<char>(tolower(word[0])) + "ay";
}

int main() {
    string sentence;

    // Read a sentence as input
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Use a string stream to extract words
    istringstream iss(sentence);
    string word;

    cout << "Pig Latin: ";

    // Process each word and convert to Pig Latin
    while (iss >> word) {
        cout << convertToPigLatin(word) << ' ';
    }

    cout << endl;

    return 0;
}
