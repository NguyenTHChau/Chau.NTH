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
    int numStocks;
    cout << "Enter the number of stock sales: ";
    cin >> numStocks;

    double totalProfitLoss = 0;

    for (int i = 1; i <= numStocks; ++i) {
        int numShares;
        double purchasePrice, purchaseCommission, salePrice, saleCommission;

        // Get input for each stock sale
        cout << "\nStock Sale #" << i << ":\n";
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

        // Display the profit or loss for each stock sale
        cout << fixed << setprecision(2);
        if (profitLoss > 0) {
            cout << "Profit from Stock Sale #" << i << ": $" << profitLoss << endl;
        } else if (profitLoss < 0) {
            cout << "Loss from Stock Sale #" << i << ": $" << profitLoss << endl;
        } else {
            cout << "No profit or loss from Stock Sale #" << i << endl;
        }

        // Accumulate the total profit or loss
        totalProfitLoss += profitLoss;
    }

    // Display the total profit or loss from all stock sales
    cout << "\nTotal Profit or Loss from all stock sales: $" << totalProfitLoss << endl;

    return 0;
}
