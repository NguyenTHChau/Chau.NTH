#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
double calculatePopulationSize(double previousPopulation, double birthRate, double deathRate);

int main() {
    double previousPopulation, birthRate, deathRate;
    int numYears;

    // Get user input
    cout << "Enter the starting size of the population: ";
    cin >> previousPopulation;

    // Validate input for starting size
    if (previousPopulation < 2) {
        cout << "Invalid input. Starting size must be at least 2." << endl;
        return 1;
    }

    cout << "Enter the annual birth rate (as a percentage): ";
    cin >> birthRate;

    // Validate input for birth rate
    if (birthRate < 0) {
        cout << "Invalid input. Birth rate cannot be negative." << endl;
        return 1;
    }

    cout << "Enter the annual death rate (as a percentage): ";
    cin >> deathRate;

    // Validate input for death rate
    if (deathRate < 0) {
        cout << "Invalid input. Death rate cannot be negative." << endl;
        return 1;
    }

    cout << "Enter the number of years to display: ";
    cin >> numYears;

    // Validate input for the number of years
    if (numYears < 1) {
        cout << "Invalid input. Number of years must be at least 1." << endl;
        return 1;
    }

    // Display header
    cout << setw(10) << "Year" << setw(20) << "Population Size" << endl;

    // Display population size for each year
    for (int year = 1; year <= numYears; ++year) {
        previousPopulation = calculatePopulationSize(previousPopulation, birthRate, deathRate);
        cout << setw(10) << year << setw(20) << fixed << setprecision(2) << previousPopulation << endl;
    }

    return 0;
}

// Function to calculate population size for a year
double calculatePopulationSize(double previousPopulation, double birthRate, double deathRate) {
    return previousPopulation + (previousPopulation * (birthRate / 100)) - (previousPopulation * (deathRate / 100));
}
