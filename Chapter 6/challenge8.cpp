#include <iostream>
#include <cstdlib> // For rand and srand functions
#include <ctime>   // For time function

using namespace std;

// Function prototype
void coinToss();

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Ask the user how many times to toss the coin
    int tossCount;
    cout << "How many times do you want to toss the coin? ";
    cin >> tossCount;

    // Simulate the tossing of the coin
    for (int i = 0; i < tossCount; ++i) {
        cout << "Toss " << (i + 1) << ": ";
        coinToss();
    }

    return 0;
}

// Function to simulate coin toss
void coinToss() {
    // Generate a random number in the range of 1 through 2
    int result = rand() % 2 + 1;

    // Display "heads" or "tails" based on the random number
    if (result == 1) {
        cout << "Heads" << endl;
    } else {
        cout << "Tails" << endl;
    }
}
