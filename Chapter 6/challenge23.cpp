#include <iostream>
#include <fstream>
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
    ofstream outFile("prime_numbers.txt");

    if (!outFile) {
        cerr << "Error creating/opening the file." << endl;
        return 1;
    }

    // Store prime numbers from 1 to 100 in a file
    for (int i = 1; i <= 100; ++i) {
        if (isPrime(i)) {
            outFile << i << endl;
        }
    }

    outFile.close();

    cout << "Prime numbers from 1 to 100 have been stored in 'prime_numbers.txt'." << endl;

    return 0;
}
