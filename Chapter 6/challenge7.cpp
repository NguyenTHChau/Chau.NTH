#include <iostream>

using namespace std;

// Function prototype
double kineticEnergy(double mass, double velocity);

int main() {
    // Get user input for mass and velocity
    double mass, velocity;

    cout << "Enter the mass of the object (in kilograms): ";
    cin >> mass;

    cout << "Enter the velocity of the object (in meters per second): ";
    cin >> velocity;

    // Calculate and display the kinetic energy
    double energy = kineticEnergy(mass, velocity);

    cout << "The kinetic energy of the object is: " << energy << " joules" << endl;

    return 0;
}

// Function to calculate kinetic energy
double kineticEnergy(double mass, double velocity) {
    // Formula: KE = 0.5 * mass * velocity^2
    double energy = 0.5 * mass * velocity * velocity;
    return energy;
}
