#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string convertToWords(int dollars, int cents) {
    const string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string result;

    if (dollars >= 1000) {
        result += ones[dollars / 1000] + " Thousand ";
        dollars %= 1000;
    }

    if (dollars >= 100) {
        result += ones[dollars / 100] + " Hundred ";
        dollars %= 100;
    }

    if (dollars >= 20) {
        result += tens[dollars / 10] + " ";
        dollars %= 10;
    } else if (dollars >= 11 && dollars <= 19) {
        result += teens[dollars - 10] + " ";
        dollars = 0; // No ones place needed for teens
    }

    if (dollars > 0) {
        result += ones[dollars] + " ";
    }

    if (cents > 0) {
        result += "and " + to_string(cents) + " cents";
    }

    return result;
}

int main() {
    // Get user input
    cout << "Enter the date: ";
    string date;
    getline(cin, date);

    cout << "Enter the payee's name: ";
    string payee;
    getline(cin, payee);

    double amount;
    do {
        cout << "Enter the amount of the check (up to $10,000): $";
        cin >> amount;

        if (amount < 0 || amount > 10000) {
            cout << "Invalid amount. Please enter a valid amount.\n";
        }
    } while (amount < 0 || amount > 10000);

    // Extract dollars and cents
    int dollars = static_cast<int>(amount);
    int cents = static_cast<int>((amount - dollars) * 100 + 0.5);

    // Display simulated check
    cout << fixed << setprecision(2);
    cout << "\nDate: " << date << endl;
    cout << "Pay to the Order of: " << payee << " $" << amount << endl;
    cout << convertToWords(dollars, cents) << endl;

    return 0;
}
