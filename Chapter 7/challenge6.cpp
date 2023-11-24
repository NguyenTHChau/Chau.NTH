#include <iostream>
#include <fstream>

using namespace std;

const int MONTHS = 3;
const int DAYS_PER_MONTH = 30;

void readWeatherData(char weatherData[][DAYS_PER_MONTH]);
void generateReport(const char weatherData[][DAYS_PER_MONTH]);

int main() {
    char weatherData[MONTHS][DAYS_PER_MONTH];

    // Read weather data from file
    readWeatherData(weatherData);

    // Generate and display the report
    generateReport(weatherData);

    return 0;
}

void readWeatherData(char weatherData[][DAYS_PER_MONTH]) {
    ifstream inputFile("RainOrShine.txt");

    if (!inputFile) {
        cerr << "Error opening file.\n";
        exit(1);
    }

    // Read weather data from the file
    for (int month = 0; month < MONTHS; ++month) {
        for (int day = 0; day < DAYS_PER_MONTH; ++day) {
            inputFile >> weatherData[month][day];
        }
    }

    inputFile.close();
}

void generateReport(const char weatherData[][DAYS_PER_MONTH]) {
    int rainyCount[MONTHS] = {0};
    int cloudyCount[MONTHS] = {0};
    int sunnyCount[MONTHS] = {0};

    // Count the number of rainy, cloudy, and sunny days for each month
    for (int month = 0; month < MONTHS; ++month) {
        for (int day = 0; day < DAYS_PER_MONTH; ++day) {
            switch (weatherData[month][day]) {
                case 'R':
                    rainyCount[month]++;
                    break;
                case 'C':
                    cloudyCount[month]++;
                    break;
                case 'S':
                    sunnyCount[month]++;
                    break;
                default:
                    cerr << "Invalid weather code.\n";
                    exit(1);
            }
        }
    }

    // Display the report
    for (int month = 0; month < MONTHS; ++month) {
        cout << "Month " << (month + 1) << ":\n";
        cout << "Rainy days: " << rainyCount[month] << "\n";
        cout << "Cloudy days: " << cloudyCount[month] << "\n";
        cout << "Sunny days: " << sunnyCount[month] << "\n";
        cout << "------------------------\n";
    }

    // Find the month with the most rainy days
    int mostRainyMonth = 0;
    for (int month = 1; month < MONTHS; ++month) {
        if (rainyCount[month] > rainyCount[mostRainyMonth]) {
            mostRainyMonth = month;
        }
    }

    cout << "Month with the most rainy days: " << (mostRainyMonth + 1) << "\n";
}
