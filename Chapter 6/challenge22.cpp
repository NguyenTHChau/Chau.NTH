#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    // Check for divisibility from 2 to the square root of the number
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false; // Not a prime number
        }
    }

    return true; // Prime number
}

int main() {
    int number;

    // Input from the user
    cout << "Enter a number: ";
    cin >> number;

    // Check if the entered number is prime using the isPrime function
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}
