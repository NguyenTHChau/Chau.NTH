#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define the structure for a parts bin
struct PartsBin {
    string description;
    int numberOfParts;
};

// Function prototypes
void displayBins(const PartsBin bins[], int size);
void addParts(PartsBin& bin, int quantity);
void removeParts(PartsBin& bin, int quantity);

int main() {
    const int NUM_BINS = 10;

    // Initialize an array of PartsBin structures
    PartsBin bins[NUM_BINS] = {
        {"Valve", 10},
        {"Bearing", 5},
        {"Bushing", 15},
        {"Coupling", 21},
        {"Flange", 7},
        {"Gear", 5},
        {"Gear Housing", 5},
        {"Vacuum Gripper", 25},
        {"Cable", 18},
        {"Rod", 12}
    };

    int choice;
    int binChoice;

    do {
        // Display the current status of bins
        displayBins(bins, NUM_BINS);

        // Ask the user for the action
        cout << "Enter the number of the bin you want to update (1-" << NUM_BINS << ") or 0 to quit: ";
        cin >> binChoice;

        if (binChoice > 0 && binChoice <= NUM_BINS) {
            // Process the selected bin
            cout << "Enter 1 to add parts, 2 to remove parts, or 0 to go back: ";
            cin >> choice;

            if (choice == 1) {
                // Add parts to the bin
                int quantity;
                cout << "Enter the number of parts to add: ";
                cin >> quantity;
                addParts(bins[binChoice - 1], quantity);
            } else if (choice == 2) {
                // Remove parts from the bin
                int quantity;
                cout << "Enter the number of parts to remove: ";
                cin >> quantity;
                removeParts(bins[binChoice - 1], quantity);
            } else if (choice != 0) {
                cout << "Invalid choice. Please try again.\n";
            }
        } else if (binChoice != 0) {
            cout << "Invalid bin number. Please try again.\n";
        }

    } while (binChoice != 0);

    cout << "Exiting the inventory management program.\n";

    return 0;
}

void displayBins(const PartsBin bins[], int size) {
    cout << "Current Inventory:\n";
    cout << setw(5) << "Bin #" << setw(20) << "Description" << setw(20) << "Number of Parts\n";
    cout << string(50, '-') << endl;

    for (int i = 0; i < size; ++i) {
        cout << setw(5) << i + 1 << setw(20) << bins[i].description << setw(20) << bins[i].numberOfParts << endl;
    }
}

void addParts(PartsBin& bin, int quantity) {
    if (quantity > 0) {
        if (bin.numberOfParts + quantity <= 30) {
            bin.numberOfParts += quantity;
            cout << quantity << " parts added to " << bin.description << ".\n";
        } else {
            cout << "Error: Bin cannot hold more than 30 parts. Parts not added.\n";
        }
    } else {
        cout << "Error: Invalid quantity. Parts not added.\n";
    }
}

void removeParts(PartsBin& bin, int quantity) {
    if (quantity > 0) {
        if (bin.numberOfParts - quantity >= 0) {
            bin.numberOfParts -= quantity;
            cout << quantity << " parts removed from " << bin.description << ".\n";
        } else {
            cout << "Error: Insufficient parts in the bin. Parts not removed.\n";
        }
    } else {
        cout << "Error: Invalid quantity. Parts not removed.\n";
    }
}
