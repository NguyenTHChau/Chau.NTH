#include <iostream>

using namespace std;

const int SIZE = 3;

// Function to display the tic-tac-toe board
void displayBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full (a tie)
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '*') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[SIZE][SIZE];

    // Initialize the board with asterisks
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '*';
        }
    }

    int row, col;
    bool player1Turn = true;

    // Main game loop
    while (true) {
        // Display the current state of the board
        displayBoard(board);

        // Determine current player
        char currentPlayer = (player1Turn) ? 'X' : 'O';

        // Get player move
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by space: ";
        cin >> row >> col;

        // Check if the chosen location is valid and not already taken
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '*') {
            // Place the player's symbol on the board
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a tie
            if (isBoardFull(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            // Switch to the other player's turn
            player1Turn = !player1Turn;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
