#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if(i < 2)
            cout << "---|---|---" << endl;
    }
}

bool placeMark(int pos, char mark) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return true;
    }
    return false;
}

bool checkWin() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

int main() {
    int move;
    char player = 'X';

    for(int turn = 0; turn < 9; turn++) {
        displayBoard();

        cout << "\nPlayer " << player << ", enter position (1-9): ";
        cin >> move;

        if(move < 1 || move > 9 || !placeMark(move, player)) {
            cout << "Invalid Move! Try Again.\n";
            turn--;
            continue;
        }

        if(checkWin()) {
            displayBoard();
            cout << "\nPlayer " << player << " Wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "\nIt's a Draw!\n";

    return 0;
}
