#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
double calculateCharges(int days, double dailyRate, double medCharges, double servCharges);
double calculateCharges(double medCharges, double servCharges);
void writeReport(ofstream& outFile, int days, double dailyRate, double medCharges, double servCharges);

int main() {
    int patientType;
    int days;
    double dailyRate;
    double medCharges;
    double servCharges;

    cout << "Enter 1 for in-patient, 2 for out-patient: ";
    cin >> patientType;

    if (patientType == 1) {
        cout << "Enter the number of days spent in the hospital: ";
        cin >> days;
        cout << "Enter the daily rate: $";
        cin >> dailyRate;
        cout << "Enter hospital medication charges: $";
        cin >> medCharges;
        cout << "Enter charges for hospital services: $";
        cin >> servCharges;
    } else if (patientType == 2) {
        cout << "Enter charges for hospital services: $";
        cin >> servCharges;
        cout << "Enter hospital medication charges: $";
        cin >> medCharges;
    } else {
        cout << "Invalid input. Please enter 1 or 2." << endl;
        return 1;
    }

    double total = (patientType == 1) ? calculateCharges(days, dailyRate, medCharges, servCharges) :
                                        calculateCharges(medCharges, servCharges);

    cout << fixed << setprecision(2);
    cout << "Total charges: $" << total << endl;

    // Writing the report to a file
    ofstream outFile("hospital_report.txt");
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    writeReport(outFile, days, dailyRate, medCharges, servCharges);

    outFile.close();

    return 0;
}

double calculateCharges(int days, double dailyRate, double medCharges, double servCharges) {
    return (days * dailyRate) + medCharges + servCharges;
}

double calculateCharges(double medCharges, double servCharges) {
    return medCharges + servCharges;
}

void writeReport(ofstream& outFile, int days, double dailyRate, double medCharges, double servCharges) {
    outFile << fixed << setprecision(2);
    outFile << "Hospital Stay Report:" << endl;
    if (days > 0) {
        outFile << "Number of days spent in the hospital: " << days << endl;
        outFile << "Daily rate: $" << dailyRate << endl;
    }
    outFile << "Hospital medication charges: $" << medCharges << endl;
    outFile << "Charges for hospital services: $" << servCharges << endl;
    outFile << "Total charges: $" << calculateCharges(days, dailyRate, medCharges, servCharges) << endl;
}
