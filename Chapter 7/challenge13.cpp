#include <iostream>
#include <string>
#include <algorithm> // for std::min_element

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 4;

// Function to calculate the average score (dropping the lowest score)
double calculateAverage(const double scores[]) {
    double sum = 0;
    
    // Find the minimum score using std::min_element
    double minScore = *min_element(scores, scores + NUM_TESTS);

    for (int i = 0; i < NUM_TESTS; ++i) {
        // Exclude the lowest score
        if (scores[i] != minScore) {
            sum += scores[i];
        }
    }
    
    // Divide by (NUM_TESTS - 1) to calculate the average without the lowest score
    return sum / (NUM_TESTS - 1);
}

// Function to get the letter grade based on the average score
char getLetterGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    string studentNames[NUM_STUDENTS];
    char letterGrades[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];

    // Input data
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Enter name for student " << i + 1 << ": ";
        cin >> studentNames[i];

        for (int j = 0; j < NUM_TESTS; ++j) {
            do {
                cout << "Enter test score " << j + 1 << " for " << studentNames[i] << ": ";
                cin >> testScores[i][j];

                // Input validation
                if (testScores[i][j] < 0 || testScores[i][j] > 100) {
                    cout << "Invalid input. Test scores must be between 0 and 100. Try again.\n";
                }
            } while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }

        // Calculate average (dropping the lowest score) and assign letter grade
        double average = calculateAverage(testScores[i]);
        letterGrades[i] = getLetterGrade(average);
    }

    // Display results
    cout << "\nResults:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student: " << studentNames[i] << "\tAverage Score: " << calculateAverage(testScores[i])
             << "\tLetter Grade: " << letterGrades[i] << endl;
    }

    return 0;
}
