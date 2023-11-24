#include <iostream>
#include <iomanip>

using namespace std;

// Function to calculate profit or loss from the sale of stock
double calculateProfitLoss(int numShares, double purchasePrice, double purchaseCommission,
                            double salePrice, double saleCommission) {
    double profitLoss = ((numShares * salePrice) - saleCommission) - ((numShares * purchasePrice) + purchaseCommission);
    return profitLoss;
}

int main() {
    int numShares;
    double purchasePrice, purchaseCommission, salePrice, saleCommission;

    // Get input from the user
    cout << "Enter the number of shares: ";
    cin >> numShares;

    cout << "Enter the purchase price per share: $";
    cin >> purchasePrice;

    cout << "Enter the purchase commission paid: $";
    cin >> purchaseCommission;

    cout << "Enter the sale price per share: $";
    cin >> salePrice;

    cout << "Enter the sale commission paid: $";
    cin >> saleCommission;

    // Calculate profit or loss using the function
    double profitLoss = calculateProfitLoss(numShares, purchasePrice, purchaseCommission, salePrice, saleCommission);

    // Display the result
    cout << fixed << setprecision(2);
    if (profitLoss > 0) {
        cout << "Profit from the sale of stock: $" << profitLoss << endl;
    } else if (profitLoss < 0) {
        cout << "Loss from the sale of stock: $" << profitLoss << endl;
    } else {
        cout << "No profit or loss from the sale of stock." << endl;
    }

    return 0;
}
