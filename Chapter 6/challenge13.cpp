#include <iostream>

using namespace std;

// Function prototypes
int getNumberOfEmployees();
int getTotalDaysAbsent(int numEmployees);
double calculateAverageDaysAbsent(int numEmployees, int totalDaysAbsent);

int main() {
    int numEmployees, totalDaysAbsent;
    double averageDaysAbsent;

    // Get the number of employees
    numEmployees = getNumberOfEmployees();

    // Get the total days absent for all employees
    totalDaysAbsent = getTotalDaysAbsent(numEmployees);

    // Calculate and display the average days absent
    averageDaysAbsent = calculateAverageDaysAbsent(numEmployees, totalDaysAbsent);
    cout << "Average number of days absent: " << averageDaysAbsent << endl;

    return 0;
}

// Function to get the number of employees
int getNumberOfEmployees() {
    int numEmployees;

    do {
        cout << "Enter the number of employees in the company: ";
        cin >> numEmployees;

        if (numEmployees < 1) {
            cout << "Invalid input. Please enter a number greater than or equal to 1." << endl;
        }
    } while (numEmployees < 1);

    return numEmployees;
}

// Function to get the total days absent for all employees
int getTotalDaysAbsent(int numEmployees) {
    int totalDaysAbsent = 0;

    for (int i = 1; i <= numEmployees; ++i) {
        int daysAbsent;
        do {
            cout << "Enter the number of days employee " << i << " missed during the past year: ";
            cin >> daysAbsent;

            if (daysAbsent < 0) {
                cout << "Invalid input. Please enter a non-negative number." << endl;
            }
        } while (daysAbsent < 0);

        totalDaysAbsent += daysAbsent;
    }

    return totalDaysAbsent;
}

// Function to calculate the average days absent
double calculateAverageDaysAbsent(int numEmployees, int totalDaysAbsent) {
    return static_cast<double>(totalDaysAbsent) / numEmployees;
}
