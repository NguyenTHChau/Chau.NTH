#include <iostream>
#include <fstream>

using namespace std;

const int NUM_QUESTIONS = 20;

void readAnswersFromFile(const char* filename, char answers[]) {
    ifstream file(filename);

    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        file >> answers[i];
    }

    file.close();
}

int main() {
    char correctAnswers[NUM_QUESTIONS];
    char studentAnswers[NUM_QUESTIONS];

    // Read correct answers from file
    readAnswersFromFile("CorrectAnswers.txt", correctAnswers);

    // Read student answers from file
    readAnswersFromFile("StudentAnswers.txt", studentAnswers);

    // Evaluate student's performance
    int questionsMissed = 0;
    int questionsCorrect = 0;

    cout << "Questions missed by the student:" << endl;
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (correctAnswers[i] != studentAnswers[i]) {
            cout << "Question " << (i + 1) << ": Correct Answer = " << correctAnswers[i]
                 << ", Student Answer = " << studentAnswers[i] << endl;
            questionsMissed++;
        } else {
            questionsCorrect++;
        }
    }

    // Display results
    cout << "\nTotal questions missed: " << questionsMissed << endl;
    cout << "Percentage of questions answered correctly: "
         << (static_cast<double>(questionsCorrect) / NUM_QUESTIONS) * 100 << "%" << endl;

    if (questionsCorrect >= 0.7 * NUM_QUESTIONS) {
        cout << "The student passed the exam." << endl;
    } else {
        cout << "The student failed the exam." << endl;
    }

    return 0;
}
