#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Board;

const int SIZE = 8;

bool threat(Board& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return true;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return true;
    }

    for (int i = row, j = col; i >= 0 && j < SIZE; i--, j++) {
        if (board[i][j] == 'Q') return true;
    }

    return false;
}

void solve(Board& board, int row, int& counter) {
    if (row == SIZE) {
        counter++;
        return;
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == '*' || threat(board, row, j))
            continue;
        board[row][j] = 'Q';
        solve(board, row + 1, counter);
        board[row][j] = '.';
    }
}

int main() {
    Board board(SIZE, vector<char>(SIZE));
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    solve(board, 0, counter);
    cout << counter << endl;
    return 0;

}