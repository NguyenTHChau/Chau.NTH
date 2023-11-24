#include <iostream>
#include <algorithm> // for std::sort
#include <iomanip>   // for std::setprecision

// Function to dynamically allocate an array of strings (names)
std::string* allocateStringArray(int numElements) {
    return new std::string[numElements];
}

// Function to dynamically allocate an array of integers (scores)
int* allocateIntArray(int numElements) {
    return new int[numElements];
}

// Function to sort arrays of names and scores in ascending order
void sortArrays(std::string* names, int* scores, int size) {
    // Use std::sort with a custom comparison function to sort both arrays
    std::sort(names, names + size, [&scores](const std::string& a, const std::string& b) {
        return scores[&a - names] < scores[&b - names];
    });
}

// Function to calculate the average of an array
double calculateAverage(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    // Add the using namespace std; statement
    using namespace std;

    int numStudents;

    // Get the number of students from the user
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Call the function to allocate the arrays for names and scores
    string* studentNames = allocateStringArray(numStudents);
    int* testScores = allocateIntArray(numStudents);

    // Get name-score pairs from the user
    cout << "Enter name-score pairs:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << " name: ";
        cin >> studentNames[i];
        cout << "Student " << i + 1 << " score: ";
        cin >> testScores[i];
    }

    // Call the function to sort arrays of names and scores
    sortArrays(studentNames, testScores, numStudents);

    // Display the sorted list of names and scores
    cout << "Sorted list of names and scores:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentNames[i] << ": " << testScores[i] << endl;
    }

    // Calculate and display the average score
    double average = calculateAverage(testScores, numStudents);
    cout << "Average score: " << fixed << setprecision(2) << average << endl;

    // Don't forget to free the allocated memory when done
    delete[] studentNames;
    delete[] testScores;

    return 0;
}
