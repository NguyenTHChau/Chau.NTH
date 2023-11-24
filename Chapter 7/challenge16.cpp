#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read teams from Teams.txt file
vector<string> readTeamsFromFile(const string& filename) {
    vector<string> teams;
    ifstream inputFile(filename);

    if (inputFile) {
        string teamName;
        while (getline(inputFile, teamName)) {
            teams.push_back(teamName);
        }
        inputFile.close();
    } else {
        cerr << "Error opening Teams.txt file.\n";
    }

    return teams;
}

// Function to count World Series wins for a given team
int countWorldSeriesWins(const vector<string>& winners, const string& teamName) {
    return count(winners.begin(), winners.end(), teamName);
}

int main() {
    // Read teams from Teams.txt file
    vector<string> teams = readTeamsFromFile("Teams.txt");

    // Read World Series winners from WorldSeriesWinners.txt file
    vector<string> worldSeriesWinners;
    ifstream winnersFile("WorldSeriesWinners.txt");

    if (winnersFile) {
        string winner;
        while (getline(winnersFile, winner)) {
            worldSeriesWinners.push_back(winner);
        }
        winnersFile.close();
    } else {
        cerr << "Error opening WorldSeriesWinners.txt file.\n";
        return 1;
    }

    // Display teams from Teams.txt
    cout << "Major League Baseball Teams:\n";
    for (const auto& team : teams) {
        cout << team << endl;
    }

    // Prompt user for team name
    cout << "\nEnter the name of a team: ";
    string userTeam;
    getline(cin, userTeam);

    // Convert team name to uppercase for case-insensitive comparison
    transform(userTeam.begin(), userTeam.end(), userTeam.begin(), ::toupper);

    // Count and display the number of World Series wins for the entered team
    int wins = countWorldSeriesWins(worldSeriesWinners, userTeam);
    cout << "\nThe team '" << userTeam << "' won the World Series " << wins << " times from 1903 to 2012.\n";

    return 0;
}
