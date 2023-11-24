#include <iostream>
#include <string>

using namespace std;

// Define the structure for customer account data
struct CustomerAccount {
    string name;
    string address;
    string cityStateZIP;
    string telephoneNumber;
    double accountBalance;
    string lastPaymentDate;
};

// Function prototypes
void displayMenu();
void inputData(CustomerAccount& account);
void displayData(const CustomerAccount& account);
void modifyData(CustomerAccount& account);

int main() {
    const int maxSize = 10;
    CustomerAccount accounts[maxSize];

    int choice;
    int accountIndex = 0;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (accountIndex < maxSize) {
                    inputData(accounts[accountIndex]);
                    accountIndex++;
                } else {
                    cout << "Error: Maximum number of accounts reached.\n";
                }
                break;
            case 2:
                for (int i = 0; i < accountIndex; ++i) {
                    displayData(accounts[i]);
                }
                break;
            case 3:
                if (accountIndex > 0) {
                    int accountNumber;
                    cout << "Enter the account number to modify (1-" << accountIndex << "): ";
                    cin >> accountNumber;
                    if (accountNumber >= 1 && accountNumber <= accountIndex) {
                        modifyData(accounts[accountNumber - 1]);
                    } else {
                        cout << "Invalid account number.\n";
                    }
                } else {
                    cout << "No accounts to modify.\n";
                }
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enter new customer account\n";
    cout << "2. Display all customer accounts\n";
    cout << "3. Modify customer account\n";
    cout << "4. Exit\n";
}

void inputData(CustomerAccount& account) {
    cout << "Enter customer data:\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin, account.name);

    cout << "Address: ";
    getline(cin, account.address);

    cout << "City, State, and ZIP: ";
    getline(cin, account.cityStateZIP);

    cout << "Telephone Number: ";
    getline(cin, account.telephoneNumber);

    cout << "Account Balance: $";
    cin >> account.accountBalance;

    // Input validation for non-negative account balance
    while (account.accountBalance < 0) {
        cout << "Account balance cannot be negative. Enter again: $";
        cin >> account.accountBalance;
    }

    cout << "Date of Last Payment: ";
    cin.ignore();
    getline(cin, account.lastPaymentDate);
}

void displayData(const CustomerAccount& account) {
    cout << "\nCustomer Data:\n";
    cout << "Name: " << account.name << endl;
    cout << "Address: " << account.address << endl;
    cout << "City, State, and ZIP: " << account.cityStateZIP << endl;
    cout << "Telephone Number: " << account.telephoneNumber << endl;
    cout << "Account Balance: $" << account.accountBalance << endl;
    cout << "Date of Last Payment: " << account.lastPaymentDate << endl;
}

void modifyData(CustomerAccount& account) {
    cout << "Enter modified customer data:\n";
    inputData(account);
}

