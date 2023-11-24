#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_NAME_LENGTH = 100;

    char firstName[MAX_NAME_LENGTH];
    char middleName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char arrangedName[MAX_NAME_LENGTH * 3]; // It's large enough to hold the rearranged name

    // Get user input
    cout << "Enter your first name: ";
    cin.getline(firstName, MAX_NAME_LENGTH);

    cout << "Enter your middle name: ";
    cin.getline(middleName, MAX_NAME_LENGTH);

    cout << "Enter your last name: ";
    cin.getline(lastName, MAX_NAME_LENGTH);

    // Rearrange names
    strcpy(arrangedName, lastName);
    strcat(arrangedName, ", ");
    strcat(arrangedName, firstName);
    strcat(arrangedName, " ");
    strcat(arrangedName, middleName);

    // Display the rearranged name
    cout << "Rearranged name: " << arrangedName << endl;

    return 0;
}
