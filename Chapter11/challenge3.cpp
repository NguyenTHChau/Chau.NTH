#include <iostream>
#include <string>

using namespace std;

// Define the structure for company division
struct DivisionData {
    string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to input sales data for a division
void inputSalesData(DivisionData& division) {
    cout << "Enter sales data for " << division.divisionName << " division:\n";
    cout << "First Quarter Sales: ";
    cin >> division.firstQuarterSales;

    // Input validation
    while (division.firstQuarterSales < 0) {
        cout << "Sales figures cannot be negative. Enter again: ";
        cin >> division.firstQuarterSales;
    }

    cout << "Second Quarter Sales: ";
    cin >> division.secondQuarterSales;

    while (division.secondQuarterSales < 0) {
        cout << "Sales figures cannot be negative. Enter again: ";
        cin >> division.secondQuarterSales;
    }

    cout << "Third Quarter Sales: ";
    cin >> division.thirdQuarterSales;

    while (division.thirdQuarterSales < 0) {
        cout << "Sales figures cannot be negative. Enter again: ";
        cin >> division.thirdQuarterSales;
    }

    cout << "Fourth Quarter Sales: ";
    cin >> division.fourthQuarterSales;

    while (division.fourthQuarterSales < 0) {
        cout << "Sales figures cannot be negative. Enter again: ";
        cin >> division.fourthQuarterSales;
    }
}

// Function to calculate total and average sales for a division
void calculateSales(DivisionData& division) {
    division.totalAnnualSales = division.firstQuarterSales + division.secondQuarterSales +
                               division.thirdQuarterSales + division.fourthQuarterSales;

    division.averageQuarterlySales = division.totalAnnualSales / 4.0;
}

// Function to display sales data for a division
void displaySalesData(const DivisionData& division) {
    cout << "\nSales data for " << division.divisionName << " division:\n";
    cout << "Total Annual Sales: $" << division.totalAnnualSales << endl;
    cout << "Average Quarterly Sales: $" << division.averageQuarterlySales << endl;
    cout << "-----------------------------------------\n";
}

int main() {
    // Create variables for each division
    DivisionData eastDivision = {"East"};
    DivisionData westDivision = {"West"};
    DivisionData northDivision = {"North"};
    DivisionData southDivision = {"South"};

    // Input and calculate sales data for each division
    inputSalesData(eastDivision);
    calculateSales(eastDivision);

    inputSalesData(westDivision);
    calculateSales(westDivision);

    inputSalesData(northDivision);
    calculateSales(northDivision);

    inputSalesData(southDivision);
    calculateSales(southDivision);

    // Display sales data for each division
    displaySalesData(eastDivision);
    displaySalesData(westDivision);
    displaySalesData(northDivision);
    displaySalesData(southDivision);

    return 0;
}
