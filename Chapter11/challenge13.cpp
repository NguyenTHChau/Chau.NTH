#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define the structure for a soft drink
struct SoftDrink {
    string name;
    double cost;
    int quantity;
};

// Function prototypes
void displayMenu(const SoftDrink drinks[], int size);
double insertMoney();
void purchaseDrink(SoftDrink& drink, double amount);

int main() {
    const int NUM_DRINKS = 5;  // Number of different drinks in the machine

    // Initialize an array of SoftDrink structures
    SoftDrink drinks[NUM_DRINKS] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    double totalEarnings = 0.0;
    int choice;  // Move the declaration here

    do {
        // Display the menu
        displayMenu(drinks, NUM_DRINKS);

        // Get user choice
        cout << "Enter the number of the drink you want (1-" << NUM_DRINKS << ") or 0 to quit: ";
        cin >> choice;

        if (choice > 0 && choice <= NUM_DRINKS) {
            // Process the purchase
            double amountInserted = insertMoney();
            purchaseDrink(drinks[choice - 1], amountInserted);
            totalEarnings += drinks[choice - 1].cost;
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    cout << "Total earnings: $" << fixed << setprecision(2) << totalEarnings << endl;
    cout << "Exiting the soft drink machine program.\n";

    return 0;
}

// ... (rest of the code remains the same)
