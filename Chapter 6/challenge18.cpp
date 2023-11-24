#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototypes
int getNumberOfRooms();
double getPriceOfPaint();
double getSquareFeet(int roomNumber);
double calculateGallonsOfPaint(double totalSquareFeet);
double calculateLaborHours(double totalSquareFeet);
double calculatePaintCost(double gallonsOfPaint, double priceOfPaint);
double calculateLaborCharges(double laborHours);
double calculateTotalCost(double paintCost, double laborCharges);

int main() {
    // Get user input
    int numberOfRooms = getNumberOfRooms();
    double priceOfPaint = getPriceOfPaint();

    // Initialize variables
    double totalSquareFeet = 0.0;
    double gallonsOfPaint, laborHours, paintCost, laborCharges, totalCost;

    // Get square footage for each room
    for (int roomNumber = 1; roomNumber <= numberOfRooms; ++roomNumber) {
        totalSquareFeet += getSquareFeet(roomNumber);
    }

    // Calculate required values
    gallonsOfPaint = calculateGallonsOfPaint(totalSquareFeet);
    laborHours = calculateLaborHours(totalSquareFeet);
    paintCost = calculatePaintCost(gallonsOfPaint, priceOfPaint);
    laborCharges = calculateLaborCharges(laborHours);
    totalCost = calculateTotalCost(paintCost, laborCharges);

    // Display results
    cout << fixed << setprecision(2);
    cout << "Number of gallons of paint required: " << gallonsOfPaint << endl;
    cout << "Hours of labor required: " << laborHours << endl;
    cout << "Cost of the paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCharges << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;

    return 0;
}

// Function to get the number of rooms
int getNumberOfRooms() {
    int rooms;
    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    // Validate input
    while (rooms < 1) {
        cout << "Invalid input. Number of rooms must be at least 1. Please enter again: ";
        cin >> rooms;
    }

    return rooms;
}

// Function to get the price of paint
double getPriceOfPaint() {
    double price;
    cout << "Enter the price of paint per gallon: $";
    cin >> price;

    // Validate input
    while (price < 10.00) {
        cout << "Invalid input. Price of paint must be at least $10.00. Please enter again: $";
        cin >> price;
    }

    return price;
}

// Function to get the square footage for a room
double getSquareFeet(int roomNumber) {
    double squareFeet;
    cout << "Enter the square footage of wall space for Room " << roomNumber << ": ";
    cin >> squareFeet;

    // Validate input
    while (squareFeet < 0) {
        cout << "Invalid input. Square footage must not be negative. Please enter again: ";
        cin >> squareFeet;
    }

    return squareFeet;
}

// Function to calculate gallons of paint required
double calculateGallonsOfPaint(double totalSquareFeet) {
    const double SQUARE_FEET_PER_GALLON = 110.0;
    return ceil(totalSquareFeet / SQUARE_FEET_PER_GALLON);
}

// Function to calculate labor hours required
double calculateLaborHours(double totalSquareFeet) {
    const double HOURS_PER_GALLON = 8.0;
    return ceil(totalSquareFeet / 110.0) * HOURS_PER_GALLON;
}

// Function to calculate the cost of paint
double calculatePaintCost(double gallonsOfPaint, double priceOfPaint) {
    return gallonsOfPaint * priceOfPaint;
}

// Function to calculate labor charges
double calculateLaborCharges(double laborHours) {
    const double LABOR_RATE = 25.00;
    return laborHours * LABOR_RATE;
}

// Function to calculate total cost of the paint job
double calculateTotalCost(double paintCost, double laborCharges) {
    return paintCost + laborCharges;
}
