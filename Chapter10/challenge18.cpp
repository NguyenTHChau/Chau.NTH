#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array of string objects holding names and phone numbers
    string phoneBook[] = {
        "Alejandra Cruz, 555-1223",
        "Joe Looney, 555-0097",
        "Geri Palmer, 555-8787",
        "Li Chen, 555-1212",
        "Holly Gaddis, 555-8878",
        "Sam Wiggins, 555-0998",
        "Bob Kain, 555-8712",
        "Tim Haynes, 555-7676",
        "Warren Gaddis, 555-9037",
        "Jean James, 555-4939",
        "Ron Palmer, 555-2783"
    };

    // Get user input for the name or partial name to search for
    cout << "Enter a name or partial name to search for: ";
    string searchTerm;
    getline(cin, searchTerm);

    // Search for and display matching entries
    cout << "Matching entries:\n";
    for (const string& entry : phoneBook) {
        size_t found = entry.find(searchTerm);
        if (found != string::npos) {
            cout << entry << endl;
        }
    }

    return 0;
}
