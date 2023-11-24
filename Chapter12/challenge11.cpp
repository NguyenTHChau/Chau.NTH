#include <iostream>
#include <fstream>

using namespace std;

struct DivisionData {
    string divisionName;
    int quarter;
    double quarterlySales;
};

void writeDivisionDataToFile(const DivisionData& data, ofstream& outFile) {
    outFile << data.divisionName << " " << data.quarter << " " << data.quarterlySales << endl;
}

int main() {
    const int NUM_DIVISIONS = 4;
    const string divisionNames[NUM_DIVISIONS] = {"East", "West", "North", "South"};

    DivisionData divisionData;
    ofstream outFile("sales_data.txt");

    if (!outFile) {
        cerr << "Error: Unable to open file.\n";
        return 1;
    }

    cout << "Enter quarterly sales data for each division:\n";

    for (int i = 0; i < NUM_DIVISIONS; ++i) {
        divisionData.divisionName = divisionNames[i];

        for (int quarter = 1; quarter <= 4; ++quarter) {
            do {
                cout << "Enter quarterly sales for " << divisionData.divisionName << " (Quarter " << quarter << "): $";
                cin >> divisionData.quarterlySales;

                if (divisionData.quarterlySales < 0) {
                    cout << "Invalid input. Please enter a non-negative value.\n";
                }

            } while (divisionData.quarterlySales < 0);

            divisionData.quarter = quarter;
            writeDivisionDataToFile(divisionData, outFile);
        }
    }

    outFile.close();

    cout << "Sales data written to sales_data.txt.\n";

    return 0;
}
