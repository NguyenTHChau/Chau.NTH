#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getData(int& spoolsOrdered, int& spoolsInStock, bool& specialCharges, double& chargesPerSpool);
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, bool specialCharges, double chargesPerSpool = 10.00);

int main() {
    int spoolsOrdered, spoolsInStock;
    bool specialCharges;
    double chargesPerSpool;

    // Get order data from the user
    getData(spoolsOrdered, spoolsInStock, specialCharges, chargesPerSpool);

    // Display the order status
    displayOrderStatus(spoolsOrdered, spoolsInStock, specialCharges, chargesPerSpool);

    return 0;
}

// Function to get order data from the user
void getData(int& spoolsOrdered, int& spoolsInStock, bool& specialCharges, double& chargesPerSpool) {
    do {
        cout << "Enter the number of spools ordered: ";
        cin >> spoolsOrdered;

        if (spoolsOrdered < 1) {
            cout << "Invalid input. Please enter a number greater than or equal to 1." << endl;
        }
    } while (spoolsOrdered < 1);

    do {
        cout << "Enter the number of spools in stock: ";
        cin >> spoolsInStock;

        if (spoolsInStock < 0) {
            cout << "Invalid input. Please enter a non-negative number." << endl;
        }
    } while (spoolsInStock < 0);

    cout << "Are there special shipping and handling charges? (1 for Yes, 0 for No): ";
    cin >> specialCharges;

    if (specialCharges) {
        do {
            cout << "Enter the special charges per spool: $";
            cin >> chargesPerSpool;

            if (chargesPerSpool < 0) {
                cout << "Invalid input. Please enter a non-negative number." << endl;
            }
        } while (chargesPerSpool < 0);
    }
}

// Function to display the order status
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, bool specialCharges, double chargesPerSpool) {
    int spoolsReadyToShip = min(spoolsOrdered, spoolsInStock);
    int spoolsOnBackorder = max(0, spoolsOrdered - spoolsInStock);
    double subtotal = spoolsReadyToShip * 100.00;
    double totalShippingCharges = spoolsReadyToShip * chargesPerSpool;
    double totalOrder = subtotal + totalShippingCharges;

    cout << "\nOrder Status:\n";
    cout << "Spools ready to ship: " << spoolsReadyToShip << endl;
    cout << "Spools on backorder: " << spoolsOnBackorder << endl;
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Total shipping and handling charges: $" << totalShippingCharges << endl;
    cout << "Total order ready to ship: $" << totalOrder << endl;
}
