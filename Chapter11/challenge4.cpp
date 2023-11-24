#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define the structure for weather data
struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

// Function to input weather data for a month
void inputWeatherData(WeatherData& month) {
    cout << "Enter weather data for the month:\n";
    
    cout << "Total Rainfall (in inches): ";
    cin >> month.totalRainfall;

    cout << "High Temperature (in Fahrenheit): ";
    cin >> month.highTemperature;

    // Input validation for temperature
    while (month.highTemperature < -100 || month.highTemperature > 140) {
        cout << "Temperature must be between -100 and 140 degrees Fahrenheit. Enter again: ";
        cin >> month.highTemperature;
    }

    cout << "Low Temperature (in Fahrenheit): ";
    cin >> month.lowTemperature;

    // Input validation for temperature
    while (month.lowTemperature < -100 || month.lowTemperature > 140) {
        cout << "Temperature must be between -100 and 140 degrees Fahrenheit. Enter again: ";
        cin >> month.lowTemperature;
    }

    month.averageTemperature = (month.highTemperature + month.lowTemperature) / 2.0;
}

int main() {
    const int numMonths = 12;
    WeatherData yearlyData[numMonths];

    // Input weather data for each month
    for (int i = 0; i < numMonths; ++i) {
        cout << "\nMonth " << i + 1 << ":\n";
        inputWeatherData(yearlyData[i]);
    }

    // Calculate and display statistics
    double totalRainfall = 0;
    double highestTemperature = numeric_limits<double>::min();
    double lowestTemperature = numeric_limits<double>::max();
    double totalAverageTemperature = 0;

    int highestTempMonth = 0;
    int lowestTempMonth = 0;

    for (int i = 0; i < numMonths; ++i) {
        totalRainfall += yearlyData[i].totalRainfall;
        totalAverageTemperature += yearlyData[i].averageTemperature;

        if (yearlyData[i].highTemperature > highestTemperature) {
            highestTemperature = yearlyData[i].highTemperature;
            highestTempMonth = i + 1;
        }

        if (yearlyData[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearlyData[i].lowTemperature;
            lowestTempMonth = i + 1;
        }
    }

    double averageMonthlyTemperature = totalAverageTemperature / numMonths;

    cout << "\nStatistics for the year:\n";
    cout << "Total Rainfall: " << totalRainfall << " inches\n";
    cout << "Highest Temperature: " << highestTemperature << " degrees Fahrenheit (Month " << highestTempMonth << ")\n";
    cout << "Lowest Temperature: " << lowestTemperature << " degrees Fahrenheit (Month " << lowestTempMonth << ")\n";
    cout << "Average Monthly Temperature: " << averageMonthlyTemperature << " degrees Fahrenheit\n";

    return 0;
}
