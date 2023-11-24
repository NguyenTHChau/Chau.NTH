#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct InventoryRecord {
    string itemDescription;
    int quantityOnHand;
    double wholesaleCost;
    double retailCost;
    string dateAdded;
};

bool isValidDateFormat(const string& date) {
    tm timeStruct = {};
    istringstream ss(date);
    ss >> get_time(&timeStruct, "%m/%d/%Y");
    return !ss.fail();
}

void calculateTotals(ifstream& inFile, double& totalWholesale, double& totalRetail, int& totalQuantity) {
    InventoryRecord record;
    totalWholesale = 0.0;
    totalRetail = 0.0;
    totalQuantity = 0;

    while (inFile >> record.itemDescription >> record.quantityOnHand >> record.wholesaleCost
            >> record.retailCost >> record.dateAdded) {
        totalWholesale += record.wholesaleCost * record.quantityOnHand;
        totalRetail += record.retailCost * record.quantityOnHand;
        totalQuantity += record.quantityOnHand;
    }
}

int main() {
    ifstream inFile("inventory.txt");

    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return 1;
    }

    double totalWholesale, totalRetail;
    int totalQuantity;

    calculateTotals(inFile, totalWholesale, totalRetail, totalQuantity);

    cout << "Total Wholesale Value: $" << fixed << setprecision(2) << totalWholesale << endl;
    cout << "Total Retail Value: $" << fixed << setprecision(2) << totalRetail << endl;
    cout << "Total Quantity: " << totalQuantity << " items\n";

    inFile.close();

    return 0;
}
