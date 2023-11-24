#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define the structure for soccer player data
struct SoccerPlayer {
    string playerName;
    int playerNumber;
    int pointsScored;
};

// Function to input data for a soccer player
void inputPlayerData(SoccerPlayer& player) {
    cout << "Enter data for a soccer player:\n";

    cout << "Player's Name: ";
    cin.ignore();
    getline(cin, player.playerName);

    cout << "Player's Number: ";
    cin >> player.playerNumber;

    // Input validation for player number
    while (player.playerNumber < 0) {
        cout << "Player's number cannot be negative. Enter again: ";
        cin >> player.playerNumber;
    }

    cout << "Points Scored by Player: ";
    cin >> player.pointsScored;

    // Input validation for points scored
    while (player.pointsScored < 0) {
        cout << "Points scored cannot be negative. Enter again: ";
        cin >> player.pointsScored;
    }
}

int main() {
    const int numPlayers = 12;
    SoccerPlayer team[numPlayers];

    // Input data for each player
    for (int i = 0; i < numPlayers; ++i) {
        cout << "\nPlayer " << i + 1 << ":\n";
        inputPlayerData(team[i]);
    }

    // Display table of player information
    cout << "\nPlayer Information:\n";
    cout << "-------------------------------------------------\n";
    cout << "Player Number\tPlayer Name\tPoints Scored\n";
    cout << "-------------------------------------------------\n";

    int totalPoints = 0;
    int maxPoints = numeric_limits<int>::min();
    int maxPointsPlayerIndex = 0;

    for (int i = 0; i < numPlayers; ++i) {
        cout << team[i].playerNumber << "\t\t" << team[i].playerName << "\t\t" << team[i].pointsScored << endl;

        totalPoints += team[i].pointsScored;

        if (team[i].pointsScored > maxPoints) {
            maxPoints = team[i].pointsScored;
            maxPointsPlayerIndex = i;
        }
    }

    // Display team statistics
    cout << "-------------------------------------------------\n";
    cout << "Total Points: " << totalPoints << endl;
    cout << "Player with the most points: " << team[maxPointsPlayerIndex].playerName << " (Player Number "
         << team[maxPointsPlayerIndex].playerNumber << ") with " << maxPoints << " points.\n";

    return 0;
}
