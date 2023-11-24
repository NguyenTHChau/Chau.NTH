#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits> // for numeric_limits
#include <ctime>

using namespace std;

struct InventoryRecord {
    string itemDescription;
    int quantityOnHand;
    double wholesaleCost;
    double retailCost;
    string dateAdded;
};

void addRecord(ofstream& outFile) {
    InventoryRecord record;

    cout << "Enter item description: ";
    cin.ignore(); // Clear input buffer
    getline(cin, record.itemDescription);

    do {
        cout << "Enter quantity on hand: ";
        cin >> record.quantityOnHand;

        if (record.quantityOnHand < 0) {
            cout << "Invalid input. Please enter a non-negative value.\n";
        }
    } while (record.quantityOnHand < 0);

    do {
        cout << "Enter wholesale cost: $";
        cin >> record.wholesaleCost;

        if (record.wholesaleCost < 0) {
            cout << "Invalid input. Please enter a non-negative value.\n";
        }
    } while (record.wholesaleCost < 0);

    do {
        cout << "Enter retail cost: $";
        cin >> record.retailCost;

        if (record.retailCost < 0) {
            cout << "Invalid input. Please enter a non-negative value.\n";
        }
    } while (record.retailCost < 0);

    cin.ignore(); // Clear input buffer
    cout << "Enter date added to inventory (MM/DD/YYYY): ";
    getline(cin, record.dateAdded);

    // Additional input validation for date format
    while (!isValidDateFormat(record.dateAdded)) {
        cout << "Invalid date format. Please enter the date in MM/DD/YYYY format: ";
        getline(cin, record.dateAdded);
    }

    outFile << record.itemDescription << " " << record.quantityOnHand << " " << fixed << setprecision(2)
            << record.wholesaleCost << " " << record.retailCost << " " << record.dateAdded << endl;

    cout << "Record added successfully.\n";
}

bool isValidDateFormat(const string& date) {
    // Validate date format (MM/DD/YYYY)
    tm timeStruct = {};
    istringstream ss(date);
    ss >> get_time(&timeStruct, "%m/%d/%Y");
    return !ss.fail();
}

void displayRecord(ifstream& inFile) {
    InventoryRecord record;

    cout << "Enter item description to display: ";
    string searchDescription;
    cin.ignore(); // Clear input buffer
    getline(cin, searchDescription);

    bool found = false;

    while (inFile >> record.itemDescription >> record.quantityOnHand >> record.wholesaleCost
            >> record.retailCost >> record.dateAdded) {
        if (record.itemDescription == searchDescription) {
            found = true;
            cout << "Item Description: " << record.itemDescription << endl;
            cout << "Quantity on Hand: " << record.quantityOnHand << endl;
            cout << "Wholesale Cost: $" << record.wholesaleCost << endl;
            cout << "Retail Cost: $" << record.retailCost << endl;
            cout << "Date Added to Inventory: " << record.dateAdded << endl;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}

void changeRecord(fstream& file) {
    InventoryRecord record;

    cout << "Enter item description to change: ";
    string searchDescription;
    cin.ignore(); // Clear input buffer
    getline(cin, searchDescription);

    bool found = false;
    streampos foundPos;

    while (file >> record.itemDescription >> record.quantityOnHand >> record.wholesaleCost
            >> record.retailCost >> record.dateAdded) {
        if (record.itemDescription == searchDescription) {
            found = true;
            foundPos = file.tellg(); // Save the position to overwrite the record later
            break;
        }
    }

    if (found) {
        // Prompt user for new data
        cout << "Enter new quantity on hand: ";
        cin >> record.quantityOnHand;

        do {
            cout << "Enter new wholesale cost: $";
            cin >> record.wholesaleCost;

            if (record.wholesaleCost < 0) {
                cout << "Invalid input. Please enter a non-negative value.\n";
            }
        } while (record.wholesaleCost < 0);

        do {
            cout << "Enter new retail cost: $";
            cin >> record.retailCost;

            if (record.retailCost < 0) {
                cout << "Invalid input. Please enter a non-negative value.\n";
            }
        } while (record.retailCost < 0);

        cin.ignore(); // Clear input buffer
        cout << "Enter new date added to inventory (MM/DD/YYYY): ";
        getline(cin, record.dateAdded);

        // Additional input validation for date format
        while (!isValidDateFormat(record.dateAdded)) {
            cout << "Invalid date format. Please enter the date in MM/DD/YYYY format: ";
            getline(cin, record.dateAdded);
        }

        // Move file pointer to the position of the record found and overwrite it
        file.seekp(foundPos);
        file << record.itemDescription << " " << record.quantityOnHand << " " << fixed << setprecision(2)
             << record.wholesaleCost << " " << record.retailCost << " " << record.dateAdded << endl;

        cout << "Record changed successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add new record\n";
        cout << "2. Display record\n";
        cout << "3. Change record\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                ofstream outFile("inventory.txt", ios::app); // Open file in append mode

                if (!outFile) {
                    cerr << "Error opening file for writing.\n";
                    return 1;
                }

                addRecord(outFile);
                outFile.close();
                break;
            }
            case 2: {
                ifstream inFile("inventory.txt");

                if (!inFile) {
                    cerr << "Error opening file for reading.\n";
                    return 1;
                }

                displayRecord(inFile);
                inFile.close();
                break;
            }
            case 3: {
                fstream file("inventory.txt", ios::in | ios::out);

                if (!file) {
                    cerr << "Error opening file for reading and writing.\n";
                    return 1;
                }

                changeRecord(file);
                file.close();
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
