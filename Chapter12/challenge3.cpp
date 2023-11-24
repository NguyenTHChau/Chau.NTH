#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to read and display each line in the file (joke file)
void displayJoke(const string& filename) {
    ifstream jokeFile(filename);

    if (!jokeFile) {
        cerr << "Error: Unable to open the joke file.\n";
        return;
    }

    string line;
    while (getline(jokeFile, line)) {
        cout << line << endl;
    }

    jokeFile.close();
}

// Function to display only the last line of the file (punch line file)
void displayPunchLine(const string& filename) {
    ifstream punchLineFile(filename);

    if (!punchLineFile) {
        cerr << "Error: Unable to open the punch line file.\n";
        return;
    }

    // Seek to the end of the file
    punchLineFile.seekg(0, ios::end);

    // Back up to the beginning of the last line
    while (punchLineFile.tellg() > 0 && punchLineFile.get() != '\n') {
        punchLineFile.seekg(-2, ios::cur);
    }

    // Display the punch line
    string punchLine;
    getline(punchLineFile, punchLine);
    cout << punchLine << endl;

    punchLineFile.close();
}

int main() {
    // File names
    string jokeFileName = "joke.txt";
    string punchLineFileName = "punchline.txt";

    // Display the joke
    cout << "Joke:\n";
    displayJoke(jokeFileName);
    cout << "\n";

    // Display the punch line
    cout << "Punch Line:\n";
    displayPunchLine(punchLineFileName);

    return 0;
}
