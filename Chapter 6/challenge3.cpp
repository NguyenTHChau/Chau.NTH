#include <iostream>
#include <string>

using namespace std;

// Function prototypes
double getSales(const string& divisionName);
void findHighest(double northeast, double southeast, double northwest, double southwest);

int main() {
    // Get sales for each division
    double northeastSales = getSales("Northeast");
    double southeastSales = getSales("Southeast");
    double northwestSales = getSales("Northwest");
    double southwestSales = getSales("Southwest");

    // Find and display the highest sales division
    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}

// Function to get sales for a division
double getSales(const string& divisionName) {
    double sales;
    do {
        cout << "Enter " << divisionName << "'s quarterly sales: $";
        cin >> sales;

        // Validate input
        if (sales < 0.0) {
            cout << "Sales cannot be less than $0.00. Please enter a valid amount." << endl;
        }
    } while (sales < 0.0);

    return sales;
}

// Function to find and display the highest sales division
void findHighest(double northeast, double southeast, double northwest, double southwest) {
    double highestSales = northeast;
    string highestDivision = "Northeast";

    if (southeast > highestSales) {
        highestSales = southeast;
        highestDivision = "Southeast";
    }
    if (northwest > highestSales) {
        highestSales = northwest;
        highestDivision = "Northwest";
    }
    if (southwest > highestSales) {
        highestSales = southwest;
        highestDivision = "Southwest";
    }

    cout << "The division with the highest sales is " << highestDivision << " with $" << highestSales << " in sales." << endl;
}
