#include <iostream>

using namespace std;

// Function prototypes
double getLength();
double getWidth();
double getArea(double length, double width);
void displayData(double length, double width, double area);

int main() {
    // Get user input
    double length = getLength();
    double width = getWidth();

    // Calculate the area
    double area = getArea(length, width);

    // Display the rectangle's information
    displayData(length, width, area);

    return 0;
}

// Function to get rectangle's length
double getLength() {
    double length;
    cout << "Enter the rectangle's length: ";
    cin >> length;
    return length;
}

// Function to get rectangle's width
double getWidth() {
    double width;
    cout << "Enter the rectangle's width: ";
    cin >> width;
    return width;
}

// Function to calculate rectangle's area
double getArea(double length, double width) {
    return length * width;
}

// Function to display rectangle's information
void displayData(double length, double width, double area) {
    cout << "Rectangle Information:\n";
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area: " << area << endl;
}
