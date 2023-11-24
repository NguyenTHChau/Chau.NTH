#include <iostream>
#include <cmath>

using namespace std;

// Function prototype
double fallingDistance(int time);

int main() {
    // Display table header
    cout << "Time (s)\tDistance (m)" << endl;

    // Call the function in a loop for time values from 1 through 10
    for (int time = 1; time <= 10; ++time) {
        double distance = fallingDistance(time);
        cout << time << "\t\t" << distance << endl;
    }

    return 0;
}

// Function to calculate falling distance
double fallingDistance(int time) {
    const double g = 9.8; // Acceleration due to gravity

    // Formula: d = 0.5 * g * t^2
    double distance = 0.5 * g * pow(time, 2);
    return distance;
}
