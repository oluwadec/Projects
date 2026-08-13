#include <iostream>
#include <vector>

std::vector<char> board(9, ' ');

void drawBoard() {
    std::cout << "\n " << board[0] << " | " << board[1] << " | " << board[2];
    std::cout << "\n---|---|---";
    std::cout << "\n " << board[3] << " | " << board[4] << " | " << board[5];
    std::cout << "\n---|---|---";
    std::cout << "\n " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

// returns true if the move actually happened
bool placeMarker(int slot, char marker) {
    int index = slot - 1;
    if (index < 0 || index > 8 || board[index] != ' ')
        return false;

    board[index] = marker;
    return true;
}

bool boardIsFull() {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

// checks if whoever just played (marker) has won
bool checkWin(char marker) {
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };

    for (auto& line : wins) {
        if (board[line[0]] == marker && board[line[1]] == marker && board[line[2]] == marker)
            return true;
    }
    return false;
}

int main() {
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "Positions are numbered 1-9 like this:\n";
    std::cout << " 1 | 2 | 3 \n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9 \n";

    int player = 1;
    char marker = 'X';

    while (true) {
        drawBoard();
        std::cout << "Player " << player << " (" << marker << "), pick a spot (1-9): ";

        int slot;
        std::cin >> slot;

        if (!placeMarker(slot, marker)) {
            std::cout << "Can't go there, pick another spot.\n";
            continue;
        }

        if (checkWin(marker)) {
            drawBoard();
            std::cout << "Player " << player << " wins!\n";
            break;
        }

        if (boardIsFull()) {
            drawBoard();
            std::cout << "It's a draw.\n";
            break;
        }

        // switch turns
        player = (player == 1) ? 2 : 1;
        marker = (marker == 'X') ? 'O' : 'X';
    }

    return 0;
}