#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

// Function to process and capitalize sentences
void processSentences(ifstream& inputFile, ofstream& outputFile) {
    char ch;
    bool newSentence = true;

    while (inputFile.get(ch)) {
        // If it's the beginning of a new sentence, capitalize the first letter
        if (newSentence && isalpha(ch)) {
            ch = toupper(ch);
            newSentence = false;
        }

        // If it's a period, mark the start of a new sentence
        if (ch == '.') {
            newSentence = true;
        }

        // Convert the rest of the letters to lowercase
        if (isalpha(ch)) {
            ch = tolower(ch);
        }

        // Write the character to the output file
        outputFile.put(ch);
    }
}

int main() {
    // Prompt the user for input and output file names
    string inputFileName, outputFileName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    // Open the input and output files
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) {
        cerr << "Error: Unable to open files.\n";
        return 1;
    }

    // Process and capitalize sentences
    processSentences(inputFile, outputFile);

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Sentences processed and written to the output file.\n";

    return 0;
}
