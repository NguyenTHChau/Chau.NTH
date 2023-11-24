#include <iostream>
#include <algorithm>

using namespace std;

// Function to dynamically allocate an array for test scores
double* allocateScores(int numScores) {
    // Dynamically allocate an array of doubles
    return new double[numScores];
}

// Function to input test scores
void inputScores(double* scores, int numScores) {
    cout << "Enter test scores:\n";
    for (int i = 0; i < numScores; ++i) {
        do {
            cout << "Score " << i + 1 << ": ";
            cin >> scores[i];
        } while (scores[i] < 0); // Input validation: Do not accept negative numbers
    }
}

// Function to sort the array in ascending order
void sortScores(double* scores, int numScores) {
    sort(scores, scores + numScores);
}

// Function to calculate the average of test scores
double calculateAverage(double* scores, int numScores) {
    double sum = 0.0;
    for (int i = 0; i < numScores; ++i) {
        sum += scores[i];
    }
    return (numScores > 0) ? (sum / numScores) : 0.0;
}

int main() {
    int numScores;

    // Get the number of test scores from the user
    cout << "Enter the number of test scores: ";
    cin >> numScores;

    // Allocate the array for test scores
    double* testScores = allocateScores(numScores);

    // Input test scores
    inputScores(testScores, numScores);

    // Sort the test scores
    sortScores(testScores, numScores);

    // Calculate and display the average
    double average = calculateAverage(testScores, numScores);
    cout << "\nSorted Test Scores:\n";
    for (int i = 0; i < numScores; ++i) {
        cout << "Score " << i + 1 << ": " << testScores[i] << endl;
    }
    cout << "\nAverage Score: " << average << endl;

    // Free the allocated memory
    delete[] testScores;

    return 0;
}
