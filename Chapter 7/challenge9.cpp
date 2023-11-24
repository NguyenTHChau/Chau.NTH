#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 7;

    // Arrays
    long empId[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[SIZE];
    double payRate[SIZE];
    double wages[SIZE];

    // Input data
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter hours worked by employee " << empId[i] << ": ";
        cin >> hours[i];

        while (hours[i] < 0) {
            cout << "Please enter a non-negative value for hours: ";
            cin >> hours[i];
        }

        cout << "Enter hourly pay rate for employee " << empId[i] << ": ";
        cin >> payRate[i];

        while (payRate[i] < 15.00) {
            cout << "Please enter a pay rate greater than or equal to 15.00: ";
            cin >> payRate[i];
        }

        wages[i] = hours[i] * payRate[i];
    }

    // Display results
    cout << "\nEmployee ID\tGross Wages" << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < SIZE; ++i) {
        cout << empId[i] << "\t\t$" << fixed << setprecision(2) << wages[i] << endl;
    }

    return 0;
}
