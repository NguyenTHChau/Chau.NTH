#include <iostream>

using namespace std;

// Structure for hourly paid worker
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

// Structure for salaried worker
struct Salaried {
    double salary;
    double bonus;
};

// Union to hold either hourly paid or salaried worker data
union WorkerData {
    HourlyPaid hourly;
    Salaried salaried;
};

// Function to calculate pay for hourly paid worker
double calculateHourlyPay(const WorkerData& data) {
    if (data.hourly.hoursWorked > 80) {
        cout << "Error: Hours worked cannot exceed 80.\n";
        return 0.0;
    }
    return data.hourly.hoursWorked * data.hourly.hourlyRate;
}

// Function to calculate pay for salaried worker
double calculateSalariedPay(const WorkerData& data) {
    return data.salaried.salary + data.salaried.bonus;
}

int main() {
    // Declare a union to hold worker data
    WorkerData worker;

    // Ask the user whether to calculate pay for an hourly paid or salaried worker
    char workerType;
    cout << "Enter 'H' for hourly paid worker, 'S' for salaried worker: ";
    cin >> workerType;

    // Input validation
    if (workerType != 'H' && workerType != 'S') {
        cout << "Invalid input. Program exiting.\n";
        return 1;
    }

    // Get worker data from the user
    if (workerType == 'H') {
        cout << "Enter hours worked: ";
        cin >> worker.hourly.hoursWorked;
        cout << "Enter hourly rate: ";
        cin >> worker.hourly.hourlyRate;
    } else {
        cout << "Enter salary: ";
        cin >> worker.salaried.salary;
        cout << "Enter bonus: ";
        cin >> worker.salaried.bonus;
    }

    // Calculate and display the pay
    double pay;
    if (workerType == 'H') {
        pay = calculateHourlyPay(worker);
    } else {
        pay = calculateSalariedPay(worker);
    }

    if (pay > 0.0) {
        cout << "The worker's pay is: $" << pay << endl;
    }

    return 0;
}
