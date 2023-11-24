#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inFile("text.txt");

    if (!inFile) {
        cerr << "Error opening file 'text.txt' for reading.\n";
        return 1;
    }

    vector<string> sentences;
    string line;

    // Read each line from the file
    while (getline(inFile, line)) {
        sentences.push_back(line);
    }

    inFile.close();

    // Calculate the average number of words per sentence
    int totalWords = 0;
    for (const string& sentence : sentences) {
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            totalWords++;
        }
    }

    double averageWordsPerSentence = static_cast<double>(totalWords) / sentences.size();

    cout << "Average number of words per sentence: " << averageWordsPerSentence << endl;

    return 0;
}
