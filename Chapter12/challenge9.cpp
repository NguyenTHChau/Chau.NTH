#include <iostream>
#include <fstream>

using namespace std;

void encryptFile(const char* inputFile, const char* outputFile) {
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile || !outFile) {
        cerr << "Error: Unable to open files.\n";
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // Encrypt the character by adding 10 to its ASCII code
        ch += 10;
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    cout << "File encrypted successfully.\n";
}

int main() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "encrypted_output.txt";

    // Call the function to encrypt the file
    encryptFile(inputFileName, outputFileName);

    return 0;
}
