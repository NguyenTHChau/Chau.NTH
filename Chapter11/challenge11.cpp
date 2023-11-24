#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Define the structure for Monthly Budget
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function prototypes
void enterExpenses(MonthlyBudget& budget);
void displayReport(const MonthlyBudget& budget);

int main() {
    MonthlyBudget monthlyBudget;

    // Get user input for actual expenses
    enterExpenses(monthlyBudget);

    // Display the budget report
    displayReport(monthlyBudget);

    return 0;
}

void enterExpenses(MonthlyBudget& budget) {
    cout << "Enter actual expenses for the month:\n";
    cout << "Housing: ";
    cin >> budget.housing;

    cout << "Utilities: ";
    cin >> budget.utilities;

    cout << "Household Expenses: ";
    cin >> budget.householdExpenses;

    cout << "Transportation: ";
    cin >> budget.transportation;

    cout << "Food: ";
    cin >> budget.food;

    cout << "Medical: ";
    cin >> budget.medical;

    cout << "Insurance: ";
    cin >> budget.insurance;

    cout << "Entertainment: ";
    cin >> budget.entertainment;

    cout << "Clothing: ";
    cin >> budget.clothing;

    cout << "Miscellaneous: ";
    cin >> budget.miscellaneous;
}

void displayReport(const MonthlyBudget& budget) {
    cout << "\nBudget Report:\n";
    cout << fixed << setprecision(2);

    // Define the budgeted amounts
    MonthlyBudget budgeted = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};

    // Display actual expenses
    cout << left << setw(20) << "Category" << setw(20) << "Budgeted" << setw(20) << "Actual" << setw(20) << "Difference\n";
    cout << string(80, '-') << endl;

    cout << left << setw(20) << "Housing" << setw(20) << budgeted.housing << setw(20) << budget.housing << setw(20) << budget.housing - budgeted.housing << endl;
    cout << left << setw(20) << "Utilities" << setw(20) << budgeted.utilities << setw(20) << budget.utilities << setw(20) << budget.utilities - budgeted.utilities << endl;
    cout << left << setw(20) << "Household Expenses" << setw(20) << budgeted.householdExpenses << setw(20) << budget.householdExpenses << setw(20) << budget.householdExpenses - budgeted.householdExpenses << endl;
    cout << left << setw(20) << "Transportation" << setw(20) << budgeted.transportation << setw(20) << budget.transportation << setw(20) << budget.transportation - budgeted.transportation << endl;
    cout << left << setw(20) << "Food" << setw(20) << budgeted.food << setw(20) << budget.food << setw(20) << budget.food - budgeted.food << endl;
    cout << left << setw(20) << "Medical" << setw(20) << budgeted.medical << setw(20) << budget.medical << setw(20) << budget.medical - budgeted.medical << endl;
    cout << left << setw(20) << "Insurance" << setw(20) << budgeted.insurance << setw(20) << budget.insurance << setw(20) << budget.insurance - budgeted.insurance << endl;
    cout << left << setw(20) << "Entertainment" << setw(20) << budgeted.entertainment << setw(20) << budget.entertainment << setw(20) << budget.entertainment - budgeted.entertainment << endl;
    cout << left << setw(20) << "Clothing" << setw(20) << budgeted.clothing << setw(20) << budget.clothing << setw(20) << budget.clothing - budgeted.clothing << endl;
    cout << left << setw(20) << "Miscellaneous" << setw(20) << budgeted.miscellaneous << setw(20) << budget.miscellaneous << setw(20) << budget.miscellaneous - budgeted.miscellaneous << endl;

    // Display total difference
    double totalDifference = budget.housing - budgeted.housing +
                            budget.utilities - budgeted.utilities +
                            budget.householdExpenses - budgeted.householdExpenses +
                            budget.transportation - budgeted.transportation +
                            budget.food - budgeted.food +
                            budget.medical - budgeted.medical +
                            budget.insurance - budgeted.insurance +
                            budget.entertainment - budgeted.entertainment +
                            budget.clothing - budgeted.clothing +
                            budget.miscellaneous - budgeted.miscellaneous;

    cout << "\nTotal Difference: $" << totalDifference << endl;
}
