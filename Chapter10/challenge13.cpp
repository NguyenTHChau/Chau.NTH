#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string formatDate(const string& inputDate) {
    stringstream ss(inputDate);
    int month, day, year;
    char delimiter;

    // Read month, day, and year from the input string
    ss >> month >> delimiter >> day >> delimiter >> year;

    // Array of month names
    const char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July",
                                "August", "September", "October", "November", "December"};

    // Validate the input
    if (ss.fail() || ss.peek() != EOF) {
        return "Invalid date format.";
    }

    // Validate month, day, and year values
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        return "Invalid date values.";
    }

    // Format the date
    stringstream formattedDate;
    formattedDate << monthNames[month - 1] << " " << day << ", " << year;

    return formattedDate.str();
}

int main() {
    string inputDate;

    // Get the date from the user
    cout << "Enter a date in the format mm/dd/yyyy: ";
    getline(cin, inputDate);

    // Format and print the date
    cout << "Formatted date: " << formatDate(inputDate) << endl;

    return 0;
}
