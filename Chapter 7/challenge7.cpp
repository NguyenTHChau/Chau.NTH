#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

int main() {
    char fileName[100];
    double numbers[MAX_SIZE];
    int count = 0;
    double total = 0;
    double lowest, highest, average;

    // Ask the user for the file name
    cout << "Enter the file name: ";
    cin.getline(fileName, sizeof(fileName));

    // Open the file
    ifstream inputFile(fileName);

    // Check if the file is opened successfully
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    // Read numbers from the file into the array
    while (count < MAX_SIZE && inputFile >> numbers[count]) {
        total += numbers[count];
        count++;
    }

    // Close the file
    inputFile.close();

    // Check if any numbers were read
    if (count == 0) {
        cerr << "No numbers found in the file.\n";
        return 1;
    }

    // Calculate lowest, highest, and average
    lowest = highest = numbers[0];
    for (int i = 1; i < count; ++i) {
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    average = total / count;

    // Display the results
    cout << fixed << setprecision(2);
    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total: " << total << endl;
    cout << "Average: " << average << endl;

    return 0;
}
