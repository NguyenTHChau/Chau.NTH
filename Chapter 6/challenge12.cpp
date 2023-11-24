#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getJudgeData(double &score);
void calcScore(double scores[]);
int findLowest(double scores[]);
int findHighest(double scores[]);

int main() {
    const int NUM_JUDGES = 5;
    double scores[NUM_JUDGES];

    // Get judge scores
    for (int i = 0; i < NUM_JUDGES; ++i) {
        cout << "Enter score for judge " << (i + 1) << ": ";
        getJudgeData(scores[i]);
    }

    // Calculate and display final score
    calcScore(scores);

    return 0;
}

// Function to get judge's score
void getJudgeData(double &score) {
    do {
        cout << "Enter a score between 0 and 10: ";
        cin >> score;

        if (score < 0 || score > 10) {
            cout << "Invalid score. Please enter a score between 0 and 10." << endl;
        }
    } while (score < 0 || score > 10);
}

// Function to calculate and display final score
void calcScore(double scores[]) {
    int lowestIndex = findLowest(scores);
    int highestIndex = findHighest(scores);

    double total = 0;

    // Calculate total excluding lowest and highest scores
    for (int i = 0; i < 5; ++i) {
        if (i != lowestIndex && i != highestIndex) {
            total += scores[i];
        }
    }

    // Calculate and display average
    double average = total / 3;
    cout << fixed << setprecision(2);
    cout << "Contestant's final score: " << average << endl;
}

// Function to find the index of the lowest score
int findLowest(double scores[]) {
    int lowestIndex = 0;

    for (int i = 1; i < 5; ++i) {
        if (scores[i] < scores[lowestIndex]) {
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

// Function to find the index of the highest score
int findHighest(double scores[]) {
    int highestIndex = 0;

    for (int i = 1; i < 5; ++i) {
        if (scores[i] > scores[highestIndex]) {
            highestIndex = i;
        }
    }

    return highestIndex;
}
