#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function prototype
double presentValue(double futureValue, double annualInterestRate, int years);

int main() {
    // Get user input for future value, annual interest rate, and number of years
    double futureValue, annualInterestRate;
    int years;

    cout << "Enter the future value you want in the account: $";
    cin >> futureValue;

    cout << "Enter the annual interest rate (as a decimal): ";
    cin >> annualInterestRate;

    cout << "Enter the number of years the money will sit in the account: ";
    cin >> years;

    // Calculate and display the present value
    double presentVal = presentValue(futureValue, annualInterestRate, years);

    cout << fixed << setprecision(2);
    cout << "You need to deposit: $" << presentVal << " today." << endl;

    return 0;
}

// Function to calculate present value
double presentValue(double futureValue, double annualInterestRate, int years) {
    // Formula: P = F / (1 + r)^n
    double presentVal = futureValue / pow(1 + annualInterestRate, years);
    return presentVal;
}
