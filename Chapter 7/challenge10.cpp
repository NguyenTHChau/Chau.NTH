#include <iostream>
#include <cctype> // For toupper function

using namespace std;

const int NUM_QUESTIONS = 20;
const char CORRECT_ANSWERS[NUM_QUESTIONS] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D',
                                             'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};

int main() {
    char studentAnswers[NUM_QUESTIONS];
    int correctCount = 0;
    int incorrectCount = 0;
    int incorrectQuestions[NUM_QUESTIONS];

    // Get student's answers
    cout << "Enter the student's answers for each of the 20 questions (A, B, C, or D):" << endl;
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        cout << "Question " << (i + 1) << ": ";
        cin >> studentAnswers[i];

        // Validate input
        while (toupper(studentAnswers[i]) != 'A' && toupper(studentAnswers[i]) != 'B' &&
               toupper(studentAnswers[i]) != 'C' && toupper(studentAnswers[i]) != 'D') {
            cout << "Invalid input. Please enter A, B, C, or D: ";
            cin >> studentAnswers[i];
        }

        // Check correctness
        if (toupper(studentAnswers[i]) == CORRECT_ANSWERS[i]) {
            correctCount++;
        } else {
            incorrectQuestions[incorrectCount] = i + 1; // Store the question number
            incorrectCount++;
        }
    }

    // Display results
    cout << "\nResults:" << endl;
    cout << "--------------------------------" << endl;
    cout << "Number of correct answers: " << correctCount << endl;
    cout << "Number of incorrect answers: " << incorrectCount << endl;

    if (correctCount >= 15) {
        cout << "The student passed the exam!" << endl;
    } else {
        cout << "The student failed the exam." << endl;
    }

    if (incorrectCount > 0) {
        cout << "\nIncorrectly answered questions:";
        for (int i = 0; i < incorrectCount; ++i) {
            cout << " " << incorrectQuestions[i];
        }
        cout << endl;
    }

    return 0;
}
