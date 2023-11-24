#include <iostream>
#include <iomanip>

const int ROWS = 3;
const int COLS = 4;

// Function prototypes
int getTotal(int arr[][COLS]);
double getAverage(int arr[][COLS]);
int getRowTotal(int arr[][COLS], int row);
int getColumnTotal(int arr[][COLS], int col);
int getHighestInRow(int arr[][COLS], int row);
int getLowestInRow(int arr[][COLS], int row);

int main() {
    int testArray[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Display total of all values in the array
    std::cout << "Total of all values: " << getTotal(testArray) << std::endl;

    // Display average of all values in the array
    std::cout << "Average of all values: " << getAverage(testArray) << std::endl;

    // Display total of values in the first row
    std::cout << "Total of values in row 1: " << getRowTotal(testArray, 0) << std::endl;

    // Display total of values in the second column
    std::cout << "Total of values in column 2: " << getColumnTotal(testArray, 1) << std::endl;

    // Display highest value in the second row
    std::cout << "Highest value in row 2: " << getHighestInRow(testArray, 1) << std::endl;

    // Display lowest value in the third row
    std::cout << "Lowest value in row 3: " << getLowestInRow(testArray, 2) << std::endl;

    return 0;
}

// Function definitions
int getTotal(int arr[][COLS]) {
    int total = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            total += arr[i][j];
        }
    }
    return total;
}

double getAverage(int arr[][COLS]) {
    return static_cast<double>(getTotal(arr)) / (ROWS * COLS);
}

int getRowTotal(int arr[][COLS], int row) {
    int total = 0;
    for (int i = 0; i < COLS; ++i) {
        total += arr[row][i];
    }
    return total;
}

int getColumnTotal(int arr[][COLS], int col) {
    int total = 0;
    for (int i = 0; i < ROWS; ++i) {
        total += arr[i][col];
    }
    return total;
}

int getHighestInRow(int arr[][COLS], int row) {
    int highest = arr[row][0];
    for (int i = 1; i < COLS; ++i) {
        if (arr[row][i] > highest) {
            highest = arr[row][i];
        }
    }
    return highest;
}

int getLowestInRow(int arr[][COLS], int row) {
    int lowest = arr[row][0];
    for (int i = 1; i < COLS; ++i) {
        if (arr[row][i] < lowest) {
            lowest = arr[row][i];
        }
    }
    return lowest;
}
