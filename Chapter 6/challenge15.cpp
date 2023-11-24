#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
double calculateCharges(int days, double rate, double medicationCharges, double serviceCharges);
double calculateCharges(double medicationCharges, double serviceCharges);

int main() {
    char patientType;
    int days;
    double rate, medicationCharges, serviceCharges, totalCharges;

    cout << "Enter patient type (I for in-patient, O for out-patient): ";
    cin >> patientType;

    if (toupper(patientType) == 'I') {
        cout << "Enter number of days spent in the hospital: ";
        cin >> days;

        cout << "Enter daily rate: $";
        cin >> rate;

        cout << "Enter hospital medication charges: $";
        cin >> medicationCharges;

        cout << "Enter charges for hospital services: $";
        cin >> serviceCharges;

        totalCharges = calculateCharges(days, rate, medicationCharges, serviceCharges);
    } else if (toupper(patientType) == 'O') {
        cout << "Enter hospital medication charges for out-patient: $";
        cin >> medicationCharges;

        cout << "Enter charges for hospital services for out-patient: $";
        cin >> serviceCharges;

        totalCharges = calculateCharges(medicationCharges, serviceCharges);
    } else {
        cout << "Invalid patient type. Please enter 'I' or 'O'." << endl;
        return 1;
    }

    cout << fixed << setprecision(2);
    cout << "Total charges: $" << totalCharges << endl;

    return 0;
}

// Function to calculate total charges for in-patient
double calculateCharges(int days, double rate, double medicationCharges, double serviceCharges) {
    if (days < 0 || rate < 0 || medicationCharges < 0 || serviceCharges < 0) {
        cout << "Invalid input. Negative numbers are not allowed." << endl;
        return 0.0;
    }

    return (days * rate) + medicationCharges + serviceCharges;
}

// Function to calculate total charges for out-patient
double calculateCharges(double medicationCharges, double serviceCharges) {
    if (medicationCharges < 0 || serviceCharges < 0) {
        cout << "Invalid input. Negative numbers are not allowed." << endl;
        return 0.0;
    }

    return medicationCharges + serviceCharges;
}
