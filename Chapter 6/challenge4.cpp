#include <iostream>
#include <string>

using namespace std;

// Function prototypes
int getNumAccidents(const string& regionName);
void findLowest(int north, int south, int east, int west, int central);

int main() {
    // Get the number of accidents for each region
    int accidentsNorth = getNumAccidents("North");
    int accidentsSouth = getNumAccidents("South");
    int accidentsEast = getNumAccidents("East");
    int accidentsWest = getNumAccidents("West");
    int accidentsCentral = getNumAccidents("Central");

    // Find and display the region with the fewest accidents
    findLowest(accidentsNorth, accidentsSouth, accidentsEast, accidentsWest, accidentsCentral);

    return 0;
}

// Function to get the number of accidents for a region
int getNumAccidents(const string& regionName) {
    int accidents;
    do {
        cout << "Enter the number of automobile accidents reported in " << regionName << " region last year: ";
        cin >> accidents;

        // Validate input
        if (accidents < 0) {
            cout << "Number of accidents cannot be less than 0. Please enter a valid number." << endl;
        }
    } while (accidents < 0);

    return accidents;
}

// Function to find and display the region with the fewest accidents
void findLowest(int north, int south, int east, int west, int central) {
    int lowestAccidents = north;
    string lowestRegion = "North";

    if (south < lowestAccidents) {
        lowestAccidents = south;
        lowestRegion = "South";
    }
    if (east < lowestAccidents) {
        lowestAccidents = east;
        lowestRegion = "East";
    }
    if (west < lowestAccidents) {
        lowestAccidents = west;
        lowestRegion = "West";
    }
    if (central < lowestAccidents) {
        lowestAccidents = central;
        lowestRegion = "Central";
    }

    cout << "The region with the fewest accidents is " << lowestRegion << " with " << lowestAccidents << " reported accidents." << endl;
}
