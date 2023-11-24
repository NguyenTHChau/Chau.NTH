#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_TESTS = 5;

// Define the structure for student data
struct Student {
    string name;
    int idnum;
    int* tests;
    double average;
    char grade;
};

// Function prototypes
void inputStudentData(Student& student);
void calculateAverage(Student& student);
void calculateGrade(Student& student);
void displayStudentData(const Student& student);

int main() {
    int numStudents, numTests;

    // Get the number of students and tests from the user
    cout << "Enter the number of students: ";
    cin >> numStudents;

    cout << "Enter the number of tests: ";
    cin >> numTests;

    // Dynamically allocate an array of Student structures
    Student* students = new Student[numStudents];

    // Process each student
    for (int i = 0; i < numStudents; ++i) {
        // Dynamically allocate an array of test scores for each student
        students[i].tests = new int[numTests];

        // Input student data
        inputStudentData(students[i]);

        // Calculate average test score and course grade
        calculateAverage(students[i]);
        calculateGrade(students[i]);
    }

    // Display the table header
    cout << setw(15) << "Name" << setw(15) << "ID Number" << setw(15) << "Average" << setw(15) << "Grade\n";
    cout << string(60, '-') << endl;

    // Display student data
    for (int i = 0; i < numStudents; ++i) {
        displayStudentData(students[i]);
    }

    // Deallocate dynamically allocated memory
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].tests;
    }
    delete[] students;

    return 0;
}

void inputStudentData(Student& student) {
    cout << "Enter student name: ";
    cin >> ws; // Consume any leading whitespaces
    getline(cin, student.name);

    cout << "Enter student ID number: ";
    cin >> student.idnum;

    cout << "Enter test scores for " << student.name << ":\n";
    for (int i = 0; i < MAX_TESTS; ++i) {
        do {
            cout << "Test " << i + 1 << ": ";
            cin >> student.tests[i];
        } while (student.tests[i] < 0); // Input validation for negative test scores
    }
}

void calculateAverage(Student& student) {
    double sum = 0.0;

    for (int i = 0; i < MAX_TESTS; ++i) {
        sum += student.tests[i];
    }

    student.average = sum / MAX_TESTS;
}

void calculateGrade(Student& student) {
    if (student.average >= 91) {
        student.grade = 'A';
    } else if (student.average >= 81) {
        student.grade = 'B';
    } else if (student.average >= 71) {
        student.grade = 'C';
    } else if (student.average >= 61) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}

void displayStudentData(const Student& student) {
    cout << setw(15) << student.name << setw(15) << student.idnum << setw(15) << student.average << setw(15) << student.grade << endl;
}
